/*
 * flightControlSystem_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(CommandBus),
  sizeof(extraSensorData_t),
  sizeof(HAL_acc_SI_t),
  sizeof(HAL_gyro_SI_t),
  sizeof(HAL_fifo_gyro_SI_t),
  sizeof(HAL_magn_mG_t),
  sizeof(HAL_pressure_SI_t),
  sizeof(HAL_echo_t),
  sizeof(HAL_list_echo_t),
  sizeof(HAL_ultrasound_SI_t),
  sizeof(HAL_vbat_SI_t),
  sizeof(HAL_acquisition_t),
  sizeof(SensorsBus),
  sizeof(parrot_ImageProcess_flightControlSystem_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "CommandBus",
  "extraSensorData_t",
  "HAL_acc_SI_t",
  "HAL_gyro_SI_t",
  "HAL_fifo_gyro_SI_t",
  "HAL_magn_mG_t",
  "HAL_pressure_SI_t",
  "HAL_echo_t",
  "HAL_list_echo_t",
  "HAL_ultrasound_SI_t",
  "HAL_vbat_SI_t",
  "HAL_acquisition_t",
  "SensorsBus",
  "parrot_ImageProcess_flightControlSystem_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&flightControlSystem_B.RateTransition1), 0, 0, 3 },

  { (char_T *)(&flightControlSystem_B.RateTransition), 8, 0, 2 },

  { (char_T *)(&flightControlSystem_B.ControlSystem.Product2[0]), 0, 0, 4 },

  { (char_T *)(&flightControlSystem_B.ControlSystem.yaw), 0, 0, 1 },

  { (char_T *)(&flightControlSystem_B.ControlSystem.SimplyIntegrateVelocity[0]),
    1, 0, 2 },

  { (char_T *)(&flightControlSystem_B.ControlSystem.altitude), 1, 0, 39 }
  ,

  { (char_T *)(&motors_outport[0]), 1, 0, 4 }
  ,

  { (char_T *)(&flag_outport), 3, 0, 1 }
  ,

  { (char_T *)(&flightControlSystem_DW.obj), 27, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.Delay1_DSTATE), 0, 0, 3 },

  { (char_T *)(&flightControlSystem_DW.RateTransition1_ActiveBufIdx), 2, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.RateTransition_Buffer0), 8, 0, 2 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.Delay2_DSTATE), 0, 0, 11 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.ToWorkspace_PWORK.LoggedData), 11, 0,
    1 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_DSTATE[0]), 1,
    0, 46 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.FIR_IMUaccel_circBuf), 6, 0,
    1 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.Output_DSTATE), 7, 0, 3 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.Memory_PreviousInput[0]), 1,
    0, 5 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.sfEvent), 6, 0, 1 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.temporalCounter_i1), 7, 0,
    1 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_PrevResetState),
    2, 0, 9 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.icLoad), 3, 0, 4 },

  { (char_T *)(&flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE), 8,
    0, 4 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.Normalcondition.Ultrasoundimproper_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Ultrasoundimproper_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.Noopticalflow.estimatorOpticalflowerror_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.estimatorOpticalflowerror_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  27U,
  rtBTransitions
};

/* [EOF] flightControlSystem_dt.h */
