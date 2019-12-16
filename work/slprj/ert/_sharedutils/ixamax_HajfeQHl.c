/*
 * E:\dron\work\slprj\ert\_sharedutils\ixamax_HajfeQHl.c
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
#include <math.h>
#include "ixamax_HajfeQHl.h"

/* Function for MATLAB Function: '<S2>/Cuadrante' */
int32_T ixamax_HajfeQHl(int32_T n, const real_T x[2], int32_T ix0)
{
  int32_T idxmax;
  idxmax = 1;
  if ((n > 1) && (fabs(x[1]) > fabs(x[ix0 - 1]))) {
    idxmax = 2;
  }

  return idxmax;
}
