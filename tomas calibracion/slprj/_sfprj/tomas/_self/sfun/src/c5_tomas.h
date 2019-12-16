#ifndef __c5_tomas_h__
#define __c5_tomas_h__

/* Type Definitions */
#ifndef struct_tag_sNrqT4fAWIMnTNkfSKQUNxE
#define struct_tag_sNrqT4fAWIMnTNkfSKQUNxE

struct tag_sNrqT4fAWIMnTNkfSKQUNxE
{
  real_T t;
};

#endif                                 /*struct_tag_sNrqT4fAWIMnTNkfSKQUNxE*/

#ifndef typedef_c5_sNrqT4fAWIMnTNkfSKQUNxE
#define typedef_c5_sNrqT4fAWIMnTNkfSKQUNxE

typedef struct tag_sNrqT4fAWIMnTNkfSKQUNxE c5_sNrqT4fAWIMnTNkfSKQUNxE;

#endif                                 /*typedef_c5_sNrqT4fAWIMnTNkfSKQUNxE*/

#ifndef typedef_SFc5_tomasInstanceStruct
#define typedef_SFc5_tomasInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_tomas;
  void *c5_RuntimeVar;
  uint32_T c5_mlFcnLineNumber;
  uint8_T c5_X[57600];
  CovrtStateflowInstance *c5_covrtInstance;
  void *c5_fEmlrtCtx;
  uint8_T (*c5_R)[19200];
  boolean_T (*c5_y)[19200];
  uint8_T (*c5_G)[19200];
  uint8_T (*c5_B)[19200];
} SFc5_tomasInstanceStruct;

#endif                                 /*typedef_SFc5_tomasInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_tomas_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_tomas_get_check_sum(mxArray *plhs[]);
extern void c5_tomas_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
