/*
 * flightControlSystem.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.873
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Fri Nov 15 15:12:51 2019
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rsedu_image.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

#include "flightControlSystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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

/* Block signals for system '<Root>/Control System' */
typedef struct {
  real32_T TmpSignalConversionAtToWorkspaceInport1[12];/* '<S1>/State Estimator' */
  real32_T VectorConcatenate[9];       /* '<S108>/Vector Concatenate' */
  real32_T MathFunction[9];            /* '<S98>/Math Function' */
  real32_T rtb_VectorConcatenate_mbvzarwird[9];
  real_T Product1[3];                  /* '<S99>/Product1' */
  real_T rtb_VectorConcatenate_cl54gopm0x[3];
  real_T rtb_FIR_IMUaccel_kkiq3xxxve[3];
  real_T Product2[2];                  /* '<S91>/Product2' */
  real_T Product3[2];                  /* '<S90>/Product3' */
  real32_T sincos_o2_f2vyjtakzt[3];    /* '<S105>/sincos' */
  real32_T FIR_IMUaccel[3];            /* '<S37>/FIR_IMUaccel' */
  real32_T Sum_amwaersy43[3];          /* '<S34>/Sum' */
  real_T yaw;                          /* '<S5>/Chart' */
  real32_T inverseIMU_gain[6];         /* '<S37>/inverseIMU_gain' */
  real_T denAccum;
  real_T invertzaxisGain;              /* '<S35>/invertzaxisGain' */
  real_T u_msmdqfiwbm;                 /* '<S4>/   ' */
  real_T rtb_Product1_tmp;
  real_T rtb_Product1_tmp_cxarnvbvui;
  real_T rtb_Product1_tmp_bhxxfovxdy;
  real32_T Merge[2];                   /* '<S34>/Merge' */
  real32_T MotorDirections[4];         /* '<S12>/MotorDirections' */
  real32_T Product2_af04vv1zot[2];     /* '<S166>/Product2' */
  real32_T Product3_drwpv1e3vz[2];     /* '<S165>/Product3' */
  real32_T Akxhatkk1_ld4ugmonpm[2];    /* '<S140>/A[k]*xhat[k|k-1]' */
  real32_T TSamp[2];                   /* '<S111>/TSamp' */
  real32_T pitchrollerror_hujfwd2vao[2];/* '<S7>/Sum19' */
  real32_T fv0[2];
  real32_T fv1[2];
  real32_T x;                          /* '<S5>/Chart' */
  real32_T y;                          /* '<S5>/Chart' */
  real32_T z;                          /* '<S5>/Chart' */
  real32_T numAccum;
  real32_T denAccum_pbm3vprmfu;
  real32_T denAccum_cv5hdgrwft;
  int32_T j;
  int32_T denIdx;
  int32_T cff;
  int32_T memOffset;
  uint32_T FixPtSum1_ackzpfy53r;       /* '<S31>/FixPt Sum1' */
  uint8_T Merge_dtz3huqpir;            /* '<S4>/Merge' */
} B_ControlSystem_flightControlSystem_T;

