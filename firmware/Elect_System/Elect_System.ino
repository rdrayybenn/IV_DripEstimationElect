#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <time.h>
#include <sys/time.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"
#include "best_iv_model_20261125_020948_539740.h"

// ==========================================
// 1. EXACT PIN DEFINITIONS
// ==========================================
#define HX711_DOUT 16
#define HX711_SCK  17

#define GREEN_LED  14
#define YELLOW_LED 27
#define RED_LED    26
#define BUZZER_PIN 25

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ==========================================
// 2. CONFIGURATION & THRESHOLDS
// ==========================================
const char* AP_SSID = "IV-Monitor-AI";
const char* AP_PASS = "12345678";

float CALIBRATION_FACTOR        = 688.0370;
const double WARNING_TIME_SEC   = 900.0;    // YELLOW LED: <= 15 mins left
const double CRITICAL_TIME_SEC  = 300.0;    // RED LED + Buzzer: <= 5 mins left

// Weight Zones:
// 0.0g  - 9.9g  -> NO_BAG (Idle, buzzer OFF)
// 10.0g - 50.0g -> CRITICAL (Replace Bag, Red LED + Buzzer ON)
// > 50.0g       -> Active infusion
const double NO_BAG_WEIGHT_G    = 10.0;     // < 10.0g = hook empty (Idle)
const double EMPTY_BAG_WEIGHT_G = 50.0;     // 10.0g to 50.0g = Critical (Replace Bag)
const double NEW_BAG_JUMP_G     = 30.0;     // Auto-reset if weight increases by > 30g
const double WEIGHT_DEADBAND_G  = 0.40;     // Ignore +/- 0.4g HX711 sensor noise

// Flow Calibration: 500g = 4 hrs (125 g/hr = 2.0833 g/min = 41.67 gtt/min), 1000g = 8 hrs
const double GTT_PER_GRAM              = 20.0;
const double DEFAULT_DRIP_RATE_GTT_MIN = 41.67;
const double BASELINE_LOSS_RATE_GS     = DEFAULT_DRIP_RATE_GTT_MIN / (GTT_PER_GRAM * 60.0);

// Realistic IV drip bounds (10 gtt/min to 120 gtt/min) so hook bounce never causes 1-hr jumps
const double MIN_VALID_LOSS_RATE_GS    = 10.0 / (GTT_PER_GRAM * 60.0);  // 0.00833 g/s
const double MAX_VALID_LOSS_RATE_GS    = 120.0 / (GTT_PER_GRAM * 60.0); // 0.10000 g/s
const double SETTLE_DELAY_SEC          = 5.0; // Wait 5s after hanging bag before sampling rate

const double MODEL_BASELINE_OFFSET_G   = 454.0;

// ==========================================
// 3. GLOBAL STATE VARIABLES
// ==========================================
WebServer server(80);
HX711 scale;

int experimentNumber = 1;
String experimentId  = "EXP_001";
bool clockSynced     = false;

unsigned long runStartMillis   = 0;
unsigned long lastSampleMillis = 0;
const unsigned long SAMPLE_INTERVAL_MS = 1000;

double filteredWeight   = 0.0;
double prevWeight       = 0.0;
bool firstReading       = true;
bool timerInitialized   = false;

// Smooth flow rate state (in grams/sec)
double smoothedLossRate = BASELINE_LOSS_RATE_GS;

// Rolling 60-second weight buffer for stable drip-rate measurement
const int RATE_WINDOW_SEC = 60;
double weightWindow[RATE_WINDOW_SEC];
int windowCount = 0;
int windowIndex = 0;

// Live telemetry variables for Web Dashboard
double liveElapsedSec     = 0.0;
double liveWeightG        = 0.0;
double liveDripRate       = 0.0;
double liveWeightLossRate = 0.0;
double liveRemainingSec   = 0.0;
String liveTimestamp      = "";
String liveStatus         = "NO_BAG";

