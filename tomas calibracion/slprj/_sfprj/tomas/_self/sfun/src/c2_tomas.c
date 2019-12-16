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
static const char * c2_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

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
static void initSimStructsc2_tomas(SFc2_tomasInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_y, const char_T *c2_identifier, boolean_T c2_c_y[19200]);
static void c2_c_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_b_y[19200]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_medfilt2(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_varargin_1[19200], boolean_T c2_b[19200]);
static void c2_indexShapeCheck(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_matrixSize, int32_T c2_indexSize[2]);
static void c2_abs(SFc2_tomasInstanceStruct *chartInstance, real_T c2_x_data[],
                   int32_T c2_x_size[1], real_T c2_y_data[], int32_T c2_y_size[1]);
static void c2_padarray(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_varargin_1[19200], real_T c2_varargin_2[2], boolean_T c2_b_data[], int32_T
  c2_b_size[2]);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_tomas, const char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
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
  const mxArray *c2_b_y = NULL;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_createcellmatrix(2, 1), false);
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", *chartInstance->c2_y, 11, 0U, 1U, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c2_b_y, 0, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_tomas;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_b_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_b_y, false);
  return c2_st;
}

static void set_sim_state_c2_tomas(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  boolean_T c2_bv0[19200];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 0)),
                        "y", c2_bv0);
  for (c2_i0 = 0; c2_i0 < 19200; c2_i0++) {
    (*chartInstance->c2_y)[c2_i0] = c2_bv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_tomas = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_b_u, 1)), "is_active_c2_tomas");
  sf_mex_destroy(&c2_b_u);
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
  uint32_T c2_debug_family_var_map[4];
  boolean_T c2_b_u[19200];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_b_y[19200];
  int32_T c2_i4;
  boolean_T c2_c_u[19200];
  boolean_T c2_bv1[19200];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 19200; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_u)[c2_i1], 0U);
  }

  for (c2_i2 = 0; c2_i2 < 19200; c2_i2++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U, (real_T)
                      (*chartInstance->c2_u)[c2_i2]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 19200; c2_i3++) {
    c2_b_u[c2_i3] = (*chartInstance->c2_u)[c2_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_y, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i4 = 0; c2_i4 < 19200; c2_i4++) {
    c2_c_u[c2_i4] = c2_b_u[c2_i4];
  }

  c2_medfilt2(chartInstance, c2_c_u, c2_bv1);
  for (c2_i5 = 0; c2_i5 < 19200; c2_i5++) {
    c2_b_y[c2_i5] = c2_bv1[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i6 = 0; c2_i6 < 19200; c2_i6++) {
    (*chartInstance->c2_y)[c2_i6] = c2_b_y[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i7 = 0; c2_i7 < 19200; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_y)[c2_i7], 1U);
  }

  for (c2_i8 = 0; c2_i8 < 19200; c2_i8++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, (real_T)
                      (*chartInstance->c2_y)[c2_i8]);
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
                     "eML_blk_kernel", 0, -1, 44);
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
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_b_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargin;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_nargin = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargin), &c2_thisId);
  sf_mex_destroy(&c2_nargin);
  *(real_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i9;
  int32_T c2_i10;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i11;
  boolean_T c2_b_u[19200];
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 160; c2_i10++) {
    for (c2_i11 = 0; c2_i11 < 120; c2_i11++) {
      c2_b_u[c2_i11 + c2_i9] = (*(boolean_T (*)[19200])c2_inData)[c2_i11 + c2_i9];
    }

    c2_i9 += 120;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_y, const char_T *c2_identifier, boolean_T c2_c_y[19200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
}

static void c2_c_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance, const
  mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_b_y[19200])
{
  boolean_T c2_bv2[19200];
  int32_T c2_i12;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_bv2, 1, 11, 0U, 1, 0U, 2,
                120, 160);
  for (c2_i12 = 0; c2_i12 < 19200; c2_i12++) {
    c2_b_y[c2_i12] = c2_bv2[c2_i12];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_c_y[19200];
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_b_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_y), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_b_y);
  c2_i13 = 0;
  for (c2_i14 = 0; c2_i14 < 160; c2_i14++) {
    for (c2_i15 = 0; c2_i15 < 120; c2_i15++) {
      (*(boolean_T (*)[19200])c2_outData)[c2_i15 + c2_i13] = c2_c_y[c2_i15 +
        c2_i13];
    }

    c2_i13 += 120;
  }

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
  c2_varargin_1[19200], boolean_T c2_b[19200])
{
  int32_T c2_idx;
  int32_T c2_tmp_size[1];
  int32_T c2_i16;
  int32_T c2_indices_size[1];
  int32_T c2_tmp_data[25];
  int32_T c2_i17;
  int32_T c2_j_size[1];
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b0;
  int32_T c2_indices_data[25];
  int32_T c2_j_data[25];
  int32_T c2_i18;
  int32_T c2_b_tmp_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i19;
  int32_T c2_iv0[2];
  int32_T c2_b_tmp_data[25];
  boolean_T c2_b1;
  int32_T c2_i20;
  int32_T c2_b_loop_ub;
  int32_T c2_i21;
  int32_T c2_iv1[2];
  boolean_T c2_b2;
  int32_T c2_i22;
  int32_T c2_c_loop_ub;
  int32_T c2_i23;
  int32_T c2_iv2[2];
  int32_T c2_rows_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i24;
  int32_T c2_cols_size[1];
  real_T c2_rows_data[25];
  int32_T c2_e_loop_ub;
  int32_T c2_i25;
  real_T c2_cols_data[25];
  int32_T c2_f_loop_ub;
  int32_T c2_i26;
  int32_T c2_g_loop_ub;
  int32_T c2_i27;
  int32_T c2_b_rows_size[1];
  int32_T c2_h_loop_ub;
  int32_T c2_i28;
  real_T c2_b_rows_data[25];
  real_T c2_varargin_1_data[25];
  int32_T c2_varargin_1_size[1];
  boolean_T c2_b3;
  const mxArray *c2_b_y = NULL;
  static char_T c2_cv0[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  static char_T c2_cv1[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_n;
  const mxArray *c2_e_y = NULL;
  int32_T c2_last;
  real_T c2_ex;
  real_T c2_maxval;
  int32_T c2_k;
  int32_T c2_b_cols_size[1];
  int32_T c2_i_loop_ub;
  int32_T c2_i29;
  real_T c2_b_cols_data[25];
  boolean_T c2_b4;
  const mxArray *c2_f_y = NULL;
  static char_T c2_cv2[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  static char_T c2_cv3[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_b_n;
  const mxArray *c2_i_y = NULL;
  int32_T c2_b_last;
  real_T c2_b_ex;
  real_T c2_b_maxval;
  int32_T c2_b_k;
  real_T c2_b_varargin_1;
  real_T c2_varargin_2;
  real_T c2_x;
  real_T c2_c_varargin_1;
  real_T c2_b_x;
  real_T c2_j_y;
  real_T c2_c_x;
  real_T c2_k_y;
  real_T c2_d_x;
  real_T c2_l_y;
  real_T c2_e_x;
  real_T c2_m_y;
  real_T c2_f_x;
  real_T c2_n_y;
  real_T c2_padSize;
  real_T c2_a;
  int32_T c2_i30;
  int32_T c2_i31;
  real_T c2_startIdx[2];
  boolean_T c2_d_varargin_1[19200];
  boolean_T c2_Apad_data[20916];
  int32_T c2_Apad_size[2];
  real_T c2_Ma;
  real_T c2_b_b;
  int32_T c2_j_loop_ub;
  int32_T c2_i32;
  int32_T c2_k_loop_ub;
  int32_T c2_i33;
  real_T c2_d1;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  real_T c2_sizeA[2];
  int32_T c2_i37;
  int32_T c2_i38;
  real_T c2_domainSizeT[2];
  real_T c2_dv0[2];
  boolean_T exitg1;
  c2_idx = 0;
  c2_tmp_size[0] = 25;
  for (c2_i16 = 0; c2_i16 < 25; c2_i16++) {
    c2_tmp_data[c2_i16] = 0;
  }

  c2_indices_size[0] = c2_tmp_size[0];
  c2_tmp_size[0] = 25;
  for (c2_i17 = 0; c2_i17 < 25; c2_i17++) {
    c2_tmp_data[c2_i17] = 0;
  }

  c2_j_size[0] = c2_tmp_size[0];
  c2_ii = 1;
  c2_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_jj <= 5)) {
    c2_idx++;
    c2_indices_data[c2_idx - 1] = c2_ii;
    c2_j_data[c2_idx - 1] = c2_jj;
    if (c2_idx >= 25) {
      exitg1 = true;
    } else {
      c2_ii++;
      if (c2_ii > 5) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b0 = (1 > c2_idx);
  if (c2_b0) {
    c2_i18 = 0;
  } else {
    c2_i18 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i18;
  c2_loop_ub = c2_i18 - 1;
  for (c2_i19 = 0; c2_i19 <= c2_loop_ub; c2_i19++) {
    c2_b_tmp_data[c2_i19] = 1 + c2_i19;
  }

  c2_iv0[0] = 1;
  c2_iv0[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv0);
  c2_indices_size[0] = c2_i18;
  c2_b1 = (1 > c2_idx);
  if (c2_b1) {
    c2_i20 = 0;
  } else {
    c2_i20 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i20;
  c2_b_loop_ub = c2_i20 - 1;
  for (c2_i21 = 0; c2_i21 <= c2_b_loop_ub; c2_i21++) {
    c2_b_tmp_data[c2_i21] = 1 + c2_i21;
  }

  c2_iv1[0] = 1;
  c2_iv1[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv1);
  c2_j_size[0] = c2_i20;
  c2_b2 = (1 > c2_idx);
  if (c2_b2) {
    c2_i22 = 0;
  } else {
    c2_i22 = c2_idx;
  }

  c2_b_tmp_size[0] = c2_i22;
  c2_c_loop_ub = c2_i22 - 1;
  for (c2_i23 = 0; c2_i23 <= c2_c_loop_ub; c2_i23++) {
    c2_b_tmp_data[c2_i23] = 1 + c2_i23;
  }

  c2_iv2[0] = 1;
  c2_iv2[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv2);
  c2_rows_size[0] = c2_indices_size[0];
  c2_d_loop_ub = c2_indices_size[0] - 1;
  for (c2_i24 = 0; c2_i24 <= c2_d_loop_ub; c2_i24++) {
    c2_rows_data[c2_i24] = (real_T)c2_indices_data[c2_i24];
  }

  c2_cols_size[0] = c2_j_size[0];
  c2_e_loop_ub = c2_j_size[0] - 1;
  for (c2_i25 = 0; c2_i25 <= c2_e_loop_ub; c2_i25++) {
    c2_cols_data[c2_i25] = (real_T)c2_j_data[c2_i25];
  }

  c2_rows_size[0];
  c2_f_loop_ub = c2_rows_size[0] - 1;
  for (c2_i26 = 0; c2_i26 <= c2_f_loop_ub; c2_i26++) {
    c2_rows_data[c2_i26] -= 3.0;
  }

  c2_cols_size[0];
  c2_g_loop_ub = c2_cols_size[0] - 1;
  for (c2_i27 = 0; c2_i27 <= c2_g_loop_ub; c2_i27++) {
    c2_cols_data[c2_i27] -= 3.0;
  }

  c2_b_rows_size[0] = c2_rows_size[0];
  c2_h_loop_ub = c2_rows_size[0] - 1;
  for (c2_i28 = 0; c2_i28 <= c2_h_loop_ub; c2_i28++) {
    c2_b_rows_data[c2_i28] = c2_rows_data[c2_i28];
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
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_b_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_c_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
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
  for (c2_i29 = 0; c2_i29 <= c2_i_loop_ub; c2_i29++) {
    c2_b_cols_data[c2_i29] = c2_cols_data[c2_i29];
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
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_g_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_h_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_i_y)));
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

  c2_b_varargin_1 = c2_maxval;
  c2_varargin_2 = c2_b_maxval;
  c2_x = c2_b_varargin_1;
  c2_c_varargin_1 = c2_varargin_2;
  c2_b_x = c2_x;
  c2_j_y = c2_c_varargin_1;
  c2_c_x = c2_b_x;
  c2_k_y = c2_j_y;
  c2_d_x = c2_c_x;
  c2_l_y = c2_k_y;
  c2_e_x = c2_d_x;
  c2_m_y = c2_l_y;
  c2_f_x = c2_e_x;
  c2_n_y = c2_m_y;
  c2_padSize = muDoubleScalarMax(c2_f_x, c2_n_y);
  c2_a = c2_padSize;
  for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
    c2_startIdx[c2_i30] = c2_a;
  }

  for (c2_i31 = 0; c2_i31 < 19200; c2_i31++) {
    c2_d_varargin_1[c2_i31] = c2_varargin_1[c2_i31];
  }

  c2_padarray(chartInstance, c2_d_varargin_1, c2_startIdx, c2_Apad_data,
              c2_Apad_size);
  c2_Ma = (real_T)c2_Apad_size[0];
  c2_b_b = c2_Ma;
  c2_cols_size[0];
  c2_j_loop_ub = c2_cols_size[0] - 1;
  for (c2_i32 = 0; c2_i32 <= c2_j_loop_ub; c2_i32++) {
    c2_cols_data[c2_i32] *= c2_b_b;
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_cols_size[0], c2_rows_size[0]);
  c2_indices_size[0] = c2_cols_size[0];
  c2_k_loop_ub = c2_cols_size[0] - 1;
  for (c2_i33 = 0; c2_i33 <= c2_k_loop_ub; c2_i33++) {
    c2_d1 = muDoubleScalarRound(c2_cols_data[c2_i33] + c2_rows_data[c2_i33]);
    if (c2_d1 < 2.147483648E+9) {
      if (c2_d1 >= -2.147483648E+9) {
        c2_i35 = (int32_T)c2_d1;
      } else {
        c2_i35 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d1 >= 2.147483648E+9) {
      c2_i35 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i35 = 0;
    }

    c2_indices_data[c2_i33] = c2_i35;
  }

  c2_startIdx[0] = c2_padSize;
  c2_startIdx[1] = c2_padSize;
  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    c2_sizeA[c2_i34] = (real_T)c2_Apad_size[c2_i34];
  }

  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_sizeA[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
    c2_domainSizeT[c2_i37] = 5.0;
  }

  for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
    c2_dv0[c2_i38] = 120.0 + 40.0 * (real_T)c2_i38;
  }

  ordfilt2_boolean(&c2_Apad_data[0], c2_sizeA[0], c2_startIdx, &c2_indices_data
                   [0], (real_T)c2_indices_size[0], c2_domainSizeT, 12.0, c2_b,
                   c2_dv0, true);
}

static void c2_indexShapeCheck(SFc2_tomasInstanceStruct *chartInstance, int32_T
  c2_matrixSize, int32_T c2_indexSize[2])
{
  (void)chartInstance;
  (void)c2_matrixSize;
  (void)c2_indexSize;
}

static void c2_abs(SFc2_tomasInstanceStruct *chartInstance, real_T c2_x_data[],
                   int32_T c2_x_size[1], real_T c2_y_data[], int32_T c2_y_size[1])
{
  int32_T c2_nx;
  real_T c2_x[2];
  int32_T c2_i39;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_b_x;
  real_T c2_b_y;
  (void)chartInstance;
  c2_nx = c2_x_size[0] - 1;
  c2_x[0] = (real_T)c2_x_size[0];
  c2_x[1] = 1.0;
  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    c2_x[c2_i39];
  }

  c2_y_size[0] = (int32_T)c2_x[0];
  for (c2_k = 0; c2_k <= c2_nx; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x_data[c2_b_k];
    c2_b_y = muDoubleScalarAbs(c2_b_x);
    c2_y_data[c2_b_k] = c2_b_y;
  }
}

static void c2_padarray(SFc2_tomasInstanceStruct *chartInstance, boolean_T
  c2_varargin_1[19200], real_T c2_varargin_2[2], boolean_T c2_b_data[], int32_T
  c2_b_size[2])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x;
  boolean_T c2_b5;
  real_T c2_b_x;
  real_T c2_c_x;
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b_p;
  static char_T c2_cv4[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
    'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c2_i40;
  const mxArray *c2_c_y = NULL;
  boolean_T c2_c_p;
  static char_T c2_cv5[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'I', 'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c2_i41;
  real_T c2_d_y[2];
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv6[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  real_T c2_d2;
  int32_T c2_i42;
  int32_T c2_j;
  real_T c2_b;
  real_T c2_b_j;
  int32_T c2_c;
  real_T c2_d3;
  int32_T c2_a;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i;
  int32_T c2_i45;
  int32_T c2_c_j;
  real_T c2_b_i;
  int32_T c2_d_j;
  real_T c2_d4;
  int32_T c2_i46;
  int32_T c2_e_j;
  int32_T c2_c_i;
  real_T c2_d5;
  int32_T c2_f_j;
  int32_T c2_i47;
  real_T c2_b_a;
  int32_T c2_d_i;
  int32_T c2_b_c;
  int32_T c2_e_i;
  int32_T c2_c_a;
  int32_T c2_i48;
  int32_T c2_i49;
  real_T c2_d_a;
  real_T c2_e_a;
  int32_T c2_f_i;
  real_T c2_b_b;
  real_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_d_c;
  real_T c2_f_a;
  real_T c2_g_a;
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
    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_b_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_c_y, 14, c2_e_y)));
  }

  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    c2_d_y[c2_i40] = 2.0 * c2_varargin_2[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 2; c2_i41++) {
    c2_d_y[c2_i41] += 120.0 + 40.0 * (real_T)c2_i41;
  }

  c2_b_size[0] = (int32_T)c2_d_y[0];
  c2_b_size[1] = (int32_T)c2_d_y[1];
  c2_d2 = c2_varargin_2[1];
  c2_i42 = (int32_T)c2_d2 - 1;
  for (c2_j = 0; c2_j <= c2_i42; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_d3 = (real_T)c2_b_size[0];
    c2_i43 = (int32_T)c2_d3 - 1;
    for (c2_i = 0; c2_i <= c2_i43; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1,
                  c2_b_size[0]) + c2_b_size[0] * ((int32_T)c2_b_j - 1)) - 1] =
        false;
    }
  }

  c2_b = c2_varargin_2[1];
  c2_c = (int32_T)c2_b;
  c2_a = c2_c + 160;
  c2_i44 = c2_a;
  c2_i45 = c2_b_size[1];
  for (c2_c_j = c2_i44 + 1; c2_c_j <= c2_i45; c2_c_j++) {
    c2_d4 = (real_T)c2_b_size[0];
    c2_i46 = (int32_T)c2_d4 - 1;
    for (c2_c_i = 0; c2_c_i <= c2_i46; c2_c_i++) {
      c2_b_i = 1.0 + (real_T)c2_c_i;
      c2_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1,
                  c2_b_size[0]) + c2_b_size[0] * (sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_c_j, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_d_j = 0; c2_d_j < 160; c2_d_j++) {
    c2_b_j = 1.0 + (real_T)c2_d_j;
    c2_d5 = c2_varargin_2[0];
    c2_i47 = (int32_T)c2_d5 - 1;
    for (c2_d_i = 0; c2_d_i <= c2_i47; c2_d_i++) {
      c2_b_i = 1.0 + (real_T)c2_d_i;
      c2_d_a = c2_b_j;
      c2_b_b = c2_varargin_2[1];
      c2_c_c = (int32_T)c2_d_a + (int32_T)c2_b_b;
      c2_b_data[((int32_T)c2_b_i + c2_b_size[0] * (sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_c_c, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_e_j = 0; c2_e_j < 160; c2_e_j++) {
    c2_b_j = 1.0 + (real_T)c2_e_j;
    c2_b_a = c2_varargin_2[0];
    c2_b_c = (int32_T)c2_b_a;
    c2_c_a = c2_b_c + 120;
    c2_i48 = c2_c_a;
    c2_i49 = c2_b_size[0];
    for (c2_f_i = c2_i48 + 1; c2_f_i <= c2_i49; c2_f_i++) {
      c2_g_a = c2_b_j;
      c2_e_b = c2_varargin_2[1];
      c2_f_c = (int32_T)c2_g_a + (int32_T)c2_e_b;
      c2_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_f_i, 1,
                  c2_b_size[0]) + c2_b_size[0] * (sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_f_c, 1, c2_b_size[1]) - 1)) - 1] = false;
    }
  }

  for (c2_f_j = 0; c2_f_j < 160; c2_f_j++) {
    c2_b_j = 1.0 + (real_T)c2_f_j;
    for (c2_e_i = 0; c2_e_i < 120; c2_e_i++) {
      c2_b_i = 1.0 + (real_T)c2_e_i;
      c2_e_a = c2_b_i;
      c2_c_b = c2_varargin_2[0];
      c2_d_c = (int32_T)c2_e_a + (int32_T)c2_c_b;
      c2_f_a = c2_b_j;
      c2_d_b = c2_varargin_2[1];
      c2_e_c = (int32_T)c2_f_a + (int32_T)c2_d_b;
      c2_b_data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_d_c, 1,
                  c2_b_size[0]) + c2_b_size[0] * (sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_e_c, 1, c2_b_size[1]) - 1)) - 1] =
        c2_varargin_1[((int32_T)c2_b_i + 120 * ((int32_T)c2_b_j - 1)) - 1];
    }
  }
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_b_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_b_y;
  int32_T c2_i50;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i50, 1, 6, 0U, 0, 0U, 0);
  c2_b_y = c2_i50;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_b_y;
  SFc2_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc2_tomasInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_b_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_tomas, const char_T *c2_identifier)
{
  uint8_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_tomas), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_tomas);
  return c2_b_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_tomasInstanceStruct *chartInstance,
  const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_b_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_b_y;
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
  chartInstance->c2_u = (boolean_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_y = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c2_tomas_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2659798781U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2202928000U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2669734578U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3848321992U);
}

