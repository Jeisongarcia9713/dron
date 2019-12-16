/* Include files */

#include "tomas_sfun.h"
#include "c2_tomas.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "tomas_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[5] = { "m", "nargin", "nargout", "u",
  "y" };

static emlrtRTEInfo c2_emlrtRTEI = { 147,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 250,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 250,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 251,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 251,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 252,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 132,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 133,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 134,/* lineNo */
  27,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 134,/* lineNo */
  43,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 153,/* lineNo */
  25,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 153,/* lineNo */
  9,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 72,/* lineNo */
  13,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 690,/* lineNo */
  5,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 696,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 114,/* lineNo */
  6,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 697,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 114,/* lineNo */
  17,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 697,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 820,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 60,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 60,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 60,/* lineNo */
  15,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 61,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 61,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 60,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 397,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 65,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 66,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 257,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 90,/* lineNo */
  40,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 94,/* lineNo */
  47,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_ac_emlrtRTEI = { 202,/* lineNo */
  12,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_bc_emlrtRTEI = { 202,/* lineNo */
  25,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_cc_emlrtRTEI = { 214,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_dc_emlrtRTEI = { 243,/* lineNo */
  18,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_ec_emlrtRTEI = { 238,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_fc_emlrtRTEI = { 243,/* lineNo */
  36,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_gc_emlrtRTEI = { 238,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_hc_emlrtRTEI = { 243,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_ic_emlrtRTEI = { 254,/* lineNo */
  8,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_jc_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_kc_emlrtRTEI = { 12,/* lineNo */
  23,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_lc_emlrtRTEI = { 166,/* lineNo */
  32,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_mc_emlrtRTEI = { 168,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_nc_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_oc_emlrtRTEI = { 297,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_pc_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static const char_T c2_cv0[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
  'n', 't', 'e', 'g', 'e', 'r' };

static const real_T c2_dv0[13] = { 3.4813359214923066E-5, 0.00054457256285105169,
  0.0051667606200595231, 0.029732654490475546, 0.10377716120747749,
  0.219696252000246, 0.28209557151935094, 0.219696252000246, 0.10377716120747749,
  0.029732654490475546, 0.0051667606200595231, 0.00054457256285105169,
  3.4813359214923066E-5 };

static const char_T c2_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c2_cv2[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

/* Function Declarations */
static void initialize_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void initialize_params_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void enable_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void disable_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_tomas(SFc2_tomasInstanceStruct
  *chartInstance);
static void ext_mode_exec_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_tomas(SFc2_tomasInstanceStruct
  *chartInstance);
static void set_sim_state_c2_tomas(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void sf_gateway_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void mdl_start_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void c2_chartstep_c2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void initSimStructsc2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_c_m, const char_T *c2_identifier, boolean_T c2_c_y[19200]);
static void c2_b_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_c_y[19200]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_medfilt2(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], boolean_T c2_b[19200]);
static void c2_indexShapeCheck(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_matrixSize, int32_T c2_indexSize[2]);
static void c2_abs(SFc2_tomasInstanceStruct *chartInstance, real_T c2_c_x_data[],
                   int32_T c2_x_size[1], real_T c2_y_data[], int32_T c2_y_size[1]);
static void c2_padarray(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[2], boolean_T c2_b_b_data[],
  int32_T c2_b_size[2]);
static void c2_edge(SFc2_tomasInstanceStruct *chartInstance, boolean_T
                    c2_b_varargin_1[19200], boolean_T c2_varargout_1[19200]);
static void c2_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real32_T c2_b[19200]);
static void c2_padImage(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real32_T c2_c_a[21120]);
static void c2_b_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200]);
static void c2_b_padImage(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real32_T c2_c_a[20640]);
static void c2_c_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real32_T c2_b[19200]);
static void c2_d_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200]);
static void c2_hypot(SFc2_tomasInstanceStruct *chartInstance, real32_T c2_x
                     [19200], real32_T c2_c_y[19200], real32_T c2_r[19200]);
static void c2_warning(SFc2_tomasInstanceStruct *chartInstance);
static void c2_thinAndThreshold(SFc2_tomasInstanceStruct *chartInstance,
  real32_T c2_d_dx[19200], real32_T c2_d_dy[19200], real32_T c2_magGrad[19200],
  real_T c2_lowThresh_data[], int32_T c2_lowThresh_size[1], real_T
  c2_highThresh_data[], int32_T c2_highThresh_size[1], boolean_T c2_H[19200]);
static void c2_round(SFc2_tomasInstanceStruct *chartInstance, real_T
                     c2_c_x_data[], int32_T c2_x_size[1], real_T c2_d_x_data[],
                     int32_T c2_b_x_size[1]);
static void c2_bwselect(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], real_T c2_c_varargin_2_data[], int32_T
  c2_varargin_2_size[1], real_T c2_varargin_3_data[], int32_T
  c2_varargin_3_size[1], boolean_T c2_varargout_1[19200]);
static void c2_b_warning(SFc2_tomasInstanceStruct *chartInstance);
static void c2_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1], real_T c2_d_x_data[], int32_T c2_b_x_size[1]);
static void c2_validate_inputs(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1]);
static void c2_make_bitarray(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_n, int32_T c2_c_idx_data[], int32_T c2_idx_size[1], boolean_T c2_b_b_data[],
  int32_T c2_b_size[2]);
static int32_T c2_num_true(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_b_data[], int32_T c2_b_size[2]);
static boolean_T c2_allinrange(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], real_T c2_lo, int32_T c2_hi);
static boolean_T c2_isequal(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_b_varargin_1[2], real_T c2_varargin_2[2]);
static void c2_imfill(SFc2_tomasInstanceStruct *chartInstance, boolean_T
                      c2_b_varargin_1[19200], real_T c2_c_varargin_2_data[],
                      int32_T c2_varargin_2_size[1], boolean_T c2_I2[19200]);
static boolean_T c2_b_isequal(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_varargin_1_data[], int32_T c2_varargin_1_size[1], real_T c2_varargin_2);
static void c2_checkLocations(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_locations_data[], int32_T c2_locations_size[1], real_T
  c2_b_locationsVar_data[], int32_T c2_locationsVar_size[1]);
static void c2_validateattributes(SFc2_tomasInstanceStruct *chartInstance,
  real_T c2_a_data[], int32_T c2_a_size[1]);
static boolean_T c2_any(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_c_x_data[], int32_T c2_x_size[1]);
static void c2_c_warning(SFc2_tomasInstanceStruct *chartInstance);
static void c2_b_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_idx, real_T c2_d_x_data[],
  int32_T c2_b_x_size[1]);
static const mxArray *c2_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[30]);
static const mxArray *c2_b_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[34]);
static const mxArray *c2_c_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[36]);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_tomas, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_round(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1]);
static void c2_c_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1]);
static void c2_d_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_idx);
static void init_dsm_address_info(SFc2_tomasInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_tomasInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx, "Image_Toolbox", 2);
  setLegacyDebuggerFlag(chartInstance->S, true);
  setDebuggerFlag(chartInstance->S, true);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_tomas(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_tomas = 0U;
}

static void initialize_params_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_tomas(SFc2_tomasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void ext_mode_exec_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_tomas(SFc2_tomasInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createcellmatrix(2, 1), false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", *chartInstance->c2_b_y, 11, 0U, 1U,
    0U, 2, 120, 160), false);
  sf_mex_setcell(c2_c_y, 0, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_tomas;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_c_y, 1, c2_e_y);
  sf_mex_assign(&c2_st, c2_c_y, false);
  return c2_st;
}

static void set_sim_state_c2_tomas(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_d_u;
  boolean_T c2_bv0[19200];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_d_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_d_u, 0)), "y",
                      c2_bv0);
  for (c2_i0 = 0; c2_i0 < 19200; c2_i0++) {
    (*chartInstance->c2_b_y)[c2_i0] = c2_bv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_tomas = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_d_u, 1)), "is_active_c2_tomas");
  sf_mex_destroy(&c2_d_u);
  c2_update_debugger_state_c2_tomas(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void sf_gateway_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 19200; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_c_u)[c2_i1], 0U);
  }

  for (c2_i2 = 0; c2_i2 < 19200; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_c_u)[c2_i2]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_tomas(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i3 = 0; c2_i3 < 19200; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_b_y)[c2_i3], 1U);
  }

  for (c2_i4 = 0; c2_i4 < 19200; c2_i4++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_b_y)[c2_i4]);
  }
}

static void mdl_start_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    4U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 56);
}

static void c2_chartstep_c2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  int32_T c2_i5;
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i5 = 0; c2_i5 < 19200; c2_i5++) {
    chartInstance->c2_u[c2_i5] = (*chartInstance->c2_c_u)[c2_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_m, 0U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_u, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_y, 4U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  for (c2_i6 = 0; c2_i6 < 19200; c2_i6++) {
    chartInstance->c2_b_u[c2_i6] = chartInstance->c2_u[c2_i6];
  }

  c2_medfilt2(chartInstance, chartInstance->c2_b_u, chartInstance->c2_bv1);
  for (c2_i7 = 0; c2_i7 < 19200; c2_i7++) {
    chartInstance->c2_m[c2_i7] = chartInstance->c2_bv1[c2_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i8 = 0; c2_i8 < 19200; c2_i8++) {
    chartInstance->c2_b_m[c2_i8] = chartInstance->c2_m[c2_i8];
  }

  c2_edge(chartInstance, chartInstance->c2_b_m, chartInstance->c2_bv2);
  for (c2_i9 = 0; c2_i9 < 19200; c2_i9++) {
    chartInstance->c2_y[c2_i9] = chartInstance->c2_bv2[c2_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i10 = 0; c2_i10 < 19200; c2_i10++) {
    (*chartInstance->c2_b_y)[c2_i10] = chartInstance->c2_y[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_tomas(SFc2_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i11;
  int32_T c2_i12;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i13;
  boolean_T c2_d_u[19200];
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i11 = 0;
  for (c2_i12 = 0; c2_i12 < 160; c2_i12++) {
    for (c2_i13 = 0; c2_i13 < 120; c2_i13++) {
      c2_d_u[c2_i13 + c2_i11] = (*(boolean_T (*)[19200])c2_inData)[c2_i13 +
        c2_i11];
    }

    c2_i11 += 120;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_d_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_c_m, const char_T *c2_identifier, boolean_T c2_c_y[19200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_m), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_c_m);
}

static void c2_b_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_c_y[19200])
{
  boolean_T c2_bv3[19200];
  int32_T c2_i14;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), c2_bv3, 1, 11, 0U, 1, 0U, 2,
                120, 160);
  for (c2_i14 = 0; c2_i14 < 19200; c2_i14++) {
    c2_c_y[c2_i14] = c2_bv3[c2_i14];
  }

  sf_mex_destroy(&c2_d_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_c_m;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_c_y[19200];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_c_m = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_c_m), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_c_m);
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 160; c2_i16++) {
    for (c2_i17 = 0; c2_i17 < 120; c2_i17++) {
      (*(boolean_T (*)[19200])c2_outData)[c2_i17 + c2_i15] = c2_c_y[c2_i17 +
        c2_i15];
    }

    c2_i15 += 120;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_d_u;
  const mxArray *c2_c_y = NULL;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_d_u = *(real_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_c_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_c_y = c2_d0;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargin;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_c_y;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_nargin = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargin),
    &c2_thisId);
  sf_mex_destroy(&c2_nargin);
  *(real_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_tomas_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_medfilt2(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], boolean_T c2_b[19200])
{
  int32_T c2_idx;
  int32_T c2_tmp_size[1];
  int32_T c2_i18;
  int32_T c2_indices_size[1];
  int32_T c2_d_tmp_data[9];
  int32_T c2_i19;
  int32_T c2_j_size[1];
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b0;
  int32_T c2_indices_data[9];
  int32_T c2_b_j_data[9];
  int32_T c2_i20;
  int32_T c2_b_tmp_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i21;
  int32_T c2_iv0[2];
  int32_T c2_e_tmp_data[9];
  boolean_T c2_b1;
  int32_T c2_i22;
  int32_T c2_b_loop_ub;
  int32_T c2_i23;
  int32_T c2_iv1[2];
  boolean_T c2_b2;
  int32_T c2_i24;
  int32_T c2_c_loop_ub;
  int32_T c2_i25;
  int32_T c2_iv2[2];
  int32_T c2_rows_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i26;
  int32_T c2_cols_size[1];
  real_T c2_rows_data[9];
  int32_T c2_e_loop_ub;
  int32_T c2_i27;
  real_T c2_cols_data[9];
  int32_T c2_f_loop_ub;
  int32_T c2_i28;
  int32_T c2_g_loop_ub;
  int32_T c2_i29;
  int32_T c2_b_rows_size[1];
  int32_T c2_h_loop_ub;
  int32_T c2_i30;
  real_T c2_b_rows_data[9];
  real_T c2_varargin_1_data[9];
  int32_T c2_varargin_1_size[1];
  boolean_T c2_b3;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv4[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_n;
  const mxArray *c2_f_y = NULL;
  int32_T c2_last;
  real_T c2_ex;
  real_T c2_maxval;
  int32_T c2_k;
  int32_T c2_b_cols_size[1];
  int32_T c2_i_loop_ub;
  int32_T c2_i31;
  real_T c2_b_cols_data[9];
  boolean_T c2_b4;
  const mxArray *c2_g_y = NULL;
  static char_T c2_cv5[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv6[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_b_n;
  const mxArray *c2_j_y = NULL;
  int32_T c2_b_last;
  real_T c2_b_ex;
  real_T c2_b_maxval;
  int32_T c2_b_k;
  real_T c2_c_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_d_varargin_1;
  real_T c2_b_x;
  real_T c2_k_y;
  real_T c2_c_x;
  real_T c2_l_y;
  real_T c2_d_x;
  real_T c2_m_y;
  real_T c2_e_x;
  real_T c2_n_y;
  real_T c2_f_x;
  real_T c2_o_y;
  real_T c2_padSize;
  real_T c2_c_a;
  int32_T c2_i32;
  int32_T c2_i33;
  real_T c2_startIdx[2];
  boolean_T c2_e_varargin_1[19200];
  boolean_T c2_Apad_data[20336];
  int32_T c2_Apad_size[2];
  real_T c2_Ma;
  real_T c2_b_b;
  int32_T c2_j_loop_ub;
  int32_T c2_i34;
  int32_T c2_k_loop_ub;
  int32_T c2_i35;
  real_T c2_d1;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  real_T c2_sizeA[2];
  int32_T c2_i39;
  int32_T c2_i40;
  real_T c2_domainSizeT[2];
  real_T c2_dv1[2];
  boolean_T exitg1;
  c2_idx = 0;
  c2_tmp_size[0] = 9;
  for (c2_i18 = 0; c2_i18 < 9; c2_i18++) {
    c2_d_tmp_data[c2_i18] = 0;
  }

  c2_indices_size[0] = c2_tmp_size[0];
  c2_tmp_size[0] = 9;
  for (c2_i19 = 0; c2_i19 < 9; c2_i19++) {
    c2_d_tmp_data[c2_i19] = 0;
  }

  c2_j_size[0] = c2_tmp_size[0];
  c2_ii = 1;
  c2_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_jj <= 3)) {
    c2_idx++;
    c2_indices_data[c2_idx - 1] = c2_ii;
    c2_b_j_data[c2_idx - 1] = c2_jj;
    if (c2_idx >= 9) {
      exitg1 = true;
    } else {
      c2_ii++;
      if (c2_ii > 3) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b0 = (1 > c2_idx);
  if (c2_b0) {
    c2_i20 = 0;
  } else {
    c2_i20 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i20;
  c2_loop_ub = c2_i20 - 1;
  for (c2_i21 = 0; c2_i21 <= c2_loop_ub; c2_i21++) {
    c2_e_tmp_data[c2_i21] = 1 + c2_i21;
  }

  c2_iv0[0] = 1;
  c2_iv0[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 9, c2_iv0);
  c2_indices_size[0] = c2_i20;
  c2_b1 = (1 > c2_idx);
  if (c2_b1) {
    c2_i22 = 0;
  } else {
    c2_i22 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i22;
  c2_b_loop_ub = c2_i22 - 1;
  for (c2_i23 = 0; c2_i23 <= c2_b_loop_ub; c2_i23++) {
    c2_e_tmp_data[c2_i23] = 1 + c2_i23;
  }

  c2_iv1[0] = 1;
  c2_iv1[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 9, c2_iv1);
  c2_j_size[0] = c2_i22;
  c2_b2 = (1 > c2_idx);
  if (c2_b2) {
    c2_i24 = 0;
  } else {
    c2_i24 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i24;
  c2_c_loop_ub = c2_i24 - 1;
  for (c2_i25 = 0; c2_i25 <= c2_c_loop_ub; c2_i25++) {
    c2_e_tmp_data[c2_i25] = 1 + c2_i25;
  }

  c2_iv2[0] = 1;
  c2_iv2[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 9, c2_iv2);
  c2_rows_size[0] = c2_indices_size[0];
  c2_d_loop_ub = c2_indices_size[0] - 1;
  for (c2_i26 = 0; c2_i26 <= c2_d_loop_ub; c2_i26++) {
    c2_rows_data[c2_i26] = (real_T)c2_indices_data[c2_i26];
  }

  c2_cols_size[0] = c2_j_size[0];
  c2_e_loop_ub = c2_j_size[0] - 1;
  for (c2_i27 = 0; c2_i27 <= c2_e_loop_ub; c2_i27++) {
    c2_cols_data[c2_i27] = (real_T)c2_b_j_data[c2_i27];
  }

  c2_rows_size[0];
  c2_f_loop_ub = c2_rows_size[0] - 1;
  for (c2_i28 = 0; c2_i28 <= c2_f_loop_ub; c2_i28++) {
    c2_rows_data[c2_i28] -= 2.0;
  }

  c2_cols_size[0];
  c2_g_loop_ub = c2_cols_size[0] - 1;
  for (c2_i29 = 0; c2_i29 <= c2_g_loop_ub; c2_i29++) {
    c2_cols_data[c2_i29] -= 2.0;
  }

  c2_b_rows_size[0] = c2_rows_size[0];
  c2_h_loop_ub = c2_rows_size[0] - 1;
  for (c2_i30 = 0; c2_i30 <= c2_h_loop_ub; c2_i30++) {
    c2_b_rows_data[c2_i30] = c2_rows_data[c2_i30];
  }

  c2_abs(chartInstance, c2_b_rows_data, c2_b_rows_size, c2_varargin_1_data,
         c2_varargin_1_size);
  if ((c2_varargin_1_size[0] == 1) || ((real_T)c2_varargin_1_size[0] != 1.0)) {
    c2_b3 = true;
  } else {
    c2_b3 = false;
  }

  if (c2_b3) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_n = c2_varargin_1_size[0];
  if (c2_n <= 2) {
    if (c2_n == 1) {
      c2_maxval = c2_varargin_1_data[0];
    } else if (c2_varargin_1_data[0] < c2_varargin_1_data[1]) {
      c2_maxval = c2_varargin_1_data[1];
    } else {
      c2_maxval = c2_varargin_1_data[0];
    }
  } else {
    c2_last = c2_n;
    c2_ex = c2_varargin_1_data[0];
    for (c2_k = 1; c2_k < c2_last; c2_k++) {
      if (c2_ex < c2_varargin_1_data[c2_k]) {
        c2_ex = c2_varargin_1_data[c2_k];
      }
    }

    c2_maxval = c2_ex;
  }

  c2_b_cols_size[0] = c2_cols_size[0];
  c2_i_loop_ub = c2_cols_size[0] - 1;
  for (c2_i31 = 0; c2_i31 <= c2_i_loop_ub; c2_i31++) {
    c2_b_cols_data[c2_i31] = c2_cols_data[c2_i31];
  }

  c2_abs(chartInstance, c2_b_cols_data, c2_b_cols_size, c2_varargin_1_data,
         c2_varargin_1_size);
  if ((c2_varargin_1_size[0] == 1) || ((real_T)c2_varargin_1_size[0] != 1.0)) {
    c2_b4 = true;
  } else {
    c2_b4 = false;
  }

  if (c2_b4) {
  } else {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_g_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_h_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_j_y)));
  }

  c2_b_n = c2_varargin_1_size[0];
  if (c2_b_n <= 2) {
    if (c2_b_n == 1) {
      c2_b_maxval = c2_varargin_1_data[0];
    } else if (c2_varargin_1_data[0] < c2_varargin_1_data[1]) {
      c2_b_maxval = c2_varargin_1_data[1];
    } else {
      c2_b_maxval = c2_varargin_1_data[0];
    }
  } else {
    c2_b_last = c2_b_n;
    c2_b_ex = c2_varargin_1_data[0];
    for (c2_b_k = 1; c2_b_k < c2_b_last; c2_b_k++) {
      if (c2_b_ex < c2_varargin_1_data[c2_b_k]) {
        c2_b_ex = c2_varargin_1_data[c2_b_k];
      }
    }

    c2_b_maxval = c2_b_ex;
  }

  c2_c_varargin_1 = c2_maxval;
  c2_varargin_2 = c2_b_maxval;
  c2_x = c2_c_varargin_1;
  c2_d_varargin_1 = c2_varargin_2;
  c2_b_x = c2_x;
  c2_k_y = c2_d_varargin_1;
  c2_c_x = c2_b_x;
  c2_l_y = c2_k_y;
  c2_d_x = c2_c_x;
  c2_m_y = c2_l_y;
  c2_e_x = c2_d_x;
  c2_n_y = c2_m_y;
  c2_f_x = c2_e_x;
  c2_o_y = c2_n_y;
  c2_padSize = muDoubleScalarMax(c2_f_x, c2_o_y);
  c2_c_a = c2_padSize;
  for (c2_i32 = 0; c2_i32 < 2; c2_i32++) {
    c2_startIdx[c2_i32] = c2_c_a;
  }

  for (c2_i33 = 0; c2_i33 < 19200; c2_i33++) {
    c2_e_varargin_1[c2_i33] = c2_b_varargin_1[c2_i33];
  }

  c2_padarray(chartInstance, c2_e_varargin_1, c2_startIdx, c2_Apad_data,
              c2_Apad_size);
  c2_Ma = (real_T)c2_Apad_size[0];
  c2_b_b = c2_Ma;
  c2_cols_size[0];
  c2_j_loop_ub = c2_cols_size[0] - 1;
  for (c2_i34 = 0; c2_i34 <= c2_j_loop_ub; c2_i34++) {
    c2_cols_data[c2_i34] *= c2_b_b;
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_cols_size[0], c2_rows_size[0]);
  c2_indices_size[0] = c2_cols_size[0];
  c2_k_loop_ub = c2_cols_size[0] - 1;
  for (c2_i35 = 0; c2_i35 <= c2_k_loop_ub; c2_i35++) {
    c2_d1 = muDoubleScalarRound(c2_cols_data[c2_i35] + c2_rows_data[c2_i35]);
    if (c2_d1 < 2.147483648E+9) {
      if (c2_d1 >= -2.147483648E+9) {
        c2_i37 = (int32_T)c2_d1;
      } else {
        c2_i37 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d1 >= 2.147483648E+9) {
      c2_i37 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i37 = 0;
    }

    c2_indices_data[c2_i35] = c2_i37;
  }

  c2_startIdx[0] = c2_padSize;
  c2_startIdx[1] = c2_padSize;
  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_sizeA[c2_i36] = (real_T)c2_Apad_size[c2_i36];
  }

  for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
    c2_sizeA[c2_i38];
  }

  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    c2_domainSizeT[c2_i39] = 3.0;
  }

  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    c2_dv1[c2_i40] = 120.0 + 40.0 * (real_T)c2_i40;
  }

  ordfilt2_boolean(&c2_Apad_data[0], c2_sizeA[0], c2_startIdx, &c2_indices_data
                   [0], (real_T)c2_indices_size[0], c2_domainSizeT, 4.0, c2_b,
                   c2_dv1, true);
}

static void c2_indexShapeCheck(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_matrixSize, int32_T c2_indexSize[2])
{
  int32_T c2_size1;
  boolean_T c2_b;
  boolean_T c2_nonSingletonDimFound;
  boolean_T c2_c;
  boolean_T c2_b_c;
  boolean_T c2_b_b;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv7[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_size1 = c2_matrixSize;
  if (c2_size1 != 1) {
    c2_b = false;
  } else {
    c2_b = true;
  }

  if (c2_b) {
    c2_nonSingletonDimFound = false;
    if (c2_indexSize[1] != 1) {
      c2_nonSingletonDimFound = true;
    }

    c2_b_b = c2_nonSingletonDimFound;
    if (c2_b_b) {
      c2_c = true;
    } else {
      c2_c = false;
    }
  } else {
    c2_c = false;
  }

  c2_b_c = c2_c;
  if (!c2_b_c) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }
}

static void c2_abs(SFc2_tomasInstanceStruct *chartInstance, real_T c2_c_x_data[],
                   int32_T c2_x_size[1], real_T c2_y_data[], int32_T c2_y_size[1])
{
  int32_T c2_nx;
  real_T c2_x[2];
  int32_T c2_i41;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_y;
  (void)chartInstance;
  c2_nx = c2_x_size[0] - 1;
  c2_x[0] = (real_T)c2_x_size[0];
  c2_x[1] = 1.0;
  for (c2_i41 = 0; c2_i41 < 2; c2_i41++) {
    c2_x[c2_i41];
  }

  c2_y_size[0] = (int32_T)c2_x[0];
  for (c2_k = 0; c2_k <= c2_nx; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_c_x_data[c2_b_k];
    c2_c_y = muDoubleScalarAbs(c2_b_x);
    c2_y_data[c2_b_k] = c2_c_y;
  }
}

static void c2_padarray(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[2], boolean_T c2_b_b_data[],
  int32_T c2_b_size[2])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  boolean_T c2_b5;
  real_T c2_b_x;
  real_T c2_c_x;
  const mxArray *c2_c_y = NULL;
  boolean_T c2_b_p;
  static char_T c2_cv8[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
    'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c2_i42;
  const mxArray *c2_d_y = NULL;
  boolean_T c2_c_p;
  int32_T c2_i43;
  real_T c2_e_y[2];
  const mxArray *c2_f_y = NULL;
  static char_T c2_cv9[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c2_d2;
  int32_T c2_i44;
  int32_T c2_j;
  real_T c2_b;
  real_T c2_b_j;
  int32_T c2_c;
  real_T c2_d3;
  int32_T c2_c_a;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i;
  int32_T c2_i47;
  int32_T c2_c_j;
  real_T c2_b_i;
  int32_T c2_d_j;
  real_T c2_d4;
  int32_T c2_i48;
  int32_T c2_e_j;
  int32_T c2_c_i;
  real_T c2_d5;
  int32_T c2_f_j;
  int32_T c2_i49;
  real_T c2_d_a;
  int32_T c2_d_i;
  int32_T c2_b_c;
  int32_T c2_e_i;
  int32_T c2_e_a;
  int32_T c2_i50;
  int32_T c2_i51;
  real_T c2_f_a;
  real_T c2_g_a;
  int32_T c2_f_i;
  real_T c2_b_b;
  real_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_d_c;
  real_T c2_h_a;
  real_T c2_i_a;
  real_T c2_d_b;
  real_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_f_c;
  boolean_T exitg1;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x = c2_varargin_2[(int32_T)c2_b_k - 1];
    c2_b_x = c2_x;
    c2_c_x = c2_b_x;
    if (c2_c_x == c2_x) {
      c2_b_p = true;
    } else {
      c2_b_p = false;
    }

    c2_c_p = c2_b_p;
    if (c2_c_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b5 = true;
  } else {
    c2_b5 = false;
  }

  if (c2_b5) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_f_y)));
  }

  for (c2_i42 = 0; c2_i42 < 2; c2_i42++) {
    c2_e_y[c2_i42] = 2.0 * c2_varargin_2[c2_i42];
  }

  for (c2_i43 = 0; c2_i43 < 2; c2_i43++) {
    c2_e_y[c2_i43] += 120.0 + 40.0 * (real_T)c2_i43;
  }

  c2_b_size[0] = (int32_T)c2_e_y[0];
  c2_b_size[1] = (int32_T)c2_e_y[1];
  c2_d2 = c2_varargin_2[1];
  c2_i44 = (int32_T)c2_d2 - 1;
  for (c2_j = 0; c2_j <= c2_i44; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_d3 = (real_T)c2_b_size[0];
    c2_i45 = (int32_T)c2_d3 - 1;
    for (c2_i = 0; c2_i <= c2_i45; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1, c2_b_size
        [0]) + c2_b_size[0] * ((int32_T)c2_b_j - 1)) - 1] = false;
    }
  }

  c2_b = c2_varargin_2[1];
  c2_c = (int32_T)c2_b;
  c2_c_a = c2_c + 160;
  c2_i46 = c2_c_a;
  c2_i47 = c2_b_size[1];
  for (c2_c_j = c2_i46 + 1; c2_c_j <= c2_i47; c2_c_j++) {
    c2_d4 = (real_T)c2_b_size[0];
    c2_i48 = (int32_T)c2_d4 - 1;
    for (c2_c_i = 0; c2_c_i <= c2_i48; c2_c_i++) {
      c2_b_i = 1.0 + (real_T)c2_c_i;
      c2_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1, c2_b_size
        [0]) + c2_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_c_j, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_d_j = 0; c2_d_j < 160; c2_d_j++) {
    c2_b_j = 1.0 + (real_T)c2_d_j;
    c2_d5 = c2_varargin_2[0];
    c2_i49 = (int32_T)c2_d5 - 1;
    for (c2_d_i = 0; c2_d_i <= c2_i49; c2_d_i++) {
      c2_b_i = 1.0 + (real_T)c2_d_i;
      c2_f_a = c2_b_j;
      c2_b_b = c2_varargin_2[1];
      c2_c_c = (int32_T)c2_f_a + (int32_T)c2_b_b;
      c2_b_b_data[((int32_T)c2_b_i + c2_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_c_c, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_e_j = 0; c2_e_j < 160; c2_e_j++) {
    c2_b_j = 1.0 + (real_T)c2_e_j;
    c2_d_a = c2_varargin_2[0];
    c2_b_c = (int32_T)c2_d_a;
    c2_e_a = c2_b_c + 120;
    c2_i50 = c2_e_a;
    c2_i51 = c2_b_size[0];
    for (c2_f_i = c2_i50 + 1; c2_f_i <= c2_i51; c2_f_i++) {
      c2_i_a = c2_b_j;
      c2_e_b = c2_varargin_2[1];
      c2_f_c = (int32_T)c2_i_a + (int32_T)c2_e_b;
      c2_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_f_i, 1, c2_b_size[0]) +
                   c2_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_f_c, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_f_j = 0; c2_f_j < 160; c2_f_j++) {
    c2_b_j = 1.0 + (real_T)c2_f_j;
    for (c2_e_i = 0; c2_e_i < 120; c2_e_i++) {
      c2_b_i = 1.0 + (real_T)c2_e_i;
      c2_g_a = c2_b_i;
      c2_c_b = c2_varargin_2[0];
      c2_d_c = (int32_T)c2_g_a + (int32_T)c2_c_b;
      c2_h_a = c2_b_j;
      c2_d_b = c2_varargin_2[1];
      c2_e_c = (int32_T)c2_h_a + (int32_T)c2_d_b;
      c2_b_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_d_c, 1, c2_b_size[0]) +
                   c2_b_size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_c, 1, c2_b_size[1]) - 1)) - 1] = c2_b_varargin_1[((int32_T)c2_b_i
        + 120 * ((int32_T)c2_b_j - 1)) - 1];
    }
  }
}

