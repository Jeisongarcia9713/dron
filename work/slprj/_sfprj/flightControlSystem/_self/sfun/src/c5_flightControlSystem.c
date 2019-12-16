/* Include files */

#include "flightControlSystem_sfun.h"
#include "c5_flightControlSystem.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "flightControlSystem_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[5] = { "m", "nargin", "nargout", "u",
  "y" };

static emlrtRTEInfo c5_emlrtRTEI = { 147,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_b_emlrtRTEI = { 250,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_c_emlrtRTEI = { 250,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_d_emlrtRTEI = { 251,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_e_emlrtRTEI = { 251,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_f_emlrtRTEI = { 252,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_g_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_h_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_i_emlrtRTEI = { 132,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_j_emlrtRTEI = { 133,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_k_emlrtRTEI = { 134,/* lineNo */
  27,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_l_emlrtRTEI = { 134,/* lineNo */
  43,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_m_emlrtRTEI = { 153,/* lineNo */
  25,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_n_emlrtRTEI = { 153,/* lineNo */
  9,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c5_o_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

static emlrtRTEInfo c5_p_emlrtRTEI = { 72,/* lineNo */
  13,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo c5_q_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_r_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_s_emlrtRTEI = { 690,/* lineNo */
  5,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_t_emlrtRTEI = { 696,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_u_emlrtRTEI = { 114,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_v_emlrtRTEI = { 697,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_w_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c5_x_emlrtRTEI = { 114,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_y_emlrtRTEI = { 697,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c5_ab_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c5_bb_emlrtRTEI = { 820,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c5_cb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c5_db_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_eb_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_fb_emlrtRTEI = { 60,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_gb_emlrtRTEI = { 60,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_hb_emlrtRTEI = { 60,/* lineNo */
  15,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_ib_emlrtRTEI = { 61,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_jb_emlrtRTEI = { 61,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_kb_emlrtRTEI = { 60,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_lb_emlrtRTEI = { 397,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_mb_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_nb_emlrtRTEI = { 65,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_ob_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_pb_emlrtRTEI = { 66,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_qb_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_rb_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_sb_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_tb_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_ub_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c5_vb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_wb_emlrtRTEI = { 257,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_xb_emlrtRTEI = { 90,/* lineNo */
  40,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_yb_emlrtRTEI = { 94,/* lineNo */
  47,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_ac_emlrtRTEI = { 202,/* lineNo */
  12,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_bc_emlrtRTEI = { 202,/* lineNo */
  25,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_cc_emlrtRTEI = { 214,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_dc_emlrtRTEI = { 243,/* lineNo */
  18,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_ec_emlrtRTEI = { 238,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_fc_emlrtRTEI = { 243,/* lineNo */
  36,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_gc_emlrtRTEI = { 238,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_hc_emlrtRTEI = { 243,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_ic_emlrtRTEI = { 254,/* lineNo */
  8,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c5_jc_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_kc_emlrtRTEI = { 12,/* lineNo */
  23,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_lc_emlrtRTEI = { 166,/* lineNo */
  32,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_mc_emlrtRTEI = { 168,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_nc_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_oc_emlrtRTEI = { 297,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c5_pc_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static const char_T c5_cv0[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
  'n', 't', 'e', 'g', 'e', 'r' };

static const real_T c5_dv0[13] = { 3.4813359214923066E-5, 0.00054457256285105169,
  0.0051667606200595231, 0.029732654490475546, 0.10377716120747749,
  0.219696252000246, 0.28209557151935094, 0.219696252000246, 0.10377716120747749,
  0.029732654490475546, 0.0051667606200595231, 0.00054457256285105169,
  3.4813359214923066E-5 };

static const char_T c5_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c5_cv2[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

/* Function Declarations */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_chartstep_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_m, const char_T *c5_identifier, boolean_T
  c5_c_y[19200]);
static void c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T c5_c_y[19200]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_medfilt2(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], boolean_T c5_b[19200]);
static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_matrixSize, int32_T c5_indexSize[2]);
static void c5_abs(SFc5_flightControlSystemInstanceStruct *chartInstance, real_T
                   c5_c_x_data[], int32_T c5_x_size[1], real_T c5_y_data[],
                   int32_T c5_y_size[1]);
static void c5_padarray(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], real_T c5_varargin_2[2], boolean_T
  c5_b_b_data[], int32_T c5_b_size[2]);
static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c5_b_varargin_1[19200], boolean_T c5_varargout_1
                    [19200]);
static void c5_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real32_T c5_b[19200]);
static void c5_padImage(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_a_tmp[19200], real_T c5_boundary_pos, int8_T c5_boundaryEnum,
  real_T c5_boundaryStr_pos, real32_T c5_c_a[21120]);
static void c5_b_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real_T c5_varargin_2[13], real32_T c5_b[19200]);
static void c5_b_padImage(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_a_tmp[19200], real_T c5_boundary_pos, int8_T c5_boundaryEnum,
  real_T c5_boundaryStr_pos, real32_T c5_c_a[20640]);
static void c5_c_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real32_T c5_b[19200]);
static void c5_d_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real_T c5_varargin_2[13], real32_T c5_b[19200]);
static void c5_hypot(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c5_x[19200], real32_T c5_c_y[19200], real32_T
                     c5_r[19200]);
static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_thinAndThreshold(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_d_dx[19200], real32_T c5_d_dy[19200], real32_T
  c5_magGrad[19200], real_T c5_lowThresh_data[], int32_T c5_lowThresh_size[1],
  real_T c5_highThresh_data[], int32_T c5_highThresh_size[1], boolean_T c5_H
  [19200]);
static void c5_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     real_T c5_c_x_data[], int32_T c5_x_size[1], real_T
                     c5_d_x_data[], int32_T c5_b_x_size[1]);
static void c5_bwselect(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], real_T c5_c_varargin_2_data[], int32_T
  c5_varargin_2_size[1], real_T c5_varargin_3_data[], int32_T
  c5_varargin_3_size[1], boolean_T c5_varargout_1[19200]);
static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1], real_T c5_d_x_data[], int32_T
  c5_b_x_size[1]);
static void c5_validate_inputs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1]);
static void c5_make_bitarray(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_n, int32_T c5_c_idx_data[], int32_T c5_idx_size[1],
  boolean_T c5_b_b_data[], int32_T c5_b_size[2]);
static int32_T c5_num_true(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_b_data[], int32_T c5_b_size[2]);
static boolean_T c5_allinrange(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], real_T c5_lo,
  int32_T c5_hi);
static boolean_T c5_isequal(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_b_varargin_1[2], real_T c5_varargin_2[2]);
static void c5_imfill(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c5_b_varargin_1[19200], real_T
                      c5_c_varargin_2_data[], int32_T c5_varargin_2_size[1],
                      boolean_T c5_I2[19200]);
static boolean_T c5_b_isequal(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_varargin_1_data[], int32_T c5_varargin_1_size[1],
  real_T c5_varargin_2);
static void c5_checkLocations(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_locations_data[], int32_T c5_locations_size[1],
  real_T c5_b_locationsVar_data[], int32_T c5_locationsVar_size[1]);
static void c5_validateattributes(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_a_data[], int32_T c5_a_size[1]);
static boolean_T c5_any(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_c_x_data[], int32_T c5_x_size[1]);
static void c5_c_warning(SFc5_flightControlSystemInstanceStruct *chartInstance);
static void c5_b_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_idx,
  real_T c5_d_x_data[], int32_T c5_b_x_size[1]);
static const mxArray *c5_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[30]);
static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[34]);
static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[36]);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_flightControlSystem, const
  char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_c_x_data[], int32_T c5_x_size[1]);
static void c5_c_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1]);
static void c5_d_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_idx);
static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c5_fEmlrtCtx, "Image_Toolbox", 2);
  setLegacyDebuggerFlag(chartInstance->S, true);
  setDebuggerFlag(chartInstance->S, true);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_flightControlSystem(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_flightControlSystem = 0U;
}

static void initialize_params_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_flightControlSystem(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void ext_mode_exec_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_d_y = NULL;
  uint8_T c5_hoistedGlobal;
  const mxArray *c5_e_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_createcellmatrix(2, 1), false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", *chartInstance->c5_b_y, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c5_c_y, 0, c5_d_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_flightControlSystem;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c5_c_y, 1, c5_e_y);
  sf_mex_assign(&c5_st, c5_c_y, false);
  return c5_st;
}

static void set_sim_state_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_d_u;
  boolean_T c5_bv0[19200];
  int32_T c5_i0;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_d_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_d_u, 0)), "y",
                      c5_bv0);
  for (c5_i0 = 0; c5_i0 < 19200; c5_i0++) {
    (*chartInstance->c5_b_y)[c5_i0] = c5_bv0[c5_i0];
  }

  chartInstance->c5_is_active_c5_flightControlSystem = c5_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_d_u, 1)),
     "is_active_c5_flightControlSystem");
  sf_mex_destroy(&c5_d_u);
  c5_update_debugger_state_c5_flightControlSystem(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void sf_gateway_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4, chartInstance->c5_sfEvent);
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_c_u)[c5_i1], 0U);
  }

  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U, (real_T)
                      (*chartInstance->c5_c_u)[c5_i2]);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_flightControlSystem(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i3 = 0; c5_i3 < 19200; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_b_y)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 19200; c5_i4++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U, (real_T)
                      (*chartInstance->c5_b_y)[c5_i4]);
  }
}

static void mdl_start_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  static const uint32_T c5_decisionTxtEndIdx = 0U;
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    38U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 56);
}

static void c5_chartstep_c5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c5_i5;
  uint32_T c5_debug_family_var_map[5];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i5 = 0; c5_i5 < 19200; c5_i5++) {
    chartInstance->c5_u[c5_i5] = (*chartInstance->c5_c_u)[c5_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_m, 0U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c5_u, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_y, 4U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 2);
  for (c5_i6 = 0; c5_i6 < 19200; c5_i6++) {
    chartInstance->c5_b_u[c5_i6] = chartInstance->c5_u[c5_i6];
  }

  c5_medfilt2(chartInstance, chartInstance->c5_b_u, chartInstance->c5_bv1);
  for (c5_i7 = 0; c5_i7 < 19200; c5_i7++) {
    chartInstance->c5_m[c5_i7] = chartInstance->c5_bv1[c5_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  for (c5_i8 = 0; c5_i8 < 19200; c5_i8++) {
    chartInstance->c5_b_m[c5_i8] = chartInstance->c5_m[c5_i8];
  }

  c5_edge(chartInstance, chartInstance->c5_b_m, chartInstance->c5_bv2);
  for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
    chartInstance->c5_y[c5_i9] = chartInstance->c5_bv2[c5_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i10 = 0; c5_i10 < 19200; c5_i10++) {
    (*chartInstance->c5_b_y)[c5_i10] = chartInstance->c5_y[c5_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_flightControlSystem
  (SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)(c5_machineNumber);
  (void)(c5_chartNumber);
  (void)(c5_instanceNumber);
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int32_T c5_i11;
  int32_T c5_i12;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i13;
  boolean_T c5_d_u[19200];
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_i11 = 0;
  for (c5_i12 = 0; c5_i12 < 160; c5_i12++) {
    for (c5_i13 = 0; c5_i13 < 120; c5_i13++) {
      c5_d_u[c5_i13 + c5_i11] = (*(boolean_T (*)[19200])c5_inData)[c5_i13 +
        c5_i11];
    }

    c5_i11 += 120;
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_d_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_c_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_c_m, const char_T *c5_identifier, boolean_T
  c5_c_y[19200])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c_m), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_c_m);
}

static void c5_b_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T c5_c_y[19200])
{
  boolean_T c5_bv3[19200];
  int32_T c5_i14;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_d_u), c5_bv3, 1, 11, 0U, 1, 0U, 2,
                120, 160);
  for (c5_i14 = 0; c5_i14 < 19200; c5_i14++) {
    c5_c_y[c5_i14] = c5_bv3[c5_i14];
  }

  sf_mex_destroy(&c5_d_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_c_m;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_c_y[19200];
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_c_m = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c_m), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_c_m);
  c5_i15 = 0;
  for (c5_i16 = 0; c5_i16 < 160; c5_i16++) {
    for (c5_i17 = 0; c5_i17 < 120; c5_i17++) {
      (*(boolean_T (*)[19200])c5_outData)[c5_i17 + c5_i15] = c5_c_y[c5_i17 +
        c5_i15];
    }

    c5_i15 += 120;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  real_T c5_d_u;
  const mxArray *c5_c_y = NULL;
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_d_u = *(real_T *)c5_inData;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_c_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_c_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_d_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_c_y = c5_d0;
  sf_mex_destroy(&c5_d_u);
  return c5_c_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargin;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_c_y;
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_nargin = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargin),
    &c5_thisId);
  sf_mex_destroy(&c5_nargin);
  *(real_T *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static void c5_medfilt2(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], boolean_T c5_b[19200])
{
  int32_T c5_idx;
  int32_T c5_tmp_size[1];
  int32_T c5_i18;
  int32_T c5_indices_size[1];
  int32_T c5_d_tmp_data[9];
  int32_T c5_i19;
  int32_T c5_j_size[1];
  int32_T c5_ii;
  int32_T c5_jj;
  boolean_T c5_b0;
  int32_T c5_indices_data[9];
  int32_T c5_b_j_data[9];
  int32_T c5_i20;
  int32_T c5_b_tmp_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i21;
  int32_T c5_iv0[2];
  int32_T c5_e_tmp_data[9];
  boolean_T c5_b1;
  int32_T c5_i22;
  int32_T c5_b_loop_ub;
  int32_T c5_i23;
  int32_T c5_iv1[2];
  boolean_T c5_b2;
  int32_T c5_i24;
  int32_T c5_c_loop_ub;
  int32_T c5_i25;
  int32_T c5_iv2[2];
  int32_T c5_rows_size[1];
  int32_T c5_d_loop_ub;
  int32_T c5_i26;
  int32_T c5_cols_size[1];
  real_T c5_rows_data[9];
  int32_T c5_e_loop_ub;
  int32_T c5_i27;
  real_T c5_cols_data[9];
  int32_T c5_f_loop_ub;
  int32_T c5_i28;
  int32_T c5_g_loop_ub;
  int32_T c5_i29;
  int32_T c5_b_rows_size[1];
  int32_T c5_h_loop_ub;
  int32_T c5_i30;
  real_T c5_b_rows_data[9];
  real_T c5_varargin_1_data[9];
  int32_T c5_varargin_1_size[1];
  boolean_T c5_b3;
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  static char_T c5_cv4[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c5_n;
  const mxArray *c5_f_y = NULL;
  int32_T c5_last;
  real_T c5_ex;
  real_T c5_maxval;
  int32_T c5_k;
  int32_T c5_b_cols_size[1];
  int32_T c5_i_loop_ub;
  int32_T c5_i31;
  real_T c5_b_cols_data[9];
  boolean_T c5_b4;
  const mxArray *c5_g_y = NULL;
  static char_T c5_cv5[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  static char_T c5_cv6[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c5_b_n;
  const mxArray *c5_j_y = NULL;
  int32_T c5_b_last;
  real_T c5_b_ex;
  real_T c5_b_maxval;
  int32_T c5_b_k;
  real_T c5_c_varargin_1;
  real_T c5_varargin_2;
  real_T c5_x;
  real_T c5_d_varargin_1;
  real_T c5_b_x;
  real_T c5_k_y;
  real_T c5_c_x;
  real_T c5_l_y;
  real_T c5_d_x;
  real_T c5_m_y;
  real_T c5_e_x;
  real_T c5_n_y;
  real_T c5_f_x;
  real_T c5_o_y;
  real_T c5_padSize;
  real_T c5_c_a;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_startIdx[2];
  boolean_T c5_e_varargin_1[19200];
  boolean_T c5_Apad_data[20336];
  int32_T c5_Apad_size[2];
  real_T c5_Ma;
  real_T c5_b_b;
  int32_T c5_j_loop_ub;
  int32_T c5_i34;
  int32_T c5_k_loop_ub;
  int32_T c5_i35;
  real_T c5_d1;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  real_T c5_sizeA[2];
  int32_T c5_i39;
  int32_T c5_i40;
  real_T c5_domainSizeT[2];
  real_T c5_dv1[2];
  boolean_T exitg1;
  c5_idx = 0;
  c5_tmp_size[0] = 9;
  for (c5_i18 = 0; c5_i18 < 9; c5_i18++) {
    c5_d_tmp_data[c5_i18] = 0;
  }

  c5_indices_size[0] = c5_tmp_size[0];
  c5_tmp_size[0] = 9;
  for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
    c5_d_tmp_data[c5_i19] = 0;
  }

  c5_j_size[0] = c5_tmp_size[0];
  c5_ii = 1;
  c5_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c5_jj <= 3)) {
    c5_idx++;
    c5_indices_data[c5_idx - 1] = c5_ii;
    c5_b_j_data[c5_idx - 1] = c5_jj;
    if (c5_idx >= 9) {
      exitg1 = true;
    } else {
      c5_ii++;
      if (c5_ii > 3) {
        c5_ii = 1;
        c5_jj++;
      }
    }
  }

  c5_b0 = (1 > c5_idx);
  if (c5_b0) {
    c5_i20 = 0;
  } else {
    c5_i20 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i20;
  c5_loop_ub = c5_i20 - 1;
  for (c5_i21 = 0; c5_i21 <= c5_loop_ub; c5_i21++) {
    c5_e_tmp_data[c5_i21] = 1 + c5_i21;
  }

  c5_iv0[0] = 1;
  c5_iv0[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 9, c5_iv0);
  c5_indices_size[0] = c5_i20;
  c5_b1 = (1 > c5_idx);
  if (c5_b1) {
    c5_i22 = 0;
  } else {
    c5_i22 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i22;
  c5_b_loop_ub = c5_i22 - 1;
  for (c5_i23 = 0; c5_i23 <= c5_b_loop_ub; c5_i23++) {
    c5_e_tmp_data[c5_i23] = 1 + c5_i23;
  }

  c5_iv1[0] = 1;
  c5_iv1[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 9, c5_iv1);
  c5_j_size[0] = c5_i22;
  c5_b2 = (1 > c5_idx);
  if (c5_b2) {
    c5_i24 = 0;
  } else {
    c5_i24 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i24;
  c5_c_loop_ub = c5_i24 - 1;
  for (c5_i25 = 0; c5_i25 <= c5_c_loop_ub; c5_i25++) {
    c5_e_tmp_data[c5_i25] = 1 + c5_i25;
  }

  c5_iv2[0] = 1;
  c5_iv2[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 9, c5_iv2);
  c5_rows_size[0] = c5_indices_size[0];
  c5_d_loop_ub = c5_indices_size[0] - 1;
  for (c5_i26 = 0; c5_i26 <= c5_d_loop_ub; c5_i26++) {
    c5_rows_data[c5_i26] = (real_T)c5_indices_data[c5_i26];
  }

  c5_cols_size[0] = c5_j_size[0];
  c5_e_loop_ub = c5_j_size[0] - 1;
  for (c5_i27 = 0; c5_i27 <= c5_e_loop_ub; c5_i27++) {
    c5_cols_data[c5_i27] = (real_T)c5_b_j_data[c5_i27];
  }

  c5_rows_size[0];
  c5_f_loop_ub = c5_rows_size[0] - 1;
  for (c5_i28 = 0; c5_i28 <= c5_f_loop_ub; c5_i28++) {
    c5_rows_data[c5_i28] -= 2.0;
  }

  c5_cols_size[0];
  c5_g_loop_ub = c5_cols_size[0] - 1;
  for (c5_i29 = 0; c5_i29 <= c5_g_loop_ub; c5_i29++) {
    c5_cols_data[c5_i29] -= 2.0;
  }

  c5_b_rows_size[0] = c5_rows_size[0];
  c5_h_loop_ub = c5_rows_size[0] - 1;
  for (c5_i30 = 0; c5_i30 <= c5_h_loop_ub; c5_i30++) {
    c5_b_rows_data[c5_i30] = c5_rows_data[c5_i30];
  }

  c5_abs(chartInstance, c5_b_rows_data, c5_b_rows_size, c5_varargin_1_data,
         c5_varargin_1_size);
  if ((c5_varargin_1_size[0] == 1) || ((real_T)c5_varargin_1_size[0] != 1.0)) {
    c5_b3 = true;
  } else {
    c5_b3 = false;
  }

  if (c5_b3) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_d_y)));
  }

  if ((real_T)c5_varargin_1_size[0] >= 1.0) {
  } else {
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv4, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv4, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_f_y)));
  }

  c5_n = c5_varargin_1_size[0];
  if (c5_n <= 2) {
    if (c5_n == 1) {
      c5_maxval = c5_varargin_1_data[0];
    } else if (c5_varargin_1_data[0] < c5_varargin_1_data[1]) {
      c5_maxval = c5_varargin_1_data[1];
    } else {
      c5_maxval = c5_varargin_1_data[0];
    }
  } else {
    c5_last = c5_n;
    c5_ex = c5_varargin_1_data[0];
    for (c5_k = 1; c5_k < c5_last; c5_k++) {
      if (c5_ex < c5_varargin_1_data[c5_k]) {
        c5_ex = c5_varargin_1_data[c5_k];
      }
    }

    c5_maxval = c5_ex;
  }

  c5_b_cols_size[0] = c5_cols_size[0];
  c5_i_loop_ub = c5_cols_size[0] - 1;
  for (c5_i31 = 0; c5_i31 <= c5_i_loop_ub; c5_i31++) {
    c5_b_cols_data[c5_i31] = c5_cols_data[c5_i31];
  }

  c5_abs(chartInstance, c5_b_cols_data, c5_b_cols_size, c5_varargin_1_data,
         c5_varargin_1_size);
  if ((c5_varargin_1_size[0] == 1) || ((real_T)c5_varargin_1_size[0] != 1.0)) {
    c5_b4 = true;
  } else {
    c5_b4 = false;
  }

  if (c5_b4) {
  } else {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv5, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv5, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_g_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_h_y)));
  }

  if ((real_T)c5_varargin_1_size[0] >= 1.0) {
  } else {
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv6, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv6, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_i_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_j_y)));
  }

  c5_b_n = c5_varargin_1_size[0];
  if (c5_b_n <= 2) {
    if (c5_b_n == 1) {
      c5_b_maxval = c5_varargin_1_data[0];
    } else if (c5_varargin_1_data[0] < c5_varargin_1_data[1]) {
      c5_b_maxval = c5_varargin_1_data[1];
    } else {
      c5_b_maxval = c5_varargin_1_data[0];
    }
  } else {
    c5_b_last = c5_b_n;
    c5_b_ex = c5_varargin_1_data[0];
    for (c5_b_k = 1; c5_b_k < c5_b_last; c5_b_k++) {
      if (c5_b_ex < c5_varargin_1_data[c5_b_k]) {
        c5_b_ex = c5_varargin_1_data[c5_b_k];
      }
    }

    c5_b_maxval = c5_b_ex;
  }

  c5_c_varargin_1 = c5_maxval;
  c5_varargin_2 = c5_b_maxval;
  c5_x = c5_c_varargin_1;
  c5_d_varargin_1 = c5_varargin_2;
  c5_b_x = c5_x;
  c5_k_y = c5_d_varargin_1;
  c5_c_x = c5_b_x;
  c5_l_y = c5_k_y;
  c5_d_x = c5_c_x;
  c5_m_y = c5_l_y;
  c5_e_x = c5_d_x;
  c5_n_y = c5_m_y;
  c5_f_x = c5_e_x;
  c5_o_y = c5_n_y;
  c5_padSize = muDoubleScalarMax(c5_f_x, c5_o_y);
  c5_c_a = c5_padSize;
  for (c5_i32 = 0; c5_i32 < 2; c5_i32++) {
    c5_startIdx[c5_i32] = c5_c_a;
  }

  for (c5_i33 = 0; c5_i33 < 19200; c5_i33++) {
    c5_e_varargin_1[c5_i33] = c5_b_varargin_1[c5_i33];
  }

  c5_padarray(chartInstance, c5_e_varargin_1, c5_startIdx, c5_Apad_data,
              c5_Apad_size);
  c5_Ma = (real_T)c5_Apad_size[0];
  c5_b_b = c5_Ma;
  c5_cols_size[0];
  c5_j_loop_ub = c5_cols_size[0] - 1;
  for (c5_i34 = 0; c5_i34 <= c5_j_loop_ub; c5_i34++) {
    c5_cols_data[c5_i34] *= c5_b_b;
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_cols_size[0], c5_rows_size[0]);
  c5_indices_size[0] = c5_cols_size[0];
  c5_k_loop_ub = c5_cols_size[0] - 1;
  for (c5_i35 = 0; c5_i35 <= c5_k_loop_ub; c5_i35++) {
    c5_d1 = muDoubleScalarRound(c5_cols_data[c5_i35] + c5_rows_data[c5_i35]);
    if (c5_d1 < 2.147483648E+9) {
      if (c5_d1 >= -2.147483648E+9) {
        c5_i37 = (int32_T)c5_d1;
      } else {
        c5_i37 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c5_d1 >= 2.147483648E+9) {
      c5_i37 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c5_i37 = 0;
    }

    c5_indices_data[c5_i35] = c5_i37;
  }

  c5_startIdx[0] = c5_padSize;
  c5_startIdx[1] = c5_padSize;
  for (c5_i36 = 0; c5_i36 < 2; c5_i36++) {
    c5_sizeA[c5_i36] = (real_T)c5_Apad_size[c5_i36];
  }

  for (c5_i38 = 0; c5_i38 < 2; c5_i38++) {
    c5_sizeA[c5_i38];
  }

  for (c5_i39 = 0; c5_i39 < 2; c5_i39++) {
    c5_domainSizeT[c5_i39] = 3.0;
  }

  for (c5_i40 = 0; c5_i40 < 2; c5_i40++) {
    c5_dv1[c5_i40] = 120.0 + 40.0 * (real_T)c5_i40;
  }

  ordfilt2_boolean(&c5_Apad_data[0], c5_sizeA[0], c5_startIdx, &c5_indices_data
                   [0], (real_T)c5_indices_size[0], c5_domainSizeT, 4.0, c5_b,
                   c5_dv1, true);
}

