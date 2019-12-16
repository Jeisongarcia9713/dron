/*
 * flightControlSystem.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.799
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu Nov 14 09:44:38 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef flightControlSystem_COMMON_INCLUDES_
# define flightControlSystem_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rsedu_image.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S4>/estimator//Optical flow error' */
typedef struct {
  int8_T estimatorOpticalflowerror_SubsysRanBC;
                                      /* '<S4>/estimator//Optical flow error' */
} DW_estimatorOpticalflowerror_flightControlSystem_T;

/* Block states (default storage) for system '<S4>/Ultrasound improper' */
typedef struct {
  int8_T Ultrasoundimproper_SubsysRanBC;/* '<S4>/Ultrasound improper' */
} DW_Ultrasoundimproper_flightControlSystem_T;

/* Block signals for system '<Root>/Control System' */
typedef struct {
  real32_T VectorConcatenate[9];       /* '<S108>/Vector Concatenate' */
  real32_T MathFunction[9];            /* '<S98>/Math Function' */
  real32_T rtb_VectorConcatenate_mbvzarwird[9];
  real_T Sum[3];                       /* '<S35>/Sum' */
  real_T rtb_FIR_IMUaccel_cl54gopm0x[3];
  real_T Product2[2];                  /* '<S91>/Product2' */
  real_T Product3[2];                  /* '<S90>/Product3' */
  real32_T sincos_o2_kq55ojr1f2[3];    /* '<S105>/sincos' */
  real32_T sincos_o2[3];               /* '<S46>/sincos' */
  real32_T FIR_IMUaccel[3];            /* '<S37>/FIR_IMUaccel' */
  real_T yaw;                          /* '<S5>/Chart' */
  real_T denAccum;
  real_T u_ch4zj0naok;                 /* '<S4>/   ' */
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real32_T SimplyIntegrateVelocity[2]; /* '<S98>/SimplyIntegrateVelocity' */
  real32_T Akxhatkk1_f5py5lpkz4[2];    /* '<S140>/A[k]*xhat[k|k-1]' */
  real32_T TSamp[2];                   /* '<S111>/TSamp' */
  real32_T pitchrollerror_lnhy3xcnpt[2];/* '<S7>/Sum19' */
  real32_T fv0[2];
  real32_T fv1[2];
  real32_T altitude;
  real32_T Sum2;                       /* '<S37>/Sum2' */
  real32_T DataTypeConversion;         /* '<S35>/Data Type Conversion' */
  real32_T inverseIMU_gain[6];         /* '<S37>/inverseIMU_gain' */
  real32_T Merge[2];                   /* '<S34>/Merge' */
  real32_T DataTypeConversion3[3];     /* '<S34>/Data Type Conversion3' */
  real32_T Reshapexhat[2];             /* '<S103>/Reshapexhat' */
  real32_T DataTypeConversion2;        /* '<S35>/Data Type Conversion2' */
  real32_T DataTypeConversion1[3];     /* '<S34>/Data Type Conversion1' */
  real32_T TmpSignalConversionAtToWorkspaceInport1[12];/* '<S1>/State Estimator' */
  real32_T Product2_i5itdihbiv[2];     /* '<S166>/Product2' */
  real32_T Product3_gd3igxsc2c[2];     /* '<S165>/Product3' */
  real32_T x;                          /* '<S5>/Chart' */
  real32_T y;                          /* '<S5>/Chart' */
  real32_T z;                          /* '<S5>/Chart' */
  real32_T numAccum;
  real32_T denAccum_kkiq3xxxve;
  real32_T denAccum_cxarnvbvui;
  int32_T j;
  int32_T denIdx;
  int32_T cff;
} B_ControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Control System' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S35>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S44>/MemoryX' */
  real_T soonarFilter_IIR_states[3];   /* '<S45>/soonarFilter_IIR' */
  real_T DelayOneStep_DSTATE;          /* '<S4>/Delay One Step' */
  real_T vel;                          /* '<S5>/Chart' */
  real_T grados;                       /* '<S5>/Chart' */
  real_T actual;                       /* '<S5>/Chart' */
  real_T cen;                          /* '<S5>/Chart' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S98>/SimplyIntegrateVelocity' */
  real32_T pressureFilter_IIR_states[3];/* '<S45>/pressureFilter_IIR' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S37>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S37>/FIR_IMUaccel' */
  real32_T MemoryX_DSTATE_hqltbc4n3u[2];/* '<S103>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S102>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S111>/UD' */
  real32_T Delay1_DSTATE[2];           /* '<S6>/Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S7>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_kgeqdjad0f;/* '<S11>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_ijwdhdrv0s[2]; /* '<S7>/Delay' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S37>/FIR_IMUaccel' */
  uint32_T Output_DSTATE;              /* '<S101>/Output' */
  uint32_T Output_DSTATE_kdeodyri3i;   /* '<S14>/Output' */
  uint32_T Output_DSTATE_aloeis45eb;   /* '<S25>/Output' */
  real32_T Memory_PreviousInput[3];    /* '<S34>/Memory' */
  real32_T IIRgyroz_tmp[2];            /* '<S102>/IIRgyroz' */
  int32_T sfEvent;                     /* '<S5>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S5>/Chart' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S98>/SimplyIntegrateVelocity' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S11>/Discrete-Time Integrator' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S145>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S140>/MeasurementUpdate' */
  int8_T EnabledSubsystem_SubsysRanBC_bgcmjfg1p0;/* '<S70>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC_cfrhkmpxp0;/* '<S65>/MeasurementUpdate' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S34>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S34>/If Action Subsystem' */
  int8_T Geofencingerror_SubsysRanBC;  /* '<S4>/Geofencing error' */
  uint8_T icLoad;                      /* '<S44>/MemoryX' */
  uint8_T icLoad_gsr0jp51l1;           /* '<S103>/MemoryX' */
  uint8_T is_active_c3_flightControlSystem;/* '<S5>/Chart' */
  uint8_T is_c3_flightControlSystem;   /* '<S5>/Chart' */
  boolean_T EnabledSubsystem_MODE;     /* '<S145>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S140>/MeasurementUpdate' */
  boolean_T EnabledSubsystem_MODE_n0gllf0cgu;/* '<S70>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE_gfpthrsdrn;/* '<S65>/MeasurementUpdate' */
  DW_Ultrasoundimproper_flightControlSystem_T Normalcondition;/* '<S4>/Normal condition' */
  DW_Ultrasoundimproper_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  DW_estimatorOpticalflowerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  DW_estimatorOpticalflowerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
} DW_ControlSystem_flightControlSystem_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T imageBuff_1[19200];
  uint8_T imageBuff_2[19200];
  uint8_T imageBuff_3[19200];
  boolean_T AND[19200];                /* '<S2>/AND' */
  boolean_T rtb_AND_mbvzarwird[768];
  real_T dv0[32];
  real_T dv1[32];
  real_T dv2[32];
  real_T dv3[32];
  real_T dv4[32];
  real_T dv5[32];
  real_T dv6[32];
  real_T dv7[32];
  real_T dv8[32];
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T estado;                     /* '<S2>/Deteccion de lineas verticales' */
  real_T caso;                       /* '<S2>/Deteccion de lineas verticales' */
  real_T alerta;
  real_T tc_idx_4;
  real_T tc_idx_7;
  boolean_T RateTransition;            /* '<Root>/Rate Transition' */
  boolean_T Compare;                   /* '<S174>/Compare' */
  B_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  parrot_ImageProcess_flightControlSystem_T obj;/* '<S2>/PARROT Image Conversion' */
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  volatile real_T RateTransition1_Buffer[2];/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile boolean_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  boolean_T objisempty;                /* '<S2>/PARROT Image Conversion' */
  DW_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} DW_flightControlSystem_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 0 g]
   * Referenced by: '<S35>/gravity'
   */
  real_T gravity_Value[3];

  /* Computed Parameter: TorqueTotalThrustToThrustPerMotor_Value
   * Referenced by: '<S8>/TorqueTotalThrustToThrustPerMotor'
   */
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroNum)
   * Referenced by:
   *   '<S37>/IIR_IMUgyro_r'
   *   '<S102>/IIRgyroz'
   */
  real32_T pooled9[6];

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroDen)
   * Referenced by:
   *   '<S37>/IIR_IMUgyro_r'
   *   '<S102>/IIRgyroz'
   */
  real32_T pooled10[6];

  /* Computed Parameter: FIR_IMUaccel_Coefficients
   * Referenced by: '<S37>/FIR_IMUaccel'
   */
  real32_T FIR_IMUaccel_Coefficients[6];

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S12>/MotorDirections'
   */
  real32_T MotorDirections_Gain[4];
} ConstP_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