static void c2_edge(SFc2_tomasInstanceStruct *chartInstance, boolean_T
                    c2_b_varargin_1[19200], boolean_T c2_varargout_1[19200])
{
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  real_T c2_derivGaussKernel[13];
  static real_T c2_dv2[13] = { 0.00050975920363612861, 0.0025659736304223,
    0.014594040963812248, 0.049305200293708981, 0.09498179875488523,
    0.089159205155936727, 0.0, -0.089159205155936727, -0.09498179875488523,
    -0.049305200293708981, -0.014594040963812248, -0.0025659736304223,
    -0.00050975920363612861 };

  int32_T c2_i55;
  static real_T c2_dv3[6] = { 0.0020299751839417141, 0.010218281014351701,
    0.058116735860084041, 0.19634433732941295, 0.37823877042972093,
    0.35505190018248872 };

  real_T c2_c_y;
  real_T c2_x[6];
  int32_T c2_k;
  real_T c2_b_x;
  int32_T c2_xoffset;
  real_T c2_c_x;
  int32_T c2_ix;
  real_T c2_d_x;
  real_T c2_d_y;
  int32_T c2_i56;
  int32_T c2_i57;
  real_T c2_b_derivGaussKernel[6];
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_c_derivGaussKernel[13];
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  real32_T c2_e_x;
  real32_T c2_f_x;
  boolean_T c2_b;
  boolean_T c2_p;
  int32_T c2_idx;
  int32_T c2_b_k;
  int32_T c2_first;
  real32_T c2_magmax;
  real32_T c2_g_x;
  real32_T c2_ex;
  real32_T c2_h_x;
  int32_T c2_i65;
  boolean_T c2_b_b;
  int32_T c2_c_k;
  real32_T c2_e_y;
  boolean_T c2_b_p;
  real_T c2_out;
  real32_T c2_f_y;
  int32_T c2_i66;
  int32_T c2_i67;
  boolean_T c2_nanFlag;
  real_T c2_counts[64];
  int32_T c2_i;
  real_T c2_b_i;
  real32_T c2_i_x;
  int32_T c2_d_k;
  boolean_T c2_c_b;
  int32_T c2_i68;
  int32_T c2_e_k;
  real32_T c2_b_idx;
  int32_T c2_c_idx;
  boolean_T c2_j_x[64];
  int32_T c2_ii_size[1];
  real32_T c2_k_x;
  int32_T c2_ii;
  boolean_T c2_d_b;
  real32_T c2_c_a;
  int32_T c2_b_ii;
  int32_T c2_c;
  real32_T c2_d_a;
  int32_T c2_i69;
  int32_T c2_b_c;
  int32_T c2_highThreshTemp_size[1];
  int32_T c2_b_ii_data[1];
  int32_T c2_loop_ub;
  int32_T c2_i70;
  real_T c2_highThreshTemp_data[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i71;
  real_T c2_d6;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_lowThresh_size[1];
  int32_T c2_b_size[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i74;
  int32_T c2_b_lowThresh_size[1];
  int32_T c2_d_loop_ub;
  real_T c2_b_b_data[1];
  int32_T c2_i75;
  int32_T c2_b_highThreshTemp_size[1];
  real_T c2_lowThresh_data[1];
  real_T c2_b_lowThresh_data[1];
  int32_T c2_e_loop_ub;
  int32_T c2_i76;
  real_T c2_b_highThreshTemp_data[1];
  boolean_T exitg1;
  for (c2_i52 = 0; c2_i52 < 19200; c2_i52++) {
    chartInstance->c2_a[c2_i52] = (real32_T)c2_b_varargin_1[c2_i52];
  }

  for (c2_i53 = 0; c2_i53 < 13; c2_i53++) {
    c2_derivGaussKernel[c2_i53] = c2_dv2[c2_i53];
  }

  for (c2_i54 = 0; c2_i54 < 6; c2_i54++) {
    c2_derivGaussKernel[c2_i54] = c2_dv3[c2_i54];
  }

  for (c2_i55 = 0; c2_i55 < 6; c2_i55++) {
    c2_x[c2_i55] = c2_derivGaussKernel[c2_i55 + 7];
  }

  c2_c_y = c2_x[0];
  for (c2_k = 0; c2_k < 5; c2_k++) {
    c2_xoffset = c2_k;
    c2_ix = c2_xoffset;
    c2_c_y += c2_x[c2_ix + 1];
  }

  c2_b_x = c2_c_y;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_d_y = muDoubleScalarAbs(c2_d_x);
  for (c2_i56 = 0; c2_i56 < 6; c2_i56++) {
    c2_b_derivGaussKernel[c2_i56] = c2_derivGaussKernel[c2_i56 + 7] / c2_d_y;
  }

  for (c2_i57 = 0; c2_i57 < 6; c2_i57++) {
    c2_derivGaussKernel[c2_i57 + 7] = c2_b_derivGaussKernel[c2_i57];
  }

  for (c2_i58 = 0; c2_i58 < 19200; c2_i58++) {
    chartInstance->c2_b_a[c2_i58] = chartInstance->c2_a[c2_i58];
  }

  c2_imfilter(chartInstance, chartInstance->c2_b_a, chartInstance->c2_dx);
  for (c2_i59 = 0; c2_i59 < 19200; c2_i59++) {
    chartInstance->c2_b_dx[c2_i59] = chartInstance->c2_dx[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 13; c2_i60++) {
    c2_c_derivGaussKernel[c2_i60] = c2_derivGaussKernel[c2_i60];
  }

  c2_b_imfilter(chartInstance, chartInstance->c2_b_dx, c2_c_derivGaussKernel,
                chartInstance->c2_dx);
  c2_c_imfilter(chartInstance, chartInstance->c2_a, chartInstance->c2_dy);
  for (c2_i61 = 0; c2_i61 < 19200; c2_i61++) {
    chartInstance->c2_b_dy[c2_i61] = chartInstance->c2_dy[c2_i61];
  }

  c2_d_imfilter(chartInstance, chartInstance->c2_b_dy, c2_derivGaussKernel,
                chartInstance->c2_dy);
  for (c2_i62 = 0; c2_i62 < 19200; c2_i62++) {
    chartInstance->c2_c_dx[c2_i62] = chartInstance->c2_dx[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 19200; c2_i63++) {
    chartInstance->c2_c_dy[c2_i63] = chartInstance->c2_dy[c2_i63];
  }

  c2_hypot(chartInstance, chartInstance->c2_c_dx, chartInstance->c2_c_dy,
           chartInstance->c2_a);
  for (c2_i64 = 0; c2_i64 < 19200; c2_i64++) {
    chartInstance->c2_varargin_1[c2_i64] = chartInstance->c2_a[c2_i64];
  }

  c2_e_x = chartInstance->c2_varargin_1[0];
  c2_f_x = c2_e_x;
  c2_b = muSingleScalarIsNaN(c2_f_x);
  c2_p = !c2_b;
  if (c2_p) {
    c2_idx = 1;
  } else {
    c2_idx = 0;
    c2_b_k = 2;
    exitg1 = false;
    while ((!exitg1) && (c2_b_k < 19201)) {
      c2_g_x = chartInstance->c2_varargin_1[c2_b_k - 1];
      c2_h_x = c2_g_x;
      c2_b_b = muSingleScalarIsNaN(c2_h_x);
      c2_b_p = !c2_b_b;
      if (c2_b_p) {
        c2_idx = c2_b_k;
        exitg1 = true;
      } else {
        c2_b_k++;
      }
    }
  }

  if (c2_idx == 0) {
    c2_magmax = chartInstance->c2_varargin_1[0];
  } else {
    c2_first = c2_idx - 1;
    c2_ex = chartInstance->c2_varargin_1[c2_first];
    c2_i65 = c2_first;
    for (c2_c_k = c2_i65 + 1; c2_c_k + 1 < 19201; c2_c_k++) {
      if (c2_ex < chartInstance->c2_varargin_1[c2_c_k]) {
        c2_ex = chartInstance->c2_varargin_1[c2_c_k];
      }
    }

    c2_magmax = c2_ex;
  }

  if (c2_magmax > 0.0F) {
    c2_e_y = c2_magmax;
    c2_f_y = c2_e_y;
    for (c2_i66 = 0; c2_i66 < 19200; c2_i66++) {
      chartInstance->c2_a[c2_i66] /= c2_f_y;
    }
  }

  c2_out = 1.0;
  getnumcores(&c2_out);
  for (c2_i67 = 0; c2_i67 < 64; c2_i67++) {
    c2_counts[c2_i67] = 0.0;
  }

  c2_nanFlag = false;
  for (c2_i = 0; c2_i < 19200; c2_i++) {
    c2_b_i = 1.0 + (real_T)c2_i;
    c2_i_x = chartInstance->c2_a[(int32_T)c2_b_i - 1];
    c2_c_b = muSingleScalarIsNaN(c2_i_x);
    if (c2_c_b) {
      c2_nanFlag = true;
      c2_b_idx = 0.0F;
    } else {
      c2_b_idx = chartInstance->c2_a[(int32_T)c2_b_i - 1] * 63.0F + 0.5F;
    }

    if (c2_b_idx > 63.0F) {
      c2_counts[63]++;
    } else {
      c2_k_x = chartInstance->c2_a[(int32_T)c2_b_i - 1];
      c2_d_b = muSingleScalarIsInf(c2_k_x);
      if (c2_d_b) {
        c2_counts[63]++;
      } else {
        c2_c_a = c2_b_idx;
        c2_c = (int32_T)c2_c_a;
        c2_d_a = c2_b_idx;
        c2_b_c = (int32_T)c2_d_a;
        c2_counts[c2_c] = c2_counts[c2_b_c] + 1.0;
      }
    }
  }

  if (c2_nanFlag) {
    c2_warning(chartInstance);
  }

  for (c2_d_k = 0; c2_d_k < 63; c2_d_k++) {
    c2_e_k = c2_d_k;
    c2_counts[c2_e_k + 1] += c2_counts[c2_e_k];
  }

  for (c2_i68 = 0; c2_i68 < 64; c2_i68++) {
    c2_j_x[c2_i68] = (c2_counts[c2_i68] > 13440.0);
  }

  c2_c_idx = 0;
  c2_ii_size[0] = 1;
  c2_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_ii < 64)) {
    c2_b_ii = c2_ii;
    if (c2_j_x[c2_b_ii]) {
      c2_c_idx = 1;
      c2_b_ii_data[0] = c2_b_ii + 1;
      exitg1 = true;
    } else {
      c2_ii++;
    }
  }

  if (c2_c_idx == 0) {
    c2_i69 = c2_ii_size[0];
    c2_ii_size[0] = 0;
  }

  c2_highThreshTemp_size[0] = c2_ii_size[0];
  c2_loop_ub = c2_ii_size[0] - 1;
  for (c2_i70 = 0; c2_i70 <= c2_loop_ub; c2_i70++) {
    c2_highThreshTemp_data[c2_i70] = (real_T)c2_b_ii_data[c2_i70];
  }

  c2_highThreshTemp_size[0];
  c2_b_loop_ub = c2_highThreshTemp_size[0] - 1;
  for (c2_i71 = 0; c2_i71 <= c2_b_loop_ub; c2_i71++) {
    c2_highThreshTemp_data[c2_i71] /= 64.0;
  }

  if (c2_highThreshTemp_size[0] == 0) {
    c2_i72 = c2_highThreshTemp_size[0];
    c2_highThreshTemp_size[0] = 0;
    c2_i73 = c2_lowThresh_size[0];
    c2_lowThresh_size[0] = 0;
  } else {
    c2_d6 = c2_highThreshTemp_data[0];
    c2_highThreshTemp_size[0] = 1;
    c2_highThreshTemp_data[0] = c2_d6;
    c2_b_size[0] = c2_highThreshTemp_size[0];
    c2_c_loop_ub = c2_highThreshTemp_size[0] - 1;
    for (c2_i74 = 0; c2_i74 <= c2_c_loop_ub; c2_i74++) {
      c2_b_b_data[c2_i74] = c2_highThreshTemp_data[c2_i74];
    }

    c2_b_size[0] = 1;
    c2_b_b_data[0] *= 0.4;
    c2_lowThresh_size[0] = 1;
    c2_b_lowThresh_data[0] = c2_b_b_data[0];
  }

  c2_b_lowThresh_size[0] = c2_lowThresh_size[0];
  c2_d_loop_ub = c2_lowThresh_size[0] - 1;
  for (c2_i75 = 0; c2_i75 <= c2_d_loop_ub; c2_i75++) {
    c2_lowThresh_data[c2_i75] = c2_b_lowThresh_data[c2_i75];
  }

  c2_b_highThreshTemp_size[0] = c2_highThreshTemp_size[0];
  c2_e_loop_ub = c2_highThreshTemp_size[0] - 1;
  for (c2_i76 = 0; c2_i76 <= c2_e_loop_ub; c2_i76++) {
    c2_b_highThreshTemp_data[c2_i76] = c2_highThreshTemp_data[c2_i76];
  }

  c2_thinAndThreshold(chartInstance, chartInstance->c2_dx, chartInstance->c2_dy,
                      chartInstance->c2_a, c2_lowThresh_data,
                      c2_b_lowThresh_size, c2_b_highThreshTemp_data,
                      c2_b_highThreshTemp_size, c2_varargout_1);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_lowThresh_size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_highThreshTemp_size[0]);
}

static void c2_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i77;
  real32_T c2_c_varargin_1[19200];
  real32_T c2_c_a[21120];
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  boolean_T c2_conn[13];
  int32_T c2_i81;
  real_T c2_padSizeT[2];
  int32_T c2_i82;
  int32_T c2_i83;
  real_T c2_outSizeT[2];
  int32_T c2_i84;
  real_T c2_connDimsT[2];
  int32_T c2_i85;
  real_T c2_startT[2];
  for (c2_i77 = 0; c2_i77 < 19200; c2_i77++) {
    c2_c_varargin_1[c2_i77] = c2_b_varargin_1[c2_i77];
  }

  c2_padImage(chartInstance, c2_c_varargin_1, 0.0, 3, 4.0, c2_c_a);
  c2_tooBig = true;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i79 = 0; c2_i79 < 2; c2_i79++) {
      c2_padSizeT[c2_i79] = 132.0 + 28.0 * (real_T)c2_i79;
    }

    for (c2_i81 = 0; c2_i81 < 2; c2_i81++) {
      c2_outSizeT[c2_i81] = 120.0 + 40.0 * (real_T)c2_i81;
    }

    for (c2_i83 = 0; c2_i83 < 2; c2_i83++) {
      c2_connDimsT[c2_i83] = 13.0 + -12.0 * (real_T)c2_i83;
    }

    ippfilter_real32(c2_c_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT, c2_dv0,
                     c2_connDimsT, true);
  } else {
    for (c2_i78 = 0; c2_i78 < 13; c2_i78++) {
      c2_conn[c2_i78] = true;
    }

    for (c2_i80 = 0; c2_i80 < 2; c2_i80++) {
      c2_padSizeT[c2_i80] = 132.0 + 28.0 * (real_T)c2_i80;
    }

    for (c2_i82 = 0; c2_i82 < 2; c2_i82++) {
      c2_outSizeT[c2_i82] = 120.0 + 40.0 * (real_T)c2_i82;
    }

    for (c2_i84 = 0; c2_i84 < 2; c2_i84++) {
      c2_connDimsT[c2_i84] = 13.0 + -12.0 * (real_T)c2_i84;
    }

    for (c2_i85 = 0; c2_i85 < 2; c2_i85++) {
      c2_startT[c2_i85] = 6.0 + -6.0 * (real_T)c2_i85;
    }

    imfilter_real32(c2_c_a, c2_b, 2.0, c2_outSizeT, 2.0, c2_padSizeT, c2_dv0,
                    13.0, c2_conn, 2.0, c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_padImage(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real32_T c2_c_a[21120])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
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

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 160; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 132; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_c_a[((int32_T)c2_b_i + 132 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 159], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_b_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200])
{
  int32_T c2_i86;
  real32_T c2_c_varargin_1[19200];
  real32_T c2_c_a[20640];
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_d_tmp_data[13];
  int32_T c2_i87;
  int32_T c2_i88;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_densityFlag;
  boolean_T c2_connb[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_padSizeT[2];
  int32_T c2_i92;
  int32_T c2_i93;
  real_T c2_outSizeT[2];
  int32_T c2_i94;
  real_T c2_connDimsT[2];
  int32_T c2_i95;
  real_T c2_startT[2];
  for (c2_i86 = 0; c2_i86 < 19200; c2_i86++) {
    c2_c_varargin_1[c2_i86] = c2_b_varargin_1[c2_i86];
  }

  c2_b_padImage(chartInstance, c2_c_varargin_1, 0.0, 3, 4.0, c2_c_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_varargin_2[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_varargin_2[c2_b_i] != 0.0) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i87 = 0; c2_i87 <= c2_loop_ub; c2_i87++) {
    c2_nonzero_h_data[c2_i87] = c2_varargin_2[c2_d_tmp_data[c2_i87] - 1];
  }

  for (c2_i88 = 0; c2_i88 < 13; c2_i88++) {
    c2_connb[c2_i88] = (c2_varargin_2[c2_i88] != 0.0);
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i89 = 0; c2_i89 < 2; c2_i89++) {
      c2_padSizeT[c2_i89] = 120.0 + 52.0 * (real_T)c2_i89;
    }

    for (c2_i91 = 0; c2_i91 < 2; c2_i91++) {
      c2_outSizeT[c2_i91] = 120.0 + 40.0 * (real_T)c2_i91;
    }

    for (c2_i93 = 0; c2_i93 < 2; c2_i93++) {
      c2_connDimsT[c2_i93] = 1.0 + 12.0 * (real_T)c2_i93;
    }

    ippfilter_real32(c2_c_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT, c2_varargin_2,
                     c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i90 = 0; c2_i90 < 2; c2_i90++) {
      c2_padSizeT[c2_i90] = 120.0 + 52.0 * (real_T)c2_i90;
    }

    for (c2_i92 = 0; c2_i92 < 2; c2_i92++) {
      c2_outSizeT[c2_i92] = 120.0 + 40.0 * (real_T)c2_i92;
    }

    for (c2_i94 = 0; c2_i94 < 2; c2_i94++) {
      c2_connDimsT[c2_i94] = 1.0 + 12.0 * (real_T)c2_i94;
    }

    for (c2_i95 = 0; c2_i95 < 2; c2_i95++) {
      c2_startT[c2_i95] = 6.0 * (real_T)c2_i95;
    }

    imfilter_real32(c2_c_a, c2_b, 2.0, c2_outSizeT, 2.0, c2_padSizeT,
                    &c2_nonzero_h_data[0], c2_numKernElem, c2_connb, 2.0,
                    c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_b_padImage(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum, real_T
  c2_boundaryStr_pos, real32_T c2_c_a[20640])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
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

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 172; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 120; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_c_a[((int32_T)c2_b_i + 120 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 171], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_c_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i96;
  real32_T c2_c_varargin_1[19200];
  real32_T c2_c_a[20640];
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_d_tmp_data[13];
  int32_T c2_i97;
  boolean_T c2_densityFlag;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  real_T c2_padSizeT[2];
  int32_T c2_i101;
  boolean_T c2_conn[13];
  int32_T c2_i102;
  real_T c2_outSizeT[2];
  int32_T c2_i103;
  real_T c2_connDimsT[2];
  int32_T c2_i104;
  int32_T c2_i105;
  real_T c2_startT[2];
  for (c2_i96 = 0; c2_i96 < 19200; c2_i96++) {
    c2_c_varargin_1[c2_i96] = c2_b_varargin_1[c2_i96];
  }

  c2_b_padImage(chartInstance, c2_c_varargin_1, 0.0, 3, 4.0, c2_c_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_dv0[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_dv0[c2_b_i] != 0.0) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i97 = 0; c2_i97 <= c2_loop_ub; c2_i97++) {
    c2_nonzero_h_data[c2_i97] = c2_dv0[c2_d_tmp_data[c2_i97] - 1];
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i98 = 0; c2_i98 < 2; c2_i98++) {
      c2_padSizeT[c2_i98] = 120.0 + 52.0 * (real_T)c2_i98;
    }

    for (c2_i100 = 0; c2_i100 < 2; c2_i100++) {
      c2_outSizeT[c2_i100] = 120.0 + 40.0 * (real_T)c2_i100;
    }

    for (c2_i102 = 0; c2_i102 < 2; c2_i102++) {
      c2_connDimsT[c2_i102] = 1.0 + 12.0 * (real_T)c2_i102;
    }

    ippfilter_real32(c2_c_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT, c2_dv0,
                     c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i99 = 0; c2_i99 < 13; c2_i99++) {
      c2_conn[c2_i99] = true;
    }

    for (c2_i101 = 0; c2_i101 < 2; c2_i101++) {
      c2_padSizeT[c2_i101] = 120.0 + 52.0 * (real_T)c2_i101;
    }

    for (c2_i103 = 0; c2_i103 < 2; c2_i103++) {
      c2_outSizeT[c2_i103] = 120.0 + 40.0 * (real_T)c2_i103;
    }

    for (c2_i104 = 0; c2_i104 < 2; c2_i104++) {
      c2_connDimsT[c2_i104] = 1.0 + 12.0 * (real_T)c2_i104;
    }

    for (c2_i105 = 0; c2_i105 < 2; c2_i105++) {
      c2_startT[c2_i105] = 6.0 * (real_T)c2_i105;
    }

    imfilter_real32(c2_c_a, c2_b, 2.0, c2_outSizeT, 2.0, c2_padSizeT,
                    &c2_nonzero_h_data[0], c2_numKernElem, c2_conn, 2.0,
                    c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_d_imfilter(SFc2_tomasInstanceStruct *chartInstance, real32_T
  c2_b_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200])
{
  int32_T c2_i106;
  real32_T c2_c_varargin_1[19200];
  real32_T c2_c_a[21120];
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_d_tmp_data[13];
  int32_T c2_i107;
  int32_T c2_i108;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_densityFlag;
  boolean_T c2_connb[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i109;
  int32_T c2_i110;
  int32_T c2_i111;
  real_T c2_padSizeT[2];
  int32_T c2_i112;
  int32_T c2_i113;
  real_T c2_outSizeT[2];
  int32_T c2_i114;
  real_T c2_connDimsT[2];
  int32_T c2_i115;
  real_T c2_startT[2];
  for (c2_i106 = 0; c2_i106 < 19200; c2_i106++) {
    c2_c_varargin_1[c2_i106] = c2_b_varargin_1[c2_i106];
  }

  c2_padImage(chartInstance, c2_c_varargin_1, 0.0, 3, 4.0, c2_c_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_varargin_2[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_varargin_2[c2_b_i] != 0.0) {
      c2_d_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i107 = 0; c2_i107 <= c2_loop_ub; c2_i107++) {
    c2_nonzero_h_data[c2_i107] = c2_varargin_2[c2_d_tmp_data[c2_i107] - 1];
  }

  for (c2_i108 = 0; c2_i108 < 13; c2_i108++) {
    c2_connb[c2_i108] = (c2_varargin_2[c2_i108] != 0.0);
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i109 = 0; c2_i109 < 2; c2_i109++) {
      c2_padSizeT[c2_i109] = 132.0 + 28.0 * (real_T)c2_i109;
    }

    for (c2_i111 = 0; c2_i111 < 2; c2_i111++) {
      c2_outSizeT[c2_i111] = 120.0 + 40.0 * (real_T)c2_i111;
    }

    for (c2_i113 = 0; c2_i113 < 2; c2_i113++) {
      c2_connDimsT[c2_i113] = 13.0 + -12.0 * (real_T)c2_i113;
    }

    ippfilter_real32(c2_c_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT, c2_varargin_2,
                     c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i110 = 0; c2_i110 < 2; c2_i110++) {
      c2_padSizeT[c2_i110] = 132.0 + 28.0 * (real_T)c2_i110;
    }

    for (c2_i112 = 0; c2_i112 < 2; c2_i112++) {
      c2_outSizeT[c2_i112] = 120.0 + 40.0 * (real_T)c2_i112;
    }

    for (c2_i114 = 0; c2_i114 < 2; c2_i114++) {
      c2_connDimsT[c2_i114] = 13.0 + -12.0 * (real_T)c2_i114;
    }

    for (c2_i115 = 0; c2_i115 < 2; c2_i115++) {
      c2_startT[c2_i115] = 6.0 + -6.0 * (real_T)c2_i115;
    }

    imfilter_real32(c2_c_a, c2_b, 2.0, c2_outSizeT, 2.0, c2_padSizeT,
                    &c2_nonzero_h_data[0], c2_numKernElem, c2_connb, 2.0,
                    c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_hypot(SFc2_tomasInstanceStruct *chartInstance, real32_T c2_x
                     [19200], real32_T c2_c_y[19200], real32_T c2_r[19200])
{
  int32_T c2_k;
  int32_T c2_b_k;
  real32_T c2_b_x;
  real32_T c2_d_y;
  real32_T c2_x1;
  real32_T c2_x2;
  real32_T c2_z;
  (void)chartInstance;
  for (c2_k = 0; c2_k < 19200; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x[c2_b_k];
    c2_d_y = c2_c_y[c2_b_k];
    c2_x1 = c2_b_x;
    c2_x2 = c2_d_y;
    c2_z = muSingleScalarHypot(c2_x1, c2_x2);
    c2_r[c2_b_k] = c2_z;
  }
}

static void c2_warning(SFc2_tomasInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv10[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv11[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_thinAndThreshold(SFc2_tomasInstanceStruct *chartInstance,
  real32_T c2_d_dx[19200], real32_T c2_d_dy[19200], real32_T c2_magGrad[19200],
  real_T c2_lowThresh_data[], int32_T c2_lowThresh_size[1], real_T
  c2_highThresh_data[], int32_T c2_highThresh_size[1], boolean_T c2_H[19200])
{
  real_T c2_lowThresh;
  real_T c2_b_lowThresh;
  int32_T c2_i116;
  int32_T c2_i117;
  boolean_T c2_E[19200];
  real_T c2_szT[2];
  real_T c2_highThresh;
  int32_T c2_i118;
  int32_T c2_i119;
  boolean_T c2_x[19200];
  int32_T c2_idx;
  int32_T c2_tmp_size[1];
  int32_T c2_i120;
  int32_T c2_i_size[1];
  int32_T c2_i121;
  int32_T c2_j_size[1];
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b6;
  int32_T c2_i122;
  int32_T c2_b_tmp_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i123;
  int32_T c2_iv3[2];
  boolean_T c2_b7;
  int32_T c2_i124;
  int32_T c2_b_loop_ub;
  int32_T c2_i125;
  int32_T c2_iv4[2];
  boolean_T c2_b8;
  int32_T c2_i126;
  int32_T c2_c_loop_ub;
  int32_T c2_i127;
  int32_T c2_iv5[2];
  int32_T c2_idxStrongR_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i128;
  int32_T c2_idxStrongC_size[1];
  int32_T c2_e_loop_ub;
  int32_T c2_i129;
  int32_T c2_i130;
  boolean_T exitg1;
  boolean_T guard1 = false;
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_lowThresh_size[0]);
  c2_lowThresh = c2_lowThresh_data[0];
  c2_b_lowThresh = c2_lowThresh;
  for (c2_i116 = 0; c2_i116 < 19200; c2_i116++) {
    c2_E[c2_i116] = false;
  }

  for (c2_i117 = 0; c2_i117 < 2; c2_i117++) {
    c2_szT[c2_i117] = 120.0 + 40.0 * (real_T)c2_i117;
  }

  cannythresholding_real32_tbb(c2_d_dx, c2_d_dy, c2_magGrad, c2_szT,
    c2_b_lowThresh, c2_E);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_highThresh_size[0]);
  c2_highThresh = c2_highThresh_data[0];
  for (c2_i118 = 0; c2_i118 < 19200; c2_i118++) {
    c2_x[c2_i118] = ((real_T)c2_magGrad[c2_i118] > c2_highThresh);
  }

  for (c2_i119 = 0; c2_i119 < 19200; c2_i119++) {
    c2_x[c2_i119] = (c2_x[c2_i119] && c2_E[c2_i119]);
  }

  c2_idx = 0;
  c2_tmp_size[0] = 19200;
  for (c2_i120 = 0; c2_i120 < 19200; c2_i120++) {
    chartInstance->c2_tmp_data[c2_i120] = 0;
  }

  c2_i_size[0] = c2_tmp_size[0];
  c2_tmp_size[0] = 19200;
  for (c2_i121 = 0; c2_i121 < 19200; c2_i121++) {
    chartInstance->c2_tmp_data[c2_i121] = 0;
  }

  c2_j_size[0] = c2_tmp_size[0];
  c2_ii = 1;
  c2_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_jj <= 160)) {
    guard1 = false;
    if (c2_x[(c2_ii + 120 * (c2_jj - 1)) - 1]) {
      c2_idx++;
      chartInstance->c2_i_data[c2_idx - 1] = c2_ii;
      chartInstance->c2_j_data[c2_idx - 1] = c2_jj;
      if (c2_idx >= 19200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      c2_ii++;
      if (c2_ii > 120) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b6 = (1 > c2_idx);
  if (c2_b6) {
    c2_i122 = 0;
  } else {
    c2_i122 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i122;
  c2_loop_ub = c2_i122 - 1;
  for (c2_i123 = 0; c2_i123 <= c2_loop_ub; c2_i123++) {
    chartInstance->c2_b_tmp_data[c2_i123] = 1 + c2_i123;
  }

  c2_iv3[0] = 1;
  c2_iv3[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv3);
  c2_i_size[0] = c2_i122;
  c2_b7 = (1 > c2_idx);
  if (c2_b7) {
    c2_i124 = 0;
  } else {
    c2_i124 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i124;
  c2_b_loop_ub = c2_i124 - 1;
  for (c2_i125 = 0; c2_i125 <= c2_b_loop_ub; c2_i125++) {
    chartInstance->c2_b_tmp_data[c2_i125] = 1 + c2_i125;
  }

  c2_iv4[0] = 1;
  c2_iv4[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv4);
  c2_j_size[0] = c2_i124;
  c2_b8 = (1 > c2_idx);
  if (c2_b8) {
    c2_i126 = 0;
  } else {
    c2_i126 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i126;
  c2_c_loop_ub = c2_i126 - 1;
  for (c2_i127 = 0; c2_i127 <= c2_c_loop_ub; c2_i127++) {
    chartInstance->c2_b_tmp_data[c2_i127] = 1 + c2_i127;
  }

  c2_iv5[0] = 1;
  c2_iv5[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv5);
  c2_idxStrongR_size[0] = c2_i_size[0];
  c2_d_loop_ub = c2_i_size[0] - 1;
  for (c2_i128 = 0; c2_i128 <= c2_d_loop_ub; c2_i128++) {
    chartInstance->c2_idxStrongR_data[c2_i128] = (real_T)
      chartInstance->c2_i_data[c2_i128];
  }

  c2_idxStrongC_size[0] = c2_j_size[0];
  c2_e_loop_ub = c2_j_size[0] - 1;
  for (c2_i129 = 0; c2_i129 <= c2_e_loop_ub; c2_i129++) {
    chartInstance->c2_idxStrongC_data[c2_i129] = (real_T)
      chartInstance->c2_j_data[c2_i129];
  }

  if (c2_idxStrongC_size[0] != 0) {
    c2_bwselect(chartInstance, c2_E, chartInstance->c2_idxStrongC_data,
                c2_idxStrongC_size, chartInstance->c2_idxStrongR_data,
                c2_idxStrongR_size, c2_H);
  } else {
    for (c2_i130 = 0; c2_i130 < 19200; c2_i130++) {
      c2_H[c2_i130] = false;
    }
  }
}

static void c2_round(SFc2_tomasInstanceStruct *chartInstance, real_T
                     c2_c_x_data[], int32_T c2_x_size[1], real_T c2_d_x_data[],
                     int32_T c2_b_x_size[1])
{
  int32_T c2_loop_ub;
  int32_T c2_i131;
  c2_b_x_size[0] = c2_x_size[0];
  c2_loop_ub = c2_x_size[0] - 1;
  for (c2_i131 = 0; c2_i131 <= c2_loop_ub; c2_i131++) {
    c2_d_x_data[c2_i131] = c2_c_x_data[c2_i131];
  }

  c2_b_round(chartInstance, c2_d_x_data, c2_b_x_size);
}

static void c2_bwselect(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_varargin_1[19200], real_T c2_c_varargin_2_data[], int32_T
  c2_varargin_2_size[1], real_T c2_varargin_3_data[], int32_T
  c2_varargin_3_size[1], boolean_T c2_varargout_1[19200])
{
  int32_T c2_r_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i132;
  int32_T c2_c_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i133;
  int32_T c2_x_size[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i134;
  int32_T c2_tmp_size[1];
  boolean_T c2_c_x_data[19200];
  int32_T c2_d_loop_ub;
  int32_T c2_i135;
  boolean_T c2_d_tmp_data[19200];
  int32_T c2_e_loop_ub;
  int32_T c2_i136;
  int32_T c2_f_loop_ub;
  int32_T c2_i137;
  int32_T c2_g_loop_ub;
  int32_T c2_i138;
  int32_T c2_h_loop_ub;
  int32_T c2_i139;
  int32_T c2_i_loop_ub;
  int32_T c2_i140;
  int32_T c2_nx;
  int32_T c2_k;
  int32_T c2_b_nx;
  int32_T c2_idx;
  int32_T c2_ii_size[1];
  int32_T c2_ii;
  int32_T c2_b_ii;
  boolean_T c2_b9;
  int32_T c2_i141;
  int32_T c2_i142;
  int32_T c2_badPix_size[1];
  int32_T c2_b_size[1];
  int32_T c2_j_loop_ub;
  int32_T c2_k_loop_ub;
  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_iv6[2];
  int32_T c2_b_r_size[1];
  int32_T c2_b_badPix_size[1];
  int32_T c2_l_loop_ub;
  int32_T c2_m_loop_ub;
  int32_T c2_i145;
  int32_T c2_i146;
  static char_T c2_cv12[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  int32_T c2_c_badPix_size[1];
  real_T c2_c_varargin_1[2];
  int32_T c2_n_loop_ub;
  int32_T c2_i147;
  real_T c2_varargin_2[2];
  static char_T c2_cv13[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'V',
    'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  int32_T c2_b_c_size[1];
  int32_T c2_o_loop_ub;
  int32_T c2_i148;
  int32_T c2_p_loop_ub;
  int32_T c2_i149;
  int32_T c2_q_loop_ub;
  int32_T c2_i150;
  int32_T c2_r_loop_ub;
  int32_T c2_i151;
  int32_T c2_s_loop_ub;
  int32_T c2_i152;
  int32_T c2_t_loop_ub;
  int32_T c2_i153;
  int32_T c2_i154;
  boolean_T c2_d_varargin_1[19200];
  int32_T c2_i155;
  int32_T c2_b_idx;
  int32_T c2_c_ii;
  int32_T c2_d_ii;
  boolean_T c2_b10;
  int32_T c2_i156;
  int32_T c2_u_loop_ub;
  int32_T c2_i157;
  int32_T c2_iv7[2];
  boolean_T exitg1;
  c2_r_size[0] = c2_varargin_3_size[0];
  c2_loop_ub = c2_varargin_3_size[0] - 1;
  for (c2_i132 = 0; c2_i132 <= c2_loop_ub; c2_i132++) {
    chartInstance->c2_r_data[c2_i132] = c2_varargin_3_data[c2_i132];
  }

  c2_b_round(chartInstance, chartInstance->c2_r_data, c2_r_size);
  c2_c_size[0] = c2_varargin_2_size[0];
  c2_b_loop_ub = c2_varargin_2_size[0] - 1;
  for (c2_i133 = 0; c2_i133 <= c2_b_loop_ub; c2_i133++) {
    chartInstance->c2_c_data[c2_i133] = c2_c_varargin_2_data[c2_i133];
  }

  c2_b_round(chartInstance, chartInstance->c2_c_data, c2_c_size);
  c2_x_size[0] = c2_r_size[0];
  c2_c_loop_ub = c2_r_size[0] - 1;
  for (c2_i134 = 0; c2_i134 <= c2_c_loop_ub; c2_i134++) {
    c2_c_x_data[c2_i134] = (chartInstance->c2_r_data[c2_i134] < 1.0);
  }

  c2_tmp_size[0] = c2_r_size[0];
  c2_d_loop_ub = c2_r_size[0] - 1;
  for (c2_i135 = 0; c2_i135 <= c2_d_loop_ub; c2_i135++) {
    c2_d_tmp_data[c2_i135] = (chartInstance->c2_r_data[c2_i135] > 120.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
  c2_x_size[0];
  c2_e_loop_ub = c2_x_size[0] - 1;
  for (c2_i136 = 0; c2_i136 <= c2_e_loop_ub; c2_i136++) {
    c2_c_x_data[c2_i136] = (c2_c_x_data[c2_i136] || c2_d_tmp_data[c2_i136]);
  }

  c2_tmp_size[0] = c2_c_size[0];
  c2_f_loop_ub = c2_c_size[0] - 1;
  for (c2_i137 = 0; c2_i137 <= c2_f_loop_ub; c2_i137++) {
    c2_d_tmp_data[c2_i137] = (chartInstance->c2_c_data[c2_i137] < 1.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
  c2_x_size[0];
  c2_g_loop_ub = c2_x_size[0] - 1;
  for (c2_i138 = 0; c2_i138 <= c2_g_loop_ub; c2_i138++) {
    c2_c_x_data[c2_i138] = (c2_c_x_data[c2_i138] || c2_d_tmp_data[c2_i138]);
  }

  c2_tmp_size[0] = c2_c_size[0];
  c2_h_loop_ub = c2_c_size[0] - 1;
  for (c2_i139 = 0; c2_i139 <= c2_h_loop_ub; c2_i139++) {
    c2_d_tmp_data[c2_i139] = (chartInstance->c2_c_data[c2_i139] > 160.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
  c2_x_size[0];
  c2_i_loop_ub = c2_x_size[0] - 1;
  for (c2_i140 = 0; c2_i140 <= c2_i_loop_ub; c2_i140++) {
    c2_c_x_data[c2_i140] = (c2_c_x_data[c2_i140] || c2_d_tmp_data[c2_i140]);
  }

  c2_nx = c2_x_size[0];
  c2_k = c2_nx;
  c2_b_nx = c2_nx - 1;
  c2_idx = 0;
  c2_ii_size[0] = c2_k;
  c2_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_ii - 1 <= c2_b_nx)) {
    c2_b_ii = c2_ii;
    if (c2_c_x_data[c2_b_ii - 1]) {
      c2_idx++;
      chartInstance->c2_ii_data[c2_idx - 1] = c2_b_ii;
      if (c2_idx >= c2_k) {
        exitg1 = true;
      } else {
        c2_ii++;
      }
    } else {
      c2_ii++;
    }
  }

  if (c2_idx <= c2_k) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_emlrt_marshallOut(chartInstance, c2_cv1), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv1))));
  }

  if (c2_k == 1) {
    if (c2_idx == 0) {
      c2_i141 = c2_ii_size[0];
      c2_ii_size[0] = 0;
    }
  } else {
    c2_b9 = (1 > c2_idx);
    if (c2_b9) {
      c2_i142 = 0;
    } else {
      c2_i142 = c2_idx;
    }

    c2_b_size[0] = c2_i142;
    c2_k_loop_ub = c2_i142 - 1;
    for (c2_i144 = 0; c2_i144 <= c2_k_loop_ub; c2_i144++) {
      chartInstance->c2_b_data[c2_i144] = 1 + c2_i144;
    }

    c2_iv6[0] = 1;
    c2_iv6[1] = c2_b_size[0];
    c2_indexShapeCheck(chartInstance, c2_ii_size[0], c2_iv6);
    c2_ii_size[0] = c2_i142;
  }

  c2_badPix_size[0] = c2_ii_size[0];
  c2_j_loop_ub = c2_ii_size[0] - 1;
  for (c2_i143 = 0; c2_i143 <= c2_j_loop_ub; c2_i143++) {
    chartInstance->c2_badPix_data[c2_i143] = (real_T)chartInstance->
      c2_ii_data[c2_i143];
  }

  if (c2_badPix_size[0] != 0) {
    c2_b_warning(chartInstance);
    c2_b_badPix_size[0] = c2_badPix_size[0];
    c2_m_loop_ub = c2_badPix_size[0] - 1;
    for (c2_i146 = 0; c2_i146 <= c2_m_loop_ub; c2_i146++) {
      chartInstance->c2_b_badPix_data[c2_i146] = (int32_T)
        chartInstance->c2_badPix_data[c2_i146];
    }

    c2_c_nullAssignment(chartInstance, chartInstance->c2_r_data, c2_r_size,
                        chartInstance->c2_b_badPix_data, c2_b_badPix_size);
    c2_c_badPix_size[0] = c2_badPix_size[0];
    c2_n_loop_ub = c2_badPix_size[0] - 1;
    for (c2_i147 = 0; c2_i147 <= c2_n_loop_ub; c2_i147++) {
      chartInstance->c2_c_badPix_data[c2_i147] = (int32_T)
        chartInstance->c2_badPix_data[c2_i147];
    }

    c2_c_nullAssignment(chartInstance, chartInstance->c2_c_data, c2_c_size,
                        chartInstance->c2_c_badPix_data, c2_c_badPix_size);
  }

  c2_b_r_size[0] = c2_r_size[0];
  c2_l_loop_ub = c2_r_size[0] - 1;
  for (c2_i145 = 0; c2_i145 <= c2_l_loop_ub; c2_i145++) {
    chartInstance->c2_b_r_data[c2_i145] = chartInstance->c2_r_data[c2_i145];
  }

  if (c2_allinrange(chartInstance, chartInstance->c2_b_r_data, c2_b_r_size, 1.0,
                    120)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_emlrt_marshallOut(chartInstance, c2_cv12), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv12))));
  }

  c2_c_varargin_1[0] = (real_T)c2_r_size[0];
  c2_c_varargin_1[1] = 1.0;
  c2_varargin_2[0] = (real_T)c2_c_size[0];
  c2_varargin_2[1] = 1.0;
  if (c2_isequal(chartInstance, c2_c_varargin_1, c2_varargin_2)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_cv13), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv13))));
  }

  c2_b_c_size[0] = c2_c_size[0];
  c2_o_loop_ub = c2_c_size[0] - 1;
  for (c2_i148 = 0; c2_i148 <= c2_o_loop_ub; c2_i148++) {
    chartInstance->c2_b_c_data[c2_i148] = chartInstance->c2_c_data[c2_i148];
  }

  if (c2_allinrange(chartInstance, chartInstance->c2_b_c_data, c2_b_c_size, 1.0,
                    160)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_emlrt_marshallOut(chartInstance, c2_cv12), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv12))));
  }

  c2_ii_size[0] = c2_r_size[0];
  c2_p_loop_ub = c2_r_size[0] - 1;
  for (c2_i149 = 0; c2_i149 <= c2_p_loop_ub; c2_i149++) {
    chartInstance->c2_ii_data[c2_i149] = (int32_T)chartInstance->
      c2_r_data[c2_i149];
  }

  c2_b_size[0] = c2_c_size[0];
  c2_q_loop_ub = c2_c_size[0] - 1;
  for (c2_i150 = 0; c2_i150 <= c2_q_loop_ub; c2_i150++) {
    chartInstance->c2_b_data[c2_i150] = (int32_T)chartInstance->
      c2_c_data[c2_i150] - 1;
  }

  c2_b_size[0];
  c2_r_loop_ub = c2_b_size[0] - 1;
  for (c2_i151 = 0; c2_i151 <= c2_r_loop_ub; c2_i151++) {
    chartInstance->c2_b_data[c2_i151] *= 120;
  }

  c2_ii_size[0];
  c2_s_loop_ub = c2_ii_size[0] - 1;
  for (c2_i152 = 0; c2_i152 <= c2_s_loop_ub; c2_i152++) {
    chartInstance->c2_ii_data[c2_i152] += chartInstance->c2_b_data[c2_i152];
  }

  c2_r_size[0] = c2_ii_size[0];
  c2_t_loop_ub = c2_ii_size[0] - 1;
  for (c2_i153 = 0; c2_i153 <= c2_t_loop_ub; c2_i153++) {
    chartInstance->c2_r_data[c2_i153] = (real_T)chartInstance->
      c2_ii_data[c2_i153];
  }

  for (c2_i154 = 0; c2_i154 < 19200; c2_i154++) {
    c2_d_varargin_1[c2_i154] = !c2_b_varargin_1[c2_i154];
  }

  c2_imfill(chartInstance, c2_d_varargin_1, chartInstance->c2_r_data, c2_r_size,
            c2_varargout_1);
  for (c2_i155 = 0; c2_i155 < 19200; c2_i155++) {
    c2_varargout_1[c2_i155] = (c2_varargout_1[c2_i155] &&
      c2_b_varargin_1[c2_i155]);
  }

  c2_b_idx = 0;
  c2_c_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_c_ii - 1 < 19200)) {
    c2_d_ii = c2_c_ii - 1;
    if (c2_varargout_1[c2_d_ii]) {
      c2_b_idx++;
      if (c2_b_idx >= 19200) {
        exitg1 = true;
      } else {
        c2_c_ii++;
      }
    } else {
      c2_c_ii++;
    }
  }

  c2_b10 = (1 > c2_b_idx);
  if (c2_b10) {
    c2_i156 = 0;
  } else {
    c2_i156 = c2_b_idx;
  }

  c2_b_size[0] = c2_i156;
  c2_u_loop_ub = c2_i156 - 1;
  for (c2_i157 = 0; c2_i157 <= c2_u_loop_ub; c2_i157++) {
    chartInstance->c2_b_data[c2_i157] = 1 + c2_i157;
  }

  c2_iv7[0] = 1;
  c2_iv7[1] = c2_b_size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv7);
}