static void c5_indexShapeCheck(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_matrixSize, int32_T c5_indexSize[2])
{
  int32_T c5_size1;
  boolean_T c5_b;
  boolean_T c5_nonSingletonDimFound;
  boolean_T c5_c;
  boolean_T c5_b_c;
  boolean_T c5_b_b;
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv7[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  const mxArray *c5_d_y = NULL;
  (void)chartInstance;
  c5_size1 = c5_matrixSize;
  if (c5_size1 != 1) {
    c5_b = false;
  } else {
    c5_b = true;
  }

  if (c5_b) {
    c5_nonSingletonDimFound = false;
    if (c5_indexSize[1] != 1) {
      c5_nonSingletonDimFound = true;
    }

    c5_b_b = c5_nonSingletonDimFound;
    if (c5_b_b) {
      c5_c = true;
    } else {
      c5_c = false;
    }
  } else {
    c5_c = false;
  }

  c5_b_c = c5_c;
  if (!c5_b_c) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_d_y)));
  }
}

static void c5_abs(SFc5_flightControlSystemInstanceStruct *chartInstance, real_T
                   c5_c_x_data[], int32_T c5_x_size[1], real_T c5_y_data[],
                   int32_T c5_y_size[1])
{
  int32_T c5_nx;
  real_T c5_x[2];
  int32_T c5_i41;
  int32_T c5_k;
  int32_T c5_b_k;
  real_T c5_b_x;
  real_T c5_c_y;
  (void)chartInstance;
  c5_nx = c5_x_size[0] - 1;
  c5_x[0] = (real_T)c5_x_size[0];
  c5_x[1] = 1.0;
  for (c5_i41 = 0; c5_i41 < 2; c5_i41++) {
    c5_x[c5_i41];
  }

  c5_y_size[0] = (int32_T)c5_x[0];
  for (c5_k = 0; c5_k <= c5_nx; c5_k++) {
    c5_b_k = c5_k;
    c5_b_x = c5_c_x_data[c5_b_k];
    c5_c_y = muDoubleScalarAbs(c5_b_x);
    c5_y_data[c5_b_k] = c5_c_y;
  }
}

