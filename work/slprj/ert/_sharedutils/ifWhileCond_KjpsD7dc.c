/*
 * E:\dron\work\slprj\ert\_sharedutils\ifWhileCond_KjpsD7dc.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.603
 * Simulink Coder version : 9.3 (R2019a) 23-Nov-2018
 * C source code generated on : Sat Nov  9 20:11:49 2019
 * Created for block: flightControlSystem
 */

#include "rtwtypes.h"
#include "ifWhileCond_KjpsD7dc.h"

/* Function for MATLAB Function: '<S2>/Deteccion de lineas verticales' */
boolean_T ifWhileCond_KjpsD7dc(const boolean_T x[4])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}