static void c2_b_warning(SFc2_tomasInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv14[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv15[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[26] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w',
    's', 'e', 'l', 'e', 'c', 't', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n',
    'g', 'e' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv14, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv15, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 26),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1], real_T c2_d_x_data[], int32_T c2_b_x_size[1])
{
  int32_T c2_loop_ub;
  int32_T c2_i158;
  int32_T c2_b_idx_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i159;
  int32_T c2_d_idx_data[19200];
  c2_b_x_size[0] = c2_x_size[0];
  c2_loop_ub = c2_x_size[0] - 1;
  for (c2_i158 = 0; c2_i158 <= c2_loop_ub; c2_i158++) {
    c2_d_x_data[c2_i158] = c2_c_x_data[c2_i158];
  }

  c2_b_idx_size[0] = c2_idx_size[0];
  c2_b_loop_ub = c2_idx_size[0] - 1;
  for (c2_i159 = 0; c2_i159 <= c2_b_loop_ub; c2_i159++) {
    c2_d_idx_data[c2_i159] = c2_c_idx_data[c2_i159];
  }

  c2_c_nullAssignment(chartInstance, c2_d_x_data, c2_b_x_size, c2_d_idx_data,
                      c2_b_idx_size);
}

static void c2_validate_inputs(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1])
{
  int32_T c2_n;
  boolean_T c2_p;
  real_T c2_d7;
  int32_T c2_i160;
  int32_T c2_k;
  real_T c2_b_k;
  const mxArray *c2_c_y = NULL;
  int32_T c2_x;
  const mxArray *c2_d_y = NULL;
  int32_T c2_b_x;
  boolean_T exitg1;
  (void)chartInstance;
  (void)c2_c_x_data;
  c2_n = c2_x_size[0];
  c2_p = true;
  c2_d7 = (real_T)c2_idx_size[0];
  c2_i160 = (int32_T)c2_d7 - 1;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= c2_i160)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    if ((c2_c_idx_data[(int32_T)c2_b_k - 1] < 1) || (c2_c_idx_data[(int32_T)
         c2_b_k - 1] > c2_n)) {
      c2_p = false;
      exitg1 = true;
    } else {
      c2_x = c2_c_idx_data[(int32_T)c2_b_k - 1];
      c2_b_x = c2_x;
      if (c2_c_idx_data[(int32_T)c2_b_k - 1] != c2_b_x) {
        c2_p = false;
        exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }
}

