/*
 * flightControlSystem_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "flightControlSystem".
 *
 * Model version              : 1.873
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Fri Nov 15 15:12:51 2019
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "flightControlSystem.h"
#include "flightControlSystem_private.h"

/* Block parameters (default storage) */
P_flightControlSystem_T flightControlSystem_P = {
  /* Variable: Sensors
   * Referenced by:
   *   '<S45>/SaturationSonar'
   *   '<S92>/Constant'
   */
  {
    { 1.00596, 1.00383, 0.99454 },

    { 0.99861, 1.00644, 0.99997 },

    {
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0 },
      190.0,
      0.707,

      { 1.00596, 0.0, 0.0, 0.0, 1.00383, 0.0, 0.0, 0.0, 0.99454 },

      { 0.09, -0.06, 0.33699999999999974 },

      { -50.0, -50.0, -50.0, 50.0, 50.0, 50.0 },
      190.0,
      0.707,

      { 0.99861, 0.0, 0.0, 0.0, 1.00644, 0.0, 0.0, 0.0, 0.99997 },

      { -0.0095, -0.0075, 0.0015 },

      { 0.0, 0.0, 0.0 },

      { -10.0, -10.0, -10.0, 10.0, 10.0, 10.0 },

      { 41.0, 41.0, 41.0, 41.0, 41.0, 41.0 },

      { 0.8, 0.8, 0.8, 0.025, 0.025, 0.025 },

      { 0.00021831529882618725, 0.00018641345254680647, 0.00037251068300213613,
        1.0651514622688397e-8, 1.3021327403798377e-8, 1.1929474437781302e-8 }
    },

    {
      1.0,
      41.0
    },
    -99.0,
    -9.0,

    {
      { -99.0, 0.0, 0.0, -9.0 },
      0.0,

      { 3.5, 70.0 }
    },
    1.0,
    1.225,
    12.01725,
    101270.95,

    { 0.99407531114557246, 0.99618461293246863, 1.0054899752649467,
      1.0013919347893572, 0.99360120821906917, 1.0000300009000269 },
    0.44,
    1.0
  },

  /* Mask Parameter: Thresholdfortotalwhitepixels_const
   * Referenced by: '<S174>/Constant'
   */
  1400U,

  /* Mask Parameter: Thresholdforeachpixel1_const
   * Referenced by: '<S171>/Constant'
   */
  210U,

  /* Mask Parameter: Thresholdforeachpixel2_const
   * Referenced by: '<S172>/Constant'
   */
  180U,

  /* Mask Parameter: Thresholdforeachpixel3_const
   * Referenced by: '<S173>/Constant'
   */
  180U,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition1'
   */
  0.0,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<S2>/Delay'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<S2>/Delay1'
   */
  1U,

  /* Computed Parameter: Delay2_DelayLength
   * Referenced by: '<S2>/Delay2'
   */
  1U,

  /* Computed Parameter: RateTransition_InitialCondition
   * Referenced by: '<Root>/Rate Transition'
   */
  0,

  /* Start of '<Root>/Control System' */
  {
    /* Mask Parameter: outlierBelowFloor_const
     * Referenced by: '<S47>/Constant'
     */
    0.0,

    /* Mask Parameter: outlierJump_const
     * Referenced by: '<S95>/Constant'
     */
    0.1,

    /* Mask Parameter: currentEstimateVeryOffFromPressure_const
     * Referenced by: '<S93>/Constant'
     */
    0.8,

    /* Mask Parameter: currentStateVeryOffsonarflt_const
     * Referenced by: '<S94>/Constant'
     */
    0.4,

    /* Mask Parameter: Checkerrorcondition_const
     * Referenced by: '<S18>/Constant'
     */
    -1.0,

    /* Mask Parameter: u0continuousOFerrors_const
     * Referenced by: '<S17>/Constant'
     */
    50.0,

    /* Mask Parameter: DiscreteDerivative_ICPrevScaledInput
     * Referenced by: '<S111>/UD'
     */
    0.0F,

    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S38>/Constant'
     */
    9.79038F,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S39>/Constant'
     */
    9.82962F,

    /* Mask Parameter: maxp_const
     * Referenced by: '<S114>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxq_const
     * Referenced by: '<S116>/Constant'
     */
    0.6F,

    /* Mask Parameter: maxw1_const
     * Referenced by: '<S118>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxw2_const
     * Referenced by: '<S119>/Constant'
     */
    7.0F,

    /* Mask Parameter: maxdw1_const
     * Referenced by: '<S112>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxdw2_const
     * Referenced by: '<S113>/Constant'
     */
    80.0F,

    /* Mask Parameter: maxp2_const
     * Referenced by: '<S115>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxq2_const
     * Referenced by: '<S117>/Constant'
     */
    0.5F,

    /* Mask Parameter: maxw3_const
     * Referenced by: '<S120>/Constant'
     */
    5.0F,

    /* Mask Parameter: maxw4_const
     * Referenced by: '<S121>/Constant'
     */
    5.0F,

    /* Mask Parameter: minHeightforOF_const
     * Referenced by: '<S122>/Constant'
     */
    -0.4F,

    /* Mask Parameter: DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
     * Referenced by: '<S104>/Constant'
     */
    -0.4F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
     * Referenced by: '<S106>/Constant'
     */
    0.0F,

    /* Mask Parameter: donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
     * Referenced by: '<S107>/Constant'
     */
    0.0F,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S21>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S23>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S22>/Constant'
     */
    6.0F,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S24>/Constant'
     */
    0.01F,

    /* Mask Parameter: CompareToConstant_const_j2aeaztlxq
     * Referenced by: '<S19>/Constant'
     */
    10.0F,

    /* Mask Parameter: CompareToConstant1_const_oea4nh0fds
     * Referenced by: '<S20>/Constant'
     */
    10.0F,

    /* Mask Parameter: WrapToZero_Threshold
     * Referenced by: '<S16>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_laizy3sja4
     * Referenced by: '<S32>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: WrapToZero_Threshold_m14ba5jvav
     * Referenced by: '<S110>/FixPt Switch'
     */
    4294967295U,

    /* Mask Parameter: CompareToConstant_const_oadmvaq2bv
     * Referenced by: '<S100>/Constant'
     */
    800U,

    /* Mask Parameter: CompareToConstant_const_o2ywjbil1g
     * Referenced by: '<S13>/Constant'
     */
    100U,

    /* Expression: 0
     * Referenced by: '<S4>/ '
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S90>/L*(y[k]-yhat[k|k-1])'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S91>/deltax'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S35>/Delay2'
     */
    0.0,

    /* Expression: pInitialization.X0
     * Referenced by: '<S44>/X0'
     */
    { -0.046, 0.0 },

    /* Expression: -inf
     * Referenced by: '<S45>/SaturationSonar'
     */
    0.0,

    /* Expression: Estimator.alt.filterSonarNum
     * Referenced by: '<S45>/soonarFilter_IIR'
     */
    { 3.7568380197861018E-6, 1.1270514059358305E-5, 1.1270514059358305E-5,
      3.7568380197861018E-6 },

    /* Expression: Estimator.alt.filterSonarDen
     * Referenced by: '<S45>/soonarFilter_IIR'
     */
    { 1.0, -2.9371707284498907, 2.8762997234793319, -0.939098940325283 },

    /* Expression: 0
     * Referenced by: '<S45>/soonarFilter_IIR'
     */
    0.0,

    /* Expression: pInitialization.M
     * Referenced by: '<S48>/KalmanGainM'
     */
    { 0.02624142064187163, 0.0697767360714917 },

    /* Expression: pInitialization.C
     * Referenced by: '<S44>/C'
     */
    { 1.0, 0.0 },

    /* Expression: pInitialization.M
     * Referenced by: '<S123>/KalmanGainM'
     */
    { 0.12546560898608972, 0.0, 0.0, 0.12546560898608972 },

    /* Expression: pInitialization.A
     * Referenced by: '<S44>/A'
     */
    { 1.0, 0.0, 0.005, 1.0 },

    /* Expression: pInitialization.L
     * Referenced by: '<S123>/KalmanGainL'
     */
    { 0.1254656089860898, 0.0, -0.0, 0.1254656089860898 },

    /* Expression: [0 0 g]
     * Referenced by: '<S35>/gravity'
     */
    { 0.0, 0.0, 9.81 },

    /* Expression: [0 0 -g]
     * Referenced by: '<S99>/gravity'
     */
    { 0.0, 0.0, -9.81 },

    /* Expression: Estimator.pos.accelerationInputGain
     * Referenced by: '<S99>/gainaccinput'
     */
    0.2,

    /* Expression: pInitialization.B
     * Referenced by: '<S44>/B'
     */
    { 0.0, 0.005 },

    /* Expression: pInitialization.D
     * Referenced by: '<S44>/D'
     */
    0.0,

    /* Expression: pInitialization.L
     * Referenced by: '<S48>/KalmanGainL'
     */
    { 0.026590304322229058, 0.06977673607149236 },

    /* Expression: 200*3
     * Referenced by: '<S4>/Wait  3 Seconds'
     */
    600.0,

    /* Expression: 0.0
     * Referenced by: '<S4>/Delay One Step'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S4>/0.5 meters'
     */
    0.5,

    /* Computed Parameter: D_xy_Gain
     * Referenced by: '<S9>/D_xy'
     */
    { 0.1F, -0.1F },

    /* Computed Parameter: Gain_Gain
     * Referenced by: '<S9>/Gain'
     */
    -1.0F,

    /* Computed Parameter: Saturation_UpperSat
     * Referenced by: '<S9>/Saturation'
     */
    3.0F,

    /* Computed Parameter: Saturation_LowerSat
     * Referenced by: '<S9>/Saturation'
     */
    -3.0F,

    /* Computed Parameter: P_xy_Gain
     * Referenced by: '<S9>/P_xy'
     */
    { -0.24F, 0.24F },

    /* Computed Parameter: D_z1_Gain
     * Referenced by: '<S11>/D_z1'
     */
    0.5F,

    /* Computed Parameter: P_z1_Gain
     * Referenced by: '<S11>/P_z1'
     */
    0.8F,

    /* Expression: Controller.takeoffGain
     * Referenced by: '<S11>/takeoff_gain1'
     */
    0.45F,

    /* Computed Parameter: _Value_ouzfzmlb2y
     * Referenced by: '<S4>/    '
     */
    0.0F,

    /* Computed Parameter: Gain1_Gain
     * Referenced by: '<S40>/Gain1'
     */
    0.001F,

    /* Computed Parameter: Gain_Gain_dvwjhkjmhw
     * Referenced by: '<S40>/Gain'
     */
    0.999F,

    /* Computed Parameter: Gain2_Gain
     * Referenced by: '<S40>/Gain2'
     */
    0.101936802F,

    /* Computed Parameter: Gain3_Gain
     * Referenced by: '<S40>/Gain3'
     */
    0.001F,

    /* Computed Parameter: Gain4_Gain
     * Referenced by: '<S40>/Gain4'
     */
    0.999F,

    /* Computed Parameter: Gain_Gain_b0xcv5ppve
     * Referenced by: '<S97>/Gain'
     */
    -1.0F,

    /* Computed Parameter: opticalFlowErrorCorrect_Gain
     * Referenced by: '<S97>/opticalFlowErrorCorrect'
     */
    1.15F,

    /* Computed Parameter: Lykyhatkk1_Y0_ly1kk4lmmc
     * Referenced by: '<S165>/L*(y[k]-yhat[k|k-1])'
     */
    0.0F,

    /* Computed Parameter: deltax_Y0_hbk4yyz1lk
     * Referenced by: '<S166>/deltax'
     */
    0.0F,

    /* Expression: Controller.Q2Ts
     * Referenced by: '<S8>/TorqueTotalThrustToThrustPerMotor'
     */
    { 0.25F, 0.25F, 0.25F, 0.25F, 103.573624F, -103.573624F, 103.573624F,
      -103.573624F, -5.66592F, -5.66592F, 5.66592F, 5.66592F, -5.66592F,
      5.66592F, 5.66592F, -5.66592F },

    /* Computed Parameter: SimplyIntegrateVelocity_gainval
     * Referenced by: '<S98>/SimplyIntegrateVelocity'
     */
    0.005F,

    /* Computed Parameter: SimplyIntegrateVelocity_IC
     * Referenced by: '<S98>/SimplyIntegrateVelocity'
     */
    0.0F,

    /* Computed Parameter: invertzaxisGain_Gain
     * Referenced by: '<S35>/invertzaxisGain'
     */
    -1.0F,

    /* Computed Parameter: prsToAltGain_Gain
     * Referenced by: '<S35>/prsToAltGain'
     */
    0.0832137167F,

    /* Computed Parameter: pressureFilter_IIR_NumCoef
     * Referenced by: '<S45>/pressureFilter_IIR'
     */
    { 3.75683794E-6F, 1.12705138E-5F, 1.12705138E-5F, 3.75683794E-6F },

    /* Computed Parameter: pressureFilter_IIR_DenCoef
     * Referenced by: '<S45>/pressureFilter_IIR'
     */
    { 1.0F, -2.93717074F, 2.87629962F, -0.939098954F },

    /* Computed Parameter: pressureFilter_IIR_InitialStates
     * Referenced by: '<S45>/pressureFilter_IIR'
     */
    0.0F,

    /* Computed Parameter: Assumingthatcalibwasdonelevel_Bias
     * Referenced by: '<S37>/Assuming that calib was done level!'
     */
    { 0.0F, 0.0F, 9.81F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: inverseIMU_gain_Gain
     * Referenced by: '<S37>/inverseIMU_gain'
     */
    { 0.994075298F, 0.996184587F, 1.00549F, 1.00139189F, 0.993601203F, 1.00003F
    },

    /* Computed Parameter: IIR_IMUgyro_r_NumCoef
     * Referenced by: '<S37>/IIR_IMUgyro_r'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIR_IMUgyro_r_DenCoef
     * Referenced by: '<S37>/IIR_IMUgyro_r'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIR_IMUgyro_r_InitialStates
     * Referenced by: '<S37>/IIR_IMUgyro_r'
     */
    0.0F,

    /* Expression: single(Estimator.complementaryFilterInit)
     * Referenced by: '<S34>/Memory'
     */
    { 0.0F, 0.0F, 0.0F },

    /* Expression: single(0)
     * Referenced by: '<S42>/Constant'
     */
    0.0F,

    /* Computed Parameter: Gain_Gain_nwkt5b5fro
     * Referenced by: '<S42>/Gain'
     */
    -1.0F,

    /* Computed Parameter: Gain_Gain_juztar0qtz
     * Referenced by: '<S34>/Gain'
     */
    0.005F,

    /* Computed Parameter: FIR_IMUaccel_InitialStates
     * Referenced by: '<S37>/FIR_IMUaccel'
     */
    0.0F,

    /* Computed Parameter: FIR_IMUaccel_Coefficients
     * Referenced by: '<S37>/FIR_IMUaccel'
     */
    { 0.0264077242F, 0.140531361F, 0.33306092F, 0.33306092F, 0.140531361F,
      0.0264077242F },

    /* Computed Parameter: Constant_Value_percv3dd1f
     * Referenced by: '<S34>/Constant'
     */
    2.0F,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S34>/Merge'
     */
    0.0F,

    /* Computed Parameter: X0_Value_lfdbgvehcb
     * Referenced by: '<S103>/X0'
     */
    { 0.0F, 0.0F },

    /* Computed Parameter: C_Value_p3s05liash
     * Referenced by: '<S103>/C'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: IIRgyroz_NumCoef
     * Referenced by: '<S102>/IIRgyroz'
     */
    { 0.282124132F, 1.27253926F, 2.42084408F, 2.42084408F, 1.27253926F,
      0.282124132F },

    /* Computed Parameter: IIRgyroz_DenCoef
     * Referenced by: '<S102>/IIRgyroz'
     */
    { 1.0F, 2.22871494F, 2.52446198F, 1.57725322F, 0.54102242F, 0.0795623958F },

    /* Computed Parameter: IIRgyroz_InitialStates
     * Referenced by: '<S102>/IIRgyroz'
     */
    0.0F,

    /* Computed Parameter: TSamp_WtEt
     * Referenced by: '<S111>/TSamp'
     */
    200.0F,

    /* Computed Parameter: Delay_InitialCondition
     * Referenced by: '<S97>/Delay'
     */
    0.0F,

    /* Computed Parameter: Delay1_InitialCondition
     * Referenced by: '<S6>/Delay1'
     */
    0.0F,

    /* Computed Parameter: D_pr_Gain
     * Referenced by: '<S7>/D_pr'
     */
    { 0.002F, 0.003F },

    /* Computed Parameter: DiscreteTimeIntegrator_gainval
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    2.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
     * Referenced by: '<S7>/Discrete-Time Integrator'
     */
    -2.0F,

    /* Computed Parameter: I_pr_Gain
     * Referenced by: '<S7>/I_pr'
     */
    0.01F,

    /* Computed Parameter: P_pr_Gain
     * Referenced by: '<S7>/P_pr'
     */
    { 0.013F, 0.011F },

    /* Computed Parameter: w1_Value
     * Referenced by: '<S11>/w1'
     */
    -0.61803F,

    /* Computed Parameter: DiscreteTimeIntegrator_gainval_b1wrfjbuk2
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.005F,

    /* Computed Parameter: DiscreteTimeIntegrator_IC_iymdtlt5j0
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    0.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_UpperSat_plvc2rxdg0
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    2.0F,

    /* Computed Parameter: DiscreteTimeIntegrator_LowerSat_cbbd1x44vs
     * Referenced by: '<S11>/Discrete-Time Integrator'
     */
    -2.0F,

    /* Computed Parameter: SaturationThrust1_UpperSat
     * Referenced by: '<S11>/SaturationThrust1'
     */
    1.20204329F,

    /* Computed Parameter: SaturationThrust1_LowerSat
     * Referenced by: '<S11>/SaturationThrust1'
     */
    -1.20204329F,

    /* Computed Parameter: P_yaw_Gain
     * Referenced by: '<S10>/P_yaw'
     */
    0.004F,

    /* Computed Parameter: D_yaw_Gain
     * Referenced by: '<S10>/D_yaw'
     */
    0.0012F,

    /* Computed Parameter: ThrustToMotorCommand_Gain
     * Referenced by: '<S12>/ThrustToMotorCommand'
     */
    -1530.72681F,

    /* Expression: Vehicle.Motor.maxLimit
     * Referenced by: '<S12>/Saturation5'
     */
    500.0F,

    /* Expression: Vehicle.Motor.minLimit
     * Referenced by: '<S12>/Saturation5'
     */
    10.0F,

    /* Computed Parameter: MotorDirections_Gain
     * Referenced by: '<S12>/MotorDirections'
     */
    { 1.0F, -1.0F, 1.0F, -1.0F },

    /* Computed Parameter: A_Value_l0gpbuxkte
     * Referenced by: '<S103>/A'
     */
    { 1.0F, 0.0F, 0.0F, 1.0F },

    /* Computed Parameter: B_Value_divnfjb1dq
     * Referenced by: '<S103>/B'
     */
    { 0.005F, 0.0F, 0.0F, 0.005F },

    /* Computed Parameter: D_Value_j0gctn4yse
     * Referenced by: '<S103>/D'
     */
    { 0.0F, 0.0F, 0.0F, 0.0F },

    /* Computed Parameter: Delay_InitialCondition_cot5fhlv10
     * Referenced by: '<S7>/Delay'
     */
    0.0F,

    /* Computed Parameter: antiWU_Gain_Gain
     * Referenced by: '<S7>/antiWU_Gain'
     */
    0.001F,

    /* Computed Parameter: I_pr_Gain_cswgo3ze1g
     * Referenced by: '<S11>/I_pr'
     */
    0.24F,

    /* Computed Parameter: Gain_Gain_nkg3zw25sw
     * Referenced by: '<S4>/Gain'
     */
    1.0F,

    /* Computed Parameter: Gain1_Gain_ov00v2ikfj
     * Referenced by: '<S4>/Gain1'
     */
    1.0F,

    /* Computed Parameter: Constant_Value_eesjyjh2ui
     * Referenced by: '<S16>/Constant'
     */
    0U,

    /* Computed Parameter: Constant_Value_phytu2r2f1
     * Referenced by: '<S32>/Constant'
     */
    0U,

    /* Computed Parameter: Constant_Value_o24gdufi11
     * Referenced by: '<S110>/Constant'
     */
    0U,

    /* Computed Parameter: Delay2_DelayLength
     * Referenced by: '<S35>/Delay2'
     */
    1U,

    /* Computed Parameter: MemoryX_DelayLength
     * Referenced by: '<S44>/MemoryX'
     */
    1U,

    /* Computed Parameter: MemoryX_DelayLength_hf1cizflt4
     * Referenced by: '<S103>/MemoryX'
     */
    1U,

    /* Computed Parameter: Output_InitialCondition
     * Referenced by: '<S101>/Output'
     */
    0U,

    /* Computed Parameter: Delay_DelayLength
     * Referenced by: '<S97>/Delay'
     */
    1U,

    /* Computed Parameter: Delay1_DelayLength
     * Referenced by: '<S6>/Delay1'
     */
    1U,

    /* Computed Parameter: Output_InitialCondition_c5nnqodi1t
     * Referenced by: '<S14>/Output'
     */
    0U,

    /* Computed Parameter: Delay_DelayLength_nnijsqwcwl
     * Referenced by: '<S7>/Delay'
     */
    1U,

    /* Computed Parameter: FixPtConstant_Value
     * Referenced by: '<S15>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: Output_InitialCondition_j3t1gcu1w1
     * Referenced by: '<S25>/Output'
     */
    0U,

    /* Computed Parameter: DelayOneStep_DelayLength
     * Referenced by: '<S4>/Delay One Step'
     */
    1U,

    /* Computed Parameter: FixPtConstant_Value_h5bewbcaxk
     * Referenced by: '<S31>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: FixPtConstant_Value_kchif4j3g4
     * Referenced by: '<S109>/FixPt Constant'
     */
    1U,

    /* Computed Parameter: controlModePosVsOrient_Value
     * Referenced by: '<S1>/controlModePosVsOrient'
     */
    1,

    /* Computed Parameter: Merge_InitialOutput_ey5vocp2a3
     * Referenced by: '<S4>/Merge'
     */
    0U,

    /* Start of '<S4>/Normal condition' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S28>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Normal condition' */

    /* Start of '<S4>/Ultrasound improper' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S29>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/Ultrasound improper' */

    /* Start of '<S4>/No optical flow ' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S27>/Constant'
       */
      0U
    }
    ,

    /* End of '<S4>/No optical flow ' */

    /* Start of '<S4>/estimator//Optical flow error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S30>/Constant'
       */
      99U
    }
    ,

    /* End of '<S4>/estimator//Optical flow error' */

    /* Start of '<S4>/Geofencing error' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S26>/Constant'
       */
      1U
    }
    /* End of '<S4>/Geofencing error' */
  }
  /* End of '<Root>/Control System' */
};
