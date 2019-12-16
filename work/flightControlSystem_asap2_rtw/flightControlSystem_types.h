/*
 * flightControlSystem_types.h
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

#ifndef RTW_HEADER_flightControlSystem_types_h_
#define RTW_HEADER_flightControlSystem_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "C:\ProgramData\MATLAB\SupportPackages\R2019a\toolbox\target\supportpackages\parrot\include\HAL.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

#endif

#ifndef typedef_c_cell_wrap_flightControlSystem_T
#define typedef_c_cell_wrap_flightControlSystem_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_flightControlSystem_T;

#endif                             /*typedef_c_cell_wrap_flightControlSystem_T*/

#ifndef typedef_parrot_ImageProcess_flightControlSystem_T
#define typedef_parrot_ImageProcess_flightControlSystem_T

typedef struct {
  int32_T isInitialized;
  c_cell_wrap_flightControlSystem_T inputVarSize;
} parrot_ImageProcess_flightControlSystem_T;

#endif                     /*typedef_parrot_ImageProcess_flightControlSystem_T*/
#endif                             /* RTW_HEADER_flightControlSystem_types_h_ */
