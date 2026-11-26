/* Generated GradientBoostingRegressor C model */

#ifndef BEST_IV_MODEL_20261125_020948_539740_H_
#define BEST_IV_MODEL_20261125_020948_539740_H_

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GB_N_FEATURES 4
#define GB_N_ESTIMATORS 100
#define GB_LEARNING_RATE (0.050000000000000003)
#define GB_INITIAL_VALUE (3620.2365977466879)

static const int gb_tree_0_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_0_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_0_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_0_threshold[7] = {3580.5, 1783.5, -2, -2, 5387.5, -2, -2};
static const double gb_tree_0_value[7] = {6.1347765407832983e-11, 1799.535381973925, 2684.4322030413641, 906.94571720616989, -1803.9968555872138, -909.89628232031919, -2709.0255725533048};

static double gb_tree_0_predict(const double *x)
{
    int node = 0;
    while (gb_tree_0_left[node] != -1) {
        int f = gb_tree_0_feature[node];
        if (x[f] <= gb_tree_0_threshold[node])
            node = gb_tree_0_left[node];
        else
            node = gb_tree_0_right[node];
    }
    return gb_tree_0_value[node];
}

static const int gb_tree_1_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_1_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_1_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_1_threshold[7] = {3665.5, 1901.5, -2, -2, 5505.5, -2, -2};
static const double gb_tree_1_value[7] = {5.474663777355858e-11, 1671.3310290555662, 2498.2165718757578, 766.13320641472546, -1754.0281999937019, -954.74290645286237, -2628.0408304072243};

static double gb_tree_1_predict(const double *x)
{
    int node = 0;
    while (gb_tree_1_left[node] != -1) {
        int f = gb_tree_1_feature[node];
        if (x[f] <= gb_tree_1_threshold[node])
            node = gb_tree_1_left[node];
        else
            node = gb_tree_1_right[node];
    }
    return gb_tree_1_value[node];
}

static const int gb_tree_2_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_2_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_2_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_2_threshold[7] = {3433.5, 1557.5, -2, -2, 5182.5, -2, -2};
static const double gb_tree_2_value[7] = {-1.0817812841707421e-10, 1691.2221104220812, 2540.4833808101434, 981.93353583803912, -1568.1434314246737, -661.6936828896786, -2360.6788779298527};

static double gb_tree_2_predict(const double *x)
{
    int node = 0;
    while (gb_tree_2_left[node] != -1) {
        int f = gb_tree_2_feature[node];
        if (x[f] <= gb_tree_2_threshold[node])
            node = gb_tree_2_left[node];
        else
            node = gb_tree_2_right[node];
    }
    return gb_tree_2_value[node];
}

static const int gb_tree_3_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_3_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_3_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_3_threshold[7] = {3796.5, 2069.5, -2, -2, 5696.5, -2, -2};
static const double gb_tree_3_value[7] = {6.4907147297524975e-11, 1459.6858500842823, 2193.9835130075235, 557.83289861680873, -1642.9148370553969, -992.89008041659054, -2474.6501735343536};

static double gb_tree_3_predict(const double *x)
{
    int node = 0;
    while (gb_tree_3_left[node] != -1) {
        int f = gb_tree_3_feature[node];
        if (x[f] <= gb_tree_3_threshold[node])
            node = gb_tree_3_left[node];
        else
            node = gb_tree_3_right[node];
    }
    return gb_tree_3_value[node];
}

static const int gb_tree_4_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_4_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_4_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_4_threshold[7] = {3323.5, 1400.5, -2, -2, 5049.5, -2, -2};
static const double gb_tree_4_value[7] = {1.6585469712292592e-11, 1571.0177479469496, 2381.9726722422201, 981.46815482171451, -1381.6548175368421, -500.25194108206165, -2090.106657373577};

static double gb_tree_4_predict(const double *x)
{
    int node = 0;
    while (gb_tree_4_left[node] != -1) {
        int f = gb_tree_4_feature[node];
        if (x[f] <= gb_tree_4_threshold[node])
            node = gb_tree_4_left[node];
        else
            node = gb_tree_4_right[node];
    }
    return gb_tree_4_value[node];
}

static const int gb_tree_5_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_5_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_5_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_5_threshold[7] = {3906.5, 2189.5, -2, -2, 5852.5, -2, -2};
static const double gb_tree_5_value[7] = {-4.0365203537946987e-11, 1280.7748550896397, 1947.6114900962498, 410.91963199044483, -1533.7588150392417, -994.8360684666377, -2326.9211760842791};

static double gb_tree_5_predict(const double *x)
{
    int node = 0;
    while (gb_tree_5_left[node] != -1) {
        int f = gb_tree_5_feature[node];
        if (x[f] <= gb_tree_5_threshold[node])
            node = gb_tree_5_left[node];
        else
            node = gb_tree_5_right[node];
    }
    return gb_tree_5_value[node];
}

static const int gb_tree_6_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_6_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_6_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_6_threshold[7] = {3229.5, 1274.5, -2, -2, 4951.5, -2, -2};
static const double gb_tree_6_value[7] = {-2.878375633394188e-11, 1457.569732648323, 2227.8440712722063, 957.11583133222757, -1220.1945640876331, -381.55364566333014, -1863.7987905286477};

static double gb_tree_6_predict(const double *x)
{
    int node = 0;
    while (gb_tree_6_left[node] != -1) {
        int f = gb_tree_6_feature[node];
        if (x[f] <= gb_tree_6_threshold[node])
            node = gb_tree_6_left[node];
        else
            node = gb_tree_6_right[node];
    }
    return gb_tree_6_value[node];
}

static const int gb_tree_7_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_7_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_7_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_7_threshold[7] = {3992.5, 2278.5, -2, -2, 5970, -2, -2};
static const double gb_tree_7_value[7] = {3.1735307048671608e-11, 1132.1609730337823, 1737.8328074578594, 306.56310729757934, -1422.1586300931431, -962.13875421096316, -2175.7505122491907};

static double gb_tree_7_predict(const double *x)
{
    int node = 0;
    while (gb_tree_7_left[node] != -1) {
        int f = gb_tree_7_feature[node];
        if (x[f] <= gb_tree_7_threshold[node])
            node = gb_tree_7_left[node];
        else
            node = gb_tree_7_right[node];
    }
    return gb_tree_7_value[node];
}

static const int gb_tree_8_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_8_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_8_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_8_threshold[7] = {3151.5, 1166.5, -2, -2, 4875.5, -2, -2};
static const double gb_tree_8_value[7] = {3.1337142722130927e-11, 1348.8059748672354, 2084.1045667631884, 919.23338480459336, -1080.7894441788035, -291.22401633910727, -1666.9424458838105};

static double gb_tree_8_predict(const double *x)
{
    int node = 0;
    while (gb_tree_8_left[node] != -1) {
        int f = gb_tree_8_feature[node];
        if (x[f] <= gb_tree_8_threshold[node])
            node = gb_tree_8_left[node];
        else
            node = gb_tree_8_right[node];
    }
    return gb_tree_8_value[node];
}

static const int gb_tree_9_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_9_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_9_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_9_threshold[7] = {4067, 2002.5, -2, -2, 6072, -2, -2};
static const double gb_tree_9_value[7] = {-2.4967076512647664e-11, 1004.1268321323664, 1660.6979436283125, 352.98192816944157, -1314.4358960360209, -919.96443246003253, -2039.5272556557684};

static double gb_tree_9_predict(const double *x)
{
    int node = 0;
    while (gb_tree_9_left[node] != -1) {
        int f = gb_tree_9_feature[node];
        if (x[f] <= gb_tree_9_threshold[node])
            node = gb_tree_9_left[node];
        else
            node = gb_tree_9_right[node];
    }
    return gb_tree_9_value[node];
}

static const int gb_tree_10_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_10_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_10_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_10_threshold[7] = {3071.5, 1060.5, -2, -2, 5260.5, -2, -2};
static const double gb_tree_10_value[7] = {-6.9409635894496809e-12, 1254.5163343444792, 1951.1166759501946, 889.02929921799137, -955.21617737719885, -363.9041409016254, -1628.578274884346};

static double gb_tree_10_predict(const double *x)
{
    int node = 0;
    while (gb_tree_10_left[node] != -1) {
        int f = gb_tree_10_feature[node];
        if (x[f] <= gb_tree_10_threshold[node])
            node = gb_tree_10_left[node];
        else
            node = gb_tree_10_right[node];
    }
    return gb_tree_10_value[node];
}

static const int gb_tree_11_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_11_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_11_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_11_threshold[7] = {4136.5, 2384.5, -2, -2, 6171.5, -2, -2};
static const double gb_tree_11_value[7] = {-1.2693627366121138e-11, 892.61096387546161, 1406.4207367741117, 179.43983880648003, -1216.6982096826846, -880.62679256164438, -1908.9993115590269};

static double gb_tree_11_predict(const double *x)
{
    int node = 0;
    while (gb_tree_11_left[node] != -1) {
        int f = gb_tree_11_feature[node];
        if (x[f] <= gb_tree_11_threshold[node])
            node = gb_tree_11_left[node];
        else
            node = gb_tree_11_right[node];
    }
    return gb_tree_11_value[node];
}