/* Block states (default storage) for system '<Root>/Control System' */
typedef struct {
  real_T Delay2_DSTATE;                /* '<S35>/Delay2' */
  real_T MemoryX_DSTATE[2];            /* '<S44>/MemoryX' */
  real_T soonarFilter_IIR_states[3];   /* '<S45>/soonarFilter_IIR' */
  real_T DelayOneStep_DSTATE;          /* '<S4>/Delay One Step' */
  real_T vel;                          /* '<S5>/Chart' */
  real_T grados;                       /* '<S5>/Chart' */
  real_T cen;                          /* '<S5>/Chart' */
  real_T actual;                       /* '<S5>/Chart' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S98>/SimplyIntegrateVelocity' */
  real32_T pressureFilter_IIR_states[3];/* '<S45>/pressureFilter_IIR' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S37>/IIR_IMUgyro_r' */
  real32_T FIR_IMUaccel_states[15];    /* '<S37>/FIR_IMUaccel' */
  real32_T MemoryX_DSTATE_f3yjwtkool[2];/* '<S103>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S102>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S111>/UD' */
  real32_T Delay_DSTATE[2];            /* '<S97>/Delay' */
  real32_T Delay1_DSTATE[2];           /* '<S6>/Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S7>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_mnqnev55nj;/* '<S11>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE_fbcbshewsf[2]; /* '<S7>/Delay' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S37>/FIR_IMUaccel' */
  uint32_T Output_DSTATE;              /* '<S101>/Output' */
  uint32_T Output_DSTATE_hymmp1tw2p;   /* '<S14>/Output' */
  uint32_T Output_DSTATE_nghfazzn45;   /* '<S25>/Output' */
  real32_T Memory_PreviousInput[3];    /* '<S34>/Memory' */
  real32_T IIRgyroz_tmp[2];            /* '<S102>/IIRgyroz' */
  uint16_T temporalCounter_i1;         /* '<S5>/Chart' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S98>/SimplyIntegrateVelocity' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S11>/Discrete-Time Integrator' */
  uint8_T icLoad;                      /* '<S44>/MemoryX' */
  uint8_T icLoad_nkomoir31r;           /* '<S103>/MemoryX' */
  uint8_T is_active_c3_flightControlSystem;/* '<S5>/Chart' */
  uint8_T is_c3_flightControlSystem;   /* '<S5>/Chart' */
  boolean_T EnabledSubsystem_MODE;     /* '<S145>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S140>/MeasurementUpdate' */
  boolean_T EnabledSubsystem_MODE_gvqneg3ntz;/* '<S70>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE_dbwln3vz1a;/* '<S65>/MeasurementUpdate' */
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
  real_T alerta;
  real_T tc_idx_4;
  real_T tc_idx_8;
  real_T tc_idx_12;
  real_T tc_idx_5;
  real_T tc_idx_9;
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  B_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} B_flightControlSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  parrot_ImageProcess_flightControlSystem_T obj;/* '<S2>/PARROT Image Conversion' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S2>/Delay2' */
  volatile real_T RateTransition1_Buffer[2];/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile boolean_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  boolean_T objisempty;                /* '<S2>/PARROT Image Conversion' */
  DW_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
} DW_flightControlSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_flightControlSystem_T;

/* Parameters for system: '<S4>/Geofencing error' */
struct P_Geofencingerror_flightControlSystem_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S26>/Constant'
                                        */
};

