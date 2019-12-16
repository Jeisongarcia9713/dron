/* Include files */

#include "tomas_sfun.h"
#include "c5_tomas.h"
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
static const char * c5_debug_family_names[8] = { "im", "BW", "nargin", "nargout",
  "R", "G", "B", "y" };

/* Function Declarations */
static void initialize_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void initialize_params_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void enable_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void disable_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_tomas(SFc5_tomasInstanceStruct
  *chartInstance);
static void ext_mode_exec_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_tomas(SFc5_tomasInstanceStruct
  *chartInstance);
static void set_sim_state_c5_tomas(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_st);
static void finalize_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void sf_gateway_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void mdl_start_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void c5_chartstep_c5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void initSimStructsc5_tomas(SFc5_tomasInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint8_T c5_b_y[19200]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_b_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_BW, const char_T *c5_identifier, boolean_T c5_b_y[19200]);
static void c5_c_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, boolean_T c5_b_y[19200]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_d_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_cat(SFc5_tomasInstanceStruct *chartInstance, uint8_T
                   c5_varargin_1[19200], uint8_T c5_varargin_2[19200], uint8_T
                   c5_varargin_3[19200], uint8_T c5_b_y[57600]);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_tomas, const char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_tomasInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc5_tomasInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c5_fEmlrtCtx, "Image_Toolbox", 2);
  setLegacyDebuggerFlag(chartInstance->S, true);
  setDebuggerFlag(chartInstance->S, true);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_tomas(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_tomas = 0U;
}

static void initialize_params_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_tomas(SFc5_tomasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void ext_mode_exec_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_tomas(SFc5_tomasInstanceStruct
  *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_hoistedGlobal;
  const mxArray *c5_d_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(2, 1), false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", *chartInstance->c5_y, 11, 0U, 1U, 0U,
    2, 120, 160), false);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_tomas;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c5_b_y, 1, c5_d_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_tomas(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_st)
{
  const mxArray *c5_u;
  boolean_T c5_bv0[19200];
  int32_T c5_i0;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "y",
                        c5_bv0);
  for (c5_i0 = 0; c5_i0 < 19200; c5_i0++) {
    (*chartInstance->c5_y)[c5_i0] = c5_bv0[c5_i0];
  }

  chartInstance->c5_is_active_c5_tomas = c5_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_tomas");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_tomas(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void sf_gateway_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, chartInstance->c5_sfEvent);
  for (c5_i1 = 0; c5_i1 < 19200; c5_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_B)[c5_i1], 2U);
  }

  for (c5_i2 = 0; c5_i2 < 19200; c5_i2++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 2U, (real_T)
                      (*chartInstance->c5_B)[c5_i2]);
  }

  for (c5_i3 = 0; c5_i3 < 19200; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_G)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 19200; c5_i4++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U, (real_T)
                      (*chartInstance->c5_G)[c5_i4]);
  }

  for (c5_i5 = 0; c5_i5 < 19200; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_R)[c5_i5], 0U);
  }

  for (c5_i6 = 0; c5_i6 < 19200; c5_i6++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U, (real_T)
                      (*chartInstance->c5_R)[c5_i6]);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_tomas(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i7 = 0; c5_i7 < 19200; c5_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c5_y)[c5_i7], 3U);
  }

  for (c5_i8 = 0; c5_i8 < 19200; c5_i8++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 3U, (real_T)
                      (*chartInstance->c5_y)[c5_i8]);
  }
}

static void mdl_start_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  static const uint32_T c5_decisionTxtEndIdx = 0U;
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    8U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 109);
}

