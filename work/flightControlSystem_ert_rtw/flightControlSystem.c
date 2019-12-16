/*
 * flightControlSystem.c
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

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_IN_Adelante ((uint8_T)1U)
#define flightControlSystem_IN_Circulo ((uint8_T)2U)
#define flightControlSystem_IN_Descender1 ((uint8_T)3U)
#define flightControlSystem_IN_Descender2 ((uint8_T)4U)
#define flightControlSystem_IN_Descender3 ((uint8_T)5U)
#define flightControlSystem_IN_EsperaDescenso ((uint8_T)6U)
#define flightControlSystem_IN_GiroDerecha ((uint8_T)7U)
#define flightControlSystem_IN_GiroIzquierda ((uint8_T)8U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_Quieto  ((uint8_T)9U)
#define flightControlSystem_IN_Quieto1 ((uint8_T)10U)
#define flightControlSystem_IN_Subir   ((uint8_T)11U)
#define flightControlSystem_IN_aterrizajeder ((uint8_T)12U)
#define flightControlSystem_IN_aterrizajeiz ((uint8_T)13U)
#define flightControlSystem_IN_centrado ((uint8_T)14U)
#define flightControlSystem_IN_der     ((uint8_T)15U)
#define flightControlSystem_IN_giro    ((uint8_T)16U)
#define flightControlSystem_IN_iz      ((uint8_T)17U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<Root>/Control System' */
uint8_T flag_outport;                  /* '<Root>/Control System' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_B;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_flightControlSystem_T flightControlSystem_Y;

/* Real-time model */
RT_MODEL_flightControlSystem_T flightControlSystem_M_;
RT_MODEL_flightControlSystem_T *const flightControlSystem_M =
  &flightControlSystem_M_;

