#include "__cf_flightControlSystem.h"
#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include <math.h>
#include <string.h>
#ifndef flightControlSystem_COMMON_INCLUDES_
#define flightControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rsedu_image.h"
#endif
#include "flightControlSystem_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real32_T ots0p1x4xa_mbvzarwird [ _t0CSRdt0cj28FWcY3kSLw_ ] ;
real32_T jliewk43cn_cl54gopm0x [ _aoel664zPcTjzpXADn7l40 ] ; real32_T
kab3usubrk_kkiq3xxxve [ _aoel664zPcTjzpXADn7l40 ] ; real32_T
oxsm050h43_cxarnvbvui [ _aoel664zPcTjzpXADn7l40 ] ; real32_T
jliewk43cn_bhxxfovxdy [ _aoel664zPcTjzpXADn7l40 ] ; real_T
pwpw41hvpq_pbm3vprmfu [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T hkhqo3ktzs [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T lc4v23roxz_cv5hdgrwft [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T jliewk43cn_fqdqrf4qbc [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T fv0 [ _g7WFphbd05O6bEjctOzUc1 ] ;
real32_T bhsqbzez02_g2mlkqadfk [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T
obiqpkzuxm [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T hx1e41ebhr_g1smspu5ke [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T nrssuc31m3_merlcviukg [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T d0uuhdq1jv ; real_T abpugu0iq5 ; real_T
do1wpy4fmt [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T dbvv5akcb0 ; real_T
f1o4lgbudp ; real32_T l5k35czx4c [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real_T
ctwxt0toy5_nz4o0shxby ; real_T lc4v23roxz_tmp ; real_T
lc4v23roxz_tmp_ppxrqq0gsf ; real_T lc4v23roxz_tmp_llw0u2ae0v ; real32_T
fdpdtjrnos [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T c3yz3mreys [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T nvdhtmgn53 [ _g7WFphbd05O6bEjctOzUc1 ] ;
real32_T eqd0jg3xm5 [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T ispkvul20t [
_gN74BbsU5wqNjkJbC9b672 ] ; real32_T jlv0kr2yo1 [ _gN74BbsU5wqNjkJbC9b672 ] ;
real32_T pzibmfponq_jwzvbuczlb [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T
hy0hlwfytb_dhmrxtyqop [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T
g24azjuzjs_guugdwf2m3 [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T fv1 [
_gN74BbsU5wqNjkJbC9b672 ] ; real32_T fv2 [ _gN74BbsU5wqNjkJbC9b672 ] ;
real32_T nh54e1zpra ; real32_T cp5k0ycqek ; real32_T bpuvmjeifc ; real32_T
numAccum ; real32_T denAccum ; int32_T denIdx ; uint8_T bzyafamzv1 ;
boolean_T oloes3v5z3 ; boolean_T blaj3zuj3y ; boolean_T oxsahknyxp ; }
eo4bbte2ey ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T mck2owxrk2 ; real_T etwz51o21c [
_gN74BbsU5wqNjkJbC9b672 ] ; real_T c4t5e3w5ek [ _nfvdmbxYkVXzXnpHyWwmg2 ] ;
real_T bw2ribqmwm ; real_T fl2edockfe ; real_T otowemn3cp ; real_T kgogwy2imk
; real_T d1aeiyggmt ; struct { void * LoggedData ; } mpopad3fr1 ; real32_T
jxg1zvdttz [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T kgows215bs [
_nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T liybiw1jbg [ _KYlcoOk9rSSGYswizhYqZ2 ] ;
real32_T nbbc5odoq4 [ _7TQ7rYk8WkCvursSu7_Dc_ ] ; real32_T kzeijhdtif [
_gN74BbsU5wqNjkJbC9b672 ] ; real32_T heeedoxzle [ _IjHdoOm5hGk4VAbwwsvcL1 ] ;
real32_T gqxdiwstsm [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T a3uar2xrsb [
_gN74BbsU5wqNjkJbC9b672 ] ; real32_T lw3rw5s0ye [ _gN74BbsU5wqNjkJbC9b672 ] ;
real32_T fuo05buemm [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T ppp4ajc3p1 ;
real32_T cosb2ibhn3 [ _gN74BbsU5wqNjkJbC9b672 ] ; int32_T cfcgwprtdx ;
uint32_T npsllq52wf ; uint32_T i13qoukcsn ; uint32_T dxm3w2i52x ; real32_T
ik5zcuhoy3 ; real32_T lfi3mnae2m [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T
lpva1qajzk ; real32_T dhhdwwczx2 [ _gN74BbsU5wqNjkJbC9b672 ] ; int8_T
ii2o5s5qnf ; int8_T gafzug4yea ; uint8_T ozjz0fr0k4 ; uint8_T pvn1aiza5a ;
uint8_T ltfttbh0l5 ; uint8_T eu3nanje0l ; uint8_T l3osxpk4vp ; boolean_T
hz0zs1tgyj ; boolean_T fxtcsw2xrl ; boolean_T lyttutf1nn ; boolean_T
oyo5l0bkak ; } dmp1xsadgu ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { real_T dv0 [ _iBpWsoOMGVrqXP6KcXjUq2 ] ; real_T dv1 [
_iBpWsoOMGVrqXP6KcXjUq2 ] ; real32_T fv0 [ _iBpWsoOMGVrqXP6KcXjUq2 ] ;
uint8_T imageBuff_1 [ _Vn2_qIHoUSNg7kzn9tUiG2 ] ; uint8_T imageBuff_2 [
_Vn2_qIHoUSNg7kzn9tUiG2 ] ; uint8_T imageBuff_3 [ _Vn2_qIHoUSNg7kzn9tUiG2 ] ;
boolean_T glxz0wys40_mbvzarwird [ _Vn2_qIHoUSNg7kzn9tUiG2 ] ; real_T vert [
_WEAeZOO5GNC_ZOlBZh0jr_ ] ; real_T av1241wy3a_cl54gopm0x [
_WEAeZOO5GNC_ZOlBZh0jr_ ] ; real_T linea1_data [ _WEAeZOO5GNC_ZOlBZh0jr_ ] ;
real_T V_data [ _WEAeZOO5GNC_ZOlBZh0jr_ ] ; real_T b_A_data [
_WEAeZOO5GNC_ZOlBZh0jr_ ] ; real_T m5enzivga1_kkiq3xxxve [
_kIF78eKlhsUh2Y30L2Fcf_ ] ; real_T tmp_data [ _kIF78eKlhsUh2Y30L2Fcf_ ] ;
real_T vert_data [ _kIF78eKlhsUh2Y30L2Fcf_ ] ; real_T b_B_data [
_kIF78eKlhsUh2Y30L2Fcf_ ] ; real_T d_linea1_data [ _zXirTuZ016Wyh2w9_LJvH2 ]
; real_T tmp_data_cxarnvbvui [ _zXirTuZ016Wyh2w9_LJvH2 ] ; real_T
d_linea1_data_bhxxfovxdy [ _3_ux9LEbXeSmB5wgIiDJm0 ] ; real_T dv2 [
_aoel664zPcTjzpXADn7l40 ] ; real_T rangos1_data [ _g7WFphbd05O6bEjctOzUc1 ] ;
real_T ioum3rfr4a_pbm3vprmfu [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T b_rangos [
_g7WFphbd05O6bEjctOzUc1 ] ; real_T f [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T
tau_data [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T work [ _gN74BbsU5wqNjkJbC9b672
] ; real_T vn1 [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T vn2 [
_gN74BbsU5wqNjkJbC9b672 ] ; real_T p_vert ; real_T cuenta ; real_T pendiente
; real_T gra ; real_T jrixtipdbg_cv5hdgrwft ; real_T ex ; real_T d_ex ;
real_T d0 ; real_T wj ; real_T temp2 ; real_T b_atmp ; real_T xnorm ; real_T
scale ; real_T absxk ; real_T t ; real_T cuenta_fqdqrf4qbc ; real_T c ;
real_T jfwz2usjq1_g2mlkqadfk ; real_T j051ekpi4d_g1smspu5ke ; int32_T
linea1_size [ _gN74BbsU5wqNjkJbC9b672 ] ; int32_T av1241wy3a_size [
_gN74BbsU5wqNjkJbC9b672 ] ; int32_T V_size [ _gN74BbsU5wqNjkJbC9b672 ] ;
int32_T jpvt [ _gN74BbsU5wqNjkJbC9b672 ] ; int32_T b_A_size [
_gN74BbsU5wqNjkJbC9b672 ] ; int32_T n ; int32_T b ; int32_T idx ; int32_T
rangos1_size ; int32_T ioum3rfr4a_size ; int32_T e ; int32_T idx_merlcviukg ;
int32_T loop_ub ; int32_T linea_size ; int32_T tmp_size ; int32_T
d_linea1_size ; int32_T vert_size ; int32_T d_linea1_size_nz4o0shxby ;
int32_T vert_size_ppxrqq0gsf ; int32_T tmp_size_llw0u2ae0v ; int32_T
linea_size_tmp ; int32_T rangos ; int32_T n_jwzvbuczlb ; int32_T k ; int32_T
mn ; int32_T minmn ; int32_T maxmn ; int32_T b_j ; int32_T c_i ; int32_T
tau_size ; int32_T m ; int32_T mn_dhmrxtyqop ; uint32_T u0 ; eo4bbte2ey
otjykwnhb3s ; } ircitwx3zdm ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { bjqsgn0csy l152eirbdu ; real_T hlax104bdy ; volatile real_T
ixsluchfec [ _gN74BbsU5wqNjkJbC9b672 ] ; volatile real_T kcuzykzzyz [
_gN74BbsU5wqNjkJbC9b672 ] ; volatile int8_T owvd5ta24v ; volatile int8_T
flqfj34f1w ; volatile boolean_T mkaglnvxwl ; boolean_T jjrfotind4 ;
dmp1xsadgu otjykwnhb3s ; } nllkaxiwhzw ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct bpvdgm2xq5_ { uint8_T Constant_Value ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct nu4qaxumex_ { real_T outlierBelowFloor_const ; real_T
outlierJump_const ; real_T currentEstimateVeryOffFromPressure_const ; real_T
currentStateVeryOffsonarflt_const ; real_T Checkerrorcondition_const ; real_T
u0continuousOFerrors_const ; real32_T DiscreteDerivative_ICPrevScaledInput ;
real32_T CompareToConstant_const ; real32_T CompareToConstant1_const ;
real32_T maxp_const ; real32_T maxq_const ; real32_T maxw1_const ; real32_T
maxw2_const ; real32_T maxdw1_const ; real32_T maxdw2_const ; real32_T
maxp2_const ; real32_T maxq2_const ; real32_T maxw3_const ; real32_T
maxw4_const ; real32_T minHeightforOF_const ; real32_T
DeactivateAccelerationIfOFisnotusedduetolowaltitude_const ; real32_T
donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con ; real32_T
donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co ; real32_T
CompareToConstant2_const ; real32_T CompareToConstant4_const ; real32_T
CompareToConstant3_const ; real32_T CompareToConstant5_const ; real32_T
CompareToConstant_const_ohohe2mqpr ; real32_T
CompareToConstant1_const_jtmdcqqffk ; uint32_T WrapToZero_Threshold ;
uint32_T WrapToZero_Threshold_cbi20d0fm2 ; uint32_T
WrapToZero_Threshold_ayznlculjr ; uint32_T CompareToConstant_const_e4sjfcivyt
; uint32_T CompareToConstant_const_h5ihgv12fp ; real_T _Value ; real_T
Lykyhatkk1_Y0 ; real_T deltax_Y0 ; real_T Delay2_InitialCondition ; real_T
X0_Value [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T SaturationSonar_LowerSat ;
real_T soonarFilter_IIR_NumCoef [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T
soonarFilter_IIR_DenCoef [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T
soonarFilter_IIR_InitialStates ; real_T KalmanGainM_Value [
_gN74BbsU5wqNjkJbC9b672 ] ; real_T C_Value [ _gN74BbsU5wqNjkJbC9b672 ] ;
real_T KalmanGainM_Value_pfy40h4nbl [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T
A_Value [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T KalmanGainL_Value [
_g7WFphbd05O6bEjctOzUc1 ] ; real_T gravity_Value [ _nfvdmbxYkVXzXnpHyWwmg2 ]
; real_T gravity_Value_pfc04gf1y0 [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real_T
gainaccinput_Gain ; real_T B_Value [ _gN74BbsU5wqNjkJbC9b672 ] ; real_T
D_Value ; real_T KalmanGainL_Value_myzlfjjodt [ _gN74BbsU5wqNjkJbC9b672 ] ;
real_T Wait3Seconds_Value ; real_T DelayOneStep_InitialCondition ; real_T
u5meters_Value ; real_T CovarianceZ_Value [ _g7WFphbd05O6bEjctOzUc1 ] ;
real_T P0_Value [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T
CovarianceZ_Value_jdj5fnfsis [ _g7WFphbd05O6bEjctOzUc1 ] ; real_T G_Value [
_gN74BbsU5wqNjkJbC9b672 ] ; real_T ConstantP_Value ; real_T H_Value ; real_T
N_Value ; real_T Q_Value ; real_T R_Value ; real_T ConstantP_Value_btxkh4allu
; real32_T D_xy_Gain [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T Gain_Gain ;
real32_T Saturation_UpperSat ; real32_T Saturation_LowerSat ; real32_T
P_xy_Gain [ _gN74BbsU5wqNjkJbC9b672 ] ; real32_T D_z1_Gain ; real32_T
P_z1_Gain ; real32_T takeoff_gain1_Gain ; real32_T _Value_hyihbm215y ;
real32_T Gain1_Gain ; real32_T Gain_Gain_bhgseiuany ; real32_T Gain2_Gain ;
real32_T Gain3_Gain ; real32_T Gain4_Gain ; real32_T Gain_Gain_fiewmprxxm ;
real32_T opticalFlowErrorCorrect_Gain ; real32_T Lykyhatkk1_Y0_j0mf11zz4c ;
real32_T deltax_Y0_g3sqpfxhn2 ; real32_T
TorqueTotalThrustToThrustPerMotor_Value [ _GL1cfYXlov7alqvUlVUDz0 ] ;
real32_T SimplyIntegrateVelocity_gainval ; real32_T
SimplyIntegrateVelocity_IC ; real32_T invertzaxisGain_Gain ; real32_T
prsToAltGain_Gain ; real32_T pressureFilter_IIR_NumCoef [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T pressureFilter_IIR_DenCoef [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T pressureFilter_IIR_InitialStates ;
real32_T Memory_InitialCondition [ _nfvdmbxYkVXzXnpHyWwmg2 ] ; real32_T
Constant_Value ; real32_T Gain_Gain_dtqbjn340p ; real32_T
Assumingthatcalibwasdonelevel_Bias [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T
inverseIMU_gain_Gain [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T
IIR_IMUgyro_r_NumCoef [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T
IIR_IMUgyro_r_DenCoef [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T
IIR_IMUgyro_r_InitialStates ; real32_T Gain_Gain_npgyww433p ; real32_T
FIR_IMUaccel_InitialStates ; real32_T FIR_IMUaccel_Coefficients [
_RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T Constant_Value_nmpgfc0332 ; real32_T
Merge_InitialOutput ; real32_T X0_Value_emw2vnukc0 [ _gN74BbsU5wqNjkJbC9b672
] ; real32_T C_Value_gmgjyss3ge [ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T
IIRgyroz_NumCoef [ _RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T IIRgyroz_DenCoef [
_RAQgyWVtpyqfEVcLRZFTL_ ] ; real32_T IIRgyroz_InitialStates ; real32_T
TSamp_WtEt ; real32_T Delay_InitialCondition ; real32_T
Delay1_InitialCondition ; real32_T D_pr_Gain [ _gN74BbsU5wqNjkJbC9b672 ] ;
real32_T DiscreteTimeIntegrator_gainval ; real32_T DiscreteTimeIntegrator_IC
; real32_T DiscreteTimeIntegrator_UpperSat ; real32_T
DiscreteTimeIntegrator_LowerSat ; real32_T I_pr_Gain ; real32_T P_pr_Gain [
_gN74BbsU5wqNjkJbC9b672 ] ; real32_T w1_Value ; real32_T
DiscreteTimeIntegrator_gainval_lzga2lo1lc ; real32_T
DiscreteTimeIntegrator_IC_hxxdupwioo ; real32_T
DiscreteTimeIntegrator_UpperSat_ilscgwq3om ; real32_T
DiscreteTimeIntegrator_LowerSat_g41gxybmmk ; real32_T
SaturationThrust1_UpperSat ; real32_T SaturationThrust1_LowerSat ; real32_T
P_yaw_Gain ; real32_T D_yaw_Gain ; real32_T ThrustToMotorCommand_Gain ;
real32_T Saturation5_UpperSat ; real32_T Saturation5_LowerSat ; real32_T
MotorDirections_Gain [ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T
A_Value_ewqpctijn1 [ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T B_Value_i13if20uk0
[ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T D_Value_bwgqvgyc5h [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T Delay_InitialCondition_hdmm1jsxtj ;
real32_T antiWU_Gain_Gain ; real32_T I_pr_Gain_ctpf4un5rn ; real32_T
Gain_Gain_f5jshqwgc3 ; real32_T Gain1_Gain_lkbjov0unm ; real32_T
P0_Value_lwgo43ncu5 [ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T G_Value_k4st4sfjeo
[ _g7WFphbd05O6bEjctOzUc1 ] ; real32_T H_Value_h01hq05eql [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T N_Value_e2um10uy1e [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T Q_Value_go5g3srejg [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T R_Value_dwnn5gd1vw [
_g7WFphbd05O6bEjctOzUc1 ] ; real32_T Constant_Value_efud2ldwcl ; real32_T
Constant_Value_mljbaqcyea ; uint32_T Delay2_DelayLength ; uint32_T
MemoryX_DelayLength ; uint32_T MemoryX_DelayLength_maliovco1p ; uint32_T
Output_InitialCondition ; uint32_T Delay_DelayLength ; uint32_T
Delay1_DelayLength ; uint32_T Output_InitialCondition_mzupedt2f0 ; uint32_T
Delay_DelayLength_gtjd3l2ukv ; uint32_T FixPtConstant_Value ; uint32_T
Constant_Value_h5h2zzz030 ; uint32_T Output_InitialCondition_elido1l3xk ;
uint32_T DelayOneStep_DelayLength ; uint32_T FixPtConstant_Value_mb25y5zhen ;
uint32_T Constant_Value_i1bggazskh ; uint32_T FixPtConstant_Value_etd5qzz33b
; uint32_T Constant_Value_axtqdou3ka ; boolean_T controlModePosVsOrient_Value
; boolean_T Constant_Value_b0jirepcd5 ; boolean_T Constant_Value_adqbc4iokf ;
boolean_T Reset_Value ; uint8_T Merge_InitialOutput_n15knxd4h3 ; uint8_T
ManualSwitchPZ_CurrentSetting ; uint8_T
ManualSwitchPZ_CurrentSetting_f20w1ldp3i ; bpvdgm2xq5 ciy1c2o0rv ; bpvdgm2xq5
jvbbqhrajh ; bpvdgm2xq5 clwiujjdqo ; bpvdgm2xq5 acfz1zxm4t ; bpvdgm2xq5
ghadbep3bbv ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct ileg2v2ld1r_ { real_T Thresholdforeachpixel_const ; uint16_T
Thresholdfortotalwhitepixels_const ; real_T Constant_Value ; real_T
Delay_InitialCondition ; real_T RateTransition1_InitialCondition ; real_T
RateTransition2_InitialCondition ; uint32_T Delay_DelayLength ; boolean_T
RateTransition_InitialCondition ; nu4qaxumex otjykwnhb3s ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
struct diqjpw4041 { const char_T * * errorStatus ; } ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
typedef struct { ipf5ube4r0 rtm ; } lhjbdsj2rjg ;
#endif
extern struct_8SSZ93PxvPkADZcA4gG8MD rtP_Sensors ; extern CommandBus
cmd_inport ; extern SensorsBus sensor_inport ; extern real32_T motors_outport
[ _g7WFphbd05O6bEjctOzUc1 ] ; extern uint8_T flag_outport ; extern void
ha1ipjbq54 ( void ) ; extern void gwlyno50ln ( void ) ; extern void
k3yxem35zg ( void ) ; extern void bog0frvixl ( void ) ; extern void
flightControlSystemTID0 ( void ) ; extern void flightControlSystemTID1 ( void
) ; extern void f4qzdbbxmw ( const char_T * * rt_errorStatus , const
rtTimingBridge * timingBridge , int_T mdlref_TID0 , int_T mdlref_TID1 ) ;
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern void ghadbep3bb ( uint8_T * hfpztkhwej , bpvdgm2xq5 * localP ) ;
extern void ic5jb3movn ( eo4bbte2ey * localB , dmp1xsadgu * localDW ,
nu4qaxumex * localP ) ; extern void bxsrqc204k ( dmp1xsadgu * localDW ,
nu4qaxumex * localP ) ; extern void cyp5v4ller ( dmp1xsadgu * localDW ) ;
extern void kegjp2lgms ( eo4bbte2ey * localB , dmp1xsadgu * localDW ,
nu4qaxumex * localP ) ; extern void otjykwnhb3TID0 ( const CommandBus *
ipxpc4eli1 , const SensorsBus * fp0u5nlpgw , boolean_T ay1xsyaztb , real_T
gq2sw3ueo2 , real_T imah0ypuf5 , eo4bbte2ey * localB , dmp1xsadgu * localDW ,
nu4qaxumex * localP ) ; extern void otjykwnhb3TID1 ( eo4bbte2ey * localB ,
dmp1xsadgu * localDW ) ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern lhjbdsj2rjg lhjbdsj2rj ;
#endif
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern ircitwx3zdm ksm0js2nhsy ; extern nllkaxiwhzw dqykr4eggmg ;
#endif
#endif