static void c2_make_bitarray(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_n, int32_T c2_c_idx_data[], int32_T c2_idx_size[1], boolean_T c2_b_b_data[],
  int32_T c2_b_size[2])
{
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_loop_ub;
  int32_T c2_i163;
  int32_T c2_i164;
  int32_T c2_k;
  int32_T c2_b_k;
  (void)chartInstance;
  c2_b_size[0] = 1;
  c2_b_size[1] = c2_n;
  c2_i161 = c2_b_size[0];
  c2_i162 = c2_b_size[1];
  c2_loop_ub = c2_n - 1;
  for (c2_i163 = 0; c2_i163 <= c2_loop_ub; c2_i163++) {
    c2_b_b_data[c2_i163] = false;
  }

  c2_i164 = c2_idx_size[0] - 1;
  for (c2_k = 0; c2_k <= c2_i164; c2_k++) {
    c2_b_k = c2_k;
    c2_b_b_data[c2_c_idx_data[c2_b_k] - 1] = true;
  }
}

static int32_T c2_num_true(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_b_b_data[], int32_T c2_b_size[2])
{
  int32_T c2_n;
  int32_T c2_i165;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i166;
  int32_T c2_i167;
  (void)chartInstance;
  c2_n = 0;
  c2_i165 = c2_b_size[1] - 1;
  for (c2_k = 0; c2_k <= c2_i165; c2_k++) {
    c2_b_k = c2_k;
    c2_i166 = c2_b_size[1];
    c2_i167 = c2_i166;
    c2_n += (int32_T)c2_b_b_data[c2_b_k];
  }

  return c2_n;
}

