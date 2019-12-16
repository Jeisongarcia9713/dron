/*
 * flightControlSystem.c
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

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"
#include "flightControlSystem_dt.h"

/* Named constants for Chart: '<S5>/Chart' */
#define flightControlSystem_CALL_EVENT (-1)
#define flightControlSystem_IN_Adelante ((uint8_T)1U)
#define flightControlSystem_IN_Circulo ((uint8_T)2U)
#define flightControlSystem_IN_Descender1 ((uint8_T)3U)
#define flightControlSystem_IN_Descender2 ((uint8_T)4U)
#define flightControlSystem_IN_Descender3 ((uint8_T)5U)
#define flightControlSystem_IN_Fin     ((uint8_T)6U)
#define flightControlSystem_IN_GiroDerecha ((uint8_T)7U)
#define flightControlSystem_IN_GiroIzquierda ((uint8_T)8U)
#define flightControlSystem_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define flightControlSystem_IN_Quieto  ((uint8_T)9U)
#define flightControlSystem_IN_Quieto1 ((uint8_T)10U)
#define flightControlSystem_IN_Subir   ((uint8_T)11U)
#define flightControlSystem_IN_centrado ((uint8_T)12U)
#define flightControlSystem_IN_der     ((uint8_T)13U)
#define flightControlSystem_IN_iz      ((uint8_T)14U)

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S12>/MotorDirections' */
uint8_T flag_outport;                  /* '<S4>/Merge' */

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
static real_T flightControlSystem_sum_erraza0c0y(const real_T x[32]);

/*
 * Output and update for action system:
 *    '<S4>/estimator//Optical flow error'
 *    '<S4>/No optical flow '
 */
void flightControlSystem_estimatorOpticalflowerror(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S30>/OutportBufferForOut1' incorporates:
   *  Constant: '<S30>/Constant'
   */
  *rty_Out1 = 99U;
}

/*
 * Output and update for action system:
 *    '<S4>/Ultrasound improper'
 *    '<S4>/Normal condition'
 */
