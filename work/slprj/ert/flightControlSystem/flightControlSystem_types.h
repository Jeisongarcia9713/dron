#include "__cf_flightControlSystem.h"
#ifndef RTW_HEADER_flightControlSystem_types_h_
#define RTW_HEADER_flightControlSystem_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#include "C:\ProgramData\MATLAB\SupportPackages\R2019a\toolbox\target\supportpackages\parrot\include\HAL.h"
#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_
typedef struct { boolean_T controlModePosVSOrient ; real32_T pos_ref [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; boolean_T takeoff_flag ; real32_T orient_ref [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; uint32_T live_time_ticks ; } CommandBus ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_
typedef struct { real32_T opticalFlow_data [ _nfvdmbxYkVXzXnpHyWwmg2 ] ;
real32_T posVIS_data [ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T usePosVIS_flag ;
} extraSensorData_t ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_
typedef struct { extraSensorData_t VisionSensors ; HAL_acquisition_t
HALSensors ; real32_T SensorCalibration [ _hCXUd_x6pbKZfXtyKXEw82 ] ; }
SensorsBus ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_eAf0NJvzCY9HYTXF7bLNgB_
#define DEFINED_TYPEDEF_FOR_struct_eAf0NJvzCY9HYTXF7bLNgB_
typedef struct { real_T Ts2Q [ _GL1cfYXlov7alqvUlVUDz0 ] ; real_T Q2Ts [
_GL1cfYXlov7alqvUlVUDz0 ] ; real_T takeoffGain ; real_T
totalThrustMaxRelative ; real_T motorsThrustPerMotorMax ; }
struct_eAf0NJvzCY9HYTXF7bLNgB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_XRMsui9C07VjBvdq1msujB_
#define DEFINED_TYPEDEF_FOR_struct_XRMsui9C07VjBvdq1msujB_
typedef struct { real_T initGreenwich ; real_T quatGain ; }
struct_XRMsui9C07VjBvdq1msujB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_hxsmtt0xTZOLDNa2Rz7GAF_
#define DEFINED_TYPEDEF_FOR_struct_hxsmtt0xTZOLDNa2Rz7GAF_
typedef struct { real_T xAxis ; } struct_hxsmtt0xTZOLDNa2Rz7GAF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_IZWOW0zYvpphl7qLgSfN7E_
#define DEFINED_TYPEDEF_FOR_struct_IZWOW0zYvpphl7qLgSfN7E_
typedef struct { real_T href ; struct_hxsmtt0xTZOLDNa2Rz7GAF FlatEarthToLLA ;
} struct_IZWOW0zYvpphl7qLgSfN7E ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_q6UUpnZ4gTjFvULFx6Rxa_
#define DEFINED_TYPEDEF_FOR_struct_q6UUpnZ4gTjFvULFx6Rxa_
typedef struct { real_T mass ; real_T inertia [ _aoel664zPcTjzpXADn7l40 ] ;
real_T d ; real_T xy ; real_T h ; real_T Cdx ; real_T Cdy ; real_T diameter ;
} struct_q6UUpnZ4gTjFvULFx6Rxa ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_OMRgDnJcZuQneKEj9vdTyD_
#define DEFINED_TYPEDEF_FOR_struct_OMRgDnJcZuQneKEj9vdTyD_
typedef struct { real_T blades ; real_T radius ; real_T chord ; real_T
flappingOffset ; real_T bladeMass ; real_T bladeInertia ; real_T hubMass ;
real_T hubInertia ; real_T inertia ; real_T Ct ; real_T Cq ; real_T solidity
; real_T theta0 ; real_T thetaTip ; real_T theta1 ; real_T theta34 ; real_T a
; real_T area ; real_T lock ; real_T b ; real_T k ; real_T w2ToThrustGain ; }
struct_OMRgDnJcZuQneKEj9vdTyD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_p3FXZIgqtjF2uqDpmYjb6C_
#define DEFINED_TYPEDEF_FOR_struct_p3FXZIgqtjF2uqDpmYjb6C_
typedef struct { real_T maxLimit ; real_T minLimit ; real_T commandToW2Gain ;
real_T thrustToMotorCommand ; } struct_p3FXZIgqtjF2uqDpmYjb6C ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_OSJpyIZcrpXqReVWwh9iuG_
#define DEFINED_TYPEDEF_FOR_struct_OSJpyIZcrpXqReVWwh9iuG_
typedef struct { struct_XRMsui9C07VjBvdq1msujB SixDOF ;
struct_IZWOW0zYvpphl7qLgSfN7E PositionOnEarth ; struct_q6UUpnZ4gTjFvULFx6Rxa
Airframe ; struct_OMRgDnJcZuQneKEj9vdTyD Rotor ;
struct_p3FXZIgqtjF2uqDpmYjb6C Motor ; } struct_OSJpyIZcrpXqReVWwh9iuG ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_hE1099BMemg5OfzqcWAA6G_
#define DEFINED_TYPEDEF_FOR_struct_hE1099BMemg5OfzqcWAA6G_
typedef struct { real_T date [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real_T posLLA [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T posNED [ _nfvdmbxYkVXzXnpHyWwmg2 ] ;
real_T vb [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T euler [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T angRates [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; }
struct_hE1099BMemg5OfzqcWAA6G ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_
#define DEFINED_TYPEDEF_FOR_struct_eF5OUT33sX0T9pzS8027m_
typedef struct { real_T cg [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T location [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T accNatFreq ; real_T accDamping ; real_T
accScaleCross [ _aoel664zPcTjzpXADn7l40 ] ; real_T accBias [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T accLimits [ _RAQgyWVtpyqfEVcLRZFTL_ ] ;
real_T gyroNatFreq ; real_T gyroDamping ; real_T gyroScaleCross [
_aoel664zPcTjzpXADn7l40 ] ; real_T gyroBias [ _nfvdmbxYkVXzXnpHyWwmg2 ] ;
real_T gyroGBias [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T gyroLimits [
_RAQgyWVtpyqfEVcLRZFTL_ ] ; real_T noiseSeeds [ _RAQgyWVtpyqfEVcLRZFTL_ ] ;
real_T noiseWeights [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real_T noisePower [
_RAQgyWVtpyqfEVcLRZFTL_ ] ; } struct_eF5OUT33sX0T9pzS8027m ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_
#define DEFINED_TYPEDEF_FOR_struct_FIfaVnupBjYAxo1EdNiDlF_
typedef struct { real_T noisePower ; real_T noiseSeeds ; }
struct_FIfaVnupBjYAxo1EdNiDlF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_
#define DEFINED_TYPEDEF_FOR_struct_eFnp8sKFNJLN84XLbLzaFF_
typedef struct { real_T posVISNoVisionAvail [ _g7WFphbd05O6bEjctOzUc1 ] ;
real_T usePosVISFlag ; real_T batteryStatus [ _gN74BbsU5wqNjkJbC9b672 ] ; }
struct_eFnp8sKFNJLN84XLbLzaFF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_8SSZ93PxvPkADZcA4gG8MD_
#define DEFINED_TYPEDEF_FOR_struct_8SSZ93PxvPkADZcA4gG8MD_
typedef struct { real_T IMUAccelGain [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T
IMUGyroGain [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; struct_eF5OUT33sX0T9pzS8027m IMU ;
struct_FIfaVnupBjYAxo1EdNiDlF Sonar ; real_T NO_VIS_X ; real_T NO_VIS_YAW ;
struct_eFnp8sKFNJLN84XLbLzaFF dummy ; real_T sensorDelay ; real_T airDensity
; real_T altToPrsGain ; real_T altToPrsBias ; real_T inverseIMUGain [
_RAQgyWVtpyqfEVcLRZFTL_ ] ; real_T altSensorMin ; real_T
velocityToOpticalFlowGain ; } struct_8SSZ93PxvPkADZcA4gG8MD ;
#endif
#ifndef typedef_elrp3gv4ik
#define typedef_elrp3gv4ik
typedef struct { uint32_T f1 [ _hCXUd_x6pbKZfXtyKXEw82 ] ; } elrp3gv4ik ;
#endif
#ifndef typedef_bjqsgn0csy
#define typedef_bjqsgn0csy
typedef struct { int32_T isInitialized ; elrp3gv4ik inputVarSize ; }
bjqsgn0csy ;
#endif
typedef struct bpvdgm2xq5_ bpvdgm2xq5 ; typedef struct nu4qaxumex_ nu4qaxumex
; typedef struct ileg2v2ld1r_ ileg2v2ld1r ; typedef struct diqjpw4041
ipf5ube4r0 ;
#endif