static void c5_padarray(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], real_T c5_varargin_2[2], boolean_T
  c5_b_b_data[], int32_T c5_b_size[2])
{
  boolean_T c5_p;
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  boolean_T c5_b5;
  real_T c5_b_x;
  real_T c5_c_x;
  const mxArray *c5_c_y = NULL;
  boolean_T c5_b_p;
  static char_T c5_cv8[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
    'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c5_i42;
  const mxArray *c5_d_y = NULL;
  boolean_T c5_c_p;
  int32_T c5_i43;
  real_T c5_e_y[2];
  const mxArray *c5_f_y = NULL;
  static char_T c5_cv9[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c5_d2;
  int32_T c5_i44;
  int32_T c5_j;
  real_T c5_b;
  real_T c5_b_j;
  int32_T c5_c;
  real_T c5_d3;
  int32_T c5_c_a;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i;
  int32_T c5_i47;
  int32_T c5_c_j;
  real_T c5_b_i;
  int32_T c5_d_j;
  real_T c5_d4;
  int32_T c5_i48;
  int32_T c5_e_j;
  int32_T c5_c_i;
  real_T c5_d5;
  int32_T c5_f_j;
  int32_T c5_i49;
  real_T c5_d_a;
  int32_T c5_d_i;
  int32_T c5_b_c;
  int32_T c5_e_i;
  int32_T c5_e_a;
  int32_T c5_i50;
  int32_T c5_i51;
  real_T c5_f_a;
  real_T c5_g_a;
  int32_T c5_f_i;
  real_T c5_b_b;
  real_T c5_c_b;
  int32_T c5_c_c;
  int32_T c5_d_c;
  real_T c5_h_a;
  real_T c5_i_a;
  real_T c5_d_b;
  real_T c5_e_b;
  int32_T c5_e_c;
  int32_T c5_f_c;
  boolean_T exitg1;
  c5_p = true;
  c5_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_k < 2)) {
    c5_b_k = 1.0 + (real_T)c5_k;
    c5_x = c5_varargin_2[(int32_T)c5_b_k - 1];
    c5_b_x = c5_x;
    c5_c_x = c5_b_x;
    if (c5_c_x == c5_x) {
      c5_b_p = true;
    } else {
      c5_b_p = false;
    }

    c5_c_p = c5_b_p;
    if (c5_c_p) {
      c5_k++;
    } else {
      c5_p = false;
      exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b5 = true;
  } else {
    c5_b5 = false;
  }

  if (c5_b5) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv8, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv0, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv9, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c5_d_y, 14, c5_f_y)));
  }

  for (c5_i42 = 0; c5_i42 < 2; c5_i42++) {
    c5_e_y[c5_i42] = 2.0 * c5_varargin_2[c5_i42];
  }

  for (c5_i43 = 0; c5_i43 < 2; c5_i43++) {
    c5_e_y[c5_i43] += 120.0 + 40.0 * (real_T)c5_i43;
  }

  c5_b_size[0] = (int32_T)c5_e_y[0];
  c5_b_size[1] = (int32_T)c5_e_y[1];
  c5_d2 = c5_varargin_2[1];
  c5_i44 = (int32_T)c5_d2 - 1;
  for (c5_j = 0; c5_j <= c5_i44; c5_j++) {
    c5_b_j = 1.0 + (real_T)c5_j;
    c5_d3 = (real_T)c5_b_size[0];
    c5_i45 = (int32_T)c5_d3 - 1;
    for (c5_i = 0; c5_i <= c5_i45; c5_i++) {
      c5_b_i = 1.0 + (real_T)c5_i;
      c5_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c5_b_i, 1, c5_b_size
        [0]) + c5_b_size[0] * ((int32_T)c5_b_j - 1)) - 1] = false;
    }
  }

  c5_b = c5_varargin_2[1];
  c5_c = (int32_T)c5_b;
  c5_c_a = c5_c + 160;
  c5_i46 = c5_c_a;
  c5_i47 = c5_b_size[1];
  for (c5_c_j = c5_i46 + 1; c5_c_j <= c5_i47; c5_c_j++) {
    c5_d4 = (real_T)c5_b_size[0];
    c5_i48 = (int32_T)c5_d4 - 1;
    for (c5_c_i = 0; c5_c_i <= c5_i48; c5_c_i++) {
      c5_b_i = 1.0 + (real_T)c5_c_i;
      c5_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c5_b_i, 1, c5_b_size
        [0]) + c5_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c5_c_j, 1, c5_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c5_d_j = 0; c5_d_j < 160; c5_d_j++) {
    c5_b_j = 1.0 + (real_T)c5_d_j;
    c5_d5 = c5_varargin_2[0];
    c5_i49 = (int32_T)c5_d5 - 1;
    for (c5_d_i = 0; c5_d_i <= c5_i49; c5_d_i++) {
      c5_b_i = 1.0 + (real_T)c5_d_i;
      c5_f_a = c5_b_j;
      c5_b_b = c5_varargin_2[1];
      c5_c_c = (int32_T)c5_f_a + (int32_T)c5_b_b;
      c5_b_b_data[((int32_T)c5_b_i + c5_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c5_c_c, 1, c5_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c5_e_j = 0; c5_e_j < 160; c5_e_j++) {
    c5_b_j = 1.0 + (real_T)c5_e_j;
    c5_d_a = c5_varargin_2[0];
    c5_b_c = (int32_T)c5_d_a;
    c5_e_a = c5_b_c + 120;
    c5_i50 = c5_e_a;
    c5_i51 = c5_b_size[0];
    for (c5_f_i = c5_i50 + 1; c5_f_i <= c5_i51; c5_f_i++) {
      c5_i_a = c5_b_j;
      c5_e_b = c5_varargin_2[1];
      c5_f_c = (int32_T)c5_i_a + (int32_T)c5_e_b;
      c5_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c5_f_i, 1, c5_b_size[0]) +
                   c5_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c5_f_c, 1, c5_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c5_f_j = 0; c5_f_j < 160; c5_f_j++) {
    c5_b_j = 1.0 + (real_T)c5_f_j;
    for (c5_e_i = 0; c5_e_i < 120; c5_e_i++) {
      c5_b_i = 1.0 + (real_T)c5_e_i;
      c5_g_a = c5_b_i;
      c5_c_b = c5_varargin_2[0];
      c5_d_c = (int32_T)c5_g_a + (int32_T)c5_c_b;
      c5_h_a = c5_b_j;
      c5_d_b = c5_varargin_2[1];
      c5_e_c = (int32_T)c5_h_a + (int32_T)c5_d_b;
      c5_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c5_d_c, 1, c5_b_size[0]) +
                   c5_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c5_e_c, 1, c5_b_size[1]) - 1)) - 1] = c5_b_varargin_1[((int32_T)c5_b_i
        + 120 * ((int32_T)c5_b_j - 1)) - 1];
    }
  }
}

static void c5_edge(SFc5_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c5_b_varargin_1[19200], boolean_T c5_varargout_1
                    [19200])
{
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  real_T c5_derivGaussKernel[13];
  static real_T c5_dv2[13] = { 0.00050975920363612861, 0.0025659736304223,
    0.014594040963812248, 0.049305200293708981, 0.09498179875488523,
    0.089159205155936727, 0.0, -0.089159205155936727, -0.09498179875488523,
    -0.049305200293708981, -0.014594040963812248, -0.0025659736304223,
    -0.00050975920363612861 };

  int32_T c5_i55;
  static real_T c5_dv3[6] = { 0.0020299751839417141, 0.010218281014351701,
    0.058116735860084041, 0.19634433732941295, 0.37823877042972093,
    0.35505190018248872 };

  real_T c5_c_y;
  real_T c5_x[6];
  int32_T c5_k;
  real_T c5_b_x;
  int32_T c5_xoffset;
  real_T c5_c_x;
  int32_T c5_ix;
  real_T c5_d_x;
  real_T c5_d_y;
  int32_T c5_i56;
  int32_T c5_i57;
  real_T c5_b_derivGaussKernel[6];
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  real_T c5_c_derivGaussKernel[13];
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  real32_T c5_e_x;
  real32_T c5_f_x;
  boolean_T c5_b;
  boolean_T c5_p;
  int32_T c5_idx;
  int32_T c5_b_k;
  int32_T c5_first;
  real32_T c5_magmax;
  real32_T c5_g_x;
  real32_T c5_ex;
  real32_T c5_h_x;
  int32_T c5_i65;
  boolean_T c5_b_b;
  int32_T c5_c_k;
  real32_T c5_e_y;
  boolean_T c5_b_p;
  real_T c5_out;
  real32_T c5_f_y;
  int32_T c5_i66;
  int32_T c5_i67;
  boolean_T c5_nanFlag;
  real_T c5_counts[64];
  int32_T c5_i;
  real_T c5_b_i;
  real32_T c5_i_x;
  int32_T c5_d_k;
  boolean_T c5_c_b;
  int32_T c5_i68;
  int32_T c5_e_k;
  real32_T c5_b_idx;
  int32_T c5_c_idx;
  boolean_T c5_j_x[64];
  int32_T c5_ii_size[1];
  real32_T c5_k_x;
  int32_T c5_ii;
  boolean_T c5_d_b;
  real32_T c5_c_a;
  int32_T c5_b_ii;
  int32_T c5_c;
  real32_T c5_d_a;
  int32_T c5_i69;
  int32_T c5_b_c;
  int32_T c5_highThreshTemp_size[1];
  int32_T c5_b_ii_data[1];
  int32_T c5_loop_ub;
  int32_T c5_i70;
  real_T c5_highThreshTemp_data[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i71;
  real_T c5_d6;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_lowThresh_size[1];
  int32_T c5_b_size[1];
  int32_T c5_c_loop_ub;
  int32_T c5_i74;
  int32_T c5_b_lowThresh_size[1];
  int32_T c5_d_loop_ub;
  real_T c5_b_b_data[1];
  int32_T c5_i75;
  int32_T c5_b_highThreshTemp_size[1];
  real_T c5_lowThresh_data[1];
  real_T c5_b_lowThresh_data[1];
  int32_T c5_e_loop_ub;
  int32_T c5_i76;
  real_T c5_b_highThreshTemp_data[1];
  boolean_T exitg1;
  for (c5_i52 = 0; c5_i52 < 19200; c5_i52++) {
    chartInstance->c5_a[c5_i52] = (real32_T)c5_b_varargin_1[c5_i52];
  }

  for (c5_i53 = 0; c5_i53 < 13; c5_i53++) {
    c5_derivGaussKernel[c5_i53] = c5_dv2[c5_i53];
  }

  for (c5_i54 = 0; c5_i54 < 6; c5_i54++) {
    c5_derivGaussKernel[c5_i54] = c5_dv3[c5_i54];
  }

  for (c5_i55 = 0; c5_i55 < 6; c5_i55++) {
    c5_x[c5_i55] = c5_derivGaussKernel[c5_i55 + 7];
  }

  c5_c_y = c5_x[0];
  for (c5_k = 0; c5_k < 5; c5_k++) {
    c5_xoffset = c5_k;
    c5_ix = c5_xoffset;
    c5_c_y += c5_x[c5_ix + 1];
  }

  c5_b_x = c5_c_y;
  c5_c_x = c5_b_x;
  c5_d_x = c5_c_x;
  c5_d_y = muDoubleScalarAbs(c5_d_x);
  for (c5_i56 = 0; c5_i56 < 6; c5_i56++) {
    c5_b_derivGaussKernel[c5_i56] = c5_derivGaussKernel[c5_i56 + 7] / c5_d_y;
  }

  for (c5_i57 = 0; c5_i57 < 6; c5_i57++) {
    c5_derivGaussKernel[c5_i57 + 7] = c5_b_derivGaussKernel[c5_i57];
  }

  for (c5_i58 = 0; c5_i58 < 19200; c5_i58++) {
    chartInstance->c5_b_a[c5_i58] = chartInstance->c5_a[c5_i58];
  }

  c5_imfilter(chartInstance, chartInstance->c5_b_a, chartInstance->c5_dx);
  for (c5_i59 = 0; c5_i59 < 19200; c5_i59++) {
    chartInstance->c5_b_dx[c5_i59] = chartInstance->c5_dx[c5_i59];
  }

  for (c5_i60 = 0; c5_i60 < 13; c5_i60++) {
    c5_c_derivGaussKernel[c5_i60] = c5_derivGaussKernel[c5_i60];
  }

  c5_b_imfilter(chartInstance, chartInstance->c5_b_dx, c5_c_derivGaussKernel,
                chartInstance->c5_dx);
  c5_c_imfilter(chartInstance, chartInstance->c5_a, chartInstance->c5_dy);
  for (c5_i61 = 0; c5_i61 < 19200; c5_i61++) {
    chartInstance->c5_b_dy[c5_i61] = chartInstance->c5_dy[c5_i61];
  }

  c5_d_imfilter(chartInstance, chartInstance->c5_b_dy, c5_derivGaussKernel,
                chartInstance->c5_dy);
  for (c5_i62 = 0; c5_i62 < 19200; c5_i62++) {
    chartInstance->c5_c_dx[c5_i62] = chartInstance->c5_dx[c5_i62];
  }

  for (c5_i63 = 0; c5_i63 < 19200; c5_i63++) {
    chartInstance->c5_c_dy[c5_i63] = chartInstance->c5_dy[c5_i63];
  }

  c5_hypot(chartInstance, chartInstance->c5_c_dx, chartInstance->c5_c_dy,
           chartInstance->c5_a);
  for (c5_i64 = 0; c5_i64 < 19200; c5_i64++) {
    chartInstance->c5_varargin_1[c5_i64] = chartInstance->c5_a[c5_i64];
  }

  c5_e_x = chartInstance->c5_varargin_1[0];
  c5_f_x = c5_e_x;
  c5_b = muSingleScalarIsNaN(c5_f_x);
  c5_p = !c5_b;
  if (c5_p) {
    c5_idx = 1;
  } else {
    c5_idx = 0;
    c5_b_k = 2;
    exitg1 = false;
    while ((!exitg1) && (c5_b_k < 19201)) {
      c5_g_x = chartInstance->c5_varargin_1[c5_b_k - 1];
      c5_h_x = c5_g_x;
      c5_b_b = muSingleScalarIsNaN(c5_h_x);
      c5_b_p = !c5_b_b;
      if (c5_b_p) {
        c5_idx = c5_b_k;
        exitg1 = true;
      } else {
        c5_b_k++;
      }
    }
  }

  if (c5_idx == 0) {
    c5_magmax = chartInstance->c5_varargin_1[0];
  } else {
    c5_first = c5_idx - 1;
    c5_ex = chartInstance->c5_varargin_1[c5_first];
    c5_i65 = c5_first;
    for (c5_c_k = c5_i65 + 1; c5_c_k + 1 < 19201; c5_c_k++) {
      if (c5_ex < chartInstance->c5_varargin_1[c5_c_k]) {
        c5_ex = chartInstance->c5_varargin_1[c5_c_k];
      }
    }

    c5_magmax = c5_ex;
  }

  if (c5_magmax > 0.0F) {
    c5_e_y = c5_magmax;
    c5_f_y = c5_e_y;
    for (c5_i66 = 0; c5_i66 < 19200; c5_i66++) {
      chartInstance->c5_a[c5_i66] /= c5_f_y;
    }
  }

  c5_out = 1.0;
  getnumcores(&c5_out);
  for (c5_i67 = 0; c5_i67 < 64; c5_i67++) {
    c5_counts[c5_i67] = 0.0;
  }

  c5_nanFlag = false;
  for (c5_i = 0; c5_i < 19200; c5_i++) {
    c5_b_i = 1.0 + (real_T)c5_i;
    c5_i_x = chartInstance->c5_a[(int32_T)c5_b_i - 1];
    c5_c_b = muSingleScalarIsNaN(c5_i_x);
    if (c5_c_b) {
      c5_nanFlag = true;
      c5_b_idx = 0.0F;
    } else {
      c5_b_idx = chartInstance->c5_a[(int32_T)c5_b_i - 1] * 63.0F + 0.5F;
    }

    if (c5_b_idx > 63.0F) {
      c5_counts[63]++;
    } else {
      c5_k_x = chartInstance->c5_a[(int32_T)c5_b_i - 1];
      c5_d_b = muSingleScalarIsInf(c5_k_x);
      if (c5_d_b) {
        c5_counts[63]++;
      } else {
        c5_c_a = c5_b_idx;
        c5_c = (int32_T)c5_c_a;
        c5_d_a = c5_b_idx;
        c5_b_c = (int32_T)c5_d_a;
        c5_counts[c5_c] = c5_counts[c5_b_c] + 1.0;
      }
    }
  }

  if (c5_nanFlag) {
    c5_warning(chartInstance);
  }

  for (c5_d_k = 0; c5_d_k < 63; c5_d_k++) {
    c5_e_k = c5_d_k;
    c5_counts[c5_e_k + 1] += c5_counts[c5_e_k];
  }

  for (c5_i68 = 0; c5_i68 < 64; c5_i68++) {
    c5_j_x[c5_i68] = (c5_counts[c5_i68] > 13440.0);
  }

  c5_c_idx = 0;
  c5_ii_size[0] = 1;
  c5_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_ii < 64)) {
    c5_b_ii = c5_ii;
    if (c5_j_x[c5_b_ii]) {
      c5_c_idx = 1;
      c5_b_ii_data[0] = c5_b_ii + 1;
      exitg1 = true;
    } else {
      c5_ii++;
    }
  }

  if (c5_c_idx == 0) {
    c5_i69 = c5_ii_size[0];
    c5_ii_size[0] = 0;
  }

  c5_highThreshTemp_size[0] = c5_ii_size[0];
  c5_loop_ub = c5_ii_size[0] - 1;
  for (c5_i70 = 0; c5_i70 <= c5_loop_ub; c5_i70++) {
    c5_highThreshTemp_data[c5_i70] = (real_T)c5_b_ii_data[c5_i70];
  }

  c5_highThreshTemp_size[0];
  c5_b_loop_ub = c5_highThreshTemp_size[0] - 1;
  for (c5_i71 = 0; c5_i71 <= c5_b_loop_ub; c5_i71++) {
    c5_highThreshTemp_data[c5_i71] /= 64.0;
  }

  if (c5_highThreshTemp_size[0] == 0) {
    c5_i72 = c5_highThreshTemp_size[0];
    c5_highThreshTemp_size[0] = 0;
    c5_i73 = c5_lowThresh_size[0];
    c5_lowThresh_size[0] = 0;
  } else {
    c5_d6 = c5_highThreshTemp_data[0];
    c5_highThreshTemp_size[0] = 1;
    c5_highThreshTemp_data[0] = c5_d6;
    c5_b_size[0] = c5_highThreshTemp_size[0];
    c5_c_loop_ub = c5_highThreshTemp_size[0] - 1;
    for (c5_i74 = 0; c5_i74 <= c5_c_loop_ub; c5_i74++) {
      c5_b_b_data[c5_i74] = c5_highThreshTemp_data[c5_i74];
    }

    c5_b_size[0] = 1;
    c5_b_b_data[0] *= 0.4;
    c5_lowThresh_size[0] = 1;
    c5_b_lowThresh_data[0] = c5_b_b_data[0];
  }

  c5_b_lowThresh_size[0] = c5_lowThresh_size[0];
  c5_d_loop_ub = c5_lowThresh_size[0] - 1;
  for (c5_i75 = 0; c5_i75 <= c5_d_loop_ub; c5_i75++) {
    c5_lowThresh_data[c5_i75] = c5_b_lowThresh_data[c5_i75];
  }

  c5_b_highThreshTemp_size[0] = c5_highThreshTemp_size[0];
  c5_e_loop_ub = c5_highThreshTemp_size[0] - 1;
  for (c5_i76 = 0; c5_i76 <= c5_e_loop_ub; c5_i76++) {
    c5_b_highThreshTemp_data[c5_i76] = c5_highThreshTemp_data[c5_i76];
  }

  c5_thinAndThreshold(chartInstance, chartInstance->c5_dx, chartInstance->c5_dy,
                      chartInstance->c5_a, c5_lowThresh_data,
                      c5_b_lowThresh_size, c5_b_highThreshTemp_data,
                      c5_b_highThreshTemp_size, c5_varargout_1);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c5_lowThresh_size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c5_highThreshTemp_size[0]);
}