static const int gb_tree_12_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_12_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_12_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_12_threshold[7] = {3493.5, 1460.5, -2, -2, 5612.5, -2, -2};
static const double gb_tree_12_value[7] = {5.8448293596108083e-12, 1012.2877154230872, 1620.4094923805412, 573.96359675429801, -970.55401550272882, -510.7700629430521, -1588.3029577312777};

static double gb_tree_12_predict(const double *x)
{
    int node = 0;
    while (gb_tree_12_left[node] != -1) {
        int f = gb_tree_12_feature[node];
        if (x[f] <= gb_tree_12_threshold[node])
            node = gb_tree_12_left[node];
        else
            node = gb_tree_12_right[node];
    }
    return gb_tree_12_value[node];
}

static const int gb_tree_13_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_13_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_13_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_13_threshold[7] = {4213.5, 2445.5, -2, -2, 6260.5, -2, -2};
static const double gb_tree_13_value[7] = {2.102704006812796e-11, 791.1006781044025, 1261.1461312072513, 127.45092715166444, -1128.8873558647979, -841.04804507751908, -1777.440250649368};

static double gb_tree_13_predict(const double *x)
{
    int node = 0;
    while (gb_tree_13_left[node] != -1) {
        int f = gb_tree_13_feature[node];
        if (x[f] <= gb_tree_13_threshold[node])
            node = gb_tree_13_left[node];
        else
            node = gb_tree_13_right[node];
    }
    return gb_tree_13_value[node];
}

static const int gb_tree_14_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_14_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_14_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_14_threshold[7] = {2986.5, 935.5, -2, -2, 4769.5, -2, -2};
static const double gb_tree_14_value[7] = {-3.6303781023288465e-12, 1058.1165848020701, 1701.4830284662157, 765.16247853074606, -765.11704835979765, -138.65751072589077, -1226.6638399807678};

static double gb_tree_14_predict(const double *x)
{
    int node = 0;
    while (gb_tree_14_left[node] != -1) {
        int f = gb_tree_14_feature[node];
        if (x[f] <= gb_tree_14_threshold[node])
            node = gb_tree_14_left[node];
        else
            node = gb_tree_14_right[node];
    }
    return gb_tree_14_value[node];
}

static const int gb_tree_15_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_15_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_15_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_15_threshold[7] = {4258, 1695.5, -2, -2, 6320, -2, -2};
static const double gb_tree_15_value[7] = {-4.2879235165919407e-12, 707.4447836058232, 1335.3939598205518, 284.86883352103689, -1033.8416759963322, -777.95301157007361, -1659.9894110602836};

static double gb_tree_15_predict(const double *x)
{
    int node = 0;
    while (gb_tree_15_left[node] != -1) {
        int f = gb_tree_15_feature[node];
        if (x[f] <= gb_tree_15_threshold[node])
            node = gb_tree_15_left[node];
        else
            node = gb_tree_15_right[node];
    }
    return gb_tree_15_value[node];
}

static const int gb_tree_16_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_16_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_16_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_16_threshold[7] = {2935.5, 860.5, -2, -2, 4814.5, -2, -2};
static const double gb_tree_16_value[7] = {9.3445034907767314e-12, 975.07621047911982, 1588.3597940732616, 722.33375946811441, -685.41093943444832, -135.32387718551067, -1120.6195479734856};

static double gb_tree_16_predict(const double *x)
{
    int node = 0;
    while (gb_tree_16_left[node] != -1) {
        int f = gb_tree_16_feature[node];
        if (x[f] <= gb_tree_16_threshold[node])
            node = gb_tree_16_left[node];
        else
            node = gb_tree_16_right[node];
    }
    return gb_tree_16_value[node];
}

static const int gb_tree_17_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_17_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_17_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_17_threshold[7] = {2898.5, 820.5, -2, -2, 5320.5, -2, -2};
static const double gb_tree_17_value[7] = {-2.4258916034815555e-12, 936.15934426074023, 1530.5213737821114, 704.21012674592009, -644.55749980614837, -231.78339127354977, -1181.7496882019407};

static double gb_tree_17_predict(const double *x)
{
    int node = 0;
    while (gb_tree_17_left[node] != -1) {
        int f = gb_tree_17_feature[node];
        if (x[f] <= gb_tree_17_threshold[node])
            node = gb_tree_17_left[node];
        else
            node = gb_tree_17_right[node];
    }
    return gb_tree_17_value[node];
}

static const int gb_tree_18_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_18_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_18_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_18_threshold[7] = {3854.5, 1615, -2, -2, 6027.5, -2, -2};
static const double gb_tree_18_value[7] = {-7.6101352669241224e-12, 686.69841563714044, 1178.69656340951, 326.63273207192066, -797.50364566907342, -512.61958311214937, -1337.2607463772104};

static double gb_tree_18_predict(const double *x)
{
    int node = 0;
    while (gb_tree_18_left[node] != -1) {
        int f = gb_tree_18_feature[node];
        if (x[f] <= gb_tree_18_threshold[node])
            node = gb_tree_18_left[node];
        else
            node = gb_tree_18_right[node];
    }
    return gb_tree_18_value[node];
}

static const int gb_tree_19_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_19_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_19_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_19_threshold[7] = {4324, 2491.5, -2, -2, 6422.5, -2, -2};
static const double gb_tree_19_value[7] = {-1.0939835118985646e-11, 572.13594146095227, 938.71747521972623, 62.805149337921776, -869.71803644228396, -664.52783318534955, -1446.0306275268335};

static double gb_tree_19_predict(const double *x)
{
    int node = 0;
    while (gb_tree_19_left[node] != -1) {
        int f = gb_tree_19_feature[node];
        if (x[f] <= gb_tree_19_threshold[node])
            node = gb_tree_19_left[node];
        else
            node = gb_tree_19_right[node];
    }
    return gb_tree_19_value[node];
}

static const int gb_tree_20_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_20_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_20_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_20_threshold[7] = {2854.5, 754.5, -2, -2, 4696.5, -2, -2};
static const double gb_tree_20_value[7] = {1.5347230454146496e-12, 819.20108929340802, 1382.4563714297981, 619.96951516543413, -549.72147162990279, -67.507297524745383, -904.86393863749004};

static double gb_tree_20_predict(const double *x)
{
    int node = 0;
    while (gb_tree_20_left[node] != -1) {
        int f = gb_tree_20_feature[node];
        if (x[f] <= gb_tree_20_threshold[node])
            node = gb_tree_20_left[node];
        else
            node = gb_tree_20_right[node];
    }
    return gb_tree_20_value[node];
}

static const int gb_tree_21_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_21_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_21_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_21_threshold[7] = {4352.5, 1844.5, -2, -2, 6462.5, -2, -2};
static const double gb_tree_21_value[7] = {-9.8047120887891086e-12, 513.38415872298708, 970.5298311713841, 170.83075563950337, -792.83850626542358, -606.40527075289424, -1349.4464586178374};

static double gb_tree_21_predict(const double *x)
{
    int node = 0;
    while (gb_tree_21_left[node] != -1) {
        int f = gb_tree_21_feature[node];
        if (x[f] <= gb_tree_21_threshold[node])
            node = gb_tree_21_left[node];
        else
            node = gb_tree_21_right[node];
    }
    return gb_tree_21_value[node];
}

static const int gb_tree_22_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_22_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_22_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_22_threshold[7] = {3027.5, 976.5, -2, -2, 5755.5, -2, -2};
static const double gb_tree_22_value[7] = {-2.1167399749415562e-12, 708.13784543065628, 1173.0370219321405, 487.74932072118406, -524.67374580617945, -255.02786127158993, -1039.8597817849234};

static double gb_tree_22_predict(const double *x)
{
    int node = 0;
    while (gb_tree_22_left[node] != -1) {
        int f = gb_tree_22_feature[node];
        if (x[f] <= gb_tree_22_threshold[node])
            node = gb_tree_22_left[node];
        else
            node = gb_tree_22_right[node];
    }
    return gb_tree_22_value[node];
}

static const int gb_tree_23_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_23_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_23_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_23_threshold[7] = {4389.5, 2326.5, -2, -2, 6513.5, -2, -2};
static const double gb_tree_23_value[7] = {-2.6592332397015566e-12, 462.40079295622701, 799.02901221954028, 73.791596759781214, -727.78760879887113, -564.36428394100903, -1255.0341740474312};

static double gb_tree_23_predict(const double *x)
{
    int node = 0;
    while (gb_tree_23_left[node] != -1) {
        int f = gb_tree_23_feature[node];
        if (x[f] <= gb_tree_23_threshold[node])
            node = gb_tree_23_left[node];
        else
            node = gb_tree_23_right[node];
    }
    return gb_tree_23_value[node];
}

static const int gb_tree_24_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_24_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_24_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_24_threshold[7] = {2802.5, 676.5, -2, -2, 5560.5, -2, -2};
static const double gb_tree_24_value[7] = {-1.174449639654778e-13, 684.65495565498622, 1203.4469448151133, 521.10757388550667, -446.33145948465273, -179.28286381441495, -898.49746504254017};

static double gb_tree_24_predict(const double *x)
{
    int node = 0;
    while (gb_tree_24_left[node] != -1) {
        int f = gb_tree_24_feature[node];
        if (x[f] <= gb_tree_24_threshold[node])
            node = gb_tree_24_left[node];
        else
            node = gb_tree_24_right[node];
    }
    return gb_tree_24_value[node];
}

