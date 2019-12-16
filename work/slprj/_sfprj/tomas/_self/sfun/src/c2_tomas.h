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
  CovrtStateflowInstance *c2_covrtInstance;
  void *c2_fEmlrtCtx;
  boolean_T (*c2_u)[19200];
  boolean_T (*c2_y)[19200];
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
