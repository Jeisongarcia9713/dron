/*
 * flightControlSystem_private.h
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

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "flightControlSystem.h"

/* Imported (extern) pointer block signals */
extern uint8_T *imRGB;                 /* '<Root>/Image Data' */
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void flightControlSystem_estimatorOpticalflowerror(uint8_T *rty_Out1);
extern void flightControlSystem_Ultrasoundimproper(uint8_T *rty_Out1);
extern void flightControlSystem_ControlSystem_Init
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_ControlSystem_Start
  (DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_ControlSystem_Update
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_ControlSystem(const SensorsBus *rtu_Sensors,
  boolean_T rtu_VisionbasedData, real_T rtu_estado,
  B_ControlSystem_flightControlSystem_T *localB,
  DW_ControlSystem_flightControlSystem_T *localDW);

#if !defined(MULTITASKING) && !defined(NRT)
#  error Model (flightControlSystem) was built \
in MultiTasking solver mode, however the MULTITASKING define \
is not present. Please verify that your template makefile is \
configured correctly.
#endif
#endif                           /* RTW_HEADER_flightControlSystem_private_h_ */