static const int gb_tree_25_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_25_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_25_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_25_threshold[7] = {4171.5, 1316.5, -2, -2, 6370.5, -2, -2};
static const double gb_tree_25_value[7] = {3.982178129816041e-12, 447.20348185627148, 925.74567313013108, 223.87383696624468, -622.4034245556802, -453.47477603595996, -1086.9806572697753};

static double gb_tree_25_predict(const double *x)
{
    int node = 0;
    while (gb_tree_25_left[node] != -1) {
        int f = gb_tree_25_feature[node];
        if (x[f] <= gb_tree_25_threshold[node])
            node = gb_tree_25_left[node];
        else
            node = gb_tree_25_right[node];
    }
    return gb_tree_25_value[node];
}

static const int gb_tree_26_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_26_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_26_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_26_threshold[7] = {3279, 1009.5, -2, -2, 5896.5, -2, -2};
static const double gb_tree_26_value[7] = {-8.9997974544015463e-14, 542.8071122932248, 968.10021200488063, 354.64613888918223, -466.45924267742453, -256.41905766475281, -892.24802191218828};

static double gb_tree_26_predict(const double *x)
{
    int node = 0;
    while (gb_tree_26_left[node] != -1) {
        int f = gb_tree_26_feature[node];
        if (x[f] <= gb_tree_26_threshold[node])
            node = gb_tree_26_left[node];
        else
            node = gb_tree_26_right[node];
    }
    return gb_tree_26_value[node];
}

static const int gb_tree_27_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_27_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_27_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_27_threshold[7] = {4446, 1649.5, -2, -2, 6597.5, -2, -2};
static const double gb_tree_27_value[7] = {2.4511146829909197e-12, 377.28743085896036, 767.45365661557844, 143.39997979726613, -612.27275067949779, -483.94352752112042, -1090.528090400946};

static double gb_tree_27_predict(const double *x)
{
    int node = 0;
    while (gb_tree_27_left[node] != -1) {
        int f = gb_tree_27_feature[node];
        if (x[f] <= gb_tree_27_threshold[node])
            node = gb_tree_27_left[node];
        else
            node = gb_tree_27_right[node];
    }
    return gb_tree_27_value[node];
}

static const int gb_tree_28_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_28_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_28_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_28_threshold[7] = {2753, 595.5, -2, -2, 5103.5, -2, -2};
static const double gb_tree_28_value[7] = {3.6993474603622649e-12, 577.4521371958034, 1050.5696176882552, 447.73724889466638, -365.35783089200561, -91.949753929388265, -673.81671746308973};

static double gb_tree_28_predict(const double *x)
{
    int node = 0;
    while (gb_tree_28_left[node] != -1) {
        int f = gb_tree_28_feature[node];
        if (x[f] <= gb_tree_28_threshold[node])
            node = gb_tree_28_left[node];
        else
            node = gb_tree_28_right[node];
    }
    return gb_tree_28_value[node];
}

static const int gb_tree_29_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_29_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_29_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_29_threshold[7] = {2733.5, 572.5, -2, -2, 4665.5, -2, -2};
static const double gb_tree_29_value[7] = {7.4551653420367896e-13, 551.42587058673701, 1009.4247688118953, 430.90473919586447, -345.35591874758791, -26.429324428699637, -587.51644121394907};

static double gb_tree_29_predict(const double *x)
{
    int node = 0;
    while (gb_tree_29_left[node] != -1) {
        int f = gb_tree_29_feature[node];
        if (x[f] <= gb_tree_29_threshold[node])
            node = gb_tree_29_left[node];
        else
            node = gb_tree_29_right[node];
    }
    return gb_tree_29_value[node];
}

static const int gb_tree_30_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_30_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_30_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_30_threshold[7] = {3734, 1118.5, -2, -2, 6221.5, -2, -2};
static const double gb_tree_30_value[7] = {2.5453634220504641e-12, 397.80946797814062, 776.12041737206698, 233.74374550134053, -433.09486945642482, -281.27080850154317, -833.31936864497504};

static double gb_tree_30_predict(const double *x)
{
    int node = 0;
    while (gb_tree_30_left[node] != -1) {
        int f = gb_tree_30_feature[node];
        if (x[f] <= gb_tree_30_threshold[node])
            node = gb_tree_30_left[node];
        else
            node = gb_tree_30_right[node];
    }
    return gb_tree_30_value[node];
}

static const int gb_tree_31_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_31_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_31_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_31_threshold[7] = {2708.5, 536.5, -2, -2, 5785.5, -2, -2};
static const double gb_tree_31_value[7] = {-1.104973567970502e-12, 504.72471884918025, 936.58224637406943, 398.00482023738169, -311.66890368908577, -139.22949882221408, -690.14195448617193};

static double gb_tree_31_predict(const double *x)
{
    int node = 0;
    while (gb_tree_31_left[node] != -1) {
        int f = gb_tree_31_feature[node];
        if (x[f] <= gb_tree_31_threshold[node])
            node = gb_tree_31_left[node];
        else
            node = gb_tree_31_right[node];
    }
    return gb_tree_31_value[node];
}

static const int gb_tree_32_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_32_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_32_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_32_threshold[7] = {4476.5, 2134.5, -2, -2, 6661.5, -2, -2};
static const double gb_tree_32_value[7] = {-1.7859967147233397e-12, 295.27721980221594, 544.12903496451474, 63.426219492669425, -488.2162441736096, -384.27105930245631, -930.74626266652001};

static double gb_tree_32_predict(const double *x)
{
    int node = 0;
    while (gb_tree_32_left[node] != -1) {
        int f = gb_tree_32_feature[node];
        if (x[f] <= gb_tree_32_threshold[node])
            node = gb_tree_32_left[node];
        else
            node = gb_tree_32_right[node];
    }
    return gb_tree_32_value[node];
}

static const int gb_tree_33_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_33_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_33_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_33_threshold[7] = {4494.5, 1227.5, -2, -2, 6685.5, -2, -2};
static const double gb_tree_33_value[7] = {4.1843568765082895e-12, 279.02518366000282, 654.45377802845417, 135.16312478062665, -466.36473147867611, -370.68739468019589, -899.5364400372016};

static double gb_tree_33_predict(const double *x)
{
    int node = 0;
    while (gb_tree_33_left[node] != -1) {
        int f = gb_tree_33_feature[node];
        if (x[f] <= gb_tree_33_threshold[node])
            node = gb_tree_33_left[node];
        else
            node = gb_tree_33_right[node];
    }
    return gb_tree_33_value[node];
}

static const int gb_tree_34_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_34_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_34_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_34_threshold[7] = {2688.5, 500.5, -2, -2, 5449.5, -2, -2};
static const double gb_tree_34_value[7] = {-1.4001342695951508e-12, 441.63684574095629, 846.2852015384824, 348.30652921174766, -269.36590551470232, -92.969145318862132, -548.91069395490399};

static double gb_tree_34_predict(const double *x)
{
    int node = 0;
    while (gb_tree_34_left[node] != -1) {
        int f = gb_tree_34_feature[node];
        if (x[f] <= gb_tree_34_threshold[node])
            node = gb_tree_34_left[node];
        else
            node = gb_tree_34_right[node];
    }
    return gb_tree_34_value[node];
}

static const int gb_tree_35_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_35_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_35_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_35_threshold[7] = {3375.5, 715.5, -2, -2, 6347.5, -2, -2};
static const double gb_tree_35_value[7] = {-3.6140788132262549e-12, 344.75571657420471, 725.57381361838372, 242.85196414416106, -311.98766143755233, -204.3858607456512, -697.34278665995032};

static double gb_tree_35_predict(const double *x)
{
    int node = 0;
    while (gb_tree_35_left[node] != -1) {
        int f = gb_tree_35_feature[node];
        if (x[f] <= gb_tree_35_threshold[node])
            node = gb_tree_35_left[node];
        else
            node = gb_tree_35_right[node];
    }
    return gb_tree_35_value[node];
}

static const int gb_tree_36_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_36_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_36_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_36_threshold[7] = {4516, 1495.5, -2, -2, 6729.5, -2, -2};
static const double gb_tree_36_value[7] = {9.4609068766821135e-13, 241.29231316382223, 526.76786520205201, 98.132610523293209, -408.88884227373558, -327.64793134934695, -815.17471912889414};

static double gb_tree_36_predict(const double *x)
{
    int node = 0;
    while (gb_tree_36_left[node] != -1) {
        int f = gb_tree_36_feature[node];
        if (x[f] <= gb_tree_36_threshold[node])
            node = gb_tree_36_left[node];
        else
            node = gb_tree_36_right[node];
    }
    return gb_tree_36_value[node];
}

static const int gb_tree_37_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_37_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_37_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_37_threshold[7] = {2662.5, 455.5, -2, -2, 5923.5, -2, -2};
static const double gb_tree_37_value[7] = {-9.0717226420649678e-13, 387.29091857196153, 762.60333246365803, 308.75456864728028, -232.63550816322046, -112.13373826665124, -545.37344677973124};