/* Forward declaration for local functions */
static void flightControlSystem_sum(const boolean_T x[768], real_T y[32]);
static real_T flightControlSystem_sum_gdv4dbd5rd(const real_T x[32]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void flightControlSystem_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(flightControlSystem_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (flightControlSystem_M->Timing.TaskCounters.TID[1])++;
  if ((flightControlSystem_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.2s, 0.0s] */
    flightControlSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/Geofencing error'
 *    '<S4>/estimator//Optical flow error'
 *    '<S4>/No optical flow '
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
void flightControlSystem_Geofencingerror(uint8_T *rty_Out1,
  P_Geofencingerror_flightControlSystem_T *localP)
{
  /* SignalConversion: '<S26>/OutportBufferForOut1' incorporates:
   *  Constant: '<S26>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* SetupRuntimeResources for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_SetupRTR(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 12 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 12 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "flightControlSystem/Control System/To Workspace";
    localDW->ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      flightControlSystem_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(flightControlSystem_M),
      flightControlSystem_M->Timing.stepSize0,
      (&rtmGetErrorStatus(flightControlSystem_M)),
      "estimatedStates",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (localDW->ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }
}

/* System initialize for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Init
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW,
   P_ControlSystem_flightControlSystem_T *localP)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_DSTATE[1] =
    localP->SimplyIntegrateVelocity_IC;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
   *  Delay: '<S35>/Delay2'
   */
  localDW->Delay2_DSTATE = localP->Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S44>/MemoryX' */
  localDW->icLoad = 1U;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[0] = localP->soonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[1] = localP->soonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] =
    localP->pressureFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = localP->soonarFilter_IIR_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = localP->IIR_IMUgyro_r_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[0] = localP->Memory_InitialCondition[0];
  localDW->Memory_PreviousInput[1] = localP->Memory_InitialCondition[1];
  localDW->Memory_PreviousInput[2] = localP->Memory_InitialCondition[2];

  /* InitializeConditions for DiscreteFir: '<S37>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = localP->FIR_IMUaccel_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFir: '<S37>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S103>/MemoryX' */
  localDW->icLoad_nkomoir31r = 1U;

  /* InitializeConditions for UnitDelay: '<S101>/Output' */
  localDW->Output_DSTATE = localP->Output_InitialCondition;

  /* InitializeConditions for DiscreteFilter: '<S102>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = localP->IIRgyroz_InitialStates;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S102>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  localDW->Output_DSTATE_hymmp1tw2p = localP->Output_InitialCondition_c5nnqodi1t;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
    localP->DiscreteTimeIntegrator_IC_iymdtlt5j0;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S25>/Output' */
  localDW->Output_DSTATE_nghfazzn45 = localP->Output_InitialCondition_j3t1gcu1w1;

  /* InitializeConditions for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = localP->DelayOneStep_InitialCondition;

  /* SystemInitialize for Chart: '<S5>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c3_flightControlSystem = 0U;
  localDW->is_c3_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for UnitDelay: '<S111>/UD' */
  localDW->UD_DSTATE[0] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  localDW->Delay_DSTATE[0] = localP->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[0] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_fbcbshewsf[0] =
    localP->Delay_InitialCondition_cot5fhlv10;

  /* SystemInitialize for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S91>/deltax' */
  localB->Product2[0] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S34>/Merge' */
  localB->Merge[0] = localP->Merge_InitialOutput;

  /* SystemInitialize for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S166>/deltax' */
  localB->Product2_af04vv1zot[0] = localP->deltax_Y0_hbk4yyz1lk;

  /* End of SystemInitialize for SubSystem: '<S145>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3_drwpv1e3vz[0] = localP->Lykyhatkk1_Y0_ly1kk4lmmc;

  /* End of SystemInitialize for SubSystem: '<S140>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[0] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S65>/MeasurementUpdate' */

  /* InitializeConditions for UnitDelay: '<S111>/UD' */
  localDW->UD_DSTATE[1] = localP->DiscreteDerivative_ICPrevScaledInput;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  localDW->Delay_DSTATE[1] = localP->Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[1] = localP->DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_fbcbshewsf[1] =
    localP->Delay_InitialCondition_cot5fhlv10;

  /* SystemInitialize for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S91>/deltax' */
  localB->Product2[1] = localP->deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S34>/Merge' */
  localB->Merge[1] = localP->Merge_InitialOutput;

  /* SystemInitialize for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S166>/deltax' */
  localB->Product2_af04vv1zot[1] = localP->deltax_Y0_hbk4yyz1lk;

  /* End of SystemInitialize for SubSystem: '<S145>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3_drwpv1e3vz[1] = localP->Lykyhatkk1_Y0_ly1kk4lmmc;

  /* End of SystemInitialize for SubSystem: '<S140>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[1] = localP->Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S65>/MeasurementUpdate' */

  /* SystemInitialize for Merge: '<S4>/Merge' */
  localB->Merge_dtz3huqpir = localP->Merge_InitialOutput_ey5vocp2a3;
}

/* Start for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Start
  (DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* Start for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE_gvqneg3ntz = false;

  /* End of Start for SubSystem: '<S70>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S145>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S140>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE_dbwln3vz1a = false;

  /* End of Start for SubSystem: '<S65>/MeasurementUpdate' */
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const CommandBus *rtu_ReferenceValueServerCmds, const
  SensorsBus *rtu_Sensors, boolean_T rtu_VisionbasedData, real_T rtu_estado,
  B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW,
  P_ControlSystem_flightControlSystem_T *localP)
{
  boolean_T rtb_nicemeasurementornewupdateneeded;
  boolean_T rtb_Compare_okungkhenj;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_Compare_irglfepkql;
  boolean_T rtb_Compare_lbcpvaevgp;
  real32_T rtb_Gain;
  real32_T rtb_TrigonometricFunction_o2;
  real32_T rtb_TrigonometricFunction_o1;
  real32_T rtb_sincos_o2_idx_0;
  real32_T rtb_sincos_o2_idx_1;
  real32_T rtb_sincos_o2_idx_2;
  real32_T rtb_Switch_idx_0;
  real32_T rtb_Product_m1rp1dgfci_idx_1;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_sincos_o2_f2vyjtakzt_tmp;
  real32_T rtb_sincos_o2_idx_2_tmp;

  /* DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  if (localP->controlModePosVsOrient_Value &&
      (localDW->SimplyIntegrateVelocity_PrevResetState <= 0)) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] =
      localP->SimplyIntegrateVelocity_IC;
    localDW->SimplyIntegrateVelocity_DSTATE[1] =
      localP->SimplyIntegrateVelocity_IC;
  }

  /* Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S44>/X0'
   *  Constant: '<S47>/Constant'
   *  Delay: '<S35>/Delay2'
   *  RelationalOperator: '<S47>/Compare'
   */
  if (localDW->Delay2_DSTATE > localP->outlierBelowFloor_const) {
    localDW->icLoad = 1U;
  }

  if (localDW->icLoad != 0) {
    localDW->MemoryX_DSTATE[0] = localP->X0_Value[0];
    localDW->MemoryX_DSTATE[1] = localP->X0_Value[1];
  }

  /* Gain: '<S35>/invertzaxisGain' incorporates:
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
   */
  localB->invertzaxisGain = (real_T)localP->invertzaxisGain_Gain *
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* DiscreteFilter: '<S45>/pressureFilter_IIR' incorporates:
   *  Gain: '<S35>/prsToAltGain'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector6_at_outport_0'
   *  Sum: '<S37>/Sum2'
   */
  localB->denAccum_pbm3vprmfu =
    ((((rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
        rtu_Sensors->SensorCalibration[6]) * localP->prsToAltGain_Gain -
       localP->pressureFilter_IIR_DenCoef[1] *
       localDW->pressureFilter_IIR_states[0]) -
      localP->pressureFilter_IIR_DenCoef[2] * localDW->
      pressureFilter_IIR_states[1]) - localP->pressureFilter_IIR_DenCoef[3] *
     localDW->pressureFilter_IIR_states[2]) / localP->
    pressureFilter_IIR_DenCoef[0];
  localB->numAccum = ((localP->pressureFilter_IIR_NumCoef[0] *
                       localB->denAccum_pbm3vprmfu +
                       localP->pressureFilter_IIR_NumCoef[1] *
                       localDW->pressureFilter_IIR_states[0]) +
                      localP->pressureFilter_IIR_NumCoef[2] *
                      localDW->pressureFilter_IIR_states[1]) +
    localP->pressureFilter_IIR_NumCoef[3] * localDW->pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localB->denAccum = (((localB->invertzaxisGain -
                        localP->soonarFilter_IIR_DenCoef[1] *
                        localDW->soonarFilter_IIR_states[0]) -
                       localP->soonarFilter_IIR_DenCoef[2] *
                       localDW->soonarFilter_IIR_states[1]) -
                      localP->soonarFilter_IIR_DenCoef[3] *
                      localDW->soonarFilter_IIR_states[2]) /
    localP->soonarFilter_IIR_DenCoef[0];

  /* Saturate: '<S45>/SaturationSonar' */
  if (localB->invertzaxisGain > -flightControlSystem_P.Sensors.altSensorMin) {
    localB->u_msmdqfiwbm = -flightControlSystem_P.Sensors.altSensorMin;
  } else if (localB->invertzaxisGain < localP->SaturationSonar_LowerSat) {
    localB->u_msmdqfiwbm = localP->SaturationSonar_LowerSat;
  } else {
    localB->u_msmdqfiwbm = localB->invertzaxisGain;
  }

  /* End of Saturate: '<S45>/SaturationSonar' */

  /* Logic: '<S45>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S45>/Absestdiff'
   *  Abs: '<S45>/Absestdiff1'
   *  Abs: '<S45>/Absestdiff2'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  Delay: '<S35>/Delay2'
   *  DiscreteFilter: '<S45>/pressureFilter_IIR'
   *  DiscreteFilter: '<S45>/soonarFilter_IIR'
   *  Logic: '<S45>/NOT'
   *  Logic: '<S45>/findingoutliers'
   *  Logic: '<S45>/newupdateneeded'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  RelationalOperator: '<S94>/Compare'
   *  RelationalOperator: '<S95>/Compare'
   *  Sum: '<S45>/Add'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  rtb_nicemeasurementornewupdateneeded = ((fabs(localDW->Delay2_DSTATE -
    localB->u_msmdqfiwbm) <= localP->outlierJump_const) &&
    (localB->invertzaxisGain < -flightControlSystem_P.Sensors.altSensorMin) &&
    ((!(fabs(localB->numAccum - localDW->Delay2_DSTATE) >=
        localP->currentEstimateVeryOffFromPressure_const)) || (!(fabs
    ((((localP->soonarFilter_IIR_NumCoef[0] * localB->denAccum +
        localP->soonarFilter_IIR_NumCoef[1] * localDW->soonarFilter_IIR_states[0])
       + localP->soonarFilter_IIR_NumCoef[2] * localDW->soonarFilter_IIR_states
       [1]) + localP->soonarFilter_IIR_NumCoef[3] *
      localDW->soonarFilter_IIR_states[2]) - localDW->Delay2_DSTATE) >=
    localP->currentStateVeryOffsonarflt_const))));

  /* Outputs for Enabled SubSystem: '<S70>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S91>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->EnabledSubsystem_MODE_gvqneg3ntz) {
      localDW->EnabledSubsystem_MODE_gvqneg3ntz = true;
    }

    /* Sum: '<S91>/Add1' incorporates:
     *  Constant: '<S44>/C'
     *  Delay: '<S44>/MemoryX'
     *  Product: '<S91>/Product'
     */
    localB->u_msmdqfiwbm = localB->invertzaxisGain - (localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]);

    /* Product: '<S91>/Product2' incorporates:
     *  Constant: '<S48>/KalmanGainM'
     */
    localB->Product2[0] = localP->KalmanGainM_Value[0] * localB->u_msmdqfiwbm;
    localB->Product2[1] = localP->KalmanGainM_Value[1] * localB->u_msmdqfiwbm;
  } else {
    if (localDW->EnabledSubsystem_MODE_gvqneg3ntz) {
      /* Disable for Outport: '<S91>/deltax' */
      localB->Product2[0] = localP->deltax_Y0;
      localB->Product2[1] = localP->deltax_Y0;
      localDW->EnabledSubsystem_MODE_gvqneg3ntz = false;
    }
  }

  /* End of Outputs for SubSystem: '<S70>/Enabled Subsystem' */

  /* DataTypeConversion: '<S35>/Data Type Conversion' incorporates:
   *  Delay: '<S44>/MemoryX'
   *  Sum: '<S70>/Add'
   */
  localDW->Delay2_DSTATE = localB->Product2[0] + localDW->MemoryX_DSTATE[0];

  /* Sum: '<S70>/Add' incorporates:
   *  Delay: '<S44>/MemoryX'
   */
  localB->u_msmdqfiwbm = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* Gain: '<S37>/inverseIMU_gain' incorporates:
   *  Bias: '<S37>/Assuming that calib was done level!'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector3_at_outport_0'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector3_at_outport_1'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector3_at_outport_2'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector4_at_outport_0'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector4_at_outport_1'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector4_at_outport_2'
   *  Sum: '<S37>/Sum1'
   */
  localB->inverseIMU_gain[0] = (rtu_Sensors->HALSensors.HAL_acc_SI.x -
    (rtu_Sensors->SensorCalibration[0] +
     localP->Assumingthatcalibwasdonelevel_Bias[0])) *
    localP->inverseIMU_gain_Gain[0];
  localB->inverseIMU_gain[1] = (rtu_Sensors->HALSensors.HAL_acc_SI.y -
    (rtu_Sensors->SensorCalibration[1] +
     localP->Assumingthatcalibwasdonelevel_Bias[1])) *
    localP->inverseIMU_gain_Gain[1];
  localB->inverseIMU_gain[2] = (rtu_Sensors->HALSensors.HAL_acc_SI.z -
    (rtu_Sensors->SensorCalibration[2] +
     localP->Assumingthatcalibwasdonelevel_Bias[2])) *
    localP->inverseIMU_gain_Gain[2];
  localB->inverseIMU_gain[3] = (rtu_Sensors->HALSensors.HAL_gyro_SI.x -
    (rtu_Sensors->SensorCalibration[3] +
     localP->Assumingthatcalibwasdonelevel_Bias[3])) *
    localP->inverseIMU_gain_Gain[3];
  localB->inverseIMU_gain[4] = (rtu_Sensors->HALSensors.HAL_gyro_SI.y -
    (rtu_Sensors->SensorCalibration[4] +
     localP->Assumingthatcalibwasdonelevel_Bias[4])) *
    localP->inverseIMU_gain_Gain[4];
  localB->inverseIMU_gain[5] = (rtu_Sensors->HALSensors.HAL_gyro_SI.z -
    (rtu_Sensors->SensorCalibration[5] +
     localP->Assumingthatcalibwasdonelevel_Bias[5])) *
    localP->inverseIMU_gain_Gain[5];

  /* DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  localB->denAccum_cv5hdgrwft = localB->inverseIMU_gain[5];
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->denAccum_cv5hdgrwft -= localP->IIR_IMUgyro_r_DenCoef[localB->denIdx]
      * localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  localB->denAccum_cv5hdgrwft /= localP->IIR_IMUgyro_r_DenCoef[0];
  rtb_Product_m1rp1dgfci_idx_1 = localP->IIR_IMUgyro_r_NumCoef[0] *
    localB->denAccum_cv5hdgrwft;
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    rtb_Product_m1rp1dgfci_idx_1 += localP->IIR_IMUgyro_r_NumCoef[localB->denIdx]
      * localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  /* SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1' incorporates:
   *  Memory: '<S34>/Memory'
   */
  rtb_sincos_o2_idx_0 = localDW->Memory_PreviousInput[2];
  rtb_sincos_o2_idx_1 = localDW->Memory_PreviousInput[1];
  rtb_sincos_o2_idx_2 = localDW->Memory_PreviousInput[0];

  /* Trigonometry: '<S42>/Trigonometric Function' incorporates:
   *  Memory: '<S34>/Memory'
   *  SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  localDW->Memory_PreviousInput[0] = (real32_T)sin(localDW->
    Memory_PreviousInput[2]);
  localB->sincos_o2_f2vyjtakzt[0] = (real32_T)cos(localDW->Memory_PreviousInput
    [2]);
  localDW->Memory_PreviousInput[1] = (real32_T)sin(localDW->
    Memory_PreviousInput[1]);
  localB->sincos_o2_f2vyjtakzt[1] = (real32_T)cos(rtb_sincos_o2_idx_1);
  localDW->Memory_PreviousInput[2] = (real32_T)sin(rtb_sincos_o2_idx_2);

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[0] = localP->Constant_Value;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[1] = localP->Constant_Value;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn3' */
  localB->VectorConcatenate[2] = localB->sincos_o2_f2vyjtakzt[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn4' */
  localB->VectorConcatenate[3] = localDW->Memory_PreviousInput[0];

  /* Product: '<S42>/Product1' */
  localB->VectorConcatenate[4] = localB->sincos_o2_f2vyjtakzt[0] *
    localB->sincos_o2_f2vyjtakzt[1];

  /* Product: '<S42>/Product3' */
  localB->VectorConcatenate[5] = localDW->Memory_PreviousInput[0] *
    localDW->Memory_PreviousInput[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn7' */
  localB->VectorConcatenate[6] = localB->sincos_o2_f2vyjtakzt[0];

  /* Product: '<S42>/Product2' incorporates:
   *  Gain: '<S42>/Gain'
   */
  localB->VectorConcatenate[7] = localP->Gain_Gain_nwkt5b5fro *
    localDW->Memory_PreviousInput[0] * localB->sincos_o2_f2vyjtakzt[1];

  /* Product: '<S42>/Product4' */
  localB->VectorConcatenate[8] = localB->sincos_o2_f2vyjtakzt[0] *
    localDW->Memory_PreviousInput[1];

  /* Product: '<S42>/Divide' */
  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->VectorConcatenate[localB->j] /= localB->sincos_o2_f2vyjtakzt[1];
  }

  /* End of Product: '<S42>/Divide' */

  /* Product: '<S34>/Product' incorporates:
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  SignalConversion: '<S34>/TmpSignal ConversionAtProductInport2'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localDW->Memory_PreviousInput[localB->j] = 0.0F;
    localDW->Memory_PreviousInput[localB->j] += localB->VectorConcatenate
      [localB->j] * localB->inverseIMU_gain[3];
    localDW->Memory_PreviousInput[localB->j] += localB->VectorConcatenate
      [localB->j + 3] * localB->inverseIMU_gain[4];
    localDW->Memory_PreviousInput[localB->j] += localB->VectorConcatenate
      [localB->j + 6] * rtb_Product_m1rp1dgfci_idx_1;
  }

  /* End of Product: '<S34>/Product' */

  /* Sum: '<S34>/Sum' incorporates:
   *  Gain: '<S34>/Gain'
   */
  localB->Sum_amwaersy43[0] = localP->Gain_Gain_juztar0qtz *
    localDW->Memory_PreviousInput[2] + rtb_sincos_o2_idx_0;
  localB->Sum_amwaersy43[1] = localP->Gain_Gain_juztar0qtz *
    localDW->Memory_PreviousInput[1] + rtb_sincos_o2_idx_1;
  localB->Sum_amwaersy43[2] = localP->Gain_Gain_juztar0qtz *
    localDW->Memory_PreviousInput[0] + rtb_sincos_o2_idx_2;

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = localB->inverseIMU_gain[0] *
    localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = rtb_sincos_o2_idx_2;

  /* Math: '<S34>/Math Function' incorporates:
   *  Constant: '<S34>/Constant'
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)floor
    (localP->Constant_Value_percv3dd1f);
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (localP->Constant_Value_percv3dd1f >
       rtb_TrigonometricFunction_o1)) {
    localB->sincos_o2_f2vyjtakzt[0] = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  } else {
    localB->sincos_o2_f2vyjtakzt[0] = rt_powf_snf(rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  }

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = localB->inverseIMU_gain[1] *
    localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[5 + localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[5 + localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = rtb_sincos_o2_idx_2;

  /* Math: '<S34>/Math Function' incorporates:
   *  Constant: '<S34>/Constant'
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (localP->Constant_Value_percv3dd1f >
       rtb_TrigonometricFunction_o1)) {
    rtb_Switch_idx_0 = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  } else {
    rtb_Switch_idx_0 = rt_powf_snf(rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  }

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_sincos_o2_idx_2 = localB->inverseIMU_gain[2] *
    localP->FIR_IMUaccel_Coefficients[0];
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[10 + localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_sincos_o2_idx_2 += localDW->FIR_IMUaccel_states[10 + localB->j] *
      localP->FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = rtb_sincos_o2_idx_2;

  /* Math: '<S34>/Math Function' incorporates:
   *  Constant: '<S34>/Constant'
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  if ((rtb_sincos_o2_idx_2 < 0.0F) && (localP->Constant_Value_percv3dd1f >
       rtb_TrigonometricFunction_o1)) {
    rtb_Gain = -rt_powf_snf(-rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  } else {
    rtb_Gain = rt_powf_snf(rtb_sincos_o2_idx_2,
      localP->Constant_Value_percv3dd1f);
  }

  /* Sqrt: '<S34>/Sqrt' incorporates:
   *  Math: '<S34>/Math Function'
   *  Sum: '<S34>/Sum of Elements'
   */
  rtb_sincos_o2_idx_1 = (real32_T)sqrt((localB->sincos_o2_f2vyjtakzt[0] +
    rtb_Switch_idx_0) + rtb_Gain);

  /* If: '<S34>/If' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Inport: '<S41>/prin'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   */
  if ((rtb_sincos_o2_idx_1 > localP->CompareToConstant_const) &&
      (rtb_sincos_o2_idx_1 < localP->CompareToConstant1_const)) {
    /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    /* Sum: '<S40>/Sum' incorporates:
     *  DiscreteFir: '<S37>/FIR_IMUaccel'
     *  Gain: '<S40>/Gain'
     *  Gain: '<S40>/Gain1'
     *  Product: '<S40>/Divide'
     *  Trigonometry: '<S40>/Trigonometric Function'
     */
    localB->Merge[1] = (real32_T)atan(localB->FIR_IMUaccel[1] /
      rtb_sincos_o2_idx_2) * localP->Gain1_Gain + localP->Gain_Gain_dvwjhkjmhw *
      localB->Sum_amwaersy43[0];

    /* Gain: '<S40>/Gain2' */
    rtb_TrigonometricFunction_o1 = localP->Gain2_Gain * localB->FIR_IMUaccel[0];

    /* Trigonometry: '<S40>/Trigonometric Function1' */
    if (rtb_TrigonometricFunction_o1 > 1.0F) {
      rtb_TrigonometricFunction_o1 = 1.0F;
    } else {
      if (rtb_TrigonometricFunction_o1 < -1.0F) {
        rtb_TrigonometricFunction_o1 = -1.0F;
      }
    }

    /* Sum: '<S40>/Sum1' incorporates:
     *  Gain: '<S40>/Gain3'
     *  Gain: '<S40>/Gain4'
     *  Trigonometry: '<S40>/Trigonometric Function1'
     */
    localB->Merge[0] = localP->Gain4_Gain * localB->Sum_amwaersy43[1] +
      localP->Gain3_Gain * (real32_T)asin(rtb_TrigonometricFunction_o1);

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    localB->Merge[0] = localB->Sum_amwaersy43[1];
    localB->Merge[1] = localB->Sum_amwaersy43[0];

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */
  }

  /* End of If: '<S34>/If' */

  /* Delay: '<S103>/MemoryX' incorporates:
   *  Constant: '<S103>/X0'
   */
  if (localDW->icLoad_nkomoir31r != 0) {
    localDW->MemoryX_DSTATE_f3yjwtkool[0] = localP->X0_Value_lfdbgvehcb[0];
    localDW->MemoryX_DSTATE_f3yjwtkool[1] = localP->X0_Value_lfdbgvehcb[1];
  }

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S100>/Constant'
   *  Gain: '<S97>/opticalFlowErrorCorrect'
   *  Product: '<S97>/ '
   *  RelationalOperator: '<S100>/Compare'
   *  UnitDelay: '<S101>/Output'
   */
  if (localDW->Output_DSTATE < localP->CompareToConstant_const_oadmvaq2bv) {
    rtb_Switch_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    rtb_Gain = rtu_Sensors->VisionSensors.opticalFlow_data[1];
  } else {
    /* Gain: '<S97>/Gain' incorporates:
     *  DataTypeConversion: '<S35>/Data Type Conversion'
     */
    rtb_Gain = localP->Gain_Gain_b0xcv5ppve * (real32_T)localDW->Delay2_DSTATE;
    rtb_Switch_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0] * rtb_Gain
      * localP->opticalFlowErrorCorrect_Gain;
    rtb_Gain = rtu_Sensors->VisionSensors.opticalFlow_data[1] * rtb_Gain *
      localP->opticalFlowErrorCorrect_Gain;
  }

  /* End of Switch: '<S97>/Switch' */
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* DiscreteFilter: '<S102>/IIRgyroz' */
    localB->memOffset = localB->cff * 5;
    rtb_sincos_o2_idx_0 = localB->inverseIMU_gain[localB->cff + 3];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_sincos_o2_idx_0 -= localDW->IIRgyroz_states[localB->memOffset +
        localB->j] * localP->IIRgyroz_DenCoef[localB->denIdx];
      localB->denIdx++;
    }

    localDW->IIRgyroz_tmp[localB->cff] = rtb_sincos_o2_idx_0 /
      localP->IIRgyroz_DenCoef[0];
    rtb_sincos_o2_idx_0 = localP->IIRgyroz_NumCoef[0] * localDW->
      IIRgyroz_tmp[localB->cff];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_sincos_o2_idx_0 += localDW->IIRgyroz_states[localB->memOffset +
        localB->j] * localP->IIRgyroz_NumCoef[localB->denIdx];
      localB->denIdx++;
    }

    /* SampleTimeMath: '<S111>/TSamp' incorporates:
     *  DiscreteFilter: '<S102>/IIRgyroz'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_sincos_o2_idx_0 *= localP->TSamp_WtEt;

    /* DiscreteFilter: '<S102>/IIRgyroz' incorporates:
     *  Sum: '<S111>/Diff'
     *  UnitDelay: '<S111>/UD'
     */
    localB->Akxhatkk1_ld4ugmonpm[localB->cff] = rtb_sincos_o2_idx_0 -
      localDW->UD_DSTATE[localB->cff];

    /* SampleTimeMath: '<S111>/TSamp'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp[localB->cff] = rtb_sincos_o2_idx_0;
  }

  /* Abs: '<S102>/Abs' incorporates:
   *  Abs: '<S102>/Abs4'
   */
  rtb_sincos_o2_idx_0 = (real32_T)fabs(localB->inverseIMU_gain[3]);

  /* Abs: '<S102>/Abs1' incorporates:
   *  Abs: '<S102>/Abs5'
   */
  rtb_sincos_o2_idx_1 = (real32_T)fabs(localB->inverseIMU_gain[4]);

  /* Logic: '<S102>/Logical Operator3' incorporates:
   *  Abs: '<S102>/Abs'
   *  Abs: '<S102>/Abs1'
   *  Abs: '<S102>/Abs2'
   *  Abs: '<S102>/Abs3'
   *  Abs: '<S102>/Abs6'
   *  Abs: '<S102>/Abs7'
   *  Abs: '<S102>/Abs8'
   *  Abs: '<S102>/Abs9'
   *  Constant: '<S112>/Constant'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S114>/Constant'
   *  Constant: '<S115>/Constant'
   *  Constant: '<S116>/Constant'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S118>/Constant'
   *  Constant: '<S119>/Constant'
   *  Constant: '<S120>/Constant'
   *  Constant: '<S121>/Constant'
   *  Constant: '<S122>/Constant'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  Delay: '<S97>/Delay'
   *  Logic: '<S102>/Logical Operator'
   *  Logic: '<S102>/Logical Operator1'
   *  Logic: '<S102>/Logical Operator2'
   *  RelationalOperator: '<S112>/Compare'
   *  RelationalOperator: '<S113>/Compare'
   *  RelationalOperator: '<S114>/Compare'
   *  RelationalOperator: '<S115>/Compare'
   *  RelationalOperator: '<S116>/Compare'
   *  RelationalOperator: '<S117>/Compare'
   *  RelationalOperator: '<S118>/Compare'
   *  RelationalOperator: '<S119>/Compare'
   *  RelationalOperator: '<S120>/Compare'
   *  RelationalOperator: '<S121>/Compare'
   *  RelationalOperator: '<S122>/Compare'
   *  Sum: '<S102>/Add'
   */
  rtb_LogicalOperator3 = (((((real32_T)fabs(localB->Merge[0]) <=
    localP->maxp_const) && ((real32_T)fabs(localB->Merge[1]) <=
    localP->maxq_const) && (rtb_sincos_o2_idx_0 <= localP->maxw1_const) &&
    (rtb_sincos_o2_idx_1 <= localP->maxw2_const) && ((real32_T)fabs
    (localB->Akxhatkk1_ld4ugmonpm[0]) <= localP->maxdw1_const) && ((real32_T)
    fabs(localB->Akxhatkk1_ld4ugmonpm[1]) <= localP->maxdw2_const)) ||
    ((rtb_sincos_o2_idx_0 <= localP->maxp2_const) && (rtb_sincos_o2_idx_1 <=
    localP->maxq2_const))) && ((real32_T)fabs(rtb_Switch_idx_0 -
    localDW->Delay_DSTATE[0]) <= localP->maxw3_const) && ((real32_T)fabs
    (rtb_Gain - localDW->Delay_DSTATE[1]) <= localP->maxw4_const) && ((real32_T)
    localDW->Delay2_DSTATE <= localP->minHeightforOF_const));

  /* Outputs for Enabled SubSystem: '<S145>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S166>/Enable'
   */
  if (rtb_LogicalOperator3) {
    if (!localDW->EnabledSubsystem_MODE) {
      localDW->EnabledSubsystem_MODE = true;
    }

    /* Sum: '<S166>/Add1' incorporates:
     *  Constant: '<S103>/C'
     *  Delay: '<S103>/MemoryX'
     *  Product: '<S166>/Product'
     */
    rtb_sincos_o2_idx_0 = rtb_Switch_idx_0 - (localP->C_Value_p3s05liash[0] *
      localDW->MemoryX_DSTATE_f3yjwtkool[0] + localP->C_Value_p3s05liash[2] *
      localDW->MemoryX_DSTATE_f3yjwtkool[1]);
    rtb_sincos_o2_idx_1 = rtb_Gain - (localP->C_Value_p3s05liash[1] *
      localDW->MemoryX_DSTATE_f3yjwtkool[0] + localP->C_Value_p3s05liash[3] *
      localDW->MemoryX_DSTATE_f3yjwtkool[1]);

    /* Product: '<S166>/Product2' incorporates:
     *  Constant: '<S123>/KalmanGainM'
     *  DataTypeConversion: '<S162>/Conversion'
     */
    localB->Product2_af04vv1zot[0] = 0.0F;
    localB->Product2_af04vv1zot[0] += (real32_T)
      localP->KalmanGainM_Value_jjsg0b0z0q[0] * rtb_sincos_o2_idx_0;
    localB->Product2_af04vv1zot[0] += (real32_T)
      localP->KalmanGainM_Value_jjsg0b0z0q[2] * rtb_sincos_o2_idx_1;
    localB->Product2_af04vv1zot[1] = 0.0F;
    localB->Product2_af04vv1zot[1] += (real32_T)
      localP->KalmanGainM_Value_jjsg0b0z0q[1] * rtb_sincos_o2_idx_0;
    localB->Product2_af04vv1zot[1] += (real32_T)
      localP->KalmanGainM_Value_jjsg0b0z0q[3] * rtb_sincos_o2_idx_1;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S166>/deltax' */
      localB->Product2_af04vv1zot[0] = localP->deltax_Y0_hbk4yyz1lk;
      localB->Product2_af04vv1zot[1] = localP->deltax_Y0_hbk4yyz1lk;
      localDW->EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S145>/Enabled Subsystem' */

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localDW->Memory_PreviousInput[0] = localB->Sum_amwaersy43[2];

  /* Sum: '<S145>/Add' incorporates:
   *  Delay: '<S103>/MemoryX'
   */
  localDW->Delay_DSTATE[0] = localB->Product2_af04vv1zot[0] +
    localDW->MemoryX_DSTATE_f3yjwtkool[0];

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localDW->Memory_PreviousInput[1] = localB->Merge[0];

  /* Sum: '<S145>/Add' incorporates:
   *  Delay: '<S103>/MemoryX'
   */
  localDW->Delay_DSTATE[1] = localB->Product2_af04vv1zot[1] +
    localDW->MemoryX_DSTATE_f3yjwtkool[1];

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localDW->Memory_PreviousInput[2] = localB->Merge[1];

  /* Trigonometry: '<S46>/sincos' incorporates:
   *  Trigonometry: '<S167>/sincos'
   */
  rtb_sincos_o2_idx_0 = (real32_T)sin(localDW->Memory_PreviousInput[0]);
  rtb_sincos_o2_idx_1 = (real32_T)cos(localDW->Memory_PreviousInput[0]);
  rtb_TrigonometricFunction_o1 = (real32_T)sin(localDW->Memory_PreviousInput[1]);
  rtb_TrigonometricFunction_o2 = (real32_T)cos(localDW->Memory_PreviousInput[1]);
  rtb_sincos_o2_f2vyjtakzt_tmp = (real32_T)sin(localDW->Memory_PreviousInput[2]);
  rtb_sincos_o2_idx_2_tmp = (real32_T)cos(localDW->Memory_PreviousInput[2]);

  /* Fcn: '<S46>/Fcn11' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[0] = rtb_TrigonometricFunction_o2 *
    rtb_sincos_o2_idx_1;

  /* Fcn: '<S46>/Fcn21' incorporates:
   *  Fcn: '<S46>/Fcn22'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_f2vyjtakzt_tmp *
    rtb_TrigonometricFunction_o1;
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_idx_1
    - rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S46>/Fcn31' incorporates:
   *  Fcn: '<S46>/Fcn32'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp *
    rtb_TrigonometricFunction_o1;
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_1 + rtb_sincos_o2_f2vyjtakzt_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S46>/Fcn12' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[3] = rtb_TrigonometricFunction_o2 *
    rtb_sincos_o2_idx_0;

  /* Fcn: '<S46>/Fcn22' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_idx_0
    + rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S46>/Fcn32' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_sincos_o2_idx_0 - rtb_sincos_o2_f2vyjtakzt_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S46>/Fcn13' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[6] = -rtb_TrigonometricFunction_o1;

  /* Fcn: '<S46>/Fcn23' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[7] = rtb_sincos_o2_f2vyjtakzt_tmp *
    rtb_TrigonometricFunction_o2;

  /* Fcn: '<S46>/Fcn33' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[8] = rtb_sincos_o2_idx_2_tmp *
    rtb_TrigonometricFunction_o2;

  /* Product: '<S35>/Product1' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion1'
   *  Delay: '<S6>/Delay1'
   *  SignalConversion: '<S35>/TmpSignal ConversionAtProduct1Inport2'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_Product1_tmp = (real_T)localB->VectorConcatenate[localB->j] *
      localDW->Delay1_DSTATE[0];
    localB->rtb_Product1_tmp_cxarnvbvui = (real_T)localB->
      VectorConcatenate[localB->j + 3] * localDW->Delay1_DSTATE[1];
    localB->rtb_Product1_tmp_bhxxfovxdy = localB->VectorConcatenate[localB->j +
      6] * localB->u_msmdqfiwbm;
    localB->Product1[localB->j] = localB->rtb_Product1_tmp_bhxxfovxdy +
      (localB->rtb_Product1_tmp_cxarnvbvui + localB->rtb_Product1_tmp);
    localB->rtb_VectorConcatenate_cl54gopm0x[localB->j] =
      localB->rtb_Product1_tmp_bhxxfovxdy + (localB->rtb_Product1_tmp_cxarnvbvui
      + localB->rtb_Product1_tmp);
  }

  /* End of Product: '<S35>/Product1' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  DataTypeConversion: '<S35>/Data Type Conversion2'
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
   */
  localB->TmpSignalConversionAtToWorkspaceInport1[2] = (real32_T)
    localDW->Delay2_DSTATE;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] = localB->Sum_amwaersy43[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] = (real32_T)
    localB->Product1[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[4] = localB->Merge[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localDW->Delay_DSTATE[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[9] = localB->inverseIMU_gain[3];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localDW->SimplyIntegrateVelocity_DSTATE[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] = localB->Merge[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localDW->Delay_DSTATE[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[10] = localB->inverseIMU_gain
    [4];
  localB->TmpSignalConversionAtToWorkspaceInport1[11] =
    rtb_Product_m1rp1dgfci_idx_1;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = flightControlSystem_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)localDW->ToWorkspace_PWORK.LoggedData,
                          &locTime,
                          &localB->TmpSignalConversionAtToWorkspaceInport1[0]);
  }

  /* Math: '<S35>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_VectorConcatenate_mbvzarwird[3 * localB->j] =
      localB->VectorConcatenate[localB->j];
    localB->rtb_VectorConcatenate_mbvzarwird[1 + 3 * localB->j] =
      localB->VectorConcatenate[localB->j + 3];
    localB->rtb_VectorConcatenate_mbvzarwird[2 + 3 * localB->j] =
      localB->VectorConcatenate[localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->VectorConcatenate[localB->j] =
      localB->rtb_VectorConcatenate_mbvzarwird[localB->j];
  }

  /* End of Math: '<S35>/Math Function' */

  /* Fcn: '<S167>/Fcn11' */
  localB->MathFunction[0] = rtb_TrigonometricFunction_o2 * rtb_sincos_o2_idx_1;

  /* Fcn: '<S167>/Fcn21' incorporates:
   *  Fcn: '<S167>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_f2vyjtakzt_tmp *
    rtb_TrigonometricFunction_o1;
  localB->MathFunction[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_idx_1 -
    rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S167>/Fcn31' incorporates:
   *  Fcn: '<S167>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp *
    rtb_TrigonometricFunction_o1;
  localB->MathFunction[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2_idx_1 +
    rtb_sincos_o2_f2vyjtakzt_tmp * rtb_sincos_o2_idx_0;

  /* Fcn: '<S167>/Fcn12' */
  localB->MathFunction[3] = rtb_TrigonometricFunction_o2 * rtb_sincos_o2_idx_0;

  /* Fcn: '<S167>/Fcn22' */
  localB->MathFunction[4] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_idx_0 +
    rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S167>/Fcn32' */
  localB->MathFunction[5] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2_idx_0 -
    rtb_sincos_o2_f2vyjtakzt_tmp * rtb_sincos_o2_idx_1;

  /* Fcn: '<S167>/Fcn13' */
  localB->MathFunction[6] = -rtb_TrigonometricFunction_o1;

  /* Fcn: '<S167>/Fcn23' */
  localB->MathFunction[7] = rtb_sincos_o2_f2vyjtakzt_tmp *
    rtb_TrigonometricFunction_o2;

  /* Fcn: '<S167>/Fcn33' */
  localB->MathFunction[8] = rtb_sincos_o2_idx_2_tmp *
    rtb_TrigonometricFunction_o2;

  /* Math: '<S98>/Math Function' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_VectorConcatenate_mbvzarwird[3 * localB->j] =
      localB->MathFunction[localB->j];
    localB->rtb_VectorConcatenate_mbvzarwird[1 + 3 * localB->j] =
      localB->MathFunction[localB->j + 3];
    localB->rtb_VectorConcatenate_mbvzarwird[2 + 3 * localB->j] =
      localB->MathFunction[localB->j + 6];
  }

  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->MathFunction[localB->j] = localB->
      rtb_VectorConcatenate_mbvzarwird[localB->j];
  }

  /* End of Math: '<S98>/Math Function' */

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localB->Akxhatkk1_ld4ugmonpm[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
  localB->Akxhatkk1_ld4ugmonpm[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];

  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_flightControlSystem == 0U) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_Subir;
    localDW->temporalCounter_i1 = 0U;
    localB->x = 0.0F;
    localB->y = 0.0F;
    localB->z = -0.8F;
    localDW->vel = 2.48;
    localB->yaw = 0.0;
    localDW->grados = 0.0;
    localDW->cen = 0.0;
    localDW->actual = 0.0;
  } else {
    switch (localDW->is_c3_flightControlSystem) {
     case flightControlSystem_IN_Adelante:
      if (localDW->actual != rtu_estado) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto1;
        localDW->actual = rtu_estado;
      } else {
        localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
        localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      }
      break;

     case flightControlSystem_IN_Circulo:
      if (localDW->actual != rtu_estado) {
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_EsperaDescenso;
        localDW->actual = rtu_estado;
        localB->z = -0.6F;
      } else {
        localB->u_msmdqfiwbm = 0.0005 * localDW->vel * 1.07;
        localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * localB->u_msmdqfiwbm);
        localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * localB->u_msmdqfiwbm);
      }
      break;

     case flightControlSystem_IN_Descender1:
      if (localDW->temporalCounter_i1 >= 20U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender2;
        localDW->temporalCounter_i1 = 0U;
        localB->z = -0.2F;
      } else {
        localB->z = -0.4F;
      }
      break;

     case flightControlSystem_IN_Descender2:
      if (localDW->temporalCounter_i1 >= 20U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender3;
        localB->z = -0.03F;
      } else {
        localB->z = -0.2F;
      }
      break;

     case flightControlSystem_IN_Descender3:
      localB->z = -0.03F;
      break;

     case flightControlSystem_IN_EsperaDescenso:
      if (rtu_estado == 7.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_aterrizajeiz;
        localDW->cen = -20.0;
      } else if (rtu_estado == 9.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_giro;
        localDW->temporalCounter_i1 = 0U;
        localB->u_msmdqfiwbm = ((localDW->grados + localDW->cen) + 120.0) *
          3.1415926535897931 / 180.0;
        localB->x += (real32_T)(cos(localB->u_msmdqfiwbm) * (0.0005 *
          localDW->vel));
        localB->y += (real32_T)(sin(localB->u_msmdqfiwbm) * (0.0005 *
          localDW->vel));
      } else if (rtu_estado == 8.0) {
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_aterrizajeder;
        localDW->cen = 20.0;
      } else if (rtu_estado == 6.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circulo;
        localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
        localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
      } else {
        localDW->actual = rtu_estado;
        localB->z = -0.6F;
      }
      break;

     case flightControlSystem_IN_GiroDerecha:
      if (localDW->temporalCounter_i1 >= 5U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto1;
        localDW->actual = rtu_estado;
      } else {
        localDW->grados += 0.5;
        localB->yaw = localDW->grados * 3.1415926535897931 / 180.0;
      }
      break;

     case flightControlSystem_IN_GiroIzquierda:
      if (localDW->temporalCounter_i1 >= 5U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto1;
        localDW->actual = rtu_estado;
      } else {
        localDW->grados += -0.5;
        localB->yaw = localDW->grados * 3.1415926535897931 / 180.0;
      }
      break;

     case flightControlSystem_IN_Quieto:
      if (localDW->temporalCounter_i1 >= 400U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto1;
        localDW->actual = rtu_estado;
      } else {
        localB->x += 0.00105F;
      }
      break;

     case flightControlSystem_IN_Quieto1:
      if (rtu_VisionbasedData && (rtu_estado == 2.0)) {
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_GiroIzquierda;
        localDW->temporalCounter_i1 = 0U;
        localDW->grados += -0.5;
        localB->yaw = localDW->grados * 3.1415926535897931 / 180.0;
      } else if (rtu_estado == 6.0) {
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_EsperaDescenso;
        localDW->actual = 6.0;
        localB->z = -0.6F;
      } else if (rtu_VisionbasedData && (rtu_estado == 3.0)) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_GiroDerecha;
        localDW->temporalCounter_i1 = 0U;
        localDW->grados += 0.5;
        localB->yaw = localDW->grados * 3.1415926535897931 / 180.0;
      } else if (!rtu_VisionbasedData) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender1;
        localDW->temporalCounter_i1 = 0U;
        localB->z = -0.4F;
      } else if (rtu_estado == 4.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_iz;
        localDW->cen = -20.0;
      } else if (rtu_estado == 1.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_centrado;
        localDW->cen = 0.0;
      } else if (rtu_estado == 5.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_der;
        localDW->cen = 20.0;
      } else {
        localDW->actual = rtu_estado;
      }
      break;

     case flightControlSystem_IN_Subir:
      if (localDW->temporalCounter_i1 >= 600U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto;
        localDW->temporalCounter_i1 = 0U;
        localB->x += 0.00105F;
      } else {
        localB->x = 0.0F;
        localB->y = 0.0F;
        localB->z = -0.8F;
        localDW->vel = 2.48;
        localB->yaw = 0.0;
        localDW->grados = 0.0;
        localDW->cen = 0.0;
        localDW->actual = 0.0;
      }
      break;

     case flightControlSystem_IN_aterrizajeder:
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circulo;
      localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
      localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
      break;

     case flightControlSystem_IN_aterrizajeiz:
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circulo;
      localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
      localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel * 1.07));
      break;

     case flightControlSystem_IN_centrado:
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Adelante;
      localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      break;

     case flightControlSystem_IN_der:
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Adelante;
      localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      break;

     case flightControlSystem_IN_giro:
      if (localDW->temporalCounter_i1 >= 40U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender1;
        localDW->temporalCounter_i1 = 0U;
        localB->z = -0.4F;
      } else {
        localB->x += (real32_T)(cos(((localDW->grados + localDW->cen) + 120.0) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
        localB->y += (real32_T)(sin(((localDW->grados + localDW->cen) + 120.0) *
          3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      }
      break;

     default:
      /* case IN_iz: */
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Adelante;
      localB->x += (real32_T)(cos((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      localB->y += (real32_T)(sin((localDW->grados + localDW->cen) *
        3.1415926535897931 / 180.0) * (0.0005 * localDW->vel));
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  BusAssignment: '<S1>/Control Mode Update'
   *  Constant: '<S1>/controlModePosVsOrient'
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Sum: '<S9>/Sum18'
   */
  if (localP->controlModePosVsOrient_Value) {
    /* Trigonometry: '<S9>/Trigonometric Function' */
    rtb_TrigonometricFunction_o1 = (real32_T)sin(localB->Sum_amwaersy43[2]);
    rtb_TrigonometricFunction_o2 = (real32_T)cos(localB->Sum_amwaersy43[2]);

    /* Sum: '<S9>/Sum17' incorporates:
     *  BusAssignment: '<S5>/Bus  Assignment'
     *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
     */
    rtb_sincos_o2_idx_0 = localB->x - localDW->SimplyIntegrateVelocity_DSTATE[0];
    rtb_sincos_o2_idx_1 = localB->y - localDW->SimplyIntegrateVelocity_DSTATE[1];

    /* Product: '<S9>/Product' incorporates:
     *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
     *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
     */
    rtb_sincos_o2_f2vyjtakzt_tmp = rtb_TrigonometricFunction_o2 *
      rtb_sincos_o2_idx_0 + rtb_TrigonometricFunction_o1 * rtb_sincos_o2_idx_1;

    /* Saturate: '<S9>/Saturation' */
    if (rtb_sincos_o2_f2vyjtakzt_tmp > localP->Saturation_UpperSat) {
      rtb_sincos_o2_f2vyjtakzt_tmp = localP->Saturation_UpperSat;
    } else {
      if (rtb_sincos_o2_f2vyjtakzt_tmp < localP->Saturation_LowerSat) {
        rtb_sincos_o2_f2vyjtakzt_tmp = localP->Saturation_LowerSat;
      }
    }

    localB->pitchrollerror_hujfwd2vao[0] = localP->P_xy_Gain[0] *
      rtb_sincos_o2_f2vyjtakzt_tmp + localP->D_xy_Gain[0] *
      localDW->Delay_DSTATE[0];

    /* Product: '<S9>/Product' incorporates:
     *  Gain: '<S9>/D_xy'
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/P_xy'
     *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
     *  Sum: '<S9>/Sum18'
     */
    rtb_sincos_o2_f2vyjtakzt_tmp = localP->Gain_Gain *
      rtb_TrigonometricFunction_o1 * rtb_sincos_o2_idx_0 +
      rtb_TrigonometricFunction_o2 * rtb_sincos_o2_idx_1;

    /* Saturate: '<S9>/Saturation' */
    if (rtb_sincos_o2_f2vyjtakzt_tmp > localP->Saturation_UpperSat) {
      rtb_sincos_o2_f2vyjtakzt_tmp = localP->Saturation_UpperSat;
    } else {
      if (rtb_sincos_o2_f2vyjtakzt_tmp < localP->Saturation_LowerSat) {
        rtb_sincos_o2_f2vyjtakzt_tmp = localP->Saturation_LowerSat;
      }
    }

    localB->pitchrollerror_hujfwd2vao[1] = localP->P_xy_Gain[1] *
      rtb_sincos_o2_f2vyjtakzt_tmp + localP->D_xy_Gain[1] *
      localDW->Delay_DSTATE[1];
  } else {
    localB->pitchrollerror_hujfwd2vao[0] =
      rtu_ReferenceValueServerCmds->orient_ref[1];
    localB->pitchrollerror_hujfwd2vao[1] =
      rtu_ReferenceValueServerCmds->orient_ref[2];
  }

  /* End of Switch: '<S3>/Switch_refAtt' */

  /* Sum: '<S7>/Sum19' */
  localB->pitchrollerror_hujfwd2vao[0] -= localB->Merge[0];
  rtb_TrigonometricFunction_o1 = localB->pitchrollerror_hujfwd2vao[1] -
    localB->Merge[1];
  localB->pitchrollerror_hujfwd2vao[1] = rtb_TrigonometricFunction_o1;

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_irglfepkql = (localDW->Output_DSTATE_hymmp1tw2p <
    localP->CompareToConstant_const_o2ywjbil1g);

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if ((!rtb_Compare_irglfepkql) &&
      (localDW->DiscreteTimeIntegrator_PrevResetState == 1)) {
    localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
      localP->DiscreteTimeIntegrator_IC_iymdtlt5j0;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj >=
      localP->DiscreteTimeIntegrator_UpperSat_plvc2rxdg0) {
    localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
      localP->DiscreteTimeIntegrator_UpperSat_plvc2rxdg0;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj <=
        localP->DiscreteTimeIntegrator_LowerSat_cbbd1x44vs) {
      localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
        localP->DiscreteTimeIntegrator_LowerSat_cbbd1x44vs;
    }
  }

  /* Sum: '<S11>/Sum2' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   */
  rtb_sincos_o2_idx_0 = localB->z - (real32_T)localDW->Delay2_DSTATE;

  /* Switch: '<S11>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S11>/w1'
   *  DataTypeConversion: '<S35>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_z1'
   *  Gain: '<S11>/P_z1'
   *  Gain: '<S11>/takeoff_gain1'
   *  Sum: '<S11>/Sum1'
   */
  if (rtb_Compare_irglfepkql) {
    rtb_sincos_o2_idx_1 = localP->takeoff_gain1_Gain * localP->w1_Value;
  } else {
    rtb_sincos_o2_idx_1 = (localP->P_z1_Gain * rtb_sincos_o2_idx_0 +
      localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj) - localP->D_z1_Gain *
      (real32_T)localB->Product1[2];
  }

  /* End of Switch: '<S11>/TakeoffOrControl_Switch1' */

  /* Sum: '<S11>/Sum5' incorporates:
   *  Constant: '<S11>/w1'
   */
  rtb_sincos_o2_idx_1 += localP->w1_Value;

  /* Saturate: '<S11>/SaturationThrust1' */
  if (rtb_sincos_o2_idx_1 > localP->SaturationThrust1_UpperSat) {
    rtb_sincos_o2_idx_1 = localP->SaturationThrust1_UpperSat;
  } else {
    if (rtb_sincos_o2_idx_1 < localP->SaturationThrust1_LowerSat) {
      rtb_sincos_o2_idx_1 = localP->SaturationThrust1_LowerSat;
    }
  }

  /* End of Saturate: '<S11>/SaturationThrust1' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  Gain: '<S10>/D_yaw'
   *  Gain: '<S10>/P_yaw'
   *  Gain: '<S7>/D_pr'
   *  Gain: '<S7>/I_pr'
   *  Gain: '<S7>/P_pr'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S7>/Sum16'
   */
  rtb_Product_m1rp1dgfci_idx_1 = ((real32_T)localB->yaw - localB->
    Sum_amwaersy43[2]) * localP->P_yaw_Gain - localP->D_yaw_Gain *
    rtb_Product_m1rp1dgfci_idx_1;
  rtb_TrigonometricFunction_o2 = (localP->P_pr_Gain[0] *
    localB->pitchrollerror_hujfwd2vao[0] + localP->I_pr_Gain *
    localDW->DiscreteTimeIntegrator_DSTATE[0]) - localP->D_pr_Gain[0] *
    localB->inverseIMU_gain[4];
  rtb_sincos_o2_f2vyjtakzt_tmp = (localP->P_pr_Gain[1] *
    rtb_TrigonometricFunction_o1 + localP->I_pr_Gain *
    localDW->DiscreteTimeIntegrator_DSTATE[1]) - localP->D_pr_Gain[1] *
    localB->inverseIMU_gain[3];
  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/TorqueTotalThrustToThrustPerMotor'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2'
     */
    rtb_TrigonometricFunction_o1 =
      localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 12] *
      rtb_sincos_o2_f2vyjtakzt_tmp +
      (localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 8] *
       rtb_TrigonometricFunction_o2 +
       (localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j + 4] *
        rtb_Product_m1rp1dgfci_idx_1 +
        localP->TorqueTotalThrustToThrustPerMotor_Value[localB->j] *
        rtb_sincos_o2_idx_1));

    /* Saturate: '<S12>/Saturation5' incorporates:
     *  Gain: '<S12>/ThrustToMotorCommand'
     */
    rtb_TrigonometricFunction_o1 *= localP->ThrustToMotorCommand_Gain;
    if (rtb_TrigonometricFunction_o1 > localP->Saturation5_UpperSat) {
      rtb_TrigonometricFunction_o1 = localP->Saturation5_UpperSat;
    } else {
      if (rtb_TrigonometricFunction_o1 < localP->Saturation5_LowerSat) {
        rtb_TrigonometricFunction_o1 = localP->Saturation5_LowerSat;
      }
    }

    /* End of Saturate: '<S12>/Saturation5' */

    /* Gain: '<S12>/MotorDirections' */
    localB->MotorDirections[localB->j] = localP->MotorDirections_Gain[localB->j]
      * rtb_TrigonometricFunction_o1;
  }

  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Sum: '<S35>/Sum' incorporates:
     *  Constant: '<S35>/gravity'
     *  DiscreteFir: '<S37>/FIR_IMUaccel'
     *  Product: '<S35>/Product'
     */
    localB->Product1[localB->j] = (localB->VectorConcatenate[localB->j + 6] *
      rtb_sincos_o2_idx_2 + (localB->VectorConcatenate[localB->j + 3] *
      localB->FIR_IMUaccel[1] + localB->VectorConcatenate[localB->j] *
      localB->FIR_IMUaccel[0])) + localP->gravity_Value[localB->j];

    /* Trigonometry: '<S105>/sincos' */
    localB->sincos_o2_f2vyjtakzt[localB->j] = (real32_T)cos
      (localDW->Memory_PreviousInput[localB->j]);

    /* Product: '<S35>/Product' incorporates:
     *  Trigonometry: '<S105>/sincos'
     */
    localB->Sum_amwaersy43[localB->j] = (real32_T)sin
      (localDW->Memory_PreviousInput[localB->j]);
  }

  /* Fcn: '<S105>/Fcn11' */
  localB->VectorConcatenate[0] = localB->sincos_o2_f2vyjtakzt[1] *
    localB->sincos_o2_f2vyjtakzt[0];

  /* Fcn: '<S105>/Fcn21' incorporates:
   *  Fcn: '<S105>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = localB->Sum_amwaersy43[2] * localB->
    Sum_amwaersy43[1];
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp *
    localB->sincos_o2_f2vyjtakzt[0] - localB->sincos_o2_f2vyjtakzt[2] *
    localB->Sum_amwaersy43[0];

  /* Fcn: '<S105>/Fcn31' incorporates:
   *  Fcn: '<S105>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = localB->sincos_o2_f2vyjtakzt[2] *
    localB->Sum_amwaersy43[1];
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    localB->sincos_o2_f2vyjtakzt[0] + localB->Sum_amwaersy43[2] *
    localB->Sum_amwaersy43[0];

  /* Fcn: '<S105>/Fcn12' */
  localB->VectorConcatenate[3] = localB->sincos_o2_f2vyjtakzt[1] *
    localB->Sum_amwaersy43[0];

  /* Fcn: '<S105>/Fcn22' */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    localB->Sum_amwaersy43[0] + localB->sincos_o2_f2vyjtakzt[2] *
    localB->sincos_o2_f2vyjtakzt[0];

  /* Fcn: '<S105>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    localB->Sum_amwaersy43[0] - localB->Sum_amwaersy43[2] *
    localB->sincos_o2_f2vyjtakzt[0];

  /* Fcn: '<S105>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->Sum_amwaersy43[1];

  /* Fcn: '<S105>/Fcn23' */
  localB->VectorConcatenate[7] = localB->Sum_amwaersy43[2] *
    localB->sincos_o2_f2vyjtakzt[1];

  /* Fcn: '<S105>/Fcn33' */
  localB->VectorConcatenate[8] = localB->sincos_o2_f2vyjtakzt[2] *
    localB->sincos_o2_f2vyjtakzt[1];

  /* RelationalOperator: '<S104>/Compare' incorporates:
   *  Constant: '<S104>/Constant'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   */
  rtb_Compare_okungkhenj = ((real32_T)localDW->Delay2_DSTATE <=
    localP->DeactivateAccelerationIfOFisnotusedduetolowaltitude_const);

  /* Logic: '<S99>/Logical Operator' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S106>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   */
  rtb_Compare_lbcpvaevgp = ((rtb_Switch_idx_0 !=
    localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con) ||
    (rtb_Gain !=
     localP->donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co));

  /* Sum: '<S99>/Add' incorporates:
   *  Constant: '<S99>/gravity'
   *  Product: '<S99>/Product1'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_FIR_IMUaccel_kkiq3xxxve[localB->j] = localB->FIR_IMUaccel
      [localB->j] - ((localB->VectorConcatenate[localB->j + 3] *
                      localP->gravity_Value_dibfthgkk3[1] +
                      localB->VectorConcatenate[localB->j] *
                      localP->gravity_Value_dibfthgkk3[0]) +
                     localB->VectorConcatenate[localB->j + 6] *
                     localP->gravity_Value_dibfthgkk3[2]);
  }

  /* End of Sum: '<S99>/Add' */

  /* Product: '<S99>/Product' incorporates:
   *  Gain: '<S99>/gainaccinput'
   */
  rtb_sincos_o2_idx_2 = (real32_T)(localP->gainaccinput_Gain *
    localB->rtb_FIR_IMUaccel_kkiq3xxxve[0]) * (real32_T)rtb_Compare_lbcpvaevgp *
    (real32_T)rtb_Compare_okungkhenj;
  rtb_Product_m1rp1dgfci_idx_1 = (real32_T)(localP->gainaccinput_Gain *
    localB->rtb_FIR_IMUaccel_kkiq3xxxve[1]) * (real32_T)rtb_Compare_lbcpvaevgp *
    (real32_T)rtb_Compare_okungkhenj;

  /* Outputs for Enabled SubSystem: '<S140>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S165>/Enable'
   */
  if (rtb_LogicalOperator3) {
    if (!localDW->MeasurementUpdate_MODE) {
      localDW->MeasurementUpdate_MODE = true;
    }

    /* Sum: '<S165>/Sum' incorporates:
     *  Constant: '<S103>/C'
     *  Constant: '<S103>/D'
     *  Delay: '<S103>/MemoryX'
     *  Product: '<S165>/C[k]*xhat[k|k-1]'
     *  Product: '<S165>/D[k]*u[k]'
     *  Sum: '<S165>/Add1'
     */
    rtb_Switch_idx_0 -= (localP->C_Value_p3s05liash[0] *
                         localDW->MemoryX_DSTATE_f3yjwtkool[0] +
                         localP->C_Value_p3s05liash[2] *
                         localDW->MemoryX_DSTATE_f3yjwtkool[1]) +
      (localP->D_Value_j0gctn4yse[0] * rtb_sincos_o2_idx_2 +
       localP->D_Value_j0gctn4yse[2] * rtb_Product_m1rp1dgfci_idx_1);
    rtb_Gain -= (localP->C_Value_p3s05liash[1] *
                 localDW->MemoryX_DSTATE_f3yjwtkool[0] +
                 localP->C_Value_p3s05liash[3] *
                 localDW->MemoryX_DSTATE_f3yjwtkool[1]) +
      (localP->D_Value_j0gctn4yse[1] * rtb_sincos_o2_idx_2 +
       localP->D_Value_j0gctn4yse[3] * rtb_Product_m1rp1dgfci_idx_1);

    /* Product: '<S165>/Product3' incorporates:
     *  Constant: '<S123>/KalmanGainL'
     *  DataTypeConversion: '<S161>/Conversion'
     */
    localB->Product3_drwpv1e3vz[0] = 0.0F;
    localB->Product3_drwpv1e3vz[0] += (real32_T)localP->KalmanGainL_Value[0] *
      rtb_Switch_idx_0;
    localB->Product3_drwpv1e3vz[0] += (real32_T)localP->KalmanGainL_Value[2] *
      rtb_Gain;
    localB->Product3_drwpv1e3vz[1] = 0.0F;
    localB->Product3_drwpv1e3vz[1] += (real32_T)localP->KalmanGainL_Value[1] *
      rtb_Switch_idx_0;
    localB->Product3_drwpv1e3vz[1] += (real32_T)localP->KalmanGainL_Value[3] *
      rtb_Gain;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3_drwpv1e3vz[0] = localP->Lykyhatkk1_Y0_ly1kk4lmmc;
      localB->Product3_drwpv1e3vz[1] = localP->Lykyhatkk1_Y0_ly1kk4lmmc;
      localDW->MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S140>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S65>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S90>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->MeasurementUpdate_MODE_dbwln3vz1a) {
      localDW->MeasurementUpdate_MODE_dbwln3vz1a = true;
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Constant: '<S44>/C'
     *  Constant: '<S44>/D'
     *  Delay: '<S44>/MemoryX'
     *  Product: '<S90>/C[k]*xhat[k|k-1]'
     *  Product: '<S90>/D[k]*u[k]'
     *  Sum: '<S90>/Add1'
     */
    localB->u_msmdqfiwbm = localB->invertzaxisGain - ((localP->C_Value[0] *
      localDW->MemoryX_DSTATE[0] + localP->C_Value[1] * localDW->MemoryX_DSTATE
      [1]) + localP->D_Value * localB->Product1[2]);

    /* Product: '<S90>/Product3' incorporates:
     *  Constant: '<S48>/KalmanGainL'
     */
    localB->Product3[0] = localP->KalmanGainL_Value_cqw4rtoxbn[0] *
      localB->u_msmdqfiwbm;
    localB->Product3[1] = localP->KalmanGainL_Value_cqw4rtoxbn[1] *
      localB->u_msmdqfiwbm;
  } else {
    if (localDW->MeasurementUpdate_MODE_dbwln3vz1a) {
      /* Disable for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3[0] = localP->Lykyhatkk1_Y0;
      localB->Product3[1] = localP->Lykyhatkk1_Y0;
      localDW->MeasurementUpdate_MODE_dbwln3vz1a = false;
    }
  }

  /* End of Outputs for SubSystem: '<S65>/MeasurementUpdate' */

  /* Sum: '<S15>/FixPt Sum1' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  UnitDelay: '<S14>/Output'
   */
  localB->FixPtSum1_ackzpfy53r = localDW->Output_DSTATE_hymmp1tw2p +
    localP->FixPtConstant_Value;

  /* Switch: '<S16>/FixPt Switch' */
  if (localB->FixPtSum1_ackzpfy53r > localP->WrapToZero_Threshold) {
    /* Update for UnitDelay: '<S14>/Output' incorporates:
     *  Constant: '<S16>/Constant'
     */
    localDW->Output_DSTATE_hymmp1tw2p = localP->Constant_Value_eesjyjh2ui;
  } else {
    /* Update for UnitDelay: '<S14>/Output' */
    localDW->Output_DSTATE_hymmp1tw2p = localB->FixPtSum1_ackzpfy53r;
  }

  /* End of Switch: '<S16>/FixPt Switch' */

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  Constant: '<S4>/Wait  3 Seconds'
   *  UnitDelay: '<S25>/Output'
   */
  rtb_nicemeasurementornewupdateneeded = (localDW->Output_DSTATE_nghfazzn45 >
    localP->Wait3Seconds_Value);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    localB->invertzaxisGain = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localB->u_msmdqfiwbm = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->invertzaxisGain = localP->_Value;
    localB->u_msmdqfiwbm = localP->_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S18>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->u_msmdqfiwbm ==
    localP->Checkerrorcondition_const) * localDW->DelayOneStep_DSTATE + (real_T)
    (localB->invertzaxisGain == localP->Checkerrorcondition_const);

  /* If: '<S4>/If' incorporates:
   *  Abs: '<S4>/Abs'
   *  Abs: '<S4>/Abs  '
   *  Abs: '<S4>/Abs1'
   *  Abs: '<S4>/Abs2'
   *  Abs: '<S4>/Abs3'
   *  Abs: '<S4>/Abs4'
   *  Abs: '<S4>/Abs5'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S4>/0.5 meters'
   *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S4>/GreaterThan  '
   *  Sum: '<S4>/Subtract'
   *  Sum: '<S4>/Subtract1'
   *  Switch: '<S4>/         '
   */
  if ((((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[0]) >
        localP->CompareToConstant_const_j2aeaztlxq) || ((real32_T)fabs
        (localDW->SimplyIntegrateVelocity_DSTATE[1]) >
        localP->CompareToConstant1_const_oea4nh0fds)) > 0) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge_dtz3huqpir,
      &localP->Geofencingerror);

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if (((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
                localP->CompareToConstant4_const) && ((real32_T)fabs
                (localP->Gain_Gain_nkg3zw25sw *
                 rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                 localDW->Delay_DSTATE[0]) > localP->CompareToConstant2_const)) ||
              (((real32_T)fabs(localP->Gain1_Gain_ov00v2ikfj *
      rtu_Sensors->VisionSensors.opticalFlow_data[1] - localDW->Delay_DSTATE[1])
                > localP->CompareToConstant3_const) && ((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[1]) >
                localP->CompareToConstant5_const))) > 0) {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge_dtz3huqpir,
      &localP->estimatorOpticalflowerror);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->DelayOneStep_DSTATE > localP->u0continuousOFerrors_const)
  {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    flightControlSystem_Geofencingerror(&localB->Merge_dtz3huqpir,
      &localP->Noopticalflow);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_nicemeasurementornewupdateneeded) {
      /* Switch: '<S4>/         ' incorporates:
       *  DataTypeConversion: '<S35>/Data Type Conversion'
       *  DiscreteFilter: '<S45>/pressureFilter_IIR'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      localB->numAccum = (real32_T)localDW->Delay2_DSTATE - localB->numAccum;
    } else {
      /* Switch: '<S4>/         ' incorporates:
       *  Constant: '<S4>/    '
       */
      localB->numAccum = localP->_Value_ouzfzmlb2y;
    }

    if ((real32_T)fabs(localB->numAccum) > localP->u5meters_Value) {
      /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge_dtz3huqpir,
        &localP->Ultrasoundimproper);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      flightControlSystem_Geofencingerror(&localB->Merge_dtz3huqpir,
        &localP->Normalcondition);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* Sum: '<S31>/FixPt Sum1' incorporates:
   *  Constant: '<S31>/FixPt Constant'
   *  UnitDelay: '<S25>/Output'
   */
  localB->FixPtSum1_ackzpfy53r = localDW->Output_DSTATE_nghfazzn45 +
    localP->FixPtConstant_Value_h5bewbcaxk;

  /* Sum: '<S109>/FixPt Sum1' incorporates:
   *  Constant: '<S109>/FixPt Constant'
   *  UnitDelay: '<S101>/Output'
   */
  localDW->Output_DSTATE += localP->FixPtConstant_Value_kchif4j3g4;

  /* Product: '<S98>/Product' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion2'
   *  SignalConversion: '<S98>/TmpSignal ConversionAtProductInport2'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->sincos_o2_f2vyjtakzt[localB->j] = localB->MathFunction[localB->j + 6]
      * (real32_T)localB->rtb_VectorConcatenate_cl54gopm0x[2] +
      (localB->MathFunction[localB->j + 3] * localDW->Delay_DSTATE[1] +
       localB->MathFunction[localB->j] * localDW->Delay_DSTATE[0]);
  }

  /* End of Product: '<S98>/Product' */

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = (int8_T)
    localP->controlModePosVsOrient_Value;

  /* Update for Delay: '<S44>/MemoryX' */
  localDW->icLoad = 0U;

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] +=
    localP->SimplyIntegrateVelocity_gainval * localB->sincos_o2_f2vyjtakzt[0];
  localDW->SimplyIntegrateVelocity_DSTATE[1] +=
    localP->SimplyIntegrateVelocity_gainval * localB->sincos_o2_f2vyjtakzt[1];

  /* Product: '<S65>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S44>/A'
   *  Delay: '<S44>/MemoryX'
   */
  localB->invertzaxisGain = localP->A_Value[1] * localDW->MemoryX_DSTATE[0] +
    localP->A_Value[3] * localDW->MemoryX_DSTATE[1];

  /* Update for Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S44>/A'
   *  Constant: '<S44>/B'
   *  Product: '<S65>/A[k]*xhat[k|k-1]'
   *  Product: '<S65>/B[k]*u[k]'
   *  Sum: '<S65>/Add'
   */
  localDW->MemoryX_DSTATE[0] = ((localP->A_Value[0] * localDW->MemoryX_DSTATE[0]
    + localP->A_Value[2] * localDW->MemoryX_DSTATE[1]) + localP->B_Value[0] *
    localB->Product1[2]) + localB->Product3[0];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S44>/B'
   *  Product: '<S65>/B[k]*u[k]'
   *  Sum: '<S65>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (localP->B_Value[1] * localB->Product1[2] +
    localB->invertzaxisGain) + localB->Product3[1];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];
  localDW->pressureFilter_IIR_states[0] = localB->denAccum_pbm3vprmfu;

  /* Update for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = localDW->soonarFilter_IIR_states[1];
  localDW->soonarFilter_IIR_states[1] = localDW->soonarFilter_IIR_states[0];
  localDW->soonarFilter_IIR_states[0] = localB->denAccum;

  /* Update for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->denAccum_cv5hdgrwft;

  /* Update for DiscreteFir: '<S37>/FIR_IMUaccel' */
  /* Update circular buffer index */
  localDW->FIR_IMUaccel_circBuf--;
  if (localDW->FIR_IMUaccel_circBuf < 0) {
    localDW->FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf] =
    localB->inverseIMU_gain[0];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 5] =
    localB->inverseIMU_gain[1];
  localDW->FIR_IMUaccel_states[localDW->FIR_IMUaccel_circBuf + 10] =
    localB->inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S37>/FIR_IMUaccel' */

  /* Update for Delay: '<S103>/MemoryX' */
  localDW->icLoad_nkomoir31r = 0U;

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[0] = localP->B_Value_divnfjb1dq[0] * rtb_sincos_o2_idx_2 +
    localP->B_Value_divnfjb1dq[2] * rtb_Product_m1rp1dgfci_idx_1;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[0] = localP->A_Value_l0gpbuxkte[0] *
    localDW->MemoryX_DSTATE_f3yjwtkool[0] + localP->A_Value_l0gpbuxkte[2] *
    localDW->MemoryX_DSTATE_f3yjwtkool[1];

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[1] = localP->B_Value_divnfjb1dq[1] * rtb_sincos_o2_idx_2;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[1] = localP->A_Value_l0gpbuxkte[1] *
    localDW->MemoryX_DSTATE_f3yjwtkool[0];

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[1] += localP->B_Value_divnfjb1dq[3] * rtb_Product_m1rp1dgfci_idx_1;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[1] += localP->A_Value_l0gpbuxkte[3] *
    localDW->MemoryX_DSTATE_f3yjwtkool[1];

  /* Switch: '<S110>/FixPt Switch' */
  if (localDW->Output_DSTATE > localP->WrapToZero_Threshold_m14ba5jvav) {
    /* Update for UnitDelay: '<S101>/Output' incorporates:
     *  Constant: '<S110>/Constant'
     */
    localDW->Output_DSTATE = localP->Constant_Value_o24gdufi11;
  }

  /* End of Switch: '<S110>/FixPt Switch' */
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* Update for Delay: '<S103>/MemoryX' incorporates:
     *  Sum: '<S140>/Add'
     */
    localDW->MemoryX_DSTATE_f3yjwtkool[localB->cff] = (localB->fv0[localB->cff]
      + localB->fv1[localB->cff]) + localB->Product3_drwpv1e3vz[localB->cff];

    /* Update for DiscreteFilter: '<S102>/IIRgyroz' */
    localB->memOffset = localB->cff * 5;
    localDW->IIRgyroz_states[localB->memOffset + 4] = localDW->
      IIRgyroz_states[localB->memOffset + 3];
    localDW->IIRgyroz_states[localB->memOffset + 3] = localDW->
      IIRgyroz_states[localB->memOffset + 2];
    localDW->IIRgyroz_states[localB->memOffset + 2] = localDW->
      IIRgyroz_states[localB->memOffset + 1];
    localDW->IIRgyroz_states[localB->memOffset + 1] = localDW->
      IIRgyroz_states[localB->memOffset];
    localDW->IIRgyroz_states[localB->memOffset] = localDW->IIRgyroz_tmp
      [localB->cff];

    /* Update for UnitDelay: '<S111>/UD' */
    localDW->UD_DSTATE[localB->cff] = localB->TSamp[localB->cff];

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE[localB->cff] = localDW->Delay_DSTATE[localB->cff];

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
     *  Delay: '<S7>/Delay'
     *  Gain: '<S7>/antiWU_Gain'
     *  Sum: '<S7>/Add'
     */
    localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] +=
      (localB->pitchrollerror_hujfwd2vao[localB->cff] - localP->antiWU_Gain_Gain
       * localDW->Delay_DSTATE_fbcbshewsf[localB->cff]) *
      localP->DiscreteTimeIntegrator_gainval;
    if (localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] >=
        localP->DiscreteTimeIntegrator_UpperSat) {
      localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] =
        localP->DiscreteTimeIntegrator_UpperSat;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] <=
          localP->DiscreteTimeIntegrator_LowerSat) {
        localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] =
          localP->DiscreteTimeIntegrator_LowerSat;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  }

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj +=
    localP->I_pr_Gain_cswgo3ze1g * rtb_sincos_o2_idx_0 *
    localP->DiscreteTimeIntegrator_gainval_b1wrfjbuk2;
  if (localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj >=
      localP->DiscreteTimeIntegrator_UpperSat_plvc2rxdg0) {
    localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
      localP->DiscreteTimeIntegrator_UpperSat_plvc2rxdg0;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj <=
        localP->DiscreteTimeIntegrator_LowerSat_cbbd1x44vs) {
      localDW->DiscreteTimeIntegrator_DSTATE_mnqnev55nj =
        localP->DiscreteTimeIntegrator_LowerSat_cbbd1x44vs;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    rtb_Compare_irglfepkql;

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

  /* Update for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_fbcbshewsf[0] = localB->Akxhatkk1_ld4ugmonpm[0];
  localDW->Delay_DSTATE_fbcbshewsf[1] = localB->Akxhatkk1_ld4ugmonpm[1];

  /* Switch: '<S32>/FixPt Switch' */
  if (localB->FixPtSum1_ackzpfy53r > localP->WrapToZero_Threshold_laizy3sja4) {
    /* Update for UnitDelay: '<S25>/Output' incorporates:
     *  Constant: '<S32>/Constant'
     */
    localDW->Output_DSTATE_nghfazzn45 = localP->Constant_Value_phytu2r2f1;
  } else {
    /* Update for UnitDelay: '<S25>/Output' */
    localDW->Output_DSTATE_nghfazzn45 = localB->FixPtSum1_ackzpfy53r;
  }

  /* End of Switch: '<S32>/FixPt Switch' */
}