static void c5_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real32_T c5_b[19200])
{
  int32_T c5_i77;
  real32_T c5_c_varargin_1[19200];
  real32_T c5_c_a[21120];
  boolean_T c5_tooBig;
  int32_T c5_i;
  boolean_T c5_modeFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  boolean_T c5_conn[13];
  int32_T c5_i81;
  real_T c5_padSizeT[2];
  int32_T c5_i82;
  int32_T c5_i83;
  real_T c5_outSizeT[2];
  int32_T c5_i84;
  real_T c5_connDimsT[2];
  int32_T c5_i85;
  real_T c5_startT[2];
  for (c5_i77 = 0; c5_i77 < 19200; c5_i77++) {
    c5_c_varargin_1[c5_i77] = c5_b_varargin_1[c5_i77];
  }

  c5_padImage(chartInstance, c5_c_varargin_1, 0.0, 3, 4.0, c5_c_a);
  c5_tooBig = true;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_tooBig = false;
  }

  if (!c5_tooBig) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i79 = 0; c5_i79 < 2; c5_i79++) {
      c5_padSizeT[c5_i79] = 132.0 + 28.0 * (real_T)c5_i79;
    }

    for (c5_i81 = 0; c5_i81 < 2; c5_i81++) {
      c5_outSizeT[c5_i81] = 120.0 + 40.0 * (real_T)c5_i81;
    }

    for (c5_i83 = 0; c5_i83 < 2; c5_i83++) {
      c5_connDimsT[c5_i83] = 13.0 + -12.0 * (real_T)c5_i83;
    }

    ippfilter_real32(c5_c_a, c5_b, c5_outSizeT, 2.0, c5_padSizeT, c5_dv0,
                     c5_connDimsT, true);
  } else {
    for (c5_i78 = 0; c5_i78 < 13; c5_i78++) {
      c5_conn[c5_i78] = true;
    }

    for (c5_i80 = 0; c5_i80 < 2; c5_i80++) {
      c5_padSizeT[c5_i80] = 132.0 + 28.0 * (real_T)c5_i80;
    }

    for (c5_i82 = 0; c5_i82 < 2; c5_i82++) {
      c5_outSizeT[c5_i82] = 120.0 + 40.0 * (real_T)c5_i82;
    }

    for (c5_i84 = 0; c5_i84 < 2; c5_i84++) {
      c5_connDimsT[c5_i84] = 13.0 + -12.0 * (real_T)c5_i84;
    }

    for (c5_i85 = 0; c5_i85 < 2; c5_i85++) {
      c5_startT[c5_i85] = 6.0 + -6.0 * (real_T)c5_i85;
    }

    imfilter_real32(c5_c_a, c5_b, 2.0, c5_outSizeT, 2.0, c5_padSizeT, c5_dv0,
                    13.0, c5_conn, 2.0, c5_connDimsT, c5_startT, 2.0, true, true);
  }
}

static void c5_padImage(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_a_tmp[19200], real_T c5_boundary_pos, int8_T c5_boundaryEnum,
  real_T c5_boundaryStr_pos, real32_T c5_c_a[21120])
{
  int32_T c5_j;
  real_T c5_b_j;
  int32_T c5_i;
  real_T c5_b_i;
  static int32_T c5_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 120, 120, 120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133,
    134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148,
    149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160 };

  (void)c5_boundary_pos;
  (void)c5_boundaryEnum;
  (void)c5_boundaryStr_pos;
  for (c5_j = 0; c5_j < 160; c5_j++) {
    c5_b_j = 1.0 + (real_T)c5_j;
    for (c5_i = 0; c5_i < 132; c5_i++) {
      c5_b_i = 1.0 + (real_T)c5_i;
      c5_c_a[((int32_T)c5_b_i + 132 * ((int32_T)c5_b_j - 1)) - 1] = c5_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c5_idxA[(int32_T)c5_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c5_idxA[(int32_T)c5_b_j + 159], 1, 160) - 1)) -
        1];
    }
  }
}

static void c5_b_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real_T c5_varargin_2[13], real32_T c5_b[19200])
{
  int32_T c5_i86;
  real32_T c5_c_varargin_1[19200];
  real32_T c5_c_a[20640];
  int32_T c5_trueCount;
  int32_T c5_i;
  int32_T c5_tmp_size[1];
  int32_T c5_partialTrueCount;
  int32_T c5_b_i;
  int32_T c5_nonzero_h_size[1];
  int32_T c5_loop_ub;
  int32_T c5_d_tmp_data[13];
  int32_T c5_i87;
  int32_T c5_i88;
  real_T c5_nonzero_h_data[13];
  boolean_T c5_densityFlag;
  boolean_T c5_connb[13];
  boolean_T c5_tooBig;
  int32_T c5_c_i;
  boolean_T c5_modeFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  real_T c5_numKernElem;
  int32_T c5_i89;
  int32_T c5_i90;
  int32_T c5_i91;
  real_T c5_padSizeT[2];
  int32_T c5_i92;
  int32_T c5_i93;
  real_T c5_outSizeT[2];
  int32_T c5_i94;
  real_T c5_connDimsT[2];
  int32_T c5_i95;
  real_T c5_startT[2];
  for (c5_i86 = 0; c5_i86 < 19200; c5_i86++) {
    c5_c_varargin_1[c5_i86] = c5_b_varargin_1[c5_i86];
  }

  c5_b_padImage(chartInstance, c5_c_varargin_1, 0.0, 3, 4.0, c5_c_a);
  c5_trueCount = 0;
  for (c5_i = 0; c5_i < 13; c5_i++) {
    if (c5_varargin_2[c5_i] != 0.0) {
      c5_trueCount++;
    }
  }

  c5_tmp_size[0] = c5_trueCount;
  c5_partialTrueCount = 0;
  for (c5_b_i = 0; c5_b_i < 13; c5_b_i++) {
    if (c5_varargin_2[c5_b_i] != 0.0) {
      c5_d_tmp_data[c5_partialTrueCount] = c5_b_i + 1;
      c5_partialTrueCount++;
    }
  }

  c5_nonzero_h_size[0] = c5_tmp_size[0];
  c5_loop_ub = c5_tmp_size[0] - 1;
  for (c5_i87 = 0; c5_i87 <= c5_loop_ub; c5_i87++) {
    c5_nonzero_h_data[c5_i87] = c5_varargin_2[c5_d_tmp_data[c5_i87] - 1];
  }

  for (c5_i88 = 0; c5_i88 < 13; c5_i88++) {
    c5_connb[c5_i88] = (c5_varargin_2[c5_i88] != 0.0);
  }

  c5_densityFlag = false;
  if ((real_T)c5_nonzero_h_size[0] / 13.0 > 0.05) {
    c5_densityFlag = true;
  }

  c5_tooBig = true;
  for (c5_c_i = 0; c5_c_i < 2; c5_c_i++) {
    c5_tooBig = false;
  }

  if (c5_densityFlag && (!c5_tooBig)) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i89 = 0; c5_i89 < 2; c5_i89++) {
      c5_padSizeT[c5_i89] = 120.0 + 52.0 * (real_T)c5_i89;
    }

    for (c5_i91 = 0; c5_i91 < 2; c5_i91++) {
      c5_outSizeT[c5_i91] = 120.0 + 40.0 * (real_T)c5_i91;
    }

    for (c5_i93 = 0; c5_i93 < 2; c5_i93++) {
      c5_connDimsT[c5_i93] = 1.0 + 12.0 * (real_T)c5_i93;
    }

    ippfilter_real32(c5_c_a, c5_b, c5_outSizeT, 2.0, c5_padSizeT, c5_varargin_2,
                     c5_connDimsT, true);
  } else {
    c5_numKernElem = (real_T)c5_nonzero_h_size[0];
    for (c5_i90 = 0; c5_i90 < 2; c5_i90++) {
      c5_padSizeT[c5_i90] = 120.0 + 52.0 * (real_T)c5_i90;
    }

    for (c5_i92 = 0; c5_i92 < 2; c5_i92++) {
      c5_outSizeT[c5_i92] = 120.0 + 40.0 * (real_T)c5_i92;
    }

    for (c5_i94 = 0; c5_i94 < 2; c5_i94++) {
      c5_connDimsT[c5_i94] = 1.0 + 12.0 * (real_T)c5_i94;
    }

    for (c5_i95 = 0; c5_i95 < 2; c5_i95++) {
      c5_startT[c5_i95] = 6.0 * (real_T)c5_i95;
    }

    imfilter_real32(c5_c_a, c5_b, 2.0, c5_outSizeT, 2.0, c5_padSizeT,
                    &c5_nonzero_h_data[0], c5_numKernElem, c5_connb, 2.0,
                    c5_connDimsT, c5_startT, 2.0, true, true);
  }
}

static void c5_b_padImage(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_a_tmp[19200], real_T c5_boundary_pos, int8_T c5_boundaryEnum,
  real_T c5_boundaryStr_pos, real32_T c5_c_a[20640])
{
  int32_T c5_j;
  real_T c5_b_j;
  int32_T c5_i;
  real_T c5_b_i;
  static int32_T c5_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
    158, 159, 160, 160, 160, 160, 160, 160, 160 };

  (void)c5_boundary_pos;
  (void)c5_boundaryEnum;
  (void)c5_boundaryStr_pos;
  for (c5_j = 0; c5_j < 172; c5_j++) {
    c5_b_j = 1.0 + (real_T)c5_j;
    for (c5_i = 0; c5_i < 120; c5_i++) {
      c5_b_i = 1.0 + (real_T)c5_i;
      c5_c_a[((int32_T)c5_b_i + 120 * ((int32_T)c5_b_j - 1)) - 1] = c5_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c5_idxA[(int32_T)c5_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c5_idxA[(int32_T)c5_b_j + 171], 1, 160) - 1)) -
        1];
    }
  }
}

static void c5_c_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real32_T c5_b[19200])
{
  int32_T c5_i96;
  real32_T c5_c_varargin_1[19200];
  real32_T c5_c_a[20640];
  int32_T c5_trueCount;
  int32_T c5_i;
  int32_T c5_tmp_size[1];
  int32_T c5_partialTrueCount;
  int32_T c5_b_i;
  int32_T c5_nonzero_h_size[1];
  int32_T c5_loop_ub;
  int32_T c5_d_tmp_data[13];
  int32_T c5_i97;
  boolean_T c5_densityFlag;
  real_T c5_nonzero_h_data[13];
  boolean_T c5_tooBig;
  int32_T c5_c_i;
  boolean_T c5_modeFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  real_T c5_numKernElem;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i100;
  real_T c5_padSizeT[2];
  int32_T c5_i101;
  boolean_T c5_conn[13];
  int32_T c5_i102;
  real_T c5_outSizeT[2];
  int32_T c5_i103;
  real_T c5_connDimsT[2];
  int32_T c5_i104;
  int32_T c5_i105;
  real_T c5_startT[2];
  for (c5_i96 = 0; c5_i96 < 19200; c5_i96++) {
    c5_c_varargin_1[c5_i96] = c5_b_varargin_1[c5_i96];
  }

  c5_b_padImage(chartInstance, c5_c_varargin_1, 0.0, 3, 4.0, c5_c_a);
  c5_trueCount = 0;
  for (c5_i = 0; c5_i < 13; c5_i++) {
    if (c5_dv0[c5_i] != 0.0) {
      c5_trueCount++;
    }
  }

  c5_tmp_size[0] = c5_trueCount;
  c5_partialTrueCount = 0;
  for (c5_b_i = 0; c5_b_i < 13; c5_b_i++) {
    if (c5_dv0[c5_b_i] != 0.0) {
      c5_d_tmp_data[c5_partialTrueCount] = c5_b_i + 1;
      c5_partialTrueCount++;
    }
  }

  c5_nonzero_h_size[0] = c5_tmp_size[0];
  c5_loop_ub = c5_tmp_size[0] - 1;
  for (c5_i97 = 0; c5_i97 <= c5_loop_ub; c5_i97++) {
    c5_nonzero_h_data[c5_i97] = c5_dv0[c5_d_tmp_data[c5_i97] - 1];
  }

  c5_densityFlag = false;
  if ((real_T)c5_nonzero_h_size[0] / 13.0 > 0.05) {
    c5_densityFlag = true;
  }

  c5_tooBig = true;
  for (c5_c_i = 0; c5_c_i < 2; c5_c_i++) {
    c5_tooBig = false;
  }

  if (c5_densityFlag && (!c5_tooBig)) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i98 = 0; c5_i98 < 2; c5_i98++) {
      c5_padSizeT[c5_i98] = 120.0 + 52.0 * (real_T)c5_i98;
    }

    for (c5_i100 = 0; c5_i100 < 2; c5_i100++) {
      c5_outSizeT[c5_i100] = 120.0 + 40.0 * (real_T)c5_i100;
    }

    for (c5_i102 = 0; c5_i102 < 2; c5_i102++) {
      c5_connDimsT[c5_i102] = 1.0 + 12.0 * (real_T)c5_i102;
    }

    ippfilter_real32(c5_c_a, c5_b, c5_outSizeT, 2.0, c5_padSizeT, c5_dv0,
                     c5_connDimsT, true);
  } else {
    c5_numKernElem = (real_T)c5_nonzero_h_size[0];
    for (c5_i99 = 0; c5_i99 < 13; c5_i99++) {
      c5_conn[c5_i99] = true;
    }

    for (c5_i101 = 0; c5_i101 < 2; c5_i101++) {
      c5_padSizeT[c5_i101] = 120.0 + 52.0 * (real_T)c5_i101;
    }

    for (c5_i103 = 0; c5_i103 < 2; c5_i103++) {
      c5_outSizeT[c5_i103] = 120.0 + 40.0 * (real_T)c5_i103;
    }

    for (c5_i104 = 0; c5_i104 < 2; c5_i104++) {
      c5_connDimsT[c5_i104] = 1.0 + 12.0 * (real_T)c5_i104;
    }

    for (c5_i105 = 0; c5_i105 < 2; c5_i105++) {
      c5_startT[c5_i105] = 6.0 * (real_T)c5_i105;
    }

    imfilter_real32(c5_c_a, c5_b, 2.0, c5_outSizeT, 2.0, c5_padSizeT,
                    &c5_nonzero_h_data[0], c5_numKernElem, c5_conn, 2.0,
                    c5_connDimsT, c5_startT, 2.0, true, true);
  }
}