static double gb_tree_37_predict(const double *x)
{
    int node = 0;
    while (gb_tree_37_left[node] != -1) {
        int f = gb_tree_37_feature[node];
        if (x[f] <= gb_tree_37_threshold[node])
            node = gb_tree_37_left[node];
        else
            node = gb_tree_37_right[node];
    }
    return gb_tree_37_value[node];
}

static const int gb_tree_38_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_38_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_38_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_38_threshold[7] = {4422.5, 1200.5, -2, -2, 6750.5, -2, -2};
static const double gb_tree_38_value[7] = {1.1402042420843072e-12, 226.17463658748699, 522.81362039222984, 113.71170053175929, -362.64487661706795, -290.82982222748365, -758.41892242405333};

static double gb_tree_38_predict(const double *x)
{
    int node = 0;
    while (gb_tree_38_left[node] != -1) {
        int f = gb_tree_38_feature[node];
        if (x[f] <= gb_tree_38_threshold[node])
            node = gb_tree_38_left[node];
        else
            node = gb_tree_38_right[node];
    }
    return gb_tree_38_value[node];
}

static const int gb_tree_39_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_39_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_39_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_39_threshold[7] = {2776.5, 439.5, -2, -2, 6122.5, -2, -2};
static const double gb_tree_39_value[7] = {-1.5627893515204938e-13, 341.61971840627348, 706.09034004329783, 271.97083334339226, -219.20598597736165, -121.06814028780121, -533.04612731220948};

static double gb_tree_39_predict(const double *x)
{
    int node = 0;
    while (gb_tree_39_left[node] != -1) {
        int f = gb_tree_39_feature[node];
        if (x[f] <= gb_tree_39_threshold[node])
            node = gb_tree_39_left[node];
        else
            node = gb_tree_39_right[node];
    }
    return gb_tree_39_value[node];
}

static const int gb_tree_40_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_40_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_40_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_40_threshold[7] = {4547.5, 2527.5, -2, -2, 6783.5, -2, -2};
static const double gb_tree_40_value[7] = {9.4994734156640652e-14, 198.99375380237055, 348.23526182630479, 7.8342118706759791, -343.82034598205047, -279.07113204821798, -708.46065603057366};

static double gb_tree_40_predict(const double *x)
{
    int node = 0;
    while (gb_tree_40_left[node] != -1) {
        int f = gb_tree_40_feature[node];
        if (x[f] <= gb_tree_40_threshold[node])
            node = gb_tree_40_left[node];
        else
            node = gb_tree_40_right[node];
    }
    return gb_tree_40_value[node];
}

static const int gb_tree_41_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_41_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_41_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_41_threshold[7] = {4559.5, 900.5, -2, -2, 6637.5, -2, -2};
static const double gb_tree_41_value[7] = {1.972284358309521e-12, 188.30402927684563, 515.75455841195674, 106.90952495477771, -327.96604691769642, -253.69421426805411, -615.05642564016773};

static double gb_tree_41_predict(const double *x)
{
    int node = 0;
    while (gb_tree_41_left[node] != -1) {
        int f = gb_tree_41_feature[node];
        if (x[f] <= gb_tree_41_threshold[node])
            node = gb_tree_41_left[node];
        else
            node = gb_tree_41_right[node];
    }
    return gb_tree_41_value[node];
}

static const int gb_tree_42_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_42_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_42_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_42_threshold[7] = {2636.5, 404.5, -2, -2, 5124.5, -2, -2};
static const double gb_tree_42_value[7] = {-3.4359408141913691e-13, 309.68817892689384, 644.13788829352325, 247.87046013400413, -182.99478762668454, -40.9267472594764, -354.0500122667741};

static double gb_tree_42_predict(const double *x)
{
    int node = 0;
    while (gb_tree_42_left[node] != -1) {
        int f = gb_tree_42_feature[node];
        if (x[f] <= gb_tree_42_threshold[node])
            node = gb_tree_42_left[node];
        else
            node = gb_tree_42_right[node];
    }
    return gb_tree_42_value[node];
}

static const int gb_tree_43_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_43_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_43_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_43_threshold[7] = {3749.5, 651.5, -2, -2, 6558.5, -2, -2};
static const double gb_tree_43_value[7] = {-3.7341980992379268e-14, 216.13415460321886, 530.28241492028781, 149.67538547207437, -237.23958042605133, -169.8636189978865, -542.07472298516063};

static double gb_tree_43_predict(const double *x)
{
    int node = 0;
    while (gb_tree_43_left[node] != -1) {
        int f = gb_tree_43_feature[node];
        if (x[f] <= gb_tree_43_threshold[node])
            node = gb_tree_43_left[node];
        else
            node = gb_tree_43_right[node];
    }
    return gb_tree_43_value[node];
}

static const int gb_tree_44_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_44_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_44_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_44_threshold[7] = {2621.5, 375.5, -2, -2, 5649.5, -2, -2};
static const double gb_tree_44_value[7] = {1.1747170718593974e-12, 283.51412918722241, 599.20842817812002, 229.50318154999212, -165.84686403200845, -64.242671189815795, -365.62507324090626};

static double gb_tree_44_predict(const double *x)
{
    int node = 0;
    while (gb_tree_44_left[node] != -1) {
        int f = gb_tree_44_feature[node];
        if (x[f] <= gb_tree_44_threshold[node])
            node = gb_tree_44_left[node];
        else
            node = gb_tree_44_right[node];
    }
    return gb_tree_44_value[node];
}

static const int gb_tree_45_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_45_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_45_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_45_threshold[7] = {4575, 1354.5, -2, -2, 6829.5, -2, -2};
static const double gb_tree_45_value[7] = {-1.5923617231997206e-12, 155.78556338189466, 366.09256791527019, 66.386158242402118, -273.51501506763248, -221.40464651873634, -598.9954752377065};

static double gb_tree_45_predict(const double *x)
{
    int node = 0;
    while (gb_tree_45_left[node] != -1) {
        int f = gb_tree_45_feature[node];
        if (x[f] <= gb_tree_45_threshold[node])
            node = gb_tree_45_left[node];
        else
            node = gb_tree_45_right[node];
    }
    return gb_tree_45_value[node];
}

static const int gb_tree_46_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_46_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_46_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_46_threshold[7] = {2610.5, 356.5, -2, -2, 6140.5, -2, -2};
static const double gb_tree_46_value[7] = {1.3197216282798615e-12, 259.18469655442379, 561.82791255060602, 210.68607683254143, -150.60972334771563, -80.350545102421179, -391.91218752089492};

static double gb_tree_46_predict(const double *x)
{
    int node = 0;
    while (gb_tree_46_left[node] != -1) {
        int f = gb_tree_46_feature[node];
        if (x[f] <= gb_tree_46_threshold[node])
            node = gb_tree_46_left[node];
        else
            node = gb_tree_46_right[node];
    }
    return gb_tree_46_value[node];
}

static const int gb_tree_47_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_47_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_47_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_47_threshold[7] = {4027.5, 778.5, -2, -2, 6803.5, -2, -2};
static const double gb_tree_47_value[7] = {-6.0021639482021448e-13, 166.70487876072494, 415.78611462362511, 106.69104892475227, -213.70910789003023, -168.71840725228205, -538.19540239684511};

static double gb_tree_47_predict(const double *x)
{
    int node = 0;
    while (gb_tree_47_left[node] != -1) {
        int f = gb_tree_47_feature[node];
        if (x[f] <= gb_tree_47_threshold[node])
            node = gb_tree_47_left[node];
        else
            node = gb_tree_47_right[node];
    }
    return gb_tree_47_value[node];
}

static const int gb_tree_48_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_48_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_48_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_48_threshold[7] = {3114.5, 483.5, -2, -2, 6539.5, -2, -2};
static const double gb_tree_48_value[7] = {9.7339692329776884e-13, 203.52210116055704, 465.58480623401408, 154.95145453648337, -159.5586301644062, -108.50356856492719, -430.89100425763593};

static double gb_tree_48_predict(const double *x)
{
    int node = 0;
    while (gb_tree_48_left[node] != -1) {
        int f = gb_tree_48_feature[node];
        if (x[f] <= gb_tree_48_threshold[node])
            node = gb_tree_48_left[node];
        else
            node = gb_tree_48_right[node];
    }
    return gb_tree_48_value[node];
}

static const int gb_tree_49_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_49_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_49_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_49_threshold[7] = {4594.5, 1960.5, -2, -2, 6871.5, -2, -2};
static const double gb_tree_49_value[7] = {-2.6699586786447126e-13, 129.82117841274928, 261.86724711861433, 29.341072288987089, -230.57258616529199, -189.12616090670315, -519.0533135465073};

static double gb_tree_49_predict(const double *x)
{
    int node = 0;
    while (gb_tree_49_left[node] != -1) {
        int f = gb_tree_49_feature[node];
        if (x[f] <= gb_tree_49_threshold[node])
            node = gb_tree_49_left[node];
        else
            node = gb_tree_49_right[node];
    }
    return gb_tree_49_value[node];
}

static const int gb_tree_50_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_50_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_50_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_50_threshold[7] = {4602.5, 1094.5, -2, -2, 6882.5, -2, -2};
static const double gb_tree_50_value[7] = {7.2386860100869993e-13, 122.9729019510187, 319.10917266418346, 61.057425233253944, -219.70507943878408, -180.88917576031361, -497.81282875202169};