/* Constant parameters (default storage) */
extern const ConstP_flightControlSystem_T flightControlSystem_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S12>/MotorDirections' */
extern uint8_T flag_outport;           /* '<S4>/Merge' */

/* Model entry point functions */
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step(int_T tid);
extern void flightControlSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_flightControlSystem_T *const flightControlSystem_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S14>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S31>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S48>/ConstantP' : Unused code path elimination
 * Block '<S48>/CovarianceZ' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Conversion' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Conversion' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Constant' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Conversion' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/G' : Unused code path elimination
 * Block '<S44>/H' : Unused code path elimination
 * Block '<S44>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S44>/N' : Unused code path elimination
 * Block '<S44>/P0' : Unused code path elimination
 * Block '<S44>/Q' : Unused code path elimination
 * Block '<S44>/R' : Unused code path elimination
 * Block '<S66>/Constant' : Unused code path elimination
 * Block '<S44>/Reshapeyhat' : Unused code path elimination
 * Block '<S75>/CheckSignalProperties' : Unused code path elimination
 * Block '<S82>/CheckSignalProperties' : Unused code path elimination
 * Block '<S84>/CheckSignalProperties' : Unused code path elimination
 * Block '<S85>/CheckSignalProperties' : Unused code path elimination
 * Block '<S101>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S109>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S111>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/ConstantP' : Unused code path elimination
 * Block '<S123>/CovarianceZ' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S163>/Conversion' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Conversion' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Constant' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Conversion' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S135>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/DataTypeConversionReset' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/G' : Unused code path elimination
 * Block '<S103>/H' : Unused code path elimination
 * Block '<S103>/ManualSwitchPZ' : Unused code path elimination
 * Block '<S103>/N' : Unused code path elimination
 * Block '<S103>/P0' : Unused code path elimination
 * Block '<S103>/Q' : Unused code path elimination
 * Block '<S103>/R' : Unused code path elimination
 * Block '<S141>/Constant' : Unused code path elimination
 * Block '<S103>/Reset' : Unused code path elimination
 * Block '<S103>/Reshapeyhat' : Unused code path elimination
 * Block '<S150>/CheckSignalProperties' : Unused code path elimination
 * Block '<S159>/CheckSignalProperties' : Unused code path elimination
 * Block '<S160>/CheckSignalProperties' : Unused code path elimination
 * Block '<S4>/Gain' : Eliminated nontunable gain of 1
 * Block '<S4>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S34>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S43>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S86>/Conversion' : Eliminate redundant data type conversion
 * Block '<S87>/Conversion' : Eliminate redundant data type conversion
 * Block '<S44>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S44>/DataTypeConversionReset' : Eliminate redundant data type conversion
 * Block '<S61>/Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Reshape' : Reshape block reduction
 * Block '<S44>/ReshapeX0' : Reshape block reduction
 * Block '<S44>/Reshapeu' : Reshape block reduction
 * Block '<S44>/Reshapexhat' : Reshape block reduction
 * Block '<S44>/Reshapey' : Reshape block reduction
 * Block '<S96>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S108>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S103>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S136>/Conversion' : Eliminate redundant data type conversion
 * Block '<S140>/Reshape' : Reshape block reduction
 * Block '<S103>/ReshapeX0' : Reshape block reduction
 * Block '<S103>/Reshapeu' : Reshape block reduction
 * Block '<S103>/Reshapey' : Reshape block reduction
 * Block '<S168>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S37>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Control System'
 * '<S2>'   : 'flightControlSystem/Image Processing System'
 * '<S3>'   : 'flightControlSystem/Control System/Controller'
 * '<S4>'   : 'flightControlSystem/Control System/Crash Predictor Flags'
 * '<S5>'   : 'flightControlSystem/Control System/Path Planning'
 * '<S6>'   : 'flightControlSystem/Control System/State Estimator'
 * '<S7>'   : 'flightControlSystem/Control System/Controller/Attitude'
 * '<S8>'   : 'flightControlSystem/Control System/Controller/ControlMixer'
 * '<S9>'   : 'flightControlSystem/Control System/Controller/XY-to-reference-orientation'
 * '<S10>'  : 'flightControlSystem/Control System/Controller/Yaw'
 * '<S11>'  : 'flightControlSystem/Control System/Controller/gravity feedforward//equilibrium thrust'
 * '<S12>'  : 'flightControlSystem/Control System/Controller/thrustsToMotorCommands'
 * '<S13>'  : 'flightControlSystem/Control System/Controller/gravity feedforward//equilibrium thrust/Compare To Constant'
 * '<S14>'  : 'flightControlSystem/Control System/Controller/gravity feedforward//equilibrium thrust/Counter Free-Running'
 * '<S15>'  : 'flightControlSystem/Control System/Controller/gravity feedforward//equilibrium thrust/Counter Free-Running/Increment Real World'
 * '<S16>'  : 'flightControlSystem/Control System/Controller/gravity feedforward//equilibrium thrust/Counter Free-Running/Wrap To Zero'
 * '<S17>'  : 'flightControlSystem/Control System/Crash Predictor Flags/50 continuous  OF errors '
 * '<S18>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Check error condition'
 * '<S19>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant'
 * '<S20>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant1'
 * '<S21>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant2'
 * '<S22>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant3'
 * '<S23>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant4'
 * '<S24>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Compare To Constant5'
 * '<S25>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running'
 * '<S26>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Geofencing error'
 * '<S27>'  : 'flightControlSystem/Control System/Crash Predictor Flags/No optical flow '
 * '<S28>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Normal condition'
 * '<S29>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Ultrasound improper'
 * '<S30>'  : 'flightControlSystem/Control System/Crash Predictor Flags/estimator//Optical flow error'
 * '<S31>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running/Increment Real World'
 * '<S32>'  : 'flightControlSystem/Control System/Crash Predictor Flags/Counter Free-Running/Wrap To Zero'
 * '<S33>'  : 'flightControlSystem/Control System/Path Planning/Chart'
 * '<S34>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter'
 * '<S35>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude'
 * '<S36>'  : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition'
 * '<S37>'  : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing'
 * '<S38>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/Compare To Constant'
 * '<S39>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/Compare To Constant1'
 * '<S40>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/If Action Subsystem'
 * '<S41>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/If Action Subsystem2'
 * '<S42>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/Wbe'
 * '<S43>'  : 'flightControlSystem/Control System/State Estimator/Complementary Filter/Wbe/Create 3x3 Matrix'
 * '<S44>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude'
 * '<S45>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/OutlierHandling'
 * '<S46>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix'
 * '<S47>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/outlierBelowFloor'
 * '<S48>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL'
 * '<S49>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat'
 * '<S50>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionA'
 * '<S51>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionB'
 * '<S52>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionC'
 * '<S53>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionD'
 * '<S54>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionG'
 * '<S55>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionH'
 * '<S56>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionN'
 * '<S57>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP'
 * '<S58>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP0'
 * '<S59>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionQ'
 * '<S60>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionR'
 * '<S61>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX'
 * '<S62>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX0'
 * '<S63>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionu'
 * '<S64>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/MemoryP'
 * '<S65>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer'
 * '<S66>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN'
 * '<S67>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionP0'
 * '<S68>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionQ'
 * '<S69>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionR'
 * '<S70>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator'
 * '<S71>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkA'
 * '<S72>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkB'
 * '<S73>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkC'
 * '<S74>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkD'
 * '<S75>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkEnable'
 * '<S76>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkG'
 * '<S77>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkH'
 * '<S78>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkN'
 * '<S79>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkP0'
 * '<S80>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkQ'
 * '<S81>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkR'
 * '<S82>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkReset'
 * '<S83>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkX0'
 * '<S84>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checku'
 * '<S85>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checky'
 * '<S86>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
 * '<S87>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
 * '<S88>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
 * '<S89>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
 * '<S90>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer/MeasurementUpdate'
 * '<S91>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
 * '<S92>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/OutlierHandling/check for min altitude'
 * '<S93>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/OutlierHandling/currentEstimateVeryOffFromPressure'
 * '<S94>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/OutlierHandling/currentStateVeryOffsonarflt'
 * '<S95>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/OutlierHandling/outlierJump'
 * '<S96>'  : 'flightControlSystem/Control System/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S97>'  : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity'
 * '<S98>'  : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorXYPosition'
 * '<S99>'  : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling'
 * '<S100>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/Compare To Constant'
 * '<S101>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/Counter Free-Running'
 * '<S102>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling'
 * '<S103>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy'
 * '<S104>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
 * '<S105>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S106>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
 * '<S107>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
 * '<S108>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S109>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/Counter Free-Running/Increment Real World'
 * '<S110>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/Counter Free-Running/Wrap To Zero'
 * '<S111>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/DiscreteDerivative'
 * '<S112>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw1'
 * '<S113>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw2'
 * '<S114>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp'
 * '<S115>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp2'
 * '<S116>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq'
 * '<S117>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq2'
 * '<S118>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw1'
 * '<S119>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw2'
 * '<S120>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw3'
 * '<S121>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw4'
 * '<S122>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/minHeightforOF'
 * '<S123>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL'
 * '<S124>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat'
 * '<S125>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionA'
 * '<S126>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionB'
 * '<S127>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionC'
 * '<S128>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionD'
 * '<S129>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionG'
 * '<S130>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionH'
 * '<S131>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionN'
 * '<S132>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP'
 * '<S133>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
 * '<S134>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
 * '<S135>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionR'
 * '<S136>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX'
 * '<S137>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
 * '<S138>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionu'
 * '<S139>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/MemoryP'
 * '<S140>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer'
 * '<S141>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN'
 * '<S142>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
 * '<S143>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
 * '<S144>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionR'
 * '<S145>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
 * '<S146>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkA'
 * '<S147>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkB'
 * '<S148>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkC'
 * '<S149>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkD'
 * '<S150>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkEnable'
 * '<S151>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkG'
 * '<S152>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkH'
 * '<S153>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkN'
 * '<S154>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkP0'
 * '<S155>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkQ'
 * '<S156>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkR'
 * '<S157>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkReset'
 * '<S158>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkX0'
 * '<S159>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checku'
 * '<S160>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checky'
 * '<S161>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
 * '<S162>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
 * '<S163>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
 * '<S164>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
 * '<S165>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
 * '<S166>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
 * '<S167>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S168>' : 'flightControlSystem/Control System/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S169>' : 'flightControlSystem/Control System/State Estimator/SensorPreprocessing/sensordata_group'
 * '<S170>' : 'flightControlSystem/Image Processing System/Deteccion de lineas verticales'
 * '<S171>' : 'flightControlSystem/Image Processing System/Threshold  for each pixel1'
 * '<S172>' : 'flightControlSystem/Image Processing System/Threshold  for each pixel2'
 * '<S173>' : 'flightControlSystem/Image Processing System/Threshold  for each pixel3'
 * '<S174>' : 'flightControlSystem/Image Processing System/Threshold for  total white pixels'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */
