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
 * C source code generated on : Thu Nov 14 09:41:30 2019
 *
 * Target selection: asap2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "flightControlSystem.h"
#include "flightControlSystem_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<S5>/Chart' */
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
real32_T motors_outport[4];            /* '<Root>/Control System' */
uint8_T flag_outport;                  /* '<Root>/Control System' */

/* Block signals (default storage) */
B_flightControlSystem_T flightControlSystem_rtB;

/* Block states (default storage) */
DW_flightControlSystem_T flightControlSystem_rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

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

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[1] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = 0.0;

  /* InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  for (i = 0; i < 5; i++) {
    localDW->IIR_IMUgyro_r_states[i] = 0.0F;
  }

  /* End of InitializeConditions for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[0] = 0.0F;
  localDW->Memory_PreviousInput[1] = 0.0F;
  localDW->Memory_PreviousInput[2] = 0.0F;

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
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c3_flightControlSystem = 0U;
  localDW->is_c3_flightControlSystem = flightControlSystem_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for UnitDelay: '<S111>/UD' */
  localDW->UD_DSTATE[0] = 0.0F;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  localDW->Delay_DSTATE[0] = 0.0F;

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
  localDW->Delay_DSTATE[1] = 0.0F;

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
  localB->Merge_mkzjcaq3mk = 0U;
}

/* Start for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Start
  (DW_ControlSystem_flightControlSystem_T *localDW)
{
  /* Start for Enabled SubSystem: '<S70>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE_n2f2djip0m = false;

  /* End of Start for SubSystem: '<S70>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S145>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S145>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S140>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S140>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S65>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE_nji240zmrw = false;

  /* End of Start for SubSystem: '<S65>/MeasurementUpdate' */
}

