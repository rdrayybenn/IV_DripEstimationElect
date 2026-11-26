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
#define GB_INITIAL_VALUE (21600.334283143373)

static const int gb_tree_0_left[7] = {1, 2, -1, -1, 5, -1, -1};
static const int gb_tree_0_right[7] = {4, 3, -1, -1, 6, -1, -1};
static const int gb_tree_0_feature[7] = {0, 0, -2, -2, 0, -2, -2};
static const double gb_tree_0_threshold[7] = {21599.5, 10796.5, -2, -2, 32399, -2, -2};
static const double gb_tree_0_value[7] = {8.5907694209036299e-11, 10800.467906418804, 16202.350985383568, 5401.8243375463662, -10800.467906418638, -5400.6726154768221, -16200.26319736044};

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
static const double gb_tree_1_threshold[7] = {21082.5, 10037.5, -2, -2, 31661.5, -2, -2};
static const double gb_tree_1_value[7] = {1.4148725915463316e-11, 10512.965746773471, 15771.217738416115, 5732.8768872544833, -10020.266707674033, -4528.6092793213375, -15055.570795546815};

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
static const double gb_tree_2_threshold[7] = {22503, 12036, -2, -2, 33755, -2, -2};
static const double gb_tree_2_value[7] = {1.2738545378167282e-10, 9362.9337897894002, 14123.683904405418, 3890.7225658430452, -10180.670063806921, -5870.3063242703201, -15314.378317379764};

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
static const double gb_tree_3_threshold[7] = {20282.5, 8875, -2, -2, 30651, -2, -2};
static const double gb_tree_3_value[7] = {-2.3807810618635435e-11, 9867.4398404209387, 14857.950530701835, 5984.9868900035917, -8734.7905401075714, -3290.7927495280037, -13231.639515289608};

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
static const double gb_tree_4_threshold[7] = {23218, 12883.5, -2, -2, 34772.5, -2, -2};
static const double gb_tree_4_value[7] = {4.5458367457540717e-11, 8195.7871172646246, 12481.384491810541, 2854.570959768615, -9524.5463775212684, -5970.3188935271492, -14395.559139981702};

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
static const double gb_tree_5_threshold[7] = {19642, 7978.5, -2, -2, 29939.5, -2, -2};
static const double gb_tree_5_value[7] = {-4.0236547547121586e-11, 9202.6062557114565, 13939.635359899903, 5962.5888484315728, -7673.9004860607574, -2430.2781964912215, -11744.303914554204};

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
static const double gb_tree_6_threshold[7] = {23790, 13482, -2, -2, 35561.5, -2, -2};
static const double gb_tree_6_value[7] = {-1.1238288311019594e-10, 7225.0273511047326, 11117.183776532829, 2134.1552446854207, -8855.2404650395238, -5851.9295022657061, -13483.752780020448};

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
static const double gb_tree_7_threshold[7] = {19122.5, 7266, -2, -2, 29424, -2, -2};
static const double gb_tree_7_value[7] = {-1.0754570253076055e-10, 8537.7167070938358, 13041.49938819463, 5775.626426584291, -6780.3231161007125, -1823.5293725635179, -10486.554977010534};

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
static const double gb_tree_8_threshold[7] = {24255.5, 13932.5, -2, -2, 36207, -2, -2};
static const double gb_tree_8_value[7] = {3.9523191624765196e-11, 6400.0112496714155, 9945.0876692626061, 1615.7709984423468, -8194.8160460906875, -5612.2343084602117, -12607.573818262061};

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
static const double gb_tree_9_threshold[7] = {18703, 6692, -2, -2, 31101.5, -2, -2};
static const double gb_tree_9_value[7] = {-7.3622423094955962e-11, 7883.1427160592248, 12180.439015913673, 5488.8023289233033, -6019.2100029790854, -2107.9536792855147, -10026.807847898783};

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
static const double gb_tree_10_threshold[7] = {24691, 11576.5, -2, -2, 36795.5, -2, -2};
static const double gb_tree_10_value[7] = {-4.9948554257535439e-12, 5685.4065792281099, 9735.9785497668345, 2109.1357732241486, -7583.8587586413023, -5368.9117298596666, -11770.635211124139};

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
static const double gb_tree_11_threshold[7] = {18278.5, 6122, -2, -2, 28776, -2, -2};
static const double gb_tree_11_value[7] = {1.0891430928504813e-10, 7295.7483042447293, 11369.650437348046, 5244.1429134733735, -5351.6063539388306, -1059.6290513927509, -8474.4463405208335};

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
static const double gb_tree_12_threshold[7] = {22154, 9429, -2, -2, 34379.5, -2, -2};
static const double gb_tree_12_value[7] = {-5.646396261300773e-11, 5795.7144878618074, 9522.7773800138948, 3033.6268913610743, -6100.7990430174332, -3446.1061447538764, -9780.1273566597247};

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
static const double gb_tree_13_threshold[7] = {25193, 14591, -2, -2, 37470, -2, -2};
static const double gb_tree_13_value[7] = {-8.5487864471175313e-11, 4790.7703406839582, 7675.9911841633029, 820.39616438356097, -6702.2523726385998, -4880.0408393627949, -10606.255601081957};

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
static const double gb_tree_14_threshold[7] = {17848, 5518.5, -2, -2, 28482.5, -2, -2};
static const double gb_tree_14_value[7] = {-1.5957076358790474e-11, 6431.5874156605605, 10242.494031946479, 4725.3906541915076, -4528.2451648723845, -741.45168991899459, -7263.3367548363758};

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
static const double gb_tree_15_threshold[7] = {17589.5, 5244, -2, -2, 32959, -2, -2};
static const double gb_tree_15_value[7] = {1.5598079649872305e-11, 6187.6117019272369, 9868.0400752741243, 4624.0815165561935, -4249.7763143770771, -1706.0796824983113, -8066.1257203328478};

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
static const double gb_tree_16_threshold[7] = {25507, 12498, -2, -2, 37985.5, -2, -2};
static const double gb_tree_16_value[7] = {9.9363796534877099e-11, 4083.6985586044016, 7089.7021482591963, 1195.9590543996255, -5887.0454870837175, -4348.9533809092882, -9567.0025013589657};

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
static const double gb_tree_17_threshold[7] = {25727, 14885.5, -2, -2, 38227.5, -2, -2};
static const double gb_tree_17_value[7] = {3.3358050574954704e-11, 3839.4896887392442, 6258.8017748073262, 518.08573430844876, -5653.1752146776616, -4238.3239444591109, -9210.1205252788404};

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
static const double gb_tree_18_threshold[7] = {20586, 7560, -2, -2, 34111, -2, -2};
static const double gb_tree_18_value[7] = {-6.0608246808968842e-11, 4645.7274934462457, 7814.6804789144553, 2806.3004185683963, -4229.135972045583, -2167.364255271722, -7296.8112812157815};

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
static const double gb_tree_19_threshold[7] = {26025, 10437, -2, -2, 38600.5, -2, -2};
static const double gb_tree_19_value[7] = {-2.9314427310293601e-12, 3435.0103902263809, 6617.3638183346557, 1304.1827207821509, -5204.99311110488, -3973.7214452112712, -8571.0470596959149};

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
static const double gb_tree_20_threshold[7] = {17197, 4572, -2, -2, 29113, -2, -2};
static const double gb_tree_20_value[7] = {3.1993262934591789e-12, 4965.7209690250847, 8320.9069070847854, 3750.0364566975954, -3284.2920922578637, -589.37820777240688, -5563.4121812756657};

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
static const double gb_tree_21_threshold[7] = {17017, 4366, -2, -2, 32764, -2, -2};
static const double gb_tree_21_value[7] = {-1.006854827466617e-11, 4759.7829529375422, 8008.5287404697519, 3638.3208987524636, -3093.2994991687997, -1153.6593622300431, -6019.6156710056703};

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
static const double gb_tree_22_threshold[7] = {24936.5, 8565, -2, -2, 37704, -2, -2};
static const double gb_tree_22_value[7] = {1.3832557841271707e-11, 3133.957968983374, 6194.4657626309709, 1532.8533772927801, -4279.0366167494221, -3025.8644463532255, -7189.3203666210002};

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
static const double gb_tree_23_threshold[7] = {16796.5, 4054, -2, -2, 28032.5, -2, -2};
static const double gb_tree_23_value[7] = {1.0434910417581899e-11, 4375.5771616137818, 7453.8826771115591, 3395.653819278662, -2783.3845642212127, -245.1643698039455, -4663.0658869286808};

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
static const double gb_tree_24_threshold[7] = {22923.5, 8267.5, -2, -2, 37029, -2, -2};
static const double gb_tree_24_value[7] = {2.7311029262956952e-11, 3120.7477197337116, 5694.0136213158503, 1669.4826189960131, -3528.6038684381856, -2282.9800109787375, -6375.5572938337746};

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
static const double gb_tree_25_threshold[7] = {16585, 3777.5, -2, -2, 33327, -2, -2};
static const double gb_tree_25_value[7] = {3.8841479789213144e-11, 4016.4917039991478, 6935.7913436866793, 3155.6157859731024, -2502.9743822390687, -964.94370648537381, -5110.7639269554375};

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
static const double gb_tree_26_threshold[7] = {26449.5, 14292.5, -2, -2, 39355, -2, -2};
static const double gb_tree_26_value[7] = {2.4473154823081796e-11, 2411.3431798655456, 4167.29835577839, 347.05481425747604, -3807.5066841235453, -2923.7128557340811, -6773.8374442778668};

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
static const double gb_tree_27_threshold[7] = {26579.5, 11247, -2, -2, 39511, -2, -2};
static const double gb_tree_27_value[7] = {2.6319150817952043e-12, 2276.6148274448828, 4401.6905134567533, 717.7171342622695, -3640.5427127626158, -2821.0047559400709, -6512.8829442249653};

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
static const double gb_tree_28_threshold[7] = {19351, 4977.5, -2, -2, 35854, -2, -2};
static const double gb_tree_28_value[7] = {1.7449395124851903e-11, 3047.740102178112, 5688.3114650349135, 2133.0323751755086, -2473.1322154865065, -1352.7948705675219, -4991.0496272035707};

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
static const double gb_tree_29_threshold[7] = {26748.5, 15195, -2, -2, 39757.5, -2, -2};
static const double gb_tree_29_value[7] = {3.4945301601429143e-11, 2053.6929620852434, 3512.3800215911151, 134.81999625728832, -3338.7168316474517, -2618.2060686094715, -6060.7970050816684};

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
static const double gb_tree_30_threshold[7] = {16398, 3410, -2, -2, 30312, -2, -2};
static const double gb_tree_30_value[7] = {2.4996100636908643e-12, 3181.0300695683572, 5883.5678630423117, 2471.3611676910255, -1946.7611800102563, -404.2456115677013, -3611.3909490207252};

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
static const double gb_tree_31_threshold[7] = {26852, 6959.5, -2, -2, 39921, -2, -2};
static const double gb_tree_31_value[7] = {5.107655683456935e-12, 1852.0301449749738, 4454.423435870337, 941.19249316161313, -3041.7035608672404, -2385.0684704633309, -5659.8088867371816};

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
static const double gb_tree_32_threshold[7] = {16265, 3183.5, -2, -2, 35220.5, -2, -2};
static const double gb_tree_32_value[7] = {1.403524367313052e-13, 2920.3327522262666, 5480.0643181876894, 2297.1984953316137, -1763.4384544711743, -809.46386228287508, -4030.0480011563741};

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
static const double gb_tree_33_threshold[7] = {23542.5, 5937, -2, -2, 38914.5, -2, -2};
static const double gb_tree_33_value[7] = {4.8785088479772531e-12, 1977.073699319584, 4297.7630914721049, 1194.4014535392419, -2368.0572918021003, -1692.9575120595041, -4789.3335237580068};

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
static const double gb_tree_34_threshold[7] = {18059, 3577.5, -2, -2, 36427, -2, -2};
static const double gb_tree_34_value[7] = {-1.0123379838870236e-11, 2438.7863116721346, 4819.1498088284425, 1850.3519348582377, -1751.8662140924725, -959.57819350778459, -3900.2512340423887};

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
static const double gb_tree_35_threshold[7] = {27072, 9648.5, -2, -2, 40310.5, -2, -2};
static const double gb_tree_35_value[7] = {2.879407303805849e-11, 1528.480825603825, 3258.0737626824289, 570.41883981785372, -2565.4778589215539, -2048.2759583696729, -4935.2134727735001};

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
static const double gb_tree_36_threshold[7] = {16043.5, 2808, -2, -2, 31963.5, -2, -2};
static const double gb_tree_36_value[7] = {3.8546726032384815e-11, 2452.3740944868641, 4775.2483824434885, 1959.4881405812407, -1448.9572814019834, -420.24137473151245, -2906.1812552789347};

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
static const int gb_tree_37_feature[7] = {0, 0, -2, -2, 1, -2, -2};
static const double gb_tree_37_threshold[7] = {27152.5, 9195.5, -2, -2, 103.98500061035156, -2, -2};
static const double gb_tree_37_value[7] = {-1.7861041047160045e-11, 1382.4990766400108, 3017.6317367575198, 545.02088395121768, -2339.1415543795461, -4614.4034876189271, -1869.2384566233852};

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
static const double gb_tree_38_threshold[7] = {15958, 2659, -2, -2, 35124, -2, -2};
static const double gb_tree_38_value[7] = {3.7361845937258627e-12, 2241.5508979886263, 4460.1319267885892, 1797.8346922286846, -1312.9464593926486, -588.27281509323916, -3032.9199665403421};

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
static const double gb_tree_39_threshold[7] = {26266.5, 6380, -2, -2, 40161, -2, -2};
static const double gb_tree_39_value[7] = {4.1407787949659699e-11, 1316.5759776702687, 3187.820536300982, 716.09515334994899, -2042.4937063187713, -1591.0949921862789, -4106.5119205129167};

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
static const double gb_tree_40_threshold[7] = {19960.5, 4184, -2, -2, 38742, -2, -2};
static const double gb_tree_40_value[7] = {-1.5640908284598864e-11, 1690.2403871340325, 3525.3902470411117, 1203.3792744030309, -1451.8066999609077, -974.83680376669156, -3461.5970038377041};

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
static const double gb_tree_41_threshold[7] = {27338, 13211.5, -2, -2, 40775, -2, -2};
static const double gb_tree_41_value[7] = {4.687416754818304e-12, 1139.4079605227278, 2161.1926403929019, 183.93033509034106, -1963.54171510129, -1593.2983819780964, -4013.9680779787013};

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
static const double gb_tree_42_threshold[7] = {15835.5, 2406, -2, -2, 28222.5, -2, -2};
static const double gb_tree_42_value[7] = {-1.2850909165707855e-11, 1874.1668176355424, 3919.7764541576221, 1507.5754138883203, -1084.7403304628706, -59.196342607115362, -1932.6327754396698};

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
static const double gb_tree_43_threshold[7] = {15771, 2319, -2, -2, 36565, -2, -2};
static const double gb_tree_43_value[7] = {3.0165953318567204e-11, 1786.3385174359476, 3767.5270221878636, 1444.7707424775156, -1027.2448613907577, -515.19438028106811, -2632.1530831891159};

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
static const double gb_tree_44_threshold[7] = {27397.5, 6457.5, -2, -2, 40925.5, -2, -2};
static const double gb_tree_44_value[7] = {-1.0768537298286245e-12, 985.7889785447195, 2536.8836879988644, 507.3108147681973, -1709.2667446763066, -1381.150722953334, -3661.1364123618232};

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
static const double gb_tree_45_threshold[7] = {20788, 3060.5, -2, -2, 39070, -2, -2};
static const double gb_tree_45_value[7] = {2.2202146007167093e-11, 1284.4045673982962, 3164.3082237808248, 959.80947233497545, -1191.5739395146179, -812.54600378440841, -2869.1069915346675};

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
static const double gb_tree_46_threshold[7] = {15668, 2111, -2, -2, 31359.5, -2, -2};
static const double gb_tree_46_value[7] = {-2.0640946793535879e-12, 1569.1381305117307, 3397.769075283828, 1284.2474791398006, -893.03696167607302, -206.47950903892809, -1802.9369071136628};

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
static const double gb_tree_47_threshold[7] = {27475, 11136.5, -2, -2, 41081.5, -2, -2};
static const double gb_tree_47_value[7] = {3.8971329662651626e-12, 853.89301931394425, 1768.9856316115381, 229.85901302976362, -1492.1138421551227, -1207.139095563417, -3322.2268936616888};

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
static const double gb_tree_48_threshold[7] = {16140, 2185.5, -2, -2, 37223.5, -2, -2};
static const double gb_tree_48_value[7] = {7.5618455708295048e-12, 1391.5215624913881, 3105.7775873664932, 1122.9229513514892, -830.11516172566621, -442.27788540501484, -2198.1612290941625};

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
static const double gb_tree_49_threshold[7] = {27260.5, 5731, -2, -2, 41194, -2, -2};
static const double gb_tree_49_value[7] = {3.6924011805181378e-12, 788.00188412528996, 2140.633862753245, 427.96487386453322, -1347.497633593603, -1094.9176692475894, -3102.9079835394923};

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
static const double gb_tree_50_threshold[7] = {24035.5, 4828.5, -2, -2, 40588.5, -2, -2};
static const double gb_tree_50_value[7] = {-3.2512253237568091e-12, 877.18765626070649, 2176.7315343086311, 550.38382388267291, -1100.1914147151217, -846.05648143955466, -2711.3942795267212};

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
static const double gb_tree_51_threshold[7] = {15551, 1857.5, -2, -2, 35349, -2, -2};
static const double gb_tree_51_value[7] = {6.7073870286494652e-12, 1256.9338058250905, 2894.6180749868849, 1034.5465878220255, -707.03447003703275, -305.11464215411723, -1720.8743330252016};

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
static const double gb_tree_52_threshold[7] = {27610, 7753, -2, -2, 41363, -2, -2};
static const double gb_tree_52_value[7] = {7.3421783216985368e-12, 674.5707524662713, 1648.5259692296979, 294.14184254110063, -1194.5494542427457, -978.77399158933315, -2810.3918077282306};

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
static const double gb_tree_53_threshold[7] = {15506, 1762, -2, -2, 38401.5, -2, -2};
static const double gb_tree_53_value[7] = {6.3069256542635445e-12, 1148.2867780895253, 2716.0594393368897, 947.2808087945516, -642.98149569712132, -375.7638919651655, -1918.2644282948734};

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
static const double gb_tree_54_threshold[7] = {27656.5, 5679, -2, -2, 41479.5, -2, -2};
static const double gb_tree_54_value[7] = {4.6729586806749432e-12, 615.36642207003274, 1705.0831060506839, 333.82281897231059, -1095.0392896277365, -903.74132207746936, -2632.2679667219536};

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
static const double gb_tree_55_threshold[7] = {17382.5, 1968.5, -2, -2, 39147.5, -2, -2};
static const double gb_tree_55_value[7] = {1.086947102343801e-12, 958.36459384063653, 2405.8451548964663, 773.39860369309201, -645.2427114866698, -417.60613789773134, -1867.8567306266343};

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
static const double gb_tree_56_threshold[7] = {21934, 2963.5, -2, -2, 40064, -2, -2};
static const double gb_tree_56_value[7] = {7.434791834371575e-12, 739.16206930601572, 1996.9565596429702, 542.63168019085219, -762.35588290494331, -556.35154852007281, -1953.4780518637594};

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
static const double gb_tree_57_threshold[7] = {27726.5, 12307.5, -2, -2, 41622, -2, -2};
static const double gb_tree_57_value[7] = {9.9414945382082383e-12, 536.92189595558239, 1086.7242682636945, 98.11954040967882, -962.00847969097583, -800.93986171598488, -2380.8675579511228};

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
static const double gb_tree_58_threshold[7] = {15420, 1562.5, -2, -2, 33457, -2, -2};
static const double gb_tree_58_value[7] = {7.0346032538374155e-12, 919.13693047539459, 2319.3133979900335, 761.01552907032647, -510.15529256795645, -160.02990887314718, -1158.2597262158081};

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
static const double gb_tree_59_threshold[7] = {27752.5, 4777, -2, -2, 41686.5, -2, -2};
static const double gb_tree_59_value[7] = {2.919098809237151e-12, 487.44509240208311, 1478.4149206445179, 281.34237149717717, -875.6431341179765, -727.9376757272853, -2236.3045516698971};

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
static const double gb_tree_60_threshold[7] = {15385.5, 1473, -2, -2, 35984.5, -2, -2};
static const double gb_tree_60_value[7] = {3.7565759341450368e-12, 841.97700493560149, 2174.7551553343055, 700.78630448589649, -465.80372390449384, -208.89484803936006, -1199.3841197852034};

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
static const double gb_tree_61_threshold[7] = {26171.5, 3898, -2, -2, 41297.5, -2, -2};
static const double gb_tree_61_value[7] = {5.0770345735967035e-12, 481.46798047251582, 1459.7204702529309, 310.14928989860874, -739.92387563959471, -592.8026904966564, -1910.3769158740017};

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
static const double gb_tree_62_threshold[7] = {15351, 1390, -2, -2, 37288, -2, -2};
static const double gb_tree_62_value[7] = {1.6422189876043876e-12, 771.23223941033734, 2033.5097538147452, 645.26813377240273, -425.13313743929848, -219.2398342654248, -1189.1383150247195};

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
static const double gb_tree_63_threshold[7] = {18496, 2522.5, -2, -2, 39640.5, -2, -2};
static const double gb_tree_63_value[7] = {-2.8097766731437195e-14, 630.85087955462905, 1572.4183965692289, 482.10192482853813, -472.35228458651471, -318.16820399253345, -1388.0570107348651};

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
static const double gb_tree_64_threshold[7] = {27821.5, 9118, -2, -2, 41860, -2, -2};
static const double gb_tree_64_value[7] = {6.3256802315721494e-12, 389.96061337710603, 916.17047043235357, 133.37292108360566, -705.34577668126087, -588.74491604048512, -1925.9934337275538};

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
static const double gb_tree_65_threshold[7] = {27843, 8398.5, -2, -2, 41906, -2, -2};
static const double gb_tree_65_value[7] = {2.8521279186296966e-12, 370.0472384902954, 902.82938158637432, 139.87328030165898, -670.8618466197039, -562.13910660318118, -1854.0050475011726};

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
static const double gb_tree_66_threshold[7] = {15307.5, 1279, -2, -2, 33217.5, -2, -2};
static const double gb_tree_66_value[7] = {1.9084657869236371e-12, 643.24749044323107, 1818.9446901679344, 536.02043112871763, -353.07638093318957, -102.20255910016701, -803.05382645329314};

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
static const double gb_tree_67_threshold[7] = {22790.5, 2894, -2, -2, 40860.5, -2, -2};
static const double gb_tree_67_value[7] = {1.9293345165833937e-13, 430.12669746119417, 1276.1032296031608, 306.99041941904983, -480.37641957731114, -362.64038255983479, -1389.9769936540611};

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
static const double gb_tree_68_threshold[7] = {15104.5, 1204.5, -2, -2, 37829.5, -2, -2};
static const double gb_tree_68_value[7] = {3.1052124146014524e-12, 592.75979751249793, 1701.4284245727349, 496.64590115586901, -318.69467725134126, -168.5898493859809, -953.78838501702273};

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
static const double gb_tree_69_threshold[7] = {27878.5, 5085, -2, -2, 42014.5, -2, -2};
static const double gb_tree_69_value[7] = {1.5168020142570258e-12, 309.08536759071387, 936.06785970633882, 169.1816563028332, -562.36547008152559, -470.52392097301134, -1657.4379299436575};

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
static const double gb_tree_70_threshold[7] = {15458.5, 1149, -2, -2, 35001, -2, -2};
static const double gb_tree_70_value[7] = {4.3799780838830641e-12, 532.26471918075765, 1597.0670966528919, 446.68517559855292, -296.58655300449874, -113.43600405356533, -733.15204562439101};

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
static const double gb_tree_71_threshold[7] = {24453, 3293.5, -2, -2, 41777, -2, -2};
static const double gb_tree_71_value[7] = {4.5032809048792738e-12, 332.54403119164743, 1019.552884967304, 225.58016035731313, -433.79555753683672, -351.26595893937377, -1439.1903030932779};

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
static const double gb_tree_72_threshold[7] = {15060, 1080, -2, -2, 39203, -2, -2};
static const double gb_tree_72_value[7] = {1.606551191486568e-12, 496.31379583570867, 1500.2382735017331, 418.60562073942668, -265.61100919076392, -158.61050855309702, -911.86281733706403};

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
static const double gb_tree_73_threshold[7] = {27912, 7063.5, -2, -2, 42122, -2, -2};
static const double gb_tree_73_value[7] = {7.3242080267137458e-12, 258.81067869140315, 688.66908745964804, 113.11974014852973, -472.43915415364881, -396.4278939019743, -1473.8247359077727};

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
static const double gb_tree_74_threshold[7] = {19887.5, 1646, -2, -2, 40688, -2, -2};
static const double gb_tree_74_value[7] = {4.3586660642141947e-12, 359.93613813628963, 1197.4886606149503, 284.38985237294474, -307.11616011073147, -221.75121658548611, -1014.3784857566523};

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
static const double gb_tree_75_threshold[7] = {28157.5, 9752.5, -2, -2, 42186.5, -2, -2};
static const double gb_tree_75_value[7] = {2.4994736667649835e-14, 233.43511502388901, 551.34087064784489, 64.941147380223342, -436.91171830054333, -368.62354356428824, -1381.819337414624};

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
static const double gb_tree_76_threshold[7] = {28170.5, 2568, -2, -2, 42083.5, -2, -2};
static const double gb_tree_76_value[7] = {-2.1697340984482388e-13, 221.62117241319129, 923.14448053011631, 151.22917148485385, -415.34864553990286, -346.90266207220549, -1267.4515411739696};

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
static const double gb_tree_77_threshold[7] = {14389.5, 964.5, -2, -2, 32074, -2, -2};
static const double gb_tree_77_value[7] = {-5.6175073923992275e-13, 414.72807486776179, 1315.4877185078699, 349.95337076429843, -207.13088695328921, -37.164332096490227, -477.24658505032721};

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
static const double gb_tree_78_threshold[7] = {14181.5, 931, -2, -2, 38465.5, -2, -2};
static const double gb_tree_78_value[7] = {1.8228085174705177e-12, 398.45378781037641, 1265.9033726644818, 337.37176325340926, -194.73439194394055, -103.57142158400741, -662.52959303113619};

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
static const double gb_tree_79_threshold[7] = {29680, 5816, -2, -2, 42290.5, -2, -2};
static const double gb_tree_79_value[7] = {4.7708234749943903e-13, 179.19501467768498, 580.63809482574391, 81.313970427627865, -393.33606240463359, -331.91896848231579, -1244.214164324851};

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
static const double gb_tree_80_threshold[7] = {18464, 1338, -2, -2, 41020, -2, -2};
static const double gb_tree_80_value[7] = {4.9563232941922283e-13, 295.1543450783787, 1024.9295951344902, 237.99828122608736, -220.32212767767828, -159.91549746871175, -845.3018693494239};

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
static const double gb_tree_81_threshold[7] = {14162.5, 861, -2, -2, 33495.5, -2, -2};
static const double gb_tree_81_value[7] = {1.4081277635615279e-12, 348.97152690286327, 1157.9560987730249, 296.5628819643718, -170.20342655280612, -40.920313281740647, -427.7340073277378};

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
static const double gb_tree_82_threshold[7] = {25881.5, 1917, -2, -2, 42251.5, -2, -2};
static const double gb_tree_82_value[7] = {1.0340250951020649e-12, 190.3323058730216, 812.73714342640142, 140.5264578287381, -284.46597903580096, -237.13143627227322, -1100.7849025310124};

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
static const double gb_tree_83_threshold[7] = {14146.5, 810, -2, -2, 40537, -2, -2};
static const double gb_tree_83_value[7] = {1.2821311032791731e-13, 320.22523353770197, 1085.3359629788574, 273.76478117911921, -155.91744841779217, -101.77606599909554, -692.52309630721891};

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
static const double gb_tree_84_threshold[7] = {30175.5, 9739, -2, -2, 42394, -2, -2};
static const double gb_tree_84_value[7] = {3.3597972767578968e-13, 141.24104862038376, 377.11391525942577, 28.801335560204549, -327.19730611758422, -277.46721137809243, -1080.5383396813802};

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
static const double gb_tree_85_threshold[7] = {29697.5, 4719.5, -2, -2, 42368, -2, -2};
static const double gb_tree_85_value[7] = {2.6531589030011334e-12, 137.77376807564329, 499.44824540684237, 69.435068364641211, -303.04940156369594, -256.27930198585739, -1014.7920453338353};

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
static const double gb_tree_86_threshold[7] = {21888.5, 1614, -2, -2, 41557.5, -2, -2};
static const double gb_tree_86_value[7] = {3.2586930554487811e-12, 193.30062021992043, 751.98089786108494, 148.75260830831058, -198.53051996140502, -152.74015857882603, -746.93106101662249};

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
static const double gb_tree_87_threshold[7] = {13714, 745, -2, -2, 37158.5, -2, -2};
static const double gb_tree_87_value[7] = {3.4915226079272437e-12, 275.72503557582627, 982.02931625137307, 235.15311136120084, -128.25970123357683, -54.632608221623308, -413.96440478720297};

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
static const double gb_tree_88_threshold[7] = {30195, 3669, -2, -2, 42471.5, -2, -2};
static const double gb_tree_88_value[7] = {2.6065111543499124e-12, 117.79333450212467, 490.25366778750799, 66.254795467875965, -273.46243359754948, -232.90574142120349, -956.61738181244982};

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
static const double gb_tree_89_threshold[7] = {13150.5, 702.5, -2, -2, 39005, -2, -2};
static const double gb_tree_89_value[7] = {5.0381273504892161e-12, 261.00520875606588, 929.4782405817806, 223.25900841618102, -114.23901978758124, -60.58367162067178, -444.91340876061429};

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
static const double gb_tree_90_threshold[7] = {20018, 1029, -2, -2, 41745.5, -2, -2};
static const double gb_tree_90_value[7] = {1.8929506366047001e-12, 177.51297630550769, 764.11711597953513, 145.69105265891244, -153.30215114141998, -118.55629245558347, -672.32325182274565};

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
static const double gb_tree_91_threshold[7] = {30208, 7699, -2, -2, 42523.5, -2, -2};
static const double gb_tree_91_value[7] = {2.428035776834934e-12, 103.9712230888546, 314.85154244178671, 31.826358508843935, -241.71818880666098, -206.69488033286154, -878.84076688032451};

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
static const int gb_tree_92_feature[7] = {0, 0, -2, -2, 1, -2, -2};
static const double gb_tree_92_threshold[7] = {15610, 671.5, -2, -2, 97.799999237060547, -2, -2};
static const double gb_tree_92_value[7] = {2.8217796026212266e-12, 201.09715849510332, 843.62267159759529, 172.11314055424114, -113.78269423363281, -486.51090077021638, -75.887936720021472};

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
static const double gb_tree_93_threshold[7] = {30221, 3500, -2, -2, 42562.5, -2, -2};
static const double gb_tree_93_value[7] = {3.7442320123528277e-12, 95.343564729916821, 409.7819763008734, 54.132613843861414, -221.97656984412038, -190.53775813737212, -830.0063800100736};

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
static const double gb_tree_94_threshold[7] = {13134, 625, -2, -2, 35956.5, -2, -2};
static const double gb_tree_94_value[7] = {4.3532442864104349e-12, 210.84150722522205, 805.22869468293698, 181.12984517411167, -92.086993136284832, -30.434332938218859, -286.36456189995744};

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
static const int gb_tree_95_feature[7] = {1, 0, -2, -2, 0, -2, -2};
static const double gb_tree_95_threshold[7] = {417.69000244140625, 42441, -2, -2, 1700.5, -2, -2};
static const double gb_tree_95_value[7] = {2.9319542195014129e-12, -177.73749565222963, -149.70905907970368, -724.2920088164434, 99.84854978847325, 517.27391376869195, 72.502865225259143};

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
static const double gb_tree_96_threshold[7] = {12342, 586, -2, -2, 40019.5, -2, -2};
static const double gb_tree_96_value[7] = {3.1468134769950849e-12, 202.6345921562081, 758.5398565913938, 174.90826179997617, -81.045328166610588, -46.984090853576497, -377.73571842132162};

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
static const double gb_tree_97_threshold[7] = {23996.5, 1684.5, -2, -2, 42324, -2, -2};
static const double gb_tree_97_value[7] = {3.153258231742951e-12, 109.8665574877526, 474.56046325323587, 82.334497238326108, -137.29612986997859, -113.69534464597081, -631.86369578646907};

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
static const double gb_tree_98_threshold[7] = {11771, 547, -2, -2, 35020.5, -2, -2};
static const double gb_tree_98_value[7] = {1.7862029924872681e-12, 192.12598743826973, 716.31800284702751, 166.55933502728314, -71.963083730224952, -16.33317807108881, -230.08420567700639};

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
static const double gb_tree_99_threshold[7] = {30392.5, 4883.5, -2, -2, 42639.5, -2, -2};
static const double gb_tree_99_value[7] = {1.3535519435934875e-12, 73.043878987996877, 279.82260651893773, 33.44236500314905, -173.31757022391744, -148.53914060228965, -714.8623239773807};

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