static boolean_T c2_allinrange(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], real_T c2_lo, int32_T c2_hi)
{
  boolean_T c2_p;
  real_T c2_d8;
  int32_T c2_i168;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_b11;
  int32_T exitg1;
  (void)chartInstance;
  (void)c2_lo;
  c2_d8 = (real_T)c2_x_size[0];
  c2_i168 = (int32_T)c2_d8 - 1;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k <= c2_i168) {
      c2_b_k = 1.0 + (real_T)c2_k;
      if ((c2_c_x_data[(int32_T)c2_b_k - 1] >= 1.0) && (c2_c_x_data[(int32_T)
           c2_b_k - 1] <= (real_T)c2_hi)) {
        c2_b11 = true;
      } else {
        c2_b11 = false;
      }

      if (!c2_b11) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_p;
}

static boolean_T c2_isequal(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_b_varargin_1[2], real_T c2_varargin_2[2])
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x1;
  real_T c2_x2;
  boolean_T c2_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x1 = c2_b_varargin_1[(int32_T)c2_b_k - 1];
    c2_x2 = c2_varargin_2[(int32_T)c2_b_k - 1];
    c2_c_p = (c2_x1 == c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_b_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static void c2_imfill(SFc2_tomasInstanceStruct *chartInstance, boolean_T
                      c2_b_varargin_1[19200], real_T c2_c_varargin_2_data[],
                      int32_T c2_varargin_2_size[1], boolean_T c2_I2[19200])
{
  int32_T c2_b_varargin_2_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i169;
  static char_T c2_cv16[36] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'n', 'o', 'I', 'n', 't', 'e', 'r', 'a', 'c', 't', 'i',
    'v', 'e', 'I', 'n', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  int32_T c2_c_varargin_2_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i170;
  int32_T c2_locationsVar_size[1];
  int32_T c2_i171;
  int32_T c2_i172;
  boolean_T c2_mask[19200];
  int32_T c2_i173;
  int32_T c2_tmp_size[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i174;
  int32_T c2_b_tmp_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i175;
  boolean_T c2_d_tmp_data[19200];
  int32_T c2_e_loop_ub;
  int32_T c2_i176;
  int32_T c2_i177;
  real_T c2_imSizeT[2];
  int32_T c2_i178;
  c2_b_varargin_2_size[0] = c2_varargin_2_size[0];
  c2_loop_ub = c2_varargin_2_size[0] - 1;
  for (c2_i169 = 0; c2_i169 <= c2_loop_ub; c2_i169++) {
    chartInstance->c2_varargin_2_data[c2_i169] = c2_c_varargin_2_data[c2_i169];
  }

  if (!c2_b_isequal(chartInstance, chartInstance->c2_varargin_2_data,
                    c2_b_varargin_2_size, 0.0)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_c_emlrt_marshallOut(chartInstance, c2_cv16), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_c_emlrt_marshallOut(chartInstance, c2_cv16))));
  }

  c2_c_varargin_2_size[0] = c2_varargin_2_size[0];
  c2_b_loop_ub = c2_varargin_2_size[0] - 1;
  for (c2_i170 = 0; c2_i170 <= c2_b_loop_ub; c2_i170++) {
    chartInstance->c2_b_varargin_2_data[c2_i170] = c2_c_varargin_2_data[c2_i170];
  }

  c2_checkLocations(chartInstance, chartInstance->c2_b_varargin_2_data,
                    c2_c_varargin_2_size, chartInstance->c2_locationsVar_data,
                    c2_locationsVar_size);
  for (c2_i171 = 0; c2_i171 < 19200; c2_i171++) {
    c2_mask[c2_i171] = c2_b_varargin_1[c2_i171];
  }

  for (c2_i172 = 0; c2_i172 < 19200; c2_i172++) {
    c2_mask[c2_i172] = !c2_mask[c2_i172];
  }

  for (c2_i173 = 0; c2_i173 < 19200; c2_i173++) {
    c2_I2[c2_i173] = false;
  }

  c2_tmp_size[0] = c2_locationsVar_size[0];
  c2_c_loop_ub = c2_locationsVar_size[0] - 1;
  for (c2_i174 = 0; c2_i174 <= c2_c_loop_ub; c2_i174++) {
    chartInstance->c2_c_tmp_data[c2_i174] = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)chartInstance->c2_locationsVar_data[c2_i174], 1, 19200);
  }

  c2_b_tmp_size[0] = c2_locationsVar_size[0];
  c2_d_loop_ub = c2_locationsVar_size[0] - 1;
  for (c2_i175 = 0; c2_i175 <= c2_d_loop_ub; c2_i175++) {
    c2_d_tmp_data[c2_i175] = c2_mask[(int32_T)
      chartInstance->c2_locationsVar_data[c2_i175] - 1];
  }

  _SFD_SUB_ASSIGN_SIZE_CHECK_1D(c2_tmp_size[0], c2_b_tmp_size[0]);
  c2_e_loop_ub = c2_b_tmp_size[0] - 1;
  for (c2_i176 = 0; c2_i176 <= c2_e_loop_ub; c2_i176++) {
    c2_I2[chartInstance->c2_c_tmp_data[c2_i176] - 1] = c2_d_tmp_data[c2_i176];
  }

  for (c2_i177 = 0; c2_i177 < 2; c2_i177++) {
    c2_imSizeT[c2_i177] = 120.0 + 40.0 * (real_T)c2_i177;
  }

  ippreconstruct_uint8(c2_I2, c2_mask, c2_imSizeT, 2.0);
  for (c2_i178 = 0; c2_i178 < 19200; c2_i178++) {
    c2_I2[c2_i178] = (c2_b_varargin_1[c2_i178] || c2_I2[c2_i178]);
  }
}

