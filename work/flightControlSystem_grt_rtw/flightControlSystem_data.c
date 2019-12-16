/*
 * flightControlSystem_data.c
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

/* Constant parameters (default storage) */
const ConstP_flightControlSystem_T flightControlSystem_ConstP = {
  /* Expression: [0 0 g]
   * Referenced by: '<S35>/gravity'
   */
  { 0.0, 0.0, 9.81 },

  /* Computed Parameter: TorqueTotalThrustToThrustPerMotor_Value
   * Referenced by: '<S8>/TorqueTotalThrustToThrustPerMotor'
   */
  { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
    -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F, 5.66592F,
    5.66592F, -5.66592F },

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroNum)
   * Referenced by:
   *   '<S37>/IIR_IMUgyro_r'
   *   '<S102>/IIRgyroz'
   */
  { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
    0.282124132F },

  /* Pooled Parameter (Expression: Estimator.IMU.filterGyroDen)
   * Referenced by:
   *   '<S37>/IIR_IMUgyro_r'
   *   '<S102>/IIRgyroz'
   */
  { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

  /* Computed Parameter: FIR_IMUaccel_Coefficients
   * Referenced by: '<S37>/FIR_IMUaccel'
   */
  { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
    0.0264077242F },

  /* Computed Parameter: MotorDirections_Gain
   * Referenced by: '<S12>/MotorDirections'
   */
  { 1.0F, -1.0F, 1.0F, -1.0F }
};