static void c5_d_imfilter(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real32_T c5_b_varargin_1[19200], real_T c5_varargin_2[13], real32_T c5_b[19200])
{
  int32_T c5_i106;
  real32_T c5_c_varargin_1[19200];
  real32_T c5_c_a[21120];
  int32_T c5_trueCount;
  int32_T c5_i;
  int32_T c5_tmp_size[1];
  int32_T c5_partialTrueCount;
  int32_T c5_b_i;
  int32_T c5_nonzero_h_size[1];
  int32_T c5_loop_ub;
  int32_T c5_d_tmp_data[13];
  int32_T c5_i107;
  int32_T c5_i108;
  real_T c5_nonzero_h_data[13];
  boolean_T c5_densityFlag;
  boolean_T c5_connb[13];
  boolean_T c5_tooBig;
  int32_T c5_c_i;
  boolean_T c5_modeFlag;
  boolean_T c5_b_modeFlag;
  boolean_T c5_c_modeFlag;
  real_T c5_numKernElem;
  int32_T c5_i109;
  int32_T c5_i110;
  int32_T c5_i111;
  real_T c5_padSizeT[2];
  int32_T c5_i112;
  int32_T c5_i113;
  real_T c5_outSizeT[2];
  int32_T c5_i114;
  real_T c5_connDimsT[2];
  int32_T c5_i115;
  real_T c5_startT[2];
  for (c5_i106 = 0; c5_i106 < 19200; c5_i106++) {
    c5_c_varargin_1[c5_i106] = c5_b_varargin_1[c5_i106];
  }

  c5_padImage(chartInstance, c5_c_varargin_1, 0.0, 3, 4.0, c5_c_a);
  c5_trueCount = 0;
  for (c5_i = 0; c5_i < 13; c5_i++) {
    if (c5_varargin_2[c5_i] != 0.0) {
      c5_trueCount++;
    }
  }

  c5_tmp_size[0] = c5_trueCount;
  c5_partialTrueCount = 0;
  for (c5_b_i = 0; c5_b_i < 13; c5_b_i++) {
    if (c5_varargin_2[c5_b_i] != 0.0) {
      c5_d_tmp_data[c5_partialTrueCount] = c5_b_i + 1;
      c5_partialTrueCount++;
    }
  }

  c5_nonzero_h_size[0] = c5_tmp_size[0];
  c5_loop_ub = c5_tmp_size[0] - 1;
  for (c5_i107 = 0; c5_i107 <= c5_loop_ub; c5_i107++) {
    c5_nonzero_h_data[c5_i107] = c5_varargin_2[c5_d_tmp_data[c5_i107] - 1];
  }

  for (c5_i108 = 0; c5_i108 < 13; c5_i108++) {
    c5_connb[c5_i108] = (c5_varargin_2[c5_i108] != 0.0);
  }

  c5_densityFlag = false;
  if ((real_T)c5_nonzero_h_size[0] / 13.0 > 0.05) {
    c5_densityFlag = true;
  }

  c5_tooBig = true;
  for (c5_c_i = 0; c5_c_i < 2; c5_c_i++) {
    c5_tooBig = false;
  }

  if (c5_densityFlag && (!c5_tooBig)) {
    c5_modeFlag = true;
  } else {
    c5_modeFlag = false;
  }

  if (c5_modeFlag) {
    c5_b_modeFlag = true;
  } else {
    c5_b_modeFlag = false;
  }

  c5_c_modeFlag = c5_b_modeFlag;
  if (c5_c_modeFlag) {
    for (c5_i109 = 0; c5_i109 < 2; c5_i109++) {
      c5_padSizeT[c5_i109] = 132.0 + 28.0 * (real_T)c5_i109;
    }

    for (c5_i111 = 0; c5_i111 < 2; c5_i111++) {
      c5_outSizeT[c5_i111] = 120.0 + 40.0 * (real_T)c5_i111;
    }

    for (c5_i113 = 0; c5_i113 < 2; c5_i113++) {
      c5_connDimsT[c5_i113] = 13.0 + -12.0 * (real_T)c5_i113;
    }

    ippfilter_real32(c5_c_a, c5_b, c5_outSizeT, 2.0, c5_padSizeT, c5_varargin_2,
                     c5_connDimsT, true);
  } else {
    c5_numKernElem = (real_T)c5_nonzero_h_size[0];
    for (c5_i110 = 0; c5_i110 < 2; c5_i110++) {
      c5_padSizeT[c5_i110] = 132.0 + 28.0 * (real_T)c5_i110;
    }

    for (c5_i112 = 0; c5_i112 < 2; c5_i112++) {
      c5_outSizeT[c5_i112] = 120.0 + 40.0 * (real_T)c5_i112;
    }

    for (c5_i114 = 0; c5_i114 < 2; c5_i114++) {
      c5_connDimsT[c5_i114] = 13.0 + -12.0 * (real_T)c5_i114;
    }

    for (c5_i115 = 0; c5_i115 < 2; c5_i115++) {
      c5_startT[c5_i115] = 6.0 + -6.0 * (real_T)c5_i115;
    }

    imfilter_real32(c5_c_a, c5_b, 2.0, c5_outSizeT, 2.0, c5_padSizeT,
                    &c5_nonzero_h_data[0], c5_numKernElem, c5_connb, 2.0,
                    c5_connDimsT, c5_startT, 2.0, true, true);
  }
}

static void c5_hypot(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c5_x[19200], real32_T c5_c_y[19200], real32_T
                     c5_r[19200])
{
  int32_T c5_k;
  int32_T c5_b_k;
  real32_T c5_b_x;
  real32_T c5_d_y;
  real32_T c5_x1;
  real32_T c5_x2;
  real32_T c5_z;
  (void)chartInstance;
  for (c5_k = 0; c5_k < 19200; c5_k++) {
    c5_b_k = c5_k;
    c5_b_x = c5_x[c5_b_k];
    c5_d_y = c5_c_y[c5_b_k];
    c5_x1 = c5_b_x;
    c5_x2 = c5_d_y;
    c5_z = muSingleScalarHypot(c5_x1, c5_x2);
    c5_r[c5_b_k] = c5_z;
  }
}

static void c5_warning(SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv10[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c5_d_y = NULL;
  static char_T c5_cv11[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c5_e_y = NULL;
  static char_T c5_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv10, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv11, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c5_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c5_d_y, 14, c5_e_y));
}

static void c5_thinAndThreshold(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real32_T c5_d_dx[19200], real32_T c5_d_dy[19200], real32_T
  c5_magGrad[19200], real_T c5_lowThresh_data[], int32_T c5_lowThresh_size[1],
  real_T c5_highThresh_data[], int32_T c5_highThresh_size[1], boolean_T c5_H
  [19200])
{
  real_T c5_lowThresh;
  real_T c5_b_lowThresh;
  int32_T c5_i116;
  int32_T c5_i117;
  boolean_T c5_E[19200];
  real_T c5_szT[2];
  real_T c5_highThresh;
  int32_T c5_i118;
  int32_T c5_i119;
  boolean_T c5_x[19200];
  int32_T c5_idx;
  int32_T c5_tmp_size[1];
  int32_T c5_i120;
  int32_T c5_i_size[1];
  int32_T c5_i121;
  int32_T c5_j_size[1];
  int32_T c5_ii;
  int32_T c5_jj;
  boolean_T c5_b6;
  int32_T c5_i122;
  int32_T c5_b_tmp_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i123;
  int32_T c5_iv3[2];
  boolean_T c5_b7;
  int32_T c5_i124;
  int32_T c5_b_loop_ub;
  int32_T c5_i125;
  int32_T c5_iv4[2];
  boolean_T c5_b8;
  int32_T c5_i126;
  int32_T c5_c_loop_ub;
  int32_T c5_i127;
  int32_T c5_iv5[2];
  int32_T c5_idxStrongR_size[1];
  int32_T c5_d_loop_ub;
  int32_T c5_i128;
  int32_T c5_idxStrongC_size[1];
  int32_T c5_e_loop_ub;
  int32_T c5_i129;
  int32_T c5_i130;
  boolean_T exitg1;
  boolean_T guard1 = false;
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c5_lowThresh_size[0]);
  c5_lowThresh = c5_lowThresh_data[0];
  c5_b_lowThresh = c5_lowThresh;
  for (c5_i116 = 0; c5_i116 < 19200; c5_i116++) {
    c5_E[c5_i116] = false;
  }

  for (c5_i117 = 0; c5_i117 < 2; c5_i117++) {
    c5_szT[c5_i117] = 120.0 + 40.0 * (real_T)c5_i117;
  }

  cannythresholding_real32_tbb(c5_d_dx, c5_d_dy, c5_magGrad, c5_szT,
    c5_b_lowThresh, c5_E);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c5_highThresh_size[0]);
  c5_highThresh = c5_highThresh_data[0];
  for (c5_i118 = 0; c5_i118 < 19200; c5_i118++) {
    c5_x[c5_i118] = ((real_T)c5_magGrad[c5_i118] > c5_highThresh);
  }

  for (c5_i119 = 0; c5_i119 < 19200; c5_i119++) {
    c5_x[c5_i119] = (c5_x[c5_i119] && c5_E[c5_i119]);
  }

  c5_idx = 0;
  c5_tmp_size[0] = 19200;
  for (c5_i120 = 0; c5_i120 < 19200; c5_i120++) {
    chartInstance->c5_tmp_data[c5_i120] = 0;
  }

  c5_i_size[0] = c5_tmp_size[0];
  c5_tmp_size[0] = 19200;
  for (c5_i121 = 0; c5_i121 < 19200; c5_i121++) {
    chartInstance->c5_tmp_data[c5_i121] = 0;
  }

  c5_j_size[0] = c5_tmp_size[0];
  c5_ii = 1;
  c5_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c5_jj <= 160)) {
    guard1 = false;
    if (c5_x[(c5_ii + 120 * (c5_jj - 1)) - 1]) {
      c5_idx++;
      chartInstance->c5_i_data[c5_idx - 1] = c5_ii;
      chartInstance->c5_j_data[c5_idx - 1] = c5_jj;
      if (c5_idx >= 19200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      c5_ii++;
      if (c5_ii > 120) {
        c5_ii = 1;
        c5_jj++;
      }
    }
  }

  c5_b6 = (1 > c5_idx);
  if (c5_b6) {
    c5_i122 = 0;
  } else {
    c5_i122 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i122;
  c5_loop_ub = c5_i122 - 1;
  for (c5_i123 = 0; c5_i123 <= c5_loop_ub; c5_i123++) {
    chartInstance->c5_b_tmp_data[c5_i123] = 1 + c5_i123;
  }

  c5_iv3[0] = 1;
  c5_iv3[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 19200, c5_iv3);
  c5_i_size[0] = c5_i122;
  c5_b7 = (1 > c5_idx);
  if (c5_b7) {
    c5_i124 = 0;
  } else {
    c5_i124 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i124;
  c5_b_loop_ub = c5_i124 - 1;
  for (c5_i125 = 0; c5_i125 <= c5_b_loop_ub; c5_i125++) {
    chartInstance->c5_b_tmp_data[c5_i125] = 1 + c5_i125;
  }

  c5_iv4[0] = 1;
  c5_iv4[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 19200, c5_iv4);
  c5_j_size[0] = c5_i124;
  c5_b8 = (1 > c5_idx);
  if (c5_b8) {
    c5_i126 = 0;
  } else {
    c5_i126 = c5_idx;
  }

  c5_b_tmp_size[0] = c5_i126;
  c5_c_loop_ub = c5_i126 - 1;
  for (c5_i127 = 0; c5_i127 <= c5_c_loop_ub; c5_i127++) {
    chartInstance->c5_b_tmp_data[c5_i127] = 1 + c5_i127;
  }

  c5_iv5[0] = 1;
  c5_iv5[1] = c5_b_tmp_size[0];
  c5_indexShapeCheck(chartInstance, 19200, c5_iv5);
  c5_idxStrongR_size[0] = c5_i_size[0];
  c5_d_loop_ub = c5_i_size[0] - 1;
  for (c5_i128 = 0; c5_i128 <= c5_d_loop_ub; c5_i128++) {
    chartInstance->c5_idxStrongR_data[c5_i128] = (real_T)
      chartInstance->c5_i_data[c5_i128];
  }

  c5_idxStrongC_size[0] = c5_j_size[0];
  c5_e_loop_ub = c5_j_size[0] - 1;
  for (c5_i129 = 0; c5_i129 <= c5_e_loop_ub; c5_i129++) {
    chartInstance->c5_idxStrongC_data[c5_i129] = (real_T)
      chartInstance->c5_j_data[c5_i129];
  }

  if (c5_idxStrongC_size[0] != 0) {
    c5_bwselect(chartInstance, c5_E, chartInstance->c5_idxStrongC_data,
                c5_idxStrongC_size, chartInstance->c5_idxStrongR_data,
                c5_idxStrongR_size, c5_H);
  } else {
    for (c5_i130 = 0; c5_i130 < 19200; c5_i130++) {
      c5_H[c5_i130] = false;
    }
  }
}

static void c5_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
                     real_T c5_c_x_data[], int32_T c5_x_size[1], real_T
                     c5_d_x_data[], int32_T c5_b_x_size[1])
{
  int32_T c5_loop_ub;
  int32_T c5_i131;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i131 = 0; c5_i131 <= c5_loop_ub; c5_i131++) {
    c5_d_x_data[c5_i131] = c5_c_x_data[c5_i131];
  }

  c5_b_round(chartInstance, c5_d_x_data, c5_b_x_size);
}