static boolean_T c2_b_isequal(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_varargin_1_data[], int32_T c2_varargin_1_size[1], real_T c2_varargin_2)
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_d_p;
  real_T c2_x1;
  boolean_T c2_e_p;
  (void)chartInstance;
  (void)c2_varargin_2;
  c2_p = false;
  c2_b_p = false;
  if ((real_T)c2_varargin_1_size[0] != 1.0) {
  } else {
    c2_b_p = true;
  }

  if (c2_b_p) {
    c2_c_p = true;
  } else {
    c2_c_p = false;
  }

  c2_d_p = c2_c_p;
  if (c2_c_p && (c2_varargin_1_size[0] != 0)) {
    c2_x1 = c2_varargin_1_data[0];
    c2_e_p = (c2_x1 == 0.0);
    if (!c2_e_p) {
      c2_d_p = false;
    }
  }

  if (!c2_d_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static void c2_checkLocations(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_locations_data[], int32_T c2_locations_size[1], real_T
  c2_b_locationsVar_data[], int32_T c2_locationsVar_size[1])
{
  int32_T c2_b_locations_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i179;
  int32_T c2_i180;
  int32_T c2_c_locations_size[1];
  int32_T c2_badPixels_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_c_loop_ub;
  int32_T c2_i181;
  int32_T c2_i182;
  int32_T c2_d_loop_ub;
  int32_T c2_tmp_size[1];
  boolean_T c2_badPixels_data[19200];
  int32_T c2_i183;
  int32_T c2_e_loop_ub;
  int32_T c2_i184;
  int32_T c2_f_loop_ub;
  boolean_T c2_d_tmp_data[19200];
  int32_T c2_i185;
  int32_T c2_g_loop_ub;
  int32_T c2_i186;
  int32_T c2_b_badPixels_size[1];
  int32_T c2_h_loop_ub;
  int32_T c2_i187;
  boolean_T c2_b_badPixels_data[19200];
  real_T c2_numelBadPix;
  int32_T c2_i188;
  int32_T c2_s;
  real_T c2_b_s;
  c2_b_locations_size[0] = c2_locations_size[0];
  c2_loop_ub = c2_locations_size[0] - 1;
  for (c2_i179 = 0; c2_i179 <= c2_loop_ub; c2_i179++) {
    chartInstance->c2_locations_data[c2_i179] = c2_c_locations_data[c2_i179];
  }

  c2_validateattributes(chartInstance, chartInstance->c2_locations_data,
                        c2_b_locations_size);
  c2_i180 = c2_locationsVar_size[0];
  c2_locationsVar_size[0] = 0;
  if (c2_locations_size[0] != 0) {
    c2_c_locations_size[0] = c2_locations_size[0] + c2_locationsVar_size[0];
    c2_b_loop_ub = c2_locations_size[0] - 1;
    for (c2_i181 = 0; c2_i181 <= c2_b_loop_ub; c2_i181++) {
      chartInstance->c2_b_locations_data[c2_i181] = c2_c_locations_data[c2_i181];
    }

    c2_d_loop_ub = c2_locationsVar_size[0] - 1;
    for (c2_i183 = 0; c2_i183 <= c2_d_loop_ub; c2_i183++) {
      chartInstance->c2_b_locations_data[c2_i183 + c2_locations_size[0]] =
        c2_b_locationsVar_data[c2_i183];
    }

    c2_locationsVar_size[0] = c2_c_locations_size[0];
    c2_f_loop_ub = c2_c_locations_size[0] - 1;
    for (c2_i185 = 0; c2_i185 <= c2_f_loop_ub; c2_i185++) {
      c2_b_locationsVar_data[c2_i185] = chartInstance->
        c2_b_locations_data[c2_i185];
    }
  }

  c2_badPixels_size[0] = c2_locations_size[0];
  c2_c_loop_ub = c2_locations_size[0] - 1;
  for (c2_i182 = 0; c2_i182 <= c2_c_loop_ub; c2_i182++) {
    c2_badPixels_data[c2_i182] = (c2_c_locations_data[c2_i182] < 1.0);
  }

  c2_tmp_size[0] = c2_locations_size[0];
  c2_e_loop_ub = c2_locations_size[0] - 1;
  for (c2_i184 = 0; c2_i184 <= c2_e_loop_ub; c2_i184++) {
    c2_d_tmp_data[c2_i184] = (c2_c_locations_data[c2_i184] > 19200.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_badPixels_size[0], c2_tmp_size[0]);
  c2_badPixels_size[0];
  c2_g_loop_ub = c2_badPixels_size[0] - 1;
  for (c2_i186 = 0; c2_i186 <= c2_g_loop_ub; c2_i186++) {
    c2_badPixels_data[c2_i186] = (c2_badPixels_data[c2_i186] ||
      c2_d_tmp_data[c2_i186]);
  }

  c2_b_badPixels_size[0] = c2_badPixels_size[0];
  c2_h_loop_ub = c2_badPixels_size[0] - 1;
  for (c2_i187 = 0; c2_i187 <= c2_h_loop_ub; c2_i187++) {
    c2_b_badPixels_data[c2_i187] = c2_badPixels_data[c2_i187];
  }

  if (c2_any(chartInstance, c2_b_badPixels_data, c2_b_badPixels_size)) {
    c2_numelBadPix = (real_T)c2_badPixels_size[0];
    c2_c_warning(chartInstance);
    c2_i188 = (int32_T)((1.0 + (-1.0 - c2_numelBadPix)) / -1.0);
    _SFD_FOR_LOOP_VECTOR_CHECK(c2_numelBadPix, -1.0, 1.0, mxDOUBLE_CLASS,
      c2_i188);
    for (c2_s = 0; c2_s < c2_i188; c2_s++) {
      c2_b_s = c2_numelBadPix + -(real_T)c2_s;
      if (c2_badPixels_data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_b_s, 1, c2_badPixels_size[0]) - 1]) {
        c2_d_nullAssignment(chartInstance, c2_b_locationsVar_data,
                            c2_locationsVar_size, (int32_T)c2_b_s);
      }
    }
  }
}

static void c2_validateattributes(SFc2_tomasInstanceStruct *chartInstance,
  real_T c2_a_data[], int32_T c2_a_size[1])
{
  boolean_T c2_p;
  real_T c2_d9;
  int32_T c2_i189;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  boolean_T c2_b12;
  boolean_T c2_b_p;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv17[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's',
    'i', 't', 'i', 'v', 'e' };

  boolean_T c2_c_p;
  const mxArray *c2_d_y = NULL;
  real_T c2_d10;
  static char_T c2_cv18[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  int32_T c2_i190;
  const mxArray *c2_e_y = NULL;
  int32_T c2_c_k;
  static char_T c2_cv19[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  real_T c2_d_k;
  real_T c2_b_x;
  boolean_T c2_b13;
  real_T c2_c_x;
  real_T c2_d_x;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_d_p;
  static char_T c2_cv20[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't',
    'e', 'g', 'e', 'r' };

  const mxArray *c2_g_y = NULL;
  boolean_T c2_e_p;
  const mxArray *c2_h_y = NULL;
  static char_T c2_cv21[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_d9 = (real_T)c2_a_size[0];
  c2_i189 = (int32_T)c2_d9 - 1;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= c2_i189)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x = c2_a_data[(int32_T)c2_b_k - 1];
    c2_b_p = !(c2_x <= 0.0);
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b12 = true;
  } else {
    c2_b12 = false;
  }

  if (c2_b12) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv17, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv18, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv19, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  c2_c_p = true;
  c2_d10 = (real_T)c2_a_size[0];
  c2_i190 = (int32_T)c2_d10 - 1;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k <= c2_i190)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_b_x = c2_a_data[(int32_T)c2_d_k - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    if (c2_d_x == c2_b_x) {
      c2_d_p = true;
    } else {
      c2_d_p = false;
    }

    c2_e_p = c2_d_p;
    if (c2_e_p) {
      c2_c_k++;
    } else {
      c2_c_p = false;
      exitg1 = true;
    }
  }

  if (c2_c_p) {
    c2_b13 = true;
  } else {
    c2_b13 = false;
  }

  if (c2_b13) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv20, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv21, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_h_y)));
  }
}

static boolean_T c2_any(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_c_x_data[], int32_T c2_x_size[1])
{
  boolean_T c2_c_y;
  boolean_T c2_b14;
  const mxArray *c2_d_y = NULL;
  static char_T c2_cv22[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
    'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c2_e_y = NULL;
  real_T c2_vlen;
  real_T c2_c_a;
  int32_T c2_c;
  int32_T c2_d_a;
  int32_T c2_vspread;
  int32_T c2_b;
  int32_T c2_i2;
  int32_T c2_e_a;
  int32_T c2_ix;
  boolean_T c2_b15;
  boolean_T exitg1;
  (void)chartInstance;
  if ((c2_x_size[0] == 1) || ((real_T)c2_x_size[0] != 1.0)) {
    c2_b14 = true;
  } else {
    c2_b14 = false;
  }

  if (c2_b14) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv22, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv22, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_c_y = false;
  c2_vlen = (real_T)c2_x_size[0];
  c2_c_a = c2_vlen;
  c2_c = (int32_T)c2_c_a;
  c2_d_a = c2_c - 1;
  c2_vspread = c2_d_a;
  c2_b = c2_vspread;
  c2_i2 = c2_b;
  c2_e_a = c2_i2;
  c2_i2 = c2_e_a;
  c2_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_ix + 1 <= c2_i2 + 1)) {
    if (!c2_c_x_data[c2_ix]) {
      c2_b15 = true;
    } else {
      c2_b15 = false;
    }

    if (!c2_b15) {
      c2_c_y = true;
      exitg1 = true;
    } else {
      c2_ix++;
    }
  }

  return c2_c_y;
}