mxArray *sf_c2_tomas_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
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
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
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
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sYld6Rt40HEZZI3zZhwVDvE";
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
     "eNrtVc1u00AQdkJAVCpVVIG4cOgBCY4VIMSN0vyollJa1W0RvVRbexKvst41++O0vEKfAcTjcOE"
     "huHPoIzB2nMZybKdt1EpIWNqs1/nmm9+dsWr2toXPCq6f+PMA94e46tb4uZ+ea5k1/t6wXqTnAw"
     "RxE+wSSQJlVT6cBLAHSjCjqeA274tCGOV9kMBdxIZC6jI2RQPDKB92DXdjPvXJp67v+MIwbxNli"
     "bfD2RmyhUbvIk+bSnB1F8DTvhRm4HcZGVxaLPWo5YM7VCaockGBdkwYm6W2DdM0ZNA5BdfmShO0"
     "WE1tczTR0NKnpW7GnipnAhRByCjhhd76RDkQYoA1HIQe/u4YjU7lYa5PpN4En0SgenSYcAoOeU6"
     "q8I8TyokWkhLWCVgrFpy1bZehPdvCA1YRELRtUwIZhoJyXZ5/p4uedjg5YdCGEzMoZ3Pgi4mTf0"
     "hhBLI0bv2WiECSAezwUqVJQDqnSbYuq2QWpmkAh0R+cDF/CrzS6sXKUQ7BPME+SpTBIHHSVvuSR"
     "hjeUjYT2HFlzrsyJhgnW82DJWydCKqycMnWdXmLMKZKYfsi7EEELGFtE02qYWPWYlwoRUgGWLUe"
     "Bjku8ZbgHp3JhWuUFkELy63d633ETlFs3BRmcw2yT1wourfK9cEzDNBR7Ew6UVdA6lEVZ2sOKs3"
     "pPJSl+oa3R0IO0dGKaz91Ic5BVX+I+/K6Ne3Ly1foyxO5/P4yw1Mr4LEye17vUr1abx3faqncRk"
     "buUU5PIycX45q47lmN86Xz5d+/Vp48/+N8+76I/h/1682xlfT8bNIwLsspmslijN3K2NUo4H+a4"
     "W+mZ/WZeW/39Jv1rc7Rkf3665E/OmxHnYTvolZtbz1n7+T7Wty5zsKkDynp2l46YOMzMeOxE/O/"
     "y9j7YE48ltLv4+fi/WLyjzfyeWzMkW/i21mubm+uf21jMfmr5Xs1l+/VZD4dE5w2ERy7r47xrhM"
     "1ex9vWt/XlbPuWO5fsfN/XG7fv6vMq7uWs+5YblH/rju3F5nz+f5m5fDNBfTcNj67/wUe3kmX"
     );
}

static void mdlSetWorkWidths_c2_tomas(SimStruct *S)
{
  sf_set_work_widths(S, sf_c2_tomas_get_post_codegen_info());
  ssSetChecksum0(S,(2332295171U));
  ssSetChecksum1(S,(3775695625U));
  ssSetChecksum2(S,(605359821U));
  ssSetChecksum3(S,(2661110764U));
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