/* Parameters for system: '<Root>/Control System' */
struct P_ControlSystem_flightControlSystem_T_ {
  real_T outlierBelowFloor_const;     /* Mask Parameter: outlierBelowFloor_const
                                       * Referenced by: '<S47>/Constant'
                                       */
  real_T outlierJump_const;            /* Mask Parameter: outlierJump_const
                                        * Referenced by: '<S95>/Constant'
                                        */
  real_T currentEstimateVeryOffFromPressure_const;
                     /* Mask Parameter: currentEstimateVeryOffFromPressure_const
                      * Referenced by: '<S93>/Constant'
                      */
  real_T currentStateVeryOffsonarflt_const;
                            /* Mask Parameter: currentStateVeryOffsonarflt_const
                             * Referenced by: '<S94>/Constant'
                             */
  real_T Checkerrorcondition_const; /* Mask Parameter: Checkerrorcondition_const
                                     * Referenced by: '<S18>/Constant'
                                     */
  real_T u0continuousOFerrors_const;
                                   /* Mask Parameter: u0continuousOFerrors_const
                                    * Referenced by: '<S17>/Constant'
                                    */
  real32_T DiscreteDerivative_ICPrevScaledInput;
                         /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
                          * Referenced by: '<S111>/UD'
                          */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S38>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S39>/Constant'
                                      */
  real32_T maxp_const;                 /* Mask Parameter: maxp_const
                                        * Referenced by: '<S114>/Constant'
                                        */
  real32_T maxq_const;                 /* Mask Parameter: maxq_const
                                        * Referenced by: '<S116>/Constant'
                                        */
  real32_T maxw1_const;                /* Mask Parameter: maxw1_const
                                        * Referenced by: '<S118>/Constant'
                                        */
  real32_T maxw2_const;                /* Mask Parameter: maxw2_const
                                        * Referenced by: '<S119>/Constant'
                                        */
  real32_T maxdw1_const;               /* Mask Parameter: maxdw1_const
                                        * Referenced by: '<S112>/Constant'
                                        */
  real32_T maxdw2_const;               /* Mask Parameter: maxdw2_const
                                        * Referenced by: '<S113>/Constant'
                                        */
  real32_T maxp2_const;                /* Mask Parameter: maxp2_const
                                        * Referenced by: '<S115>/Constant'
                                        */
  real32_T maxq2_const;                /* Mask Parameter: maxq2_const
                                        * Referenced by: '<S117>/Constant'
                                        */
  real32_T maxw3_const;                /* Mask Parameter: maxw3_const
                                        * Referenced by: '<S120>/Constant'
                                        */
  real32_T maxw4_const;                /* Mask Parameter: maxw4_const
                                        * Referenced by: '<S121>/Constant'
                                        */
  real32_T minHeightforOF_const;       /* Mask Parameter: minHeightforOF_const
                                        * Referenced by: '<S122>/Constant'
                                        */
  real32_T DeactivateAccelerationIfOFisnotusedduetolowaltitude_const;
    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S104>/Constant'
     */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
   * Referenced by: '<S106>/Constant'
   */
  real32_T donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co;
  /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
   * Referenced by: '<S107>/Constant'
   */
  real32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S21>/Constant'
                                      */
  real32_T CompareToConstant4_const; /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S23>/Constant'
                                      */
  real32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S22>/Constant'
                                      */
  real32_T CompareToConstant5_const; /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S24>/Constant'
                                      */
  real32_T CompareToConstant_const_j2aeaztlxq;
                           /* Mask Parameter: CompareToConstant_const_j2aeaztlxq
                            * Referenced by: '<S19>/Constant'
                            */
  real32_T CompareToConstant1_const_oea4nh0fds;
                          /* Mask Parameter: CompareToConstant1_const_oea4nh0fds
                           * Referenced by: '<S20>/Constant'
                           */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S16>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_laizy3sja4;
                              /* Mask Parameter: WrapToZero_Threshold_laizy3sja4
                               * Referenced by: '<S32>/FixPt Switch'
                               */
  uint32_T WrapToZero_Threshold_m14ba5jvav;
                              /* Mask Parameter: WrapToZero_Threshold_m14ba5jvav
                               * Referenced by: '<S110>/FixPt Switch'
                               */
  uint32_T CompareToConstant_const_oadmvaq2bv;
                           /* Mask Parameter: CompareToConstant_const_oadmvaq2bv
                            * Referenced by: '<S100>/Constant'
                            */
  uint32_T CompareToConstant_const_o2ywjbil1g;
                           /* Mask Parameter: CompareToConstant_const_o2ywjbil1g
                            * Referenced by: '<S13>/Constant'
                            */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S4>/ '
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S90>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S91>/deltax'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S35>/Delay2'
                                        */
  real_T X0_Value[2];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S44>/X0'
                                        */
  real_T SaturationSonar_LowerSat;     /* Expression: -inf
                                        * Referenced by: '<S45>/SaturationSonar'
                                        */
  real_T soonarFilter_IIR_NumCoef[4];/* Expression: Estimator.alt.filterSonarNum
                                      * Referenced by: '<S45>/soonarFilter_IIR'
                                      */
  real_T soonarFilter_IIR_DenCoef[4];/* Expression: Estimator.alt.filterSonarDen
                                      * Referenced by: '<S45>/soonarFilter_IIR'
                                      */
  real_T soonarFilter_IIR_InitialStates;/* Expression: 0
                                         * Referenced by: '<S45>/soonarFilter_IIR'
                                         */
  real_T KalmanGainM_Value[2];         /* Expression: pInitialization.M
                                        * Referenced by: '<S48>/KalmanGainM'
                                        */
  real_T C_Value[2];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S44>/C'
                                        */
  real_T KalmanGainM_Value_jjsg0b0z0q[4];/* Expression: pInitialization.M
                                          * Referenced by: '<S123>/KalmanGainM'
                                          */
  real_T A_Value[4];                   /* Expression: pInitialization.A
                                        * Referenced by: '<S44>/A'
                                        */
  real_T KalmanGainL_Value[4];         /* Expression: pInitialization.L
                                        * Referenced by: '<S123>/KalmanGainL'
                                        */
  real_T gravity_Value[3];             /* Expression: [0 0 g]
                                        * Referenced by: '<S35>/gravity'
                                        */
  real_T gravity_Value_dibfthgkk3[3];  /* Expression: [0 0 -g]
                                        * Referenced by: '<S99>/gravity'
                                        */
  real_T gainaccinput_Gain;   /* Expression: Estimator.pos.accelerationInputGain
                               * Referenced by: '<S99>/gainaccinput'
                               */
  real_T B_Value[2];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S44>/B'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S44>/D'
                                        */
  real_T KalmanGainL_Value_cqw4rtoxbn[2];/* Expression: pInitialization.L
                                          * Referenced by: '<S48>/KalmanGainL'
                                          */
  real_T Wait3Seconds_Value;           /* Expression: 200*3
                                        * Referenced by: '<S4>/Wait  3 Seconds'
                                        */
  real_T DelayOneStep_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S4>/Delay One Step'
                                        */
  real_T u5meters_Value;               /* Expression: 0.5
                                        * Referenced by: '<S4>/0.5 meters'
                                        */
  real32_T D_xy_Gain[2];               /* Computed Parameter: D_xy_Gain
                                        * Referenced by: '<S9>/D_xy'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S9>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S9>/Saturation'
                                       */
  real32_T P_xy_Gain[2];               /* Computed Parameter: P_xy_Gain
                                        * Referenced by: '<S9>/P_xy'
                                        */
  real32_T D_z1_Gain;                  /* Computed Parameter: D_z1_Gain
                                        * Referenced by: '<S11>/D_z1'
                                        */
  real32_T P_z1_Gain;                  /* Computed Parameter: P_z1_Gain
                                        * Referenced by: '<S11>/P_z1'
                                        */
  real32_T takeoff_gain1_Gain;         /* Expression: Controller.takeoffGain
                                        * Referenced by: '<S11>/takeoff_gain1'
                                        */
  real32_T _Value_ouzfzmlb2y;          /* Computed Parameter: _Value_ouzfzmlb2y
                                        * Referenced by: '<S4>/    '
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S40>/Gain1'
                                        */
  real32_T Gain_Gain_dvwjhkjmhw;     /* Computed Parameter: Gain_Gain_dvwjhkjmhw
                                      * Referenced by: '<S40>/Gain'
                                      */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S40>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S40>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S40>/Gain4'
                                        */
  real32_T Gain_Gain_b0xcv5ppve;     /* Computed Parameter: Gain_Gain_b0xcv5ppve
                                      * Referenced by: '<S97>/Gain'
                                      */
  real32_T opticalFlowErrorCorrect_Gain;
                             /* Computed Parameter: opticalFlowErrorCorrect_Gain
                              * Referenced by: '<S97>/opticalFlowErrorCorrect'
                              */
  real32_T Lykyhatkk1_Y0_ly1kk4lmmc;
                                 /* Computed Parameter: Lykyhatkk1_Y0_ly1kk4lmmc
                                  * Referenced by: '<S165>/L*(y[k]-yhat[k|k-1])'
                                  */
  real32_T deltax_Y0_hbk4yyz1lk;     /* Computed Parameter: deltax_Y0_hbk4yyz1lk
                                      * Referenced by: '<S166>/deltax'
                                      */
  real32_T TorqueTotalThrustToThrustPerMotor_Value[16];/* Expression: Controller.Q2Ts
                                                        * Referenced by: '<S8>/TorqueTotalThrustToThrustPerMotor'
                                                        */
  real32_T SimplyIntegrateVelocity_gainval;
                          /* Computed Parameter: SimplyIntegrateVelocity_gainval
                           * Referenced by: '<S98>/SimplyIntegrateVelocity'
                           */
  real32_T SimplyIntegrateVelocity_IC;
                               /* Computed Parameter: SimplyIntegrateVelocity_IC
                                * Referenced by: '<S98>/SimplyIntegrateVelocity'
                                */
  real32_T invertzaxisGain_Gain;     /* Computed Parameter: invertzaxisGain_Gain
                                      * Referenced by: '<S35>/invertzaxisGain'
                                      */
  real32_T prsToAltGain_Gain;          /* Computed Parameter: prsToAltGain_Gain
                                        * Referenced by: '<S35>/prsToAltGain'
                                        */
  real32_T pressureFilter_IIR_NumCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_NumCoef
                                * Referenced by: '<S45>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_DenCoef[4];
                               /* Computed Parameter: pressureFilter_IIR_DenCoef
                                * Referenced by: '<S45>/pressureFilter_IIR'
                                */
  real32_T pressureFilter_IIR_InitialStates;
                         /* Computed Parameter: pressureFilter_IIR_InitialStates
                          * Referenced by: '<S45>/pressureFilter_IIR'
                          */
  real32_T Assumingthatcalibwasdonelevel_Bias[6];
                       /* Computed Parameter: Assumingthatcalibwasdonelevel_Bias
                        * Referenced by: '<S37>/Assuming that calib was done level!'
                        */
  real32_T inverseIMU_gain_Gain[6];  /* Computed Parameter: inverseIMU_gain_Gain
                                      * Referenced by: '<S37>/inverseIMU_gain'
                                      */
  real32_T IIR_IMUgyro_r_NumCoef[6];/* Computed Parameter: IIR_IMUgyro_r_NumCoef
                                     * Referenced by: '<S37>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_DenCoef[6];/* Computed Parameter: IIR_IMUgyro_r_DenCoef
                                     * Referenced by: '<S37>/IIR_IMUgyro_r'
                                     */
  real32_T IIR_IMUgyro_r_InitialStates;
                              /* Computed Parameter: IIR_IMUgyro_r_InitialStates
                               * Referenced by: '<S37>/IIR_IMUgyro_r'
                               */
  real32_T Memory_InitialCondition[3];
                        /* Expression: single(Estimator.complementaryFilterInit)
                         * Referenced by: '<S34>/Memory'
                         */
  real32_T Constant_Value;             /* Expression: single(0)
                                        * Referenced by: '<S42>/Constant'
                                        */
  real32_T Gain_Gain_nwkt5b5fro;     /* Computed Parameter: Gain_Gain_nwkt5b5fro
                                      * Referenced by: '<S42>/Gain'
                                      */
  real32_T Gain_Gain_juztar0qtz;     /* Computed Parameter: Gain_Gain_juztar0qtz
                                      * Referenced by: '<S34>/Gain'
                                      */
  real32_T FIR_IMUaccel_InitialStates;
                               /* Computed Parameter: FIR_IMUaccel_InitialStates
                                * Referenced by: '<S37>/FIR_IMUaccel'
                                */
  real32_T FIR_IMUaccel_Coefficients[6];
                                /* Computed Parameter: FIR_IMUaccel_Coefficients
                                 * Referenced by: '<S37>/FIR_IMUaccel'
                                 */
  real32_T Constant_Value_percv3dd1f;
                                /* Computed Parameter: Constant_Value_percv3dd1f
                                 * Referenced by: '<S34>/Constant'
                                 */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S34>/Merge'
                                       */
  real32_T X0_Value_lfdbgvehcb[2];    /* Computed Parameter: X0_Value_lfdbgvehcb
                                       * Referenced by: '<S103>/X0'
                                       */
  real32_T C_Value_p3s05liash[4];      /* Computed Parameter: C_Value_p3s05liash
                                        * Referenced by: '<S103>/C'
                                        */
  real32_T IIRgyroz_NumCoef[6];        /* Computed Parameter: IIRgyroz_NumCoef
                                        * Referenced by: '<S102>/IIRgyroz'
                                        */
  real32_T IIRgyroz_DenCoef[6];        /* Computed Parameter: IIRgyroz_DenCoef
                                        * Referenced by: '<S102>/IIRgyroz'
                                        */
  real32_T IIRgyroz_InitialStates; /* Computed Parameter: IIRgyroz_InitialStates
                                    * Referenced by: '<S102>/IIRgyroz'
                                    */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S111>/TSamp'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S97>/Delay'
                                    */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S6>/Delay1'
                                   */
  real32_T D_pr_Gain[2];               /* Computed Parameter: D_pr_Gain
                                        * Referenced by: '<S7>/D_pr'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S7>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S7>/Discrete-Time Integrator'
                           */
  real32_T I_pr_Gain;                  /* Computed Parameter: I_pr_Gain
                                        * Referenced by: '<S7>/I_pr'
                                        */
  real32_T P_pr_Gain[2];               /* Computed Parameter: P_pr_Gain
                                        * Referenced by: '<S7>/P_pr'
                                        */
  real32_T w1_Value;                   /* Computed Parameter: w1_Value
                                        * Referenced by: '<S11>/w1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval_b1wrfjbuk2;
                /* Computed Parameter: DiscreteTimeIntegrator_gainval_b1wrfjbuk2
                 * Referenced by: '<S11>/Discrete-Time Integrator'
                 */
  real32_T DiscreteTimeIntegrator_IC_iymdtlt5j0;
                     /* Computed Parameter: DiscreteTimeIntegrator_IC_iymdtlt5j0
                      * Referenced by: '<S11>/Discrete-Time Integrator'
                      */
  real32_T DiscreteTimeIntegrator_UpperSat_plvc2rxdg0;
               /* Computed Parameter: DiscreteTimeIntegrator_UpperSat_plvc2rxdg0
                * Referenced by: '<S11>/Discrete-Time Integrator'
                */
  real32_T DiscreteTimeIntegrator_LowerSat_cbbd1x44vs;
               /* Computed Parameter: DiscreteTimeIntegrator_LowerSat_cbbd1x44vs
                * Referenced by: '<S11>/Discrete-Time Integrator'
                */
  real32_T SaturationThrust1_UpperSat;
                               /* Computed Parameter: SaturationThrust1_UpperSat
                                * Referenced by: '<S11>/SaturationThrust1'
                                */
  real32_T SaturationThrust1_LowerSat;
                               /* Computed Parameter: SaturationThrust1_LowerSat
                                * Referenced by: '<S11>/SaturationThrust1'
                                */
  real32_T P_yaw_Gain;                 /* Computed Parameter: P_yaw_Gain
                                        * Referenced by: '<S10>/P_yaw'
                                        */
  real32_T D_yaw_Gain;                 /* Computed Parameter: D_yaw_Gain
                                        * Referenced by: '<S10>/D_yaw'
                                        */
  real32_T ThrustToMotorCommand_Gain;
                                /* Computed Parameter: ThrustToMotorCommand_Gain
                                 * Referenced by: '<S12>/ThrustToMotorCommand'
                                 */
  real32_T Saturation5_UpperSat;       /* Expression: Vehicle.Motor.maxLimit
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real32_T Saturation5_LowerSat;       /* Expression: Vehicle.Motor.minLimit
                                        * Referenced by: '<S12>/Saturation5'
                                        */
  real32_T MotorDirections_Gain[4];  /* Computed Parameter: MotorDirections_Gain
                                      * Referenced by: '<S12>/MotorDirections'
                                      */
  real32_T A_Value_l0gpbuxkte[4];      /* Computed Parameter: A_Value_l0gpbuxkte
                                        * Referenced by: '<S103>/A'
                                        */
  real32_T B_Value_divnfjb1dq[4];      /* Computed Parameter: B_Value_divnfjb1dq
                                        * Referenced by: '<S103>/B'
                                        */
  real32_T D_Value_j0gctn4yse[4];      /* Computed Parameter: D_Value_j0gctn4yse
                                        * Referenced by: '<S103>/D'
                                        */
  real32_T Delay_InitialCondition_cot5fhlv10;
                        /* Computed Parameter: Delay_InitialCondition_cot5fhlv10
                         * Referenced by: '<S7>/Delay'
                         */
  real32_T antiWU_Gain_Gain;           /* Computed Parameter: antiWU_Gain_Gain
                                        * Referenced by: '<S7>/antiWU_Gain'
                                        */
  real32_T I_pr_Gain_cswgo3ze1g;     /* Computed Parameter: I_pr_Gain_cswgo3ze1g
                                      * Referenced by: '<S11>/I_pr'
                                      */
  real32_T Gain_Gain_nkg3zw25sw;     /* Computed Parameter: Gain_Gain_nkg3zw25sw
                                      * Referenced by: '<S4>/Gain'
                                      */
  real32_T Gain1_Gain_ov00v2ikfj;   /* Computed Parameter: Gain1_Gain_ov00v2ikfj
                                     * Referenced by: '<S4>/Gain1'
                                     */
  uint32_T Constant_Value_eesjyjh2ui;
                                /* Computed Parameter: Constant_Value_eesjyjh2ui
                                 * Referenced by: '<S16>/Constant'
                                 */
  uint32_T Constant_Value_phytu2r2f1;
                                /* Computed Parameter: Constant_Value_phytu2r2f1
                                 * Referenced by: '<S32>/Constant'
                                 */
  uint32_T Constant_Value_o24gdufi11;
                                /* Computed Parameter: Constant_Value_o24gdufi11
                                 * Referenced by: '<S110>/Constant'
                                 */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S35>/Delay2'
                                        */
  uint32_T MemoryX_DelayLength;       /* Computed Parameter: MemoryX_DelayLength
                                       * Referenced by: '<S44>/MemoryX'
                                       */
  uint32_T MemoryX_DelayLength_hf1cizflt4;
                           /* Computed Parameter: MemoryX_DelayLength_hf1cizflt4
                            * Referenced by: '<S103>/MemoryX'
                            */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S101>/Output'
                                   */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S97>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S6>/Delay1'
                                        */
  uint32_T Output_InitialCondition_c5nnqodi1t;
                       /* Computed Parameter: Output_InitialCondition_c5nnqodi1t
                        * Referenced by: '<S14>/Output'
                        */
  uint32_T Delay_DelayLength_nnijsqwcwl;
                             /* Computed Parameter: Delay_DelayLength_nnijsqwcwl
                              * Referenced by: '<S7>/Delay'
                              */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S15>/FixPt Constant'
                                       */
  uint32_T Output_InitialCondition_j3t1gcu1w1;
                       /* Computed Parameter: Output_InitialCondition_j3t1gcu1w1
                        * Referenced by: '<S25>/Output'
                        */
  uint32_T DelayOneStep_DelayLength;
                                 /* Computed Parameter: DelayOneStep_DelayLength
                                  * Referenced by: '<S4>/Delay One Step'
                                  */
  uint32_T FixPtConstant_Value_h5bewbcaxk;
                           /* Computed Parameter: FixPtConstant_Value_h5bewbcaxk
                            * Referenced by: '<S31>/FixPt Constant'
                            */
  uint32_T FixPtConstant_Value_kchif4j3g4;
                           /* Computed Parameter: FixPtConstant_Value_kchif4j3g4
                            * Referenced by: '<S109>/FixPt Constant'
                            */
  boolean_T controlModePosVsOrient_Value;
                             /* Computed Parameter: controlModePosVsOrient_Value
                              * Referenced by: '<S1>/controlModePosVsOrient'
                              */
  uint8_T Merge_InitialOutput_ey5vocp2a3;
                           /* Computed Parameter: Merge_InitialOutput_ey5vocp2a3
                            * Referenced by: '<S4>/Merge'
                            */
  P_Geofencingerror_flightControlSystem_T Normalcondition;/* '<S4>/Normal condition' */
  P_Geofencingerror_flightControlSystem_T Ultrasoundimproper;/* '<S4>/Ultrasound improper' */
  P_Geofencingerror_flightControlSystem_T Noopticalflow;/* '<S4>/No optical flow ' */
  P_Geofencingerror_flightControlSystem_T estimatorOpticalflowerror;
                                      /* '<S4>/estimator//Optical flow error' */
  P_Geofencingerror_flightControlSystem_T Geofencingerror;/* '<S4>/Geofencing error' */
};