static void c5_bwselect(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_varargin_1[19200], real_T c5_c_varargin_2_data[], int32_T
  c5_varargin_2_size[1], real_T c5_varargin_3_data[], int32_T
  c5_varargin_3_size[1], boolean_T c5_varargout_1[19200])
{
  int32_T c5_r_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i132;
  int32_T c5_c_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i133;
  int32_T c5_x_size[1];
  int32_T c5_c_loop_ub;
  int32_T c5_i134;
  int32_T c5_tmp_size[1];
  boolean_T c5_c_x_data[19200];
  int32_T c5_d_loop_ub;
  int32_T c5_i135;
  boolean_T c5_d_tmp_data[19200];
  int32_T c5_e_loop_ub;
  int32_T c5_i136;
  int32_T c5_f_loop_ub;
  int32_T c5_i137;
  int32_T c5_g_loop_ub;
  int32_T c5_i138;
  int32_T c5_h_loop_ub;
  int32_T c5_i139;
  int32_T c5_i_loop_ub;
  int32_T c5_i140;
  int32_T c5_nx;
  int32_T c5_k;
  int32_T c5_b_nx;
  int32_T c5_idx;
  int32_T c5_ii_size[1];
  int32_T c5_ii;
  int32_T c5_b_ii;
  boolean_T c5_b9;
  int32_T c5_i141;
  int32_T c5_i142;
  int32_T c5_badPix_size[1];
  int32_T c5_b_size[1];
  int32_T c5_j_loop_ub;
  int32_T c5_k_loop_ub;
  int32_T c5_i143;
  int32_T c5_i144;
  int32_T c5_iv6[2];
  int32_T c5_b_r_size[1];
  int32_T c5_b_badPix_size[1];
  int32_T c5_l_loop_ub;
  int32_T c5_m_loop_ub;
  int32_T c5_i145;
  int32_T c5_i146;
  static char_T c5_cv12[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  int32_T c5_c_badPix_size[1];
  real_T c5_c_varargin_1[2];
  int32_T c5_n_loop_ub;
  int32_T c5_i147;
  real_T c5_varargin_2[2];
  static char_T c5_cv13[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'V',
    'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  int32_T c5_b_c_size[1];
  int32_T c5_o_loop_ub;
  int32_T c5_i148;
  int32_T c5_p_loop_ub;
  int32_T c5_i149;
  int32_T c5_q_loop_ub;
  int32_T c5_i150;
  int32_T c5_r_loop_ub;
  int32_T c5_i151;
  int32_T c5_s_loop_ub;
  int32_T c5_i152;
  int32_T c5_t_loop_ub;
  int32_T c5_i153;
  int32_T c5_i154;
  boolean_T c5_d_varargin_1[19200];
  int32_T c5_i155;
  int32_T c5_b_idx;
  int32_T c5_c_ii;
  int32_T c5_d_ii;
  boolean_T c5_b10;
  int32_T c5_i156;
  int32_T c5_u_loop_ub;
  int32_T c5_i157;
  int32_T c5_iv7[2];
  boolean_T exitg1;
  c5_r_size[0] = c5_varargin_3_size[0];
  c5_loop_ub = c5_varargin_3_size[0] - 1;
  for (c5_i132 = 0; c5_i132 <= c5_loop_ub; c5_i132++) {
    chartInstance->c5_r_data[c5_i132] = c5_varargin_3_data[c5_i132];
  }

  c5_b_round(chartInstance, chartInstance->c5_r_data, c5_r_size);
  c5_c_size[0] = c5_varargin_2_size[0];
  c5_b_loop_ub = c5_varargin_2_size[0] - 1;
  for (c5_i133 = 0; c5_i133 <= c5_b_loop_ub; c5_i133++) {
    chartInstance->c5_c_data[c5_i133] = c5_c_varargin_2_data[c5_i133];
  }

  c5_b_round(chartInstance, chartInstance->c5_c_data, c5_c_size);
  c5_x_size[0] = c5_r_size[0];
  c5_c_loop_ub = c5_r_size[0] - 1;
  for (c5_i134 = 0; c5_i134 <= c5_c_loop_ub; c5_i134++) {
    c5_c_x_data[c5_i134] = (chartInstance->c5_r_data[c5_i134] < 1.0);
  }

  c5_tmp_size[0] = c5_r_size[0];
  c5_d_loop_ub = c5_r_size[0] - 1;
  for (c5_i135 = 0; c5_i135 <= c5_d_loop_ub; c5_i135++) {
    c5_d_tmp_data[c5_i135] = (chartInstance->c5_r_data[c5_i135] > 120.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_x_size[0], c5_tmp_size[0]);
  c5_x_size[0];
  c5_e_loop_ub = c5_x_size[0] - 1;
  for (c5_i136 = 0; c5_i136 <= c5_e_loop_ub; c5_i136++) {
    c5_c_x_data[c5_i136] = (c5_c_x_data[c5_i136] || c5_d_tmp_data[c5_i136]);
  }

  c5_tmp_size[0] = c5_c_size[0];
  c5_f_loop_ub = c5_c_size[0] - 1;
  for (c5_i137 = 0; c5_i137 <= c5_f_loop_ub; c5_i137++) {
    c5_d_tmp_data[c5_i137] = (chartInstance->c5_c_data[c5_i137] < 1.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_x_size[0], c5_tmp_size[0]);
  c5_x_size[0];
  c5_g_loop_ub = c5_x_size[0] - 1;
  for (c5_i138 = 0; c5_i138 <= c5_g_loop_ub; c5_i138++) {
    c5_c_x_data[c5_i138] = (c5_c_x_data[c5_i138] || c5_d_tmp_data[c5_i138]);
  }

  c5_tmp_size[0] = c5_c_size[0];
  c5_h_loop_ub = c5_c_size[0] - 1;
  for (c5_i139 = 0; c5_i139 <= c5_h_loop_ub; c5_i139++) {
    c5_d_tmp_data[c5_i139] = (chartInstance->c5_c_data[c5_i139] > 160.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_x_size[0], c5_tmp_size[0]);
  c5_x_size[0];
  c5_i_loop_ub = c5_x_size[0] - 1;
  for (c5_i140 = 0; c5_i140 <= c5_i_loop_ub; c5_i140++) {
    c5_c_x_data[c5_i140] = (c5_c_x_data[c5_i140] || c5_d_tmp_data[c5_i140]);
  }

  c5_nx = c5_x_size[0];
  c5_k = c5_nx;
  c5_b_nx = c5_nx - 1;
  c5_idx = 0;
  c5_ii_size[0] = c5_k;
  c5_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (c5_ii - 1 <= c5_b_nx)) {
    c5_b_ii = c5_ii;
    if (c5_c_x_data[c5_b_ii - 1]) {
      c5_idx++;
      chartInstance->c5_ii_data[c5_idx - 1] = c5_b_ii;
      if (c5_idx >= c5_k) {
        exitg1 = true;
      } else {
        c5_ii++;
      }
    } else {
      c5_ii++;
    }
  }

  if (c5_idx <= c5_k) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_emlrt_marshallOut(chartInstance, c5_cv1), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv1))));
  }

  if (c5_k == 1) {
    if (c5_idx == 0) {
      c5_i141 = c5_ii_size[0];
      c5_ii_size[0] = 0;
    }
  } else {
    c5_b9 = (1 > c5_idx);
    if (c5_b9) {
      c5_i142 = 0;
    } else {
      c5_i142 = c5_idx;
    }

    c5_b_size[0] = c5_i142;
    c5_k_loop_ub = c5_i142 - 1;
    for (c5_i144 = 0; c5_i144 <= c5_k_loop_ub; c5_i144++) {
      chartInstance->c5_b_data[c5_i144] = 1 + c5_i144;
    }

    c5_iv6[0] = 1;
    c5_iv6[1] = c5_b_size[0];
    c5_indexShapeCheck(chartInstance, c5_ii_size[0], c5_iv6);
    c5_ii_size[0] = c5_i142;
  }

  c5_badPix_size[0] = c5_ii_size[0];
  c5_j_loop_ub = c5_ii_size[0] - 1;
  for (c5_i143 = 0; c5_i143 <= c5_j_loop_ub; c5_i143++) {
    chartInstance->c5_badPix_data[c5_i143] = (real_T)chartInstance->
      c5_ii_data[c5_i143];
  }

  if (c5_badPix_size[0] != 0) {
    c5_b_warning(chartInstance);
    c5_b_badPix_size[0] = c5_badPix_size[0];
    c5_m_loop_ub = c5_badPix_size[0] - 1;
    for (c5_i146 = 0; c5_i146 <= c5_m_loop_ub; c5_i146++) {
      chartInstance->c5_b_badPix_data[c5_i146] = (int32_T)
        chartInstance->c5_badPix_data[c5_i146];
    }

    c5_c_nullAssignment(chartInstance, chartInstance->c5_r_data, c5_r_size,
                        chartInstance->c5_b_badPix_data, c5_b_badPix_size);
    c5_c_badPix_size[0] = c5_badPix_size[0];
    c5_n_loop_ub = c5_badPix_size[0] - 1;
    for (c5_i147 = 0; c5_i147 <= c5_n_loop_ub; c5_i147++) {
      chartInstance->c5_c_badPix_data[c5_i147] = (int32_T)
        chartInstance->c5_badPix_data[c5_i147];
    }

    c5_c_nullAssignment(chartInstance, chartInstance->c5_c_data, c5_c_size,
                        chartInstance->c5_c_badPix_data, c5_c_badPix_size);
  }

  c5_b_r_size[0] = c5_r_size[0];
  c5_l_loop_ub = c5_r_size[0] - 1;
  for (c5_i145 = 0; c5_i145 <= c5_l_loop_ub; c5_i145++) {
    chartInstance->c5_b_r_data[c5_i145] = chartInstance->c5_r_data[c5_i145];
  }

  if (c5_allinrange(chartInstance, chartInstance->c5_b_r_data, c5_b_r_size, 1.0,
                    120)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_emlrt_marshallOut(chartInstance, c5_cv12), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv12))));
  }

  c5_c_varargin_1[0] = (real_T)c5_r_size[0];
  c5_c_varargin_1[1] = 1.0;
  c5_varargin_2[0] = (real_T)c5_c_size[0];
  c5_varargin_2[1] = 1.0;
  if (c5_isequal(chartInstance, c5_c_varargin_1, c5_varargin_2)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_b_emlrt_marshallOut(chartInstance, c5_cv13), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_b_emlrt_marshallOut(chartInstance, c5_cv13))));
  }

  c5_b_c_size[0] = c5_c_size[0];
  c5_o_loop_ub = c5_c_size[0] - 1;
  for (c5_i148 = 0; c5_i148 <= c5_o_loop_ub; c5_i148++) {
    chartInstance->c5_b_c_data[c5_i148] = chartInstance->c5_c_data[c5_i148];
  }

  if (c5_allinrange(chartInstance, chartInstance->c5_b_c_data, c5_b_c_size, 1.0,
                    160)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_emlrt_marshallOut(chartInstance, c5_cv12), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv12))));
  }

  c5_ii_size[0] = c5_r_size[0];
  c5_p_loop_ub = c5_r_size[0] - 1;
  for (c5_i149 = 0; c5_i149 <= c5_p_loop_ub; c5_i149++) {
    chartInstance->c5_ii_data[c5_i149] = (int32_T)chartInstance->
      c5_r_data[c5_i149];
  }

  c5_b_size[0] = c5_c_size[0];
  c5_q_loop_ub = c5_c_size[0] - 1;
  for (c5_i150 = 0; c5_i150 <= c5_q_loop_ub; c5_i150++) {
    chartInstance->c5_b_data[c5_i150] = (int32_T)chartInstance->
      c5_c_data[c5_i150] - 1;
  }

  c5_b_size[0];
  c5_r_loop_ub = c5_b_size[0] - 1;
  for (c5_i151 = 0; c5_i151 <= c5_r_loop_ub; c5_i151++) {
    chartInstance->c5_b_data[c5_i151] *= 120;
  }

  c5_ii_size[0];
  c5_s_loop_ub = c5_ii_size[0] - 1;
  for (c5_i152 = 0; c5_i152 <= c5_s_loop_ub; c5_i152++) {
    chartInstance->c5_ii_data[c5_i152] += chartInstance->c5_b_data[c5_i152];
  }

  c5_r_size[0] = c5_ii_size[0];
  c5_t_loop_ub = c5_ii_size[0] - 1;
  for (c5_i153 = 0; c5_i153 <= c5_t_loop_ub; c5_i153++) {
    chartInstance->c5_r_data[c5_i153] = (real_T)chartInstance->
      c5_ii_data[c5_i153];
  }

  for (c5_i154 = 0; c5_i154 < 19200; c5_i154++) {
    c5_d_varargin_1[c5_i154] = !c5_b_varargin_1[c5_i154];
  }

  c5_imfill(chartInstance, c5_d_varargin_1, chartInstance->c5_r_data, c5_r_size,
            c5_varargout_1);
  for (c5_i155 = 0; c5_i155 < 19200; c5_i155++) {
    c5_varargout_1[c5_i155] = (c5_varargout_1[c5_i155] &&
      c5_b_varargin_1[c5_i155]);
  }

  c5_b_idx = 0;
  c5_c_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (c5_c_ii - 1 < 19200)) {
    c5_d_ii = c5_c_ii - 1;
    if (c5_varargout_1[c5_d_ii]) {
      c5_b_idx++;
      if (c5_b_idx >= 19200) {
        exitg1 = true;
      } else {
        c5_c_ii++;
      }
    } else {
      c5_c_ii++;
    }
  }

  c5_b10 = (1 > c5_b_idx);
  if (c5_b10) {
    c5_i156 = 0;
  } else {
    c5_i156 = c5_b_idx;
  }

  c5_b_size[0] = c5_i156;
  c5_u_loop_ub = c5_i156 - 1;
  for (c5_i157 = 0; c5_i157 <= c5_u_loop_ub; c5_i157++) {
    chartInstance->c5_b_data[c5_i157] = 1 + c5_i157;
  }

  c5_iv7[0] = 1;
  c5_iv7[1] = c5_b_size[0];
  c5_indexShapeCheck(chartInstance, 19200, c5_iv7);
}

static void c5_b_warning(SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv14[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c5_d_y = NULL;
  static char_T c5_cv15[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c5_e_y = NULL;
  static char_T c5_msgID[26] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w',
    's', 'e', 'l', 'e', 'c', 't', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n',
    'g', 'e' };

  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv14, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv15, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_msgID, 10, 0U, 1U, 0U, 2, 1, 26),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c5_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c5_d_y, 14, c5_e_y));
}

static void c5_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1], real_T c5_d_x_data[], int32_T
  c5_b_x_size[1])
{
  int32_T c5_loop_ub;
  int32_T c5_i158;
  int32_T c5_b_idx_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i159;
  int32_T c5_d_idx_data[19200];
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i158 = 0; c5_i158 <= c5_loop_ub; c5_i158++) {
    c5_d_x_data[c5_i158] = c5_c_x_data[c5_i158];
  }

  c5_b_idx_size[0] = c5_idx_size[0];
  c5_b_loop_ub = c5_idx_size[0] - 1;
  for (c5_i159 = 0; c5_i159 <= c5_b_loop_ub; c5_i159++) {
    c5_d_idx_data[c5_i159] = c5_c_idx_data[c5_i159];
  }

  c5_c_nullAssignment(chartInstance, c5_d_x_data, c5_b_x_size, c5_d_idx_data,
                      c5_b_idx_size);
}

static void c5_validate_inputs(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1])
{
  int32_T c5_n;
  boolean_T c5_p;
  real_T c5_d7;
  int32_T c5_i160;
  int32_T c5_k;
  real_T c5_b_k;
  const mxArray *c5_c_y = NULL;
  int32_T c5_x;
  const mxArray *c5_d_y = NULL;
  int32_T c5_b_x;
  boolean_T exitg1;
  (void)chartInstance;
  (void)c5_c_x_data;
  c5_n = c5_x_size[0];
  c5_p = true;
  c5_d7 = (real_T)c5_idx_size[0];
  c5_i160 = (int32_T)c5_d7 - 1;
  c5_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_k <= c5_i160)) {
    c5_b_k = 1.0 + (real_T)c5_k;
    if ((c5_c_idx_data[(int32_T)c5_b_k - 1] < 1) || (c5_c_idx_data[(int32_T)
         c5_b_k - 1] > c5_n)) {
      c5_p = false;
      exitg1 = true;
    } else {
      c5_x = c5_c_idx_data[(int32_T)c5_b_k - 1];
      c5_b_x = c5_x;
      if (c5_c_idx_data[(int32_T)c5_b_k - 1] != c5_b_x) {
        c5_p = false;
        exitg1 = true;
      } else {
        c5_k++;
      }
    }
  }

  if (c5_p) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_d_y)));
  }
}

static void c5_make_bitarray(SFc5_flightControlSystemInstanceStruct
  *chartInstance, int32_T c5_n, int32_T c5_c_idx_data[], int32_T c5_idx_size[1],
  boolean_T c5_b_b_data[], int32_T c5_b_size[2])
{
  int32_T c5_i161;
  int32_T c5_i162;
  int32_T c5_loop_ub;
  int32_T c5_i163;
  int32_T c5_i164;
  int32_T c5_k;
  int32_T c5_b_k;
  (void)chartInstance;
  c5_b_size[0] = 1;
  c5_b_size[1] = c5_n;
  c5_i161 = c5_b_size[0];
  c5_i162 = c5_b_size[1];
  c5_loop_ub = c5_n - 1;
  for (c5_i163 = 0; c5_i163 <= c5_loop_ub; c5_i163++) {
    c5_b_b_data[c5_i163] = false;
  }

  c5_i164 = c5_idx_size[0] - 1;
  for (c5_k = 0; c5_k <= c5_i164; c5_k++) {
    c5_b_k = c5_k;
    c5_b_b_data[c5_c_idx_data[c5_b_k] - 1] = true;
  }
}