static double gb_tree_50_predict(const double *x)
{
    int node = 0;
    while (gb_tree_50_left[node] != -1) {
        int f = gb_tree_50_feature[node];
        if (x[f] <= gb_tree_50_threshold[node])
            node = gb_tree_50_left[node];
        else
            node = gb_tree_50_right[node];
    }
    return gb_tree_50_value[node];
}

static const int gb_tree_51_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_51_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_51_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_51_threshold[7] = {2592.5, 314.5, -2, -2, 5003.5, -2, -2};
static const double gb_tree_51_value[7] = {-8.2819531156863776e-14, 208.21192469665672, 482.1834452840007, 170.09414791928816, -119.64219671379014, -20.048313142048862, -230.06550770782323};

static double gb_tree_51_predict(const double *x)
{
    int node = 0;
    while (gb_tree_51_left[node] != -1) {
        int f = gb_tree_51_feature[node];
        if (x[f] <= gb_tree_51_threshold[node])
            node = gb_tree_51_left[node];
        else
            node = gb_tree_51_right[node];
    }
    return gb_tree_51_value[node];
}

static const int gb_tree_52_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_52_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_52_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_52_threshold[7] = {2586.5, 325.5, -2, -2, 6204.5, -2, -2};
static const double gb_tree_52_value[7] = {1.3405391141026013e-13, 198.1531575609572, 453.00951203962796, 161.13547055919463, -113.46737468590477, -61.257224042573974, -309.66049750633789};

static double gb_tree_52_predict(const double *x)
{
    int node = 0;
    while (gb_tree_52_left[node] != -1) {
        int f = gb_tree_52_feature[node];
        if (x[f] <= gb_tree_52_threshold[node])
            node = gb_tree_52_left[node];
        else
            node = gb_tree_52_right[node];
    }
    return gb_tree_52_value[node];
}

static const int gb_tree_53_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_53_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_53_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_53_threshold[7] = {4586.5, 791.5, -2, -2, 6902, -2, -2};
static const double gb_tree_53_value[7] = {2.186131594350689e-12, 107.61577785703159, 317.32203833918584, 63.564181267362201, -190.21277713739383, -156.14237808140169, -457.00307292232617};

static double gb_tree_53_predict(const double *x)
{
    int node = 0;
    while (gb_tree_53_left[node] != -1) {
        int f = gb_tree_53_feature[node];
        if (x[f] <= gb_tree_53_threshold[node])
            node = gb_tree_53_left[node];
        else
            node = gb_tree_53_right[node];
    }
    return gb_tree_53_value[node];
}

static const int gb_tree_54_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_54_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_54_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_54_threshold[7] = {2578, 286.5, -2, -2, 5808.5, -2, -2};
static const double gb_tree_54_value[7] = {2.7762277915329387e-13, 181.65412120856723, 434.31476775716072, 150.04730203172784, -103.51989958862966, -43.129853027309139, -245.28131012425362};

static double gb_tree_54_predict(const double *x)
{
    int node = 0;
    while (gb_tree_54_left[node] != -1) {
        int f = gb_tree_54_feature[node];
        if (x[f] <= gb_tree_54_threshold[node])
            node = gb_tree_54_left[node];
        else
            node = gb_tree_54_right[node];
    }
    return gb_tree_54_value[node];
}

static const int gb_tree_55_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_55_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_55_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_55_threshold[7] = {3953.5, 629.5, -2, -2, 6711.5, -2, -2};
static const double gb_tree_55_value[7] = {1.4822641071716805e-12, 117.85085686060924, 316.98159129608621, 79.983285685719522, -144.80956556299387, -108.52640169785867, -360.90679679813144};

static double gb_tree_55_predict(const double *x)
{
    int node = 0;
    while (gb_tree_55_left[node] != -1) {
        int f = gb_tree_55_feature[node];
        if (x[f] <= gb_tree_55_threshold[node])
            node = gb_tree_55_left[node];
        else
            node = gb_tree_55_right[node];
    }
    return gb_tree_55_value[node];
}

static const int gb_tree_56_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_56_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_56_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_56_threshold[7] = {2828.5, 276.5, -2, -2, 6492.5, -2, -2};
static const double gb_tree_56_value[7] = {5.3169744892089209e-13, 153.76578843319768, 401.77363624806856, 126.89293119365409, -101.78282744641378, -65.005273610535824, -298.3458893316585};

static double gb_tree_56_predict(const double *x)
{
    int node = 0;
    while (gb_tree_56_left[node] != -1) {
        int f = gb_tree_56_feature[node];
        if (x[f] <= gb_tree_56_threshold[node])
            node = gb_tree_56_left[node];
        else
            node = gb_tree_56_right[node];
    }
    return gb_tree_56_value[node];
}

static const int gb_tree_57_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_57_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_57_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_57_threshold[7] = {4621.5, 1727.5, -2, -2, 6930.5, -2, -2};
static const double gb_tree_57_value[7] = {1.3432275115279855e-12, 89.096092775551952, 194.06614386940836, 25.446453890607845, -161.29678869561457, -132.99013007868348, -401.04066340671642};

static double gb_tree_57_predict(const double *x)
{
    int node = 0;
    while (gb_tree_57_left[node] != -1) {
        int f = gb_tree_57_feature[node];
        if (x[f] <= gb_tree_57_threshold[node])
            node = gb_tree_57_left[node];
        else
            node = gb_tree_57_right[node];
    }
    return gb_tree_57_value[node];
}

static const int gb_tree_58_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_58_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_58_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_58_threshold[7] = {2564.5, 256.5, -2, -2, 5226.5, -2, -2};
static const double gb_tree_58_value[7] = {8.2948320876456792e-13, 151.66300395542379, 382.95297547380892, 126.16473786457222, -85.667633058610448, -18.828802736724722, -176.93541259301048};

static double gb_tree_58_predict(const double *x)
{
    int node = 0;
    while (gb_tree_58_left[node] != -1) {
        int f = gb_tree_58_feature[node];
        if (x[f] <= gb_tree_58_threshold[node])
            node = gb_tree_58_left[node];
        else
            node = gb_tree_58_right[node];
    }
    return gb_tree_58_value[node];
}

static const int gb_tree_59_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_59_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_59_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_59_threshold[7] = {4626.5, 1032.5, -2, -2, 6942, -2, -2};
static const double gb_tree_59_value[7] = {1.7113760919449383e-12, 80.656676364998248, 219.95353551488333, 40.337983931939497, -146.57177672188556, -120.37238141848376, -376.7330173736222};

static double gb_tree_59_predict(const double *x)
{
    int node = 0;
    while (gb_tree_59_left[node] != -1) {
        int f = gb_tree_59_feature[node];
        if (x[f] <= gb_tree_59_threshold[node])
            node = gb_tree_59_left[node];
        else
            node = gb_tree_59_right[node];
    }
    return gb_tree_59_value[node];
}

static const int gb_tree_60_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_60_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_60_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_60_threshold[7] = {2558.5, 244.5, -2, -2, 6574.5, -2, -2};
static const double gb_tree_60_value[7] = {8.2624587155075437e-13, 138.68941270557542, 358.33469456127523, 115.57763945807947, -78.087440012940405, -49.867845397933536, -264.79010799636552};

static double gb_tree_60_predict(const double *x)
{
    int node = 0;
    while (gb_tree_60_left[node] != -1) {
        int f = gb_tree_60_feature[node];
        if (x[f] <= gb_tree_60_threshold[node])
            node = gb_tree_60_left[node];
        else
            node = gb_tree_60_right[node];
    }
    return gb_tree_60_value[node];
}

static const int gb_tree_61_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_61_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_61_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_61_threshold[7] = {4297.5, 622.5, -2, -2, 6915.5, -2, -2};
static const double gb_tree_61_value[7] = {1.4320783426679758e-12, 81.472079205506105, 247.11057774211508, 53.305126408669722, -121.84940503452678, -98.619221331361757, -335.42076323777934};

static double gb_tree_61_predict(const double *x)
{
    int node = 0;
    while (gb_tree_61_left[node] != -1) {
        int f = gb_tree_61_feature[node];
        if (x[f] <= gb_tree_61_threshold[node])
            node = gb_tree_61_left[node];
        else
            node = gb_tree_61_right[node];
    }
    return gb_tree_61_value[node];
}

static const int gb_tree_62_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_62_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_62_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_62_threshold[7] = {3186.5, 390.5, -2, -2, 6619.5, -2, -2};
static const double gb_tree_62_value[7] = {1.556349865540843e-12, 105.44824922626707, 277.60232804618477, 80.897392086206082, -86.053832617590956, -59.356218342910225, -248.73044399946039};

static double gb_tree_62_predict(const double *x)
{
    int node = 0;
    while (gb_tree_62_left[node] != -1) {
        int f = gb_tree_62_feature[node];
        if (x[f] <= gb_tree_62_threshold[node])
            node = gb_tree_62_left[node];
        else
            node = gb_tree_62_right[node];
    }
    return gb_tree_62_value[node];
}

static const int gb_tree_63_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_63_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_63_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_63_threshold[7] = {4637.5, 1511.5, -2, -2, 6968.5, -2, -2};
static const double gb_tree_63_value[7] = {2.78425075767152e-13, 67.430585366134721, 158.25536272733459, 23.137174500908419, -123.36879736368563, -102.51496401827545, -327.99703706552503};

