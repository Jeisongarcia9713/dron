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

#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "flightControlSystem.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

/* Imported (extern) pointer block signals */
extern uint8_T *imRGB;                 /* '<Root>/Image Data' */
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void flightControlSystem_estimatorOpticalflowerror(uint8_T *rty_Out1);
extern void flightControlSystem_Ultrasoundimproper(uint8_T *rty_Out1);
extern void flightControlSystem_ControlSystem_SetupRTR
  (RT_MODEL_flightControlSystem_T * const flightControlSystem_M,
   DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_ControlSystem_Init
  (B_ControlSystem_flightControlSystem_T *localB,
   DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_ControlSystem(RT_MODEL_flightControlSystem_T *
  const flightControlSystem_M, const SensorsBus *rtu_Sensors, boolean_T
  rtu_VisionbasedData, real_T rtu_estado, B_ControlSystem_flightControlSystem_T *
  localB, DW_ControlSystem_flightControlSystem_T *localDW);
extern void flightControlSystem_step0(void);
extern void flightControlSystem_step1(void);

#endif                           /* RTW_HEADER_flightControlSystem_private_h_ */
