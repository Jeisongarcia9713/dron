#ifndef __c2_tomas_h__
#define __c2_tomas_h__

/* Type Definitions */
#ifndef typedef_SFc2_tomasInstanceStruct
#define typedef_SFc2_tomasInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_tomas;
  void *c2_RuntimeVar;
  uint32_T c2_mlFcnLineNumber;
  real_T c2_idxStrongR_data[19200];
  real_T c2_idxStrongC_data[19200];
  real_T c2_r_data[19200];
  real_T c2_c_data[19200];
  real_T c2_badPix_data[19200];
  real_T c2_b_r_data[19200];
  real_T c2_b_c_data[19200];
  real_T c2_varargin_2_data[19200];
  real_T c2_b_varargin_2_data[19200];
  real_T c2_locationsVar_data[19200];
  real_T c2_locations_data[19200];
  real_T c2_b_locations_data[19200];
  real_T c2_x_data[19200];
  real32_T c2_a[19200];
  real32_T c2_b_a[19200];
  real32_T c2_dx[19200];
  real32_T c2_b_dx[19200];
  real32_T c2_dy[19200];
  real32_T c2_b_dy[19200];
  real32_T c2_c_dx[19200];
  real32_T c2_c_dy[19200];
  real32_T c2_varargin_1[19200];
  int32_T c2_tmp_data[19200];
  int32_T c2_i_data[19200];
  int32_T c2_j_data[19200];
  int32_T c2_b_tmp_data[19200];
  int32_T c2_ii_data[19200];
  int32_T c2_b_data[19200];
  int32_T c2_b_badPix_data[19200];
  int32_T c2_c_badPix_data[19200];
  int32_T c2_c_tmp_data[19200];
  boolean_T c2_u[19200];
  boolean_T c2_m[19200];
  boolean_T c2_y[19200];
  boolean_T c2_b_u[19200];
  boolean_T c2_bv1[19200];
  boolean_T c2_b_m[19200];
  boolean_T c2_bv2[19200];
  real_T c2_b_x_data[19200];
  int32_T c2_idx_data[19200];
  int32_T c2_b_idx_data[19200];
  CovrtStateflowInstance *c2_covrtInstance;
  void *c2_fEmlrtCtx;
  boolean_T (*c2_c_u)[19200];
  boolean_T (*c2_b_y)[19200];
} SFc2_tomasInstanceStruct;

#endif                                 /*typedef_SFc2_tomasInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_tomas_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_tomas_get_check_sum(mxArray *plhs[]);
extern void c2_tomas_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