static double gb_tree_63_predict(const double *x)
{
    int node = 0;
    while (gb_tree_63_left[node] != -1) {
        int f = gb_tree_63_feature[node];
        if (x[f] <= gb_tree_63_threshold[node])
            node = gb_tree_63_left[node];
        else
            node = gb_tree_63_right[node];
    }
    return gb_tree_63_value[node];
}

static const int gb_tree_64_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_64_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_64_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_64_threshold[7] = {2549.5, 221.5, -2, -2, 5814.5, -2, -2};
static const double gb_tree_64_value[7] = {1.8068564266836512e-13, 116.39604939135498, 318.9178405041414, 97.404855017193029, -65.148971547905305, -25.610910676216989, -159.47678071482594};

static double gb_tree_64_predict(const double *x)
{
    int node = 0;
    while (gb_tree_64_left[node] != -1) {
        int f = gb_tree_64_feature[node];
        if (x[f] <= gb_tree_64_threshold[node])
            node = gb_tree_64_left[node];
        else
            node = gb_tree_64_right[node];
    }
    return gb_tree_64_value[node];
}

static const int gb_tree_65_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_65_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_65_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_65_threshold[7] = {4642.5, 699.5, -2, -2, 6979.5, -2, -2};
static const double gb_tree_65_value[7] = {-4.789570030941129e-13, 61.300893283192728, 198.45923574724785, 36.797289495373157, -112.51947359352643, -93.473776245698218, -308.75817662384122};

static double gb_tree_65_predict(const double *x)
{
    int node = 0;
    while (gb_tree_65_left[node] != -1) {
        int f = gb_tree_65_feature[node];
        if (x[f] <= gb_tree_65_threshold[node])
            node = gb_tree_65_left[node];
        else
            node = gb_tree_65_right[node];
    }
    return gb_tree_65_value[node];
}

static const int gb_tree_66_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_66_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_66_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_66_threshold[7] = {2545.5, 209.5, -2, -2, 6396.5, -2, -2};
static const double gb_tree_66_value[7] = {1.4142659503024063e-12, 106.65882619279813, 299.11050901701236, 89.650121618262915, -59.554436234219175, -34.312626574067536, -184.77645575010271};

static double gb_tree_66_predict(const double *x)
{
    int node = 0;
    while (gb_tree_66_left[node] != -1) {
        int f = gb_tree_66_feature[node];
        if (x[f] <= gb_tree_66_threshold[node])
            node = gb_tree_66_left[node];
        else
            node = gb_tree_66_right[node];
    }
    return gb_tree_66_value[node];
}

static const int gb_tree_67_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_67_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_67_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_67_threshold[7] = {3530.5, 419.5, -2, -2, 6846, -2, -2};
static const double gb_tree_67_value[7] = {5.5420398024649126e-13, 76.877935327777521, 219.9872895731651, 57.193521800644177, -75.220799183537693, -57.519537369220778, -243.53086647335135};

static double gb_tree_67_predict(const double *x)
{
    int node = 0;
    while (gb_tree_67_left[node] != -1) {
        int f = gb_tree_67_feature[node];
        if (x[f] <= gb_tree_67_threshold[node])
            node = gb_tree_67_left[node];
        else
            node = gb_tree_67_right[node];
    }
    return gb_tree_67_value[node];
}

static const int gb_tree_68_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_68_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_68_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_68_threshold[7] = {4719.5, 2116.5, -2, -2, 6997.5, -2, -2};
static const double gb_tree_68_value[7] = {-2.1007503441811554e-14, 52.439968786901254, 109.52267820548406, 5.3489354040442167, -101.32936426512224, -84.844444673049011, -280.14642753913182};

static double gb_tree_68_predict(const double *x)
{
    int node = 0;
    while (gb_tree_68_left[node] != -1) {
        int f = gb_tree_68_feature[node];
        if (x[f] <= gb_tree_68_threshold[node])
            node = gb_tree_68_left[node];
        else
            node = gb_tree_68_right[node];
    }
    return gb_tree_68_value[node];
}

static const int gb_tree_69_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_69_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_69_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_69_threshold[7] = {4647.5, 1342.5, -2, -2, 6989.5, -2, -2};
static const double gb_tree_69_value[7] = {9.4947581636352508e-13, 51.046671815045151, 128.51295462686332, 19.288104154552077, -94.003097138381847, -78.319710840948233, -262.53469245440937};

static double gb_tree_69_predict(const double *x)
{
    int node = 0;
    while (gb_tree_69_left[node] != -1) {
        int f = gb_tree_69_feature[node];
        if (x[f] <= gb_tree_69_threshold[node])
            node = gb_tree_69_left[node];
        else
            node = gb_tree_69_right[node];
    }
    return gb_tree_69_value[node];
}

static const int gb_tree_70_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_70_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_70_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_70_threshold[7] = {2540.5, 193.5, -2, -2, 6104.5, -2, -2};
static const double gb_tree_70_value[7] = {-2.0814670746901794e-13, 88.834155346032105, 270.03483660667314, 74.220103395556009, -49.428388777660068, -23.328493959122078, -136.71937228545139};

static double gb_tree_70_predict(const double *x)
{
    int node = 0;
    while (gb_tree_70_left[node] != -1) {
        int f = gb_tree_70_feature[node];
        if (x[f] <= gb_tree_70_threshold[node])
            node = gb_tree_70_left[node];
        else
            node = gb_tree_70_right[node];
    }
    return gb_tree_70_value[node];
}

static const int gb_tree_71_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_71_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_71_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_71_threshold[7] = {4725.5, 551.5, -2, -2, 7014.5, -2, -2};
static const double gb_tree_71_value[7] = {1.1795167761633556e-14, 45.419490702204044, 171.03300199106948, 28.729770346009708, -88.078772180511876, -74.193305076223737, -255.46296589608946};

static double gb_tree_71_predict(const double *x)
{
    int node = 0;
    while (gb_tree_71_left[node] != -1) {
        int f = gb_tree_71_feature[node];
        if (x[f] <= gb_tree_71_threshold[node])
            node = gb_tree_71_left[node];
        else
            node = gb_tree_71_right[node];
    }
    return gb_tree_71_value[node];
}

static const int gb_tree_72_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_72_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_72_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_72_threshold[7] = {2646.5, 184.5, -2, -2, 6483.5, -2, -2};
static const double gb_tree_72_value[7] = {-1.0395371301138977e-13, 78.79688308710783, 251.81838158342944, 66.026175228757538, -46.845684220080791, -28.317004592889603, -149.34476300879902};

static double gb_tree_72_predict(const double *x)
{
    int node = 0;
    while (gb_tree_72_left[node] != -1) {
        int f = gb_tree_72_feature[node];
        if (x[f] <= gb_tree_72_threshold[node])
            node = gb_tree_72_left[node];
        else
            node = gb_tree_72_right[node];
    }
    return gb_tree_72_value[node];
}

static const int gb_tree_73_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_73_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_73_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_73_threshold[7] = {3712.5, 338.5, -2, -2, 6851.5, -2, -2};
static const double gb_tree_73_value[7] = {-2.1724644011567199e-13, 55.83388532244615, 189.65216186097314, 42.175726359681377, -60.171334420164548, -46.030187871690991, -189.94041616276078};

static double gb_tree_73_predict(const double *x)
{
    int node = 0;
    while (gb_tree_73_left[node] != -1) {
        int f = gb_tree_73_feature[node];
        if (x[f] <= gb_tree_73_threshold[node])
            node = gb_tree_73_left[node];
        else
            node = gb_tree_73_right[node];
    }
    return gb_tree_73_value[node];
}

static const int gb_tree_74_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_74_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_74_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_74_threshold[7] = {2351.5, 169.5, -2, -2, 5582.5, -2, -2};
static const double gb_tree_74_value[7] = {3.8193541433404125e-14, 79.014506636423164, 237.38548497312027, 66.883691928110665, -39.028621099153192, -10.219076095306846, -97.162310850140159};

static double gb_tree_74_predict(const double *x)
{
    int node = 0;
    while (gb_tree_74_left[node] != -1) {
        int f = gb_tree_74_feature[node];
        if (x[f] <= gb_tree_74_threshold[node])
            node = gb_tree_74_left[node];
        else
            node = gb_tree_74_right[node];
    }
    return gb_tree_74_value[node];
}

static const int gb_tree_75_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_75_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_75_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_75_threshold[7] = {4730.5, 1102.5, -2, -2, 7029.5, -2, -2};
static const double gb_tree_75_value[7] = {4.1196523583695912e-13, 38.065499786964672, 108.71975562208922, 16.369682470114778, -74.001218557965117, -62.333089714202877, -228.62665585893723};

static double gb_tree_75_predict(const double *x)
{
    int node = 0;
    while (gb_tree_75_left[node] != -1) {
        int f = gb_tree_75_feature[node];
        if (x[f] <= gb_tree_75_threshold[node])
            node = gb_tree_75_left[node];
        else
            node = gb_tree_75_right[node];
    }
    return gb_tree_75_value[node];
}

static const int gb_tree_76_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_76_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_76_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_76_threshold[7] = {2239.5, 160.5, -2, -2, 5436.5, -2, -2};
static const double gb_tree_76_value[7] = {-4.4914534996864769e-14, 74.583541251289574, 225.55571082035812, 63.259038013491399, -34.430440414774061, -6.7785487163757008, -84.899383852032415};

