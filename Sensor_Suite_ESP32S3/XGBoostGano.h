// Auto-generated High-Speed XGBoost Classifier for ESP32-S3
// Generated from 35 Gradient Boosted Trees on Multimodal Dataset
#ifndef XGBOOST_GANO_H
#define XGBOOST_GANO_H

#include <Arduino.h>
#include <math.h>

struct XGBoostOutput {
    uint8_t  predicted_class;     // 0: HEALTHY, 1: EARLY, 2: MODERATE, 3: SEVERE
    float    probabilities[4];    // Softmax class probabilities
    float    risk_score;          // Continuous risk score 0.0 to 1.0
};

class XGBoostGano {
public:
    static XGBoostOutput predict(const float* features) {
        float raw_scores[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        
        // Tree ensemble execution
        // Tree 0 (Class 0)
        raw_scores[0] += evaluate_tree_0(features);
        // Tree 1 (Class 1)
        raw_scores[1] += evaluate_tree_1(features);
        // Tree 2 (Class 2)
        raw_scores[2] += evaluate_tree_2(features);
        // Tree 3 (Class 3)
        raw_scores[3] += evaluate_tree_3(features);
        // Tree 4 (Class 0)
        raw_scores[0] += evaluate_tree_4(features);
        // Tree 5 (Class 1)
        raw_scores[1] += evaluate_tree_5(features);
        // Tree 6 (Class 2)
        raw_scores[2] += evaluate_tree_6(features);
        // Tree 7 (Class 3)
        raw_scores[3] += evaluate_tree_7(features);
        // Tree 8 (Class 0)
        raw_scores[0] += evaluate_tree_8(features);
        // Tree 9 (Class 1)
        raw_scores[1] += evaluate_tree_9(features);
        // Tree 10 (Class 2)
        raw_scores[2] += evaluate_tree_10(features);
        // Tree 11 (Class 3)
        raw_scores[3] += evaluate_tree_11(features);
        // Tree 12 (Class 0)
        raw_scores[0] += evaluate_tree_12(features);
        // Tree 13 (Class 1)
        raw_scores[1] += evaluate_tree_13(features);
        // Tree 14 (Class 2)
        raw_scores[2] += evaluate_tree_14(features);
        // Tree 15 (Class 3)
        raw_scores[3] += evaluate_tree_15(features);
        // Tree 16 (Class 0)
        raw_scores[0] += evaluate_tree_16(features);
        // Tree 17 (Class 1)
        raw_scores[1] += evaluate_tree_17(features);
        // Tree 18 (Class 2)
        raw_scores[2] += evaluate_tree_18(features);
        // Tree 19 (Class 3)
        raw_scores[3] += evaluate_tree_19(features);
        // Tree 20 (Class 0)
        raw_scores[0] += evaluate_tree_20(features);
        // Tree 21 (Class 1)
        raw_scores[1] += evaluate_tree_21(features);
        // Tree 22 (Class 2)
        raw_scores[2] += evaluate_tree_22(features);
        // Tree 23 (Class 3)
        raw_scores[3] += evaluate_tree_23(features);
        // Tree 24 (Class 0)
        raw_scores[0] += evaluate_tree_24(features);
        // Tree 25 (Class 1)
        raw_scores[1] += evaluate_tree_25(features);
        // Tree 26 (Class 2)
        raw_scores[2] += evaluate_tree_26(features);
        // Tree 27 (Class 3)
        raw_scores[3] += evaluate_tree_27(features);
        // Tree 28 (Class 0)
        raw_scores[0] += evaluate_tree_28(features);
        // Tree 29 (Class 1)
        raw_scores[1] += evaluate_tree_29(features);
        // Tree 30 (Class 2)
        raw_scores[2] += evaluate_tree_30(features);
        // Tree 31 (Class 3)
        raw_scores[3] += evaluate_tree_31(features);
        // Tree 32 (Class 0)
        raw_scores[0] += evaluate_tree_32(features);
        // Tree 33 (Class 1)
        raw_scores[1] += evaluate_tree_33(features);
        // Tree 34 (Class 2)
        raw_scores[2] += evaluate_tree_34(features);
        // Tree 35 (Class 3)
        raw_scores[3] += evaluate_tree_35(features);
        // Tree 36 (Class 0)
        raw_scores[0] += evaluate_tree_36(features);
        // Tree 37 (Class 1)
        raw_scores[1] += evaluate_tree_37(features);
        // Tree 38 (Class 2)
        raw_scores[2] += evaluate_tree_38(features);
        // Tree 39 (Class 3)
        raw_scores[3] += evaluate_tree_39(features);
        // Tree 40 (Class 0)
        raw_scores[0] += evaluate_tree_40(features);
        // Tree 41 (Class 1)
        raw_scores[1] += evaluate_tree_41(features);
        // Tree 42 (Class 2)
        raw_scores[2] += evaluate_tree_42(features);
        // Tree 43 (Class 3)
        raw_scores[3] += evaluate_tree_43(features);
        // Tree 44 (Class 0)
        raw_scores[0] += evaluate_tree_44(features);
        // Tree 45 (Class 1)
        raw_scores[1] += evaluate_tree_45(features);
        // Tree 46 (Class 2)
        raw_scores[2] += evaluate_tree_46(features);
        // Tree 47 (Class 3)
        raw_scores[3] += evaluate_tree_47(features);
        // Tree 48 (Class 0)
        raw_scores[0] += evaluate_tree_48(features);
        // Tree 49 (Class 1)
        raw_scores[1] += evaluate_tree_49(features);
        // Tree 50 (Class 2)
        raw_scores[2] += evaluate_tree_50(features);
        // Tree 51 (Class 3)
        raw_scores[3] += evaluate_tree_51(features);
        // Tree 52 (Class 0)
        raw_scores[0] += evaluate_tree_52(features);
        // Tree 53 (Class 1)
        raw_scores[1] += evaluate_tree_53(features);
        // Tree 54 (Class 2)
        raw_scores[2] += evaluate_tree_54(features);
        // Tree 55 (Class 3)
        raw_scores[3] += evaluate_tree_55(features);
        // Tree 56 (Class 0)
        raw_scores[0] += evaluate_tree_56(features);
        // Tree 57 (Class 1)
        raw_scores[1] += evaluate_tree_57(features);
        // Tree 58 (Class 2)
        raw_scores[2] += evaluate_tree_58(features);
        // Tree 59 (Class 3)
        raw_scores[3] += evaluate_tree_59(features);
        // Tree 60 (Class 0)
        raw_scores[0] += evaluate_tree_60(features);
        // Tree 61 (Class 1)
        raw_scores[1] += evaluate_tree_61(features);
        // Tree 62 (Class 2)
        raw_scores[2] += evaluate_tree_62(features);
        // Tree 63 (Class 3)
        raw_scores[3] += evaluate_tree_63(features);
        // Tree 64 (Class 0)
        raw_scores[0] += evaluate_tree_64(features);
        // Tree 65 (Class 1)
        raw_scores[1] += evaluate_tree_65(features);
        // Tree 66 (Class 2)
        raw_scores[2] += evaluate_tree_66(features);
        // Tree 67 (Class 3)
        raw_scores[3] += evaluate_tree_67(features);
        // Tree 68 (Class 0)
        raw_scores[0] += evaluate_tree_68(features);
        // Tree 69 (Class 1)
        raw_scores[1] += evaluate_tree_69(features);
        // Tree 70 (Class 2)
        raw_scores[2] += evaluate_tree_70(features);
        // Tree 71 (Class 3)
        raw_scores[3] += evaluate_tree_71(features);
        // Tree 72 (Class 0)
        raw_scores[0] += evaluate_tree_72(features);
        // Tree 73 (Class 1)
        raw_scores[1] += evaluate_tree_73(features);
        // Tree 74 (Class 2)
        raw_scores[2] += evaluate_tree_74(features);
        // Tree 75 (Class 3)
        raw_scores[3] += evaluate_tree_75(features);
        // Tree 76 (Class 0)
        raw_scores[0] += evaluate_tree_76(features);
        // Tree 77 (Class 1)
        raw_scores[1] += evaluate_tree_77(features);
        // Tree 78 (Class 2)
        raw_scores[2] += evaluate_tree_78(features);
        // Tree 79 (Class 3)
        raw_scores[3] += evaluate_tree_79(features);
        // Tree 80 (Class 0)
        raw_scores[0] += evaluate_tree_80(features);
        // Tree 81 (Class 1)
        raw_scores[1] += evaluate_tree_81(features);
        // Tree 82 (Class 2)
        raw_scores[2] += evaluate_tree_82(features);
        // Tree 83 (Class 3)
        raw_scores[3] += evaluate_tree_83(features);
        // Tree 84 (Class 0)
        raw_scores[0] += evaluate_tree_84(features);
        // Tree 85 (Class 1)
        raw_scores[1] += evaluate_tree_85(features);
        // Tree 86 (Class 2)
        raw_scores[2] += evaluate_tree_86(features);
        // Tree 87 (Class 3)
        raw_scores[3] += evaluate_tree_87(features);
        // Tree 88 (Class 0)
        raw_scores[0] += evaluate_tree_88(features);
        // Tree 89 (Class 1)
        raw_scores[1] += evaluate_tree_89(features);
        // Tree 90 (Class 2)
        raw_scores[2] += evaluate_tree_90(features);
        // Tree 91 (Class 3)
        raw_scores[3] += evaluate_tree_91(features);
        // Tree 92 (Class 0)
        raw_scores[0] += evaluate_tree_92(features);
        // Tree 93 (Class 1)
        raw_scores[1] += evaluate_tree_93(features);
        // Tree 94 (Class 2)
        raw_scores[2] += evaluate_tree_94(features);
        // Tree 95 (Class 3)
        raw_scores[3] += evaluate_tree_95(features);
        // Tree 96 (Class 0)
        raw_scores[0] += evaluate_tree_96(features);
        // Tree 97 (Class 1)
        raw_scores[1] += evaluate_tree_97(features);
        // Tree 98 (Class 2)
        raw_scores[2] += evaluate_tree_98(features);
        // Tree 99 (Class 3)
        raw_scores[3] += evaluate_tree_99(features);
        // Tree 100 (Class 0)
        raw_scores[0] += evaluate_tree_100(features);
        // Tree 101 (Class 1)
        raw_scores[1] += evaluate_tree_101(features);
        // Tree 102 (Class 2)
        raw_scores[2] += evaluate_tree_102(features);
        // Tree 103 (Class 3)
        raw_scores[3] += evaluate_tree_103(features);
        // Tree 104 (Class 0)
        raw_scores[0] += evaluate_tree_104(features);
        // Tree 105 (Class 1)
        raw_scores[1] += evaluate_tree_105(features);
        // Tree 106 (Class 2)
        raw_scores[2] += evaluate_tree_106(features);
        // Tree 107 (Class 3)
        raw_scores[3] += evaluate_tree_107(features);
        // Tree 108 (Class 0)
        raw_scores[0] += evaluate_tree_108(features);
        // Tree 109 (Class 1)
        raw_scores[1] += evaluate_tree_109(features);
        // Tree 110 (Class 2)
        raw_scores[2] += evaluate_tree_110(features);
        // Tree 111 (Class 3)
        raw_scores[3] += evaluate_tree_111(features);
        // Tree 112 (Class 0)
        raw_scores[0] += evaluate_tree_112(features);
        // Tree 113 (Class 1)
        raw_scores[1] += evaluate_tree_113(features);
        // Tree 114 (Class 2)
        raw_scores[2] += evaluate_tree_114(features);
        // Tree 115 (Class 3)
        raw_scores[3] += evaluate_tree_115(features);
        // Tree 116 (Class 0)
        raw_scores[0] += evaluate_tree_116(features);
        // Tree 117 (Class 1)
        raw_scores[1] += evaluate_tree_117(features);
        // Tree 118 (Class 2)
        raw_scores[2] += evaluate_tree_118(features);
        // Tree 119 (Class 3)
        raw_scores[3] += evaluate_tree_119(features);
        // Tree 120 (Class 0)
        raw_scores[0] += evaluate_tree_120(features);
        // Tree 121 (Class 1)
        raw_scores[1] += evaluate_tree_121(features);
        // Tree 122 (Class 2)
        raw_scores[2] += evaluate_tree_122(features);
        // Tree 123 (Class 3)
        raw_scores[3] += evaluate_tree_123(features);
        // Tree 124 (Class 0)
        raw_scores[0] += evaluate_tree_124(features);
        // Tree 125 (Class 1)
        raw_scores[1] += evaluate_tree_125(features);
        // Tree 126 (Class 2)
        raw_scores[2] += evaluate_tree_126(features);
        // Tree 127 (Class 3)
        raw_scores[3] += evaluate_tree_127(features);
        // Tree 128 (Class 0)
        raw_scores[0] += evaluate_tree_128(features);
        // Tree 129 (Class 1)
        raw_scores[1] += evaluate_tree_129(features);
        // Tree 130 (Class 2)
        raw_scores[2] += evaluate_tree_130(features);
        // Tree 131 (Class 3)
        raw_scores[3] += evaluate_tree_131(features);
        // Tree 132 (Class 0)
        raw_scores[0] += evaluate_tree_132(features);
        // Tree 133 (Class 1)
        raw_scores[1] += evaluate_tree_133(features);
        // Tree 134 (Class 2)
        raw_scores[2] += evaluate_tree_134(features);
        // Tree 135 (Class 3)
        raw_scores[3] += evaluate_tree_135(features);
        // Tree 136 (Class 0)
        raw_scores[0] += evaluate_tree_136(features);
        // Tree 137 (Class 1)
        raw_scores[1] += evaluate_tree_137(features);
        // Tree 138 (Class 2)
        raw_scores[2] += evaluate_tree_138(features);
        // Tree 139 (Class 3)
        raw_scores[3] += evaluate_tree_139(features);

        // Softmax normalization
        float max_s = raw_scores[0];
        for (int c = 1; c < 4; c++) {
            if (raw_scores[c] > max_s) max_s = raw_scores[c];
        }
        
        float sum_exp = 0.0f;
        float exp_scores[4];
        for (int c = 0; c < 4; c++) {
            exp_scores[c] = expf(raw_scores[c] - max_s);
            sum_exp += exp_scores[c];
        }
        
        XGBoostOutput out;
        uint8_t best_c = 0;
        float max_prob = 0.0f;
        for (int c = 0; c < 4; c++) {
            out.probabilities[c] = exp_scores[c] / sum_exp;
            if (out.probabilities[c] > max_prob) {
                max_prob = out.probabilities[c];
                best_c = c;
            }
        }
        
        out.predicted_class = best_c;
        out.risk_score = 1.0f - out.probabilities[0]; // P(Infected) = 1.0 - P(Healthy)
        return out;
    }

private:
    static inline float evaluate_tree_0(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[4] < 1.623931f) {
                if (features[9] < 58.235779f) {
                    if (features[4] < 0.400538f) {
                        return -0.028465f;
                    } else {
                        return 0.045115f;
                    }
                } else {
                    if (features[9] < 82.335815f) {
                        return 0.054111f;
                    } else {
                        return 0.086564f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.927128f) {
                        return 0.012302f;
                    } else {
                        return -0.042546f;
                    }
                } else {
                    if (features[0] < 0.414259f) {
                        return 0.089505f;
                    } else {
                        return 0.010026f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[0] < 0.628219f) {
                    if (features[6] < 75.935898f) {
                        return 0.004920f;
                    } else {
                        return 0.051308f;
                    }
                } else {
                    if (features[8] < -43.954227f) {
                        return 0.009354f;
                    } else {
                        return -0.033886f;
                    }
                }
            } else {
                if (features[8] < -38.093536f) {
                    if (features[4] < 7.331466f) {
                        return -0.042044f;
                    } else {
                        return -0.000342f;
                    }
                } else {
                    if (features[9] < 169.536896f) {
                        return -0.057600f;
                    } else {
                        return -0.018342f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_1(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.497523f) {
                    if (features[0] < 0.220000f) {
                        return -0.038511f;
                    } else {
                        return -0.014026f;
                    }
                } else {
                    if (features[8] < -26.652636f) {
                        return 0.043862f;
                    } else {
                        return 0.003706f;
                    }
                }
            } else {
                if (features[0] < 0.739753f) {
                    if (features[8] < -28.226032f) {
                        return 0.096452f;
                    } else {
                        return 0.032207f;
                    }
                } else {
                    if (features[8] < -34.658733f) {
                        return 0.052349f;
                    } else {
                        return -0.033205f;
                    }
                }
            }
        } else {
            if (features[8] < -30.668053f) {
                if (features[4] < 8.812652f) {
                    if (features[8] < -38.221569f) {
                        return -0.022455f;
                    } else {
                        return -0.039470f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.032668f;
                    } else {
                        return -0.053262f;
                    }
                }
            } else {
                if (features[7] < 91.934250f) {
                    if (features[7] < 62.344837f) {
                        return -0.055537f;
                    } else {
                        return -0.046526f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.035743f;
                    } else {
                        return 0.015634f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_2(const float* features) {
        if (features[0] < 0.516456f) {
            if (features[4] < 3.827744f) {
                if (features[9] < 71.615776f) {
                    if (features[0] < 0.220345f) {
                        return 0.001106f;
                    } else {
                        return -0.039618f;
                    }
                } else {
                    if (features[4] < 0.400538f) {
                        return -0.040380f;
                    } else {
                        return -0.050375f;
                    }
                }
            } else {
                if (features[0] < 0.421617f) {
                    if (features[0] < 0.337552f) {
                        return -0.051974f;
                    } else {
                        return -0.024073f;
                    }
                } else {
                    if (features[9] < 95.357391f) {
                        return 0.087863f;
                    } else {
                        return -0.012402f;
                    }
                }
            }
        } else {
            if (features[9] < 29.557575f) {
                if (features[9] < 21.241404f) {
                    if (features[4] < 1.786625f) {
                        return 0.030011f;
                    } else {
                        return -0.050193f;
                    }
                } else {
                    if (features[10] < -34.938953f) {
                        return 0.106084f;
                    } else {
                        return -0.044489f;
                    }
                }
            } else {
                if (features[4] < 3.421923f) {
                    if (features[9] < 63.809109f) {
                        return 0.079068f;
                    } else {
                        return -0.006510f;
                    }
                } else {
                    if (features[4] < 8.450968f) {
                        return 0.124801f;
                    } else {
                        return 0.022647f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_3(const float* features) {
        if (features[8] < -12.451389f) {
            if (features[9] < 29.557575f) {
                if (features[4] < 8.192201f) {
                    if (features[8] < -19.934113f) {
                        return -0.042362f;
                    } else {
                        return 0.081989f;
                    }
                } else {
                    return 0.234357f;
                }
            } else {
                if (features[4] < 11.305647f) {
                    if (features[0] < 0.811343f) {
                        return -0.045610f;
                    } else {
                        return -0.034083f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return 0.148055f;
                    } else {
                        return -0.006808f;
                    }
                }
            }
        } else {
            if (features[9] < 50.309807f) {
                if (features[8] < 9.294910f) {
                    if (features[9] < 36.799816f) {
                        return 0.282767f;
                    } else {
                        return 0.191994f;
                    }
                } else {
                    return -0.035695f;
                }
            } else {
                if (features[4] < 7.015437f) {
                    if (features[9] < 58.235779f) {
                        return 0.017204f;
                    } else {
                        return -0.041158f;
                    }
                } else {
                    if (features[0] < 0.599232f) {
                        return -0.031637f;
                    } else {
                        return 0.175681f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_4(const float* features) {
        if (features[4] < 1.670599f) {
            if (features[0] < 0.560268f) {
                if (features[9] < 61.430943f) {
                    if (features[9] < 35.805687f) {
                        return -0.045112f;
                    } else {
                        return 0.024451f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.096090f;
                    } else {
                        return 0.064964f;
                    }
                }
            } else {
                if (features[8] < -38.367355f) {
                    if (features[0] < 0.613141f) {
                        return 0.040305f;
                    } else {
                        return -0.008981f;
                    }
                } else {
                    if (features[9] < 86.299431f) {
                        return -0.043998f;
                    } else {
                        return -0.017183f;
                    }
                }
            }
        } else {
            if (features[0] < 0.510783f) {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.895638f) {
                        return 0.007920f;
                    } else {
                        return -0.041545f;
                    }
                } else {
                    if (features[0] < 0.398692f) {
                        return 0.085650f;
                    } else {
                        return 0.015303f;
                    }
                }
            } else {
                if (features[8] < -37.889999f) {
                    if (features[4] < 4.196662f) {
                        return -0.049237f;
                    } else {
                        return -0.015474f;
                    }
                } else {
                    if (features[9] < 122.216560f) {
                        return -0.056714f;
                    } else {
                        return -0.041706f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_5(const float* features) {
        if (features[8] < -25.423883f) {
            if (features[0] < 0.320042f) {
                if (features[0] < 0.220000f) {
                    if (features[7] < 109.807594f) {
                        return -0.013169f;
                    } else {
                        return -0.033192f;
                    }
                } else {
                    if (features[8] < -45.201443f) {
                        return -0.012451f;
                    } else {
                        return 0.008015f;
                    }
                }
            } else {
                if (features[0] < 0.826246f) {
                    if (features[0] < 0.447848f) {
                        return 0.013220f;
                    } else {
                        return 0.034922f;
                    }
                } else {
                    if (features[8] < -39.060780f) {
                        return 0.029795f;
                    } else {
                        return -0.035219f;
                    }
                }
            }
        } else {
            if (features[7] < 68.562370f) {
                if (features[12] < 10.241736f) {
                    if (features[0] < 0.677156f) {
                        return -0.040889f;
                    } else {
                        return -0.054412f;
                    }
                } else {
                    if (features[0] < 0.596163f) {
                        return 0.021360f;
                    } else {
                        return -0.038456f;
                    }
                }
            } else {
                if (features[0] < 0.616168f) {
                    if (features[0] < 0.263678f) {
                        return -0.011854f;
                    } else {
                        return 0.018918f;
                    }
                } else {
                    if (features[12] < 8.883047f) {
                        return -0.033734f;
                    } else {
                        return 0.002533f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_6(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[8] < -28.914127f) {
                if (features[9] < 62.805889f) {
                    if (features[8] < -31.245762f) {
                        return -0.033653f;
                    } else {
                        return 0.011643f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.042131f;
                    } else {
                        return -0.049924f;
                    }
                }
            } else {
                if (features[10] < -15.526775f) {
                    if (features[12] < 11.994812f) {
                        return 0.037000f;
                    } else {
                        return -0.029730f;
                    }
                } else {
                    if (features[0] < 0.433287f) {
                        return -0.035239f;
                    } else {
                        return -0.000223f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -33.892399f) {
                    if (features[0] < 0.731283f) {
                        return -0.018209f;
                    } else {
                        return 0.045672f;
                    }
                } else {
                    if (features[0] < 0.689149f) {
                        return 0.064732f;
                    } else {
                        return 0.113928f;
                    }
                }
            } else {
                if (features[12] < 11.254656f) {
                    if (features[7] < 57.726425f) {
                        return -0.051131f;
                    } else {
                        return 0.027485f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.048641f;
                    } else {
                        return 0.059284f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_7(const float* features) {
        if (features[8] < -14.335972f) {
            if (features[9] < 21.241404f) {
                if (features[12] < 1.778070f) {
                    if (features[0] < 0.684972f) {
                        return 0.044121f;
                    } else {
                        return 0.175805f;
                    }
                } else {
                    return -0.023721f;
                }
            } else {
                if (features[12] < -30.397575f) {
                    if (features[11] < 49.034405f) {
                        return -0.036126f;
                    } else {
                        return 0.165937f;
                    }
                } else {
                    if (features[9] < 34.864788f) {
                        return -0.006232f;
                    } else {
                        return -0.044641f;
                    }
                }
            }
        } else {
            if (features[9] < 52.675392f) {
                if (features[12] < 11.254656f) {
                    if (features[8] < 9.294910f) {
                        return 0.216134f;
                    } else {
                        return -0.024773f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return 0.049005f;
                    } else {
                        return 0.191696f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[12] < 7.045576f) {
                        return -0.002341f;
                    } else {
                        return -0.044834f;
                    }
                } else {
                    if (features[12] < 16.149860f) {
                        return 0.183989f;
                    } else {
                        return 0.002219f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_8(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[8] < -36.246079f) {
                if (features[9] < 93.905449f) {
                    if (features[0] < 0.441691f) {
                        return 0.047608f;
                    } else {
                        return 0.009170f;
                    }
                } else {
                    if (features[0] < 0.453835f) {
                        return 0.069785f;
                    } else {
                        return 0.043707f;
                    }
                }
            } else {
                if (features[9] < 107.164749f) {
                    if (features[0] < 0.220000f) {
                        return 0.055682f;
                    } else {
                        return -0.002418f;
                    }
                } else {
                    if (features[0] < 0.433287f) {
                        return 0.051051f;
                    } else {
                        return 0.021759f;
                    }
                }
            }
        } else {
            if (features[0] < 0.613141f) {
                if (features[8] < -37.889999f) {
                    if (features[9] < 76.524193f) {
                        return -0.019012f;
                    } else {
                        return 0.024915f;
                    }
                } else {
                    if (features[9] < 107.164749f) {
                        return -0.040997f;
                    } else {
                        return -0.001431f;
                    }
                }
            } else {
                if (features[8] < -42.629635f) {
                    if (features[0] < 0.982828f) {
                        return -0.027467f;
                    } else {
                        return 0.009489f;
                    }
                } else {
                    if (features[7] < 105.973305f) {
                        return -0.054248f;
                    } else {
                        return -0.036444f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_9(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.476928f) {
                    if (features[0] < 0.220000f) {
                        return -0.035238f;
                    } else {
                        return -0.014086f;
                    }
                } else {
                    if (features[0] < 0.592166f) {
                        return 0.013727f;
                    } else {
                        return 0.045882f;
                    }
                }
            } else {
                if (features[0] < 0.739753f) {
                    if (features[8] < -27.366392f) {
                        return 0.081778f;
                    } else {
                        return 0.027266f;
                    }
                } else {
                    if (features[8] < -38.221569f) {
                        return 0.067982f;
                    } else {
                        return -0.024851f;
                    }
                }
            }
        } else {
            if (features[8] < -31.245762f) {
                if (features[4] < 8.450968f) {
                    if (features[8] < -37.965397f) {
                        return -0.022491f;
                    } else {
                        return -0.038615f;
                    }
                } else {
                    if (features[4] < 12.867560f) {
                        return 0.021490f;
                    } else {
                        return -0.048502f;
                    }
                }
            } else {
                if (features[9] < 95.902306f) {
                    if (features[0] < 0.418023f) {
                        return -0.020454f;
                    } else {
                        return -0.052358f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return -0.033145f;
                    } else {
                        return 0.022145f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_10(const float* features) {
        if (features[0] < 0.537527f) {
            if (features[8] < -30.046419f) {
                if (features[9] < 65.561447f) {
                    if (features[11] < 2.257185f) {
                        return -0.031073f;
                    } else {
                        return 0.017635f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.040648f;
                    } else {
                        return -0.048667f;
                    }
                }
            } else {
                if (features[0] < 0.433287f) {
                    if (features[0] < 0.220345f) {
                        return 0.003522f;
                    } else {
                        return -0.038998f;
                    }
                } else {
                    if (features[12] < 8.613287f) {
                        return 0.061216f;
                    } else {
                        return -0.018152f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -35.359493f) {
                    if (features[0] < 0.762566f) {
                        return -0.018417f;
                    } else {
                        return 0.043505f;
                    }
                } else {
                    if (features[9] < 95.902306f) {
                        return 0.096783f;
                    } else {
                        return 0.043382f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[7] < 58.294384f) {
                        return -0.050786f;
                    } else {
                        return 0.026401f;
                    }
                } else {
                    if (features[9] < 26.425684f) {
                        return -0.034097f;
                    } else {
                        return 0.057179f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_11(const float* features) {
        if (features[8] < -14.335972f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 49.034405f) {
                    if (features[4] < 9.028560f) {
                        return -0.040056f;
                    } else {
                        return 0.051233f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.227811f;
                    } else {
                        return -0.038598f;
                    }
                }
            } else {
                if (features[9] < 29.557575f) {
                    if (features[8] < -17.408821f) {
                        return -0.009237f;
                    } else {
                        return 0.122435f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return -0.044320f;
                    } else {
                        return 0.023107f;
                    }
                }
            }
        } else {
            if (features[9] < 52.675392f) {
                if (features[12] < 11.254656f) {
                    if (features[8] < 4.928890f) {
                        return 0.174569f;
                    } else {
                        return 0.105994f;
                    }
                } else {
                    if (features[7] < 17.192841f) {
                        return 0.158302f;
                    } else {
                        return 0.035814f;
                    }
                }
            } else {
                if (features[4] < 9.522261f) {
                    if (features[12] < 7.045576f) {
                        return -0.006324f;
                    } else {
                        return -0.044585f;
                    }
                } else {
                    if (features[7] < 82.335472f) {
                        return 0.158042f;
                    } else {
                        return 0.010887f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_12(const float* features) {
        if (features[4] < 1.670599f) {
            if (features[0] < 0.592166f) {
                if (features[9] < 61.430943f) {
                    if (features[9] < 35.805687f) {
                        return -0.043777f;
                    } else {
                        return 0.018752f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.083558f;
                    } else {
                        return 0.054890f;
                    }
                }
            } else {
                if (features[9] < 83.752045f) {
                    if (features[4] < 0.779510f) {
                        return -0.017439f;
                    } else {
                        return -0.045118f;
                    }
                } else {
                    if (features[0] < 0.716383f) {
                        return 0.006711f;
                    } else {
                        return -0.027478f;
                    }
                }
            }
        } else {
            if (features[0] < 0.474017f) {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.974356f) {
                        return 0.005718f;
                    } else {
                        return -0.041200f;
                    }
                } else {
                    if (features[0] < 0.402608f) {
                        return 0.074991f;
                    } else {
                        return 0.014001f;
                    }
                }
            } else {
                if (features[9] < 113.426125f) {
                    if (features[0] < 0.661144f) {
                        return -0.045358f;
                    } else {
                        return -0.054227f;
                    }
                } else {
                    if (features[4] < 3.764467f) {
                        return -0.043101f;
                    } else {
                        return -0.008378f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_13(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.544245f) {
                    if (features[4] < 0.400000f) {
                        return -0.031813f;
                    } else {
                        return -0.010121f;
                    }
                } else {
                    if (features[9] < 45.711044f) {
                        return -0.022789f;
                    } else {
                        return 0.044346f;
                    }
                }
            } else {
                if (features[0] < 0.739753f) {
                    if (features[8] < -28.226032f) {
                        return 0.077340f;
                    } else {
                        return 0.028082f;
                    }
                } else {
                    if (features[8] < -31.652088f) {
                        return 0.036676f;
                    } else {
                        return -0.036768f;
                    }
                }
            }
        } else {
            if (features[8] < -30.668053f) {
                if (features[4] < 8.192201f) {
                    if (features[8] < -38.221569f) {
                        return -0.021212f;
                    } else {
                        return -0.037592f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.018716f;
                    } else {
                        return -0.047491f;
                    }
                }
            } else {
                if (features[9] < 97.146423f) {
                    if (features[0] < 0.418023f) {
                        return -0.018594f;
                    } else {
                        return -0.051287f;
                    }
                } else {
                    if (features[4] < 8.068044f) {
                        return -0.035908f;
                    } else {
                        return 0.008769f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_14(const float* features) {
        if (features[0] < 0.544245f) {
            if (features[8] < -30.046419f) {
                if (features[9] < 60.447125f) {
                    if (features[12] < -1.710238f) {
                        return 0.011006f;
                    } else {
                        return -0.032848f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.038762f;
                    } else {
                        return -0.048059f;
                    }
                }
            } else {
                if (features[0] < 0.465420f) {
                    if (features[7] < 91.934250f) {
                        return 0.000895f;
                    } else {
                        return -0.040149f;
                    }
                } else {
                    if (features[9] < 103.294876f) {
                        return 0.066844f;
                    } else {
                        return -0.024150f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -34.941708f) {
                    if (features[9] < 89.328476f) {
                        return 0.027894f;
                    } else {
                        return -0.025294f;
                    }
                } else {
                    if (features[9] < 89.328476f) {
                        return 0.089512f;
                    } else {
                        return 0.048863f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[9] < 59.967148f) {
                        return -0.049859f;
                    } else {
                        return 0.025872f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.047718f;
                    } else {
                        return 0.046071f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_15(const float* features) {
        if (features[8] < -14.335972f) {
            if (features[9] < 34.864788f) {
                if (features[8] < -17.408821f) {
                    if (features[0] < 0.943626f) {
                        return -0.031399f;
                    } else {
                        return 0.034975f;
                    }
                } else {
                    if (features[0] < 0.758140f) {
                        return 0.032864f;
                    } else {
                        return 0.148672f;
                    }
                }
            } else {
                if (features[11] < 51.201965f) {
                    if (features[0] < 0.811343f) {
                        return -0.044904f;
                    } else {
                        return -0.036568f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.085238f;
                    } else {
                        return -0.044378f;
                    }
                }
            }
        } else {
            if (features[9] < 50.309807f) {
                if (features[8] < 9.294910f) {
                    if (features[8] < -11.347665f) {
                        return 0.100215f;
                    } else {
                        return 0.146400f;
                    }
                } else {
                    return -0.035332f;
                }
            } else {
                if (features[0] < 0.669613f) {
                    if (features[11] < 49.034405f) {
                        return -0.042550f;
                    } else {
                        return -0.000259f;
                    }
                } else {
                    if (features[7] < 82.335472f) {
                        return 0.084420f;
                    } else {
                        return -0.023287f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_16(const float* features) {
        if (features[4] < 1.600707f) {
            if (features[9] < 82.335815f) {
                if (features[4] < 0.400000f) {
                    if (features[8] < -45.605885f) {
                        return 0.085650f;
                    } else {
                        return 0.054938f;
                    }
                } else {
                    if (features[4] < 0.400538f) {
                        return -0.036594f;
                    } else {
                        return 0.017444f;
                    }
                }
            } else {
                if (features[8] < -38.494102f) {
                    if (features[4] < 0.400000f) {
                        return 0.079041f;
                    } else {
                        return 0.057351f;
                    }
                } else {
                    if (features[4] < 0.349933f) {
                        return 0.062534f;
                    } else {
                        return 0.038474f;
                    }
                }
            }
        } else {
            if (features[9] < 93.905449f) {
                if (features[8] < -38.727856f) {
                    if (features[4] < 3.900546f) {
                        return -0.039523f;
                    } else {
                        return 0.000660f;
                    }
                } else {
                    if (features[8] < -30.668053f) {
                        return -0.042175f;
                    } else {
                        return -0.051997f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.927128f) {
                        return 0.004865f;
                    } else {
                        return -0.040939f;
                    }
                } else {
                    if (features[8] < -33.079437f) {
                        return 0.040504f;
                    } else {
                        return -0.023342f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_17(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.476928f) {
                    if (features[0] < 0.220000f) {
                        return -0.034291f;
                    } else {
                        return -0.012827f;
                    }
                } else {
                    if (features[0] < 0.592166f) {
                        return 0.015787f;
                    } else {
                        return 0.042069f;
                    }
                }
            } else {
                if (features[0] < 0.681520f) {
                    if (features[9] < 49.106506f) {
                        return 0.008207f;
                    } else {
                        return 0.069651f;
                    }
                } else {
                    if (features[8] < -31.500172f) {
                        return 0.043166f;
                    } else {
                        return -0.031630f;
                    }
                }
            }
        } else {
            if (features[8] < -31.245762f) {
                if (features[4] < 8.450968f) {
                    if (features[8] < -38.221569f) {
                        return -0.019921f;
                    } else {
                        return -0.036705f;
                    }
                } else {
                    if (features[4] < 12.867560f) {
                        return 0.020244f;
                    } else {
                        return -0.045702f;
                    }
                }
            } else {
                if (features[7] < 77.685852f) {
                    if (features[0] < 0.418023f) {
                        return -0.019342f;
                    } else {
                        return -0.050609f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.040639f;
                    } else {
                        return 0.011041f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_18(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[8] < -30.046419f) {
                if (features[9] < 46.499054f) {
                    if (features[11] < -26.387800f) {
                        return -0.033097f;
                    } else {
                        return 0.024622f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.038192f;
                    } else {
                        return -0.047332f;
                    }
                }
            } else {
                if (features[9] < 94.355614f) {
                    if (features[8] < -8.364439f) {
                        return 0.023991f;
                    } else {
                        return -0.040107f;
                    }
                } else {
                    if (features[12] < -0.807765f) {
                        return 0.019814f;
                    } else {
                        return -0.035332f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -35.359493f) {
                    if (features[0] < 0.821098f) {
                        return -0.014150f;
                    } else {
                        return 0.044967f;
                    }
                } else {
                    if (features[9] < 95.357391f) {
                        return 0.078312f;
                    } else {
                        return 0.034058f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[7] < 58.294384f) {
                        return -0.048841f;
                    } else {
                        return 0.023274f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.047084f;
                    } else {
                        return 0.046216f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_19(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[12] < -30.397575f) {
                if (features[8] < -37.965397f) {
                    return -0.043650f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.168905f;
                    } else {
                        return -0.041487f;
                    }
                }
            } else {
                if (features[9] < 21.241404f) {
                    if (features[12] < 1.778070f) {
                        return 0.105978f;
                    } else {
                        return -0.027508f;
                    }
                } else {
                    if (features[4] < 11.099153f) {
                        return -0.043643f;
                    } else {
                        return -0.000060f;
                    }
                }
            }
        } else {
            if (features[9] < 57.058514f) {
                if (features[12] < 10.241736f) {
                    if (features[9] < 41.545544f) {
                        return 0.129782f;
                    } else {
                        return 0.095235f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return 0.024707f;
                    } else {
                        return 0.134463f;
                    }
                }
            } else {
                if (features[4] < 8.649189f) {
                    if (features[4] < 7.097217f) {
                        return -0.041527f;
                    } else {
                        return 0.013976f;
                    }
                } else {
                    if (features[8] < 0.503690f) {
                        return 0.127929f;
                    } else {
                        return -0.024288f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_20(const float* features) {
        if (features[4] < 1.670599f) {
            if (features[0] < 0.596163f) {
                if (features[9] < 81.496719f) {
                    if (features[4] < 0.400000f) {
                        return 0.066983f;
                    } else {
                        return 0.013778f;
                    }
                } else {
                    if (features[8] < -36.365192f) {
                        return 0.062132f;
                    } else {
                        return 0.043385f;
                    }
                }
            } else {
                if (features[4] < 0.683138f) {
                    if (features[8] < -37.156734f) {
                        return 0.029318f;
                    } else {
                        return -0.014888f;
                    }
                } else {
                    if (features[0] < 0.628219f) {
                        return -0.001759f;
                    } else {
                        return -0.036115f;
                    }
                }
            }
        } else {
            if (features[0] < 0.474017f) {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.974356f) {
                        return 0.005626f;
                    } else {
                        return -0.036905f;
                    }
                } else {
                    if (features[0] < 0.379932f) {
                        return 0.069342f;
                    } else {
                        return 0.017065f;
                    }
                }
            } else {
                if (features[9] < 113.426125f) {
                    if (features[8] < -38.727856f) {
                        return -0.036304f;
                    } else {
                        return -0.051357f;
                    }
                } else {
                    if (features[4] < 3.764467f) {
                        return -0.038795f;
                    } else {
                        return -0.006405f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_21(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.476928f) {
                    if (features[0] < 0.220000f) {
                        return -0.033379f;
                    } else {
                        return -0.011960f;
                    }
                } else {
                    if (features[0] < 0.602645f) {
                        return 0.015179f;
                    } else {
                        return 0.041027f;
                    }
                }
            } else {
                if (features[0] < 0.731283f) {
                    if (features[8] < -28.760742f) {
                        return 0.066403f;
                    } else {
                        return 0.028597f;
                    }
                } else {
                    if (features[8] < -32.200939f) {
                        return 0.031319f;
                    } else {
                        return -0.032559f;
                    }
                }
            }
        } else {
            if (features[8] < -31.245762f) {
                if (features[4] < 8.812652f) {
                    if (features[8] < -38.221569f) {
                        return -0.018830f;
                    } else {
                        return -0.035959f;
                    }
                } else {
                    if (features[4] < 12.867560f) {
                        return 0.024119f;
                    } else {
                        return -0.045625f;
                    }
                }
            } else {
                if (features[9] < 95.902306f) {
                    if (features[9] < 69.853561f) {
                        return -0.050183f;
                    } else {
                        return -0.040201f;
                    }
                } else {
                    if (features[4] < 9.028560f) {
                        return -0.033270f;
                    } else {
                        return 0.022962f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_22(const float* features) {
        if (features[4] < 3.235201f) {
            if (features[8] < -31.954910f) {
                if (features[9] < 59.967148f) {
                    if (features[4] < 1.354129f) {
                        return -0.030600f;
                    } else {
                        return 0.021198f;
                    }
                } else {
                    if (features[4] < 1.734174f) {
                        return -0.044005f;
                    } else {
                        return -0.028832f;
                    }
                }
            } else {
                if (features[9] < 92.629234f) {
                    if (features[8] < -8.364439f) {
                        return 0.037241f;
                    } else {
                        return -0.038445f;
                    }
                } else {
                    if (features[4] < 1.786625f) {
                        return -0.032464f;
                    } else {
                        return -0.003295f;
                    }
                }
            }
        } else {
            if (features[8] < -11.347665f) {
                if (features[8] < -37.742649f) {
                    if (features[9] < 86.727104f) {
                        return 0.032901f;
                    } else {
                        return -0.023863f;
                    }
                } else {
                    if (features[4] < 8.300533f) {
                        return 0.080801f;
                    } else {
                        return 0.033230f;
                    }
                }
            } else {
                if (features[12] < 13.077276f) {
                    if (features[9] < 42.247967f) {
                        return -0.048056f;
                    } else {
                        return -0.021107f;
                    }
                } else {
                    if (features[11] < -55.646774f) {
                        return -0.046105f;
                    } else {
                        return 0.056070f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_23(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 49.034405f) {
                    if (features[0] < 0.844169f) {
                        return -0.041134f;
                    } else {
                        return 0.029917f;
                    }
                } else {
                    if (features[7] < 76.587669f) {
                        return 0.150912f;
                    } else {
                        return -0.037356f;
                    }
                }
            } else {
                if (features[9] < 32.271271f) {
                    if (features[4] < 8.192201f) {
                        return -0.002654f;
                    } else {
                        return 0.115501f;
                    }
                } else {
                    if (features[4] < 11.099153f) {
                        return -0.043708f;
                    } else {
                        return -0.002466f;
                    }
                }
            }
        } else {
            if (features[9] < 50.309807f) {
                if (features[12] < 11.653634f) {
                    if (features[9] < 37.734699f) {
                        return 0.115416f;
                    } else {
                        return 0.086914f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return 0.022244f;
                    } else {
                        return 0.111859f;
                    }
                }
            } else {
                if (features[4] < 7.097217f) {
                    if (features[12] < 7.045576f) {
                        return -0.013520f;
                    } else {
                        return -0.044032f;
                    }
                } else {
                    if (features[12] < 9.132126f) {
                        return 0.113808f;
                    } else {
                        return -0.004879f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_24(const float* features) {
        if (features[4] < 1.600707f) {
            if (features[0] < 0.592166f) {
                if (features[9] < 51.497909f) {
                    if (features[11] < -30.040165f) {
                        return 0.038002f;
                    } else {
                        return -0.028508f;
                    }
                } else {
                    if (features[4] < 0.400000f) {
                        return 0.067095f;
                    } else {
                        return 0.043198f;
                    }
                }
            } else {
                if (features[7] < 81.398003f) {
                    if (features[8] < -43.954227f) {
                        return -0.003397f;
                    } else {
                        return -0.037985f;
                    }
                } else {
                    if (features[0] < 0.716383f) {
                        return 0.008968f;
                    } else {
                        return -0.022284f;
                    }
                }
            }
        } else {
            if (features[0] < 0.462088f) {
                if (features[4] < 3.712480f) {
                    if (features[4] < 1.927128f) {
                        return 0.016876f;
                    } else {
                        return -0.036359f;
                    }
                } else {
                    if (features[0] < 0.392228f) {
                        return 0.064964f;
                    } else {
                        return 0.017869f;
                    }
                }
            } else {
                if (features[8] < -37.889999f) {
                    if (features[4] < 3.654021f) {
                        return -0.041649f;
                    } else {
                        return -0.010049f;
                    }
                } else {
                    if (features[0] < 0.565911f) {
                        return -0.035393f;
                    } else {
                        return -0.050846f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_25(const float* features) {
        if (features[9] < 45.711044f) {
            if (features[8] < -25.790308f) {
                if (features[0] < 0.494693f) {
                    if (features[0] < 0.246910f) {
                        return -0.011529f;
                    } else {
                        return 0.022537f;
                    }
                } else {
                    if (features[12] < 4.413506f) {
                        return -0.040269f;
                    } else {
                        return -0.004783f;
                    }
                }
            } else {
                if (features[12] < 12.347901f) {
                    return -0.049575f;
                } else {
                    if (features[0] < 0.606666f) {
                        return 0.013255f;
                    } else {
                        return -0.042287f;
                    }
                }
            }
        } else {
            if (features[0] < 0.885088f) {
                if (features[0] < 0.355664f) {
                    if (features[8] < -44.673698f) {
                        return -0.017570f;
                    } else {
                        return 0.003805f;
                    }
                } else {
                    if (features[8] < -28.226032f) {
                        return 0.025078f;
                    } else {
                        return -0.005317f;
                    }
                }
            } else {
                if (features[9] < 94.355614f) {
                    if (features[8] < -40.219589f) {
                        return -0.008423f;
                    } else {
                        return -0.041731f;
                    }
                } else {
                    if (features[10] < -20.156591f) {
                        return 0.056344f;
                    } else {
                        return -0.010782f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_26(const float* features) {
        if (features[4] < 3.421923f) {
            if (features[8] < -31.500172f) {
                if (features[9] < 59.967148f) {
                    if (features[4] < 1.411447f) {
                        return -0.024744f;
                    } else {
                        return 0.022357f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.029677f;
                    } else {
                        return -0.043978f;
                    }
                }
            } else {
                if (features[9] < 98.072708f) {
                    if (features[8] < -8.364439f) {
                        return 0.036806f;
                    } else {
                        return -0.033256f;
                    }
                } else {
                    if (features[4] < 1.506792f) {
                        return -0.034134f;
                    } else {
                        return -0.003125f;
                    }
                }
            }
        } else {
            if (features[8] < -12.451389f) {
                if (features[8] < -34.793274f) {
                    if (features[9] < 89.328476f) {
                        return 0.043834f;
                    } else {
                        return -0.015307f;
                    }
                } else {
                    if (features[4] < 8.300533f) {
                        return 0.079493f;
                    } else {
                        return 0.035584f;
                    }
                }
            } else {
                if (features[12] < 10.562995f) {
                    if (features[9] < 42.247967f) {
                        return -0.047465f;
                    } else {
                        return -0.005242f;
                    }
                } else {
                    if (features[4] < 7.331466f) {
                        return 0.053059f;
                    } else {
                        return -0.033747f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_27(const float* features) {
        if (features[9] < 33.471188f) {
            if (features[9] < 25.116167f) {
                if (features[12] < 11.994812f) {
                    if (features[11] < -39.977287f) {
                        return 0.069960f;
                    } else {
                        return 0.103529f;
                    }
                } else {
                    if (features[0] < 0.609552f) {
                        return -0.025138f;
                    } else {
                        return 0.092048f;
                    }
                }
            } else {
                if (features[10] < -34.938953f) {
                    if (features[11] < 8.383734f) {
                        return -0.030452f;
                    } else {
                        return 0.082773f;
                    }
                } else {
                    if (features[11] < -51.437321f) {
                        return -0.028872f;
                    } else {
                        return 0.102861f;
                    }
                }
            }
        } else {
            if (features[4] < 9.305356f) {
                if (features[10] < -5.939061f) {
                    if (features[12] < -30.397575f) {
                        return 0.002852f;
                    } else {
                        return -0.042293f;
                    }
                } else {
                    if (features[7] < 58.294384f) {
                        return 0.065203f;
                    } else {
                        return -0.033964f;
                    }
                }
            } else {
                if (features[9] < 85.425072f) {
                    if (features[10] < -27.566055f) {
                        return -0.024043f;
                    } else {
                        return 0.083595f;
                    }
                } else {
                    if (features[10] < -5.449071f) {
                        return -0.043959f;
                    } else {
                        return 0.054321f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_28(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[4] < 1.670599f) {
                if (features[9] < 50.876228f) {
                    if (features[4] < 0.400538f) {
                        return -0.035901f;
                    } else {
                        return 0.032450f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.065455f;
                    } else {
                        return 0.041882f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.867067f) {
                        return 0.012931f;
                    } else {
                        return -0.036123f;
                    }
                } else {
                    if (features[9] < 73.650993f) {
                        return -0.008919f;
                    } else {
                        return 0.051131f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[0] < 0.628219f) {
                    if (features[8] < -38.494102f) {
                        return 0.042816f;
                    } else {
                        return 0.004970f;
                    }
                } else {
                    if (features[4] < 0.683138f) {
                        return 0.004406f;
                    } else {
                        return -0.030602f;
                    }
                }
            } else {
                if (features[8] < -38.093536f) {
                    if (features[4] < 3.654021f) {
                        return -0.038978f;
                    } else {
                        return -0.015398f;
                    }
                } else {
                    if (features[9] < 129.727692f) {
                        return -0.049864f;
                    } else {
                        return -0.029376f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_29(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.600707f) {
                if (features[0] < 0.510783f) {
                    if (features[0] < 0.220000f) {
                        return -0.030981f;
                    } else {
                        return -0.008621f;
                    }
                } else {
                    if (features[0] < 0.950064f) {
                        return 0.033075f;
                    } else {
                        return -0.011064f;
                    }
                }
            } else {
                if (features[0] < 0.739753f) {
                    if (features[8] < -27.366392f) {
                        return 0.059735f;
                    } else {
                        return 0.022837f;
                    }
                } else {
                    if (features[8] < -30.046419f) {
                        return 0.023555f;
                    } else {
                        return -0.035463f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[9] < 88.734299f) {
                        return -0.035920f;
                    } else {
                        return -0.018724f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.024720f;
                    } else {
                        return -0.046116f;
                    }
                }
            } else {
                if (features[7] < 94.130890f) {
                    if (features[11] < -97.100410f) {
                        return 0.013688f;
                    } else {
                        return -0.047964f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.036588f;
                    } else {
                        return 0.020988f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_30(const float* features) {
        if (features[0] < 0.510783f) {
            if (features[9] < 66.463921f) {
                if (features[0] < 0.444404f) {
                    if (features[0] < 0.220345f) {
                        return 0.000036f;
                    } else {
                        return -0.036088f;
                    }
                } else {
                    if (features[10] < -32.693859f) {
                        return 0.000834f;
                    } else {
                        return 0.041962f;
                    }
                }
            } else {
                if (features[9] < 98.072708f) {
                    if (features[10] < -20.156591f) {
                        return -0.038905f;
                    } else {
                        return 0.002291f;
                    }
                } else {
                    if (features[0] < 0.456542f) {
                        return -0.045275f;
                    } else {
                        return -0.035513f;
                    }
                }
            }
        } else {
            if (features[9] < 26.425684f) {
                if (features[11] < -27.850300f) {
                    if (features[9] < 15.668049f) {
                        return -0.040481f;
                    } else {
                        return 0.034681f;
                    }
                } else {
                    if (features[0] < 0.526172f) {
                        return 0.038947f;
                    } else {
                        return -0.044716f;
                    }
                }
            } else {
                if (features[9] < 82.776611f) {
                    if (features[10] < -7.859140f) {
                        return 0.055230f;
                    } else {
                        return -0.019506f;
                    }
                } else {
                    if (features[0] < 0.720622f) {
                        return -0.009919f;
                    } else {
                        return 0.035860f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_31(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[12] < -30.397575f) {
                if (features[0] < 0.650629f) {
                    if (features[5] < 24.768200f) {
                        return 0.012369f;
                    } else {
                        return -0.040538f;
                    }
                } else {
                    if (features[10] < -27.415358f) {
                        return -0.036840f;
                    } else {
                        return 0.117064f;
                    }
                }
            } else {
                if (features[4] < 11.305647f) {
                    if (features[8] < -17.408821f) {
                        return -0.042977f;
                    } else {
                        return -0.013874f;
                    }
                } else {
                    if (features[7] < 36.311123f) {
                        return 0.081337f;
                    } else {
                        return -0.017025f;
                    }
                }
            }
        } else {
            if (features[7] < 58.294384f) {
                if (features[12] < 10.241736f) {
                    if (features[8] < 9.294910f) {
                        return 0.094253f;
                    } else {
                        return -0.031646f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return 0.010860f;
                    } else {
                        return 0.099216f;
                    }
                }
            } else {
                if (features[4] < 8.649189f) {
                    if (features[7] < 78.622673f) {
                        return -0.013296f;
                    } else {
                        return -0.043521f;
                    }
                } else {
                    if (features[12] < 16.149860f) {
                        return 0.096022f;
                    } else {
                        return -0.029467f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_32(const float* features) {
        if (features[4] < 1.670599f) {
            if (features[0] < 0.596163f) {
                if (features[9] < 80.604530f) {
                    if (features[4] < 0.400000f) {
                        return 0.056272f;
                    } else {
                        return 0.011226f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.062313f;
                    } else {
                        return 0.042739f;
                    }
                }
            } else {
                if (features[4] < 0.683138f) {
                    if (features[0] < 0.909618f) {
                        return 0.000315f;
                    } else {
                        return 0.073279f;
                    }
                } else {
                    if (features[9] < 115.276413f) {
                        return -0.033258f;
                    } else {
                        return 0.000563f;
                    }
                }
            }
        } else {
            if (features[0] < 0.462088f) {
                if (features[4] < 3.712480f) {
                    if (features[4] < 1.927128f) {
                        return 0.012283f;
                    } else {
                        return -0.035520f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return 0.058765f;
                    } else {
                        return 0.020304f;
                    }
                }
            } else {
                if (features[9] < 108.319771f) {
                    if (features[0] < 0.654357f) {
                        return -0.039460f;
                    } else {
                        return -0.049386f;
                    }
                } else {
                    if (features[0] < 0.596163f) {
                        return -0.000810f;
                    } else {
                        return -0.035222f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_33(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.565724f) {
                if (features[0] < 0.476928f) {
                    if (features[9] < 110.258118f) {
                        return -0.007585f;
                    } else {
                        return -0.023683f;
                    }
                } else {
                    if (features[0] < 0.560268f) {
                        return 0.011690f;
                    } else {
                        return 0.033147f;
                    }
                }
            } else {
                if (features[0] < 0.792771f) {
                    if (features[9] < 52.089478f) {
                        return -0.000130f;
                    } else {
                        return 0.051380f;
                    }
                } else {
                    if (features[8] < -42.325005f) {
                        return 0.060878f;
                    } else {
                        return -0.025053f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.192201f) {
                    if (features[8] < -38.221569f) {
                        return -0.018693f;
                    } else {
                        return -0.034820f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.014005f;
                    } else {
                        return -0.046098f;
                    }
                }
            } else {
                if (features[7] < 75.665001f) {
                    if (features[11] < -84.723663f) {
                        return -0.000155f;
                    } else {
                        return -0.047765f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.038982f;
                    } else {
                        return 0.014823f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_34(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[4] < 3.827744f) {
                if (features[4] < 0.400538f) {
                    if (features[4] < 0.400000f) {
                        return -0.047176f;
                    } else {
                        return 0.012582f;
                    }
                } else {
                    if (features[0] < 0.424671f) {
                        return -0.047124f;
                    } else {
                        return -0.035079f;
                    }
                }
            } else {
                if (features[0] < 0.398692f) {
                    if (features[0] < 0.370829f) {
                        return -0.045861f;
                    } else {
                        return -0.012980f;
                    }
                } else {
                    if (features[9] < 95.357391f) {
                        return 0.057673f;
                    } else {
                        return -0.013638f;
                    }
                }
            }
        } else {
            if (features[9] < 29.557575f) {
                if (features[4] < 2.010578f) {
                    if (features[10] < -28.177908f) {
                        return 0.075712f;
                    } else {
                        return -0.015846f;
                    }
                } else {
                    if (features[11] < -18.819571f) {
                        return -0.016979f;
                    } else {
                        return -0.044298f;
                    }
                }
            } else {
                if (features[4] < 3.421923f) {
                    if (features[9] < 63.809109f) {
                        return 0.046323f;
                    } else {
                        return -0.009234f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return 0.067652f;
                    } else {
                        return 0.011106f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_35(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 49.034405f) {
                    if (features[4] < 9.028560f) {
                        return -0.037997f;
                    } else {
                        return 0.049377f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.124657f;
                    } else {
                        return -0.036323f;
                    }
                }
            } else {
                if (features[9] < 34.864788f) {
                    if (features[4] < 8.192201f) {
                        return -0.014206f;
                    } else {
                        return 0.101240f;
                    }
                } else {
                    if (features[4] < 11.099153f) {
                        return -0.042973f;
                    } else {
                        return -0.010432f;
                    }
                }
            }
        } else {
            if (features[9] < 59.967148f) {
                if (features[12] < 10.241736f) {
                    if (features[8] < 9.294910f) {
                        return 0.087025f;
                    } else {
                        return -0.033117f;
                    }
                } else {
                    if (features[4] < 3.075931f) {
                        return -0.019499f;
                    } else {
                        return 0.066656f;
                    }
                }
            } else {
                if (features[4] < 8.649189f) {
                    if (features[4] < 7.097217f) {
                        return -0.039825f;
                    } else {
                        return 0.003448f;
                    }
                } else {
                    if (features[12] < 16.149860f) {
                        return 0.087431f;
                    } else {
                        return -0.030678f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_36(const float* features) {
        if (features[4] < 1.670599f) {
            if (features[9] < 82.335815f) {
                if (features[4] < 0.386141f) {
                    if (features[6] < 56.781601f) {
                        return -0.012890f;
                    } else {
                        return 0.049590f;
                    }
                } else {
                    if (features[4] < 0.420719f) {
                        return -0.035563f;
                    } else {
                        return 0.012253f;
                    }
                }
            } else {
                if (features[8] < -38.494102f) {
                    if (features[4] < 1.333764f) {
                        return 0.051030f;
                    } else {
                        return 0.023061f;
                    }
                } else {
                    if (features[4] < 0.349933f) {
                        return 0.047853f;
                    } else {
                        return 0.024664f;
                    }
                }
            }
        } else {
            if (features[8] < -33.079437f) {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.927128f) {
                        return -0.000545f;
                    } else {
                        return -0.040064f;
                    }
                } else {
                    if (features[9] < 86.727104f) {
                        return -0.019850f;
                    } else {
                        return 0.031258f;
                    }
                }
            } else {
                if (features[9] < 109.567810f) {
                    if (features[11] < -76.410004f) {
                        return -0.000294f;
                    } else {
                        return -0.047015f;
                    }
                } else {
                    if (features[4] < 3.563289f) {
                        return -0.041257f;
                    } else {
                        return -0.009399f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_37(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.427372f) {
                if (features[9] < 112.184113f) {
                    if (features[9] < 45.711044f) {
                        return -0.027647f;
                    } else {
                        return 0.006146f;
                    }
                } else {
                    if (features[8] < -39.060780f) {
                        return -0.019756f;
                    } else {
                        return -0.004223f;
                    }
                }
            } else {
                if (features[9] < 50.876228f) {
                    if (features[8] < -24.223234f) {
                        return -0.000166f;
                    } else {
                        return -0.038933f;
                    }
                } else {
                    if (features[8] < -28.914127f) {
                        return 0.046073f;
                    } else {
                        return 0.015372f;
                    }
                }
            }
        } else {
            if (features[8] < -30.668053f) {
                if (features[4] < 8.812652f) {
                    if (features[5] < 34.890099f) {
                        return -0.027453f;
                    } else {
                        return 0.009851f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.020733f;
                    } else {
                        return -0.043726f;
                    }
                }
            } else {
                if (features[7] < 91.934250f) {
                    if (features[8] < 9.294910f) {
                        return -0.046150f;
                    } else {
                        return 0.005200f;
                    }
                } else {
                    if (features[11] < 27.816441f) {
                        return -0.014806f;
                    } else {
                        return -0.045577f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_38(const float* features) {
        if (features[0] < 0.533426f) {
            if (features[8] < -30.046419f) {
                if (features[4] < 4.130574f) {
                    if (features[4] < 0.400538f) {
                        return -0.033869f;
                    } else {
                        return -0.045357f;
                    }
                } else {
                    if (features[0] < 0.408305f) {
                        return -0.043693f;
                    } else {
                        return 0.007388f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[4] < 0.400538f) {
                        return 0.014456f;
                    } else {
                        return -0.027666f;
                    }
                } else {
                    if (features[0] < 0.368169f) {
                        return -0.037698f;
                    } else {
                        return 0.068661f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -37.156734f) {
                    if (features[4] < 3.712480f) {
                        return -0.024313f;
                    } else {
                        return 0.034078f;
                    }
                } else {
                    if (features[4] < 1.138125f) {
                        return -0.018566f;
                    } else {
                        return 0.055383f;
                    }
                }
            } else {
                if (features[7] < 58.294384f) {
                    if (features[8] < 2.464921f) {
                        return -0.043358f;
                    } else {
                        return -0.007455f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return 0.048626f;
                    } else {
                        return -0.033614f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_39(const float* features) {
        if (features[8] < -14.335972f) {
            if (features[9] < 33.471188f) {
                if (features[8] < -18.989941f) {
                    if (features[11] < 8.005199f) {
                        return -0.034193f;
                    } else {
                        return 0.093651f;
                    }
                } else {
                    if (features[12] < 1.429055f) {
                        return 0.102826f;
                    } else {
                        return -0.017185f;
                    }
                }
            } else {
                if (features[12] < -30.397575f) {
                    if (features[11] < 45.744942f) {
                        return -0.037495f;
                    } else {
                        return 0.083322f;
                    }
                } else {
                    if (features[4] < 11.099153f) {
                        return -0.042809f;
                    } else {
                        return -0.007461f;
                    }
                }
            }
        } else {
            if (features[9] < 58.808765f) {
                if (features[12] < 10.241736f) {
                    if (features[8] < 9.294910f) {
                        return 0.081354f;
                    } else {
                        return -0.029822f;
                    }
                } else {
                    if (features[9] < 38.696392f) {
                        return 0.058327f;
                    } else {
                        return -0.022066f;
                    }
                }
            } else {
                if (features[0] < 0.962186f) {
                    if (features[12] < -0.516902f) {
                        return 0.056477f;
                    } else {
                        return -0.036112f;
                    }
                } else {
                    if (features[4] < 3.827744f) {
                        return -0.001595f;
                    } else {
                        return 0.090689f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_40(const float* features) {
        if (features[0] < 0.557457f) {
            if (features[4] < 1.670599f) {
                if (features[8] < -36.365192f) {
                    if (features[4] < 0.400000f) {
                        return 0.058567f;
                    } else {
                        return 0.041862f;
                    }
                } else {
                    if (features[9] < 69.853561f) {
                        return -0.008073f;
                    } else {
                        return 0.028919f;
                    }
                }
            } else {
                if (features[4] < 3.654021f) {
                    if (features[4] < 2.095944f) {
                        return -0.000649f;
                    } else {
                        return -0.038982f;
                    }
                } else {
                    if (features[0] < 0.424671f) {
                        return 0.046924f;
                    } else {
                        return -0.004143f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[8] < -46.397450f) {
                    if (features[0] < 0.602645f) {
                        return 0.060079f;
                    } else {
                        return 0.011094f;
                    }
                } else {
                    if (features[0] < 0.677156f) {
                        return -0.000062f;
                    } else {
                        return -0.029522f;
                    }
                }
            } else {
                if (features[9] < 114.050507f) {
                    if (features[8] < -38.221569f) {
                        return -0.035852f;
                    } else {
                        return -0.048026f;
                    }
                } else {
                    if (features[8] < -36.131538f) {
                        return -0.009818f;
                    } else {
                        return -0.039632f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_41(const float* features) {
        if (features[9] < 45.711044f) {
            if (features[0] < 0.609552f) {
                if (features[11] < -53.396942f) {
                    if (features[6] < 83.489502f) {
                        return 0.056527f;
                    } else {
                        return -0.022226f;
                    }
                } else {
                    if (features[8] < -31.500172f) {
                        return 0.008566f;
                    } else {
                        return -0.033352f;
                    }
                }
            } else {
                if (features[8] < -31.245762f) {
                    if (features[6] < 86.127098f) {
                        return -0.040536f;
                    } else {
                        return -0.001920f;
                    }
                } else {
                    if (features[7] < 42.485451f) {
                        return -0.046067f;
                    } else {
                        return -0.001895f;
                    }
                }
            }
        } else {
            if (features[0] < 0.826246f) {
                if (features[0] < 0.364617f) {
                    if (features[8] < -44.673698f) {
                        return -0.013861f;
                    } else {
                        return 0.005110f;
                    }
                } else {
                    if (features[8] < -27.366392f) {
                        return 0.021404f;
                    } else {
                        return -0.002887f;
                    }
                }
            } else {
                if (features[8] < -39.060780f) {
                    if (features[0] < 0.950064f) {
                        return 0.044573f;
                    } else {
                        return -0.005814f;
                    }
                } else {
                    if (features[9] < 90.172180f) {
                        return -0.039528f;
                    } else {
                        return -0.006349f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_42(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[8] < -30.203865f) {
                if (features[9] < 44.778130f) {
                    if (features[11] < -13.162652f) {
                        return -0.019032f;
                    } else {
                        return 0.055264f;
                    }
                } else {
                    if (features[4] < 3.827744f) {
                        return -0.042395f;
                    } else {
                        return -0.025517f;
                    }
                }
            } else {
                if (features[4] < 4.045522f) {
                    if (features[4] < 0.400538f) {
                        return 0.010981f;
                    } else {
                        return -0.032657f;
                    }
                } else {
                    if (features[0] < 0.368169f) {
                        return -0.040694f;
                    } else {
                        return 0.069490f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[4] < 3.153043f) {
                    if (features[8] < -29.210335f) {
                        return -0.014893f;
                    } else {
                        return 0.043808f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return 0.058962f;
                    } else {
                        return 0.010408f;
                    }
                }
            } else {
                if (features[12] < 11.254656f) {
                    if (features[7] < 58.294384f) {
                        return -0.045716f;
                    } else {
                        return 0.015632f;
                    }
                } else {
                    if (features[4] < 8.450968f) {
                        return 0.045787f;
                    } else {
                        return -0.042079f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_43(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 51.201965f) {
                    if (features[4] < 9.522261f) {
                        return -0.037341f;
                    } else {
                        return 0.055921f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.108281f;
                    } else {
                        return -0.036661f;
                    }
                }
            } else {
                if (features[4] < 11.099153f) {
                    if (features[9] < 32.271271f) {
                        return 0.004159f;
                    } else {
                        return -0.042363f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return 0.084411f;
                    } else {
                        return -0.014592f;
                    }
                }
            }
        } else {
            if (features[9] < 50.309807f) {
                if (features[12] < 11.254656f) {
                    if (features[8] < 9.294910f) {
                        return 0.076835f;
                    } else {
                        return -0.026513f;
                    }
                } else {
                    if (features[4] < 7.250103f) {
                        return 0.012173f;
                    } else {
                        return 0.075340f;
                    }
                }
            } else {
                if (features[4] < 7.097217f) {
                    if (features[12] < 7.045576f) {
                        return -0.012908f;
                    } else {
                        return -0.043089f;
                    }
                } else {
                    if (features[12] < 9.132126f) {
                        return 0.081497f;
                    } else {
                        return -0.005059f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_44(const float* features) {
        if (features[0] < 0.513516f) {
            if (features[4] < 1.754536f) {
                if (features[9] < 87.941666f) {
                    if (features[8] < -35.250809f) {
                        return 0.032300f;
                    } else {
                        return 0.002384f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.056328f;
                    } else {
                        return 0.039214f;
                    }
                }
            } else {
                if (features[4] < 3.712480f) {
                    if (features[4] < 1.867067f) {
                        return 0.014704f;
                    } else {
                        return -0.033497f;
                    }
                } else {
                    if (features[0] < 0.408305f) {
                        return 0.049313f;
                    } else {
                        return 0.005302f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[0] < 0.602645f) {
                    if (features[8] < -46.880394f) {
                        return 0.055455f;
                    } else {
                        return 0.009606f;
                    }
                } else {
                    if (features[4] < 0.149881f) {
                        return 0.029417f;
                    } else {
                        return -0.018657f;
                    }
                }
            } else {
                if (features[9] < 114.660995f) {
                    if (features[8] < -38.221569f) {
                        return -0.033299f;
                    } else {
                        return -0.046825f;
                    }
                } else {
                    if (features[0] < 0.628219f) {
                        return -0.004833f;
                    } else {
                        return -0.032236f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_45(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.867067f) {
                if (features[0] < 0.441691f) {
                    if (features[4] < 0.223583f) {
                        return -0.034569f;
                    } else {
                        return -0.008583f;
                    }
                } else {
                    if (features[0] < 0.869055f) {
                        return 0.023788f;
                    } else {
                        return -0.006970f;
                    }
                }
            } else {
                if (features[0] < 0.779673f) {
                    if (features[8] < -28.226032f) {
                        return 0.053471f;
                    } else {
                        return 0.013592f;
                    }
                } else {
                    if (features[8] < -38.221569f) {
                        return 0.038752f;
                    } else {
                        return -0.024349f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[7] < 76.587669f) {
                        return -0.032692f;
                    } else {
                        return -0.017735f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.022431f;
                    } else {
                        return -0.044274f;
                    }
                }
            } else {
                if (features[7] < 75.665001f) {
                    if (features[11] < -84.723663f) {
                        return -0.001571f;
                    } else {
                        return -0.045488f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.038850f;
                    } else {
                        return 0.000338f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_46(const float* features) {
        if (features[4] < 3.192151f) {
            if (features[8] < -31.500172f) {
                if (features[9] < 59.967148f) {
                    if (features[4] < 1.411447f) {
                        return -0.023829f;
                    } else {
                        return 0.023706f;
                    }
                } else {
                    if (features[8] < -38.727856f) {
                        return -0.041914f;
                    } else {
                        return -0.028829f;
                    }
                }
            } else {
                if (features[9] < 78.590889f) {
                    if (features[8] < -8.364439f) {
                        return 0.035377f;
                    } else {
                        return -0.033977f;
                    }
                } else {
                    if (features[8] < -25.607260f) {
                        return -0.024343f;
                    } else {
                        return 0.005099f;
                    }
                }
            }
        } else {
            if (features[8] < -14.335972f) {
                if (features[8] < -34.793274f) {
                    if (features[9] < 100.804039f) {
                        return 0.023792f;
                    } else {
                        return -0.025999f;
                    }
                } else {
                    if (features[9] < 150.050537f) {
                        return 0.057750f;
                    } else {
                        return -0.003323f;
                    }
                }
            } else {
                if (features[9] < 36.799816f) {
                    if (features[8] < 9.294910f) {
                        return -0.043158f;
                    } else {
                        return 0.059428f;
                    }
                } else {
                    if (features[4] < 7.969834f) {
                        return 0.031182f;
                    } else {
                        return -0.026792f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_47(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[4] < 9.028560f) {
                if (features[9] < 29.557575f) {
                    if (features[0] < 0.758140f) {
                        return -0.029589f;
                    } else {
                        return 0.042960f;
                    }
                } else {
                    if (features[11] < 51.201965f) {
                        return -0.042136f;
                    } else {
                        return -0.024500f;
                    }
                }
            } else {
                if (features[9] < 40.606697f) {
                    if (features[6] < 69.872597f) {
                        return -0.030831f;
                    } else {
                        return 0.094703f;
                    }
                } else {
                    if (features[11] < 45.744942f) {
                        return -0.029241f;
                    } else {
                        return 0.066379f;
                    }
                }
            }
        } else {
            if (features[9] < 59.967148f) {
                if (features[8] < 9.294910f) {
                    if (features[9] < 39.707916f) {
                        return 0.071481f;
                    } else {
                        return 0.046024f;
                    }
                } else {
                    return -0.038956f;
                }
            } else {
                if (features[4] < 8.649189f) {
                    if (features[0] < 0.962186f) {
                        return -0.039245f;
                    } else {
                        return 0.020154f;
                    }
                } else {
                    if (features[0] < 0.563239f) {
                        return -0.029516f;
                    } else {
                        return 0.062813f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_48(const float* features) {
        if (features[4] < 1.600707f) {
            if (features[9] < 83.208870f) {
                if (features[4] < 0.400000f) {
                    if (features[4] < 0.149881f) {
                        return 0.056421f;
                    } else {
                        return 0.030811f;
                    }
                } else {
                    if (features[4] < 0.415711f) {
                        return -0.038935f;
                    } else {
                        return 0.012783f;
                    }
                }
            } else {
                if (features[8] < -38.494102f) {
                    if (features[4] < 0.400000f) {
                        return 0.053899f;
                    } else {
                        return 0.037938f;
                    }
                } else {
                    if (features[4] < 0.349933f) {
                        return 0.041252f;
                    } else {
                        return 0.020844f;
                    }
                }
            }
        } else {
            if (features[9] < 93.905449f) {
                if (features[8] < -40.648365f) {
                    if (features[4] < 3.385558f) {
                        return -0.030290f;
                    } else {
                        return 0.003218f;
                    }
                } else {
                    if (features[12] < 11.653634f) {
                        return -0.043198f;
                    } else {
                        return -0.026613f;
                    }
                }
            } else {
                if (features[4] < 3.764467f) {
                    if (features[4] < 1.927128f) {
                        return 0.003584f;
                    } else {
                        return -0.032954f;
                    }
                } else {
                    if (features[8] < -33.079437f) {
                        return 0.030540f;
                    } else {
                        return -0.017178f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_49(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.486399f) {
                if (features[0] < 0.476928f) {
                    if (features[4] < 0.246010f) {
                        return -0.028999f;
                    } else {
                        return -0.008797f;
                    }
                } else {
                    if (features[0] < 0.602645f) {
                        return 0.010383f;
                    } else {
                        return 0.032451f;
                    }
                }
            } else {
                if (features[0] < 0.826246f) {
                    if (features[9] < 43.121307f) {
                        return -0.014252f;
                    } else {
                        return 0.039417f;
                    }
                } else {
                    if (features[8] < -39.311249f) {
                        return 0.033565f;
                    } else {
                        return -0.031187f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[8] < -38.221569f) {
                        return -0.014541f;
                    } else {
                        return -0.031683f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.019876f;
                    } else {
                        return -0.043628f;
                    }
                }
            } else {
                if (features[7] < 75.665001f) {
                    if (features[11] < -84.723663f) {
                        return -0.000911f;
                    } else {
                        return -0.045334f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.034230f;
                    } else {
                        return 0.006666f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_50(const float* features) {
        if (features[4] < 1.786625f) {
            if (features[8] < -28.914127f) {
                if (features[7] < 70.346886f) {
                    if (features[8] < -40.219589f) {
                        return -0.038077f;
                    } else {
                        return -0.009539f;
                    }
                } else {
                    if (features[8] < -38.093536f) {
                        return -0.044088f;
                    } else {
                        return -0.034701f;
                    }
                }
            } else {
                if (features[10] < -19.302191f) {
                    if (features[12] < 4.413506f) {
                        return 0.046381f;
                    } else {
                        return -0.001103f;
                    }
                } else {
                    if (features[4] < 0.400000f) {
                        return -0.043768f;
                    } else {
                        return -0.004307f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -34.793274f) {
                    if (features[7] < 76.980568f) {
                        return 0.012352f;
                    } else {
                        return -0.028277f;
                    }
                } else {
                    if (features[4] < 3.654021f) {
                        return 0.023009f;
                    } else {
                        return 0.051306f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[7] < 58.294384f) {
                        return -0.044342f;
                    } else {
                        return 0.002810f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.045767f;
                    } else {
                        return 0.028279f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_51(const float* features) {
        if (features[8] < -16.819752f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 40.793491f) {
                    return -0.041895f;
                } else {
                    if (features[7] < 76.587669f) {
                        return 0.097713f;
                    } else {
                        return -0.037319f;
                    }
                }
            } else {
                if (features[4] < 11.099153f) {
                    if (features[8] < -19.934113f) {
                        return -0.041989f;
                    } else {
                        return -0.024117f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.025047f;
                    } else {
                        return -0.038893f;
                    }
                }
            }
        } else {
            if (features[7] < 49.898972f) {
                if (features[12] < 10.241736f) {
                    if (features[8] < 9.294910f) {
                        return 0.068904f;
                    } else {
                        return -0.025873f;
                    }
                } else {
                    if (features[4] < 3.004038f) {
                        return -0.024848f;
                    } else {
                        return 0.051272f;
                    }
                }
            } else {
                if (features[4] < 7.172990f) {
                    if (features[12] < 7.045576f) {
                        return -0.018148f;
                    } else {
                        return -0.042721f;
                    }
                } else {
                    if (features[0] < 0.599232f) {
                        return -0.034051f;
                    } else {
                        return 0.064555f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_52(const float* features) {
        if (features[0] < 0.554127f) {
            if (features[4] < 1.506792f) {
                if (features[8] < -36.020836f) {
                    if (features[4] < 0.312337f) {
                        return 0.053390f;
                    } else {
                        return 0.035398f;
                    }
                } else {
                    if (features[0] < 0.220345f) {
                        return -0.001968f;
                    } else {
                        return 0.029787f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[4] < 1.927128f) {
                        return 0.011392f;
                    } else {
                        return -0.032105f;
                    }
                } else {
                    if (features[0] < 0.398692f) {
                        return 0.050652f;
                    } else {
                        return 0.003021f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[0] < 0.619183f) {
                    if (features[6] < 79.263603f) {
                        return -0.008233f;
                    } else {
                        return 0.034641f;
                    }
                } else {
                    if (features[8] < -45.201443f) {
                        return 0.009072f;
                    } else {
                        return -0.025030f;
                    }
                }
            } else {
                if (features[8] < -38.891602f) {
                    if (features[0] < 0.650629f) {
                        return -0.007915f;
                    } else {
                        return -0.035872f;
                    }
                } else {
                    if (features[7] < 133.129364f) {
                        return -0.045769f;
                    } else {
                        return -0.027472f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_53(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.486399f) {
                if (features[0] < 0.507954f) {
                    if (features[0] < 0.220000f) {
                        return -0.025957f;
                    } else {
                        return -0.006941f;
                    }
                } else {
                    if (features[0] < 0.950064f) {
                        return 0.029088f;
                    } else {
                        return -0.009292f;
                    }
                }
            } else {
                if (features[0] < 0.681520f) {
                    if (features[4] < 1.895638f) {
                        return 0.022527f;
                    } else {
                        return 0.046126f;
                    }
                } else {
                    if (features[8] < -34.941708f) {
                        return 0.030872f;
                    } else {
                        return -0.022932f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[7] < 84.948257f) {
                        return -0.030093f;
                    } else {
                        return -0.010648f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.016479f;
                    } else {
                        return -0.042683f;
                    }
                }
            } else {
                if (features[7] < 94.130890f) {
                    if (features[11] < -84.723663f) {
                        return 0.004446f;
                    } else {
                        return -0.043868f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.031475f;
                    } else {
                        return 0.009760f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_54(const float* features) {
        if (features[0] < 0.563239f) {
            if (features[8] < -31.652088f) {
                if (features[4] < 3.963336f) {
                    if (features[4] < 0.400538f) {
                        return -0.032997f;
                    } else {
                        return -0.043163f;
                    }
                } else {
                    if (features[0] < 0.421617f) {
                        return -0.039542f;
                    } else {
                        return 0.006370f;
                    }
                }
            } else {
                if (features[4] < 3.457900f) {
                    if (features[4] < 0.400538f) {
                        return 0.012774f;
                    } else {
                        return -0.026381f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return -0.045313f;
                    } else {
                        return 0.047975f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -38.221569f) {
                    if (features[4] < 3.421923f) {
                        return -0.025501f;
                    } else {
                        return 0.024309f;
                    }
                } else {
                    if (features[4] < 1.138125f) {
                        return -0.014803f;
                    } else {
                        return 0.045545f;
                    }
                }
            } else {
                if (features[12] < 11.254656f) {
                    if (features[7] < 57.726425f) {
                        return -0.044200f;
                    } else {
                        return 0.016108f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return 0.031539f;
                    } else {
                        return -0.029095f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_55(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -30.397575f) {
                if (features[0] < 0.673074f) {
                    if (features[11] < 58.311615f) {
                        return -0.041436f;
                    } else {
                        return 0.009195f;
                    }
                } else {
                    if (features[8] < -38.615391f) {
                        return -0.036188f;
                    } else {
                        return 0.088298f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[9] < 27.835165f) {
                        return -0.005902f;
                    } else {
                        return -0.041942f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return 0.053768f;
                    } else {
                        return -0.026512f;
                    }
                }
            }
        } else {
            if (features[9] < 52.675392f) {
                if (features[12] < 10.241736f) {
                    if (features[8] < 9.294910f) {
                        return 0.065783f;
                    } else {
                        return -0.029504f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return 0.001526f;
                    } else {
                        return 0.062213f;
                    }
                }
            } else {
                if (features[4] < 8.649189f) {
                    if (features[0] < 0.712718f) {
                        return -0.040656f;
                    } else {
                        return -0.015797f;
                    }
                } else {
                    if (features[7] < 88.575722f) {
                        return 0.058941f;
                    } else {
                        return -0.035756f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_56(const float* features) {
        if (features[0] < 0.557457f) {
            if (features[4] < 1.670599f) {
                if (features[0] < 0.220000f) {
                    if (features[6] < 65.251701f) {
                        return 0.036937f;
                    } else {
                        return 0.052055f;
                    }
                } else {
                    if (features[0] < 0.220345f) {
                        return -0.025108f;
                    } else {
                        return 0.034278f;
                    }
                }
            } else {
                if (features[4] < 3.563289f) {
                    if (features[4] < 2.165001f) {
                        return -0.000249f;
                    } else {
                        return -0.036967f;
                    }
                } else {
                    if (features[0] < 0.424671f) {
                        return 0.043120f;
                    } else {
                        return -0.003091f;
                    }
                }
            }
        } else {
            if (features[4] < 1.524967f) {
                if (features[0] < 0.716383f) {
                    if (features[6] < 90.056198f) {
                        return -0.007232f;
                    } else {
                        return 0.031262f;
                    }
                } else {
                    if (features[0] < 0.968604f) {
                        return -0.034488f;
                    } else {
                        return 0.014600f;
                    }
                }
            } else {
                if (features[8] < -38.891602f) {
                    if (features[4] < 4.196662f) {
                        return -0.037045f;
                    } else {
                        return -0.007680f;
                    }
                } else {
                    if (features[0] < 0.697237f) {
                        return -0.039236f;
                    } else {
                        return -0.046463f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_57(const float* features) {
        if (features[9] < 45.711044f) {
            if (features[0] < 0.609552f) {
                if (features[11] < -23.561142f) {
                    if (features[11] < -53.396942f) {
                        return 0.042069f;
                    } else {
                        return -0.002292f;
                    }
                } else {
                    if (features[8] < -38.221569f) {
                        return 0.048325f;
                    } else {
                        return -0.034044f;
                    }
                }
            } else {
                if (features[8] < -31.359373f) {
                    if (features[5] < 34.029701f) {
                        return -0.033053f;
                    } else {
                        return 0.025826f;
                    }
                } else {
                    if (features[7] < 42.485451f) {
                        return -0.043874f;
                    } else {
                        return 0.003923f;
                    }
                }
            }
        } else {
            if (features[0] < 0.830531f) {
                if (features[0] < 0.220000f) {
                    if (features[9] < 110.258118f) {
                        return -0.005286f;
                    } else {
                        return -0.025720f;
                    }
                } else {
                    if (features[8] < -25.607260f) {
                        return 0.014015f;
                    } else {
                        return -0.001825f;
                    }
                }
            } else {
                if (features[8] < -42.180264f) {
                    if (features[9] < 86.727104f) {
                        return -0.001310f;
                    } else {
                        return 0.045412f;
                    }
                } else {
                    if (features[9] < 95.902306f) {
                        return -0.035740f;
                    } else {
                        return -0.000973f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_58(const float* features) {
        if (features[0] < 0.526172f) {
            if (features[8] < -28.914127f) {
                if (features[4] < 4.130574f) {
                    if (features[4] < 0.400538f) {
                        return -0.027768f;
                    } else {
                        return -0.043251f;
                    }
                } else {
                    if (features[0] < 0.429799f) {
                        return -0.034847f;
                    } else {
                        return 0.007541f;
                    }
                }
            } else {
                if (features[12] < 8.613287f) {
                    if (features[10] < -24.766962f) {
                        return 0.048802f;
                    } else {
                        return 0.001174f;
                    }
                } else {
                    if (features[4] < 0.400538f) {
                        return -0.001295f;
                    } else {
                        return -0.034641f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[4] < 1.138125f) {
                    if (features[8] < -27.366392f) {
                        return -0.038669f;
                    } else {
                        return 0.013938f;
                    }
                } else {
                    if (features[8] < -35.359493f) {
                        return 0.008571f;
                    } else {
                        return 0.044467f;
                    }
                }
            } else {
                if (features[12] < 11.653634f) {
                    if (features[7] < 57.726425f) {
                        return -0.043613f;
                    } else {
                        return 0.020419f;
                    }
                } else {
                    if (features[11] < -55.646774f) {
                        return -0.043282f;
                    } else {
                        return 0.036463f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_59(const float* features) {
        if (features[8] < -16.819752f) {
            if (features[4] < 9.028560f) {
                if (features[0] < 0.754269f) {
                    if (features[8] < -17.973049f) {
                        return -0.042434f;
                    } else {
                        return -0.008594f;
                    }
                } else {
                    if (features[11] < 49.034405f) {
                        return -0.035249f;
                    } else {
                        return 0.015013f;
                    }
                }
            } else {
                if (features[10] < -26.249136f) {
                    if (features[10] < -26.340010f) {
                        return -0.013501f;
                    } else {
                        return 0.112919f;
                    }
                } else {
                    if (features[9] < 55.573097f) {
                        return 0.049533f;
                    } else {
                        return -0.042928f;
                    }
                }
            }
        } else {
            if (features[9] < 39.707916f) {
                if (features[8] < 9.294910f) {
                    if (features[11] < -18.223438f) {
                        return 0.052614f;
                    } else {
                        return 0.063226f;
                    }
                } else {
                    return -0.037076f;
                }
            } else {
                if (features[4] < 7.172990f) {
                    if (features[0] < 0.955786f) {
                        return -0.027108f;
                    } else {
                        return 0.032289f;
                    }
                } else {
                    if (features[8] < 1.458143f) {
                        return 0.054670f;
                    } else {
                        return -0.024764f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_60(const float* features) {
        if (features[0] < 0.584801f) {
            if (features[4] < 1.754536f) {
                if (features[8] < -36.365192f) {
                    if (features[4] < 0.312337f) {
                        return 0.049084f;
                    } else {
                        return 0.031731f;
                    }
                } else {
                    if (features[0] < 0.220000f) {
                        return 0.052180f;
                    } else {
                        return 0.007494f;
                    }
                }
            } else {
                if (features[4] < 3.654021f) {
                    if (features[4] < 2.095944f) {
                        return -0.002555f;
                    } else {
                        return -0.036742f;
                    }
                } else {
                    if (features[9] < 78.183678f) {
                        return -0.014434f;
                    } else {
                        return 0.032584f;
                    }
                }
            }
        } else {
            if (features[4] < 1.565724f) {
                if (features[4] < 0.651518f) {
                    if (features[8] < -37.156734f) {
                        return 0.030595f;
                    } else {
                        return -0.009768f;
                    }
                } else {
                    if (features[9] < 115.276413f) {
                        return -0.026273f;
                    } else {
                        return 0.005041f;
                    }
                }
            } else {
                if (features[8] < -39.753029f) {
                    if (features[4] < 4.196662f) {
                        return -0.038661f;
                    } else {
                        return -0.012879f;
                    }
                } else {
                    if (features[9] < 169.536896f) {
                        return -0.044747f;
                    } else {
                        return -0.015914f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_61(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.623931f) {
                if (features[4] < 0.312337f) {
                    if (features[8] < -36.131538f) {
                        return -0.024751f;
                    } else {
                        return 0.004974f;
                    }
                } else {
                    if (features[7] < 108.246620f) {
                        return 0.008004f;
                    } else {
                        return -0.005092f;
                    }
                }
            } else {
                if (features[8] < -27.733391f) {
                    if (features[4] < 1.974356f) {
                        return 0.019603f;
                    } else {
                        return 0.039123f;
                    }
                } else {
                    if (features[7] < 62.344837f) {
                        return -0.023502f;
                    } else {
                        return 0.019923f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[7] < 116.067444f) {
                        return -0.029187f;
                    } else {
                        return -0.008377f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.017280f;
                    } else {
                        return -0.042054f;
                    }
                }
            } else {
                if (features[7] < 75.665001f) {
                    if (features[11] < -84.723663f) {
                        return 0.001753f;
                    } else {
                        return -0.043477f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.038197f;
                    } else {
                        return -0.001640f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_62(const float* features) {
        if (features[0] < 0.537527f) {
            if (features[8] < -30.046419f) {
                if (features[9] < 88.347015f) {
                    if (features[4] < 0.400538f) {
                        return -0.005151f;
                    } else {
                        return -0.034181f;
                    }
                } else {
                    if (features[8] < -34.241722f) {
                        return -0.043516f;
                    } else {
                        return -0.033560f;
                    }
                }
            } else {
                if (features[4] < 3.457900f) {
                    if (features[0] < 0.220345f) {
                        return 0.014859f;
                    } else {
                        return -0.026278f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return -0.043395f;
                    } else {
                        return 0.048817f;
                    }
                }
            }
        } else {
            if (features[8] < -11.347665f) {
                if (features[8] < -33.079437f) {
                    if (features[4] < 3.712480f) {
                        return -0.015458f;
                    } else {
                        return 0.033460f;
                    }
                } else {
                    if (features[4] < 1.138125f) {
                        return -0.008878f;
                    } else {
                        return 0.044828f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[9] < 58.235779f) {
                        return -0.043405f;
                    } else {
                        return 0.022823f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.038030f;
                    } else {
                        return 0.044502f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_63(const float* features) {
        if (features[8] < -15.206089f) {
            if (features[4] < 8.192201f) {
                if (features[12] < -30.397575f) {
                    if (features[9] < 85.425072f) {
                        return 0.041696f;
                    } else {
                        return -0.041099f;
                    }
                } else {
                    if (features[9] < 29.557575f) {
                        return -0.000533f;
                    } else {
                        return -0.041619f;
                    }
                }
            } else {
                if (features[9] < 39.707916f) {
                    if (features[12] < 5.329009f) {
                        return 0.093887f;
                    } else {
                        return -0.028118f;
                    }
                } else {
                    if (features[12] < -27.232882f) {
                        return 0.076718f;
                    } else {
                        return -0.027047f;
                    }
                }
            }
        } else {
            if (features[9] < 39.707916f) {
                if (features[12] < 11.653634f) {
                    if (features[7] < 36.972729f) {
                        return 0.061176f;
                    } else {
                        return 0.034633f;
                    }
                } else {
                    if (features[4] < 3.004038f) {
                        return -0.016301f;
                    } else {
                        return 0.045948f;
                    }
                }
            } else {
                if (features[4] < 7.331466f) {
                    if (features[12] < 7.935221f) {
                        return 0.008852f;
                    } else {
                        return -0.044055f;
                    }
                } else {
                    if (features[7] < 88.575722f) {
                        return 0.057483f;
                    } else {
                        return -0.036518f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_64(const float* features) {
        if (features[0] < 0.592166f) {
            if (features[4] < 1.506792f) {
                if (features[8] < -27.896215f) {
                    if (features[4] < 0.400000f) {
                        return 0.043412f;
                    } else {
                        return 0.025894f;
                    }
                } else {
                    if (features[4] < 0.402781f) {
                        return -0.017361f;
                    } else {
                        return 0.021191f;
                    }
                }
            } else {
                if (features[0] < 0.270445f) {
                    if (features[4] < 4.130574f) {
                        return 0.015130f;
                    } else {
                        return 0.059457f;
                    }
                } else {
                    if (features[4] < 3.654021f) {
                        return -0.023185f;
                    } else {
                        return 0.008159f;
                    }
                }
            }
        } else {
            if (features[4] < 1.582848f) {
                if (features[8] < -32.701836f) {
                    if (features[0] < 1.000000f) {
                        return -0.007241f;
                    } else {
                        return 0.042020f;
                    }
                } else {
                    if (features[0] < 0.613141f) {
                        return 0.017116f;
                    } else {
                        return -0.037895f;
                    }
                }
            } else {
                if (features[8] < -41.056179f) {
                    if (features[12] < 7.421323f) {
                        return -0.031575f;
                    } else {
                        return 0.038341f;
                    }
                } else {
                    if (features[0] < 0.697237f) {
                        return -0.036724f;
                    } else {
                        return -0.045239f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_65(const float* features) {
        if (features[4] < 3.764467f) {
            if (features[4] < 1.754536f) {
                if (features[0] < 0.441691f) {
                    if (features[0] < 0.220000f) {
                        return -0.023825f;
                    } else {
                        return -0.005462f;
                    }
                } else {
                    if (features[0] < 0.962186f) {
                        return 0.018365f;
                    } else {
                        return -0.017560f;
                    }
                }
            } else {
                if (features[0] < 0.830531f) {
                    if (features[9] < 60.447125f) {
                        return 0.007181f;
                    } else {
                        return 0.039490f;
                    }
                } else {
                    if (features[9] < 97.643196f) {
                        return -0.028375f;
                    } else {
                        return 0.028443f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[8] < -38.221569f) {
                        return -0.012406f;
                    } else {
                        return -0.027951f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.019852f;
                    } else {
                        return -0.040608f;
                    }
                }
            } else {
                if (features[9] < 72.449219f) {
                    if (features[11] < -46.189808f) {
                        return -0.027392f;
                    } else {
                        return -0.044317f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.033266f;
                    } else {
                        return 0.011983f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_66(const float* features) {
        if (features[0] < 0.510783f) {
            if (features[9] < 65.561447f) {
                if (features[4] < 3.900546f) {
                    if (features[4] < 0.400538f) {
                        return 0.009785f;
                    } else {
                        return -0.031462f;
                    }
                } else {
                    if (features[0] < 0.331265f) {
                        return -0.043591f;
                    } else {
                        return 0.057372f;
                    }
                }
            } else {
                if (features[4] < 4.196662f) {
                    if (features[4] < 0.400538f) {
                        return -0.022224f;
                    } else {
                        return -0.042278f;
                    }
                } else {
                    if (features[0] < 0.398692f) {
                        return -0.038223f;
                    } else {
                        return 0.005427f;
                    }
                }
            }
        } else {
            if (features[9] < 25.116167f) {
                if (features[4] < 2.010578f) {
                    if (features[9] < 10.220938f) {
                        return -0.025682f;
                    } else {
                        return 0.050654f;
                    }
                } else {
                    if (features[12] < 6.403727f) {
                        return -0.041263f;
                    } else {
                        return -0.008372f;
                    }
                }
            } else {
                if (features[4] < 1.209616f) {
                    if (features[4] < 0.732578f) {
                        return -0.043097f;
                    } else {
                        return -0.011586f;
                    }
                } else {
                    if (features[9] < 81.496719f) {
                        return 0.038884f;
                    } else {
                        return 0.011156f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_67(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 45.744942f) {
                    return -0.041522f;
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.089250f;
                    } else {
                        return -0.035817f;
                    }
                }
            } else {
                if (features[4] < 11.099153f) {
                    if (features[9] < 27.835165f) {
                        return 0.007940f;
                    } else {
                        return -0.041510f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.018610f;
                    } else {
                        return -0.037127f;
                    }
                }
            }
        } else {
            if (features[9] < 47.942356f) {
                if (features[12] < 9.589411f) {
                    if (features[9] < 37.734699f) {
                        return 0.059925f;
                    } else {
                        return 0.043824f;
                    }
                } else {
                    if (features[9] < 21.241404f) {
                        return 0.051077f;
                    } else {
                        return 0.000090f;
                    }
                }
            } else {
                if (features[4] < 7.510496f) {
                    if (features[12] < 7.045576f) {
                        return -0.006129f;
                    } else {
                        return -0.042508f;
                    }
                } else {
                    if (features[9] < 88.734299f) {
                        return 0.057417f;
                    } else {
                        return -0.021980f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_68(const float* features) {
        if (features[0] < 0.584801f) {
            if (features[4] < 1.754536f) {
                if (features[0] < 0.220000f) {
                    if (features[0] < 0.131048f) {
                        return 0.034289f;
                    } else {
                        return 0.049316f;
                    }
                } else {
                    if (features[0] < 0.220345f) {
                        return -0.024722f;
                    } else {
                        return 0.028556f;
                    }
                }
            } else {
                if (features[4] < 3.421923f) {
                    if (features[4] < 2.165001f) {
                        return -0.004940f;
                    } else {
                        return -0.037773f;
                    }
                } else {
                    if (features[0] < 0.379932f) {
                        return 0.040449f;
                    } else {
                        return -0.002096f;
                    }
                }
            }
        } else {
            if (features[4] < 1.209616f) {
                if (features[4] < 0.683138f) {
                    if (features[0] < 0.909618f) {
                        return 0.002887f;
                    } else {
                        return 0.058183f;
                    }
                } else {
                    if (features[0] < 0.613141f) {
                        return 0.022377f;
                    } else {
                        return -0.022531f;
                    }
                }
            } else {
                if (features[7] < 105.312714f) {
                    if (features[0] < 0.689149f) {
                        return -0.032153f;
                    } else {
                        return -0.044239f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return -0.025383f;
                    } else {
                        return 0.016174f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_69(const float* features) {
        if (features[4] < 3.712480f) {
            if (features[4] < 1.754536f) {
                if (features[0] < 0.468439f) {
                    if (features[0] < 0.220000f) {
                        return -0.023725f;
                    } else {
                        return -0.004258f;
                    }
                } else {
                    if (features[0] < 0.869055f) {
                        return 0.020849f;
                    } else {
                        return -0.007272f;
                    }
                }
            } else {
                if (features[0] < 0.635327f) {
                    if (features[4] < 2.191313f) {
                        return 0.030146f;
                    } else {
                        return 0.043987f;
                    }
                } else {
                    if (features[8] < -30.941257f) {
                        return 0.024870f;
                    } else {
                        return -0.020179f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[4] < 3.963336f) {
                        return 0.001065f;
                    } else {
                        return -0.024766f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.019840f;
                    } else {
                        return -0.040174f;
                    }
                }
            } else {
                if (features[7] < 75.665001f) {
                    if (features[0] < 0.606666f) {
                        return -0.032857f;
                    } else {
                        return -0.043040f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.033013f;
                    } else {
                        return 0.011611f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_70(const float* features) {
        if (features[0] < 0.563239f) {
            if (features[8] < -29.612240f) {
                if (features[4] < 3.827744f) {
                    if (features[4] < 0.400538f) {
                        return -0.025239f;
                    } else {
                        return -0.040612f;
                    }
                } else {
                    if (features[0] < 0.421617f) {
                        return -0.038768f;
                    } else {
                        return 0.004570f;
                    }
                }
            } else {
                if (features[4] < 3.109267f) {
                    if (features[4] < 0.400538f) {
                        return 0.012213f;
                    } else {
                        return -0.022587f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return -0.039868f;
                    } else {
                        return 0.042313f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -42.038635f) {
                    if (features[4] < 3.421923f) {
                        return -0.034129f;
                    } else {
                        return 0.008280f;
                    }
                } else {
                    if (features[4] < 0.874601f) {
                        return -0.030150f;
                    } else {
                        return 0.034502f;
                    }
                }
            } else {
                if (features[12] < 11.254656f) {
                    if (features[7] < 58.294384f) {
                        return -0.043057f;
                    } else {
                        return 0.010190f;
                    }
                } else {
                    if (features[11] < -55.646774f) {
                        return -0.043196f;
                    } else {
                        return 0.036235f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_71(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 40.793491f) {
                    if (features[11] < 27.816441f) {
                        return -0.041137f;
                    } else {
                        return 0.003882f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.085922f;
                    } else {
                        return -0.036220f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return 0.001917f;
                    } else {
                        return -0.041217f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.013103f;
                    } else {
                        return -0.042215f;
                    }
                }
            }
        } else {
            if (features[9] < 52.675392f) {
                if (features[12] < 11.254656f) {
                    if (features[8] < 9.294910f) {
                        return 0.056544f;
                    } else {
                        return -0.030079f;
                    }
                } else {
                    if (features[4] < 8.068044f) {
                        return -0.003477f;
                    } else {
                        return 0.051619f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[8] < -5.862233f) {
                        return -0.040202f;
                    } else {
                        return -0.011645f;
                    }
                } else {
                    if (features[12] < 16.149860f) {
                        return 0.056840f;
                    } else {
                        return -0.014463f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_72(const float* features) {
        if (features[4] < 1.754536f) {
            if (features[8] < -36.365192f) {
                if (features[4] < 0.400000f) {
                    if (features[6] < 60.369301f) {
                        return 0.023025f;
                    } else {
                        return 0.045724f;
                    }
                } else {
                    if (features[4] < 0.400538f) {
                        return -0.005961f;
                    } else {
                        return 0.025151f;
                    }
                }
            } else {
                if (features[7] < 104.648392f) {
                    if (features[12] < 7.421323f) {
                        return -0.012808f;
                    } else {
                        return 0.017286f;
                    }
                } else {
                    if (features[4] < 1.506792f) {
                        return 0.027000f;
                    } else {
                        return -0.008698f;
                    }
                }
            }
        } else {
            if (features[8] < -33.079437f) {
                if (features[4] < 3.654021f) {
                    if (features[4] < 2.165001f) {
                        return -0.006543f;
                    } else {
                        return -0.035294f;
                    }
                } else {
                    if (features[7] < 77.273239f) {
                        return -0.014037f;
                    } else {
                        return 0.023845f;
                    }
                }
            } else {
                if (features[7] < 157.891937f) {
                    if (features[7] < 105.312714f) {
                        return -0.041235f;
                    } else {
                        return -0.025161f;
                    }
                } else {
                    if (features[4] < 3.269457f) {
                        return -0.021983f;
                    } else {
                        return 0.026877f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_73(const float* features) {
        if (features[9] < 44.778130f) {
            if (features[11] < -18.223438f) {
                if (features[0] < 0.624089f) {
                    if (features[11] < -53.396942f) {
                        return 0.048184f;
                    } else {
                        return 0.007171f;
                    }
                } else {
                    if (features[8] < -37.677303f) {
                        return 0.024130f;
                    } else {
                        return -0.037864f;
                    }
                }
            } else {
                if (features[9] < 36.799816f) {
                    if (features[5] < 24.301901f) {
                        return -0.012630f;
                    } else {
                        return -0.044241f;
                    }
                } else {
                    if (features[0] < 0.834728f) {
                        return -0.027697f;
                    } else {
                        return -0.046045f;
                    }
                }
            }
        } else {
            if (features[0] < 0.830531f) {
                if (features[0] < 0.220000f) {
                    if (features[9] < 110.258118f) {
                        return -0.002310f;
                    } else {
                        return -0.023214f;
                    }
                } else {
                    if (features[8] < -25.423883f) {
                        return 0.012901f;
                    } else {
                        return -0.000900f;
                    }
                }
            } else {
                if (features[9] < 85.781014f) {
                    if (features[8] < -47.446758f) {
                        return 0.022014f;
                    } else {
                        return -0.032305f;
                    }
                } else {
                    if (features[8] < -31.500172f) {
                        return 0.025166f;
                    } else {
                        return -0.016929f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_74(const float* features) {
        if (features[0] < 0.479567f) {
            if (features[8] < -31.808825f) {
                if (features[9] < 46.499054f) {
                    if (features[4] < 0.400538f) {
                        return 0.061958f;
                    } else {
                        return -0.020185f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return -0.031512f;
                    } else {
                        return -0.042340f;
                    }
                }
            } else {
                if (features[4] < 0.400538f) {
                    if (features[4] < 0.400000f) {
                        return -0.043436f;
                    } else {
                        return 0.040761f;
                    }
                } else {
                    if (features[0] < 0.398692f) {
                        return -0.043282f;
                    } else {
                        return 0.005605f;
                    }
                }
            }
        } else {
            if (features[8] < -8.364439f) {
                if (features[8] < -38.367355f) {
                    if (features[0] < 0.821098f) {
                        return -0.025626f;
                    } else {
                        return 0.027315f;
                    }
                } else {
                    if (features[4] < 1.109238f) {
                        return -0.021856f;
                    } else {
                        return 0.032739f;
                    }
                }
            } else {
                if (features[12] < 12.347901f) {
                    if (features[8] < 2.464921f) {
                        return -0.042052f;
                    } else {
                        return 0.001348f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.044675f;
                    } else {
                        return 0.032315f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_75(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[8] < -37.965397f) {
                    return -0.041264f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.088721f;
                    } else {
                        return -0.039181f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return -0.002669f;
                    } else {
                        return -0.040892f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return 0.051393f;
                    } else {
                        return -0.024079f;
                    }
                }
            }
        } else {
            if (features[9] < 39.707916f) {
                if (features[12] < 11.653634f) {
                    if (features[8] < 2.464921f) {
                        return 0.056319f;
                    } else {
                        return 0.040247f;
                    }
                } else {
                    if (features[0] < 0.645642f) {
                        return -0.028152f;
                    } else {
                        return 0.041618f;
                    }
                }
            } else {
                if (features[4] < 6.867007f) {
                    if (features[12] < 7.045576f) {
                        return -0.000586f;
                    } else {
                        return -0.043167f;
                    }
                } else {
                    if (features[8] < 2.464921f) {
                        return 0.044622f;
                    } else {
                        return -0.032439f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_76(const float* features) {
        if (features[0] < 0.592166f) {
            if (features[4] < 1.506792f) {
                if (features[8] < -36.365192f) {
                    if (features[4] < 0.290872f) {
                        return 0.043053f;
                    } else {
                        return 0.027576f;
                    }
                } else {
                    if (features[12] < 7.248966f) {
                        return 0.004319f;
                    } else {
                        return 0.030681f;
                    }
                }
            } else {
                if (features[8] < -42.038635f) {
                    if (features[4] < 3.827744f) {
                        return 0.005248f;
                    } else {
                        return 0.042799f;
                    }
                } else {
                    if (features[0] < 0.281372f) {
                        return 0.018419f;
                    } else {
                        return -0.018777f;
                    }
                }
            }
        } else {
            if (features[4] < 1.194893f) {
                if (features[6] < 97.991699f) {
                    if (features[8] < -45.201443f) {
                        return 0.009799f;
                    } else {
                        return -0.022398f;
                    }
                } else {
                    if (features[5] < 26.410200f) {
                        return -0.025261f;
                    } else {
                        return 0.050632f;
                    }
                }
            } else {
                if (features[9] < 102.380646f) {
                    if (features[8] < -42.629635f) {
                        return -0.029024f;
                    } else {
                        return -0.043225f;
                    }
                } else {
                    if (features[4] < 9.028560f) {
                        return -0.028468f;
                    } else {
                        return 0.016460f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_77(const float* features) {
        if (features[9] < 45.711044f) {
            if (features[0] < 0.609552f) {
                if (features[11] < -17.242056f) {
                    if (features[12] < 34.158642f) {
                        return 0.000234f;
                    } else {
                        return 0.058838f;
                    }
                } else {
                    if (features[8] < -36.131538f) {
                        return 0.011327f;
                    } else {
                        return -0.033797f;
                    }
                }
            } else {
                if (features[12] < 12.347901f) {
                    if (features[9] < 36.799816f) {
                        return -0.043369f;
                    } else {
                        return -0.033013f;
                    }
                } else {
                    if (features[8] < -21.294926f) {
                        return 0.040493f;
                    } else {
                        return -0.036622f;
                    }
                }
            }
        } else {
            if (features[0] < 0.885088f) {
                if (features[0] < 0.281372f) {
                    if (features[9] < 113.426125f) {
                        return 0.000281f;
                    } else {
                        return -0.012259f;
                    }
                } else {
                    if (features[8] < -25.607260f) {
                        return 0.013165f;
                    } else {
                        return -0.001748f;
                    }
                }
            } else {
                if (features[9] < 90.172180f) {
                    if (features[8] < -38.891602f) {
                        return -0.013940f;
                    } else {
                        return -0.036977f;
                    }
                } else {
                    if (features[8] < -28.578499f) {
                        return 0.019288f;
                    } else {
                        return -0.032513f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_78(const float* features) {
        if (features[0] < 0.479567f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.474017f) {
                        return -0.044147f;
                    } else {
                        return -0.010658f;
                    }
                } else {
                    if (features[8] < -9.279342f) {
                        return 0.032698f;
                    } else {
                        return -0.039834f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[0] < 0.386137f) {
                        return -0.044337f;
                    } else {
                        return -0.035086f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return -0.041600f;
                    } else {
                        return 0.008009f;
                    }
                }
            }
        } else {
            if (features[9] < 25.116167f) {
                if (features[8] < -16.819752f) {
                    if (features[4] < 8.192201f) {
                        return 0.037338f;
                    } else {
                        return -0.050867f;
                    }
                } else {
                    if (features[0] < 0.513516f) {
                        return 0.070535f;
                    } else {
                        return -0.040171f;
                    }
                }
            } else {
                if (features[4] < 1.138125f) {
                    if (features[8] < -25.790308f) {
                        return -0.037422f;
                    } else {
                        return 0.018135f;
                    }
                } else {
                    if (features[8] < -38.367355f) {
                        return -0.005353f;
                    } else {
                        return 0.029916f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_79(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 42.393765f) {
                    if (features[11] < 27.816441f) {
                        return -0.040706f;
                    } else {
                        return 0.006076f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.079268f;
                    } else {
                        return -0.035216f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return -0.013270f;
                    } else {
                        return -0.040830f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.010561f;
                    } else {
                        return -0.038898f;
                    }
                }
            }
        } else {
            if (features[9] < 52.675392f) {
                if (features[12] < 8.613287f) {
                    if (features[8] < 9.294910f) {
                        return 0.053803f;
                    } else {
                        return -0.030130f;
                    }
                } else {
                    if (features[8] < -7.445725f) {
                        return -0.018426f;
                    } else {
                        return 0.037420f;
                    }
                }
            } else {
                if (features[4] < 8.068044f) {
                    if (features[0] < 0.834728f) {
                        return -0.036583f;
                    } else {
                        return -0.001868f;
                    }
                } else {
                    if (features[8] < -15.206089f) {
                        return -0.029433f;
                    } else {
                        return 0.047759f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_80(const float* features) {
        if (features[0] < 0.592166f) {
            if (features[4] < 1.867067f) {
                if (features[8] < -36.769554f) {
                    if (features[6] < 68.928497f) {
                        return 0.016184f;
                    } else {
                        return 0.032704f;
                    }
                } else {
                    if (features[7] < 105.973305f) {
                        return 0.000242f;
                    } else {
                        return 0.024534f;
                    }
                }
            } else {
                if (features[4] < 3.421923f) {
                    if (features[6] < 97.991699f) {
                        return -0.034420f;
                    } else {
                        return 0.001995f;
                    }
                } else {
                    if (features[0] < 0.379932f) {
                        return 0.037472f;
                    } else {
                        return -0.003419f;
                    }
                }
            }
        } else {
            if (features[4] < 1.411447f) {
                if (features[0] < 0.681520f) {
                    if (features[8] < -29.210335f) {
                        return 0.009572f;
                    } else {
                        return -0.028322f;
                    }
                } else {
                    if (features[0] < 0.982828f) {
                        return -0.030166f;
                    } else {
                        return 0.014469f;
                    }
                }
            } else {
                if (features[8] < -39.753029f) {
                    if (features[4] < 3.900546f) {
                        return -0.037163f;
                    } else {
                        return -0.009283f;
                    }
                } else {
                    if (features[8] < -32.200939f) {
                        return -0.036287f;
                    } else {
                        return -0.043783f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_81(const float* features) {
        if (features[4] < 3.712480f) {
            if (features[4] < 1.254273f) {
                if (features[8] < -45.201443f) {
                    if (features[4] < 0.400000f) {
                        return -0.030298f;
                    } else {
                        return -0.008986f;
                    }
                } else {
                    if (features[7] < 14.921755f) {
                        return -0.037674f;
                    } else {
                        return 0.003530f;
                    }
                }
            } else {
                if (features[9] < 50.876228f) {
                    if (features[8] < -24.223234f) {
                        return 0.003835f;
                    } else {
                        return -0.034318f;
                    }
                } else {
                    if (features[4] < 1.974356f) {
                        return 0.014925f;
                    } else {
                        return 0.030784f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.192201f) {
                    if (features[4] < 3.963336f) {
                        return 0.005209f;
                    } else {
                        return -0.022260f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.015019f;
                    } else {
                        return -0.038968f;
                    }
                }
            } else {
                if (features[9] < 81.853035f) {
                    if (features[11] < -119.900040f) {
                        return 0.011055f;
                    } else {
                        return -0.041429f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.030509f;
                    } else {
                        return 0.008376f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_82(const float* features) {
        if (features[0] < 0.510783f) {
            if (features[8] < -30.203865f) {
                if (features[9] < 88.347015f) {
                    if (features[0] < 0.220345f) {
                        return -0.008649f;
                    } else {
                        return -0.033518f;
                    }
                } else {
                    if (features[8] < -32.582027f) {
                        return -0.042188f;
                    } else {
                        return -0.028539f;
                    }
                }
            } else {
                if (features[7] < 112.047249f) {
                    if (features[12] < 8.613287f) {
                        return 0.019677f;
                    } else {
                        return -0.019390f;
                    }
                } else {
                    if (features[0] < 0.459414f) {
                        return -0.039345f;
                    } else {
                        return -0.013351f;
                    }
                }
            }
        } else {
            if (features[8] < -8.364439f) {
                if (features[8] < -32.453449f) {
                    if (features[0] < 0.762566f) {
                        return -0.011644f;
                    } else {
                        return 0.021890f;
                    }
                } else {
                    if (features[9] < 132.872925f) {
                        return 0.034395f;
                    } else {
                        return -0.003465f;
                    }
                }
            } else {
                if (features[12] < 11.254656f) {
                    if (features[7] < 58.294384f) {
                        return -0.041794f;
                    } else {
                        return 0.002674f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.042693f;
                    } else {
                        return 0.026278f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_83(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 42.393765f) {
                    if (features[11] < 27.816441f) {
                        return -0.040065f;
                    } else {
                        return -0.003979f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.070289f;
                    } else {
                        return -0.034502f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return 0.003864f;
                    } else {
                        return -0.040512f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return 0.048845f;
                    } else {
                        return -0.022474f;
                    }
                }
            }
        } else {
            if (features[9] < 39.707916f) {
                if (features[12] < 13.492349f) {
                    if (features[7] < 36.972729f) {
                        return 0.052933f;
                    } else {
                        return 0.021650f;
                    }
                } else {
                    if (features[11] < -36.200611f) {
                        return 0.040655f;
                    } else {
                        return -0.024648f;
                    }
                }
            } else {
                if (features[12] < 9.132126f) {
                    if (features[8] < -10.363048f) {
                        return -0.010422f;
                    } else {
                        return 0.043941f;
                    }
                } else {
                    if (features[4] < 10.386150f) {
                        return -0.043109f;
                    } else {
                        return 0.013897f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_84(const float* features) {
        if (features[0] < 0.560268f) {
            if (features[4] < 1.333764f) {
                if (features[0] < 0.220345f) {
                    if (features[0] < 0.220000f) {
                        return 0.041160f;
                    } else {
                        return -0.027049f;
                    }
                } else {
                    if (features[6] < 74.708000f) {
                        return 0.021043f;
                    } else {
                        return 0.035242f;
                    }
                }
            } else {
                if (features[0] < 0.267229f) {
                    if (features[4] < 3.109267f) {
                        return 0.014589f;
                    } else {
                        return 0.048021f;
                    }
                } else {
                    if (features[7] < 157.891937f) {
                        return -0.009979f;
                    } else {
                        return 0.034116f;
                    }
                }
            }
        } else {
            if (features[4] < 1.524967f) {
                if (features[4] < 0.683138f) {
                    if (features[8] < -37.882805f) {
                        return 0.023410f;
                    } else {
                        return -0.007312f;
                    }
                } else {
                    if (features[6] < 79.657204f) {
                        return -0.029114f;
                    } else {
                        return -0.003870f;
                    }
                }
            } else {
                if (features[8] < -38.891602f) {
                    if (features[0] < 0.650629f) {
                        return 0.001236f;
                    } else {
                        return -0.030737f;
                    }
                } else {
                    if (features[7] < 133.129364f) {
                        return -0.042165f;
                    } else {
                        return -0.022450f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_85(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.240314f) {
                if (features[9] < 111.598907f) {
                    if (features[9] < 45.711044f) {
                        return -0.023581f;
                    } else {
                        return 0.007212f;
                    }
                } else {
                    if (features[8] < -39.060780f) {
                        return -0.014827f;
                    } else {
                        return -0.000101f;
                    }
                }
            } else {
                if (features[9] < 44.778130f) {
                    if (features[11] < -32.464855f) {
                        return 0.013816f;
                    } else {
                        return -0.034054f;
                    }
                } else {
                    if (features[4] < 1.927128f) {
                        return 0.012698f;
                    } else {
                        return 0.027685f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.450968f) {
                    if (features[12] < -7.776650f) {
                        return -0.036239f;
                    } else {
                        return -0.016766f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.014691f;
                    } else {
                        return -0.039393f;
                    }
                }
            } else {
                if (features[12] < 11.994812f) {
                    if (features[9] < 150.050537f) {
                        return -0.040217f;
                    } else {
                        return 0.002906f;
                    }
                } else {
                    if (features[9] < 98.628227f) {
                        return -0.025610f;
                    } else {
                        return 0.017924f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_86(const float* features) {
        if (features[0] < 0.580373f) {
            if (features[8] < -31.500172f) {
                if (features[4] < 3.712480f) {
                    if (features[9] < 48.478733f) {
                        return -0.001713f;
                    } else {
                        return -0.037369f;
                    }
                } else {
                    if (features[0] < 0.421617f) {
                        return -0.036448f;
                    } else {
                        return 0.005131f;
                    }
                }
            } else {
                if (features[12] < 8.613287f) {
                    if (features[7] < 104.046165f) {
                        return 0.021494f;
                    } else {
                        return -0.022423f;
                    }
                } else {
                    if (features[6] < 66.103500f) {
                        return -0.001031f;
                    } else {
                        return -0.032699f;
                    }
                }
            }
        } else {
            if (features[8] < -10.363048f) {
                if (features[8] < -36.769554f) {
                    if (features[9] < 100.804039f) {
                        return 0.008711f;
                    } else {
                        return -0.030358f;
                    }
                } else {
                    if (features[4] < 1.151242f) {
                        return -0.011106f;
                    } else {
                        return 0.034619f;
                    }
                }
            } else {
                if (features[12] < 10.241736f) {
                    if (features[4] < 1.702742f) {
                        return 0.040611f;
                    } else {
                        return -0.040500f;
                    }
                } else {
                    if (features[11] < -53.396942f) {
                        return -0.042047f;
                    } else {
                        return 0.031168f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_87(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 40.793491f) {
                    if (features[11] < 27.816441f) {
                        return -0.040349f;
                    } else {
                        return 0.006720f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.073844f;
                    } else {
                        return -0.034224f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return -0.001164f;
                    } else {
                        return -0.040246f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.004730f;
                    } else {
                        return -0.038361f;
                    }
                }
            }
        } else {
            if (features[7] < 36.972729f) {
                if (features[12] < 11.653634f) {
                    if (features[12] < 7.248966f) {
                        return 0.052410f;
                    } else {
                        return 0.038084f;
                    }
                } else {
                    if (features[8] < -6.724053f) {
                        return -0.008129f;
                    } else {
                        return 0.041668f;
                    }
                }
            } else {
                if (features[4] < 7.510496f) {
                    if (features[8] < -10.363048f) {
                        return -0.042631f;
                    } else {
                        return -0.002466f;
                    }
                } else {
                    if (features[8] < 2.464921f) {
                        return 0.044411f;
                    } else {
                        return -0.048408f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_88(const float* features) {
        if (features[0] < 0.592166f) {
            if (features[4] < 1.867067f) {
                if (features[0] < 0.220000f) {
                    if (features[6] < 68.928497f) {
                        return 0.025524f;
                    } else {
                        return 0.041175f;
                    }
                } else {
                    if (features[0] < 0.220345f) {
                        return -0.025858f;
                    } else {
                        return 0.021218f;
                    }
                }
            } else {
                if (features[4] < 3.385558f) {
                    if (features[4] < 2.165001f) {
                        return -0.006570f;
                    } else {
                        return -0.036174f;
                    }
                } else {
                    if (features[9] < 74.585480f) {
                        return -0.017552f;
                    } else {
                        return 0.023214f;
                    }
                }
            }
        } else {
            if (features[4] < 1.565724f) {
                if (features[9] < 89.328476f) {
                    if (features[11] < -63.827534f) {
                        return 0.032910f;
                    } else {
                        return -0.026394f;
                    }
                } else {
                    if (features[6] < 68.614899f) {
                        return -0.024981f;
                    } else {
                        return 0.011470f;
                    }
                }
            } else {
                if (features[9] < 98.072708f) {
                    if (features[0] < 0.716383f) {
                        return -0.034476f;
                    } else {
                        return -0.043225f;
                    }
                } else {
                    if (features[4] < 8.649189f) {
                        return -0.031927f;
                    } else {
                        return 0.013533f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_89(const float* features) {
        if (features[9] < 44.778130f) {
            if (features[11] < -18.223438f) {
                if (features[0] < 0.624089f) {
                    if (features[6] < 80.024696f) {
                        return -0.007011f;
                    } else {
                        return 0.026553f;
                    }
                } else {
                    if (features[8] < -37.677303f) {
                        return 0.037268f;
                    } else {
                        return -0.036032f;
                    }
                }
            } else {
                if (features[9] < 37.734699f) {
                    if (features[7] < 36.972729f) {
                        return -0.042227f;
                    } else {
                        return 0.015775f;
                    }
                } else {
                    if (features[12] < 15.550030f) {
                        return -0.031397f;
                    } else {
                        return 0.008682f;
                    }
                }
            }
        } else {
            if (features[0] < 0.830531f) {
                if (features[0] < 0.281372f) {
                    if (features[9] < 150.050537f) {
                        return 0.000548f;
                    } else {
                        return -0.016567f;
                    }
                } else {
                    if (features[9] < 171.947769f) {
                        return 0.012556f;
                    } else {
                        return -0.003106f;
                    }
                }
            } else {
                if (features[9] < 86.727104f) {
                    if (features[8] < -47.446758f) {
                        return 0.017636f;
                    } else {
                        return -0.030472f;
                    }
                } else {
                    if (features[8] < -31.245762f) {
                        return 0.021133f;
                    } else {
                        return -0.018355f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_90(const float* features) {
        if (features[0] < 0.468439f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.044007f;
                    } else {
                        return -0.014148f;
                    }
                } else {
                    if (features[8] < -42.325005f) {
                        return -0.029887f;
                    } else {
                        return 0.033329f;
                    }
                }
            } else {
                if (features[0] < 0.414259f) {
                    if (features[4] < 3.900546f) {
                        return -0.043244f;
                    } else {
                        return -0.030528f;
                    }
                } else {
                    if (features[4] < 3.827744f) {
                        return -0.029556f;
                    } else {
                        return 0.013693f;
                    }
                }
            }
        } else {
            if (features[4] < 1.209616f) {
                if (features[8] < -28.050787f) {
                    if (features[0] < 0.834728f) {
                        return -0.038015f;
                    } else {
                        return -0.003393f;
                    }
                } else {
                    if (features[12] < 3.598175f) {
                        return 0.035177f;
                    } else {
                        return -0.023081f;
                    }
                }
            } else {
                if (features[8] < -12.451389f) {
                    if (features[8] < -33.079437f) {
                        return 0.003432f;
                    } else {
                        return 0.033712f;
                    }
                } else {
                    if (features[7] < 37.622398f) {
                        return -0.037495f;
                    } else {
                        return 0.009327f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_91(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[4] < 8.812652f) {
                if (features[0] < 0.754269f) {
                    if (features[8] < -17.973049f) {
                        return -0.041305f;
                    } else {
                        return 0.002485f;
                    }
                } else {
                    if (features[11] < 51.201965f) {
                        return -0.032496f;
                    } else {
                        return 0.019489f;
                    }
                }
            } else {
                if (features[10] < -26.310945f) {
                    if (features[10] < -26.340010f) {
                        return -0.011601f;
                    } else {
                        return 0.098127f;
                    }
                } else {
                    if (features[9] < 59.428001f) {
                        return 0.014982f;
                    } else {
                        return -0.041261f;
                    }
                }
            }
        } else {
            if (features[9] < 59.428001f) {
                if (features[9] < 35.805687f) {
                    if (features[11] < -18.223438f) {
                        return 0.037155f;
                    } else {
                        return 0.050756f;
                    }
                } else {
                    if (features[0] < 0.613141f) {
                        return -0.032288f;
                    } else {
                        return 0.036889f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[9] < 78.590889f) {
                        return -0.015674f;
                    } else {
                        return -0.038461f;
                    }
                } else {
                    if (features[8] < -9.279342f) {
                        return -0.017524f;
                    } else {
                        return 0.038027f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_92(const float* features) {
        if (features[0] < 0.613141f) {
            if (features[9] < 103.933548f) {
                if (features[8] < -36.921341f) {
                    if (features[12] < 0.005831f) {
                        return 0.007360f;
                    } else {
                        return 0.027256f;
                    }
                } else {
                    if (features[0] < 0.479567f) {
                        return -0.002727f;
                    } else {
                        return -0.028555f;
                    }
                }
            } else {
                if (features[8] < -41.883942f) {
                    if (features[6] < 72.484100f) {
                        return 0.020729f;
                    } else {
                        return 0.036825f;
                    }
                } else {
                    if (features[0] < 0.429799f) {
                        return 0.022070f;
                    } else {
                        return 0.004215f;
                    }
                }
            }
        } else {
            if (features[8] < -42.629635f) {
                if (features[5] < 33.327599f) {
                    if (features[0] < 0.787316f) {
                        return -0.008461f;
                    } else {
                        return -0.030173f;
                    }
                } else {
                    if (features[9] < 114.050507f) {
                        return -0.007299f;
                    } else {
                        return 0.052574f;
                    }
                }
            } else {
                if (features[7] < 105.312714f) {
                    if (features[0] < 0.709359f) {
                        return -0.030372f;
                    } else {
                        return -0.042351f;
                    }
                } else {
                    if (features[0] < 0.727645f) {
                        return -0.004763f;
                    } else {
                        return -0.031101f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_93(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.254273f) {
                if (features[0] < 0.557457f) {
                    if (features[4] < 0.013142f) {
                        return -0.028601f;
                    } else {
                        return -0.004163f;
                    }
                } else {
                    if (features[0] < 0.950064f) {
                        return 0.028815f;
                    } else {
                        return -0.015396f;
                    }
                }
            } else {
                if (features[0] < 0.826246f) {
                    if (features[9] < 47.942356f) {
                        return -0.006449f;
                    } else {
                        return 0.024485f;
                    }
                } else {
                    if (features[9] < 82.335815f) {
                        return -0.032121f;
                    } else {
                        return 0.013824f;
                    }
                }
            }
        } else {
            if (features[9] < 62.368469f) {
                if (features[0] < 0.673074f) {
                    if (features[4] < 7.648993f) {
                        return -0.035551f;
                    } else {
                        return 0.003563f;
                    }
                } else {
                    if (features[11] < -49.385864f) {
                        return -0.019478f;
                    } else {
                        return -0.041146f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[5] < 34.719700f) {
                        return -0.024666f;
                    } else {
                        return 0.007539f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.013507f;
                    } else {
                        return -0.042523f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_94(const float* features) {
        if (features[0] < 0.471007f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.043704f;
                    } else {
                        return -0.020881f;
                    }
                } else {
                    if (features[9] < 107.757637f) {
                        return 0.030130f;
                    } else {
                        return -0.025981f;
                    }
                }
            } else {
                if (features[4] < 3.827744f) {
                    if (features[0] < 0.411004f) {
                        return -0.042940f;
                    } else {
                        return -0.030316f;
                    }
                } else {
                    if (features[0] < 0.337552f) {
                        return -0.044004f;
                    } else {
                        return 0.004787f;
                    }
                }
            }
        } else {
            if (features[4] < 1.138125f) {
                if (features[8] < -28.050787f) {
                    if (features[0] < 0.834728f) {
                        return -0.038715f;
                    } else {
                        return -0.014458f;
                    }
                } else {
                    if (features[12] < -1.056396f) {
                        return 0.077313f;
                    } else {
                        return -0.006053f;
                    }
                }
            } else {
                if (features[8] < -12.451389f) {
                    if (features[9] < 100.804039f) {
                        return 0.026816f;
                    } else {
                        return -0.006000f;
                    }
                } else {
                    if (features[9] < 33.471188f) {
                        return -0.036597f;
                    } else {
                        return 0.005289f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_95(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 49.034405f) {
                    if (features[4] < 5.630928f) {
                        return -0.040331f;
                    } else {
                        return 0.003258f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.068241f;
                    } else {
                        return -0.032136f;
                    }
                }
            } else {
                if (features[4] < 10.871242f) {
                    if (features[9] < 27.835165f) {
                        return 0.006803f;
                    } else {
                        return -0.040011f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.015071f;
                    } else {
                        return -0.039648f;
                    }
                }
            }
        } else {
            if (features[9] < 67.846146f) {
                if (features[12] < 8.883047f) {
                    if (features[8] < 9.294910f) {
                        return 0.048487f;
                    } else {
                        return -0.032365f;
                    }
                } else {
                    if (features[4] < 7.331466f) {
                        return -0.008000f;
                    } else {
                        return 0.045120f;
                    }
                }
            } else {
                if (features[4] < 7.172990f) {
                    if (features[9] < 78.590889f) {
                        return -0.017153f;
                    } else {
                        return -0.040756f;
                    }
                } else {
                    if (features[8] < -12.451389f) {
                        return -0.034491f;
                    } else {
                        return 0.028631f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_96(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[9] < 107.164749f) {
                if (features[8] < -36.921341f) {
                    if (features[0] < 0.220000f) {
                        return 0.031045f;
                    } else {
                        return 0.009623f;
                    }
                } else {
                    if (features[12] < 5.858821f) {
                        return -0.018506f;
                    } else {
                        return 0.007379f;
                    }
                }
            } else {
                if (features[6] < 73.504799f) {
                    if (features[0] < 0.427493f) {
                        return 0.019440f;
                    } else {
                        return 0.001471f;
                    }
                } else {
                    if (features[8] < -36.769554f) {
                        return 0.033648f;
                    } else {
                        return 0.018329f;
                    }
                }
            }
        } else {
            if (features[8] < -33.079437f) {
                if (features[0] < 0.716383f) {
                    if (features[5] < 30.826799f) {
                        return -0.019895f;
                    } else {
                        return 0.001276f;
                    }
                } else {
                    if (features[9] < 98.072708f) {
                        return -0.036421f;
                    } else {
                        return -0.013969f;
                    }
                }
            } else {
                if (features[12] < 18.231884f) {
                    if (features[11] < -63.827534f) {
                        return -0.013114f;
                    } else {
                        return -0.042300f;
                    }
                } else {
                    if (features[9] < 85.696213f) {
                        return -0.043323f;
                    } else {
                        return 0.012827f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_97(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.333764f) {
                if (features[0] < 0.541182f) {
                    if (features[6] < 74.540901f) {
                        return 0.002236f;
                    } else {
                        return -0.010077f;
                    }
                } else {
                    if (features[0] < 0.890645f) {
                        return 0.023643f;
                    } else {
                        return -0.015206f;
                    }
                }
            } else {
                if (features[0] < 0.826246f) {
                    if (features[5] < 28.382099f) {
                        return 0.012319f;
                    } else {
                        return 0.026974f;
                    }
                } else {
                    if (features[7] < 76.821541f) {
                        return -0.023574f;
                    } else {
                        return 0.012259f;
                    }
                }
            }
        } else {
            if (features[7] < 77.273239f) {
                if (features[0] < 0.606666f) {
                    if (features[4] < 8.812652f) {
                        return -0.020751f;
                    } else {
                        return 0.024960f;
                    }
                } else {
                    if (features[11] < -44.690674f) {
                        return -0.015112f;
                    } else {
                        return -0.037394f;
                    }
                }
            } else {
                if (features[4] < 7.748848f) {
                    if (features[10] < -20.270802f) {
                        return -0.005084f;
                    } else {
                        return -0.023921f;
                    }
                } else {
                    if (features[4] < 12.867560f) {
                        return 0.017646f;
                    } else {
                        return -0.044764f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_98(const float* features) {
        if (features[0] < 0.479567f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.043529f;
                    } else {
                        return -0.021770f;
                    }
                } else {
                    if (features[9] < 31.048883f) {
                        return -0.032067f;
                    } else {
                        return 0.025693f;
                    }
                }
            } else {
                if (features[4] < 3.963336f) {
                    if (features[0] < 0.414259f) {
                        return -0.042391f;
                    } else {
                        return -0.028592f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return -0.039511f;
                    } else {
                        return 0.008918f;
                    }
                }
            }
        } else {
            if (features[4] < 0.957507f) {
                if (features[6] < 64.157204f) {
                    if (features[4] < 0.423230f) {
                        return -0.040030f;
                    } else {
                        return 0.024230f;
                    }
                } else {
                    if (features[4] < 0.795667f) {
                        return -0.043722f;
                    } else {
                        return -0.018123f;
                    }
                }
            } else {
                if (features[9] < 26.425684f) {
                    if (features[4] < 2.165001f) {
                        return 0.031274f;
                    } else {
                        return -0.033805f;
                    }
                } else {
                    if (features[9] < 102.858009f) {
                        return 0.024303f;
                    } else {
                        return -0.007825f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_99(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -27.232882f) {
                if (features[11] < 42.393765f) {
                    if (features[0] < 0.968604f) {
                        return -0.040015f;
                    } else {
                        return 0.017293f;
                    }
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.067127f;
                    } else {
                        return -0.033817f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[9] < 27.835165f) {
                        return -0.006637f;
                    } else {
                        return -0.040025f;
                    }
                } else {
                    if (features[9] < 35.805687f) {
                        return 0.064611f;
                    } else {
                        return -0.022414f;
                    }
                }
            }
        } else {
            if (features[7] < 36.972729f) {
                if (features[12] < 11.994812f) {
                    if (features[12] < 7.421323f) {
                        return 0.049598f;
                    } else {
                        return 0.033359f;
                    }
                } else {
                    if (features[9] < 17.460260f) {
                        return 0.042763f;
                    } else {
                        return -0.012274f;
                    }
                }
            } else {
                if (features[4] < 4.130574f) {
                    if (features[8] < -7.445725f) {
                        return -0.040962f;
                    } else {
                        return -0.009034f;
                    }
                } else {
                    if (features[8] < 2.464921f) {
                        return 0.029501f;
                    } else {
                        return -0.036506f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_100(const float* features) {
        if (features[0] < 0.588419f) {
            if (features[4] < 1.867067f) {
                if (features[4] < 0.400000f) {
                    if (features[6] < 81.564400f) {
                        return 0.027064f;
                    } else {
                        return 0.047812f;
                    }
                } else {
                    if (features[4] < 0.400538f) {
                        return -0.027162f;
                    } else {
                        return 0.019692f;
                    }
                }
            } else {
                if (features[4] < 3.385558f) {
                    if (features[6] < 97.991699f) {
                        return -0.032378f;
                    } else {
                        return 0.009004f;
                    }
                } else {
                    if (features[0] < 0.370829f) {
                        return 0.032018f;
                    } else {
                        return -0.003410f;
                    }
                }
            }
        } else {
            if (features[4] < 1.565724f) {
                if (features[4] < 0.683138f) {
                    if (features[5] < 31.707300f) {
                        return -0.001599f;
                    } else {
                        return 0.024302f;
                    }
                } else {
                    if (features[7] < 107.558311f) {
                        return -0.024225f;
                    } else {
                        return 0.003404f;
                    }
                }
            } else {
                if (features[7] < 159.767288f) {
                    if (features[7] < 81.398003f) {
                        return -0.040259f;
                    } else {
                        return -0.030297f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return -0.015844f;
                    } else {
                        return 0.065072f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_101(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.254273f) {
                if (features[0] < 0.468439f) {
                    if (features[4] < 0.312337f) {
                        return -0.021335f;
                    } else {
                        return -0.004961f;
                    }
                } else {
                    if (features[8] < -45.028492f) {
                        return 0.001523f;
                    } else {
                        return 0.020721f;
                    }
                }
            } else {
                if (features[0] < 0.885088f) {
                    if (features[8] < -24.832764f) {
                        return 0.023124f;
                    } else {
                        return -0.002174f;
                    }
                } else {
                    if (features[8] < -42.180264f) {
                        return 0.022249f;
                    } else {
                        return -0.026171f;
                    }
                }
            }
        } else {
            if (features[9] < 89.328476f) {
                if (features[0] < 0.606666f) {
                    if (features[4] < 8.192201f) {
                        return -0.022576f;
                    } else {
                        return 0.023410f;
                    }
                } else {
                    if (features[8] < -31.245762f) {
                        return -0.027123f;
                    } else {
                        return -0.039534f;
                    }
                }
            } else {
                if (features[4] < 7.969834f) {
                    if (features[11] < 76.410004f) {
                        return -0.017947f;
                    } else {
                        return 0.024356f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.016217f;
                    } else {
                        return -0.044438f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_102(const float* features) {
        if (features[0] < 0.479567f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.043381f;
                    } else {
                        return -0.019956f;
                    }
                } else {
                    if (features[9] < 85.625351f) {
                        return 0.032546f;
                    } else {
                        return -0.010588f;
                    }
                }
            } else {
                if (features[0] < 0.414259f) {
                    if (features[0] < 0.370829f) {
                        return -0.042859f;
                    } else {
                        return -0.031519f;
                    }
                } else {
                    if (features[4] < 3.457900f) {
                        return -0.029112f;
                    } else {
                        return 0.013322f;
                    }
                }
            }
        } else {
            if (features[4] < 0.957507f) {
                if (features[0] < 0.762566f) {
                    if (features[6] < 62.653801f) {
                        return -0.015711f;
                    } else {
                        return -0.041254f;
                    }
                } else {
                    if (features[9] < 51.497909f) {
                        return 0.065007f;
                    } else {
                        return -0.012031f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[4] < 3.712480f) {
                        return 0.006283f;
                    } else {
                        return 0.033099f;
                    }
                } else {
                    if (features[9] < 34.864788f) {
                        return -0.043055f;
                    } else {
                        return -0.005850f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_103(const float* features) {
        if (features[8] < -18.441996f) {
            if (features[12] < -25.221086f) {
                if (features[8] < -37.965397f) {
                    return -0.040434f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.073636f;
                    } else {
                        return -0.038278f;
                    }
                }
            } else {
                if (features[4] < 9.522261f) {
                    if (features[0] < 0.754269f) {
                        return -0.041368f;
                    } else {
                        return -0.030919f;
                    }
                } else {
                    if (features[0] < 0.716383f) {
                        return -0.041547f;
                    } else {
                        return 0.015613f;
                    }
                }
            }
        } else {
            if (features[9] < 35.805687f) {
                if (features[12] < 11.653634f) {
                    if (features[11] < -43.145985f) {
                        return 0.023593f;
                    } else {
                        return 0.048520f;
                    }
                } else {
                    if (features[8] < -7.445725f) {
                        return -0.028058f;
                    } else {
                        return 0.030979f;
                    }
                }
            } else {
                if (features[4] < 6.867007f) {
                    if (features[12] < 7.935221f) {
                        return -0.000161f;
                    } else {
                        return -0.038577f;
                    }
                } else {
                    if (features[8] < 2.464921f) {
                        return 0.039883f;
                    } else {
                        return -0.035997f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_104(const float* features) {
        if (features[0] < 0.602645f) {
            if (features[9] < 107.164749f) {
                if (features[8] < -36.020836f) {
                    if (features[0] < 0.447848f) {
                        return 0.016502f;
                    } else {
                        return -0.001197f;
                    }
                } else {
                    if (features[0] < 0.456542f) {
                        return -0.002329f;
                    } else {
                        return -0.024433f;
                    }
                }
            } else {
                if (features[6] < 73.504799f) {
                    if (features[0] < 0.459414f) {
                        return 0.016588f;
                    } else {
                        return -0.006245f;
                    }
                } else {
                    if (features[8] < -38.367355f) {
                        return 0.033424f;
                    } else {
                        return 0.020185f;
                    }
                }
            }
        } else {
            if (features[8] < -32.079453f) {
                if (features[0] < 0.720622f) {
                    if (features[5] < 32.869999f) {
                        return -0.011203f;
                    } else {
                        return 0.015015f;
                    }
                } else {
                    if (features[8] < -46.397450f) {
                        return -0.008571f;
                    } else {
                        return -0.034490f;
                    }
                }
            } else {
                if (features[11] < -76.410004f) {
                    if (features[0] < 0.657505f) {
                        return 0.078562f;
                    } else {
                        return -0.030939f;
                    }
                } else {
                    if (features[7] < 82.837090f) {
                        return -0.041969f;
                    } else {
                        return -0.030941f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_105(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.254273f) {
                if (features[0] < 0.476928f) {
                    if (features[4] < 0.400000f) {
                        return -0.017931f;
                    } else {
                        return -0.003177f;
                    }
                } else {
                    if (features[8] < -49.948929f) {
                        return -0.005999f;
                    } else {
                        return 0.018069f;
                    }
                }
            } else {
                if (features[0] < 0.859119f) {
                    if (features[8] < -27.733391f) {
                        return 0.023163f;
                    } else {
                        return 0.004089f;
                    }
                } else {
                    if (features[9] < 68.913864f) {
                        return -0.036805f;
                    } else {
                        return -0.001150f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 9.305356f) {
                    if (features[12] < -9.196494f) {
                        return -0.035430f;
                    } else {
                        return -0.012391f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.020998f;
                    } else {
                        return -0.036166f;
                    }
                }
            } else {
                if (features[9] < 72.449219f) {
                    if (features[8] < 9.294910f) {
                        return -0.040225f;
                    } else {
                        return -0.005345f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.031456f;
                    } else {
                        return 0.011354f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_106(const float* features) {
        if (features[8] < -34.241722f) {
            if (features[4] < 3.764467f) {
                if (features[9] < 86.727104f) {
                    if (features[12] < -5.817526f) {
                        return 0.006101f;
                    } else {
                        return -0.024949f;
                    }
                } else {
                    if (features[4] < 2.836606f) {
                        return -0.037649f;
                    } else {
                        return -0.023025f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[12] < -0.807765f) {
                        return 0.036707f;
                    } else {
                        return 0.001248f;
                    }
                } else {
                    if (features[9] < 60.447125f) {
                        return 0.032745f;
                    } else {
                        return -0.035295f;
                    }
                }
            }
        } else {
            if (features[8] < -8.364439f) {
                if (features[9] < 113.426125f) {
                    if (features[4] < 0.400000f) {
                        return -0.044048f;
                    } else {
                        return 0.024128f;
                    }
                } else {
                    if (features[4] < 3.004038f) {
                        return -0.027450f;
                    } else {
                        return 0.012442f;
                    }
                }
            } else {
                if (features[12] < 12.347901f) {
                    if (features[9] < 58.808765f) {
                        return -0.039865f;
                    } else {
                        return -0.003281f;
                    }
                } else {
                    if (features[12] < 34.158642f) {
                        return 0.026442f;
                    } else {
                        return -0.026943f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_107(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -25.221086f) {
                if (features[8] < -37.965397f) {
                    return -0.040296f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.072587f;
                    } else {
                        return -0.037844f;
                    }
                }
            } else {
                if (features[4] < 8.068044f) {
                    if (features[8] < -19.934113f) {
                        return -0.040183f;
                    } else {
                        return -0.018396f;
                    }
                } else {
                    if (features[7] < 29.923719f) {
                        return 0.032557f;
                    } else {
                        return -0.025385f;
                    }
                }
            }
        } else {
            if (features[7] < 67.691116f) {
                if (features[12] < 13.492349f) {
                    if (features[7] < 36.972729f) {
                        return 0.046842f;
                    } else {
                        return 0.027082f;
                    }
                } else {
                    if (features[0] < 0.774887f) {
                        return -0.030171f;
                    } else {
                        return 0.026528f;
                    }
                }
            } else {
                if (features[0] < 0.962186f) {
                    if (features[7] < 80.903244f) {
                        return -0.017416f;
                    } else {
                        return -0.041608f;
                    }
                } else {
                    if (features[8] < -10.363048f) {
                        return -0.032438f;
                    } else {
                        return 0.058048f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_108(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[8] < -36.921341f) {
                if (features[9] < 93.905449f) {
                    if (features[0] < 0.220000f) {
                        return 0.026439f;
                    } else {
                        return 0.006488f;
                    }
                } else {
                    if (features[8] < -47.446758f) {
                        return 0.031909f;
                    } else {
                        return 0.018403f;
                    }
                }
            } else {
                if (features[9] < 107.164749f) {
                    if (features[12] < 4.413506f) {
                        return -0.018055f;
                    } else {
                        return 0.004730f;
                    }
                } else {
                    if (features[0] < 0.433287f) {
                        return 0.019388f;
                    } else {
                        return -0.001763f;
                    }
                }
            }
        } else {
            if (features[8] < -42.629635f) {
                if (features[0] < 1.000000f) {
                    if (features[0] < 0.792771f) {
                        return -0.003054f;
                    } else {
                        return -0.035682f;
                    }
                } else {
                    if (features[10] < -39.631782f) {
                        return -0.023917f;
                    } else {
                        return 0.053898f;
                    }
                }
            } else {
                if (features[7] < 105.312714f) {
                    if (features[0] < 0.689149f) {
                        return -0.026559f;
                    } else {
                        return -0.040732f;
                    }
                } else {
                    if (features[5] < 31.328301f) {
                        return -0.028163f;
                    } else {
                        return -0.001283f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_109(const float* features) {
        if (features[4] < 3.712480f) {
            if (features[4] < 1.867067f) {
                if (features[4] < 0.149881f) {
                    if (features[8] < -41.285187f) {
                        return -0.031938f;
                    } else {
                        return -0.001700f;
                    }
                } else {
                    if (features[9] < 150.050537f) {
                        return 0.005977f;
                    } else {
                        return -0.008086f;
                    }
                }
            } else {
                if (features[9] < 60.447125f) {
                    if (features[8] < -32.964340f) {
                        return 0.014342f;
                    } else {
                        return -0.016910f;
                    }
                } else {
                    if (features[8] < -27.733391f) {
                        return 0.029427f;
                    } else {
                        return 0.010506f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.192201f) {
                    if (features[12] < -7.776650f) {
                        return -0.030916f;
                    } else {
                        return -0.013144f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.010527f;
                    } else {
                        return -0.035856f;
                    }
                }
            } else {
                if (features[9] < 72.449219f) {
                    if (features[12] < 11.994812f) {
                        return -0.040051f;
                    } else {
                        return -0.027915f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return -0.027897f;
                    } else {
                        return 0.016746f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_110(const float* features) {
        if (features[0] < 0.563239f) {
            if (features[8] < -31.808825f) {
                if (features[9] < 62.805889f) {
                    if (features[6] < 66.787498f) {
                        return 0.028362f;
                    } else {
                        return -0.016736f;
                    }
                } else {
                    if (features[12] < 1.047316f) {
                        return -0.029857f;
                    } else {
                        return -0.044227f;
                    }
                }
            } else {
                if (features[12] < 11.994812f) {
                    if (features[9] < 125.640701f) {
                        return 0.014792f;
                    } else {
                        return -0.031715f;
                    }
                } else {
                    if (features[6] < 66.103500f) {
                        return -0.001038f;
                    } else {
                        return -0.035925f;
                    }
                }
            }
        } else {
            if (features[8] < -9.279342f) {
                if (features[8] < -42.038635f) {
                    if (features[12] < -10.698044f) {
                        return 0.009226f;
                    } else {
                        return -0.027138f;
                    }
                } else {
                    if (features[9] < 83.752045f) {
                        return 0.028147f;
                    } else {
                        return 0.007405f;
                    }
                }
            } else {
                if (features[12] < 13.492349f) {
                    if (features[7] < 58.294384f) {
                        return -0.040240f;
                    } else {
                        return 0.007921f;
                    }
                } else {
                    if (features[11] < -55.646774f) {
                        return -0.040569f;
                    } else {
                        return 0.022156f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_111(const float* features) {
        if (features[9] < 39.707916f) {
            if (features[9] < 33.471188f) {
                if (features[11] < -18.819571f) {
                    if (features[4] < 2.480896f) {
                        return -0.013492f;
                    } else {
                        return 0.036282f;
                    }
                } else {
                    if (features[9] < 23.626583f) {
                        return 0.046599f;
                    } else {
                        return 0.037309f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[10] < -26.284296f) {
                        return -0.039786f;
                    } else {
                        return 0.013897f;
                    }
                } else {
                    if (features[11] < -39.977287f) {
                        return -0.011050f;
                    } else {
                        return 0.055722f;
                    }
                }
            }
        } else {
            if (features[0] < 0.766519f) {
                if (features[4] < 11.305647f) {
                    if (features[10] < -9.073926f) {
                        return -0.040225f;
                    } else {
                        return -0.028847f;
                    }
                } else {
                    if (features[11] < 19.884397f) {
                        return -0.026361f;
                    } else {
                        return 0.041289f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[10] < -26.340010f) {
                        return -0.041140f;
                    } else {
                        return -0.009776f;
                    }
                } else {
                    if (features[9] < 88.734299f) {
                        return 0.038991f;
                    } else {
                        return -0.040580f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_112(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[4] < 1.927128f) {
                if (features[0] < 0.220000f) {
                    if (features[6] < 77.853996f) {
                        return 0.024449f;
                    } else {
                        return 0.040190f;
                    }
                } else {
                    if (features[0] < 0.220345f) {
                        return -0.024910f;
                    } else {
                        return 0.016664f;
                    }
                }
            } else {
                if (features[4] < 3.654021f) {
                    if (features[0] < 0.246910f) {
                        return 0.001544f;
                    } else {
                        return -0.031729f;
                    }
                } else {
                    if (features[9] < 74.929031f) {
                        return -0.017997f;
                    } else {
                        return 0.019666f;
                    }
                }
            }
        } else {
            if (features[4] < 1.054752f) {
                if (features[0] < 0.968604f) {
                    if (features[0] < 0.716383f) {
                        return 0.007176f;
                    } else {
                        return -0.027526f;
                    }
                } else {
                    if (features[10] < -23.863565f) {
                        return 0.077935f;
                    } else {
                        return -0.013362f;
                    }
                }
            } else {
                if (features[0] < 0.697237f) {
                    if (features[9] < 174.369415f) {
                        return -0.024455f;
                    } else {
                        return 0.030114f;
                    }
                } else {
                    if (features[9] < 110.258118f) {
                        return -0.040342f;
                    } else {
                        return -0.024291f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_113(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.927128f) {
                if (features[4] < 0.246010f) {
                    if (features[8] < -39.455936f) {
                        return -0.025280f;
                    } else {
                        return 0.000683f;
                    }
                } else {
                    if (features[9] < 45.711044f) {
                        return -0.017497f;
                    } else {
                        return 0.004796f;
                    }
                }
            } else {
                if (features[8] < -27.733391f) {
                    if (features[9] < 52.675392f) {
                        return -0.000152f;
                    } else {
                        return 0.027553f;
                    }
                } else {
                    if (features[12] < 9.358112f) {
                        return -0.020433f;
                    } else {
                        return 0.033940f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.450968f) {
                    if (features[12] < -7.776650f) {
                        return -0.032530f;
                    } else {
                        return -0.013172f;
                    }
                } else {
                    if (features[12] < -2.313942f) {
                        return -0.009004f;
                    } else {
                        return 0.020547f;
                    }
                }
            } else {
                if (features[9] < 81.853035f) {
                    if (features[11] < -46.189808f) {
                        return -0.015504f;
                    } else {
                        return -0.039392f;
                    }
                } else {
                    if (features[4] < 7.748848f) {
                        return -0.032416f;
                    } else {
                        return 0.014524f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_114(const float* features) {
        if (features[0] < 0.642864f) {
            if (features[8] < -28.760742f) {
                if (features[9] < 93.010498f) {
                    if (features[12] < -1.710238f) {
                        return 0.002614f;
                    } else {
                        return -0.023004f;
                    }
                } else {
                    if (features[9] < 133.908447f) {
                        return -0.032304f;
                    } else {
                        return -0.042506f;
                    }
                }
            } else {
                if (features[12] < 11.994812f) {
                    if (features[8] < -8.364439f) {
                        return 0.022440f;
                    } else {
                        return -0.028419f;
                    }
                } else {
                    if (features[9] < 77.765427f) {
                        return -0.009664f;
                    } else {
                        return -0.033603f;
                    }
                }
            }
        } else {
            if (features[8] < -14.335972f) {
                if (features[9] < 83.752045f) {
                    if (features[0] < 0.826246f) {
                        return 0.022106f;
                    } else {
                        return 0.040195f;
                    }
                } else {
                    if (features[8] < -42.629635f) {
                        return -0.022120f;
                    } else {
                        return 0.012925f;
                    }
                }
            } else {
                if (features[12] < 7.248966f) {
                    if (features[9] < 41.545544f) {
                        return -0.039841f;
                    } else {
                        return -0.004684f;
                    }
                } else {
                    if (features[11] < -55.646774f) {
                        return -0.028984f;
                    } else {
                        return 0.022815f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_115(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[0] < 0.754269f) {
                if (features[4] < 14.148499f) {
                    if (features[12] < -34.099476f) {
                        return -0.013384f;
                    } else {
                        return -0.041041f;
                    }
                } else {
                    if (features[0] < 0.661144f) {
                        return -0.022041f;
                    } else {
                        return 0.048017f;
                    }
                }
            } else {
                if (features[12] < -25.221086f) {
                    if (features[7] < 75.180084f) {
                        return -0.035243f;
                    } else {
                        return 0.065717f;
                    }
                } else {
                    if (features[9] < 29.557575f) {
                        return 0.052012f;
                    } else {
                        return -0.025593f;
                    }
                }
            }
        } else {
            if (features[12] < 7.248966f) {
                if (features[8] < 4.928890f) {
                    if (features[7] < 82.335472f) {
                        return 0.045218f;
                    } else {
                        return -0.020896f;
                    }
                } else {
                    if (features[7] < 14.227375f) {
                        return 0.032223f;
                    } else {
                        return -0.047193f;
                    }
                }
            } else {
                if (features[7] < 40.311138f) {
                    if (features[4] < 7.331466f) {
                        return 0.003093f;
                    } else {
                        return 0.044686f;
                    }
                } else {
                    if (features[4] < 9.305356f) {
                        return -0.041223f;
                    } else {
                        return 0.014924f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_116(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[4] < 1.867067f) {
                if (features[6] < 83.356598f) {
                    if (features[4] < 1.370346f) {
                        return 0.012028f;
                    } else {
                        return -0.023217f;
                    }
                } else {
                    if (features[4] < 1.543872f) {
                        return 0.020978f;
                    } else {
                        return 0.046735f;
                    }
                }
            } else {
                if (features[4] < 3.654021f) {
                    if (features[8] < -45.028492f) {
                        return 0.000274f;
                    } else {
                        return -0.032037f;
                    }
                } else {
                    if (features[8] < -33.079437f) {
                        return 0.020577f;
                    } else {
                        return -0.013680f;
                    }
                }
            }
        } else {
            if (features[4] < 0.957507f) {
                if (features[0] < 0.982828f) {
                    if (features[0] < 0.716383f) {
                        return 0.007014f;
                    } else {
                        return -0.020076f;
                    }
                } else {
                    if (features[8] < -42.629635f) {
                        return 0.082829f;
                    } else {
                        return 0.017086f;
                    }
                }
            } else {
                if (features[8] < -32.852593f) {
                    if (features[4] < 7.331466f) {
                        return -0.030175f;
                    } else {
                        return -0.003367f;
                    }
                } else {
                    if (features[4] < 1.054752f) {
                        return -0.002582f;
                    } else {
                        return -0.040614f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_117(const float* features) {
        if (features[9] < 45.711044f) {
            if (features[0] < 0.731283f) {
                if (features[11] < -17.242056f) {
                    if (features[12] < 9.132126f) {
                        return -0.004864f;
                    } else {
                        return 0.024095f;
                    }
                } else {
                    if (features[8] < -34.941708f) {
                        return 0.020339f;
                    } else {
                        return -0.030312f;
                    }
                }
            } else {
                if (features[8] < -22.515675f) {
                    if (features[12] < 13.943329f) {
                        return -0.032568f;
                    } else {
                        return 0.041980f;
                    }
                } else {
                    if (features[7] < 42.485451f) {
                        return -0.041313f;
                    } else {
                        return -0.002403f;
                    }
                }
            }
        } else {
            if (features[0] < 0.885088f) {
                if (features[0] < 0.320042f) {
                    if (features[8] < -45.201443f) {
                        return -0.010836f;
                    } else {
                        return 0.002522f;
                    }
                } else {
                    if (features[8] < -26.821964f) {
                        return 0.011326f;
                    } else {
                        return 0.000054f;
                    }
                }
            } else {
                if (features[8] < -47.446758f) {
                    if (features[5] < 29.811600f) {
                        return -0.014058f;
                    } else {
                        return 0.037014f;
                    }
                } else {
                    if (features[9] < 119.811668f) {
                        return -0.026560f;
                    } else {
                        return 0.009224f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_118(const float* features) {
        if (features[0] < 0.619183f) {
            if (features[8] < -28.760742f) {
                if (features[9] < 62.805889f) {
                    if (features[4] < 3.712480f) {
                        return -0.011122f;
                    } else {
                        return 0.028690f;
                    }
                } else {
                    if (features[4] < 3.385558f) {
                        return -0.034276f;
                    } else {
                        return -0.015078f;
                    }
                }
            } else {
                if (features[12] < 11.994812f) {
                    if (features[8] < -8.364439f) {
                        return 0.021905f;
                    } else {
                        return -0.030117f;
                    }
                } else {
                    if (features[6] < 73.669296f) {
                        return -0.001369f;
                    } else {
                        return -0.031692f;
                    }
                }
            }
        } else {
            if (features[9] < 29.557575f) {
                if (features[4] < 2.264338f) {
                    if (features[12] < 2.800243f) {
                        return 0.008568f;
                    } else {
                        return 0.071669f;
                    }
                } else {
                    if (features[8] < -17.408821f) {
                        return 0.002600f;
                    } else {
                        return -0.035635f;
                    }
                }
            } else {
                if (features[8] < -36.769554f) {
                    if (features[4] < 2.298678f) {
                        return -0.021795f;
                    } else {
                        return 0.008992f;
                    }
                } else {
                    if (features[4] < 0.795667f) {
                        return -0.024540f;
                    } else {
                        return 0.026321f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_119(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -25.221086f) {
                if (features[8] < -37.965397f) {
                    return -0.039825f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.072381f;
                    } else {
                        return -0.037174f;
                    }
                }
            } else {
                if (features[4] < 9.305356f) {
                    if (features[0] < 0.754269f) {
                        return -0.041001f;
                    } else {
                        return -0.030929f;
                    }
                } else {
                    if (features[0] < 0.716383f) {
                        return -0.037367f;
                    } else {
                        return 0.014651f;
                    }
                }
            }
        } else {
            if (features[7] < 36.972729f) {
                if (features[12] < 7.248966f) {
                    if (features[8] < 9.294910f) {
                        return 0.045059f;
                    } else {
                        return -0.026207f;
                    }
                } else {
                    if (features[8] < -7.445725f) {
                        return -0.012170f;
                    } else {
                        return 0.033443f;
                    }
                }
            } else {
                if (features[4] < 4.130574f) {
                    if (features[11] < 28.662636f) {
                        return -0.035111f;
                    } else {
                        return 0.021239f;
                    }
                } else {
                    if (features[8] < 2.464921f) {
                        return 0.025229f;
                    } else {
                        return -0.039617f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_120(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[9] < 106.620445f) {
                if (features[4] < 1.895638f) {
                    if (features[0] < 0.220000f) {
                        return 0.030019f;
                    } else {
                        return 0.003669f;
                    }
                } else {
                    if (features[4] < 3.192151f) {
                        return -0.037195f;
                    } else {
                        return -0.005500f;
                    }
                }
            } else {
                if (features[6] < 85.961403f) {
                    if (features[4] < 1.427372f) {
                        return 0.020920f;
                    } else {
                        return -0.000301f;
                    }
                } else {
                    if (features[4] < 2.264338f) {
                        return 0.035724f;
                    } else {
                        return 0.004125f;
                    }
                }
            }
        } else {
            if (features[4] < 1.524967f) {
                if (features[8] < -43.954227f) {
                    if (features[0] < 1.000000f) {
                        return 0.000905f;
                    } else {
                        return 0.071534f;
                    }
                } else {
                    if (features[6] < 87.908302f) {
                        return -0.024200f;
                    } else {
                        return 0.009008f;
                    }
                }
            } else {
                if (features[8] < -42.629635f) {
                    if (features[12] < 8.613287f) {
                        return -0.020881f;
                    } else {
                        return 0.072293f;
                    }
                } else {
                    if (features[9] < 125.640701f) {
                        return -0.039994f;
                    } else {
                        return -0.016731f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_121(const float* features) {
        if (features[4] < 3.963336f) {
            if (features[4] < 1.974356f) {
                if (features[0] < 0.441691f) {
                    if (features[4] < 0.246010f) {
                        return -0.023424f;
                    } else {
                        return -0.002225f;
                    }
                } else {
                    if (features[0] < 0.859119f) {
                        return 0.014106f;
                    } else {
                        return -0.007671f;
                    }
                }
            } else {
                if (features[0] < 0.635327f) {
                    if (features[4] < 3.109267f) {
                        return 0.033881f;
                    } else {
                        return 0.017860f;
                    }
                } else {
                    if (features[9] < 85.879204f) {
                        return -0.009534f;
                    } else {
                        return 0.021236f;
                    }
                }
            }
        } else {
            if (features[9] < 53.914539f) {
                if (features[0] < 0.673074f) {
                    if (features[4] < 7.648993f) {
                        return -0.032596f;
                    } else {
                        return 0.008007f;
                    }
                } else {
                    if (features[11] < -58.817574f) {
                        return -0.015167f;
                    } else {
                        return -0.040299f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[5] < 34.719700f) {
                        return -0.019177f;
                    } else {
                        return 0.017563f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.016644f;
                    } else {
                        return -0.039942f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_122(const float* features) {
        if (features[8] < -38.221569f) {
            if (features[4] < 3.421923f) {
                if (features[9] < 49.106506f) {
                    if (features[12] < 0.495753f) {
                        return 0.035852f;
                    } else {
                        return -0.037258f;
                    }
                } else {
                    if (features[8] < -42.325005f) {
                        return -0.037315f;
                    } else {
                        return -0.023886f;
                    }
                }
            } else {
                if (features[7] < 106.623741f) {
                    if (features[4] < 8.192201f) {
                        return 0.017349f;
                    } else {
                        return -0.031887f;
                    }
                } else {
                    if (features[6] < 55.259701f) {
                        return 0.037172f;
                    } else {
                        return -0.038640f;
                    }
                }
            }
        } else {
            if (features[8] < -7.445725f) {
                if (features[9] < 83.752045f) {
                    if (features[4] < 0.400000f) {
                        return -0.044589f;
                    } else {
                        return 0.021736f;
                    }
                } else {
                    if (features[4] < 3.712480f) {
                        return -0.015332f;
                    } else {
                        return 0.016087f;
                    }
                }
            } else {
                if (features[12] < 14.932377f) {
                    if (features[7] < 62.940784f) {
                        return -0.039337f;
                    } else {
                        return -0.006738f;
                    }
                } else {
                    if (features[12] < 34.158642f) {
                        return 0.031177f;
                    } else {
                        return -0.026429f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_123(const float* features) {
        if (features[8] < -17.408821f) {
            if (features[12] < -30.397575f) {
                if (features[11] < 27.816441f) {
                    return -0.038269f;
                } else {
                    if (features[9] < 85.425072f) {
                        return 0.056801f;
                    } else {
                        return -0.033315f;
                    }
                }
            } else {
                if (features[0] < 0.811343f) {
                    if (features[9] < 32.271271f) {
                        return -0.008122f;
                    } else {
                        return -0.040502f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.027833f;
                    } else {
                        return 0.013973f;
                    }
                }
            }
        } else {
            if (features[12] < 7.248966f) {
                if (features[9] < 78.590889f) {
                    if (features[8] < 4.928890f) {
                        return 0.042994f;
                    } else {
                        return -0.017044f;
                    }
                } else {
                    if (features[11] < 40.793491f) {
                        return -0.030028f;
                    } else {
                        return 0.042815f;
                    }
                }
            } else {
                if (features[4] < 8.450968f) {
                    if (features[9] < 12.212687f) {
                        return 0.043632f;
                    } else {
                        return -0.031746f;
                    }
                } else {
                    if (features[0] < 0.592166f) {
                        return -0.043703f;
                    } else {
                        return 0.042336f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_124(const float* features) {
        if (features[0] < 0.592166f) {
            if (features[8] < -36.921341f) {
                if (features[9] < 93.905449f) {
                    if (features[4] < 1.254273f) {
                        return 0.014992f;
                    } else {
                        return -0.002884f;
                    }
                } else {
                    if (features[8] < -47.446758f) {
                        return 0.031651f;
                    } else {
                        return 0.016910f;
                    }
                }
            } else {
                if (features[4] < 0.400000f) {
                    if (features[6] < 81.435898f) {
                        return 0.016450f;
                    } else {
                        return 0.047015f;
                    }
                } else {
                    if (features[4] < 0.410878f) {
                        return -0.038404f;
                    } else {
                        return -0.000337f;
                    }
                }
            }
        } else {
            if (features[4] < 1.565724f) {
                if (features[9] < 83.752045f) {
                    if (features[4] < 0.683138f) {
                        return -0.005689f;
                    } else {
                        return -0.029560f;
                    }
                } else {
                    if (features[6] < 70.829002f) {
                        return -0.022709f;
                    } else {
                        return 0.009564f;
                    }
                }
            } else {
                if (features[9] < 94.787773f) {
                    if (features[8] < -38.221569f) {
                        return -0.026599f;
                    } else {
                        return -0.040715f;
                    }
                } else {
                    if (features[4] < 8.812652f) {
                        return -0.026130f;
                    } else {
                        return 0.015815f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_125(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.867067f) {
                if (features[0] < 0.441691f) {
                    if (features[6] < 74.875801f) {
                        return 0.007946f;
                    } else {
                        return -0.011024f;
                    }
                } else {
                    if (features[0] < 0.950064f) {
                        return 0.012500f;
                    } else {
                        return -0.020719f;
                    }
                }
            } else {
                if (features[0] < 0.731283f) {
                    if (features[8] < -27.366392f) {
                        return 0.028388f;
                    } else {
                        return 0.006708f;
                    }
                } else {
                    if (features[7] < 76.821541f) {
                        return -0.016577f;
                    } else {
                        return 0.020265f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[12] < -7.776650f) {
                        return -0.029569f;
                    } else {
                        return -0.010398f;
                    }
                } else {
                    if (features[12] < -2.313942f) {
                        return -0.008775f;
                    } else {
                        return 0.023243f;
                    }
                }
            } else {
                if (features[7] < 94.130890f) {
                    if (features[12] < 9.358112f) {
                        return -0.037519f;
                    } else {
                        return -0.019484f;
                    }
                } else {
                    if (features[0] < 0.705297f) {
                        return 0.010185f;
                    } else {
                        return -0.025912f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_126(const float* features) {
        if (features[0] < 0.471007f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.042693f;
                    } else {
                        return -0.017885f;
                    }
                } else {
                    if (features[8] < -38.093536f) {
                        return -0.016931f;
                    } else {
                        return 0.037084f;
                    }
                }
            } else {
                if (features[0] < 0.398692f) {
                    if (features[0] < 0.337552f) {
                        return -0.043410f;
                    } else {
                        return -0.033339f;
                    }
                } else {
                    if (features[4] < 2.541310f) {
                        return -0.031386f;
                    } else {
                        return 0.004987f;
                    }
                }
            }
        } else {
            if (features[4] < 1.209616f) {
                if (features[8] < -28.050787f) {
                    if (features[9] < 55.031353f) {
                        return 0.006593f;
                    } else {
                        return -0.035779f;
                    }
                } else {
                    if (features[4] < 0.409576f) {
                        return -0.037297f;
                    } else {
                        return 0.014867f;
                    }
                }
            } else {
                if (features[4] < 8.450968f) {
                    if (features[9] < 107.164749f) {
                        return 0.021551f;
                    } else {
                        return -0.007089f;
                    }
                } else {
                    if (features[9] < 34.864788f) {
                        return -0.041165f;
                    } else {
                        return -0.011528f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_127(const float* features) {
        if (features[8] < -18.441996f) {
            if (features[12] < -25.221086f) {
                if (features[8] < -37.965397f) {
                    return -0.039412f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.065274f;
                    } else {
                        return -0.034316f;
                    }
                }
            } else {
                if (features[4] < 9.522261f) {
                    if (features[0] < 0.754269f) {
                        return -0.040667f;
                    } else {
                        return -0.029072f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return 0.013547f;
                    } else {
                        return -0.036326f;
                    }
                }
            }
        } else {
            if (features[7] < 36.972729f) {
                if (features[12] < 13.492349f) {
                    if (features[12] < 6.058572f) {
                        return 0.044060f;
                    } else {
                        return 0.028046f;
                    }
                } else {
                    if (features[0] < 0.645642f) {
                        return -0.038662f;
                    } else {
                        return 0.024340f;
                    }
                }
            } else {
                if (features[4] < 4.130574f) {
                    if (features[11] < 28.662636f) {
                        return -0.033972f;
                    } else {
                        return 0.023996f;
                    }
                } else {
                    if (features[0] < 0.631200f) {
                        return -0.029211f;
                    } else {
                        return 0.027051f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_128(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[8] < -41.056179f) {
                if (features[7] < 72.180710f) {
                    if (features[4] < 0.149881f) {
                        return 0.045829f;
                    } else {
                        return 0.006104f;
                    }
                } else {
                    if (features[12] < -15.741932f) {
                        return 0.005944f;
                    } else {
                        return 0.025002f;
                    }
                }
            } else {
                if (features[4] < 1.506792f) {
                    if (features[0] < 0.220345f) {
                        return -0.004386f;
                    } else {
                        return 0.014190f;
                    }
                } else {
                    if (features[0] < 0.277815f) {
                        return 0.016113f;
                    } else {
                        return -0.018680f;
                    }
                }
            }
        } else {
            if (features[4] < 1.224071f) {
                if (features[11] < -33.566009f) {
                    if (features[12] < -1.294214f) {
                        return 0.006214f;
                    } else {
                        return 0.068219f;
                    }
                } else {
                    if (features[8] < -45.201443f) {
                        return 0.016303f;
                    } else {
                        return -0.016389f;
                    }
                }
            } else {
                if (features[8] < -32.852593f) {
                    if (features[4] < 7.331466f) {
                        return -0.028496f;
                    } else {
                        return -0.000354f;
                    }
                } else {
                    if (features[7] < 118.677025f) {
                        return -0.041592f;
                    } else {
                        return -0.024821f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_129(const float* features) {
        if (features[4] < 3.712480f) {
            if (features[4] < 1.974356f) {
                if (features[0] < 0.360786f) {
                    if (features[4] < 0.366643f) {
                        return -0.019087f;
                    } else {
                        return -0.002420f;
                    }
                } else {
                    if (features[7] < 198.148407f) {
                        return 0.010286f;
                    } else {
                        return -0.018427f;
                    }
                }
            } else {
                if (features[0] < 0.642864f) {
                    if (features[4] < 3.385558f) {
                        return 0.031595f;
                    } else {
                        return 0.009934f;
                    }
                } else {
                    if (features[9] < 59.967148f) {
                        return -0.021196f;
                    } else {
                        return 0.007790f;
                    }
                }
            }
        } else {
            if (features[9] < 67.016052f) {
                if (features[0] < 0.624089f) {
                    if (features[4] < 8.192201f) {
                        return -0.019876f;
                    } else {
                        return 0.023854f;
                    }
                } else {
                    if (features[11] < -14.437303f) {
                        return -0.022440f;
                    } else {
                        return -0.040740f;
                    }
                }
            } else {
                if (features[4] < 8.812652f) {
                    if (features[5] < 34.651501f) {
                        return -0.014775f;
                    } else {
                        return 0.018321f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.019869f;
                    } else {
                        return -0.039109f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_130(const float* features) {
        if (features[0] < 0.465420f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.042450f;
                    } else {
                        return -0.004661f;
                    }
                } else {
                    if (features[9] < 88.347015f) {
                        return 0.035610f;
                    } else {
                        return -0.009064f;
                    }
                }
            } else {
                if (features[0] < 0.414259f) {
                    if (features[0] < 0.370829f) {
                        return -0.042277f;
                    } else {
                        return -0.027970f;
                    }
                } else {
                    if (features[4] < 1.392679f) {
                        return -0.037514f;
                    } else {
                        return -0.000742f;
                    }
                }
            }
        } else {
            if (features[4] < 1.020314f) {
                if (features[4] < 0.732578f) {
                    if (features[6] < 64.157204f) {
                        return -0.010452f;
                    } else {
                        return -0.042806f;
                    }
                } else {
                    if (features[0] < 0.770455f) {
                        return -0.024149f;
                    } else {
                        return 0.018011f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[9] < 89.328476f) {
                        return 0.020976f;
                    } else {
                        return -0.001370f;
                    }
                } else {
                    if (features[9] < 40.606697f) {
                        return -0.039624f;
                    } else {
                        return -0.007966f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_131(const float* features) {
        if (features[8] < -18.441996f) {
            if (features[12] < -27.232882f) {
                if (features[8] < -37.965397f) {
                    return -0.038923f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.062490f;
                    } else {
                        return -0.035816f;
                    }
                }
            } else {
                if (features[0] < 0.766519f) {
                    if (features[4] < 14.487167f) {
                        return -0.040668f;
                    } else {
                        return 0.019665f;
                    }
                } else {
                    if (features[8] < -37.882805f) {
                        return -0.000098f;
                    } else {
                        return -0.031000f;
                    }
                }
            }
        } else {
            if (features[7] < 37.622398f) {
                if (features[12] < 6.058572f) {
                    if (features[8] < 2.464921f) {
                        return 0.043588f;
                    } else {
                        return 0.009446f;
                    }
                } else {
                    if (features[8] < -12.451389f) {
                        return -0.031812f;
                    } else {
                        return 0.029507f;
                    }
                }
            } else {
                if (features[4] < 6.867007f) {
                    if (features[12] < -0.516902f) {
                        return 0.031845f;
                    } else {
                        return -0.025048f;
                    }
                } else {
                    if (features[10] < 9.069347f) {
                        return 0.030000f;
                    } else {
                        return -0.053408f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_132(const float* features) {
        if (features[0] < 0.681520f) {
            if (features[8] < -27.896215f) {
                if (features[4] < 1.427372f) {
                    if (features[4] < 0.223583f) {
                        return 0.032435f;
                    } else {
                        return 0.012026f;
                    }
                } else {
                    if (features[4] < 4.350451f) {
                        return -0.008969f;
                    } else {
                        return 0.016582f;
                    }
                }
            } else {
                if (features[12] < 11.994812f) {
                    if (features[0] < 0.220000f) {
                        return 0.027363f;
                    } else {
                        return -0.029480f;
                    }
                } else {
                    if (features[9] < 107.164749f) {
                        return -0.003156f;
                    } else {
                        return 0.024896f;
                    }
                }
            }
        } else {
            if (features[4] < 0.844081f) {
                if (features[0] < 0.950064f) {
                    if (features[7] < 75.180084f) {
                        return -0.032603f;
                    } else {
                        return 0.005134f;
                    }
                } else {
                    if (features[8] < -42.629635f) {
                        return 0.073919f;
                    } else {
                        return 0.008010f;
                    }
                }
            } else {
                if (features[9] < 87.193474f) {
                    if (features[0] < 0.689149f) {
                        return -0.012114f;
                    } else {
                        return -0.039833f;
                    }
                } else {
                    if (features[8] < -33.079437f) {
                        return -0.016329f;
                    } else {
                        return -0.037413f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_133(const float* features) {
        if (features[4] < 3.827744f) {
            if (features[4] < 1.081871f) {
                if (features[4] < 0.066629f) {
                    if (features[6] < 64.838097f) {
                        return 0.001864f;
                    } else {
                        return -0.028300f;
                    }
                } else {
                    if (features[4] < 0.415711f) {
                        return 0.008466f;
                    } else {
                        return -0.002230f;
                    }
                }
            } else {
                if (features[9] < 43.121307f) {
                    if (features[11] < -18.819571f) {
                        return 0.006419f;
                    } else {
                        return -0.031137f;
                    }
                } else {
                    if (features[5] < 28.200501f) {
                        return 0.002967f;
                    } else {
                        return 0.017594f;
                    }
                }
            }
        } else {
            if (features[9] < 50.309807f) {
                if (features[8] < -35.081638f) {
                    if (features[5] < 34.029701f) {
                        return -0.017803f;
                    } else {
                        return 0.041491f;
                    }
                } else {
                    if (features[11] < -18.223438f) {
                        return -0.027551f;
                    } else {
                        return -0.041150f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[12] < 5.663101f) {
                        return -0.020674f;
                    } else {
                        return -0.000493f;
                    }
                } else {
                    if (features[4] < 13.116750f) {
                        return 0.010887f;
                    } else {
                        return -0.039071f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_134(const float* features) {
        if (features[0] < 0.465420f) {
            if (features[4] < 0.400538f) {
                if (features[4] < 0.400000f) {
                    if (features[0] < 0.459414f) {
                        return -0.042356f;
                    } else {
                        return -0.001420f;
                    }
                } else {
                    if (features[8] < -42.325005f) {
                        return -0.029473f;
                    } else {
                        return 0.027258f;
                    }
                }
            } else {
                if (features[0] < 0.424671f) {
                    if (features[4] < 4.196662f) {
                        return -0.040874f;
                    } else {
                        return -0.022157f;
                    }
                } else {
                    if (features[8] < -26.176405f) {
                        return -0.019485f;
                    } else {
                        return 0.027595f;
                    }
                }
            }
        } else {
            if (features[4] < 0.957507f) {
                if (features[6] < 64.157204f) {
                    if (features[9] < 74.585480f) {
                        return 0.033277f;
                    } else {
                        return -0.022218f;
                    }
                } else {
                    if (features[8] < -24.623827f) {
                        return -0.041240f;
                    } else {
                        return -0.001668f;
                    }
                }
            } else {
                if (features[4] < 8.192201f) {
                    if (features[4] < 3.712480f) {
                        return 0.004311f;
                    } else {
                        return 0.026029f;
                    }
                } else {
                    if (features[9] < 34.864788f) {
                        return -0.041788f;
                    } else {
                        return -0.010456f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_135(const float* features) {
        if (features[8] < -18.441996f) {
            if (features[12] < -25.221086f) {
                if (features[11] < 27.816441f) {
                    return -0.038878f;
                } else {
                    if (features[8] < -38.221569f) {
                        return -0.034486f;
                    } else {
                        return 0.058299f;
                    }
                }
            } else {
                if (features[4] < 9.522261f) {
                    if (features[0] < 0.754269f) {
                        return -0.040491f;
                    } else {
                        return -0.030023f;
                    }
                } else {
                    if (features[0] < 0.716383f) {
                        return -0.040097f;
                    } else {
                        return 0.012812f;
                    }
                }
            }
        } else {
            if (features[12] < 7.248966f) {
                if (features[8] < 4.928890f) {
                    if (features[8] < -10.363048f) {
                        return 0.020885f;
                    } else {
                        return 0.043975f;
                    }
                } else {
                    if (features[10] < 18.686190f) {
                        return -0.036946f;
                    } else {
                        return 0.020954f;
                    }
                }
            } else {
                if (features[4] < 8.450968f) {
                    if (features[8] < -8.364439f) {
                        return -0.039964f;
                    } else {
                        return 0.003339f;
                    }
                } else {
                    if (features[11] < 2.933401f) {
                        return 0.031944f;
                    } else {
                        return -0.007748f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_136(const float* features) {
        if (features[0] < 0.628219f) {
            if (features[9] < 103.933548f) {
                if (features[4] < 2.010578f) {
                    if (features[6] < 83.084099f) {
                        return -0.001877f;
                    } else {
                        return 0.016738f;
                    }
                } else {
                    if (features[4] < 3.385558f) {
                        return -0.040275f;
                    } else {
                        return -0.005173f;
                    }
                }
            } else {
                if (features[6] < 73.504799f) {
                    if (features[4] < 3.109267f) {
                        return 0.001026f;
                    } else {
                        return 0.032350f;
                    }
                } else {
                    if (features[4] < 2.165001f) {
                        return 0.025219f;
                    } else {
                        return 0.003958f;
                    }
                }
            }
        } else {
            if (features[4] < 1.524967f) {
                if (features[4] < 0.683138f) {
                    if (features[10] < -24.766962f) {
                        return 0.023305f;
                    } else {
                        return -0.008476f;
                    }
                } else {
                    if (features[12] < -19.375830f) {
                        return 0.027991f;
                    } else {
                        return -0.019343f;
                    }
                }
            } else {
                if (features[9] < 124.728996f) {
                    if (features[0] < 0.792771f) {
                        return -0.028418f;
                    } else {
                        return -0.040660f;
                    }
                } else {
                    if (features[4] < 8.192201f) {
                        return -0.020821f;
                    } else {
                        return 0.029864f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_137(const float* features) {
        if (features[4] < 3.712480f) {
            if (features[4] < 2.010578f) {
                if (features[0] < 0.441691f) {
                    if (features[6] < 74.708000f) {
                        return 0.006454f;
                    } else {
                        return -0.009986f;
                    }
                } else {
                    if (features[12] < -2.825142f) {
                        return 0.000778f;
                    } else {
                        return 0.012932f;
                    }
                }
            } else {
                if (features[0] < 0.830531f) {
                    if (features[8] < -27.733391f) {
                        return 0.025643f;
                    } else {
                        return 0.005631f;
                    }
                } else {
                    if (features[8] < -42.325005f) {
                        return 0.032057f;
                    } else {
                        return -0.023197f;
                    }
                }
            }
        } else {
            if (features[8] < -28.914127f) {
                if (features[4] < 8.812652f) {
                    if (features[5] < 34.890099f) {
                        return -0.013487f;
                    } else {
                        return 0.029861f;
                    }
                } else {
                    if (features[0] < 0.962186f) {
                        return 0.014074f;
                    } else {
                        return -0.030335f;
                    }
                }
            } else {
                if (features[0] < 0.613141f) {
                    if (features[4] < 8.649189f) {
                        return -0.020485f;
                    } else {
                        return 0.044814f;
                    }
                } else {
                    if (features[8] < 9.294910f) {
                        return -0.035197f;
                    } else {
                        return 0.044993f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_138(const float* features) {
        if (features[0] < 0.565911f) {
            if (features[8] < -31.808825f) {
                if (features[9] < 62.805889f) {
                    if (features[6] < 66.787498f) {
                        return 0.035759f;
                    } else {
                        return -0.014811f;
                    }
                } else {
                    if (features[9] < 98.628227f) {
                        return -0.025714f;
                    } else {
                        return -0.037215f;
                    }
                }
            } else {
                if (features[9] < 112.184113f) {
                    if (features[0] < 0.220000f) {
                        return -0.043854f;
                    } else {
                        return 0.010980f;
                    }
                } else {
                    if (features[6] < 61.018501f) {
                        return 0.013147f;
                    } else {
                        return -0.030591f;
                    }
                }
            }
        } else {
            if (features[9] < 21.241404f) {
                if (features[11] < -19.858553f) {
                    if (features[9] < 15.668049f) {
                        return -0.028732f;
                    } else {
                        return 0.015557f;
                    }
                } else {
                    if (features[6] < 56.781601f) {
                        return 0.014365f;
                    } else {
                        return -0.040429f;
                    }
                }
            } else {
                if (features[8] < -42.038635f) {
                    if (features[9] < 106.188156f) {
                        return -0.005530f;
                    } else {
                        return -0.033133f;
                    }
                } else {
                    if (features[0] < 0.731283f) {
                        return 0.005946f;
                    } else {
                        return 0.022224f;
                    }
                }
            }
        }
    }

    static inline float evaluate_tree_139(const float* features) {
        if (features[8] < -17.973049f) {
            if (features[12] < -25.221086f) {
                if (features[8] < -37.965397f) {
                    return -0.038847f;
                } else {
                    if (features[8] < -37.882805f) {
                        return 0.062716f;
                    } else {
                        return -0.033023f;
                    }
                }
            } else {
                if (features[0] < 0.754269f) {
                    if (features[9] < 32.271271f) {
                        return -0.017286f;
                    } else {
                        return -0.040314f;
                    }
                } else {
                    if (features[10] < -26.310945f) {
                        return -0.007330f;
                    } else {
                        return -0.037602f;
                    }
                }
            }
        } else {
            if (features[7] < 36.972729f) {
                if (features[12] < 6.058572f) {
                    if (features[8] < 9.294910f) {
                        return 0.042328f;
                    } else {
                        return -0.026712f;
                    }
                } else {
                    if (features[8] < -12.451389f) {
                        return -0.037294f;
                    } else {
                        return 0.028269f;
                    }
                }
            } else {
                if (features[12] < -0.516902f) {
                    if (features[7] < 60.556522f) {
                        return 0.057932f;
                    } else {
                        return 0.005431f;
                    }
                } else {
                    if (features[0] < 0.677156f) {
                        return -0.031054f;
                    } else {
                        return 0.006660f;
                    }
                }
            }
        }
    }

};

#endif // XGBOOST_GANO_H