static void c2_c_warning(SFc2_tomasInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv23[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv24[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[24] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'l', 'l', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv23, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv24, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_b_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_idx, real_T c2_d_x_data[],
  int32_T c2_b_x_size[1])
{
  int32_T c2_loop_ub;
  int32_T c2_i191;
  c2_b_x_size[0] = c2_x_size[0];
  c2_loop_ub = c2_x_size[0] - 1;
  for (c2_i191 = 0; c2_i191 <= c2_loop_ub; c2_i191++) {
    c2_d_x_data[c2_i191] = c2_c_x_data[c2_i191];
  }

  c2_d_nullAssignment(chartInstance, c2_d_x_data, c2_b_x_size, c2_idx);
}

static const mxArray *c2_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[30])
{
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c2_c_y;
}

static const mxArray *c2_b_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[34])
{
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  return c2_c_y;
}

static const mxArray *c2_c_emlrt_marshallOut(SFc2_tomasInstanceStruct
  *chartInstance, const char_T c2_d_u[36])
{
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 36),
                false);
  return c2_c_y;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_d_u;
  const mxArray *c2_c_y = NULL;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_d_u = *(int32_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_c_y;
  int32_T c2_i192;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_i192, 1, 6, 0U, 0, 0U, 0);
  c2_c_y = c2_i192;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_c_y;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_tomas, const char_T *c2_identifier)
{
  uint8_T c2_c_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_tomas), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_tomas);
  return c2_c_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_c_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_c_y = c2_u0;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void c2_b_round(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1])
{
  int32_T c2_nx;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_x;
  real_T c2_b_x;
  (void)chartInstance;
  c2_nx = c2_x_size[0] - 1;
  for (c2_k = 0; c2_k <= c2_nx; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_c_x_data[c2_b_k];
    c2_b_x = c2_x;
    c2_c_x_data[c2_b_k] = c2_b_x;
  }
}

static void c2_c_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_c_idx_data[], int32_T
  c2_idx_size[1])
{
  int32_T c2_b_x_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i193;
  int32_T c2_b_idx_size[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i194;
  int32_T c2_nxin;
  int32_T c2_nrowx;
  int32_T c2_c_idx_size[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i195;
  boolean_T c2_b_b_data[19200];
  int32_T c2_b_size[2];
  int32_T c2_b_b_size[2];
  int32_T c2_i196;
  int32_T c2_i197;
  int32_T c2_d_loop_ub;
  int32_T c2_i198;
  int32_T c2_nxout;
  boolean_T c2_c_b_data[19200];
  int32_T c2_nb;
  int32_T c2_k0;
  int32_T c2_k;
  int32_T c2_b_k;
  boolean_T c2_b16;
  int32_T c2_i199;
  c2_b_x_size[0] = c2_x_size[0];
  c2_loop_ub = c2_x_size[0] - 1;
  for (c2_i193 = 0; c2_i193 <= c2_loop_ub; c2_i193++) {
    chartInstance->c2_b_x_data[c2_i193] = c2_c_x_data[c2_i193];
  }

  c2_b_idx_size[0] = c2_idx_size[0];
  c2_b_loop_ub = c2_idx_size[0] - 1;
  for (c2_i194 = 0; c2_i194 <= c2_b_loop_ub; c2_i194++) {
    chartInstance->c2_idx_data[c2_i194] = c2_c_idx_data[c2_i194];
  }

  c2_validate_inputs(chartInstance, chartInstance->c2_b_x_data, c2_b_x_size,
                     chartInstance->c2_idx_data, c2_b_idx_size);
  c2_nxin = c2_x_size[0];
  c2_nrowx = c2_x_size[0];
  c2_c_idx_size[0] = c2_idx_size[0];
  c2_c_loop_ub = c2_idx_size[0] - 1;
  for (c2_i195 = 0; c2_i195 <= c2_c_loop_ub; c2_i195++) {
    chartInstance->c2_b_idx_data[c2_i195] = c2_c_idx_data[c2_i195];
  }

  c2_make_bitarray(chartInstance, c2_nxin, chartInstance->c2_b_idx_data,
                   c2_c_idx_size, c2_b_b_data, c2_b_size);
  c2_b_b_size[0] = 1;
  c2_b_b_size[1] = c2_b_size[1];
  c2_i196 = c2_b_b_size[0];
  c2_i197 = c2_b_b_size[1];
  c2_d_loop_ub = c2_b_size[0] * c2_b_size[1] - 1;
  for (c2_i198 = 0; c2_i198 <= c2_d_loop_ub; c2_i198++) {
    c2_c_b_data[c2_i198] = c2_b_b_data[c2_i198];
  }

  c2_nxout = c2_nxin - c2_num_true(chartInstance, c2_c_b_data, c2_b_b_size);
  c2_nb = c2_b_size[1];
  c2_k0 = -1;
  for (c2_k = 0; c2_k < c2_nxin; c2_k++) {
    c2_b_k = c2_k;
    if ((c2_b_k + 1 > c2_nb) || (!c2_b_b_data[c2_b_k])) {
      c2_k0++;
      c2_c_x_data[c2_k0] = c2_c_x_data[c2_b_k];
    }
  }

  if (c2_nxout <= c2_nrowx) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_emlrt_marshallOut(chartInstance, c2_cv1), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv1))));
  }

  c2_b16 = (1 > c2_nxout);
  if (c2_b16) {
    c2_i199 = 0;
  } else {
    c2_i199 = c2_nxout;
  }

  c2_x_size[0] = c2_i199;
}

static void c2_d_nullAssignment(SFc2_tomasInstanceStruct *chartInstance, real_T
  c2_c_x_data[], int32_T c2_x_size[1], int32_T c2_idx)
{
  int32_T c2_b_idx;
  int32_T c2_c_idx;
  real_T c2_d11;
  int32_T c2_n;
  boolean_T c2_p;
  int32_T c2_x;
  int32_T c2_b_x;
  const mxArray *c2_c_y = NULL;
  int32_T c2_d_idx;
  const mxArray *c2_d_y = NULL;
  int32_T c2_nrowx;
  int32_T c2_nrows;
  int32_T c2_i;
  int32_T c2_c_x[2];
  const mxArray *c2_e_y = NULL;
  boolean_T c2_b17;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i200;
  int32_T c2_b_x_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i201;
  int32_T c2_b_loop_ub;
  int32_T c2_i202;
  c2_b_idx = c2_idx;
  c2_c_idx = c2_b_idx;
  c2_d11 = (real_T)c2_x_size[0];
  c2_n = (int32_T)c2_d11;
  c2_p = true;
  if (c2_c_idx > c2_n) {
    c2_p = false;
  } else {
    c2_x = c2_c_idx;
    c2_b_x = c2_x;
    if (c2_c_idx != c2_b_x) {
      c2_p = false;
    }
  }

  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_d_idx = c2_idx;
  c2_nrowx = c2_x_size[0];
  c2_nrows = c2_nrowx - 1;
  for (c2_i = c2_d_idx; c2_i <= c2_nrows; c2_i++) {
    c2_c_x[0] = c2_x_size[0];
    c2_c_x[1] = 1;
    c2_c_x_data[c2_i - 1] = c2_c_x_data[c2_i];
  }

  if (c2_nrows <= c2_nrowx) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_b17 = (1 > c2_nrows);
  if (c2_b17) {
    c2_i200 = -1;
  } else {
    c2_i200 = c2_nrows - 1;
  }

  c2_b_x_size[0] = c2_i200 + 1;
  c2_loop_ub = c2_i200;
  for (c2_i201 = 0; c2_i201 <= c2_loop_ub; c2_i201++) {
    chartInstance->c2_x_data[c2_i201] = c2_c_x_data[c2_i201];
  }

  c2_x_size[0] = c2_b_x_size[0];
  c2_b_loop_ub = c2_b_x_size[0] - 1;
  for (c2_i202 = 0; c2_i202 <= c2_b_loop_ub; c2_i202++) {
    c2_c_x_data[c2_i202] = chartInstance->c2_x_data[c2_i202];
  }
}

static void init_dsm_address_info(SFc2_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_tomasInstanceStruct *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_c_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_b_y = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c2_tomas_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2181966925U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3622309961U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1151756893U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3500755181U);
}

mxArray *sf_c2_tomas_third_party_uses_info(void)
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

mxArray *sf_c2_tomas_jit_fallback_info(void)
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

mxArray *sf_c2_tomas_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_tomas(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wMjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/Efg"
    "8C7hdCcT+En1kcn5hcklmWGp9sFF+Sn5tYjDAPBABAmxbK"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_tomas_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_tomasInstanceStruct *chartInstance = (SFc2_tomasInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _tomasMachineNumber_,
           2,
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
        init_script_number_translation(_tomasMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_tomasMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _tomasMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _tomasMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_tomasInstanceStruct *chartInstance = (SFc2_tomasInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_c_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_b_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s9NF6NFQLVgN6uxqeXk2ueE";
}

static void sf_opaque_initialize_c2_tomas(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_tomasInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
  initialize_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_tomas(void *chartInstanceVar)
{
  enable_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_tomas(void *chartInstanceVar)
{
  disable_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_tomas(void *chartInstanceVar)
{
  sf_gateway_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_tomas(SimStruct* S)
{
  return get_sim_state_c2_tomas((SFc2_tomasInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_tomas(SimStruct* S, const mxArray *st)
{
  set_sim_state_c2_tomas((SFc2_tomasInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c2_tomas(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_tomasInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_tomas_optimization_info();
    }

    finalize_c2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_tomas((SFc2_tomasInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_tomas(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_tomas((SFc2_tomasInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc2_tomas((SFc2_tomasInstanceStruct*)sf_get_chart_instance_ptr
      (S));
  }
}

const char* sf_c2_tomas_get_post_codegen_info(void)
{
  return
    (
     "eNrtVc1u00AQdqJQUQmqqCD1AlJvcEQ9FDhRmh8RKU0Lbgu3amtP4lXWu+7+pImQOPAk8AC8R1+"
     "BOycu9BEYO05iObbTNmolJCxt1ut8883vzlil1p6FzxquC/xZwf0+rrI1fu7F51Jijb9XrGfx+Q"
     "hB3PgHRBJfWYUPJz58ACWY0VTwFu+KTBjlXZDAHcQGQuo8NkV9wyjvNw13Qj710aOOZ3vCMHcXZ"
     "Ym7z9kI2QKjD5CnTiU4ugngak8K0/OajPSmFkt9XvPA6SvjF7mgQNsmCM1Se4ZpGjBoDMFpcaUJ"
     "WqxmttmaaKjpYa6boafKngCFHzBKeKa3HlE2BBhgDUeBi7/7RqNTaZjjEal3wSMDUG3ajzgFhzQ"
     "nVfjHKeVEC0kJa/isFgrO23bA0J494QIrCAjatiuB9ANBuc7Pv91ETxucnDKow6np5bPZcGbC5B"
     "9TOAeZG7duTQxAkh7s81ylUUAawyhb0yqZh2nqwzGRbx3MnwI3t3qxcpRNME9wiBJ5MIicbKlDS"
     "QcY3lw247fCylx0ZYw/TrZaBIvYGgMoysKUrenwGmFM5cIORdCGAbCItU40KYaNWbNxgRQB6WHV"
     "uhjksMRrgrt0LheOUVr4NSy3ervdwU6RbdwM1uIaZJc4kHVvleOBaxigo9iZdKQug9SlKszWAlS"
     "c00UoS3UNr58L2UdHC679zIUwB0X9IezLL6xZX35whb48kUvvzxM8pQweK7Gn9a6Wi/WW8a0Uy+"
     "0k5B6m9FRSciGuiuvH6Puvi5ef//y2nn559HXj5zL6v5WvN8fW4vOTScOYltNgLosh9l3CrkoG/"
     "0aCvxqf1etOc7vTfN8+7nW2zfAMPvW3DDQivstSsb3llL2T75th5xoFUR9S0mm58YANz8SMx07I"
     "/yph78qCeKzG38fP5Zvl5B/vpPNYWSBfxbdRqm5vrn9zZzn5q+V7PZXv9Wg+nRCcNgM4cbZO8K4"
     "TNX8fb1rf15Wz7ljuX7Hzf1xu37+rzKu7lrPuWG5Z/647t5eZ8+n+ZqXw1SX03DY+uf8FvMdMEg"
     "=="
     );
}

static void mdlSetWorkWidths_c2_tomas(SimStruct *S)
{
  sf_set_work_widths(S, sf_c2_tomas_get_post_codegen_info());
  ssSetChecksum0(S,(3835787693U));
  ssSetChecksum1(S,(4017829832U));
  ssSetChecksum2(S,(2115829994U));
  ssSetChecksum3(S,(3642196499U));
}

static void mdlRTW_c2_tomas(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_tomas(SimStruct *S)
{
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)utMalloc(sizeof
    (SFc2_tomasInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_tomasInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_tomas;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_tomas;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_tomas;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_tomas;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_tomas;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_tomas;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_tomas;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_tomas;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_tomas;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_tomas;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_tomas;
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
  mdl_start_c2_tomas(chartInstance);
}

void c2_tomas_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_tomas(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_tomas(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_tomas(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_tomas_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
