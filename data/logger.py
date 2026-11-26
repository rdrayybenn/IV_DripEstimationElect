import csv
import os
import serial
from datetime import datetime

# Change 'COM3' to your ESP32 port
PORT = 'COM6'
BAUD = 115200
OUTPUT_FILE = 'iv_drip_dataset8hrsRun2.csv'
RUN_DURATION_SECONDS = 8 * 60 * 60
EXPERIMENT_INTERVAL_SECONDS = 2 * 60 * 60
DROP_FACTOR_DROPS_PER_ML = 20
# Approximate density confirmed by the user for estimating drops per minute.
FLUID_DENSITY_G_PER_ML = 1.017

CSV_COLUMNS = [
    'experiment_id',
    'timestamp',
    'elapsed_time',
    'current_weight',
    'drip_rate',
    'weight_loss_rate',
    'remaining_time',
]
LEGACY_COLUMNS = CSV_COLUMNS[:4]


def experiment_id_for_elapsed(elapsed):
    if elapsed < 0:
        raise ValueError(f"Elapsed time cannot be negative: {elapsed}")
    if elapsed > RUN_DURATION_SECONDS:
        return 'EXP_005'

    experiment_number = min(
        int(elapsed // EXPERIMENT_INTERVAL_SECONDS) + 1,
        RUN_DURATION_SECONDS // EXPERIMENT_INTERVAL_SECONDS,
    )
    return f'EXP_{experiment_number:03d}'


def prepare_output_file():
    if not os.path.exists(OUTPUT_FILE) or os.path.getsize(OUTPUT_FILE) == 0:
        return

    with open(OUTPUT_FILE, mode='r', newline='') as file:
        reader = csv.reader(file)
        header = next(reader, None)

    if header == CSV_COLUMNS:
        return
    if header != LEGACY_COLUMNS:
        raise ValueError(
            f"Unexpected CSV header in {OUTPUT_FILE}: {header}. "
            "Rename the file or update its columns before logging."
        )

    temporary_file = OUTPUT_FILE + '.tmp'
    with open(OUTPUT_FILE, mode='r', newline='') as source, \
            open(temporary_file, mode='w', newline='') as destination:
        reader = csv.reader(source)
        writer = csv.writer(destination)
        header = next(reader, None)
        if header != LEGACY_COLUMNS:
            raise ValueError(f"CSV header changed while preparing {OUTPUT_FILE}.")
        writer.writerow(CSV_COLUMNS)
        for row in reader:
            if len(row) != len(LEGACY_COLUMNS):
                raise ValueError(f"Unexpected row in {OUTPUT_FILE}: {row}")
            writer.writerow(row + ['', '', ''])

    os.replace(temporary_file, OUTPUT_FILE)


prepare_output_file()
ser = serial.Serial(PORT, BAUD, timeout=1)

with open(OUTPUT_FILE, mode='a', newline='') as file:
    writer = csv.writer(file)
    if file.tell() == 0:
        writer.writerow(CSV_COLUMNS)

    print("Connected! Type 's' + Enter to start a run, 'r' + Enter to stop.")

    import threading

    def send_commands():
        while True:
            cmd = input()
            ser.write(cmd.encode())

    threading.Thread(target=send_commands, daemon=True).start()
    previous_experiment_id = None
    previous_elapsed = None
    previous_weight = None

    while True:
        line = ser.readline().decode('utf-8', errors='ignore').strip()
        if not line:
            continue

        if line.startswith("DATA:"):
            # Parse DATA:EXP_001,12,495.20
            parts = line.replace("DATA:", "").split(",")
            if len(parts) != 3:
                raise ValueError(f"Unexpected DATA message: {line}")

            _, elapsed_text, weight_text = parts
            elapsed = float(elapsed_text)
            weight = float(weight_text)
            exp_id = experiment_id_for_elapsed(elapsed)
            ts = datetime.now().strftime("%Y-%m-%dT%H:%M:%S")

            if (exp_id == previous_experiment_id
                    and previous_elapsed is not None
                    and previous_weight is not None
                    and elapsed > previous_elapsed):
                weight_loss_rate = (previous_weight - weight) / (elapsed - previous_elapsed)
            else:
                weight_loss_rate = 0.0

            drip_rate = (
                weight_loss_rate
                * 60
                * DROP_FACTOR_DROPS_PER_ML
                / FLUID_DENSITY_G_PER_ML
            )
            remaining_time = max(0, round(RUN_DURATION_SECONDS - elapsed))

            writer.writerow([
                exp_id,
                ts,
                elapsed_text,
                weight_text,
                round(drip_rate, 2),
                round(weight_loss_rate, 6),
                remaining_time,
            ])
            file.flush()
            print(f"Saved -> {exp_id} | {ts} | {elapsed}s | {weight}g")

            previous_experiment_id = exp_id
            previous_elapsed = elapsed
            previous_weight = weight

        elif line.startswith("INIT_WEIGHT:"):
            print(f"\n>>> RECORD THIS INITIAL WEIGHT: {line.replace('INIT_WEIGHT:', '')} g <<<\n")
        else:
            print(line)
