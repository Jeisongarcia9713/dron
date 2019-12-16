#ifndef __c5_flightControlSystem_h__
#define __c5_flightControlSystem_h__

/* Type Definitions */
#ifndef typedef_SFc5_flightControlSystemInstanceStruct
#define typedef_SFc5_flightControlSystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_flightControlSystem;
  void *c5_RuntimeVar;
  uint32_T c5_mlFcnLineNumber;
  real_T c5_idxStrongR_data[19200];
  real_T c5_idxStrongC_data[19200];
  real_T c5_r_data[19200];
  real_T c5_c_data[19200];
  real_T c5_badPix_data[19200];
  real_T c5_b_r_data[19200];
  real_T c5_b_c_data[19200];
  real_T c5_varargin_2_data[19200];
  real_T c5_b_varargin_2_data[19200];
  real_T c5_locationsVar_data[19200];
  real_T c5_locations_data[19200];
  real_T c5_b_locations_data[19200];
  real_T c5_x_data[19200];
  real32_T c5_a[19200];
  real32_T c5_b_a[19200];
  real32_T c5_dx[19200];
  real32_T c5_b_dx[19200];
  real32_T c5_dy[19200];
  real32_T c5_b_dy[19200];
  real32_T c5_c_dx[19200];
  real32_T c5_c_dy[19200];
  real32_T c5_varargin_1[19200];
  int32_T c5_tmp_data[19200];
  int32_T c5_i_data[19200];
  int32_T c5_j_data[19200];
  int32_T c5_b_tmp_data[19200];
  int32_T c5_ii_data[19200];
  int32_T c5_b_data[19200];
  int32_T c5_b_badPix_data[19200];
  int32_T c5_c_badPix_data[19200];
  int32_T c5_c_tmp_data[19200];
  boolean_T c5_u[19200];
  boolean_T c5_m[19200];
  boolean_T c5_y[19200];
  boolean_T c5_b_u[19200];
  boolean_T c5_bv1[19200];
  boolean_T c5_b_m[19200];
  boolean_T c5_bv2[19200];
  real_T c5_b_x_data[19200];
  int32_T c5_idx_data[19200];
  int32_T c5_b_idx_data[19200];
  CovrtStateflowInstance *c5_covrtInstance;
  void *c5_fEmlrtCtx;
  boolean_T (*c5_c_u)[19200];
  boolean_T (*c5_b_y)[19200];
} SFc5_flightControlSystemInstanceStruct;

#endif                                 /*typedef_SFc5_flightControlSystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_flightControlSystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_flightControlSystem_get_check_sum(mxArray *plhs[]);
extern void c5_flightControlSystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