static int32_T c5_num_true(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_b_b_data[], int32_T c5_b_size[2])
{
  int32_T c5_n;
  int32_T c5_i165;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_i166;
  int32_T c5_i167;
  (void)chartInstance;
  c5_n = 0;
  c5_i165 = c5_b_size[1] - 1;
  for (c5_k = 0; c5_k <= c5_i165; c5_k++) {
    c5_b_k = c5_k;
    c5_i166 = c5_b_size[1];
    c5_i167 = c5_i166;
    c5_n += (int32_T)c5_b_b_data[c5_b_k];
  }

  return c5_n;
}

static boolean_T c5_allinrange(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], real_T c5_lo,
  int32_T c5_hi)
{
  boolean_T c5_p;
  real_T c5_d8;
  int32_T c5_i168;
  int32_T c5_k;
  real_T c5_b_k;
  boolean_T c5_b11;
  int32_T exitg1;
  (void)chartInstance;
  (void)c5_lo;
  c5_d8 = (real_T)c5_x_size[0];
  c5_i168 = (int32_T)c5_d8 - 1;
  c5_k = 0;
  do {
    exitg1 = 0;
    if (c5_k <= c5_i168) {
      c5_b_k = 1.0 + (real_T)c5_k;
      if ((c5_c_x_data[(int32_T)c5_b_k - 1] >= 1.0) && (c5_c_x_data[(int32_T)
           c5_b_k - 1] <= (real_T)c5_hi)) {
        c5_b11 = true;
      } else {
        c5_b11 = false;
      }

      if (!c5_b11) {
        c5_p = false;
        exitg1 = 1;
      } else {
        c5_k++;
      }
    } else {
      c5_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c5_p;
}

static boolean_T c5_isequal(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_b_varargin_1[2], real_T c5_varargin_2[2])
{
  boolean_T c5_p;
  boolean_T c5_b_p;
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_x1;
  real_T c5_x2;
  boolean_T c5_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c5_p = false;
  c5_b_p = true;
  c5_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_k < 2)) {
    c5_b_k = 1.0 + (real_T)c5_k;
    c5_x1 = c5_b_varargin_1[(int32_T)c5_b_k - 1];
    c5_x2 = c5_varargin_2[(int32_T)c5_b_k - 1];
    c5_c_p = (c5_x1 == c5_x2);
    if (!c5_c_p) {
      c5_b_p = false;
      exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (!c5_b_p) {
  } else {
    c5_p = true;
  }

  return c5_p;
}

static void c5_imfill(SFc5_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c5_b_varargin_1[19200], real_T
                      c5_c_varargin_2_data[], int32_T c5_varargin_2_size[1],
                      boolean_T c5_I2[19200])
{
  int32_T c5_b_varargin_2_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i169;
  static char_T c5_cv16[36] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'n', 'o', 'I', 'n', 't', 'e', 'r', 'a', 'c', 't', 'i',
    'v', 'e', 'I', 'n', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  int32_T c5_c_varargin_2_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i170;
  int32_T c5_locationsVar_size[1];
  int32_T c5_i171;
  int32_T c5_i172;
  boolean_T c5_mask[19200];
  int32_T c5_i173;
  int32_T c5_tmp_size[1];
  int32_T c5_c_loop_ub;
  int32_T c5_i174;
  int32_T c5_b_tmp_size[1];
  int32_T c5_d_loop_ub;
  int32_T c5_i175;
  boolean_T c5_d_tmp_data[19200];
  int32_T c5_e_loop_ub;
  int32_T c5_i176;
  int32_T c5_i177;
  real_T c5_imSizeT[2];
  int32_T c5_i178;
  c5_b_varargin_2_size[0] = c5_varargin_2_size[0];
  c5_loop_ub = c5_varargin_2_size[0] - 1;
  for (c5_i169 = 0; c5_i169 <= c5_loop_ub; c5_i169++) {
    chartInstance->c5_varargin_2_data[c5_i169] = c5_c_varargin_2_data[c5_i169];
  }

  if (!c5_b_isequal(chartInstance, chartInstance->c5_varargin_2_data,
                    c5_b_varargin_2_size, 0.0)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_c_emlrt_marshallOut(chartInstance, c5_cv16), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_c_emlrt_marshallOut(chartInstance, c5_cv16))));
  }

  c5_c_varargin_2_size[0] = c5_varargin_2_size[0];
  c5_b_loop_ub = c5_varargin_2_size[0] - 1;
  for (c5_i170 = 0; c5_i170 <= c5_b_loop_ub; c5_i170++) {
    chartInstance->c5_b_varargin_2_data[c5_i170] = c5_c_varargin_2_data[c5_i170];
  }

  c5_checkLocations(chartInstance, chartInstance->c5_b_varargin_2_data,
                    c5_c_varargin_2_size, chartInstance->c5_locationsVar_data,
                    c5_locationsVar_size);
  for (c5_i171 = 0; c5_i171 < 19200; c5_i171++) {
    c5_mask[c5_i171] = c5_b_varargin_1[c5_i171];
  }

  for (c5_i172 = 0; c5_i172 < 19200; c5_i172++) {
    c5_mask[c5_i172] = !c5_mask[c5_i172];
  }

  for (c5_i173 = 0; c5_i173 < 19200; c5_i173++) {
    c5_I2[c5_i173] = false;
  }

  c5_tmp_size[0] = c5_locationsVar_size[0];
  c5_c_loop_ub = c5_locationsVar_size[0] - 1;
  for (c5_i174 = 0; c5_i174 <= c5_c_loop_ub; c5_i174++) {
    chartInstance->c5_c_tmp_data[c5_i174] = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)chartInstance->c5_locationsVar_data[c5_i174], 1, 19200);
  }

  c5_b_tmp_size[0] = c5_locationsVar_size[0];
  c5_d_loop_ub = c5_locationsVar_size[0] - 1;
  for (c5_i175 = 0; c5_i175 <= c5_d_loop_ub; c5_i175++) {
    c5_d_tmp_data[c5_i175] = c5_mask[(int32_T)
      chartInstance->c5_locationsVar_data[c5_i175] - 1];
  }

  _SFD_SUB_ASSIGN_SIZE_CHECK_1D(c5_tmp_size[0], c5_b_tmp_size[0]);
  c5_e_loop_ub = c5_b_tmp_size[0] - 1;
  for (c5_i176 = 0; c5_i176 <= c5_e_loop_ub; c5_i176++) {
    c5_I2[chartInstance->c5_c_tmp_data[c5_i176] - 1] = c5_d_tmp_data[c5_i176];
  }

  for (c5_i177 = 0; c5_i177 < 2; c5_i177++) {
    c5_imSizeT[c5_i177] = 120.0 + 40.0 * (real_T)c5_i177;
  }

  ippreconstruct_uint8(c5_I2, c5_mask, c5_imSizeT, 2.0);
  for (c5_i178 = 0; c5_i178 < 19200; c5_i178++) {
    c5_I2[c5_i178] = (c5_b_varargin_1[c5_i178] || c5_I2[c5_i178]);
  }
}

static boolean_T c5_b_isequal(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_varargin_1_data[], int32_T c5_varargin_1_size[1],
  real_T c5_varargin_2)
{
  boolean_T c5_p;
  boolean_T c5_b_p;
  boolean_T c5_c_p;
  boolean_T c5_d_p;
  real_T c5_x1;
  boolean_T c5_e_p;
  (void)chartInstance;
  (void)c5_varargin_2;
  c5_p = false;
  c5_b_p = false;
  if ((real_T)c5_varargin_1_size[0] != 1.0) {
  } else {
    c5_b_p = true;
  }

  if (c5_b_p) {
    c5_c_p = true;
  } else {
    c5_c_p = false;
  }

  c5_d_p = c5_c_p;
  if (c5_c_p && (c5_varargin_1_size[0] != 0)) {
    c5_x1 = c5_varargin_1_data[0];
    c5_e_p = (c5_x1 == 0.0);
    if (!c5_e_p) {
      c5_d_p = false;
    }
  }

  if (!c5_d_p) {
  } else {
    c5_p = true;
  }

  return c5_p;
}

static void c5_checkLocations(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_locations_data[], int32_T c5_locations_size[1],
  real_T c5_b_locationsVar_data[], int32_T c5_locationsVar_size[1])
{
  int32_T c5_b_locations_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i179;
  int32_T c5_i180;
  int32_T c5_c_locations_size[1];
  int32_T c5_badPixels_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_i181;
  int32_T c5_i182;
  int32_T c5_d_loop_ub;
  int32_T c5_tmp_size[1];
  boolean_T c5_badPixels_data[19200];
  int32_T c5_i183;
  int32_T c5_e_loop_ub;
  int32_T c5_i184;
  int32_T c5_f_loop_ub;
  boolean_T c5_d_tmp_data[19200];
  int32_T c5_i185;
  int32_T c5_g_loop_ub;
  int32_T c5_i186;
  int32_T c5_b_badPixels_size[1];
  int32_T c5_h_loop_ub;
  int32_T c5_i187;
  boolean_T c5_b_badPixels_data[19200];
  real_T c5_numelBadPix;
  int32_T c5_i188;
  int32_T c5_s;
  real_T c5_b_s;
  c5_b_locations_size[0] = c5_locations_size[0];
  c5_loop_ub = c5_locations_size[0] - 1;
  for (c5_i179 = 0; c5_i179 <= c5_loop_ub; c5_i179++) {
    chartInstance->c5_locations_data[c5_i179] = c5_c_locations_data[c5_i179];
  }

  c5_validateattributes(chartInstance, chartInstance->c5_locations_data,
                        c5_b_locations_size);
  c5_i180 = c5_locationsVar_size[0];
  c5_locationsVar_size[0] = 0;
  if (c5_locations_size[0] != 0) {
    c5_c_locations_size[0] = c5_locations_size[0] + c5_locationsVar_size[0];
    c5_b_loop_ub = c5_locations_size[0] - 1;
    for (c5_i181 = 0; c5_i181 <= c5_b_loop_ub; c5_i181++) {
      chartInstance->c5_b_locations_data[c5_i181] = c5_c_locations_data[c5_i181];
    }

    c5_d_loop_ub = c5_locationsVar_size[0] - 1;
    for (c5_i183 = 0; c5_i183 <= c5_d_loop_ub; c5_i183++) {
      chartInstance->c5_b_locations_data[c5_i183 + c5_locations_size[0]] =
        c5_b_locationsVar_data[c5_i183];
    }

    c5_locationsVar_size[0] = c5_c_locations_size[0];
    c5_f_loop_ub = c5_c_locations_size[0] - 1;
    for (c5_i185 = 0; c5_i185 <= c5_f_loop_ub; c5_i185++) {
      c5_b_locationsVar_data[c5_i185] = chartInstance->
        c5_b_locations_data[c5_i185];
    }
  }

  c5_badPixels_size[0] = c5_locations_size[0];
  c5_c_loop_ub = c5_locations_size[0] - 1;
  for (c5_i182 = 0; c5_i182 <= c5_c_loop_ub; c5_i182++) {
    c5_badPixels_data[c5_i182] = (c5_c_locations_data[c5_i182] < 1.0);
  }

  c5_tmp_size[0] = c5_locations_size[0];
  c5_e_loop_ub = c5_locations_size[0] - 1;
  for (c5_i184 = 0; c5_i184 <= c5_e_loop_ub; c5_i184++) {
    c5_d_tmp_data[c5_i184] = (c5_c_locations_data[c5_i184] > 19200.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_badPixels_size[0], c5_tmp_size[0]);
  c5_badPixels_size[0];
  c5_g_loop_ub = c5_badPixels_size[0] - 1;
  for (c5_i186 = 0; c5_i186 <= c5_g_loop_ub; c5_i186++) {
    c5_badPixels_data[c5_i186] = (c5_badPixels_data[c5_i186] ||
      c5_d_tmp_data[c5_i186]);
  }

  c5_b_badPixels_size[0] = c5_badPixels_size[0];
  c5_h_loop_ub = c5_badPixels_size[0] - 1;
  for (c5_i187 = 0; c5_i187 <= c5_h_loop_ub; c5_i187++) {
    c5_b_badPixels_data[c5_i187] = c5_badPixels_data[c5_i187];
  }

  if (c5_any(chartInstance, c5_b_badPixels_data, c5_b_badPixels_size)) {
    c5_numelBadPix = (real_T)c5_badPixels_size[0];
    c5_c_warning(chartInstance);
    c5_i188 = (int32_T)((1.0 + (-1.0 - c5_numelBadPix)) / -1.0);
    _SFD_FOR_LOOP_VECTOR_CHECK(c5_numelBadPix, -1.0, 1.0, mxDOUBLE_CLASS,
      c5_i188);
    for (c5_s = 0; c5_s < c5_i188; c5_s++) {
      c5_b_s = c5_numelBadPix + -(real_T)c5_s;
      if (c5_badPixels_data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c5_b_s, 1, c5_badPixels_size[0]) - 1]) {
        c5_d_nullAssignment(chartInstance, c5_b_locationsVar_data,
                            c5_locationsVar_size, (int32_T)c5_b_s);
      }
    }
  }
}

static void c5_validateattributes(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_a_data[], int32_T c5_a_size[1])
{
  boolean_T c5_p;
  real_T c5_d9;
  int32_T c5_i189;
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_x;
  boolean_T c5_b12;
  boolean_T c5_b_p;
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv17[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's',
    'i', 't', 'i', 'v', 'e' };

  boolean_T c5_c_p;
  const mxArray *c5_d_y = NULL;
  real_T c5_d10;
  static char_T c5_cv18[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  int32_T c5_i190;
  const mxArray *c5_e_y = NULL;
  int32_T c5_c_k;
  static char_T c5_cv19[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  real_T c5_d_k;
  real_T c5_b_x;
  boolean_T c5_b13;
  real_T c5_c_x;
  real_T c5_d_x;
  const mxArray *c5_f_y = NULL;
  boolean_T c5_d_p;
  static char_T c5_cv20[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't',
    'e', 'g', 'e', 'r' };

  const mxArray *c5_g_y = NULL;
  boolean_T c5_e_p;
  const mxArray *c5_h_y = NULL;
  static char_T c5_cv21[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  boolean_T exitg1;
  (void)chartInstance;
  c5_p = true;
  c5_d9 = (real_T)c5_a_size[0];
  c5_i189 = (int32_T)c5_d9 - 1;
  c5_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_k <= c5_i189)) {
    c5_b_k = 1.0 + (real_T)c5_k;
    c5_x = c5_a_data[(int32_T)c5_b_k - 1];
    c5_b_p = !(c5_x <= 0.0);
    if (c5_b_p) {
      c5_k++;
    } else {
      c5_p = false;
      exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b12 = true;
  } else {
    c5_b12 = false;
  }

  if (c5_b12) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv17, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv18, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv19, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c5_d_y, 14, c5_e_y)));
  }

  c5_c_p = true;
  c5_d10 = (real_T)c5_a_size[0];
  c5_i190 = (int32_T)c5_d10 - 1;
  c5_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_c_k <= c5_i190)) {
    c5_d_k = 1.0 + (real_T)c5_c_k;
    c5_b_x = c5_a_data[(int32_T)c5_d_k - 1];
    c5_c_x = c5_b_x;
    c5_d_x = c5_c_x;
    if (c5_d_x == c5_b_x) {
      c5_d_p = true;
    } else {
      c5_d_p = false;
    }

    c5_e_p = c5_d_p;
    if (c5_e_p) {
      c5_c_k++;
    } else {
      c5_c_p = false;
      exitg1 = true;
    }
  }

  if (c5_c_p) {
    c5_b13 = true;
  } else {
    c5_b13 = false;
  }

  if (c5_b13) {
  } else {
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv20, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv0, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv21, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c5_g_y, 14, c5_h_y)));
  }
}