void flightControlSystem_Ultrasoundimproper(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S29>/OutportBufferForOut1' incorporates:
   *  Constant: '<S29>/Constant'
   */
  *rty_Out1 = 0U;
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
   DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T i;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
  localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  localDW->SimplyIntegrateVelocity_PrevResetState = 2;

  /* InitializeConditions for Delay: '<S35>/Delay2' */
  localDW->Delay2_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S44>/MemoryX' */
  localDW->icLoad = 1U;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[0] = 0.0;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[0] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */

  /* InitializeConditions for DiscreteFir: '<S37>/FIR_IMUaccel' */
  localDW->FIR_IMUaccel_circBuf = 0;
  for (i = 0; i < 15; i++) {
    localDW->FIR_IMUaccel_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFir: '<S37>/FIR_IMUaccel' */

  /* InitializeConditions for Delay: '<S103>/MemoryX' */
  localDW->icLoad_gsr0jp51l1 = 1U;

  /* InitializeConditions for UnitDelay: '<S101>/Output' */
  localDW->Output_DSTATE = 0U;

  /* InitializeConditions for DiscreteFilter: '<S102>/IIRgyroz' */
  for (i = 0; i < 10; i++) {
    localDW->IIRgyroz_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S102>/IIRgyroz' */

  /* InitializeConditions for UnitDelay: '<S14>/Output' */
  localDW->Output_DSTATE_kdeodyri3i = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = 0.0F;
  localDW->DiscreteTimeIntegrator_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S25>/Output' */
  localDW->Output_DSTATE_aloeis45eb = 0U;

  /* InitializeConditions for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = 0.0;

  /* SystemInitialize for Chart: '<S5>/Chart' */
  localDW->sfEvent = flightControlSystem_CALL_EVENT;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c3_flightControlSystem = 0U;
  localDW->is_c3_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for UnitDelay: '<S111>/UD' */
  localDW->UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  localB->Reshapexhat[0] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_ijwdhdrv0s[0] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S91>/deltax' */
  localB->Product2[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S34>/Merge' */
  localB->Merge[0] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S166>/deltax' */
  localB->Product2_i5itdihbiv[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S145>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3_gd3igxsc2c[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S140>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[0] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S65>/MeasurementUpdate' */

  /* InitializeConditions for UnitDelay: '<S111>/UD' */
  localDW->UD_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  localB->Reshapexhat[1] = 0.0F;

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  localDW->Delay1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_ijwdhdrv0s[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S91>/deltax' */
  localB->Product2[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem' */

  /* SystemInitialize for Merge: '<S34>/Merge' */
  localB->Merge[1] = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S166>/deltax' */
  localB->Product2_i5itdihbiv[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S145>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3_gd3igxsc2c[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S140>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3[1] = 0.0;

  /* End of SystemInitialize for SubSystem: '<S65>/MeasurementUpdate' */

  /* SystemInitialize for Merge: '<S4>/Merge' */
  flag_outport = 0U;
}

/* Output and update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T * const
  flightControlSystem_M, const SensorsBus *rtu_Sensors, boolean_T
  rtu_VisionbasedData, real_T rtu_estado, B_ControlSystem_flightControlSystem_T *
  localB, DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T memOffset;
  boolean_T rtb_nicemeasurementornewupdateneeded;
  real32_T rtb_Abs;
  boolean_T rtb_Compare_fdisj14o15;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_Compare_gctmfem22b;
  boolean_T rtb_Compare_dy3hxo2bjx;
  real32_T rtb_pitchrollerror;
  real32_T rtb_Sum_mah4rh5nu3_idx_1;
  real32_T rtb_Sum_mah4rh5nu3_idx_0;
  real32_T rtb_Product_pqmkptcz2s_idx_0;
  real32_T u0;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_sincos_o2_kq55ojr1f2_tmp;
  real32_T rtb_sincos_o2_kq55ojr1f2_tmp_0;
  real32_T rtb_sincos_o2_tmp;

  /* DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  if (localDW->SimplyIntegrateVelocity_PrevResetState <= 0) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  localB->SimplyIntegrateVelocity[0] = localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->SimplyIntegrateVelocity[1] = localDW->SimplyIntegrateVelocity_DSTATE[1];

  /* End of DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */

  /* Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S47>/Constant'
   *  Delay: '<S35>/Delay2'
   *  RelationalOperator: '<S47>/Compare'
   */
  if (localDW->Delay2_DSTATE > 0.0) {
    localDW->icLoad = 1U;
  }

  if (localDW->icLoad != 0) {
    localDW->MemoryX_DSTATE[0] = -0.046;
    localDW->MemoryX_DSTATE[1] = 0.0;
  }

  /* SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0' */
  localB->altitude = rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;

  /* Sum: '<S37>/Sum2' incorporates:
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector6_at_outport_0'
   */
  localB->Sum2 = rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
    rtu_Sensors->SensorCalibration[6];

  /* DiscreteFilter: '<S45>/pressureFilter_IIR' incorporates:
   *  Gain: '<S35>/prsToAltGain'
   */
  localB->denAccum_kkiq3xxxve = ((0.0832137167F * localB->Sum2 - -2.93717074F *
    localDW->pressureFilter_IIR_states[0]) - 2.87629962F *
    localDW->pressureFilter_IIR_states[1]) - -0.939098954F *
    localDW->pressureFilter_IIR_states[2];
  localB->numAccum = ((3.75683794E-6F * localB->denAccum_kkiq3xxxve +
                       1.12705138E-5F * localDW->pressureFilter_IIR_states[0]) +
                      1.12705138E-5F * localDW->pressureFilter_IIR_states[1]) +
    3.75683794E-6F * localDW->pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S45>/soonarFilter_IIR' incorporates:
   *  Gain: '<S35>/invertzaxisGain'
   */
  localB->denAccum = ((-(real_T)localB->altitude - -2.9371707284498907 *
                       localDW->soonarFilter_IIR_states[0]) - 2.8762997234793319
                      * localDW->soonarFilter_IIR_states[1]) -
    -0.939098940325283 * localDW->soonarFilter_IIR_states[2];

  /* Saturate: '<S45>/SaturationSonar' incorporates:
   *  Gain: '<S35>/invertzaxisGain'
   */
  if (-(real_T)localB->altitude >= -0.44) {
    localB->u_ch4zj0naok = -0.44;
  } else {
    localB->u_ch4zj0naok = -(real_T)localB->altitude;
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
   *  Gain: '<S35>/invertzaxisGain'
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
    localB->u_ch4zj0naok) <= 0.1) && (-(real_T)localB->altitude < -0.44) &&
    ((!(fabs(localB->numAccum - localDW->Delay2_DSTATE) >= 0.8)) || (!(fabs
    ((((3.7568380197861018E-6 * localB->denAccum + 1.1270514059358305E-5 *
        localDW->soonarFilter_IIR_states[0]) + 1.1270514059358305E-5 *
       localDW->soonarFilter_IIR_states[1]) + 3.7568380197861018E-6 *
      localDW->soonarFilter_IIR_states[2]) - localDW->Delay2_DSTATE) >= 0.4))));

  /* Outputs for Enabled SubSystem: '<S70>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S91>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->EnabledSubsystem_MODE_n0gllf0cgu) {
      localDW->EnabledSubsystem_MODE_n0gllf0cgu = true;
    }

    /* Sum: '<S91>/Add1' incorporates:
     *  Constant: '<S44>/C'
     *  Delay: '<S44>/MemoryX'
     *  Gain: '<S35>/invertzaxisGain'
     *  Product: '<S91>/Product'
     */
    localB->u_ch4zj0naok = -(real_T)localB->altitude - (0.0 *
      localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]);

    /* Product: '<S91>/Product2' */
    localB->Product2[0] = 0.02624142064187163 * localB->u_ch4zj0naok;
    localB->Product2[1] = 0.0697767360714917 * localB->u_ch4zj0naok;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC_bgcmjfg1p0);
  } else {
    if (localDW->EnabledSubsystem_MODE_n0gllf0cgu) {
      /* Disable for Outport: '<S91>/deltax' */
      localB->Product2[0] = 0.0;
      localB->Product2[1] = 0.0;
      localDW->EnabledSubsystem_MODE_n0gllf0cgu = false;
    }
  }

  /* End of Outputs for SubSystem: '<S70>/Enabled Subsystem' */

  /* Delay: '<S35>/Delay2' incorporates:
   *  Delay: '<S44>/MemoryX'
   *  Sum: '<S70>/Add'
   */
  localDW->Delay2_DSTATE = localB->Product2[0] + localDW->MemoryX_DSTATE[0];

  /* Sum: '<S70>/Add' incorporates:
   *  Delay: '<S44>/MemoryX'
   */
  localB->u_ch4zj0naok = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

  /* DataTypeConversion: '<S35>/Data Type Conversion' */
  localB->DataTypeConversion = (real32_T)localDW->Delay2_DSTATE;

  /* SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1' incorporates:
   *  Memory: '<S34>/Memory'
   */
  localB->sincos_o2_kq55ojr1f2[0] = localDW->Memory_PreviousInput[2];
  localB->sincos_o2_kq55ojr1f2[1] = localDW->Memory_PreviousInput[1];
  localB->sincos_o2_kq55ojr1f2[2] = localDW->Memory_PreviousInput[0];

  /* Trigonometry: '<S42>/Trigonometric Function' incorporates:
   *  Memory: '<S34>/Memory'
   *  SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  localDW->Memory_PreviousInput[0] = (real32_T)sin(localDW->
    Memory_PreviousInput[2]);
  localB->sincos_o2[0] = (real32_T)cos(localDW->Memory_PreviousInput[2]);
  localDW->Memory_PreviousInput[1] = (real32_T)sin(localDW->
    Memory_PreviousInput[1]);
  localB->sincos_o2[1] = (real32_T)cos(localB->sincos_o2_kq55ojr1f2[1]);
  localDW->Memory_PreviousInput[2] = (real32_T)sin(localB->sincos_o2_kq55ojr1f2
    [2]);

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[0] = 0.0F;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[1] = 0.0F;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn3' */
  localB->VectorConcatenate[2] = localB->sincos_o2[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn4' */
  localB->VectorConcatenate[3] = localDW->Memory_PreviousInput[0];

  /* Product: '<S42>/Product1' */
  localB->VectorConcatenate[4] = localB->sincos_o2[0] * localB->sincos_o2[1];

  /* Product: '<S42>/Product3' */
  localB->VectorConcatenate[5] = localDW->Memory_PreviousInput[0] *
    localDW->Memory_PreviousInput[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn7' */
  localB->VectorConcatenate[6] = localB->sincos_o2[0];

  /* Product: '<S42>/Product2' incorporates:
   *  Gain: '<S42>/Gain'
   */
  localB->VectorConcatenate[7] = localB->sincos_o2[1] *
    -localDW->Memory_PreviousInput[0];

  /* Product: '<S42>/Product4' */
  localB->VectorConcatenate[8] = localB->sincos_o2[0] *
    localDW->Memory_PreviousInput[1];

  /* Product: '<S42>/Divide' */
  for (localB->j = 0; localB->j < 9; localB->j++) {
    localB->VectorConcatenate[localB->j] /= localB->sincos_o2[1];
  }

  /* End of Product: '<S42>/Divide' */

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
    rtu_Sensors->SensorCalibration[0]) * 0.994075298F;
  localB->inverseIMU_gain[1] = (rtu_Sensors->HALSensors.HAL_acc_SI.y -
    rtu_Sensors->SensorCalibration[1]) * 0.996184587F;
  localB->inverseIMU_gain[2] = (rtu_Sensors->HALSensors.HAL_acc_SI.z -
    (rtu_Sensors->SensorCalibration[2] + 9.81F)) * 1.00549F;
  localB->inverseIMU_gain[3] = (rtu_Sensors->HALSensors.HAL_gyro_SI.x -
    rtu_Sensors->SensorCalibration[3]) * 1.00139189F;
  localB->inverseIMU_gain[4] = (rtu_Sensors->HALSensors.HAL_gyro_SI.y -
    rtu_Sensors->SensorCalibration[4]) * 0.993601203F;
  localB->inverseIMU_gain[5] = (rtu_Sensors->HALSensors.HAL_gyro_SI.z -
    rtu_Sensors->SensorCalibration[5]) * 1.00003F;

  /* DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  localB->denAccum_cxarnvbvui = localB->inverseIMU_gain[5];
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->denAccum_cxarnvbvui -= flightControlSystem_ConstP.pooled10
      [localB->denIdx] * localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  rtb_pitchrollerror = 0.282124132F * localB->denAccum_cxarnvbvui;
  localB->denIdx = 1;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    rtb_pitchrollerror += flightControlSystem_ConstP.pooled9[localB->denIdx] *
      localDW->IIR_IMUgyro_r_states[localB->j];
    localB->denIdx++;
  }

  /* SignalConversion: '<S34>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   */
  localDW->Memory_PreviousInput[0] = localB->inverseIMU_gain[3];
  localDW->Memory_PreviousInput[1] = localB->inverseIMU_gain[4];
  localDW->Memory_PreviousInput[2] = rtb_pitchrollerror;

  /* Product: '<S34>/Product' */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->sincos_o2[localB->j] = localB->VectorConcatenate[localB->j + 6] *
      localDW->Memory_PreviousInput[2] + (localB->VectorConcatenate[localB->j +
      3] * localDW->Memory_PreviousInput[1] + localB->VectorConcatenate
      [localB->j] * localDW->Memory_PreviousInput[0]);
  }

  /* End of Product: '<S34>/Product' */

  /* Sum: '<S34>/Sum' incorporates:
   *  Gain: '<S34>/Gain'
   */
  rtb_Sum_mah4rh5nu3_idx_0 = 0.005F * localB->sincos_o2[2] +
    localB->sincos_o2_kq55ojr1f2[0];

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_Product_pqmkptcz2s_idx_0 = localB->inverseIMU_gain[0] * 0.0264077242F;
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[localB->j] *
      flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[localB->j] *
      flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[0] = rtb_Product_pqmkptcz2s_idx_0;

  /* Math: '<S34>/Math Function' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  localB->sincos_o2_kq55ojr1f2[0] = rt_powf_snf(rtb_Product_pqmkptcz2s_idx_0,
    2.0F);

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_Product_pqmkptcz2s_idx_0 = localB->inverseIMU_gain[1] * 0.0264077242F;
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[5 + localB->j] *
      flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[5 + localB->j] *
      flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[1] = rtb_Product_pqmkptcz2s_idx_0;

  /* Math: '<S34>/Math Function' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  rtb_Sum_mah4rh5nu3_idx_1 = rt_powf_snf(rtb_Product_pqmkptcz2s_idx_0, 2.0F);

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  rtb_Product_pqmkptcz2s_idx_0 = localB->inverseIMU_gain[2] * 0.0264077242F;
  localB->cff = 1;
  localB->j = localDW->FIR_IMUaccel_circBuf;
  while (localB->j < 5) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[10 + localB->j]
      * flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->j = 0;
  while (localB->j < localDW->FIR_IMUaccel_circBuf) {
    rtb_Product_pqmkptcz2s_idx_0 += localDW->FIR_IMUaccel_states[10 + localB->j]
      * flightControlSystem_ConstP.FIR_IMUaccel_Coefficients[localB->cff];
    localB->cff++;
    localB->j++;
  }

  localB->FIR_IMUaccel[2] = rtb_Product_pqmkptcz2s_idx_0;

  /* Sqrt: '<S34>/Sqrt' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   *  Math: '<S34>/Math Function'
   *  Sum: '<S34>/Sum of Elements'
   */
  rtb_Abs = (real32_T)sqrt((localB->sincos_o2_kq55ojr1f2[0] +
    rtb_Sum_mah4rh5nu3_idx_1) + rt_powf_snf(rtb_Product_pqmkptcz2s_idx_0, 2.0F));

  /* If: '<S34>/If' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Gain: '<S34>/Gain'
   *  Inport: '<S41>/prin'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   *  Sum: '<S34>/Sum'
   */
  if ((rtb_Abs > 9.79038F) && (rtb_Abs < 9.82962F)) {
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
      rtb_Product_pqmkptcz2s_idx_0) * 0.001F + 0.999F * rtb_Sum_mah4rh5nu3_idx_0;

    /* Gain: '<S40>/Gain2' */
    u0 = 0.101936802F * localB->FIR_IMUaccel[0];

    /* Trigonometry: '<S40>/Trigonometric Function1' */
    if (u0 > 1.0F) {
      u0 = 1.0F;
    } else {
      if (u0 < -1.0F) {
        u0 = -1.0F;
      }
    }

    /* Sum: '<S40>/Sum1' incorporates:
     *  Gain: '<S34>/Gain'
     *  Gain: '<S40>/Gain3'
     *  Gain: '<S40>/Gain4'
     *  Sum: '<S34>/Sum'
     *  Trigonometry: '<S40>/Trigonometric Function1'
     */
    localB->Merge[0] = (0.005F * localB->sincos_o2[1] +
                        localB->sincos_o2_kq55ojr1f2[1]) * 0.999F + 0.001F *
      (real32_T)asin(u0);

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    /* Update for If: '<S34>/If' */
    srUpdateBC(localDW->IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S34>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    localB->Merge[0] = 0.005F * localB->sincos_o2[1] +
      localB->sincos_o2_kq55ojr1f2[1];
    localB->Merge[1] = rtb_Sum_mah4rh5nu3_idx_0;

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */

    /* Update for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    /* Update for If: '<S34>/If' incorporates:
     *  Gain: '<S34>/Gain'
     *  Inport: '<S41>/prin'
     *  Sum: '<S34>/Sum'
     */
    srUpdateBC(localDW->IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<S34>/If Action Subsystem2' */
  }

  /* End of If: '<S34>/If' */

  /* DataTypeConversion: '<S34>/Data Type Conversion3' incorporates:
   *  Gain: '<S34>/Gain'
   *  Sum: '<S34>/Sum'
   */
  localB->DataTypeConversion3[0] = 0.005F * localB->sincos_o2[0] +
    localB->sincos_o2_kq55ojr1f2[2];
  localB->DataTypeConversion3[1] = localB->Merge[0];
  localB->DataTypeConversion3[2] = localB->Merge[1];

  /* Delay: '<S103>/MemoryX' */
  if (localDW->icLoad_gsr0jp51l1 != 0) {
    localDW->MemoryX_DSTATE_hqltbc4n3u[0] = 0.0F;
    localDW->MemoryX_DSTATE_hqltbc4n3u[1] = 0.0F;
  }

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S100>/Constant'
   *  Gain: '<S97>/Gain'
   *  Gain: '<S97>/opticalFlowErrorCorrect'
   *  Product: '<S97>/ '
   *  RelationalOperator: '<S100>/Compare'
   *  UnitDelay: '<S101>/Output'
   */
  if (localDW->Output_DSTATE < 800U) {
    rtb_Sum_mah4rh5nu3_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0];
    rtb_Sum_mah4rh5nu3_idx_1 = rtu_Sensors->VisionSensors.opticalFlow_data[1];
  } else {
    rtb_Sum_mah4rh5nu3_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[0] *
      -localB->DataTypeConversion * 1.15F;
    rtb_Sum_mah4rh5nu3_idx_1 = rtu_Sensors->VisionSensors.opticalFlow_data[1] *
      -localB->DataTypeConversion * 1.15F;
  }

  /* End of Switch: '<S97>/Switch' */
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* DiscreteFilter: '<S102>/IIRgyroz' */
    memOffset = localB->cff * 5;
    rtb_pitchrollerror = localB->inverseIMU_gain[localB->cff + 3];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_pitchrollerror -= localDW->IIRgyroz_states[memOffset + localB->j] *
        flightControlSystem_ConstP.pooled10[localB->denIdx];
      localB->denIdx++;
    }

    localDW->IIRgyroz_tmp[localB->cff] = rtb_pitchrollerror;
    rtb_pitchrollerror = 0.282124132F * localDW->IIRgyroz_tmp[localB->cff];
    localB->denIdx = 1;
    for (localB->j = 0; localB->j < 5; localB->j++) {
      rtb_pitchrollerror += localDW->IIRgyroz_states[memOffset + localB->j] *
        flightControlSystem_ConstP.pooled9[localB->denIdx];
      localB->denIdx++;
    }

    /* SampleTimeMath: '<S111>/TSamp' incorporates:
     *  DiscreteFilter: '<S102>/IIRgyroz'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_pitchrollerror *= 200.0F;

    /* DiscreteFilter: '<S102>/IIRgyroz' incorporates:
     *  Sum: '<S111>/Diff'
     *  UnitDelay: '<S111>/UD'
     */
    localB->Akxhatkk1_f5py5lpkz4[localB->cff] = rtb_pitchrollerror -
      localDW->UD_DSTATE[localB->cff];

    /* SampleTimeMath: '<S111>/TSamp'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp[localB->cff] = rtb_pitchrollerror;
  }

  /* Abs: '<S102>/Abs' incorporates:
   *  Abs: '<S102>/Abs4'
   */
  rtb_pitchrollerror = (real32_T)fabs(localB->inverseIMU_gain[3]);

  /* Abs: '<S102>/Abs1' incorporates:
   *  Abs: '<S102>/Abs5'
   */
  rtb_Abs = (real32_T)fabs(localB->inverseIMU_gain[4]);

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
  rtb_LogicalOperator3 = (((((real32_T)fabs(localB->DataTypeConversion3[1]) <=
    0.6F) && ((real32_T)fabs(localB->DataTypeConversion3[2]) <= 0.6F) &&
    (rtb_pitchrollerror <= 7.0F) && (rtb_Abs <= 7.0F) && ((real32_T)fabs
    (localB->Akxhatkk1_f5py5lpkz4[0]) <= 80.0F) && ((real32_T)fabs
    (localB->Akxhatkk1_f5py5lpkz4[1]) <= 80.0F)) || ((rtb_pitchrollerror <= 0.5F)
    && (rtb_Abs <= 0.5F))) && ((real32_T)fabs(rtb_Sum_mah4rh5nu3_idx_0 -
    localB->Reshapexhat[0]) <= 5.0F) && ((real32_T)fabs(rtb_Sum_mah4rh5nu3_idx_1
    - localB->Reshapexhat[1]) <= 5.0F) && (localB->DataTypeConversion <= -0.4F));

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
    rtb_pitchrollerror = rtb_Sum_mah4rh5nu3_idx_0 - (0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[1] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[0]);
    rtb_Abs = rtb_Sum_mah4rh5nu3_idx_1 - (0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[0] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[1]);

    /* Product: '<S166>/Product2' */
    localB->Product2_i5itdihbiv[0] = 0.0F;
    localB->Product2_i5itdihbiv[0] += 0.125465602F * rtb_pitchrollerror;
    localB->Product2_i5itdihbiv[0] += 0.0F * rtb_Abs;
    localB->Product2_i5itdihbiv[1] = 0.0F;
    localB->Product2_i5itdihbiv[1] += 0.0F * rtb_pitchrollerror;
    localB->Product2_i5itdihbiv[1] += 0.125465602F * rtb_Abs;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S166>/deltax' */
      localB->Product2_i5itdihbiv[0] = 0.0F;
      localB->Product2_i5itdihbiv[1] = 0.0F;
      localDW->EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S145>/Enabled Subsystem' */

  /* Reshape: '<S103>/Reshapexhat' incorporates:
   *  Delay: '<S103>/MemoryX'
   *  Sum: '<S145>/Add'
   */
  localB->Reshapexhat[0] = localB->Product2_i5itdihbiv[0] +
    localDW->MemoryX_DSTATE_hqltbc4n3u[0];
  localB->Reshapexhat[1] = localB->Product2_i5itdihbiv[1] +
    localDW->MemoryX_DSTATE_hqltbc4n3u[1];

  /* Trigonometry: '<S46>/sincos' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   *  Trigonometry: '<S167>/sincos'
   *  Trigonometry: '<S9>/Trigonometric Function'
   */
  rtb_pitchrollerror = (real32_T)sin(localB->DataTypeConversion3[0]);
  rtb_Abs = (real32_T)cos(localB->DataTypeConversion3[0]);
  rtb_sincos_o2_kq55ojr1f2_tmp = (real32_T)sin(localB->DataTypeConversion3[1]);
  u0 = (real32_T)cos(localB->DataTypeConversion3[1]);
  rtb_sincos_o2_kq55ojr1f2_tmp_0 = (real32_T)sin(localB->DataTypeConversion3[2]);
  rtb_sincos_o2_tmp = (real32_T)cos(localB->DataTypeConversion3[2]);

  /* Fcn: '<S46>/Fcn11' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[0] = u0 * rtb_Abs;

  /* Fcn: '<S46>/Fcn21' incorporates:
   *  Fcn: '<S46>/Fcn22'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_kq55ojr1f2_tmp_0 *
    rtb_sincos_o2_kq55ojr1f2_tmp;
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_Abs -
    rtb_sincos_o2_tmp * rtb_pitchrollerror;

  /* Fcn: '<S46>/Fcn31' incorporates:
   *  Fcn: '<S46>/Fcn32'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_tmp * rtb_sincos_o2_kq55ojr1f2_tmp;
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 * rtb_Abs +
    rtb_sincos_o2_kq55ojr1f2_tmp_0 * rtb_pitchrollerror;

  /* Fcn: '<S46>/Fcn12' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[3] = u0 * rtb_pitchrollerror;

  /* Fcn: '<S46>/Fcn22' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp * rtb_pitchrollerror
    + rtb_sincos_o2_tmp * rtb_Abs;

  /* Fcn: '<S46>/Fcn32' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_pitchrollerror - rtb_sincos_o2_kq55ojr1f2_tmp_0 * rtb_Abs;

  /* Fcn: '<S46>/Fcn13' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[6] = -rtb_sincos_o2_kq55ojr1f2_tmp;

  /* Fcn: '<S46>/Fcn23' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[7] = rtb_sincos_o2_kq55ojr1f2_tmp_0 * u0;

  /* Fcn: '<S46>/Fcn33' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[8] = rtb_sincos_o2_tmp * u0;

  /* SignalConversion: '<S35>/TmpSignal ConversionAtProduct1Inport2' incorporates:
   *  Delay: '<S6>/Delay1'
   */
  localB->unnamed_idx_0 = localDW->Delay1_DSTATE[0];
  localB->unnamed_idx_1 = localDW->Delay1_DSTATE[1];
  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* DataTypeConversion: '<S34>/Data Type Conversion1' */
    localB->DataTypeConversion1[localB->j] = localDW->
      Memory_PreviousInput[localB->j];

    /* Product: '<S35>/Product1' incorporates:
     *  SignalConversion: '<S35>/TmpSignal ConversionAtProduct1Inport2'
     */
    localB->Sum[localB->j] = localB->VectorConcatenate[localB->j + 6] *
      localB->u_ch4zj0naok + (localB->VectorConcatenate[localB->j + 3] *
      localB->unnamed_idx_1 + localB->VectorConcatenate[localB->j] *
      localB->unnamed_idx_0);
  }

  /* DataTypeConversion: '<S35>/Data Type Conversion2' */
  localB->DataTypeConversion2 = (real32_T)localB->Sum[2];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtTo WorkspaceInport1' */
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localB->SimplyIntegrateVelocity[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localB->SimplyIntegrateVelocity[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[2] =
    localB->DataTypeConversion;
  localB->TmpSignalConversionAtToWorkspaceInport1[3] =
    localB->DataTypeConversion3[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[4] =
    localB->DataTypeConversion3[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] =
    localB->DataTypeConversion3[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Reshapexhat[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Reshapexhat[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] =
    localB->DataTypeConversion2;
  localB->TmpSignalConversionAtToWorkspaceInport1[9] =
    localB->DataTypeConversion1[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[10] =
    localB->DataTypeConversion1[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[11] =
    localB->DataTypeConversion1[2];

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

  /* Trigonometry: '<S167>/sincos' */
  localDW->Memory_PreviousInput[0] = rtb_Abs;
  localDW->Memory_PreviousInput[1] = u0;
  localDW->Memory_PreviousInput[2] = rtb_sincos_o2_tmp;

  /* Fcn: '<S167>/Fcn11' */
  localB->MathFunction[0] = localDW->Memory_PreviousInput[1] *
    localDW->Memory_PreviousInput[0];

  /* Fcn: '<S167>/Fcn21' incorporates:
   *  Fcn: '<S167>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_kq55ojr1f2_tmp_0 *
    rtb_sincos_o2_kq55ojr1f2_tmp;
  localB->MathFunction[1] = rtb_VectorConcatenate_tmp *
    localDW->Memory_PreviousInput[0] - localDW->Memory_PreviousInput[2] *
    rtb_pitchrollerror;

  /* Fcn: '<S167>/Fcn31' incorporates:
   *  Fcn: '<S167>/Fcn32'
   */
  u0 = localDW->Memory_PreviousInput[2] * rtb_sincos_o2_kq55ojr1f2_tmp;
  localB->MathFunction[2] = u0 * localDW->Memory_PreviousInput[0] +
    rtb_sincos_o2_kq55ojr1f2_tmp_0 * rtb_pitchrollerror;

  /* Fcn: '<S167>/Fcn12' */
  localB->MathFunction[3] = localDW->Memory_PreviousInput[1] *
    rtb_pitchrollerror;

  /* Fcn: '<S167>/Fcn22' */
  localB->MathFunction[4] = rtb_VectorConcatenate_tmp * rtb_pitchrollerror +
    localDW->Memory_PreviousInput[2] * localDW->Memory_PreviousInput[0];

  /* Fcn: '<S167>/Fcn32' */
  localB->MathFunction[5] = u0 * rtb_pitchrollerror -
    rtb_sincos_o2_kq55ojr1f2_tmp_0 * localDW->Memory_PreviousInput[0];

  /* Fcn: '<S167>/Fcn13' */
  localB->MathFunction[6] = -rtb_sincos_o2_kq55ojr1f2_tmp;

  /* Fcn: '<S167>/Fcn23' */
  localB->MathFunction[7] = rtb_sincos_o2_kq55ojr1f2_tmp_0 *
    localDW->Memory_PreviousInput[1];

  /* Fcn: '<S167>/Fcn33' */
  localB->MathFunction[8] = localDW->Memory_PreviousInput[2] *
    localDW->Memory_PreviousInput[1];

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
  localB->Akxhatkk1_f5py5lpkz4[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
  localB->Akxhatkk1_f5py5lpkz4[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];

  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  localDW->sfEvent = flightControlSystem_CALL_EVENT;
  if (localDW->is_active_c3_flightControlSystem == 0U) {
    localDW->is_active_c3_flightControlSystem = 1U;
    localDW->is_c3_flightControlSystem = flightControlSystem_IN_Subir;
    localDW->temporalCounter_i1 = 0U;
    localB->x = 0.0F;
    localB->y = 0.0F;
    localB->z = -0.8F;
    localDW->vel = 2.1;
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
      if (localDW->temporalCounter_i1 >= (uint32_T)ceil(3.8 / localDW->vel *
           200.0)) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender1;
        localDW->temporalCounter_i1 = 0U;
        localB->z = -0.4F;
      } else {
        localB->x += (real32_T)(cos(localDW->grados * 3.1415926535897931 / 180.0)
          * (0.0005 * localDW->vel));
        localB->y += (real32_T)(sin(localDW->grados * 3.1415926535897931 / 180.0)
          * (0.0005 * localDW->vel));
      }
      break;

     case flightControlSystem_IN_Descender1:
      if (localDW->temporalCounter_i1 >= 200U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender2;
        localDW->temporalCounter_i1 = 0U;
        localB->z = -0.2F;
      } else {
        localB->z = -0.4F;
      }
      break;

     case flightControlSystem_IN_Descender2:
      if (localDW->temporalCounter_i1 >= 200U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Descender3;
        localB->z = -0.001F;
      } else {
        localB->z = -0.2F;
      }
      break;

     case flightControlSystem_IN_Descender3:
      localDW->is_c3_flightControlSystem = flightControlSystem_IN_Fin;
      break;

     case flightControlSystem_IN_Fin:
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
        localB->x += (real32_T)(0.0005 * localDW->vel);
      }
      break;

     case flightControlSystem_IN_Quieto1:
      if (rtu_VisionbasedData && (rtu_estado == 2.0)) {
        localDW->is_c3_flightControlSystem =
          flightControlSystem_IN_GiroIzquierda;
        localDW->temporalCounter_i1 = 0U;
        localDW->grados += -0.5;
        localB->yaw = localDW->grados * 3.1415926535897931 / 180.0;
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
      } else if (rtu_estado == 6.0) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Circulo;
        localDW->temporalCounter_i1 = 0U;
        localB->u_ch4zj0naok = localDW->grados * 3.1415926535897931 / 180.0;
        localB->x += (real32_T)(cos(localB->u_ch4zj0naok) * (0.0005 *
          localDW->vel));
        localB->y += (real32_T)(sin(localB->u_ch4zj0naok) * (0.0005 *
          localDW->vel));
      } else {
        localDW->actual = rtu_estado;
      }
      break;

     case flightControlSystem_IN_Subir:
      if (localDW->temporalCounter_i1 >= 600U) {
        localDW->is_c3_flightControlSystem = flightControlSystem_IN_Quieto;
        localDW->temporalCounter_i1 = 0U;
        localB->x += (real32_T)(0.0005 * localDW->vel);
      } else {
        localB->x = 0.0F;
        localB->y = 0.0F;
        localB->z = -0.8F;
        localDW->vel = 2.1;
        localB->yaw = 0.0;
        localDW->grados = 0.0;
        localDW->cen = 0.0;
        localDW->actual = 0.0;
      }
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

  /* Sum: '<S9>/Sum17' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_sincos_o2_kq55ojr1f2_tmp = localB->x - localB->SimplyIntegrateVelocity[0];
  rtb_sincos_o2_kq55ojr1f2_tmp_0 = localB->y - localB->SimplyIntegrateVelocity[1];

  /* Product: '<S9>/Product' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_VectorConcatenate_tmp = rtb_Abs * rtb_sincos_o2_kq55ojr1f2_tmp +
    rtb_pitchrollerror * rtb_sincos_o2_kq55ojr1f2_tmp_0;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  if (rtb_VectorConcatenate_tmp > 3.0F) {
    rtb_VectorConcatenate_tmp = 3.0F;
  } else {
    if (rtb_VectorConcatenate_tmp < -3.0F) {
      rtb_VectorConcatenate_tmp = -3.0F;
    }
  }

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Sum: '<S7>/Sum19'
   *  Sum: '<S9>/Sum18'
   */
  localB->pitchrollerror_lnhy3xcnpt[0] = (-0.24F * rtb_VectorConcatenate_tmp +
    0.1F * localB->Reshapexhat[0]) - localB->DataTypeConversion3[1];

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_VectorConcatenate_tmp = -rtb_pitchrollerror * rtb_sincos_o2_kq55ojr1f2_tmp
    + rtb_Abs * rtb_sincos_o2_kq55ojr1f2_tmp_0;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  if (rtb_VectorConcatenate_tmp > 3.0F) {
    rtb_VectorConcatenate_tmp = 3.0F;
  } else {
    if (rtb_VectorConcatenate_tmp < -3.0F) {
      rtb_VectorConcatenate_tmp = -3.0F;
    }
  }

  /* Sum: '<S7>/Sum19' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Sum: '<S9>/Sum18'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_VectorConcatenate_tmp = (0.24F * rtb_VectorConcatenate_tmp + -0.1F *
    localB->Reshapexhat[1]) - localB->DataTypeConversion3[2];

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  Gain: '<S9>/P_xy'
   */
  localB->pitchrollerror_lnhy3xcnpt[1] = rtb_VectorConcatenate_tmp;

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  rtb_Compare_gctmfem22b = (localDW->Output_DSTATE_kdeodyri3i < 100U);

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if ((!rtb_Compare_gctmfem22b) &&
      (localDW->DiscreteTimeIntegrator_PrevResetState == 1)) {
    localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = 0.0F;
  }

  if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = 2.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f <= -2.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = -2.0F;
    }
  }

  /* Sum: '<S11>/Sum2' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   */
  rtb_pitchrollerror = localB->z - localB->DataTypeConversion;

  /* Switch: '<S11>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S11>/w1'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_z1'
   *  Gain: '<S11>/P_z1'
   *  Gain: '<S11>/takeoff_gain1'
   *  Sum: '<S11>/Sum1'
   */
  if (rtb_Compare_gctmfem22b) {
    rtb_sincos_o2_kq55ojr1f2_tmp = -0.278113484F;
  } else {
    rtb_sincos_o2_kq55ojr1f2_tmp = (0.8F * rtb_pitchrollerror +
      localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f) - 0.5F *
      localB->DataTypeConversion2;
  }

  /* End of Switch: '<S11>/TakeoffOrControl_Switch1' */

  /* Sum: '<S11>/Sum5' incorporates:
   *  Constant: '<S11>/w1'
   */
  rtb_Abs = -0.61803F + rtb_sincos_o2_kq55ojr1f2_tmp;

  /* Saturate: '<S11>/SaturationThrust1' incorporates:
   *  Constant: '<S11>/w1'
   *  Sum: '<S11>/Sum5'
   */
  if (-0.61803F + rtb_sincos_o2_kq55ojr1f2_tmp > 1.20204329F) {
    rtb_Abs = 1.20204329F;
  } else {
    if (-0.61803F + rtb_sincos_o2_kq55ojr1f2_tmp < -1.20204329F) {
      rtb_Abs = -1.20204329F;
    }
  }

  /* End of Saturate: '<S11>/SaturationThrust1' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2' incorporates:
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
  rtb_sincos_o2_kq55ojr1f2_tmp = ((real32_T)localB->yaw -
    localB->DataTypeConversion3[0]) * 0.004F - 0.0012F *
    localB->DataTypeConversion1[2];
  rtb_sincos_o2_kq55ojr1f2_tmp_0 = (0.013F * localB->pitchrollerror_lnhy3xcnpt[0]
    + 0.01F * localDW->DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    localB->DataTypeConversion1[1];
  rtb_VectorConcatenate_tmp = (0.011F * rtb_VectorConcatenate_tmp + 0.01F *
    localDW->DiscreteTimeIntegrator_DSTATE[1]) - 0.003F *
    localB->DataTypeConversion1[0];
  for (localB->j = 0; localB->j < 4; localB->j++) {
    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/TorqueTotalThrustToThrustPerMotor'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2'
     */
    u0 =
      flightControlSystem_ConstP.TorqueTotalThrustToThrustPerMotor_Value
      [localB->j + 12] * rtb_VectorConcatenate_tmp +
      (flightControlSystem_ConstP.TorqueTotalThrustToThrustPerMotor_Value
       [localB->j + 8] * rtb_sincos_o2_kq55ojr1f2_tmp_0 +
       (flightControlSystem_ConstP.TorqueTotalThrustToThrustPerMotor_Value[localB
        ->j + 4] * rtb_sincos_o2_kq55ojr1f2_tmp +
        flightControlSystem_ConstP.TorqueTotalThrustToThrustPerMotor_Value[localB
        ->j] * rtb_Abs));

    /* Saturate: '<S12>/Saturation5' incorporates:
     *  Gain: '<S12>/ThrustToMotorCommand'
     */
    u0 *= -1530.72681F;
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else {
      if (u0 < 10.0F) {
        u0 = 10.0F;
      }
    }

    /* End of Saturate: '<S12>/Saturation5' */

    /* Gain: '<S12>/MotorDirections' */
    motors_outport[localB->j] =
      flightControlSystem_ConstP.MotorDirections_Gain[localB->j] * u0;
  }

  for (localB->j = 0; localB->j < 3; localB->j++) {
    /* Sum: '<S35>/Sum' incorporates:
     *  Constant: '<S35>/gravity'
     *  DiscreteFir: '<S37>/FIR_IMUaccel'
     *  Product: '<S35>/Product'
     */
    localB->Sum[localB->j] = (localB->VectorConcatenate[localB->j + 6] *
      rtb_Product_pqmkptcz2s_idx_0 + (localB->VectorConcatenate[localB->j + 3] *
      localB->FIR_IMUaccel[1] + localB->VectorConcatenate[localB->j] *
      localB->FIR_IMUaccel[0])) +
      flightControlSystem_ConstP.gravity_Value[localB->j];

    /* Trigonometry: '<S105>/sincos' */
    localB->sincos_o2_kq55ojr1f2[localB->j] = (real32_T)cos
      (localB->DataTypeConversion3[localB->j]);

    /* Product: '<S35>/Product' incorporates:
     *  Trigonometry: '<S105>/sincos'
     */
    localB->sincos_o2[localB->j] = (real32_T)sin(localB->
      DataTypeConversion3[localB->j]);
  }

  /* Fcn: '<S105>/Fcn11' */
  localB->VectorConcatenate[0] = localB->sincos_o2_kq55ojr1f2[1] *
    localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn21' */
  localB->VectorConcatenate[1] = localB->sincos_o2[2] * localB->sincos_o2[1] *
    localB->sincos_o2_kq55ojr1f2[0] - localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2[0];

  /* Fcn: '<S105>/Fcn31' incorporates:
   *  Fcn: '<S105>/Fcn32'
   */
  rtb_VectorConcatenate_tmp = localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2[1];
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp *
    localB->sincos_o2_kq55ojr1f2[0] + localB->sincos_o2[2] * localB->sincos_o2[0];

  /* Fcn: '<S105>/Fcn12' */
  localB->VectorConcatenate[3] = localB->sincos_o2_kq55ojr1f2[1] *
    localB->sincos_o2[0];

  /* Fcn: '<S105>/Fcn22' */
  localB->VectorConcatenate[4] = localB->sincos_o2[2] * localB->sincos_o2[1] *
    localB->sincos_o2[0] + localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp * localB->sincos_o2[0]
    - localB->sincos_o2[2] * localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->sincos_o2[1];

  /* Fcn: '<S105>/Fcn23' */
  localB->VectorConcatenate[7] = localB->sincos_o2[2] *
    localB->sincos_o2_kq55ojr1f2[1];

  /* Fcn: '<S105>/Fcn33' */
  localB->VectorConcatenate[8] = localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2_kq55ojr1f2[1];

  /* RelationalOperator: '<S104>/Compare' incorporates:
   *  Constant: '<S104>/Constant'
   */
  rtb_Compare_fdisj14o15 = (localB->DataTypeConversion <= -0.4F);

  /* Logic: '<S99>/Logical Operator' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S106>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   */
  rtb_Compare_dy3hxo2bjx = ((rtb_Sum_mah4rh5nu3_idx_0 != 0.0F) ||
    (rtb_Sum_mah4rh5nu3_idx_1 != 0.0F));

  /* Sum: '<S99>/Add' incorporates:
   *  Product: '<S99>/Product1'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->rtb_FIR_IMUaccel_cl54gopm0x[localB->j] = localB->FIR_IMUaccel
      [localB->j] - ((localB->VectorConcatenate[localB->j + 3] * 0.0 +
                      localB->VectorConcatenate[localB->j] * 0.0) +
                     localB->VectorConcatenate[localB->j + 6] * -9.81);
  }

  /* End of Sum: '<S99>/Add' */

  /* Product: '<S99>/Product' incorporates:
   *  Gain: '<S99>/gainaccinput'
   */
  rtb_Product_pqmkptcz2s_idx_0 = (real32_T)(0.2 *
    localB->rtb_FIR_IMUaccel_cl54gopm0x[0]) * (real32_T)rtb_Compare_dy3hxo2bjx *
    (real32_T)rtb_Compare_fdisj14o15;
  rtb_Abs = (real32_T)(0.2 * localB->rtb_FIR_IMUaccel_cl54gopm0x[1]) * (real32_T)
    rtb_Compare_dy3hxo2bjx * (real32_T)rtb_Compare_fdisj14o15;

  /* Outputs for Enabled SubSystem: '<S140>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S165>/Enable'
   */
  if (rtb_LogicalOperator3) {
    if (!localDW->MeasurementUpdate_MODE) {
      localDW->MeasurementUpdate_MODE = true;
    }

    /* Product: '<S165>/D[k]*u[k]' */
    rtb_sincos_o2_kq55ojr1f2_tmp = 0.0F * rtb_Product_pqmkptcz2s_idx_0 + 0.0F *
      rtb_Abs;

    /* Sum: '<S165>/Sum' incorporates:
     *  Constant: '<S103>/C'
     *  Delay: '<S103>/MemoryX'
     *  Product: '<S165>/C[k]*xhat[k|k-1]'
     *  Product: '<S165>/D[k]*u[k]'
     *  Sum: '<S165>/Add1'
     */
    rtb_Sum_mah4rh5nu3_idx_0 -= (0.0F * localDW->MemoryX_DSTATE_hqltbc4n3u[1] +
      localDW->MemoryX_DSTATE_hqltbc4n3u[0]) + rtb_sincos_o2_kq55ojr1f2_tmp;
    rtb_Sum_mah4rh5nu3_idx_1 -= (0.0F * localDW->MemoryX_DSTATE_hqltbc4n3u[0] +
      localDW->MemoryX_DSTATE_hqltbc4n3u[1]) + rtb_sincos_o2_kq55ojr1f2_tmp;

    /* Product: '<S165>/Product3' */
    localB->Product3_gd3igxsc2c[0] = 0.0F;
    localB->Product3_gd3igxsc2c[0] += 0.125465602F * rtb_Sum_mah4rh5nu3_idx_0;
    localB->Product3_gd3igxsc2c[0] += -0.0F * rtb_Sum_mah4rh5nu3_idx_1;
    localB->Product3_gd3igxsc2c[1] = 0.0F;
    localB->Product3_gd3igxsc2c[1] += 0.0F * rtb_Sum_mah4rh5nu3_idx_0;
    localB->Product3_gd3igxsc2c[1] += 0.125465602F * rtb_Sum_mah4rh5nu3_idx_1;
    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC);
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3_gd3igxsc2c[0] = 0.0F;
      localB->Product3_gd3igxsc2c[1] = 0.0F;
      localDW->MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S140>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S65>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S90>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->MeasurementUpdate_MODE_gfpthrsdrn) {
      localDW->MeasurementUpdate_MODE_gfpthrsdrn = true;
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Constant: '<S44>/C'
     *  Constant: '<S44>/D'
     *  Delay: '<S44>/MemoryX'
     *  Gain: '<S35>/invertzaxisGain'
     *  Product: '<S90>/C[k]*xhat[k|k-1]'
     *  Product: '<S90>/D[k]*u[k]'
     *  Sum: '<S90>/Add1'
     */
    localB->u_ch4zj0naok = -(real_T)localB->altitude - ((0.0 *
      localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]) + 0.0 *
      localB->Sum[2]);

    /* Product: '<S90>/Product3' */
    localB->Product3[0] = 0.026590304322229058 * localB->u_ch4zj0naok;
    localB->Product3[1] = 0.06977673607149236 * localB->u_ch4zj0naok;
    srUpdateBC(localDW->MeasurementUpdate_SubsysRanBC_cfrhkmpxp0);
  } else {
    if (localDW->MeasurementUpdate_MODE_gfpthrsdrn) {
      /* Disable for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3[0] = 0.0;
      localB->Product3[1] = 0.0;
      localDW->MeasurementUpdate_MODE_gfpthrsdrn = false;
    }
  }

  /* End of Outputs for SubSystem: '<S65>/MeasurementUpdate' */

  /* Update for UnitDelay: '<S14>/Output' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Sum: '<S15>/FixPt Sum1'
   *  Switch: '<S16>/FixPt Switch'
   */
  localDW->Output_DSTATE_kdeodyri3i++;

  /* RelationalOperator: '<S4>/GreaterThan' incorporates:
   *  UnitDelay: '<S25>/Output'
   */
  rtb_nicemeasurementornewupdateneeded = (localDW->Output_DSTATE_aloeis45eb >
    600U);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/ '
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    localB->u_ch4zj0naok = rtu_Sensors->VisionSensors.opticalFlow_data[2];
    localB->unnamed_idx_0 = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->u_ch4zj0naok = 0.0;
    localB->unnamed_idx_0 = 0.0;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S18>/Compare'
   */
  localDW->DelayOneStep_DSTATE = (real_T)(localB->unnamed_idx_0 == -1.0) *
    localDW->DelayOneStep_DSTATE + (real_T)(localB->u_ch4zj0naok == -1.0);

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
  if ((((real32_T)fabs(localB->SimplyIntegrateVelocity[0]) > 10.0F) ||
       ((real32_T)fabs(localB->SimplyIntegrateVelocity[1]) > 10.0F)) > 0) {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion: '<S26>/OutportBufferForOut1' incorporates:
     *  Constant: '<S26>/Constant'
     */
    flag_outport = 1U;

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */

    /* Update for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Update for If: '<S4>/If' */
    srUpdateBC(localDW->Geofencingerror_SubsysRanBC);

    /* End of Update for SubSystem: '<S4>/Geofencing error' */
  } else if (((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
                0.01F) && ((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                 localB->Reshapexhat[0]) > 6.0F)) || (((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[1] -
                 localB->Reshapexhat[1]) > 6.0F) && ((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[1]) > 0.01F))) > 0)
  {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    flightControlSystem_estimatorOpticalflowerror(&flag_outport);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localDW->DelayOneStep_DSTATE > 50.0) {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    flightControlSystem_estimatorOpticalflowerror(&flag_outport);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_nicemeasurementornewupdateneeded) {
      /* Switch: '<S4>/         ' incorporates:
       *  DiscreteFilter: '<S45>/pressureFilter_IIR'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      localB->numAccum = localB->DataTypeConversion - localB->numAccum;
    } else {
      /* Switch: '<S4>/         ' incorporates:
       *  Constant: '<S4>/    '
       */
      localB->numAccum = 0.0F;
    }

    if ((real32_T)fabs(localB->numAccum) > 0.5F) {
      /* Outputs for IfAction SubSystem: '<S4>/Ultrasound improper' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      flightControlSystem_Ultrasoundimproper(&flag_outport);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      flightControlSystem_Ultrasoundimproper(&flag_outport);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* Product: '<S98>/Product' incorporates:
   *  SignalConversion: '<S98>/TmpSignal ConversionAtProductInport2'
   */
  for (localB->j = 0; localB->j < 3; localB->j++) {
    localB->sincos_o2_kq55ojr1f2[localB->j] = localB->MathFunction[localB->j + 6]
      * localB->DataTypeConversion2 + (localB->MathFunction[localB->j + 3] *
      localB->Reshapexhat[1] + localB->MathFunction[localB->j] *
      localB->Reshapexhat[0]);
  }

  /* End of Product: '<S98>/Product' */

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = 1;

  /* Update for Delay: '<S44>/MemoryX' */
  localDW->icLoad = 0U;

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] += 0.005F *
    localB->sincos_o2_kq55ojr1f2[0];
  localDW->SimplyIntegrateVelocity_DSTATE[1] += 0.005F *
    localB->sincos_o2_kq55ojr1f2[1];

  /* Product: '<S65>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S44>/A'
   *  Delay: '<S44>/MemoryX'
   */
  localB->unnamed_idx_0 = 0.0 * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1];

  /* Update for Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S44>/A'
   *  Constant: '<S44>/B'
   *  Product: '<S65>/A[k]*xhat[k|k-1]'
   *  Product: '<S65>/B[k]*u[k]'
   *  Sum: '<S65>/Add'
   */
  localDW->MemoryX_DSTATE[0] = ((0.005 * localDW->MemoryX_DSTATE[1] +
    localDW->MemoryX_DSTATE[0]) + 0.0 * localB->Sum[2]) + localB->Product3[0];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for Delay: '<S44>/MemoryX' incorporates:
   *  Constant: '<S44>/B'
   *  Product: '<S65>/B[k]*u[k]'
   *  Sum: '<S65>/Add'
   */
  localDW->MemoryX_DSTATE[1] = (0.005 * localB->Sum[2] + localB->unnamed_idx_0)
    + localB->Product3[1];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];
  localDW->pressureFilter_IIR_states[0] = localB->denAccum_kkiq3xxxve;

  /* Update for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = localDW->soonarFilter_IIR_states[1];
  localDW->soonarFilter_IIR_states[1] = localDW->soonarFilter_IIR_states[0];
  localDW->soonarFilter_IIR_states[0] = localB->denAccum;

  /* Update for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[0] = localB->DataTypeConversion3[0];
  localDW->Memory_PreviousInput[1] = localB->DataTypeConversion3[1];
  localDW->Memory_PreviousInput[2] = localB->DataTypeConversion3[2];

  /* Update for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localB->denAccum_cxarnvbvui;

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
  localDW->icLoad_gsr0jp51l1 = 0U;

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[0] = 0.005F * rtb_Product_pqmkptcz2s_idx_0 + 0.0F * rtb_Abs;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[0] = 0.0F * localDW->MemoryX_DSTATE_hqltbc4n3u[1] +
    localDW->MemoryX_DSTATE_hqltbc4n3u[0];

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[1] = 0.0F * rtb_Product_pqmkptcz2s_idx_0;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[1] = 0.0F * localDW->MemoryX_DSTATE_hqltbc4n3u[0];

  /* Product: '<S140>/B[k]*u[k]' incorporates:
   *  Constant: '<S103>/B'
   */
  localB->fv0[1] += 0.005F * rtb_Abs;

  /* Product: '<S140>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S103>/A'
   *  Delay: '<S103>/MemoryX'
   */
  localB->fv1[1] += localDW->MemoryX_DSTATE_hqltbc4n3u[1];

  /* Update for UnitDelay: '<S101>/Output' incorporates:
   *  Constant: '<S109>/FixPt Constant'
   *  Sum: '<S109>/FixPt Sum1'
   */
  localDW->Output_DSTATE++;
  for (localB->cff = 0; localB->cff < 2; localB->cff++) {
    /* Update for Delay: '<S103>/MemoryX' incorporates:
     *  Sum: '<S140>/Add'
     */
    localDW->MemoryX_DSTATE_hqltbc4n3u[localB->cff] = (localB->fv0[localB->cff]
      + localB->fv1[localB->cff]) + localB->Product3_gd3igxsc2c[localB->cff];

    /* Update for DiscreteFilter: '<S102>/IIRgyroz' */
    memOffset = localB->cff * 5;
    localDW->IIRgyroz_states[memOffset + 4] = localDW->IIRgyroz_states[memOffset
      + 3];
    localDW->IIRgyroz_states[memOffset + 3] = localDW->IIRgyroz_states[memOffset
      + 2];
    localDW->IIRgyroz_states[memOffset + 2] = localDW->IIRgyroz_states[memOffset
      + 1];
    localDW->IIRgyroz_states[memOffset + 1] = localDW->IIRgyroz_states[memOffset];
    localDW->IIRgyroz_states[memOffset] = localDW->IIRgyroz_tmp[localB->cff];

    /* Update for UnitDelay: '<S111>/UD' */
    localDW->UD_DSTATE[localB->cff] = localB->TSamp[localB->cff];

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE[localB->cff] = localB->Reshapexhat[localB->cff];

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
     *  Delay: '<S7>/Delay'
     *  Gain: '<S7>/antiWU_Gain'
     *  Sum: '<S7>/Add'
     */
    localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] +=
      (localB->pitchrollerror_lnhy3xcnpt[localB->cff] - 0.001F *
       localDW->Delay_DSTATE_ijwdhdrv0s[localB->cff]) * 0.005F;
    if (localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] >= 2.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] = 2.0F;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] <= -2.0F) {
        localDW->DiscreteTimeIntegrator_DSTATE[localB->cff] = -2.0F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  }

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S11>/I_pr'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f += 0.24F *
    rtb_pitchrollerror * 0.005F;
  if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = 2.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f <= -2.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = -2.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    rtb_Compare_gctmfem22b;

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

  /* Update for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_ijwdhdrv0s[0] = localB->Akxhatkk1_f5py5lpkz4[0];
  localDW->Delay_DSTATE_ijwdhdrv0s[1] = localB->Akxhatkk1_f5py5lpkz4[1];

  /* Update for UnitDelay: '<S25>/Output' incorporates:
   *  Constant: '<S31>/FixPt Constant'
   *  Sum: '<S31>/FixPt Sum1'
   */
  localDW->Output_DSTATE_aloeis45eb++;
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
static real_T flightControlSystem_sum_erraza0c0y(const real_T x[32])
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
  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.Geofencingerror_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.estimatorOpticalflowerror_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Ultrasoundimproper_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_cfrhkmpxp0);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_bgcmjfg1p0);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC);

  /* RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_B.RateTransition =
    flightControlSystem_DW.RateTransition_Buffer0;

  /* RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_B.RateTransition1 =
    flightControlSystem_DW.RateTransition1_Buffer[flightControlSystem_DW.RateTransition1_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<Root>/Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_ControlSystem(flightControlSystem_M, &sensor_inport,
    flightControlSystem_B.RateTransition, flightControlSystem_B.RateTransition1,
    &flightControlSystem_B.ControlSystem, &flightControlSystem_DW.ControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Control System' */

  /* Outport: '<Root>/Actuators' */
  flightControlSystem_Y.Actuators[0] = motors_outport[0];
  flightControlSystem_Y.Actuators[1] = motors_outport[1];
  flightControlSystem_Y.Actuators[2] = motors_outport[2];
  flightControlSystem_Y.Actuators[3] = motors_outport[3];

  /* Outport: '<Root>/Flag' */
  flightControlSystem_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(flightControlSystem_M->rtwLogInfo,
                      (&flightControlSystem_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)flightControlSystem_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(flightControlSystem_M)!=-1) &&
        !((rtmGetTFinal(flightControlSystem_M)-
           flightControlSystem_M->Timing.taskTime0) >
          flightControlSystem_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(flightControlSystem_M, "Simulation finished");
    }

    if (rtmGetStopRequested(flightControlSystem_M)) {
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
  int32_T caso;
  int32_T frentesuperior;
  int32_T frente;
  int32_T lateraliz;
  int32_T lateralder;
  int32_T alertacentro;
  uint16_T tmp;
  int32_T i;
  real_T tc_idx_10;
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
  for (caso = 0; caso < 19200; caso++) {
    flightControlSystem_B.AND[caso] = ((flightControlSystem_B.imageBuff_1[caso] >
      100) && (flightControlSystem_B.imageBuff_2[caso] < 100) &&
      (flightControlSystem_B.imageBuff_3[caso] < 100));
  }

  /* End of Logic: '<S2>/AND' */

  /* MATLAB Function: '<S2>/Deteccion de lineas verticales' incorporates:
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   */
  frentesuperior = 0;
  frente = 0;
  lateraliz = 0;
  lateralder = 0;
  alertacentro = 0;
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[120 * caso + i];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv8);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(32 + caso) * 120 + i];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv7);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(64 + caso) * 120 + i];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv6);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(96 + caso) * 120 + i];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv5);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(128 + caso) * 120 + i];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv4);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(120 * caso + i) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv3);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[((32 + caso) * 120 + i) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  flightControlSystem_B.tc_idx_4 = flightControlSystem_sum_erraza0c0y
    (flightControlSystem_B.dv2);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[((64 + caso) * 120 + i) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  flightControlSystem_B.tc_idx_7 = flightControlSystem_sum_erraza0c0y
    (flightControlSystem_B.dv2);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[((96 + caso) * 120 + i) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  tc_idx_10 = flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv2);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[((128 + caso) * 120 + i) + 24];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv2);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[(120 * caso + i) + 48];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv1);
  for (caso = 0; caso < 32; caso++) {
    for (i = 0; i < 24; i++) {
      flightControlSystem_B.rtb_AND_mbvzarwird[i + 24 * caso] =
        flightControlSystem_B.AND[((128 + caso) * 120 + i) + 48];
    }
  }

  flightControlSystem_sum(flightControlSystem_B.rtb_AND_mbvzarwird,
    flightControlSystem_B.dv0);
  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv7) > 150.0) {
    frentesuperior = 1;
  }

  if (flightControlSystem_B.tc_idx_4 > 150.0) {
    frente = 1;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv8) > 150.0) {
    lateraliz = 1;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv4) > 150.0) {
    lateralder = 1;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv6) > 150.0) {
    frentesuperior++;
  }

  if (flightControlSystem_B.tc_idx_7 > 150.0) {
    frente++;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv3) > 150.0) {
    lateraliz++;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv2) > 150.0) {
    lateralder++;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv5) > 150.0) {
    frentesuperior++;
  }

  if (tc_idx_10 > 150.0) {
    frente++;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv1) > 150.0) {
    lateraliz++;
  }

  if (flightControlSystem_sum_erraza0c0y(flightControlSystem_B.dv0) > 150.0) {
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

  if ((frente == 0) && (frentesuperior > 0) && (lateraliz == 0) && (lateralder ==
       0)) {
    alertacentro = 1;
  }

  if ((frentesuperior > 0) && (alertacentro == 0)) {
    if (flightControlSystem_B.tc_idx_4 - 100.0 > flightControlSystem_B.tc_idx_7)
    {
      caso = 4;
    } else if (tc_idx_10 - 100.0 > flightControlSystem_B.tc_idx_7) {
      caso = 5;
    } else {
      caso = 1;
    }
  } else if ((frentesuperior == 0) && (lateraliz > 0) && (alertacentro == 0)) {
    caso = 2;
  } else if ((frentesuperior == 0) && (lateralder > 0) && (alertacentro == 0)) {
    caso = 3;
  } else if ((frentesuperior == 0) && (flightControlSystem_B.alerta == 1.0) &&
             (alertacentro == 0)) {
    caso = 2;
  } else if ((frentesuperior == 0) && (flightControlSystem_B.alerta == 2.0) &&
             (alertacentro == 0)) {
    caso = 3;
  } else if (alertacentro == 1) {
    caso = 6;
  } else {
    caso = 0;
  }

  if ((flightControlSystem_B.estado == 0.0) || (flightControlSystem_B.estado ==
       1.0) || (flightControlSystem_B.estado == 4.0) ||
      (flightControlSystem_B.estado == 5.0)) {
    flightControlSystem_B.estado = caso;
  } else {
    flightControlSystem_B.estado = 0.0;
  }

  flightControlSystem_B.caso = caso;

  /* Sum: '<S2>/Sum of white pixels' */
  tmp = 0U;
  for (caso = 0; caso < 19200; caso++) {
    tmp = (uint16_T)((uint32_T)tmp + flightControlSystem_B.AND[caso]);
  }

  /* RelationalOperator: '<S174>/Compare' incorporates:
   *  Constant: '<S174>/Constant'
   *  Sum: '<S2>/Sum of white pixels'
   */
  flightControlSystem_B.Compare = (tmp > 1400);

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  MATLAB Function: '<S2>/Deteccion de lineas verticales'
   */
  flightControlSystem_DW.Delay1_DSTATE = flightControlSystem_B.alerta;

  /* End of Outputs for SubSystem: '<Root>/Image Processing System' */

  /* Update for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 = flightControlSystem_B.Compare;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_DW.RateTransition1_Buffer[flightControlSystem_DW.RateTransition1_ActiveBufIdx
    == 0] = flightControlSystem_B.estado;
  flightControlSystem_DW.RateTransition1_ActiveBufIdx = (int8_T)
    (flightControlSystem_DW.RateTransition1_ActiveBufIdx == 0);
  rtExtModeUpload(1, (real_T)(((flightControlSystem_M->Timing.clockTick1+
    flightControlSystem_M->Timing.clockTickH1* 4294967296.0)) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  flightControlSystem_M->Timing.clockTick1++;
  if (!flightControlSystem_M->Timing.clockTick1) {
    flightControlSystem_M->Timing.clockTickH1++;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void flightControlSystem_step(int_T tid)
{
  switch (tid) {
   case 0 :
    flightControlSystem_step0();
    break;

   case 1 :
    flightControlSystem_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)flightControlSystem_M, 0,
                sizeof(RT_MODEL_flightControlSystem_T));
  (flightControlSystem_M)->Timing.TaskCounters.cLimit[0] = 1;
  (flightControlSystem_M)->Timing.TaskCounters.cLimit[1] = 40;
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

  /* External mode info */
  flightControlSystem_M->Sizes.checksums[0] = (3980205875U);
  flightControlSystem_M->Sizes.checksums[1] = (2391229496U);
  flightControlSystem_M->Sizes.checksums[2] = (1599075989U);
  flightControlSystem_M->Sizes.checksums[3] = (1244393035U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    flightControlSystem_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Geofencingerror_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Noopticalflow.estimatorOpticalflowerror_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Normalcondition.Ultrasoundimproper_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Ultrasoundimproper_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.estimatorOpticalflowerror_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.IfActionSubsystem2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_cfrhkmpxp0;
    systemRan[14] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_bgcmjfg1p0;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(flightControlSystem_M->extModeInfo,
      &flightControlSystem_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(flightControlSystem_M->extModeInfo,
                        flightControlSystem_M->Sizes.checksums);
    rteiSetTPtr(flightControlSystem_M->extModeInfo, rtmGetTPtr
                (flightControlSystem_M));
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

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    flightControlSystem_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(flightControlSystem_M->rtwLogInfo, 0.0,
    rtmGetTFinal(flightControlSystem_M), flightControlSystem_M->Timing.stepSize0,
    (&rtmGetErrorStatus(flightControlSystem_M)));

  /* SetupRuntimeResources for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_SetupRTR(flightControlSystem_M,
    &flightControlSystem_DW.ControlSystem);

  /* End of SetupRuntimeResources for SubSystem: '<Root>/Control System' */

  /* Start for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_B.RateTransition = false;

  /* Start for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_B.RateTransition1 = 0.0;

  /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_DW.obj.isInitialized = 0;
  flightControlSystem_DW.objisempty = true;
  flightControlSystem_DW.obj.isInitialized = 1;

  /* End of Start for SubSystem: '<Root>/Image Processing System' */

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_DW.RateTransition_Buffer0 = false;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_DW.RateTransition1_Buffer[0] = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Init(&flightControlSystem_B.ControlSystem,
    &flightControlSystem_DW.ControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightControlSystem_B.estado = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  flightControlSystem_DW.Delay1_DSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
}

/* Model terminate function */
void flightControlSystem_terminate(void)
{
  /* (no terminate code required) */
}