/* Parameters (default storage) */
struct P_flightControlSystem_T_ {
  struct_8SSZ93PxvPkADZcA4gG8MD Sensors;/* Variable: Sensors
                                         * Referenced by:
                                         *   '<S45>/SaturationSonar'
                                         *   '<S92>/Constant'
                                         */
  uint16_T Thresholdfortotalwhitepixels_const;
                           /* Mask Parameter: Thresholdfortotalwhitepixels_const
                            * Referenced by: '<S174>/Constant'
                            */
  uint8_T Thresholdforeachpixel1_const;
                                 /* Mask Parameter: Thresholdforeachpixel1_const
                                  * Referenced by: '<S171>/Constant'
                                  */
  uint8_T Thresholdforeachpixel2_const;
                                 /* Mask Parameter: Thresholdforeachpixel2_const
                                  * Referenced by: '<S172>/Constant'
                                  */
  uint8_T Thresholdforeachpixel3_const;
                                 /* Mask Parameter: Thresholdforeachpixel3_const
                                  * Referenced by: '<S173>/Constant'
                                  */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay2'
                                        */
  real_T RateTransition1_InitialCondition;/* Expression: 0
                                           * Referenced by: '<Root>/Rate Transition1'
                                           */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S2>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S2>/Delay1'
                                        */
  uint32_T Delay2_DelayLength;         /* Computed Parameter: Delay2_DelayLength
                                        * Referenced by: '<S2>/Delay2'
                                        */
  boolean_T RateTransition_InitialCondition;
                          /* Computed Parameter: RateTransition_InitialCondition
                           * Referenced by: '<Root>/Rate Transition'
                           */
  P_ControlSystem_flightControlSystem_T ControlSystem;/* '<Root>/Control System' */
};

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

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
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_flightControlSystem_T flightControlSystem_P;

/* Block signals (default storage) */
extern B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
extern DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_flightControlSystem_T flightControlSystem_Y;

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
extern real32_T motors_outport[4];     /* '<Root>/Control System' */
extern uint8_T flag_outport;           /* '<Root>/Control System' */

/* External function called from main */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void flightControlSystem_initialize(void);
extern void flightControlSystem_step0(void);
extern void flightControlSystem_step1(void);
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
 * Block '<S6>/Display' : Unused code path elimination
 * Block '<S6>/Display1' : Unused code path elimination
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
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S34>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S34>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S34>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * Block '<S103>/Reshapexhat' : Reshape block reduction
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