/* Function for MATLAB Function: '<S2>/Deteccion de lineas verticales' */
static void flightControlSystem_sum(const boolean_T x[768], real_T y[32])
{
  int32_T xpageoffset;
  int32_T i;
  int32_T k;
  for (i = 0; i < 32; i++) {
    xpageoffset = i * 24;
    y[i] = x[xpageoffset];
    for (k = 0; k < 23; k++) {
      y[i] += (real_T)x[(xpageoffset + k) + 1];
    }
  }
}

/* Function for MATLAB Function: '<S2>/Deteccion de lineas verticales' */
static real_T flightControlSystem_sum_gdv4dbd5rd(const real_T x[32])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 31; k++) {
    y += x[k + 1];
  }

  return y;
}

/* Model step function for TID0 */
void flightControlSystem_step0(void)   /* Sample time: [0.005s, 0.0s] */
{
  boolean_T rtb_RateTransition;

  {                                    /* Sample time: [0.005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  rtb_RateTransition = flightControlSystem_DW.RateTransition_Buffer0;

  /* RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_B.RateTransition1 =
    flightControlSystem_DW.RateTransition1_Buffer[flightControlSystem_DW.RateTransition1_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_ControlSystem(flightControlSystem_M, &cmd_inport,
    &sensor_inport, rtb_RateTransition, flightControlSystem_B.RateTransition1,
    &flightControlSystem_B.ControlSystem, &flightControlSystem_DW.ControlSystem,
    &flightControlSystem_P.ControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtControl SystemOutport1' */
  motors_outport[0] = flightControlSystem_B.ControlSystem.MotorDirections[0];
  motors_outport[1] = flightControlSystem_B.ControlSystem.MotorDirections[1];
  motors_outport[2] = flightControlSystem_B.ControlSystem.MotorDirections[2];
  motors_outport[3] = flightControlSystem_B.ControlSystem.MotorDirections[3];

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* SignalConversion: '<Root>/TmpSignal ConversionAtControl SystemOutport2' */
  flag_outport = flightControlSystem_B.ControlSystem.Merge_dtz3huqpir;

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++flightControlSystem_M->Timing.clockTick0)) {
    ++flightControlSystem_M->Timing.clockTickH0;
  }

  flightControlSystem_M->Timing.taskTime0 =
    flightControlSystem_M->Timing.clockTick0 *
    flightControlSystem_M->Timing.stepSize0 +
    flightControlSystem_M->Timing.clockTickH0 *
    flightControlSystem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void flightControlSystem_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  int32_T alertacentro;
  int32_T frentesuperior;
  int32_T frente;
  int32_T lateraliz;
  int32_T lateralder;
  boolean_T rtb_Compare_bxgvey1kb0;
  uint32_T tmp;
  int32_T i;
  int32_T i_0;
  real_T tc_idx_13;
  const uint8_T *u0;

  /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
  /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
   *  Inport: '<Root>/Image Data'
   */
  u0 = &imRGB[0];
  MW_Build_RGB(u0, flightControlSystem_B.imageBuff_1,
               flightControlSystem_B.imageBuff_2,
               flightControlSystem_B.imageBuff_3);

  /* Logic: '<S2>/AND' incorporates:
   *  Constant: '<S171>/Constant'
   *  Constant: '<S172>/Constant'
   *  Constant: '<S173>/Constant'
   *  MATLABSystem: '<S2>/PARROT Image Conversion'
   *  RelationalOperator: '<S171>/Compare'
   *  RelationalOperator: '<S172>/Compare'
   *  RelationalOperator: '<S173>/Compare'
   */
  for (i = 0; i < 19200; i++) {
    flightControlSystem_B.AND[i] = ((flightControlSystem_B.imageBuff_1[i] >
      flightControlSystem_P.Thresholdforeachpixel1_const) &&
      (flightControlSystem_B.imageBuff_2[i] <
       flightControlSystem_P.Thresholdforeachpixel2_const) &&
      (flightControlSystem_B.imageBuff_3[i] <
       flightControlSystem_P.Thresholdforeachpixel3_const));
  }

  /* End of Logic: '<S2>/AND' */

  /* MATLAB Function: '<S2>/Deteccion de lineas verticales' incorporates:
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   *  Delay: '<S2>/Delay2'
   */
  frentesuperior = 0;
  frente = 0;
  lateraliz = 0;
  lateralder = 0;
  alertacentro = 0;
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[120 * i + i_0];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv5);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(32 + i) * 120 + i_0];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv4);
  flightControlSystem_B.tc_idx_4 = flightControlSystem_sum_gdv4dbd5rd
    (flightControlSystem_B.dv4);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(64 + i) * 120 + i_0];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv4);
  flightControlSystem_B.tc_idx_8 = flightControlSystem_sum_gdv4dbd5rd
    (flightControlSystem_B.dv4);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(96 + i) * 120 + i_0];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv4);
  flightControlSystem_B.tc_idx_12 = flightControlSystem_sum_gdv4dbd5rd
    (flightControlSystem_B.dv4);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(128 + i) * 120 + i_0];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv4);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(120 * i + i_0) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv3);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[((32 + i) * 120 + i_0) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  flightControlSystem_B.tc_idx_5 = flightControlSystem_sum_gdv4dbd5rd
    (flightControlSystem_B.dv2);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[((64 + i) * 120 + i_0) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  flightControlSystem_B.tc_idx_9 = flightControlSystem_sum_gdv4dbd5rd
    (flightControlSystem_B.dv2);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[((96 + i) * 120 + i_0) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  tc_idx_13 = flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv2);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[((128 + i) * 120 + i_0) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[(120 * i + i_0) + 48];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv1);
  for (i = 0; i < 32; i++) {
    for (i_0 = 0; i_0 < 24; i_0++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i_0 + 24 * i] =
        flightControlSystem_B.AND[((128 + i) * 120 + i_0) + 48];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv0);
  if (flightControlSystem_B.tc_idx_4 > 150.0) {
    frentesuperior = 1;
  }

  if (flightControlSystem_B.tc_idx_5 > 150.0) {
    frente = 1;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv5) > 150.0) {
    lateraliz = 1;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv4) > 150.0) {
    lateralder = 1;
  }

  if (flightControlSystem_B.tc_idx_8 > 150.0) {
    frentesuperior++;
  }

  if (flightControlSystem_B.tc_idx_9 > 150.0) {
    frente++;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv3) > 150.0) {
    lateraliz++;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv2) > 150.0) {
    lateralder++;
  }

  if (flightControlSystem_B.tc_idx_12 > 150.0) {
    frentesuperior++;
  }

  if (tc_idx_13 > 150.0) {
    frente++;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv1) > 150.0) {
    lateraliz++;
  }

  if (flightControlSystem_sum_gdv4dbd5rd(flightControlSystem_B.dv0) > 150.0) {
    lateralder++;
  }

  if ((lateraliz > 0) && (lateraliz > lateralder)) {
    flightControlSystem_B.alerta = 1.0;
  } else if ((lateralder > 0) && (lateralder > lateraliz)) {
    flightControlSystem_B.alerta = 2.0;
  } else {
    flightControlSystem_B.alerta = 0.0;
  }

  if ((flightControlSystem_B.alerta == 0.0) || (flightControlSystem_B.alerta ==
       flightControlSystem_DW.Delay1_DSTATE)) {
    flightControlSystem_B.alerta = flightControlSystem_DW.Delay1_DSTATE;
  }

  if (((frente == 0) && (frentesuperior > 0) && (lateralder == 0) && (lateraliz ==
        0)) || (flightControlSystem_DW.Delay2_DSTATE == 1.0)) {
    alertacentro = 1;
  }

  if ((flightControlSystem_DW.Delay_DSTATE == 0.0) ||
      (flightControlSystem_DW.Delay_DSTATE == 1.0) ||
      (flightControlSystem_DW.Delay_DSTATE == 4.0) ||
      (flightControlSystem_DW.Delay_DSTATE == 5.0) || (alertacentro == 1)) {
    if ((frentesuperior > 0) && (alertacentro == 0)) {
      if (flightControlSystem_B.tc_idx_5 - 100.0 >
          flightControlSystem_B.tc_idx_9) {
        frentesuperior = 4;
      } else if (tc_idx_13 - 100.0 > flightControlSystem_B.tc_idx_9) {
        frentesuperior = 5;
      } else {
        frentesuperior = 1;
      }
    } else if ((frentesuperior == 0) && (lateraliz > 0) && (alertacentro == 0))
    {
      frentesuperior = 2;
    } else if ((frentesuperior == 0) && (lateralder > 0) && (alertacentro == 0))
    {
      frentesuperior = 3;
    } else if ((frentesuperior == 0) && (flightControlSystem_B.alerta == 1.0) &&
               (alertacentro == 0)) {
      frentesuperior = 2;
    } else if ((frentesuperior == 0) && (flightControlSystem_B.alerta == 2.0) &&
               (alertacentro == 0)) {
      frentesuperior = 3;
    } else if ((alertacentro == 1) && (flightControlSystem_DW.Delay2_DSTATE ==
                0.0)) {
      frentesuperior = 6;
    } else if ((alertacentro == 1) && (flightControlSystem_DW.Delay2_DSTATE ==
                1.0)) {
      if (frentesuperior == 0) {
        frentesuperior = 9;
      } else if (flightControlSystem_B.tc_idx_4 - 100.0 >
                 flightControlSystem_B.tc_idx_8) {
        frentesuperior = 7;
      } else if (flightControlSystem_B.tc_idx_12 - 100.0 >
                 flightControlSystem_B.tc_idx_8) {
        frentesuperior = 8;
      } else {
        frentesuperior = 6;
      }
    } else {
      frentesuperior = 0;
    }
  } else {
    frentesuperior = 0;
  }

  /* Sum: '<S2>/Sum of white pixels' */
  tmp = 0U;
  for (i = 0; i < 19200; i++) {
    tmp += flightControlSystem_B.AND[i];
  }

  /* RelationalOperator: '<S174>/Compare' incorporates:
   *  Constant: '<S174>/Constant'
   *  Sum: '<S2>/Sum of white pixels'
   */
  rtb_Compare_bxgvey1kb0 = ((uint16_T)tmp >
    flightControlSystem_P.Thresholdfortotalwhitepixels_const);

  /* Update for Delay: '<S2>/Delay' */
  flightControlSystem_DW.Delay_DSTATE = frentesuperior;

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  MATLAB Function: '<S2>/Deteccion de lineas verticales'
   */
  flightControlSystem_DW.Delay1_DSTATE = flightControlSystem_B.alerta;

  /* Update for Delay: '<S2>/Delay2' incorporates:
   *  MATLAB Function: '<S2>/Deteccion de lineas verticales'
   */
  flightControlSystem_DW.Delay2_DSTATE = alertacentro;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */

  /* Update for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 = rtb_Compare_bxgvey1kb0;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_DW.RateTransition1_Buffer[flightControlSystem_DW.RateTransition1_ActiveBufIdx
    == 0] = frentesuperior;
  flightControlSystem_DW.RateTransition1_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition1_ActiveBufIdx == 0);
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  flightControlSystem_P.ControlSystem.SaturationSonar_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  rtmSetTFinal(flightControlSystem_M, -1);
  flightControlSystem_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    flightControlSystem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogT(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogX(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogXFinal(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(flightControlSystem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(flightControlSystem_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(flightControlSystem_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(flightControlSystem_M->rtwLogInfo, 1);
    rtliSetLogY(flightControlSystem_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(flightControlSystem_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(flightControlSystem_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &flightControlSystem_B), 0,
                sizeof(B_flightControlSystem_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&flightControlSystem_DW, 0,
                sizeof(DW_flightControlSystem_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&flightControlSystem_Y, 0,
                sizeof(ExtY_flightControlSystem_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* SetupRuntimeResources for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_SetupRTR(flightControlSystem_M,
    &flightControlSystem_DW.ControlSystem);

  /* End of SetupRuntimeResources for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Start(&flightControlSystem_DW.ControlSystem);

  /* End of Start for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_DW.obj.isInitialized = 0;
  flightControlSystem_DW.objisempty = true;
  flightControlSystem_DW.obj.isInitialized = 1;

  /* End of Start for SubSystem: '<Root>/Image Processing System' */

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 =
    flightControlSystem_P.RateTransition_InitialCondition;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_DW.RateTransition1_Buffer[0] =
    flightControlSystem_P.RateTransition1_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Init(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem, &flightControlSystem_P.ControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightControlSystem_DW.Delay_DSTATE =
    flightControlSystem_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  flightControlSystem_DW.Delay1_DSTATE =
    flightControlSystem_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S2>/Delay2' */
  flightControlSystem_DW.Delay2_DSTATE =
    flightControlSystem_P.Delay2_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