// ==========================================
// 4. WEB DASHBOARD
// ==========================================
const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>AI IV Drip Monitor</title>
<style>
  :root { --bg:#0f172a; --card:#1e293b; --text:#f8fafc; --muted:#94a3b8; --green:#22c55e; --yellow:#eab308; --red:#ef4444; --blue:#38bdf8; }
  * { box-sizing:border-box; font-family:system-ui,-apple-system,sans-serif; }
  body { margin:0; padding:16px; background:var(--bg); color:var(--text); }
  .container { max-width:880px; margin:0 auto; }
  header { display:flex; justify-content:space-between; align-items:center; flex-wrap:wrap; gap:10px; margin-bottom:16px; }
  h1 { font-size:1.25rem; margin:0; }
  .badge { padding:6px 14px; border-radius:999px; font-weight:700; font-size:0.85rem; }
  .NO_BAG { background:rgba(148,163,184,0.2); color:var(--muted); border:1px solid var(--muted); }
  .NORMAL { background:rgba(34,197,94,0.2); color:var(--green); border:1px solid var(--green); }
  .WARNING { background:rgba(234,179,8,0.2); color:var(--yellow); border:1px solid var(--yellow); }
  .CRITICAL { background:rgba(239,68,68,0.25); color:var(--red); border:1px solid var(--red); animation:pulse 1s infinite; }
  @keyframes pulse { 0%,100%{opacity:1;} 50%{opacity:0.5;} }
  .grid { display:grid; grid-template-columns:repeat(auto-fit,minmax(180px,1fr)); gap:12px; margin-bottom:16px; }
  .card { background:var(--card); padding:16px; border-radius:12px; border:1px solid #334155; }
  .label { color:var(--muted); font-size:0.78rem; text-transform:uppercase; margin-bottom:6px; }
  .value { font-size:1.65rem; font-weight:700; }
  .unit { font-size:0.85rem; color:var(--muted); font-weight:400; }
  .chart-box { background:var(--card); padding:16px; border-radius:12px; border:1px solid #334155; margin-bottom:14px; }
  svg { width:100%; height:190px; background:#0b1120; border-radius:8px; margin-top:8px; }
  .controls { display:flex; gap:10px; flex-wrap:wrap; justify-content:space-between; align-items:center; }
  button { background:#2563eb; color:white; border:none; padding:10px 16px; border-radius:8px; font-weight:600; cursor:pointer; }
  button:hover { background:#1d4ed8; }
  button.secondary { background:#475569; }
  button.secondary:hover { background:#334155; }
  .meta { font-size:0.82rem; color:var(--muted); }
</style>
</head>
<body>
<div class="container">
  <header>
    <h1>AI IV Drip Monitor <span style="color:var(--blue);font-size:0.85rem;" id="expBadge">EXP_001</span></h1>
    <div id="statusBadge" class="badge NO_BAG">NO BAG</div>
  </header>

  <div class="grid">
    <div class="card">
      <div class="label">Est. Remaining Time</div>
      <div class="value" id="remTime">--:--:--</div>
    </div>
    <div class="card">
      <div class="label">Current Weight</div>
      <div class="value"><span id="weight">0.00</span> <span class="unit">g</span></div>
    </div>
    <div class="card">
      <div class="label">Drip Rate</div>
      <div class="value"><span id="dripRate">0.0</span> <span class="unit">gtt/min</span></div>
    </div>
    <div class="card">
      <div class="label">Weight Loss Rate</div>
      <div class="value"><span id="lossRate">0.000</span> <span class="unit">g/s</span></div>
    </div>
  </div>

  <div class="chart-box">
    <div style="display:flex;justify-content:space-between;align-items:center;">
      <span class="label" style="margin:0;">Live Weight Feed (Last 60s)</span>
      <span class="meta" id="tsDisplay">Timestamp: --</span>
    </div>
    <svg viewBox="0 0 600 180" preserveAspectRatio="none">
      <polyline id="weightLine" fill="none" stroke="#38bdf8" stroke-width="3" points=""/>
    </svg>
  </div>

  <div class="controls">
    <div class="meta">Scale: 500g = 4h | 1000g = 8h | Critical: 10g–50g</div>
    <div style="display:flex;gap:8px;">
      <button class="secondary" onclick="tareScale()">Tare Scale (0g)</button>
      <button onclick="newExperiment()">+ New IV Bag Run</button>
    </div>
  </div>
</div>

<script>
const history = [];

async function syncClock() {
  const epochSec = Math.floor(Date.now() / 1000);
  const tzOffsetSec = -new Date().getTimezoneOffset() * 60;
  try {
    await fetch(`/api/sync-time?epoch=${epochSec}&tz=${tzOffsetSec}`);
  } catch (e) {}
}

function fmtTime(sec, status) {
  if (status === 'NO_BAG') return '--:--:--';
  sec = Math.max(0, Math.round(sec));
  const h = String(Math.floor(sec / 3600)).padStart(2, '0');
  const m = String(Math.floor((sec % 3600) / 60)).padStart(2, '0');
  const s = String(sec % 60).padStart(2, '0');
  return `${h}:${m}:${s}`;
}

function drawChart() {
  if (history.length < 2) return;
  const minW = Math.min(...history) - 1;
  const maxW = Math.max(...history) + 1;
  const range = Math.max(0.5, maxW - minW);
  const pts = history.map((w, i) => {
    const x = (i / 59) * 600;
    const y = 170 - ((w - minW) / range) * 160;
    return `${x.toFixed(1)},${y.toFixed(1)}`;
  }).join(' ');
  document.getElementById('weightLine').setAttribute('points', pts);
}

async function pollData() {
  try {
    const res = await fetch('/api/data');
    const d = await res.json();
    document.getElementById('expBadge').textContent = d.experiment_id;
    document.getElementById('remTime').textContent = fmtTime(d.remaining_time, d.status);
    document.getElementById('weight').textContent = d.current_weight.toFixed(2);
    document.getElementById('dripRate').textContent = d.drip_rate.toFixed(1);
    document.getElementById('lossRate').textContent = d.weight_loss_rate.toFixed(3);
    document.getElementById('tsDisplay').textContent = `${d.timestamp} (Elapsed: ${Math.floor(d.elapsed_time)}s)`;

    const badge = document.getElementById('statusBadge');
    badge.textContent = d.status.replace('_', ' ');
    badge.className = 'badge ' + d.status;

    history.push(d.current_weight);
    if (history.length > 60) history.shift();
    drawChart();
  } catch (e) {}
}

async function tareScale() {
  if (!confirm('Remove all load from the hook before taring to 0.00g. Continue?')) return;
  await fetch('/api/tare');
  history.length = 0;
  pollData();
}

async function newExperiment() {
  if (!confirm('Start a new experiment ID for a fresh IV bag?')) return;
  await fetch('/api/new-run');
  history.length = 0;
  pollData();
}

syncClock();
setInterval(pollData, 1000);
pollData();
</script>
</body>
</html>
)rawliteral";

// ==========================================
// 5. TIMESTAMP & RATE HELPERS
// ==========================================
String getIsoTimestamp() {
  time_t now;
  time(&now);
  struct tm timeinfo;
  localtime_r(&now, &timeinfo);

  char buf[25];
  strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", &timeinfo);
  return String(buf);
}

void resetRateWindow() {
  windowCount      = 0;
  windowIndex      = 0;
  smoothedLossRate = BASELINE_LOSS_RATE_GS;
}

double computeRollingLossRate(double currentWeight, double elapsedSec) {
  // Wait 5 seconds after hanging a bag so hook swing settles before recording baseline
  if (elapsedSec < SETTLE_DELAY_SEC) {
    return 0.0;
  }

  if (windowCount == 0) {
    weightWindow[0] = currentWeight;
    windowCount     = 1;
    windowIndex     = 1;
    return 0.0;
  }

  int oldestIdx = (windowCount < RATE_WINDOW_SEC) ? 0 : windowIndex;
  double oldestWeight = weightWindow[oldestIdx];
  double spanSec = (double)windowCount;

  weightWindow[windowIndex] = currentWeight;
  windowIndex = (windowIndex + 1) % RATE_WINDOW_SEC;
  if (windowCount < RATE_WINDOW_SEC) windowCount++;

  // Require full 60s window before switching off the baseline 4h/500g flow rate
  if (windowCount < RATE_WINDOW_SEC) return 0.0;

  double netDrop = oldestWeight - currentWeight;
  // Require at least 1.0g drop over 60s (>= 20 gtt/min) so static bags never trigger
  if (netDrop < 1.0) return 0.0;

  double rate = netDrop / spanSec;
  if (rate < MIN_VALID_LOSS_RATE_GS) rate = MIN_VALID_LOSS_RATE_GS;
  if (rate > MAX_VALID_LOSS_RATE_GS) rate = MAX_VALID_LOSS_RATE_GS;
  return rate;
}

// ==========================================
// 6. WEB SERVER HANDLERS
// ==========================================
void handleRoot() {
  server.send_P(200, "text/html", INDEX_HTML);
}

void handleSyncTime() {
  if (server.hasArg("epoch")) {
    time_t epoch = (time_t)server.arg("epoch").toInt();
    long tzOffset = server.hasArg("tz") ? server.arg("tz").toInt() : 0;
    struct timeval tv = { .tv_sec = epoch + tzOffset, .tv_usec = 0 };
    settimeofday(&tv, NULL);
    clockSynced = true;
  }
  server.send(200, "text/plain", "OK");
}

void handleTare() {
  scale.tare(20);
  firstReading     = true;
  timerInitialized = false;
  resetRateWindow();
  server.send(200, "text/plain", "TARED");
}

void handleNewRun() {
  experimentNumber++;
  char expBuf[12];
  sprintf(expBuf, "EXP_%03d", experimentNumber);
  experimentId     = String(expBuf);
  runStartMillis   = millis();
  firstReading     = true;
  timerInitialized = false;
  resetRateWindow();
  server.send(200, "text/plain", experimentId);
}

void handleApiData() {
  char json[300];
  snprintf(json, sizeof(json),
           "{\"experiment_id\":\"%s\",\"timestamp\":\"%s\",\"elapsed_time\":%.0f,"
           "\"current_weight\":%.2f,\"drip_rate\":%.1f,\"weight_loss_rate\":%.3f,"
           "\"remaining_time\":%.0f,\"status\":\"%s\"}",
           experimentId.c_str(), liveTimestamp.c_str(), liveElapsedSec,
           liveWeightG, liveDripRate, liveWeightLossRate,
           liveRemainingSec, liveStatus.c_str());
  server.send(200, "application/json", json);
}

// ==========================================
// 7. HARDWARE OUTPUTS, SETUP & MAIN LOOP
// ==========================================
void updateHardwareOutputs(double weight, double remSeconds, String status) {
  if (status == "NO_BAG") {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  } else if (status == "CRITICAL") {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER_PIN, ((millis() / 500) % 2 == 0) ? HIGH : LOW);
  } else if (status == "WARNING") {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  lcd.setCursor(0, 0);
  if (status == "NO_BAG") {
    lcd.printf("Wt:%6.1fg[IDLE]", weight);
    lcd.setCursor(0, 1);
    lcd.print("Hang IV Bag...  ");
    return;
  }

  int totalSec = (int)round(remSeconds);
  if (totalSec < 0) totalSec = 0;
  int hrs  = totalSec / 3600;
  int mins = (totalSec % 3600) / 60;
  int secs = totalSec % 60;

  if (status == "CRITICAL") {
    lcd.print("! REPLACE BAG ! ");
  } else if (status == "WARNING") {
    lcd.printf("Wt:%6.1fg [LOW]", weight);
  } else {
    lcd.printf("Wt:%6.1fg  [OK]", weight);
  }

  lcd.setCursor(0, 1);
  lcd.printf("Left: %02d:%02d:%02d  ", hrs, mins, secs);
}

void setup() {
  Serial.begin(115200);

  struct timeval tv = { .tv_sec = 1795564800, .tv_usec = 0 };
  settimeofday(&tv, NULL);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("AI IV Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Taring Scale...");

  scale.begin(HX711_DOUT, HX711_SCK);
  scale.set_scale(CALIBRATION_FACTOR);
  delay(500);
  scale.tare(20);

  WiFi.softAP(AP_SSID, AP_PASS);
  server.on("/", handleRoot);
  server.on("/api/data", handleApiData);
  server.on("/api/sync-time", handleSyncTime);
  server.on("/api/tare", handleTare);
  server.on("/api/new-run", handleNewRun);
  server.begin();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP:192.168.4.1");
  lcd.setCursor(0, 1);
  lcd.print("WiFi AP Ready");
  delay(1500);
  lcd.clear();

  runStartMillis   = millis();
  lastSampleMillis = millis();
}

void loop() {
  server.handleClient();

  unsigned long currentMillis = millis();
  if (currentMillis - lastSampleMillis >= SAMPLE_INTERVAL_MS) {
    double dt_sec = (currentMillis - lastSampleMillis) / 1000.0;
    lastSampleMillis += SAMPLE_INTERVAL_MS;

    // 1. Read Load Cell Weight with 10-sample average + 0.4g deadband filter
    double raw_weight = scale.get_units(10);
    if (raw_weight < 0.0) raw_weight = 0.0;

    if (firstReading) {
      filteredWeight = raw_weight;
      prevWeight     = raw_weight;
      firstReading   = false;
    } else if (fabs(raw_weight - filteredWeight) >= WEIGHT_DEADBAND_G) {
      filteredWeight = raw_weight;
    }

    double current_weight = filteredWeight;

    // 2. IDLE GUARD (0.0g - 9.9g): Hook is empty -> pause timer & turn off buzzer
    if (current_weight < NO_BAG_WEIGHT_G) {
      prevWeight         = current_weight;
      timerInitialized   = false;
      resetRateWindow();
      runStartMillis     = currentMillis;
      liveTimestamp      = getIsoTimestamp();
      liveElapsedSec     = 0.0;
      liveWeightG        = current_weight;
      liveDripRate       = 0.0;
      liveWeightLossRate = 0.0;
      liveRemainingSec   = 0.0;
      liveStatus         = "NO_BAG";
      updateHardwareOutputs(current_weight, 0.0, liveStatus);
      return;
    }

    // 3. Auto-Detect New IV Bag (weight jumps up by > 30g)
    if ((current_weight - prevWeight) >= NEW_BAG_JUMP_G) {
      experimentNumber++;
      char expBuf[12];
      sprintf(expBuf, "EXP_%03d", experimentNumber);
      experimentId     = String(expBuf);
      runStartMillis   = currentMillis;
      timerInitialized = false;
      resetRateWindow();
    }

    // 4. Compute Smooth Rolling Weight-Loss Rate & Drip Rate (after 5s settle + 60s window)
    double elapsed_time     = (currentMillis - runStartMillis) / 1000.0;
    double weight_loss_rate = computeRollingLossRate(current_weight, elapsed_time);
    double drip_rate        = weight_loss_rate * (GTT_PER_GRAM * 60.0);
    prevWeight              = current_weight;

    // 5. Run AI Model Inference (kept active for model telemetry)
    double model_input_weight = current_weight + MODEL_BASELINE_OFFSET_G;
    double features[] = {
      elapsed_time,
      model_input_weight,
      drip_rate,
      weight_loss_rate
    };
    double ai_pred_sec = predict_model(features);
    if (ai_pred_sec < 0.0) ai_pred_sec = 0.0;
    (void)ai_pred_sec;

    // 6. Exact Weight-to-Time Formula (500g = ~4h, 1000g = ~8h)
    // Net fluid remaining above the 10g empty-bag floor
    double fluid_left_g = current_weight - NO_BAG_WEIGHT_G;
    if (fluid_left_g < 0.0) fluid_left_g = 0.0;

    if (!timerInitialized) {
      // Lock initial time strictly to weight: 490g / 0.03472 g/s = 14,112s (~3h 55m)
      smoothedLossRate = BASELINE_LOSS_RATE_GS;
      liveRemainingSec = fluid_left_g / smoothedLossRate;
      timerInitialized = true;
    } else if (weight_loss_rate <= 0.0) {
      // Static / settling weight: strictly decrement 1.0s per second (no sudden drops)
      liveRemainingSec -= dt_sec;
      if (liveRemainingSec < 0.0) liveRemainingSec = 0.0;
    } else {
      // Sustained dripping after 65s: blend flow rate gently & limit step to max -2s/tick
      smoothedLossRate = (0.02 * weight_loss_rate) + (0.98 * smoothedLossRate);
      double target_sec = fluid_left_g / smoothedLossRate;
      double step = 0.01 * (target_sec - liveRemainingSec);
      if (step < -2.0) step = -2.0; // Never drop more than 2 extra seconds per second
      if (step > 0.0)  step = 0.0;  // Never count upward
      liveRemainingSec += step - dt_sec;
      if (liveRemainingSec < 0.0) liveRemainingSec = 0.0;
    }

    // 7. Update Live Telemetry & Status
    liveTimestamp      = getIsoTimestamp();
    liveElapsedSec     = elapsed_time;
    liveWeightG        = current_weight;
    liveDripRate       = drip_rate;
    liveWeightLossRate = weight_loss_rate;

    // 10.0g to 50.0g -> CRITICAL (Red LED + Buzzer ON until bag is removed < 10.0g)
    if (current_weight <= EMPTY_BAG_WEIGHT_G || liveRemainingSec <= CRITICAL_TIME_SEC) {
      liveStatus = "CRITICAL";
    } else if (liveRemainingSec <= WARNING_TIME_SEC) {
      liveStatus = "WARNING";
    } else {
      liveStatus = "NORMAL";
    }

    // 8. Update LEDs, Buzzer, and LCD
    updateHardwareOutputs(current_weight, liveRemainingSec, liveStatus);
  }
}