static double gb_tree_76_predict(const double *x)
{
    int node = 0;
    while (gb_tree_76_left[node] != -1) {
        int f = gb_tree_76_feature[node];
        if (x[f] <= gb_tree_76_threshold[node])
            node = gb_tree_76_left[node];
        else
            node = gb_tree_76_right[node];
    }
    return gb_tree_76_value[node];
}

static const int gb_tree_77_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_77_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_77_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_77_threshold[7] = {4293.5, 518.5, -2, -2, 6956.5, -2, -2};
static const double gb_tree_77_value[7] = {5.7230491788546591e-14, 39.512249211428212, 135.69406292453604, 26.08599768003042, -58.987885628295047, -47.125957401830078, -185.87197709045552};

static double gb_tree_77_predict(const double *x)
{
    int node = 0;
    while (gb_tree_77_left[node] != -1) {
        int f = gb_tree_77_feature[node];
        if (x[f] <= gb_tree_77_threshold[node])
            node = gb_tree_77_left[node];
        else
            node = gb_tree_77_right[node];
    }
    return gb_tree_77_value[node];
}

static const int gb_tree_78_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_78_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_78_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_78_threshold[7] = {2516.5, 176.5, -2, -2, 6626.5, -2, -2};
static const double gb_tree_78_value[7] = {-4.5547927060436975e-14, 62.712159426089734, 199.21011959148666, 52.502389054760599, -34.369989435342411, -21.63451319609425, -129.06757265976239};

static double gb_tree_78_predict(const double *x)
{
    int node = 0;
    while (gb_tree_78_left[node] != -1) {
        int f = gb_tree_78_feature[node];
        if (x[f] <= gb_tree_78_threshold[node])
            node = gb_tree_78_left[node];
        else
            node = gb_tree_78_right[node];
    }
    return gb_tree_78_value[node];
}

static const int gb_tree_79_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_79_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_79_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_79_threshold[7] = {4734.5, 886.5, -2, -2, 7043.5, -2, -2};
static const double gb_tree_79_value[7] = {8.3889259975341284e-14, 31.766250936845317, 100.63300390718021, 15.783441909338668, -61.908816174106967, -52.143697769015475, -204.54631492881759};

static double gb_tree_79_predict(const double *x)
{
    int node = 0;
    while (gb_tree_79_left[node] != -1) {
        int f = gb_tree_79_feature[node];
        if (x[f] <= gb_tree_79_threshold[node])
            node = gb_tree_79_left[node];
        else
            node = gb_tree_79_right[node];
    }
    return gb_tree_79_value[node];
}

static const int gb_tree_80_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_80_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_80_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_80_threshold[7] = {2234.5, 144.5, -2, -2, 6287.5, -2, -2};
static const double gb_tree_80_value[7] = {2.7453323342098054e-13, 62.73289790750222, 199.85676716500203, 53.411006669685179, -28.860308238357376, -13.940774670320682, -97.393615619135716};

static double gb_tree_80_predict(const double *x)
{
    int node = 0;
    while (gb_tree_80_left[node] != -1) {
        int f = gb_tree_80_feature[node];
        if (x[f] <= gb_tree_80_threshold[node])
            node = gb_tree_80_left[node];
        else
            node = gb_tree_80_right[node];
    }
    return gb_tree_80_value[node];
}

static const int gb_tree_81_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_81_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_81_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_81_threshold[7] = {3190.5, 235.5, -2, -2, 6818, -2, -2};
static const double gb_tree_81_value[7] = {6.6126131436938482e-14, 44.979967320300382, 158.73101377323792, 36.01561503972686, -36.799030101436472, -26.66862731038896, -134.72220329893543};

static double gb_tree_81_predict(const double *x)
{
    int node = 0;
    while (gb_tree_81_left[node] != -1) {
        int f = gb_tree_81_feature[node];
        if (x[f] <= gb_tree_81_threshold[node])
            node = gb_tree_81_left[node];
        else
            node = gb_tree_81_right[node];
    }
    return gb_tree_81_value[node];
}

static const int gb_tree_82_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_82_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_82_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_82_threshold[7] = {4737.5, 729.5, -2, -2, 7053.5, -2, -2};
static const double gb_tree_82_value[7] = {2.0605651365922965e-13, 27.911615632879691, 96.082398017489879, 15.478520306427335, -54.516947243453032, -46.019919173624672, -187.7234055820378};

static double gb_tree_82_predict(const double *x)
{
    int node = 0;
    while (gb_tree_82_left[node] != -1) {
        int f = gb_tree_82_feature[node];
        if (x[f] <= gb_tree_82_threshold[node])
            node = gb_tree_82_left[node];
        else
            node = gb_tree_82_right[node];
    }
    return gb_tree_82_value[node];
}

static const int gb_tree_83_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_83_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_83_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_83_threshold[7] = {2230.5, 134.5, -2, -2, 6002.5, -2, -2};
static const double gb_tree_83_value[7] = {4.3723406032869256e-13, 55.150534642998224, 181.84089664772515, 47.116382343410102, -25.306589589186856, -9.5210252067893624, -75.630538976188532};

static double gb_tree_83_predict(const double *x)
{
    int node = 0;
    while (gb_tree_83_left[node] != -1) {
        int f = gb_tree_83_feature[node];
        if (x[f] <= gb_tree_83_threshold[node])
            node = gb_tree_83_left[node];
        else
            node = gb_tree_83_right[node];
    }
    return gb_tree_83_value[node];
}

static const int gb_tree_84_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_84_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_84_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_84_threshold[7] = {4914, 1362.5, -2, -2, 7061.5, -2, -2};
static const double gb_tree_84_value[7] = {1.8501734061423949e-13, 24.081139145681124, 67.592275442313081, 7.2866995579884097, -52.767284749877788, -44.581028631061237, -178.68726964546482};

static double gb_tree_84_predict(const double *x)
{
    int node = 0;
    while (gb_tree_84_left[node] != -1) {
        int f = gb_tree_84_feature[node];
        if (x[f] <= gb_tree_84_threshold[node])
            node = gb_tree_84_left[node];
        else
            node = gb_tree_84_right[node];
    }
    return gb_tree_84_value[node];
}

static const int gb_tree_85_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_85_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_85_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_85_threshold[7] = {3948.5, 301, -2, -2, 7021.5, -2, -2};
static const double gb_tree_85_value[7] = {2.4146664885771367e-13, 30.768602577046547, 123.51773231656151, 23.004662997292154, -37.693657206646762, -30.881081954897734, -153.60886440575791};

static double gb_tree_85_predict(const double *x)
{
    int node = 0;
    while (gb_tree_85_left[node] != -1) {
        int f = gb_tree_85_feature[node];
        if (x[f] <= gb_tree_85_threshold[node])
            node = gb_tree_85_left[node];
        else
            node = gb_tree_85_right[node];
    }
    return gb_tree_85_value[node];
}

static const int gb_tree_86_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_86_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_86_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_86_threshold[7] = {2229.5, 125.5, -2, -2, 6767.5, -2, -2};
static const double gb_tree_86_value[7] = {7.9142338343347354e-14, 48.387191821853996, 166.73794038106553, 41.297510161135868, -22.184015896656064, -14.617618285524328, -105.61155958943338};

static double gb_tree_86_predict(const double *x)
{
    int node = 0;
    while (gb_tree_86_left[node] != -1) {
        int f = gb_tree_86_feature[node];
        if (x[f] <= gb_tree_86_threshold[node])
            node = gb_tree_86_left[node];
        else
            node = gb_tree_86_right[node];
    }
    return gb_tree_86_value[node];
}

static const int gb_tree_87_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_87_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_87_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_87_threshold[7] = {4992.5, 1670.5, -2, -2, 7074.5, -2, -2};
static const double gb_tree_87_value[7] = {4.014122202888866e-13, 20.738776362751601, 54.057510271030445, 3.8005262066215582, -47.757276257139914, -40.803583978262758, -164.03006563038215};

static double gb_tree_87_predict(const double *x)
{
    int node = 0;
    while (gb_tree_87_left[node] != -1) {
        int f = gb_tree_87_feature[node];
        if (x[f] <= gb_tree_87_threshold[node])
            node = gb_tree_87_left[node];
        else
            node = gb_tree_87_right[node];
    }
    return gb_tree_87_value[node];
}

static const int gb_tree_88_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_88_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_88_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_88_threshold[7] = {4533.5, 344.5, -2, -2, 7049.5, -2, -2};
static const double gb_tree_88_value[7] = {4.4931777336373126e-13, 22.852021607509933, 103.91306596830039, 16.063191449543364, -39.117351742784386, -32.81610924643023, -144.53188767138468};

static double gb_tree_88_predict(const double *x)
{
    int node = 0;
    while (gb_tree_88_left[node] != -1) {
        int f = gb_tree_88_feature[node];
        if (x[f] <= gb_tree_88_threshold[node])
            node = gb_tree_88_left[node];
        else
            node = gb_tree_88_right[node];
    }
    return gb_tree_88_value[node];
}