/* Outputs for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem(const SensorsBus *rtu_Sensors, boolean_T
  rtu_VisionbasedData, real_T rtu_estado, B_ControlSystem_flightControlSystem_T *
  localB, DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T j;
  int32_T denIdx;
  real32_T acc1;
  int32_T cff;
  int32_T memOffset;
  boolean_T rtb_nicemeasurementornewupdateneeded;
  real32_T rtb_SaturationThrust1;
  boolean_T rtb_Compare_fdisj14o15;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_Compare_c551j053yo;
  real32_T rtb_TrigonometricFunction_o1;
  real32_T u0;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_sincos_o2_idx_1_tmp;
  real32_T rtb_sincos_o2_kq55ojr1f2_tmp;
  real32_T rtb_sincos_o2_idx_2_tmp;

  /* DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  if (localDW->SimplyIntegrateVelocity_PrevResetState <= 0) {
    localDW->SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    localDW->SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

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

  /* DiscreteFilter: '<S45>/pressureFilter_IIR' incorporates:
   *  Gain: '<S35>/prsToAltGain'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector6_at_outport_0'
   *  Sum: '<S37>/Sum2'
   */
  localDW->pressureFilter_IIR_tmp =
    (((rtu_Sensors->HALSensors.HAL_pressure_SI.pressure -
       rtu_Sensors->SensorCalibration[6]) * 0.0832137167F - -2.93717074F *
      localDW->pressureFilter_IIR_states[0]) - 2.87629962F *
     localDW->pressureFilter_IIR_states[1]) - -0.939098954F *
    localDW->pressureFilter_IIR_states[2];
  localB->numAccum = ((3.75683794E-6F * localDW->pressureFilter_IIR_tmp +
                       1.12705138E-5F * localDW->pressureFilter_IIR_states[0]) +
                      1.12705138E-5F * localDW->pressureFilter_IIR_states[1]) +
    3.75683794E-6F * localDW->pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S45>/soonarFilter_IIR' incorporates:
   *  Gain: '<S35>/invertzaxisGain'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
   */
  localDW->soonarFilter_IIR_tmp = ((-(real_T)
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude - -2.9371707284498907 *
    localDW->soonarFilter_IIR_states[0]) - 2.8762997234793319 *
    localDW->soonarFilter_IIR_states[1]) - -0.939098940325283 *
    localDW->soonarFilter_IIR_states[2];

  /* Saturate: '<S45>/SaturationSonar' incorporates:
   *  Gain: '<S35>/invertzaxisGain'
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
   */
  if (-(real_T)rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude >= -0.44) {
    localB->u_ch4zj0naok = -0.44;
  } else {
    localB->u_ch4zj0naok = -(real_T)
      rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;
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
   *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
   *  Sum: '<S45>/Add'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  rtb_nicemeasurementornewupdateneeded = ((fabs(localDW->Delay2_DSTATE -
    localB->u_ch4zj0naok) <= 0.1) && (-(real_T)
    rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude < -0.44) && ((!(fabs
    (localB->numAccum - localDW->Delay2_DSTATE) >= 0.8)) || (!(fabs
    ((((3.7568380197861018E-6 * localDW->soonarFilter_IIR_tmp +
        1.1270514059358305E-5 * localDW->soonarFilter_IIR_states[0]) +
       1.1270514059358305E-5 * localDW->soonarFilter_IIR_states[1]) +
      3.7568380197861018E-6 * localDW->soonarFilter_IIR_states[2]) -
     localDW->Delay2_DSTATE) >= 0.4))));

  /* Outputs for Enabled SubSystem: '<S70>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S91>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->EnabledSubsystem_MODE_n2f2djip0m) {
      localDW->EnabledSubsystem_MODE_n2f2djip0m = true;
    }

    /* Sum: '<S91>/Add1' incorporates:
     *  Constant: '<S44>/C'
     *  Delay: '<S44>/MemoryX'
     *  Gain: '<S35>/invertzaxisGain'
     *  Product: '<S91>/Product'
     *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
     */
    localB->u_ch4zj0naok = -(real_T)
      rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude - (0.0 *
      localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]);

    /* Product: '<S91>/Product2' */
    localB->Product2[0] = 0.02624142064187163 * localB->u_ch4zj0naok;
    localB->Product2[1] = 0.0697767360714917 * localB->u_ch4zj0naok;
  } else {
    if (localDW->EnabledSubsystem_MODE_n2f2djip0m) {
      /* Disable for Outport: '<S91>/deltax' */
      localB->Product2[0] = 0.0;
      localB->Product2[1] = 0.0;
      localDW->EnabledSubsystem_MODE_n2f2djip0m = false;
    }
  }

  /* End of Outputs for SubSystem: '<S70>/Enabled Subsystem' */

  /* Sum: '<S70>/Add' incorporates:
   *  Delay: '<S44>/MemoryX'
   */
  localB->Add[0] = localB->Product2[0] + localDW->MemoryX_DSTATE[0];
  localB->Add[1] = localB->Product2[1] + localDW->MemoryX_DSTATE[1];

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
  localDW->IIR_IMUgyro_r_tmp = localB->inverseIMU_gain[5];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    localDW->IIR_IMUgyro_r_tmp -= flightControlSystem_rtConstP.pooled10[denIdx] *
      localDW->IIR_IMUgyro_r_states[j];
    denIdx++;
  }

  localB->numAccum_cxarnvbvui = 0.282124132F * localDW->IIR_IMUgyro_r_tmp;
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    localB->numAccum_cxarnvbvui += flightControlSystem_rtConstP.pooled9[denIdx] *
      localDW->IIR_IMUgyro_r_states[j];
    denIdx++;
  }

  /* Trigonometry: '<S42>/Trigonometric Function' incorporates:
   *  Memory: '<S34>/Memory'
   *  SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  localB->Product_m2bcxc3hq4[0] = (real32_T)sin(localDW->Memory_PreviousInput[2]);
  localB->sincos_o2_kq55ojr1f2[0] = (real32_T)cos(localDW->Memory_PreviousInput
    [2]);
  localB->Product_m2bcxc3hq4[1] = (real32_T)sin(localDW->Memory_PreviousInput[1]);
  localB->sincos_o2_kq55ojr1f2[1] = (real32_T)cos(localDW->Memory_PreviousInput
    [1]);

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[0] = 0.0F;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Constant: '<S42>/Constant'
   */
  localB->VectorConcatenate[1] = 0.0F;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn3' */
  localB->VectorConcatenate[2] = localB->sincos_o2_kq55ojr1f2[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn4' */
  localB->VectorConcatenate[3] = localB->Product_m2bcxc3hq4[0];

  /* Product: '<S42>/Product1' */
  localB->VectorConcatenate[4] = localB->sincos_o2_kq55ojr1f2[0] *
    localB->sincos_o2_kq55ojr1f2[1];

  /* Product: '<S42>/Product3' */
  localB->VectorConcatenate[5] = localB->Product_m2bcxc3hq4[0] *
    localB->Product_m2bcxc3hq4[1];

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn7' */
  localB->VectorConcatenate[6] = localB->sincos_o2_kq55ojr1f2[0];

  /* Product: '<S42>/Product2' incorporates:
   *  Gain: '<S42>/Gain'
   */
  localB->VectorConcatenate[7] = localB->sincos_o2_kq55ojr1f2[1] *
    -localB->Product_m2bcxc3hq4[0];

  /* Product: '<S42>/Product4' */
  localB->VectorConcatenate[8] = localB->sincos_o2_kq55ojr1f2[0] *
    localB->Product_m2bcxc3hq4[1];

  /* Product: '<S42>/Divide' */
  for (j = 0; j < 9; j++) {
    localB->VectorConcatenate[j] /= localB->sincos_o2_kq55ojr1f2[1];
  }

  /* End of Product: '<S42>/Divide' */

  /* Product: '<S34>/Product' incorporates:
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  SignalConversion: '<S34>/TmpSignal ConversionAtProductInport2'
   */
  for (j = 0; j < 3; j++) {
    localB->Product_m2bcxc3hq4[j] = localB->VectorConcatenate[j + 6] *
      localB->numAccum_cxarnvbvui + (localB->VectorConcatenate[j + 3] *
      localB->inverseIMU_gain[4] + localB->VectorConcatenate[j] *
      localB->inverseIMU_gain[3]);
  }

  /* End of Product: '<S34>/Product' */

  /* Sum: '<S34>/Sum' incorporates:
   *  Gain: '<S34>/Gain'
   *  Memory: '<S34>/Memory'
   *  SignalConversion: '<S42>/TmpSignal ConversionAtTrigonometric FunctionInport1'
   */
  localB->Sum_mah4rh5nu3[0] = 0.005F * localB->Product_m2bcxc3hq4[2] +
    localDW->Memory_PreviousInput[2];
  localB->Sum_mah4rh5nu3[1] = 0.005F * localB->Product_m2bcxc3hq4[1] +
    localDW->Memory_PreviousInput[1];
  localB->Sum_mah4rh5nu3[2] = 0.005F * localB->Product_m2bcxc3hq4[0] +
    localDW->Memory_PreviousInput[0];

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  acc1 = localB->inverseIMU_gain[0] * 0.0264077242F;
  cff = 1;
  for (j = localDW->FIR_IMUaccel_circBuf; j < 5; j++) {
    acc1 += localDW->FIR_IMUaccel_states[j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < localDW->FIR_IMUaccel_circBuf; j++) {
    acc1 += localDW->FIR_IMUaccel_states[j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  localB->FIR_IMUaccel[0] = acc1;

  /* Math: '<S34>/Math Function' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  localB->sincos_o2_kq55ojr1f2[0] = rt_powf_snf(acc1, 2.0F);

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  acc1 = localB->inverseIMU_gain[1] * 0.0264077242F;
  cff = 1;
  for (j = localDW->FIR_IMUaccel_circBuf; j < 5; j++) {
    acc1 += localDW->FIR_IMUaccel_states[5 + j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < localDW->FIR_IMUaccel_circBuf; j++) {
    acc1 += localDW->FIR_IMUaccel_states[5 + j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  localB->FIR_IMUaccel[1] = acc1;

  /* Math: '<S34>/Math Function' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   */
  rtb_TrigonometricFunction_o1 = rt_powf_snf(acc1, 2.0F);

  /* DiscreteFir: '<S37>/FIR_IMUaccel' */
  acc1 = localB->inverseIMU_gain[2] * 0.0264077242F;
  cff = 1;
  for (j = localDW->FIR_IMUaccel_circBuf; j < 5; j++) {
    acc1 += localDW->FIR_IMUaccel_states[10 + j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (j = 0; j < localDW->FIR_IMUaccel_circBuf; j++) {
    acc1 += localDW->FIR_IMUaccel_states[10 + j] *
      flightControlSystem_rtConstP.FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  localB->FIR_IMUaccel[2] = acc1;

  /* Sqrt: '<S34>/Sqrt' incorporates:
   *  DiscreteFir: '<S37>/FIR_IMUaccel'
   *  Math: '<S34>/Math Function'
   *  Sum: '<S34>/Sum of Elements'
   */
  rtb_SaturationThrust1 = (real32_T)sqrt((localB->sincos_o2_kq55ojr1f2[0] +
    rtb_TrigonometricFunction_o1) + rt_powf_snf(acc1, 2.0F));

  /* If: '<S34>/If' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Inport: '<S41>/prin'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   */
  if ((rtb_SaturationThrust1 > 9.79038F) && (rtb_SaturationThrust1 < 9.82962F))
  {
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
    localB->Merge[1] = (real32_T)atan(localB->FIR_IMUaccel[1] / acc1) * 0.001F +
      0.999F * localB->Sum_mah4rh5nu3[0];

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
     *  Gain: '<S40>/Gain3'
     *  Gain: '<S40>/Gain4'
     *  Trigonometry: '<S40>/Trigonometric Function1'
     */
    localB->Merge[0] = 0.999F * localB->Sum_mah4rh5nu3[1] + 0.001F * (real32_T)
      asin(u0);

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    localB->Merge[0] = localB->Sum_mah4rh5nu3[1];
    localB->Merge[1] = localB->Sum_mah4rh5nu3[0];

    /* End of Outputs for SubSystem: '<S34>/If Action Subsystem2' */
  }

  /* End of If: '<S34>/If' */

  /* Delay: '<S103>/MemoryX' */
  if (localDW->icLoad_gsr0jp51l1 != 0) {
    localDW->MemoryX_DSTATE_hqltbc4n3u[0] = 0.0F;
    localDW->MemoryX_DSTATE_hqltbc4n3u[1] = 0.0F;
  }

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S100>/Constant'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  Gain: '<S97>/Gain'
   *  Gain: '<S97>/opticalFlowErrorCorrect'
   *  Product: '<S97>/ '
   *  RelationalOperator: '<S100>/Compare'
   *  UnitDelay: '<S101>/Output'
   */
  if (localDW->Output_DSTATE < 800U) {
    localB->Product_m2bcxc3hq4[0] = rtu_Sensors->VisionSensors.opticalFlow_data
      [0];
    localB->Product_m2bcxc3hq4[1] = rtu_Sensors->VisionSensors.opticalFlow_data
      [1];
  } else {
    localB->Product_m2bcxc3hq4[0] = rtu_Sensors->VisionSensors.opticalFlow_data
      [0] * -(real32_T)localB->Add[0] * 1.15F;
    localB->Product_m2bcxc3hq4[1] = rtu_Sensors->VisionSensors.opticalFlow_data
      [1] * -(real32_T)localB->Add[0] * 1.15F;
  }

  /* End of Switch: '<S97>/Switch' */
  for (cff = 0; cff < 2; cff++) {
    /* DiscreteFilter: '<S102>/IIRgyroz' */
    memOffset = cff * 5;
    rtb_TrigonometricFunction_o1 = localB->inverseIMU_gain[cff + 3];
    denIdx = 1;
    for (j = 0; j < 5; j++) {
      rtb_TrigonometricFunction_o1 -= localDW->IIRgyroz_states[memOffset + j] *
        flightControlSystem_rtConstP.pooled10[denIdx];
      denIdx++;
    }

    localDW->IIRgyroz_tmp[cff] = rtb_TrigonometricFunction_o1;
    rtb_TrigonometricFunction_o1 = 0.282124132F * localDW->IIRgyroz_tmp[cff];
    denIdx = 1;
    for (j = 0; j < 5; j++) {
      rtb_TrigonometricFunction_o1 += localDW->IIRgyroz_states[memOffset + j] *
        flightControlSystem_rtConstP.pooled9[denIdx];
      denIdx++;
    }

    /* SampleTimeMath: '<S111>/TSamp' incorporates:
     *  DiscreteFilter: '<S102>/IIRgyroz'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    localB->TSamp[cff] = rtb_TrigonometricFunction_o1 * 200.0F;

    /* DiscreteFilter: '<S102>/IIRgyroz' incorporates:
     *  Sum: '<S111>/Diff'
     *  UnitDelay: '<S111>/UD'
     */
    localB->Akxhatkk1_f5py5lpkz4[cff] = localB->TSamp[cff] - localDW->
      UD_DSTATE[cff];
  }

  /* Abs: '<S102>/Abs' incorporates:
   *  Abs: '<S102>/Abs4'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)fabs(localB->inverseIMU_gain[3]);

  /* Abs: '<S102>/Abs1' incorporates:
   *  Abs: '<S102>/Abs5'
   */
  rtb_SaturationThrust1 = (real32_T)fabs(localB->inverseIMU_gain[4]);

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
  rtb_LogicalOperator3 = (((((real32_T)fabs(localB->Merge[0]) <= 0.6F) &&
    ((real32_T)fabs(localB->Merge[1]) <= 0.6F) && (rtb_TrigonometricFunction_o1 <=
    7.0F) && (rtb_SaturationThrust1 <= 7.0F) && ((real32_T)fabs
    (localB->Akxhatkk1_f5py5lpkz4[0]) <= 80.0F) && ((real32_T)fabs
    (localB->Akxhatkk1_f5py5lpkz4[1]) <= 80.0F)) ||
    ((rtb_TrigonometricFunction_o1 <= 0.5F) && (rtb_SaturationThrust1 <= 0.5F)))
    && ((real32_T)fabs(localB->Product_m2bcxc3hq4[0] - localDW->Delay_DSTATE[0])
        <= 5.0F) && ((real32_T)fabs(localB->Product_m2bcxc3hq4[1] -
    localDW->Delay_DSTATE[1]) <= 5.0F) && ((real32_T)localB->Add[0] <= -0.4F));

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
    rtb_SaturationThrust1 = localB->Product_m2bcxc3hq4[0] - (0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[1] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[0]);
    u0 = localB->Product_m2bcxc3hq4[1] - (0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[0] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[1]);

    /* Product: '<S166>/Product2' */
    localB->Product2_i5itdihbiv[0] = 0.0F;
    localB->Product2_i5itdihbiv[0] += 0.125465602F * rtb_SaturationThrust1;
    localB->Product2_i5itdihbiv[0] += 0.0F * u0;
    localB->Product2_i5itdihbiv[1] = 0.0F;
    localB->Product2_i5itdihbiv[1] += 0.0F * rtb_SaturationThrust1;
    localB->Product2_i5itdihbiv[1] += 0.125465602F * u0;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S166>/deltax' */
      localB->Product2_i5itdihbiv[0] = 0.0F;
      localB->Product2_i5itdihbiv[1] = 0.0F;
      localDW->EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S145>/Enabled Subsystem' */

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localB->TmpSignalConversionAtsincosInport1[0] = localB->Sum_mah4rh5nu3[2];

  /* Sum: '<S145>/Add' incorporates:
   *  Delay: '<S103>/MemoryX'
   */
  localB->Add_l4du2kzkfo[0] = localB->Product2_i5itdihbiv[0] +
    localDW->MemoryX_DSTATE_hqltbc4n3u[0];

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localB->TmpSignalConversionAtsincosInport1[1] = localB->Merge[0];

  /* Sum: '<S145>/Add' incorporates:
   *  Delay: '<S103>/MemoryX'
   */
  localB->Add_l4du2kzkfo[1] = localB->Product2_i5itdihbiv[1] +
    localDW->MemoryX_DSTATE_hqltbc4n3u[1];

  /* SignalConversion: '<S46>/TmpSignal ConversionAtsincosInport1' */
  localB->TmpSignalConversionAtsincosInport1[2] = localB->Merge[1];

  /* Trigonometry: '<S46>/sincos' incorporates:
   *  Trigonometry: '<S167>/sincos'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)sin
    (localB->TmpSignalConversionAtsincosInport1[0]);
  rtb_SaturationThrust1 = (real32_T)cos
    (localB->TmpSignalConversionAtsincosInport1[0]);
  u0 = (real32_T)sin(localB->TmpSignalConversionAtsincosInport1[1]);
  rtb_sincos_o2_idx_1_tmp = (real32_T)cos
    (localB->TmpSignalConversionAtsincosInport1[1]);
  rtb_sincos_o2_kq55ojr1f2_tmp = (real32_T)sin
    (localB->TmpSignalConversionAtsincosInport1[2]);
  rtb_sincos_o2_idx_2_tmp = (real32_T)cos
    (localB->TmpSignalConversionAtsincosInport1[2]);

  /* Fcn: '<S46>/Fcn11' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[0] = rtb_sincos_o2_idx_1_tmp * rtb_SaturationThrust1;

  /* Fcn: '<S46>/Fcn21' incorporates:
   *  Fcn: '<S46>/Fcn22'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_kq55ojr1f2_tmp * u0;
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp *
    rtb_SaturationThrust1 - rtb_sincos_o2_idx_2_tmp *
    rtb_TrigonometricFunction_o1;

  /* Fcn: '<S46>/Fcn31' incorporates:
   *  Fcn: '<S46>/Fcn32'
   *  Trigonometry: '<S46>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp * u0;
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    rtb_SaturationThrust1 + rtb_sincos_o2_kq55ojr1f2_tmp *
    rtb_TrigonometricFunction_o1;

  /* Fcn: '<S46>/Fcn12' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[3] = rtb_sincos_o2_idx_1_tmp *
    rtb_TrigonometricFunction_o1;

  /* Fcn: '<S46>/Fcn22' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    rtb_TrigonometricFunction_o1 + rtb_sincos_o2_idx_2_tmp *
    rtb_SaturationThrust1;

  /* Fcn: '<S46>/Fcn32' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_TrigonometricFunction_o1 - rtb_sincos_o2_kq55ojr1f2_tmp *
    rtb_SaturationThrust1;

  /* Fcn: '<S46>/Fcn13' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[6] = -u0;

  /* Fcn: '<S46>/Fcn23' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[7] = rtb_sincos_o2_kq55ojr1f2_tmp *
    rtb_sincos_o2_idx_1_tmp;

  /* Fcn: '<S46>/Fcn33' incorporates:
   *  Trigonometry: '<S46>/sincos'
   */
  localB->VectorConcatenate[8] = rtb_sincos_o2_idx_2_tmp *
    rtb_sincos_o2_idx_1_tmp;

  /* Product: '<S35>/Product1' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion1'
   *  Delay: '<S6>/Delay1'
   *  SignalConversion: '<S35>/TmpSignal ConversionAtProduct1Inport2'
   */
  for (j = 0; j < 3; j++) {
    localB->u_ch4zj0naok = (real_T)localB->VectorConcatenate[j] *
      localDW->Delay1_DSTATE[0];
    localB->rtb_Product1_tmp = (real_T)localB->VectorConcatenate[j + 3] *
      localDW->Delay1_DSTATE[1];
    localB->rtb_Product1_tmp_kkiq3xxxve = localB->VectorConcatenate[j + 6] *
      localB->Add[1];
    localB->Product1[j] = localB->rtb_Product1_tmp_kkiq3xxxve +
      (localB->rtb_Product1_tmp + localB->u_ch4zj0naok);
    localB->rtb_VectorConcatenate_cl54gopm0x[j] =
      localB->rtb_Product1_tmp_kkiq3xxxve + (localB->rtb_Product1_tmp +
      localB->u_ch4zj0naok);
  }

  /* End of Product: '<S35>/Product1' */

  /* SignalConversion: '<S1>/TmpSignal ConversionAtTo WorkspaceInport1' incorporates:
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   *  DataTypeConversion: '<S35>/Data Type Conversion2'
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
   */
  localB->TmpSignalConversionAtToWorkspaceInport1[2] = (real32_T)localB->Add[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[3] = localB->Sum_mah4rh5nu3[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[8] = (real32_T)
    localB->Product1[2];
  localB->TmpSignalConversionAtToWorkspaceInport1[0] =
    localDW->SimplyIntegrateVelocity_DSTATE[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[4] = localB->Merge[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[6] = localB->Add_l4du2kzkfo[0];
  localB->TmpSignalConversionAtToWorkspaceInport1[9] = localB->inverseIMU_gain[3];
  localB->TmpSignalConversionAtToWorkspaceInport1[1] =
    localDW->SimplyIntegrateVelocity_DSTATE[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[5] = localB->Merge[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[7] = localB->Add_l4du2kzkfo[1];
  localB->TmpSignalConversionAtToWorkspaceInport1[10] = localB->inverseIMU_gain
    [4];
  localB->TmpSignalConversionAtToWorkspaceInport1[11] =
    localB->numAccum_cxarnvbvui;

  /* Math: '<S35>/Math Function' */
  for (j = 0; j < 3; j++) {
    localB->rtb_VectorConcatenate_mbvzarwird[3 * j] = localB->
      VectorConcatenate[j];
    localB->rtb_VectorConcatenate_mbvzarwird[1 + 3 * j] =
      localB->VectorConcatenate[j + 3];
    localB->rtb_VectorConcatenate_mbvzarwird[2 + 3 * j] =
      localB->VectorConcatenate[j + 6];
  }

  for (j = 0; j < 9; j++) {
    localB->VectorConcatenate[j] = localB->rtb_VectorConcatenate_mbvzarwird[j];
  }

  /* End of Math: '<S35>/Math Function' */

  /* Fcn: '<S167>/Fcn11' */
  localB->MathFunction[0] = rtb_sincos_o2_idx_1_tmp * rtb_SaturationThrust1;

  /* Fcn: '<S167>/Fcn21' incorporates:
   *  Fcn: '<S167>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o2_kq55ojr1f2_tmp * u0;
  localB->MathFunction[1] = rtb_VectorConcatenate_tmp * rtb_SaturationThrust1 -
    rtb_sincos_o2_idx_2_tmp * rtb_TrigonometricFunction_o1;

  /* Fcn: '<S167>/Fcn31' incorporates:
   *  Fcn: '<S167>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2_tmp * u0;
  localB->MathFunction[2] = rtb_VectorConcatenate_tmp_0 * rtb_SaturationThrust1
    + rtb_sincos_o2_kq55ojr1f2_tmp * rtb_TrigonometricFunction_o1;

  /* Fcn: '<S167>/Fcn12' */
  localB->MathFunction[3] = rtb_sincos_o2_idx_1_tmp *
    rtb_TrigonometricFunction_o1;

  /* Fcn: '<S167>/Fcn22' */
  localB->MathFunction[4] = rtb_VectorConcatenate_tmp *
    rtb_TrigonometricFunction_o1 + rtb_sincos_o2_idx_2_tmp *
    rtb_SaturationThrust1;

  /* Fcn: '<S167>/Fcn32' */
  localB->MathFunction[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_TrigonometricFunction_o1 - rtb_sincos_o2_kq55ojr1f2_tmp *
    rtb_SaturationThrust1;

  /* Fcn: '<S167>/Fcn13' */
  localB->MathFunction[6] = -u0;

  /* Fcn: '<S167>/Fcn23' */
  localB->MathFunction[7] = rtb_sincos_o2_kq55ojr1f2_tmp *
    rtb_sincos_o2_idx_1_tmp;

  /* Fcn: '<S167>/Fcn33' */
  localB->MathFunction[8] = rtb_sincos_o2_idx_2_tmp * rtb_sincos_o2_idx_1_tmp;

  /* Math: '<S98>/Math Function' */
  for (j = 0; j < 3; j++) {
    localB->rtb_VectorConcatenate_mbvzarwird[3 * j] = localB->MathFunction[j];
    localB->rtb_VectorConcatenate_mbvzarwird[1 + 3 * j] = localB->MathFunction[j
      + 3];
    localB->rtb_VectorConcatenate_mbvzarwird[2 + 3 * j] = localB->MathFunction[j
      + 6];
  }

  for (j = 0; j < 9; j++) {
    localB->MathFunction[j] = localB->rtb_VectorConcatenate_mbvzarwird[j];
  }

  /* End of Math: '<S98>/Math Function' */

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  localB->DiscreteTimeIntegrator[0] = localDW->DiscreteTimeIntegrator_DSTATE[0];
  localB->DiscreteTimeIntegrator[1] = localDW->DiscreteTimeIntegrator_DSTATE[1];

  /* Chart: '<S5>/Chart' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

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

  /* Trigonometry: '<S9>/Trigonometric Function' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_TrigonometricFunction_o1 = (real32_T)sin(localB->Sum_mah4rh5nu3[2]);
  rtb_SaturationThrust1 = (real32_T)cos(localB->Sum_mah4rh5nu3[2]);

  /* Sum: '<S9>/Sum17' incorporates:
   *  BusAssignment: '<S5>/Bus  Assignment'
   *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
   *  Switch: '<S3>/Switch_refAtt'
   */
  u0 = localB->x - localDW->SimplyIntegrateVelocity_DSTATE[0];
  rtb_sincos_o2_idx_1_tmp = localB->y - localDW->SimplyIntegrateVelocity_DSTATE
    [1];

  /* Product: '<S9>/Product' incorporates:
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_sincos_o2_kq55ojr1f2_tmp = rtb_SaturationThrust1 * u0 +
    rtb_TrigonometricFunction_o1 * rtb_sincos_o2_idx_1_tmp;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  if (rtb_sincos_o2_kq55ojr1f2_tmp > 3.0F) {
    rtb_sincos_o2_kq55ojr1f2_tmp = 3.0F;
  } else {
    if (rtb_sincos_o2_kq55ojr1f2_tmp < -3.0F) {
      rtb_sincos_o2_kq55ojr1f2_tmp = -3.0F;
    }
  }

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Sum: '<S9>/Sum18'
   */
  localB->Add_o0zm3by3ri[0] = -0.24F * rtb_sincos_o2_kq55ojr1f2_tmp + 0.1F *
    localB->Add_l4du2kzkfo[0];

  /* Sum: '<S7>/Sum19' */
  localB->Add_o0zm3by3ri[0] -= localB->Merge[0];

  /* Product: '<S9>/Product' incorporates:
   *  Gain: '<S9>/Gain'
   *  SignalConversion: '<S9>/ConcatBufferAtVector Concatenate1In2'
   *  Switch: '<S3>/Switch_refAtt'
   */
  rtb_sincos_o2_kq55ojr1f2_tmp = -rtb_TrigonometricFunction_o1 * u0 +
    rtb_SaturationThrust1 * rtb_sincos_o2_idx_1_tmp;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Switch: '<S3>/Switch_refAtt'
   */
  if (rtb_sincos_o2_kq55ojr1f2_tmp > 3.0F) {
    rtb_sincos_o2_kq55ojr1f2_tmp = 3.0F;
  } else {
    if (rtb_sincos_o2_kq55ojr1f2_tmp < -3.0F) {
      rtb_sincos_o2_kq55ojr1f2_tmp = -3.0F;
    }
  }

  /* Switch: '<S3>/Switch_refAtt' incorporates:
   *  Gain: '<S9>/D_xy'
   *  Gain: '<S9>/P_xy'
   *  Sum: '<S9>/Sum18'
   */
  localB->Add_o0zm3by3ri[1] = 0.24F * rtb_sincos_o2_kq55ojr1f2_tmp + -0.1F *
    localB->Add_l4du2kzkfo[1];

  /* Sum: '<S7>/Sum19' */
  localB->Add_o0zm3by3ri[1] -= localB->Merge[1];

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  UnitDelay: '<S14>/Output'
   */
  localB->Compare_nuuzxwlhye = (localDW->Output_DSTATE_kdeodyri3i < 100U);

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if ((!localB->Compare_nuuzxwlhye) &&
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
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   */
  rtb_TrigonometricFunction_o1 = localB->z - (real32_T)localB->Add[0];

  /* Switch: '<S11>/TakeoffOrControl_Switch1' incorporates:
   *  Constant: '<S11>/w1'
   *  DataTypeConversion: '<S35>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  Gain: '<S11>/D_z1'
   *  Gain: '<S11>/P_z1'
   *  Gain: '<S11>/takeoff_gain1'
   *  Sum: '<S11>/Sum1'
   */
  if (localB->Compare_nuuzxwlhye) {
    u0 = -0.278113484F;
  } else {
    u0 = (0.8F * rtb_TrigonometricFunction_o1 +
          localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f) - 0.5F * (real32_T)
      localB->Product1[2];
  }

  /* End of Switch: '<S11>/TakeoffOrControl_Switch1' */

  /* Sum: '<S11>/Sum5' incorporates:
   *  Constant: '<S11>/w1'
   */
  rtb_SaturationThrust1 = -0.61803F + u0;

  /* Saturate: '<S11>/SaturationThrust1' incorporates:
   *  Constant: '<S11>/w1'
   *  Sum: '<S11>/Sum5'
   */
  if (-0.61803F + u0 > 1.20204329F) {
    rtb_SaturationThrust1 = 1.20204329F;
  } else {
    if (-0.61803F + u0 < -1.20204329F) {
      rtb_SaturationThrust1 = -1.20204329F;
    }
  }

  /* End of Saturate: '<S11>/SaturationThrust1' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2' incorporates:
   *  DiscreteFilter: '<S37>/IIR_IMUgyro_r'
   *  Gain: '<S10>/D_yaw'
   *  Gain: '<S10>/P_yaw'
   *  Gain: '<S7>/D_pr'
   *  Gain: '<S7>/I_pr'
   *  Gain: '<S7>/P_pr'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S7>/Sum16'
   */
  localB->numAccum_cxarnvbvui = ((real32_T)localB->yaw - localB->Sum_mah4rh5nu3
    [2]) * 0.004F - 0.0012F * localB->numAccum_cxarnvbvui;
  rtb_sincos_o2_idx_1_tmp = (0.013F * localB->Add_o0zm3by3ri[0] + 0.01F *
    localB->DiscreteTimeIntegrator[0]) - 0.002F * localB->inverseIMU_gain[4];
  rtb_sincos_o2_kq55ojr1f2_tmp = (0.011F * localB->Add_o0zm3by3ri[1] + 0.01F *
    localB->DiscreteTimeIntegrator[1]) - 0.003F * localB->inverseIMU_gain[3];
  for (j = 0; j < 4; j++) {
    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/TorqueTotalThrustToThrustPerMotor'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtProductInport2'
     */
    u0 = flightControlSystem_rtConstP.TorqueTotalThrustToThrustPerMotor_Value[j
      + 12] * rtb_sincos_o2_kq55ojr1f2_tmp +
      (flightControlSystem_rtConstP.TorqueTotalThrustToThrustPerMotor_Value[j +
       8] * rtb_sincos_o2_idx_1_tmp +
       (flightControlSystem_rtConstP.TorqueTotalThrustToThrustPerMotor_Value[j +
        4] * localB->numAccum_cxarnvbvui +
        flightControlSystem_rtConstP.TorqueTotalThrustToThrustPerMotor_Value[j] *
        rtb_SaturationThrust1));

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
    localB->MotorDirections[j] =
      flightControlSystem_rtConstP.MotorDirections_Gain[j] * u0;
  }

  for (j = 0; j < 3; j++) {
    /* Product: '<S98>/Product' incorporates:
     *  DataTypeConversion: '<S35>/Data Type Conversion2'
     *  SignalConversion: '<S98>/TmpSignal ConversionAtProductInport2'
     */
    localB->Product[j] = 0.0F;
    localB->Product[j] += localB->MathFunction[j] * localB->Add_l4du2kzkfo[0];
    localB->Product[j] += localB->MathFunction[j + 3] * localB->Add_l4du2kzkfo[1];
    localB->Product[j] += localB->MathFunction[j + 6] * (real32_T)
      localB->rtb_VectorConcatenate_cl54gopm0x[2];

    /* Sum: '<S35>/Sum' incorporates:
     *  Constant: '<S35>/gravity'
     *  DiscreteFir: '<S37>/FIR_IMUaccel'
     *  Product: '<S35>/Product'
     */
    localB->Product1[j] = (localB->VectorConcatenate[j + 6] * acc1 +
      (localB->VectorConcatenate[j + 3] * localB->FIR_IMUaccel[1] +
       localB->VectorConcatenate[j] * localB->FIR_IMUaccel[0])) +
      flightControlSystem_rtConstP.gravity_Value[j];

    /* Trigonometry: '<S105>/sincos' */
    localB->sincos_o2_kq55ojr1f2[j] = (real32_T)cos
      (localB->TmpSignalConversionAtsincosInport1[j]);

    /* Product: '<S35>/Product' incorporates:
     *  Trigonometry: '<S105>/sincos'
     */
    localB->Sum_mah4rh5nu3[j] = (real32_T)sin
      (localB->TmpSignalConversionAtsincosInport1[j]);
  }

  /* Fcn: '<S105>/Fcn11' */
  localB->VectorConcatenate[0] = localB->sincos_o2_kq55ojr1f2[1] *
    localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn21' incorporates:
   *  Fcn: '<S105>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = localB->Sum_mah4rh5nu3[2] * localB->
    Sum_mah4rh5nu3[1];
  localB->VectorConcatenate[1] = rtb_VectorConcatenate_tmp *
    localB->sincos_o2_kq55ojr1f2[0] - localB->sincos_o2_kq55ojr1f2[2] *
    localB->Sum_mah4rh5nu3[0];

  /* Fcn: '<S105>/Fcn31' incorporates:
   *  Fcn: '<S105>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = localB->sincos_o2_kq55ojr1f2[2] *
    localB->Sum_mah4rh5nu3[1];
  localB->VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 *
    localB->sincos_o2_kq55ojr1f2[0] + localB->Sum_mah4rh5nu3[2] *
    localB->Sum_mah4rh5nu3[0];

  /* Fcn: '<S105>/Fcn12' */
  localB->VectorConcatenate[3] = localB->sincos_o2_kq55ojr1f2[1] *
    localB->Sum_mah4rh5nu3[0];

  /* Fcn: '<S105>/Fcn22' */
  localB->VectorConcatenate[4] = rtb_VectorConcatenate_tmp *
    localB->Sum_mah4rh5nu3[0] + localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn32' */
  localB->VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    localB->Sum_mah4rh5nu3[0] - localB->Sum_mah4rh5nu3[2] *
    localB->sincos_o2_kq55ojr1f2[0];

  /* Fcn: '<S105>/Fcn13' */
  localB->VectorConcatenate[6] = -localB->Sum_mah4rh5nu3[1];

  /* Fcn: '<S105>/Fcn23' */
  localB->VectorConcatenate[7] = localB->Sum_mah4rh5nu3[2] *
    localB->sincos_o2_kq55ojr1f2[1];

  /* Fcn: '<S105>/Fcn33' */
  localB->VectorConcatenate[8] = localB->sincos_o2_kq55ojr1f2[2] *
    localB->sincos_o2_kq55ojr1f2[1];

  /* RelationalOperator: '<S104>/Compare' incorporates:
   *  Constant: '<S104>/Constant'
   *  DataTypeConversion: '<S35>/Data Type Conversion'
   */
  rtb_Compare_fdisj14o15 = ((real32_T)localB->Add[0] <= -0.4F);

  /* Logic: '<S99>/Logical Operator' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S106>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   */
  rtb_Compare_c551j053yo = ((localB->Product_m2bcxc3hq4[0] != 0.0F) ||
    (localB->Product_m2bcxc3hq4[1] != 0.0F));

  /* Sum: '<S99>/Add' incorporates:
   *  Product: '<S99>/Product1'
   */
  for (j = 0; j < 3; j++) {
    localB->rtb_VectorConcatenate_cl54gopm0x[j] = localB->FIR_IMUaccel[j] -
      ((localB->VectorConcatenate[j + 3] * 0.0 + localB->VectorConcatenate[j] *
        0.0) + localB->VectorConcatenate[j + 6] * -9.81);
  }

  /* End of Sum: '<S99>/Add' */

  /* Product: '<S99>/Product' incorporates:
   *  Gain: '<S99>/gainaccinput'
   */
  localB->Akxhatkk1_f5py5lpkz4[0] = (real32_T)(0.2 *
    localB->rtb_VectorConcatenate_cl54gopm0x[0]) * (real32_T)
    rtb_Compare_c551j053yo * (real32_T)rtb_Compare_fdisj14o15;
  localB->Akxhatkk1_f5py5lpkz4[1] = (real32_T)(0.2 *
    localB->rtb_VectorConcatenate_cl54gopm0x[1]) * (real32_T)
    rtb_Compare_c551j053yo * (real32_T)rtb_Compare_fdisj14o15;

  /* Outputs for Enabled SubSystem: '<S140>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S165>/Enable'
   */
  if (rtb_LogicalOperator3) {
    if (!localDW->MeasurementUpdate_MODE) {
      localDW->MeasurementUpdate_MODE = true;
    }

    /* Product: '<S165>/D[k]*u[k]' incorporates:
     *  Constant: '<S103>/D'
     */
    acc1 = 0.0F * localB->Akxhatkk1_f5py5lpkz4[0] + 0.0F *
      localB->Akxhatkk1_f5py5lpkz4[1];

    /* Sum: '<S165>/Sum' incorporates:
     *  Constant: '<S103>/C'
     *  Delay: '<S103>/MemoryX'
     *  Product: '<S165>/C[k]*xhat[k|k-1]'
     *  Product: '<S165>/D[k]*u[k]'
     *  Sum: '<S165>/Add1'
     */
    rtb_SaturationThrust1 = localB->Product_m2bcxc3hq4[0] - ((0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[1] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[0]) + acc1);
    u0 = localB->Product_m2bcxc3hq4[1] - ((0.0F *
      localDW->MemoryX_DSTATE_hqltbc4n3u[0] + localDW->
      MemoryX_DSTATE_hqltbc4n3u[1]) + acc1);

    /* Product: '<S165>/Product3' */
    localB->Product3_gd3igxsc2c[0] = 0.0F;
    localB->Product3_gd3igxsc2c[0] += 0.125465602F * rtb_SaturationThrust1;
    localB->Product3_gd3igxsc2c[0] += -0.0F * u0;
    localB->Product3_gd3igxsc2c[1] = 0.0F;
    localB->Product3_gd3igxsc2c[1] += 0.0F * rtb_SaturationThrust1;
    localB->Product3_gd3igxsc2c[1] += 0.125465602F * u0;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S165>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3_gd3igxsc2c[0] = 0.0F;
      localB->Product3_gd3igxsc2c[1] = 0.0F;
      localDW->MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S140>/MeasurementUpdate' */

  /* Sum: '<S140>/Add' incorporates:
   *  Constant: '<S103>/A'
   *  Constant: '<S103>/B'
   *  Delay: '<S103>/MemoryX'
   *  Product: '<S140>/A[k]*xhat[k|k-1]'
   *  Product: '<S140>/B[k]*u[k]'
   */
  localB->Add_m44y1dersg[0] = ((0.005F * localB->Akxhatkk1_f5py5lpkz4[0] + 0.0F *
    localB->Akxhatkk1_f5py5lpkz4[1]) + (0.0F *
    localDW->MemoryX_DSTATE_hqltbc4n3u[1] + localDW->MemoryX_DSTATE_hqltbc4n3u[0]))
    + localB->Product3_gd3igxsc2c[0];
  localB->Add_m44y1dersg[1] = ((0.0F * localB->Akxhatkk1_f5py5lpkz4[0] + 0.005F *
    localB->Akxhatkk1_f5py5lpkz4[1]) + (0.0F *
    localDW->MemoryX_DSTATE_hqltbc4n3u[0] + localDW->MemoryX_DSTATE_hqltbc4n3u[1]))
    + localB->Product3_gd3igxsc2c[1];

  /* Outputs for Enabled SubSystem: '<S65>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S90>/Enable'
   */
  if (rtb_nicemeasurementornewupdateneeded) {
    if (!localDW->MeasurementUpdate_MODE_nji240zmrw) {
      localDW->MeasurementUpdate_MODE_nji240zmrw = true;
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Constant: '<S44>/C'
     *  Constant: '<S44>/D'
     *  Delay: '<S44>/MemoryX'
     *  Gain: '<S35>/invertzaxisGain'
     *  Product: '<S90>/C[k]*xhat[k|k-1]'
     *  Product: '<S90>/D[k]*u[k]'
     *  SignalConversion: '<S169>/SigConversion_InsertedFor_Bus Selector5_at_outport_0'
     *  Sum: '<S90>/Add1'
     */
    localB->u_ch4zj0naok = -(real_T)
      rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude - ((0.0 *
      localDW->MemoryX_DSTATE[1] + localDW->MemoryX_DSTATE[0]) + 0.0 *
      localB->Product1[2]);

    /* Product: '<S90>/Product3' */
    localB->Product3[0] = 0.026590304322229058 * localB->u_ch4zj0naok;
    localB->Product3[1] = 0.06977673607149236 * localB->u_ch4zj0naok;
  } else {
    if (localDW->MeasurementUpdate_MODE_nji240zmrw) {
      /* Disable for Outport: '<S90>/L*(y[k]-yhat[k|k-1])' */
      localB->Product3[0] = 0.0;
      localB->Product3[1] = 0.0;
      localDW->MeasurementUpdate_MODE_nji240zmrw = false;
    }
  }

  /* End of Outputs for SubSystem: '<S65>/MeasurementUpdate' */

  /* Sum: '<S65>/Add' incorporates:
   *  Constant: '<S44>/A'
   *  Constant: '<S44>/B'
   *  Delay: '<S44>/MemoryX'
   *  Product: '<S65>/A[k]*xhat[k|k-1]'
   *  Product: '<S65>/B[k]*u[k]'
   */
  localB->Add_ief3tvrper[0] = ((0.005 * localDW->MemoryX_DSTATE[1] +
    localDW->MemoryX_DSTATE[0]) + 0.0 * localB->Product1[2]) + localB->Product3
    [0];

  /* Sum: '<S7>/Add' incorporates:
   *  Delay: '<S7>/Delay'
   *  Gain: '<S7>/antiWU_Gain'
   */
  localB->Add_o0zm3by3ri[0] -= 0.001F * localDW->Delay_DSTATE_ijwdhdrv0s[0];

  /* Sum: '<S65>/Add' incorporates:
   *  Constant: '<S44>/A'
   *  Constant: '<S44>/B'
   *  Delay: '<S44>/MemoryX'
   *  Product: '<S65>/A[k]*xhat[k|k-1]'
   *  Product: '<S65>/B[k]*u[k]'
   */
  localB->Add_ief3tvrper[1] = ((0.0 * localDW->MemoryX_DSTATE[0] +
    localDW->MemoryX_DSTATE[1]) + 0.005 * localB->Product1[2]) +
    localB->Product3[1];

  /* Sum: '<S7>/Add' incorporates:
   *  Delay: '<S7>/Delay'
   *  Gain: '<S7>/antiWU_Gain'
   */
  localB->Add_o0zm3by3ri[1] -= 0.001F * localDW->Delay_DSTATE_ijwdhdrv0s[1];

  /* Gain: '<S11>/I_pr' */
  localB->I_pr = 0.24F * rtb_TrigonometricFunction_o1;

  /* Switch: '<S16>/FixPt Switch' incorporates:
   *  Constant: '<S15>/FixPt Constant'
   *  Sum: '<S15>/FixPt Sum1'
   *  UnitDelay: '<S14>/Output'
   */
  localB->FixPtSwitch = localDW->Output_DSTATE_kdeodyri3i + 1U;

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
    localB->rtb_Product1_tmp = rtu_Sensors->VisionSensors.opticalFlow_data[2];
  } else {
    localB->u_ch4zj0naok = 0.0;
    localB->rtb_Product1_tmp = 0.0;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S4>/   '
   *  Delay: '<S4>/Delay One Step'
   *  Product: '<S4>/  '
   *  RelationalOperator: '<S18>/Compare'
   */
  localB->Add_ol0omud3hx = (real_T)(localB->rtb_Product1_tmp == -1.0) *
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
   *  DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity'
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
  if ((((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[0]) > 10.0F) ||
       ((real32_T)fabs(localDW->SimplyIntegrateVelocity_DSTATE[1]) > 10.0F)) > 0)
  {
    /* Outputs for IfAction SubSystem: '<S4>/Geofencing error' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion: '<S26>/OutportBufferForOut1' incorporates:
     *  Constant: '<S26>/Constant'
     */
    localB->Merge_mkzjcaq3mk = 1U;

    /* End of Outputs for SubSystem: '<S4>/Geofencing error' */
  } else if (((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
                0.01F) && ((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                 localB->Add_l4du2kzkfo[0]) > 6.0F)) || (((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[1] -
                 localB->Add_l4du2kzkfo[1]) > 6.0F) && ((real32_T)fabs
                (rtu_Sensors->VisionSensors.opticalFlow_data[1]) > 0.01F))) > 0)
  {
    /* Outputs for IfAction SubSystem: '<S4>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    flightControlSystem_estimatorOpticalflowerror(&localB->Merge_mkzjcaq3mk);

    /* End of Outputs for SubSystem: '<S4>/estimator//Optical flow error' */
  } else if (localB->Add_ol0omud3hx > 50.0) {
    /* Outputs for IfAction SubSystem: '<S4>/No optical flow ' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    flightControlSystem_estimatorOpticalflowerror(&localB->Merge_mkzjcaq3mk);

    /* End of Outputs for SubSystem: '<S4>/No optical flow ' */
  } else {
    if (rtb_nicemeasurementornewupdateneeded) {
      /* Switch: '<S4>/         ' incorporates:
       *  DataTypeConversion: '<S35>/Data Type Conversion'
       *  DiscreteFilter: '<S45>/pressureFilter_IIR'
       *  Sum: '<S4>/Difference between  sonar and pressure'
       */
      localB->numAccum = (real32_T)localB->Add[0] - localB->numAccum;
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
      flightControlSystem_Ultrasoundimproper(&localB->Merge_mkzjcaq3mk);

      /* End of Outputs for SubSystem: '<S4>/Ultrasound improper' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/Normal condition' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      flightControlSystem_Ultrasoundimproper(&localB->Merge_mkzjcaq3mk);

      /* End of Outputs for SubSystem: '<S4>/Normal condition' */
    }
  }

  /* End of If: '<S4>/If' */

  /* Switch: '<S32>/FixPt Switch' incorporates:
   *  Constant: '<S31>/FixPt Constant'
   *  Sum: '<S31>/FixPt Sum1'
   *  UnitDelay: '<S25>/Output'
   */
  localB->FixPtSwitch_efg3mboxv2 = localDW->Output_DSTATE_aloeis45eb + 1U;

  /* Switch: '<S110>/FixPt Switch' incorporates:
   *  Constant: '<S109>/FixPt Constant'
   *  Sum: '<S109>/FixPt Sum1'
   *  UnitDelay: '<S101>/Output'
   */
  localB->FixPtSwitch_kiztrseemx = localDW->Output_DSTATE + 1U;
}

/* Update for atomic system: '<Root>/Control System' */
void flightControlSystem_ControlSystem_Update
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW)
{
  int32_T memOffset;
  int32_T i;

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' incorporates:
   *  Constant: '<S1>/controlModePosVsOrient'
   */
  localDW->SimplyIntegrateVelocity_PrevResetState = 1;

  /* Update for Delay: '<S35>/Delay2' */
  localDW->Delay2_DSTATE = localB->Add[0];

  /* Update for Delay: '<S44>/MemoryX' */
  localDW->icLoad = 0U;

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[0] += 0.005F * localB->Product[0];

  /* Update for Delay: '<S44>/MemoryX' */
  localDW->MemoryX_DSTATE[0] = localB->Add_ief3tvrper[0];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[2] = localDW->pressureFilter_IIR_states[1];

  /* Update for DiscreteIntegrator: '<S98>/SimplyIntegrateVelocity' */
  localDW->SimplyIntegrateVelocity_DSTATE[1] += 0.005F * localB->Product[1];

  /* Update for Delay: '<S44>/MemoryX' */
  localDW->MemoryX_DSTATE[1] = localB->Add_ief3tvrper[1];

  /* Update for DiscreteFilter: '<S45>/pressureFilter_IIR' */
  localDW->pressureFilter_IIR_states[1] = localDW->pressureFilter_IIR_states[0];
  localDW->pressureFilter_IIR_states[0] = localDW->pressureFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S45>/soonarFilter_IIR' */
  localDW->soonarFilter_IIR_states[2] = localDW->soonarFilter_IIR_states[1];
  localDW->soonarFilter_IIR_states[1] = localDW->soonarFilter_IIR_states[0];
  localDW->soonarFilter_IIR_states[0] = localDW->soonarFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S37>/IIR_IMUgyro_r' */
  localDW->IIR_IMUgyro_r_states[4] = localDW->IIR_IMUgyro_r_states[3];
  localDW->IIR_IMUgyro_r_states[3] = localDW->IIR_IMUgyro_r_states[2];
  localDW->IIR_IMUgyro_r_states[2] = localDW->IIR_IMUgyro_r_states[1];
  localDW->IIR_IMUgyro_r_states[1] = localDW->IIR_IMUgyro_r_states[0];
  localDW->IIR_IMUgyro_r_states[0] = localDW->IIR_IMUgyro_r_tmp;

  /* Update for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput[0] = localB->TmpSignalConversionAtsincosInport1
    [0];
  localDW->Memory_PreviousInput[1] = localB->TmpSignalConversionAtsincosInport1
    [1];
  localDW->Memory_PreviousInput[2] = localB->TmpSignalConversionAtsincosInport1
    [2];

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

  /* Update for UnitDelay: '<S101>/Output' */
  localDW->Output_DSTATE = localB->FixPtSwitch_kiztrseemx;
  for (i = 0; i < 2; i++) {
    /* Update for Delay: '<S103>/MemoryX' */
    localDW->MemoryX_DSTATE_hqltbc4n3u[i] = localB->Add_m44y1dersg[i];

    /* Update for DiscreteFilter: '<S102>/IIRgyroz' */
    memOffset = i * 5;
    localDW->IIRgyroz_states[memOffset + 4] = localDW->IIRgyroz_states[memOffset
      + 3];
    localDW->IIRgyroz_states[memOffset + 3] = localDW->IIRgyroz_states[memOffset
      + 2];
    localDW->IIRgyroz_states[memOffset + 2] = localDW->IIRgyroz_states[memOffset
      + 1];
    localDW->IIRgyroz_states[memOffset + 1] = localDW->IIRgyroz_states[memOffset];
    localDW->IIRgyroz_states[memOffset] = localDW->IIRgyroz_tmp[i];

    /* Update for UnitDelay: '<S111>/UD' */
    localDW->UD_DSTATE[i] = localB->TSamp[i];

    /* Update for Delay: '<S97>/Delay' */
    localDW->Delay_DSTATE[i] = localB->Add_l4du2kzkfo[i];

    /* Update for Delay: '<S6>/Delay1' */
    localDW->Delay1_DSTATE[i] = localB->Add_l4du2kzkfo[i];

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_DSTATE[i] += 0.005F * localB->
      Add_o0zm3by3ri[i];
    if (localDW->DiscreteTimeIntegrator_DSTATE[i] >= 2.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE[i] = 2.0F;
    } else {
      if (localDW->DiscreteTimeIntegrator_DSTATE[i] <= -2.0F) {
        localDW->DiscreteTimeIntegrator_DSTATE[i] = -2.0F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  }

  /* Update for UnitDelay: '<S14>/Output' */
  localDW->Output_DSTATE_kdeodyri3i = localB->FixPtSwitch;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f += 0.005F * localB->I_pr;
  if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f >= 2.0F) {
    localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = 2.0F;
  } else {
    if (localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f <= -2.0F) {
      localDW->DiscreteTimeIntegrator_DSTATE_kgeqdjad0f = -2.0F;
    }
  }

  localDW->DiscreteTimeIntegrator_PrevResetState = (int8_T)
    localB->Compare_nuuzxwlhye;

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

  /* Update for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE_ijwdhdrv0s[0] = localB->DiscreteTimeIntegrator[0];
  localDW->Delay_DSTATE_ijwdhdrv0s[1] = localB->DiscreteTimeIntegrator[1];

  /* Update for UnitDelay: '<S25>/Output' */
  localDW->Output_DSTATE_aloeis45eb = localB->FixPtSwitch_efg3mboxv2;

  /* Update for Delay: '<S4>/Delay One Step' */
  localDW->DelayOneStep_DSTATE = localB->Add_ol0omud3hx;
}

/* Function for MATLAB Function: '<S2>/Deteccion de lineas verticales' */
static void flightControlSystem_sum(const boolean_T x[768], real_T y[32])
{
  for (flightControlSystem_rtB.i = 0; flightControlSystem_rtB.i < 32;
       flightControlSystem_rtB.i++) {
    flightControlSystem_rtB.xpageoffset = flightControlSystem_rtB.i * 24;
    y[flightControlSystem_rtB.i] = x[flightControlSystem_rtB.xpageoffset];
    for (flightControlSystem_rtB.k = 0; flightControlSystem_rtB.k < 23;
         flightControlSystem_rtB.k++) {
      y[flightControlSystem_rtB.i] += (real_T)x
        [(flightControlSystem_rtB.xpageoffset + flightControlSystem_rtB.k) + 1];
    }
  }
}

/* Function for MATLAB Function: '<S2>/Deteccion de lineas verticales' */
static real_T flightControlSystem_sum_erraza0c0y(const real_T x[32])
{
  real_T y;
  y = x[0];
  for (flightControlSystem_rtB.k_cl54gopm0x = 0;
       flightControlSystem_rtB.k_cl54gopm0x < 31;
       flightControlSystem_rtB.k_cl54gopm0x++) {
    y += x[flightControlSystem_rtB.k_cl54gopm0x + 1];
  }

  return y;
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  flightControlSystem_rtDW.RateTransition_Buffer0 = false;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  flightControlSystem_rtDW.RateTransition1_Buffer[0] = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Init(&flightControlSystem_rtB.ControlSystem,
    &flightControlSystem_rtDW.ControlSystem);

  /* End of SystemInitialize for SubSystem: '<Root>/Control System' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Image Processing System' */
  /* InitializeConditions for Delay: '<S2>/Delay' */
  flightControlSystem_rtDW.Delay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/Delay1' */
  flightControlSystem_rtDW.Delay1_DSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Image Processing System' */
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Start for Atomic SubSystem: '<Root>/Control System' */
  flightControlSystem_ControlSystem_Start
    (&flightControlSystem_rtDW.ControlSystem);

  /* End of Start for SubSystem: '<Root>/Control System' */

  /* Start for Atomic SubSystem: '<Root>/Image Processing System' */
  /* Start for MATLABSystem: '<S2>/PARROT Image Conversion' */
  flightControlSystem_rtDW.obj.isInitialized = 0;
  flightControlSystem_rtDW.objisempty = true;
  flightControlSystem_rtDW.obj.isInitialized = 1;

  /* End of Start for SubSystem: '<Root>/Image Processing System' */
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  const uint8_T *u0;

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Inport: '<Root>/AC cmd'
   *  Inport: '<Root>/Sensors'
   */
  if (ssIsSampleHit(rtS, 0, tid)) {
    flightControlSystem_rtB.RateTransition =
      flightControlSystem_rtDW.RateTransition_Buffer0;

    /* RateTransition: '<Root>/Rate Transition1' */
    flightControlSystem_rtB.RateTransition1 =
      flightControlSystem_rtDW.RateTransition1_Buffer[flightControlSystem_rtDW.RateTransition1_ActiveBufIdx];

    /* Outputs for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem(&sensor_inport,
      flightControlSystem_rtB.RateTransition,
      flightControlSystem_rtB.RateTransition1,
      &flightControlSystem_rtB.ControlSystem,
      &flightControlSystem_rtDW.ControlSystem);

    /* End of Outputs for SubSystem: '<Root>/Control System' */

    /* SignalConversion: '<Root>/TmpSignal ConversionAtControl SystemOutport1' incorporates:
     *  Inport: '<Root>/AC cmd'
     *  Inport: '<Root>/Sensors'
     */
    motors_outport[0] = flightControlSystem_rtB.ControlSystem.MotorDirections[0];
    motors_outport[1] = flightControlSystem_rtB.ControlSystem.MotorDirections[1];
    motors_outport[2] = flightControlSystem_rtB.ControlSystem.MotorDirections[2];
    motors_outport[3] = flightControlSystem_rtB.ControlSystem.MotorDirections[3];

    /* SignalConversion: '<Root>/TmpSignal ConversionAtControl SystemOutport2' */
    flag_outport = flightControlSystem_rtB.ControlSystem.Merge_mkzjcaq3mk;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */
  if (ssIsSampleHit(rtS, 1, tid)) {
    /* Outputs for Atomic SubSystem: '<Root>/Image Processing System' */
    /* MATLABSystem: '<S2>/PARROT Image Conversion' incorporates:
     *  Inport: '<Root>/Image Data'
     */
    u0 = &imRGB[0];
    MW_Build_RGB(u0, flightControlSystem_rtB.imageBuff_1,
                 flightControlSystem_rtB.imageBuff_2,
                 flightControlSystem_rtB.imageBuff_3);

    /* Logic: '<S2>/AND' incorporates:
     *  Constant: '<S171>/Constant'
     *  Constant: '<S172>/Constant'
     *  Constant: '<S173>/Constant'
     *  MATLABSystem: '<S2>/PARROT Image Conversion'
     *  RelationalOperator: '<S171>/Compare'
     *  RelationalOperator: '<S172>/Compare'
     *  RelationalOperator: '<S173>/Compare'
     */
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 19200;
         flightControlSystem_rtB.i0++) {
      flightControlSystem_rtB.AND[flightControlSystem_rtB.i0] =
        ((flightControlSystem_rtB.imageBuff_1[flightControlSystem_rtB.i0] > 100)
         && (flightControlSystem_rtB.imageBuff_2[flightControlSystem_rtB.i0] <
             100) &&
         (flightControlSystem_rtB.imageBuff_3[flightControlSystem_rtB.i0] < 100));
    }

    /* End of Logic: '<S2>/AND' */

    /* MATLAB Function: '<S2>/Deteccion de lineas verticales' incorporates:
     *  Delay: '<S2>/Delay'
     *  Delay: '<S2>/Delay1'
     */
    flightControlSystem_rtB.frentesuperior = 0;
    flightControlSystem_rtB.frente = 0;
    flightControlSystem_rtB.lateraliz = 0;
    flightControlSystem_rtB.lateralder = 0;
    flightControlSystem_rtB.alertacentro = 0;
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[120 *
          flightControlSystem_rtB.i0 + flightControlSystem_rtB.i1];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv8);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(32 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv7);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(64 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv6);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(96 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv5);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(128 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv4);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(120 *
          flightControlSystem_rtB.i0 + flightControlSystem_rtB.i1) + 24];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv3);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[((32 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1) + 24];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv2);
    flightControlSystem_rtB.RateTransition1 = flightControlSystem_sum_erraza0c0y
      (flightControlSystem_rtB.dv2);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[((64 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1) + 24];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv2);
    flightControlSystem_rtB.tc_idx_7 = flightControlSystem_sum_erraza0c0y
      (flightControlSystem_rtB.dv2);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[((96 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1) + 24];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv2);
    flightControlSystem_rtB.tc_idx_10 = flightControlSystem_sum_erraza0c0y
      (flightControlSystem_rtB.dv2);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[((128 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1) + 24];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv2);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[(120 *
          flightControlSystem_rtB.i0 + flightControlSystem_rtB.i1) + 48];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv1);
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 32;
         flightControlSystem_rtB.i0++) {
      for (flightControlSystem_rtB.i1 = 0; flightControlSystem_rtB.i1 < 24;
           flightControlSystem_rtB.i1++) {
        flightControlSystem_rtB.rtb_AND_mbvzarwird[flightControlSystem_rtB.i1 +
          24 * flightControlSystem_rtB.i0] = flightControlSystem_rtB.AND[((128 +
          flightControlSystem_rtB.i0) * 120 + flightControlSystem_rtB.i1) + 48];
      }
    }

    flightControlSystem_sum(flightControlSystem_rtB.rtb_AND_mbvzarwird,
      flightControlSystem_rtB.dv0);
    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv7) > 150.0)
    {
      flightControlSystem_rtB.frentesuperior = 1;
    }

    if (flightControlSystem_rtB.RateTransition1 > 150.0) {
      flightControlSystem_rtB.frente = 1;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv8) > 150.0)
    {
      flightControlSystem_rtB.lateraliz = 1;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv4) > 150.0)
    {
      flightControlSystem_rtB.lateralder = 1;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv6) > 150.0)
    {
      flightControlSystem_rtB.frentesuperior++;
    }

    if (flightControlSystem_rtB.tc_idx_7 > 150.0) {
      flightControlSystem_rtB.frente++;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv3) > 150.0)
    {
      flightControlSystem_rtB.lateraliz++;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv2) > 150.0)
    {
      flightControlSystem_rtB.lateralder++;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv5) > 150.0)
    {
      flightControlSystem_rtB.frentesuperior++;
    }

    if (flightControlSystem_rtB.tc_idx_10 > 150.0) {
      flightControlSystem_rtB.frente++;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv1) > 150.0)
    {
      flightControlSystem_rtB.lateraliz++;
    }

    if (flightControlSystem_sum_erraza0c0y(flightControlSystem_rtB.dv0) > 150.0)
    {
      flightControlSystem_rtB.lateralder++;
    }

    if ((flightControlSystem_rtB.lateraliz > 0) &&
        (flightControlSystem_rtB.lateraliz > flightControlSystem_rtB.lateralder))
    {
      flightControlSystem_rtB.alerta = 1.0;
    } else if ((flightControlSystem_rtB.lateralder > 0) &&
               (flightControlSystem_rtB.lateralder >
                flightControlSystem_rtB.lateraliz)) {
      flightControlSystem_rtB.alerta = 2.0;
    } else {
      flightControlSystem_rtB.alerta = 0.0;
    }

    if ((flightControlSystem_rtB.alerta == 0.0) ||
        (flightControlSystem_rtB.alerta ==
         flightControlSystem_rtDW.Delay1_DSTATE)) {
      flightControlSystem_rtB.alerta = flightControlSystem_rtDW.Delay1_DSTATE;
    }

    if ((flightControlSystem_rtB.frente == 0) &&
        (flightControlSystem_rtB.frentesuperior > 0) &&
        (flightControlSystem_rtB.lateraliz == 0) &&
        (flightControlSystem_rtB.lateralder == 0)) {
      flightControlSystem_rtB.alertacentro = 1;
    }

    if ((flightControlSystem_rtDW.Delay_DSTATE == 0.0) ||
        (flightControlSystem_rtDW.Delay_DSTATE == 1.0) ||
        (flightControlSystem_rtDW.Delay_DSTATE == 4.0) ||
        (flightControlSystem_rtDW.Delay_DSTATE == 5.0)) {
      if ((flightControlSystem_rtB.frentesuperior > 0) &&
          (flightControlSystem_rtB.alertacentro == 0)) {
        if (flightControlSystem_rtB.RateTransition1 - 100.0 >
            flightControlSystem_rtB.tc_idx_7) {
          flightControlSystem_rtB.estado = 4.0;
        } else if (flightControlSystem_rtB.tc_idx_10 - 100.0 >
                   flightControlSystem_rtB.tc_idx_7) {
          flightControlSystem_rtB.estado = 5.0;
        } else {
          flightControlSystem_rtB.estado = 1.0;
        }
      } else if ((flightControlSystem_rtB.frentesuperior == 0) &&
                 (flightControlSystem_rtB.lateraliz > 0) &&
                 (flightControlSystem_rtB.alertacentro == 0)) {
        flightControlSystem_rtB.estado = 2.0;
      } else if ((flightControlSystem_rtB.frentesuperior == 0) &&
                 (flightControlSystem_rtB.lateralder > 0) &&
                 (flightControlSystem_rtB.alertacentro == 0)) {
        flightControlSystem_rtB.estado = 3.0;
      } else if ((flightControlSystem_rtB.frentesuperior == 0) &&
                 (flightControlSystem_rtB.alerta == 1.0) &&
                 (flightControlSystem_rtB.alertacentro == 0)) {
        flightControlSystem_rtB.estado = 2.0;
      } else if ((flightControlSystem_rtB.frentesuperior == 0) &&
                 (flightControlSystem_rtB.alerta == 2.0) &&
                 (flightControlSystem_rtB.alertacentro == 0)) {
        flightControlSystem_rtB.estado = 3.0;
      } else if (flightControlSystem_rtB.alertacentro == 1) {
        flightControlSystem_rtB.estado = 6.0;
      } else {
        flightControlSystem_rtB.estado = 0.0;
      }
    } else {
      flightControlSystem_rtB.estado = 0.0;
    }

    /* End of MATLAB Function: '<S2>/Deteccion de lineas verticales' */

    /* Sum: '<S2>/Sum of white pixels' */
    flightControlSystem_rtB.u0 = 0U;
    for (flightControlSystem_rtB.i0 = 0; flightControlSystem_rtB.i0 < 19200;
         flightControlSystem_rtB.i0++) {
      flightControlSystem_rtB.u0 = (uint16_T)((uint32_T)
        flightControlSystem_rtB.u0 +
        flightControlSystem_rtB.AND[flightControlSystem_rtB.i0]);
    }

    /* RelationalOperator: '<S174>/Compare' incorporates:
     *  Constant: '<S174>/Constant'
     *  Sum: '<S2>/Sum of white pixels'
     */
    flightControlSystem_rtB.Compare = (flightControlSystem_rtB.u0 > 1400);

    /* End of Outputs for SubSystem: '<Root>/Image Processing System' */
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for RateTransition: '<Root>/Rate Transition' */
  if (ssIsSampleHit(rtS, 1, tid)) {
    flightControlSystem_rtDW.RateTransition_Buffer0 =
      flightControlSystem_rtB.Compare;

    /* Update for RateTransition: '<Root>/Rate Transition1' */
    flightControlSystem_rtDW.RateTransition1_Buffer[flightControlSystem_rtDW.RateTransition1_ActiveBufIdx
      == 0] = flightControlSystem_rtB.estado;
    flightControlSystem_rtDW.RateTransition1_ActiveBufIdx = (int8_T)
      (flightControlSystem_rtDW.RateTransition1_ActiveBufIdx == 0);
  }

  /* End of Update for RateTransition: '<Root>/Rate Transition' */
  if (ssIsSampleHit(rtS, 0, tid)) {
    /* Update for Atomic SubSystem: '<Root>/Control System' */
    flightControlSystem_ControlSystem_Update
      (&flightControlSystem_rtB.ControlSystem,
       &flightControlSystem_rtDW.ControlSystem);

    /* End of Update for SubSystem: '<Root>/Control System' */
  }

  if (ssIsSampleHit(rtS, 1, tid)) {
    /* Update for Atomic SubSystem: '<Root>/Image Processing System' */
    /* Update for Delay: '<S2>/Delay' */
    flightControlSystem_rtDW.Delay_DSTATE = flightControlSystem_rtB.estado;

    /* Update for Delay: '<S2>/Delay1' */
    flightControlSystem_rtDW.Delay1_DSTATE = flightControlSystem_rtB.alerta;

    /* End of Update for SubSystem: '<Root>/Image Processing System' */
  }

  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 0);          /* Number of continuous states */
  ssSetNumY(rtS, 5);                   /* Number of model outputs */
  ssSetNumU(rtS, 38402);               /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 395);            /* Number of blocks */
  ssSetNumBlockIO(rtS, 33);            /* Number of block outputs */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.005);
  ssSetSampleTime(rtS, 1, 0.2);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * flightControlSystem(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
      }
    }

    mdlSampleHits[0] = 1;
    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
  }

  {
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    (void) memset((void *)&mdlPerTaskSampleHits[0], 0,
                  2 * 2 * sizeof(int_T));
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_MULTITASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &flightControlSystem_rtB));
    (void) memset(((void *) &flightControlSystem_rtB), 0,
                  sizeof(B_flightControlSystem_T));
  }

  /* external inputs */
  {
    (void)memset(&cmd_inport, 0, sizeof(CommandBus));
    (void)memset(&sensor_inport, 0, sizeof(SensorsBus));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &flightControlSystem_rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW_flightControlSystem_T));
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "flightControlSystem");
  ssSetPath(rtS, "flightControlSystem");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, -1);
  ssSetStepSize(rtS, 0.005);
  ssSetFixedStepSize(rtS, 0.005);
  ssSetChecksumVal(rtS, 0, 3039750393U);
  ssSetChecksumVal(rtS, 1, 2319935285U);
  ssSetChecksumVal(rtS, 2, 2221550514U);
  ssSetChecksumVal(rtS, 3, 645048517U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