static void c5_chartstep_c5_tomas(SFc5_tomasInstanceStruct *chartInstance)
{
  int32_T c5_i9;
  int32_T c5_i10;
  uint8_T c5_b_R[19200];
  int32_T c5_i11;
  uint8_T c5_b_G[19200];
  uint32_T c5_debug_family_var_map[8];
  uint8_T c5_b_B[19200];
  uint8_T c5_im[19200];
  boolean_T c5_BW[19200];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  boolean_T c5_b_y[19200];
  int32_T c5_i12;
  int32_T c5_i13;
  uint8_T c5_c_R[19200];
  int32_T c5_i14;
  uint8_T c5_c_G[19200];
  uint8_T c5_c_B[19200];
  int32_T c5_i15;
  int32_T c5_i16;
  uint8_T c5_outputImage[19200];
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  for (c5_i9 = 0; c5_i9 < 19200; c5_i9++) {
    c5_b_R[c5_i9] = (*chartInstance->c5_R)[c5_i9];
  }

  for (c5_i10 = 0; c5_i10 < 19200; c5_i10++) {
    c5_b_G[c5_i10] = (*chartInstance->c5_G)[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 19200; c5_i11++) {
    c5_b_B[c5_i11] = (*chartInstance->c5_B)[c5_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_im, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_BW, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 2U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 3U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_R, 4U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_G, 5U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_B, 6U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  for (c5_i12 = 0; c5_i12 < 19200; c5_i12++) {
    c5_c_R[c5_i12] = c5_b_R[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 19200; c5_i13++) {
    c5_c_G[c5_i13] = c5_b_G[c5_i13];
  }

  for (c5_i14 = 0; c5_i14 < 19200; c5_i14++) {
    c5_c_B[c5_i14] = c5_b_B[c5_i14];
  }

  c5_cat(chartInstance, c5_c_R, c5_c_G, c5_c_B, chartInstance->c5_X);
  for (c5_i15 = 0; c5_i15 < 19200; c5_i15++) {
    c5_outputImage[c5_i15] = c5_im[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 19200; c5_i16++) {
    c5_im[c5_i16] = c5_outputImage[c5_i16];
  }

  rgb2gray_tbb_uint8(chartInstance->c5_X, 19200.0, c5_im, true);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  for (c5_i17 = 0; c5_i17 < 19200; c5_i17++) {
    c5_outputImage[c5_i17] = c5_im[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 19200; c5_i18++) {
    c5_BW[c5_i18] = ((real_T)c5_outputImage[c5_i18] > 127.5);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  for (c5_i19 = 0; c5_i19 < 19200; c5_i19++) {
    c5_b_y[c5_i19] = c5_BW[c5_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i20 = 0; c5_i20 < 19200; c5_i20++) {
    (*chartInstance->c5_y)[c5_i20] = c5_b_y[c5_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_tomas(SFc5_tomasInstanceStruct *chartInstance)
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
  int32_T c5_i21;
  int32_T c5_i22;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i23;
  uint8_T c5_u[19200];
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_i21 = 0;
  for (c5_i22 = 0; c5_i22 < 160; c5_i22++) {
    for (c5_i23 = 0; c5_i23 < 120; c5_i23++) {
      c5_u[c5_i23 + c5_i21] = (*(uint8_T (*)[19200])c5_inData)[c5_i23 + c5_i21];
    }

    c5_i21 += 120;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 3, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint8_T c5_b_y[19200])
{
  uint8_T c5_uv0[19200];
  int32_T c5_i24;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv0, 1, 3, 0U, 1, 0U, 2, 120,
                160);
  for (c5_i24 = 0; c5_i24 < 19200; c5_i24++) {
    c5_b_y[c5_i24] = c5_uv0[c5_i24];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_im;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_b_y[19200];
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_im = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_im), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_im);
  c5_i25 = 0;
  for (c5_i26 = 0; c5_i26 < 160; c5_i26++) {
    for (c5_i27 = 0; c5_i27 < 120; c5_i27++) {
      (*(uint8_T (*)[19200])c5_outData)[c5_i27 + c5_i25] = c5_b_y[c5_i27 +
        c5_i25];
    }

    c5_i25 += 120;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int32_T c5_i28;
  int32_T c5_i29;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i30;
  boolean_T c5_u[19200];
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_i28 = 0;
  for (c5_i29 = 0; c5_i29 < 160; c5_i29++) {
    for (c5_i30 = 0; c5_i30 < 120; c5_i30++) {
      c5_u[c5_i30 + c5_i28] = (*(boolean_T (*)[19200])c5_inData)[c5_i30 + c5_i28];
    }

    c5_i28 += 120;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_b_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_BW, const char_T *c5_identifier, boolean_T c5_b_y[19200])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_BW), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_BW);
}

static void c5_c_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance, const
  mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, boolean_T c5_b_y[19200])
{
  boolean_T c5_bv1[19200];
  int32_T c5_i31;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_bv1, 1, 11, 0U, 1, 0U, 2, 120,
                160);
  for (c5_i31 = 0; c5_i31 < 19200; c5_i31++) {
    c5_b_y[c5_i31] = c5_bv1[c5_i31];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_BW;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_b_y[19200];
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_BW = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_BW), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_BW);
  c5_i32 = 0;
  for (c5_i33 = 0; c5_i33 < 160; c5_i33++) {
    for (c5_i34 = 0; c5_i34 < 120; c5_i34++) {
      (*(boolean_T (*)[19200])c5_outData)[c5_i34 + c5_i32] = c5_b_y[c5_i34 +
        c5_i32];
    }

    c5_i32 += 120;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_d_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_b_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargin;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_nargin = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargin),
    &c5_thisId);
  sf_mex_destroy(&c5_nargin);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_tomas_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static void c5_cat(SFc5_tomasInstanceStruct *chartInstance, uint8_T
                   c5_varargin_1[19200], uint8_T c5_varargin_2[19200], uint8_T
                   c5_varargin_3[19200], uint8_T c5_b_y[57600])
{
  int32_T c5_iy;
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_c_j;
  int32_T c5_d_j;
  (void)chartInstance;
  c5_iy = -1;
  for (c5_j = 0; c5_j < 19200; c5_j++) {
    c5_c_j = c5_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_1[c5_c_j];
  }

  for (c5_b_j = 0; c5_b_j < 19200; c5_b_j++) {
    c5_c_j = c5_b_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_2[c5_c_j];
  }

  for (c5_d_j = 0; c5_d_j < 19200; c5_d_j++) {
    c5_c_j = c5_d_j;
    c5_iy++;
    c5_b_y[c5_iy] = c5_varargin_3[c5_c_j];
  }
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int32_T c5_u;
  const mxArray *c5_b_y = NULL;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_b_y;
  int32_T c5_i35;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i35, 1, 6, 0U, 0, 0U, 0);
  c5_b_y = c5_i35;
  sf_mex_destroy(&c5_u);
  return c5_b_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_b_y;
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_tomas, const char_T *c5_identifier)
{
  uint8_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_tomas), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_tomas);
  return c5_b_y;
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_tomasInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_b_y;
}

static void init_dsm_address_info(SFc5_tomasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_tomasInstanceStruct *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_R = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_y = (boolean_T (*)[19200])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_G = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_B = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

/* SFunction Glue Code */
void sf_c5_tomas_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2830789180U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2292686148U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1758819991U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2784792439U);
}

mxArray *sf_c5_tomas_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  return(mxcell3p);
}