static const int gb_tree_89_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_89_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_89_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_89_threshold[7] = {2835.5, 137.5, -2, -2, 6770.5, -2, -2};
static const double gb_tree_89_value[7] = {2.2839062158974523e-13, 35.292138651352168, 145.63303614126286, 29.683412679235467, -23.457779709523564, -16.210651817292472, -92.985901889573896};

static double gb_tree_89_predict(const double *x)
{
    int node = 0;
    while (gb_tree_89_left[node] != -1) {
        int f = gb_tree_89_feature[node];
        if (x[f] <= gb_tree_89_threshold[node])
            node = gb_tree_89_left[node];
        else
            node = gb_tree_89_right[node];
    }
    return gb_tree_89_value[node];
}

static const int gb_tree_90_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_90_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_90_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_90_threshold[7] = {4994.5, 889.5, -2, -2, 7084.5, -2, -2};
static const double gb_tree_90_value[7] = {4.1853491907412197e-13, 18.145479617334161, 63.999913737416598, 8.1538519491451016, -41.846758970143668, -36.02393408741581, -149.82522359545186};

static double gb_tree_90_predict(const double *x)
{
    int node = 0;
    while (gb_tree_90_left[node] != -1) {
        int f = gb_tree_90_feature[node];
        if (x[f] <= gb_tree_90_threshold[node])
            node = gb_tree_90_left[node];
        else
            node = gb_tree_90_right[node];
    }
    return gb_tree_90_value[node];
}

static const int gb_tree_91_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_91_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_91_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_91_threshold[7] = {2148.5, 112.5, -2, -2, 6291.5, -2, -2};
static const double gb_tree_91_value[7] = {1.646678611495835e-13, 40.17687562791253, 146.37534940492208, 34.260398358539057, -17.436728357288882, -7.9380149108827336, -62.254262105688326};

static double gb_tree_91_predict(const double *x)
{
    int node = 0;
    while (gb_tree_91_left[node] != -1) {
        int f = gb_tree_91_feature[node];
        if (x[f] <= gb_tree_91_threshold[node])
            node = gb_tree_91_left[node];
        else
            node = gb_tree_91_right[node];
    }
    return gb_tree_91_value[node];
}

static const int gb_tree_92_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_92_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_92_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_92_threshold[7] = {3120.5, 204, -2, -2, 6951.5, -2, -2};
static const double gb_tree_92_value[7] = {9.3105114500316907e-14, 28.42889686540537, 110.69493625764413, 22.754950647369011, -22.372032334126221, -17.163729174862496, -100.49657972307827};

static double gb_tree_92_predict(const double *x)
{
    int node = 0;
    while (gb_tree_92_left[node] != -1) {
        int f = gb_tree_92_feature[node];
        if (x[f] <= gb_tree_92_threshold[node])
            node = gb_tree_92_left[node];
        else
            node = gb_tree_92_right[node];
    }
    return gb_tree_92_value[node];
}

static const int gb_tree_93_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_93_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_93_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_93_threshold[7] = {4996, 473.5, -2, -2, 7091.5, -2, -2};
static const double gb_tree_93_value[7] = {-4.6086310314473352e-14, 16.005784545479248, 73.980884226661544, 9.8045387392909369, -36.933904960597999, -31.844412357789011, -137.61922883487884};

static double gb_tree_93_predict(const double *x)
{
    int node = 0;
    while (gb_tree_93_left[node] != -1) {
        int f = gb_tree_93_feature[node];
        if (x[f] <= gb_tree_93_threshold[node])
            node = gb_tree_93_left[node];
        else
            node = gb_tree_93_right[node];
    }
    return gb_tree_93_value[node];
}

static const int gb_tree_94_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_94_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_94_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_94_threshold[7] = {2147.5, 103.5, -2, -2, 5938.5, -2, -2};
static const double gb_tree_94_value[7] = {-2.5121736779192806e-13, 35.434061022815769, 134.15410483137762, 30.378031234471436, -15.360314854597645, -4.9067426863857362, -47.266075575123686};

static double gb_tree_94_predict(const double *x)
{
    int node = 0;
    while (gb_tree_94_left[node] != -1) {
        int f = gb_tree_94_feature[node];
        if (x[f] <= gb_tree_94_threshold[node])
            node = gb_tree_94_left[node];
        else
            node = gb_tree_94_right[node];
    }
    return gb_tree_94_value[node];
}

static const int gb_tree_95_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_95_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_95_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_95_threshold[7] = {2121.5, 99.5, -2, -2, 6580.5, -2, -2};
static const double gb_tree_95_value[7] = {3.8158352985427888e-14, 33.973904027864037, 129.84557776328236, 29.239757859071663, -14.465146781149109, -8.0192371905055087, -62.358638724724727};

static double gb_tree_95_predict(const double *x)
{
    int node = 0;
    while (gb_tree_95_left[node] != -1) {
        int f = gb_tree_95_feature[node];
        if (x[f] <= gb_tree_95_threshold[node])
            node = gb_tree_95_left[node];
        else
            node = gb_tree_95_right[node];
    }
    return gb_tree_95_value[node];
}

static const int gb_tree_96_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_96_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_96_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_96_threshold[7] = {4990.5, 638.5, -2, -2, 7097.5, -2, -2};
static const double gb_tree_96_value[7] = {-2.1577556299026542e-13, 14.097893361121114, 57.878269050669367, 7.6479266522993852, -32.445611514324568, -27.875281034497345, -127.70843745321852};

static double gb_tree_96_predict(const double *x)
{
    int node = 0;
    while (gb_tree_96_left[node] != -1) {
        int f = gb_tree_96_feature[node];
        if (x[f] <= gb_tree_96_threshold[node])
            node = gb_tree_96_left[node];
        else
            node = gb_tree_96_right[node];
    }
    return gb_tree_96_value[node];
}

static const int gb_tree_97_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_97_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_97_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_97_threshold[7] = {3526.5, 230.5, -2, -2, 7035.5, -2, -2};
static const double gb_tree_97_value[7] = {-7.2340411349541357e-14, 20.704357948735503, 86.232501682310257, 16.146718361798211, -20.217971465662355, -16.466536323385302, -99.109337988695742};

static double gb_tree_97_predict(const double *x)
{
    int node = 0;
    while (gb_tree_97_left[node] != -1) {
        int f = gb_tree_97_feature[node];
        if (x[f] <= gb_tree_97_threshold[node])
            node = gb_tree_97_left[node];
        else
            node = gb_tree_97_right[node];
    }
    return gb_tree_97_value[node];
}

static const int gb_tree_98_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_98_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_98_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_98_threshold[7] = {5134.5, 1134.5, -2, -2, 7105.5, -2, -2};
static const double gb_tree_98_value[7] = {1.4576462689675071e-13, 12.33123381966864, 41.403679822585538, 3.9642473002365439, -31.095570436474084, -26.88370533613163, -120.21619429879044};

static double gb_tree_98_predict(const double *x)
{
    int node = 0;
    while (gb_tree_98_left[node] != -1) {
        int f = gb_tree_98_feature[node];
        if (x[f] <= gb_tree_98_threshold[node])
            node = gb_tree_98_left[node];
        else
            node = gb_tree_98_right[node];
    }
    return gb_tree_98_value[node];
}

static const int gb_tree_99_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_99_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_99_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_99_threshold[7] = {2349.5, 95, -2, -2, 6813.5, -2, -2};
static const double gb_tree_99_value[7] = {1.5605372908500147e-13, 26.724554425658098, 115.81814722417158, 22.912970752504489, -13.189318742988203, -8.8255889494039863, -64.946993762014898};

static double gb_tree_99_predict(const double *x)
{
    int node = 0;
    while (gb_tree_99_left[node] != -1) {
        int f = gb_tree_99_feature[node];
        if (x[f] <= gb_tree_99_threshold[node])
            node = gb_tree_99_left[node];
        else
            node = gb_tree_99_right[node];
    }
    return gb_tree_99_value[node];
}

static inline double predict_model(const double *features)
{
    if (features == NULL) return NAN;
    double prediction = GB_INITIAL_VALUE;
    prediction += GB_LEARNING_RATE * gb_tree_0_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_1_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_2_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_3_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_4_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_5_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_6_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_7_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_8_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_9_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_10_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_11_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_12_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_13_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_14_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_15_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_16_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_17_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_18_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_19_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_20_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_21_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_22_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_23_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_24_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_25_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_26_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_27_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_28_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_29_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_30_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_31_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_32_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_33_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_34_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_35_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_36_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_37_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_38_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_39_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_40_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_41_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_42_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_43_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_44_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_45_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_46_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_47_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_48_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_49_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_50_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_51_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_52_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_53_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_54_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_55_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_56_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_57_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_58_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_59_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_60_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_61_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_62_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_63_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_64_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_65_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_66_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_67_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_68_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_69_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_70_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_71_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_72_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_73_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_74_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_75_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_76_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_77_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_78_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_79_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_80_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_81_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_82_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_83_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_84_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_85_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_86_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_87_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_88_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_89_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_90_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_91_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_92_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_93_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_94_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_95_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_96_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_97_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_98_predict(features);
    prediction += GB_LEARNING_RATE * gb_tree_99_predict(features);
    return prediction;
}

#ifdef __cplusplus
}
#endif

#endif /* BEST_IV_MODEL_20261125_020948_539740_H_ */