static boolean_T c5_any(SFc5_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c5_c_x_data[], int32_T c5_x_size[1])
{
  boolean_T c5_c_y;
  boolean_T c5_b14;
  const mxArray *c5_d_y = NULL;
  static char_T c5_cv22[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c5_e_y = NULL;
  real_T c5_vlen;
  real_T c5_c_a;
  int32_T c5_c;
  int32_T c5_d_a;
  int32_T c5_vspread;
  int32_T c5_b;
  int32_T c5_i2;
  int32_T c5_e_a;
  int32_T c5_ix;
  boolean_T c5_b15;
  boolean_T exitg1;
  (void)chartInstance;
  if ((c5_x_size[0] == 1) || ((real_T)c5_x_size[0] != 1.0)) {
    c5_b14 = true;
  } else {
    c5_b14 = false;
  }

  if (c5_b14) {
  } else {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv22, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv22, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_e_y)));
  }

  c5_c_y = false;
  c5_vlen = (real_T)c5_x_size[0];
  c5_c_a = c5_vlen;
  c5_c = (int32_T)c5_c_a;
  c5_d_a = c5_c - 1;
  c5_vspread = c5_d_a;
  c5_b = c5_vspread;
  c5_i2 = c5_b;
  c5_e_a = c5_i2;
  c5_i2 = c5_e_a;
  c5_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c5_ix + 1 <= c5_i2 + 1)) {
    if (!c5_c_x_data[c5_ix]) {
      c5_b15 = true;
    } else {
      c5_b15 = false;
    }

    if (!c5_b15) {
      c5_c_y = true;
      exitg1 = true;
    } else {
      c5_ix++;
    }
  }

  return c5_c_y;
}

static void c5_c_warning(SFc5_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c5_c_y = NULL;
  static char_T c5_cv23[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c5_d_y = NULL;
  static char_T c5_cv24[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c5_e_y = NULL;
  static char_T c5_msgID[24] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'l', 'l', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv23, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv24, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c5_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c5_d_y, 14, c5_e_y));
}

static void c5_b_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_idx,
  real_T c5_d_x_data[], int32_T c5_b_x_size[1])
{
  int32_T c5_loop_ub;
  int32_T c5_i191;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i191 = 0; c5_i191 <= c5_loop_ub; c5_i191++) {
    c5_d_x_data[c5_i191] = c5_c_x_data[c5_i191];
  }

  c5_d_nullAssignment(chartInstance, c5_d_x_data, c5_b_x_size, c5_idx);
}

static const mxArray *c5_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[30])
{
  const mxArray *c5_c_y = NULL;
  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_d_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c5_c_y;
}

static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[34])
{
  const mxArray *c5_c_y = NULL;
  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_d_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  return c5_c_y;
}

static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_flightControlSystemInstanceStruct *chartInstance, const char_T c5_d_u[36])
{
  const mxArray *c5_c_y = NULL;
  (void)chartInstance;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_d_u, 10, 0U, 1U, 0U, 2, 1, 36),
                false);
  return c5_c_y;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int32_T c5_d_u;
  const mxArray *c5_c_y = NULL;
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_d_u = *(int32_T *)c5_inData;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_c_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_c_y;
  int32_T c5_i192;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_d_u), &c5_i192, 1, 6, 0U, 0, 0U, 0);
  c5_c_y = c5_i192;
  sf_mex_destroy(&c5_d_u);
  return c5_c_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_c_y;
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_flightControlSystem, const
  char_T *c5_identifier)
{
  uint8_T c5_c_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_flightControlSystem), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_flightControlSystem);
  return c5_c_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c5_d_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_c_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_d_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_c_y = c5_u0;
  sf_mex_destroy(&c5_d_u);
  return c5_c_y;
}

static void c5_b_round(SFc5_flightControlSystemInstanceStruct *chartInstance,
  real_T c5_c_x_data[], int32_T c5_x_size[1])
{
  int32_T c5_nx;
  int32_T c5_k;
  int32_T c5_b_k;
  real_T c5_x;
  real_T c5_b_x;
  (void)chartInstance;
  c5_nx = c5_x_size[0] - 1;
  for (c5_k = 0; c5_k <= c5_nx; c5_k++) {
    c5_b_k = c5_k;
    c5_x = c5_c_x_data[c5_b_k];
    c5_b_x = c5_x;
    c5_c_x_data[c5_b_k] = c5_b_x;
  }
}

static void c5_c_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T
  c5_c_idx_data[], int32_T c5_idx_size[1])
{
  int32_T c5_b_x_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i193;
  int32_T c5_b_idx_size[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i194;
  int32_T c5_nxin;
  int32_T c5_nrowx;
  int32_T c5_c_idx_size[1];
  int32_T c5_c_loop_ub;
  int32_T c5_i195;
  boolean_T c5_b_b_data[19200];
  int32_T c5_b_size[2];
  int32_T c5_b_b_size[2];
  int32_T c5_i196;
  int32_T c5_i197;
  int32_T c5_d_loop_ub;
  int32_T c5_i198;
  int32_T c5_nxout;
  boolean_T c5_c_b_data[19200];
  int32_T c5_nb;
  int32_T c5_k0;
  int32_T c5_k;
  int32_T c5_b_k;
  boolean_T c5_b16;
  int32_T c5_i199;
  c5_b_x_size[0] = c5_x_size[0];
  c5_loop_ub = c5_x_size[0] - 1;
  for (c5_i193 = 0; c5_i193 <= c5_loop_ub; c5_i193++) {
    chartInstance->c5_b_x_data[c5_i193] = c5_c_x_data[c5_i193];
  }

  c5_b_idx_size[0] = c5_idx_size[0];
  c5_b_loop_ub = c5_idx_size[0] - 1;
  for (c5_i194 = 0; c5_i194 <= c5_b_loop_ub; c5_i194++) {
    chartInstance->c5_idx_data[c5_i194] = c5_c_idx_data[c5_i194];
  }

  c5_validate_inputs(chartInstance, chartInstance->c5_b_x_data, c5_b_x_size,
                     chartInstance->c5_idx_data, c5_b_idx_size);
  c5_nxin = c5_x_size[0];
  c5_nrowx = c5_x_size[0];
  c5_c_idx_size[0] = c5_idx_size[0];
  c5_c_loop_ub = c5_idx_size[0] - 1;
  for (c5_i195 = 0; c5_i195 <= c5_c_loop_ub; c5_i195++) {
    chartInstance->c5_b_idx_data[c5_i195] = c5_c_idx_data[c5_i195];
  }

  c5_make_bitarray(chartInstance, c5_nxin, chartInstance->c5_b_idx_data,
                   c5_c_idx_size, c5_b_b_data, c5_b_size);
  c5_b_b_size[0] = 1;
  c5_b_b_size[1] = c5_b_size[1];
  c5_i196 = c5_b_b_size[0];
  c5_i197 = c5_b_b_size[1];
  c5_d_loop_ub = c5_b_size[0] * c5_b_size[1] - 1;
  for (c5_i198 = 0; c5_i198 <= c5_d_loop_ub; c5_i198++) {
    c5_c_b_data[c5_i198] = c5_b_b_data[c5_i198];
  }

  c5_nxout = c5_nxin - c5_num_true(chartInstance, c5_c_b_data, c5_b_b_size);
  c5_nb = c5_b_size[1];
  c5_k0 = -1;
  for (c5_k = 0; c5_k < c5_nxin; c5_k++) {
    c5_b_k = c5_k;
    if ((c5_b_k + 1 > c5_nb) || (!c5_b_b_data[c5_b_k])) {
      c5_k0++;
      c5_c_x_data[c5_k0] = c5_c_x_data[c5_b_k];
    }
  }

  if (c5_nxout <= c5_nrowx) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c5_emlrt_marshallOut(chartInstance, c5_cv1), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv1))));
  }

  c5_b16 = (1 > c5_nxout);
  if (c5_b16) {
    c5_i199 = 0;
  } else {
    c5_i199 = c5_nxout;
  }

  c5_x_size[0] = c5_i199;
}

static void c5_d_nullAssignment(SFc5_flightControlSystemInstanceStruct
  *chartInstance, real_T c5_c_x_data[], int32_T c5_x_size[1], int32_T c5_idx)
{
  int32_T c5_b_idx;
  int32_T c5_c_idx;
  real_T c5_d11;
  int32_T c5_n;
  boolean_T c5_p;
  int32_T c5_x;
  int32_T c5_b_x;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_idx;
  const mxArray *c5_d_y = NULL;
  int32_T c5_nrowx;
  int32_T c5_nrows;
  int32_T c5_i;
  int32_T c5_c_x[2];
  const mxArray *c5_e_y = NULL;
  boolean_T c5_b17;
  const mxArray *c5_f_y = NULL;
  int32_T c5_i200;
  int32_T c5_b_x_size[1];
  int32_T c5_loop_ub;
  int32_T c5_i201;
  int32_T c5_b_loop_ub;
  int32_T c5_i202;
  c5_b_idx = c5_idx;
  c5_c_idx = c5_b_idx;
  c5_d11 = (real_T)c5_x_size[0];
  c5_n = (int32_T)c5_d11;
  c5_p = true;
  if (c5_c_idx > c5_n) {
    c5_p = false;
  } else {
    c5_x = c5_c_idx;
    c5_b_x = c5_x;
    if (c5_c_idx != c5_b_x) {
      c5_p = false;
    }
  }

  if (c5_p) {
  } else {
    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_d_y)));
  }

  c5_d_idx = c5_idx;
  c5_nrowx = c5_x_size[0];
  c5_nrows = c5_nrowx - 1;
  for (c5_i = c5_d_idx; c5_i <= c5_nrows; c5_i++) {
    c5_c_x[0] = c5_x_size[0];
    c5_c_x[1] = 1;
    c5_c_x_data[c5_i - 1] = c5_c_x_data[c5_i];
  }

  if (c5_nrows <= c5_nrowx) {
  } else {
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c5_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c5_f_y)));
  }

  c5_b17 = (1 > c5_nrows);
  if (c5_b17) {
    c5_i200 = -1;
  } else {
    c5_i200 = c5_nrows - 1;
  }

  c5_b_x_size[0] = c5_i200 + 1;
  c5_loop_ub = c5_i200;
  for (c5_i201 = 0; c5_i201 <= c5_loop_ub; c5_i201++) {
    chartInstance->c5_x_data[c5_i201] = c5_c_x_data[c5_i201];
  }

  c5_x_size[0] = c5_b_x_size[0];
  c5_b_loop_ub = c5_b_x_size[0] - 1;
  for (c5_i202 = 0; c5_i202 <= c5_b_loop_ub; c5_i202++) {
    c5_c_x_data[c5_i202] = chartInstance->c5_x_data[c5_i202];
  }
}

static void init_dsm_address_info(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_c_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_b_y = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c5_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3180170U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1435906444U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(240354405U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1427737251U);
}

mxArray *sf_c5_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,6);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  return(mxcell3p);
}

mxArray *sf_c5_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ordfilt2_boolean");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/E/g"
    "AC7ldAcT+En1kcn5hcklmWGp9sGp+Wk5meUeKcn1dSlJ8TXFlckpoL8x8AZtkcuQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_flightControlSystemInstanceStruct *chartInstance =
      (SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _flightControlSystemMachineNumber_,
           5,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_flightControlSystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_flightControlSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _flightControlSystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _flightControlSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_flightControlSystemInstanceStruct *chartInstance =
      (SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_c_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_b_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sSG89PvKCbO9t7UzRjIvn2F";
}

static void sf_opaque_initialize_c5_flightControlSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_flightControlSystem(void *chartInstanceVar)
{
  enable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_flightControlSystem(void *chartInstanceVar)
{
  disable_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c5_flightControlSystem
    ((SFc5_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c5_flightControlSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    finalize_c5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_flightControlSystem
      ((SFc5_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc5_flightControlSystem((SFc5_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_flightControlSystem_get_post_codegen_info(void)
{
  return
    (
     "eNrtVctu00AUdaKAqESrLIrYsMgONkgICdGuKM0DItImqtuyrCb2TTxkPGPm4Tbs2bHiK/gBJD4"
     "DiR1f0WV3cO085dhOS2glJCxNxuOce+5z7rUKzT0Lnw1c3/HnNu53cBWt0XNrfC7MrdH3kvVwfD"
     "5CEDd+h0jiKyv34cSHA1CCGU0Fb/KeSIVR3gMJ3EFsIKTOYlPUN4zyQcNwJ+JTbz3qeLYnDHN3U"
     "Za4bc6GyBYY3UGeGpXg6AaAqz0pTN9rMNKfWiz1adUDZ6CMn+eCAm2bIDJL7RmmacCgfgZOkytN"
     "0GI1s83WRENVn2W6GXmq7AlQ+AGjhKd66xFlQ4AB1nAUuPjbNhqdSsIcj0i9Cx4JQbXoIOYUHJK"
     "cVOEfXcqJFpISVvdZNRJctK3D0J494QLLCQjatiuBDAJBuc7Ov91AT+ucdBnUoGv62Ww2vDdR8o"
     "8pnILMjFuvKkKQpA9tnqk0Dkj9LM7WtEoWYZr6cEzkSwfzp8DNrF6sHGUTzBMcokQWDGInm+pQ0"
     "hDDm8lm/GZUmcuujPFHyVbLYDFbPYS8LEzZGg6vEsZUJuxQBC0IgcWsNaJJPmzEmo4LpAhIH6vW"
     "xSBHJV4V3KULuXCM0sKvYrnVWq197BTpxs1gTa5B9ogDafdWOR64hgE6ip1Jx+pSSF2qomwtQY1"
     "zugxlqZ7htVMhB+hozrWfuRDlIK8/RH35iTXry3cv0Zcncsn90RxPIYXHmtuTeteK+XqL+FYYy+"
     "3Mya0n9JQSchGujOur/vXx4t7jT5/Pv23u//yxvor+L8WrzbGN8fnBpGFMyylcyGKEfT1nVymF/"
     "/4cf3l8Vvarre1O+KbabW/r50cfDt41Q/60EfNdFPLtLSbsnXyvRJ1rGMR9SEmn6Y4HbHQmZjR2"
     "Iv6tOXtvL4nH2vj76Dl/sZr85k4yj6Ul8mV8Gybq9s/1V3ZWkx/p7yyxv5LIdyWeTycEp00IJ86"
     "zkx6jfS9qeloKZg+VBn/jL9yzq8pZNyz3r9j5Py7X799l5tZNy1k3LLeqf1ed36vM+2SfsxL48g"
     "p6rhs/v/8GPcBSlA=="
     );
}

static void mdlSetWorkWidths_c5_flightControlSystem(SimStruct *S)
{
  sf_set_work_widths(S, sf_c5_flightControlSystem_get_post_codegen_info());
  ssSetChecksum0(S,(2248111285U));
  ssSetChecksum1(S,(2351764984U));
  ssSetChecksum2(S,(347664530U));
  ssSetChecksum3(S,(231987790U));
}

static void mdlRTW_c5_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_flightControlSystem(SimStruct *S)
{
  SFc5_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc5_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc5_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_flightControlSystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_flightControlSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c5_flightControlSystem(chartInstance);
}

void c5_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