mxArray *sf_c5_tomas_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2gray_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_tomas_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_tomas(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiD+wMjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig4g/QZI+lkI6BcAsiqh4QILH/LtV3CgTD/Efg"
    "8C7hdCcT+En1kcn5hcklmWGp9sGl+Sn5tYjDAPBABA2hbN"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_tomas_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_tomasInstanceStruct *chartInstance = (SFc5_tomasInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _tomasMachineNumber_,
           5,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,1,1,0,"G");
          _SFD_SET_DATA_PROPS(2,1,1,0,"B");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y");
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
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
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
    SFc5_tomasInstanceStruct *chartInstance = (SFc5_tomasInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_R);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_y);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_G);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_B);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s1vR1eO6TkdL5dCwXRIBPoC";
}

static void sf_opaque_initialize_c5_tomas(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_tomasInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
  initialize_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_tomas(void *chartInstanceVar)
{
  enable_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_tomas(void *chartInstanceVar)
{
  disable_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_tomas(void *chartInstanceVar)
{
  sf_gateway_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_tomas(SimStruct* S)
{
  return get_sim_state_c5_tomas((SFc5_tomasInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_tomas(SimStruct* S, const mxArray *st)
{
  set_sim_state_c5_tomas((SFc5_tomasInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c5_tomas(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_tomasInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_tomas_optimization_info();
    }

    finalize_c5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_tomas((SFc5_tomasInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_tomas(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_tomas((SFc5_tomasInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc5_tomas((SFc5_tomasInstanceStruct*)sf_get_chart_instance_ptr
      (S));
  }
}

const char* sf_c5_tomas_get_post_codegen_info(void)
{
  return
    (
     "eNrtVU1u00AUttOAqFSqqEJiw6JiA8sWqYgdJU4iIqUkNGnprpraL/Eo4xkzP0krcQVu0AXH4Ah"
     "cgwULdj0Cb5xfnDhpG7USEiM543G+973fec9xqwcOrk18fuDPQ9wf4ZNzBuvB8OxOPYPveefF8H"
     "yEIG6iBpEkUs7CxUkEh6AEM5oKXuVtMRdGeRskcB+xsZA6i03RyDDKuxXDfcunPoXUD5uhMCwoo"
     "iwJ6pxdIFtsdAN5SlSCrysAgQ6lMJ2wwkhnbLHUfS8Ev6tMtMgFBbppYmuWOjBM05hB+Rz8Klea"
     "oMVqYltTEw2ePs9003qqmiOgiGJGCZ/rbUhUE2IMsIajOMDfutHoVBrmh0TqIoSkB6pGuwmn4JD"
     "mpAr/OKOcaCEpYeWIeVZw1rYGQ3sORABsQUDQtqIE0o0F5To7/80Kelrm5IxBCc5MJ5utCZ+NTf"
     "4xhT7IzLi1PdEDSTpQ55lKk4CUz5NsjatkFqZpBMdEvvMxfwqCzOrFylFNgnmCFkpkwSBxsqpak"
     "vYwvJlsJqraylx2ZUw0SLZaBkvYyj1YlIUxW8XnHmFMZcJaIq5BD1jCWiKaLIYNWOfjYili0sGq"
     "DTDItsQ9wQM6kwvfKC0iD8utVKt9wE4x37gJrMo1yDbxYd69VX4IgWGAjmJn0om6OaQBVTZbS1D"
     "DnC5DOapteKkvZBcdXXDtJy7YHCzqD7Yv7ziTvrxxjb48kkvvL6d43Dk8ztSe1rue+xu/ltKbwy"
     "+u6yZy+1Nyj1N68ik5iytYmS+X7ZOfl99/f93Yef7r1cdl+t0Z/W7ybuW+5W42xzaH52ejhjEup"
     "95MFi32/ZRd+Tn8T6f4C8Oz2u0d7kL9dasb1PYCr39yWC02hJfwXbmL7c2l7B1937ad6yJO+pCS"
     "fjUYDlh7JmYwdiz/myl7Hy6Jx/rw+2BdvV1N/sl+Oo/5JfIFfLtI1e3t9W/vryZ/vXxvpfK9lcy"
     "nU4LTpgen/t4p3nWiZu/jbev7pnLOPcv9K3b+j8vd+3edebV2Szl3xfl4X3Kr+nfTub3KnE/3Ny"
     "eFL6yg567x0/sfU6FLSQ=="
     );
}

static void mdlSetWorkWidths_c5_tomas(SimStruct *S)
{
  sf_set_work_widths(S, sf_c5_tomas_get_post_codegen_info());
  ssSetChecksum0(S,(1721531456U));
  ssSetChecksum1(S,(3097289048U));
  ssSetChecksum2(S,(806129129U));
  ssSetChecksum3(S,(1362289954U));
}

static void mdlRTW_c5_tomas(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_tomas(SimStruct *S)
{
  SFc5_tomasInstanceStruct *chartInstance;
  chartInstance = (SFc5_tomasInstanceStruct *)utMalloc(sizeof
    (SFc5_tomasInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_tomasInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_tomas;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_tomas;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_tomas;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_tomas;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_tomas;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_tomas;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_tomas;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_tomas;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_tomas;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_tomas;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_tomas;
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
  mdl_start_c5_tomas(chartInstance);
}

void c5_tomas_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_tomas(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_tomas(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_tomas(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_tomas_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
