  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Sensors
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Thresholdfortotalwhitepixels_const
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Thresholdforeachpixel1_const
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.Thresholdforeachpixel2_const
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.Thresholdforeachpixel3_const
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Delay_InitialCondition
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.Delay1_InitialCondition
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.Delay2_InitialCondition
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.RateTransition1_InitialCondition
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.Delay1_DelayLength
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.Delay2_DelayLength
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.RateTransition_InitialCondition
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.outlierBelowFloor_const
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.outlierJump_const
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.ControlSystem.currentEstimateVeryOffFromPressure_const
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.currentStateVeryOffsonarflt_const
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.Checkerrorcondition_const
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.ControlSystem.u0continuousOFerrors_const
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.DiscreteDerivative_ICPrevScaledInput
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant1_const
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.maxp_const
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.maxq_const
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.ControlSystem.maxw1_const
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.ControlSystem.maxw2_const
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.ControlSystem.maxdw1_const
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.ControlSystem.maxdw2_const
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.ControlSystem.maxp2_const
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.ControlSystem.maxq2_const
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.ControlSystem.maxw3_const
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.ControlSystem.maxw4_const
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 12;
	
	  ;% flightControlSystem_P.ControlSystem.minHeightforOF_const
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 13;
	
	  ;% flightControlSystem_P.ControlSystem.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.ControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.ControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 16;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant2_const
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 17;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant4_const
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 18;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant3_const
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 19;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant5_const
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 20;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_j2aeaztlxq
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 21;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant1_const_oea4nh0fds
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold_laizy3sja4
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold_m14ba5jvav
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_oadmvaq2bv
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_o2ywjbil1g
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem._Value
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.Lykyhatkk1_Y0
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.ControlSystem.deltax_Y0
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.Delay2_InitialCondition
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.X0_Value
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.ControlSystem.SaturationSonar_LowerSat
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.ControlSystem.soonarFilter_IIR_NumCoef
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.ControlSystem.soonarFilter_IIR_DenCoef
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.ControlSystem.soonarFilter_IIR_InitialStates
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 16;
	
	  ;% flightControlSystem_P.ControlSystem.C_Value
	  section.data(11).logicalSrcIdx = 57;
	  section.data(11).dtTransOffset = 18;
	
	  ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value_jjsg0b0z0q
	  section.data(12).logicalSrcIdx = 58;
	  section.data(12).dtTransOffset = 20;
	
	  ;% flightControlSystem_P.ControlSystem.A_Value
	  section.data(13).logicalSrcIdx = 59;
	  section.data(13).dtTransOffset = 24;
	
	  ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value
	  section.data(14).logicalSrcIdx = 60;
	  section.data(14).dtTransOffset = 28;
	
	  ;% flightControlSystem_P.ControlSystem.gravity_Value
	  section.data(15).logicalSrcIdx = 61;
	  section.data(15).dtTransOffset = 32;
	
	  ;% flightControlSystem_P.ControlSystem.gravity_Value_dibfthgkk3
	  section.data(16).logicalSrcIdx = 62;
	  section.data(16).dtTransOffset = 35;
	
	  ;% flightControlSystem_P.ControlSystem.gainaccinput_Gain
	  section.data(17).logicalSrcIdx = 63;
	  section.data(17).dtTransOffset = 38;
	
	  ;% flightControlSystem_P.ControlSystem.B_Value
	  section.data(18).logicalSrcIdx = 64;
	  section.data(18).dtTransOffset = 39;
	
	  ;% flightControlSystem_P.ControlSystem.D_Value
	  section.data(19).logicalSrcIdx = 65;
	  section.data(19).dtTransOffset = 41;
	
	  ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value_cqw4rtoxbn
	  section.data(20).logicalSrcIdx = 66;
	  section.data(20).dtTransOffset = 42;
	
	  ;% flightControlSystem_P.ControlSystem.Wait3Seconds_Value
	  section.data(21).logicalSrcIdx = 67;
	  section.data(21).dtTransOffset = 44;
	
	  ;% flightControlSystem_P.ControlSystem.DelayOneStep_InitialCondition
	  section.data(22).logicalSrcIdx = 68;
	  section.data(22).dtTransOffset = 45;
	
	  ;% flightControlSystem_P.ControlSystem.u5meters_Value
	  section.data(23).logicalSrcIdx = 69;
	  section.data(23).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 75;
      section.data(75)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.D_xy_Gain
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.Saturation_UpperSat
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.Saturation_LowerSat
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.ControlSystem.P_xy_Gain
	  section.data(5).logicalSrcIdx = 74;
	  section.data(5).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.ControlSystem.D_z1_Gain
	  section.data(6).logicalSrcIdx = 75;
	  section.data(6).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.ControlSystem.P_z1_Gain
	  section.data(7).logicalSrcIdx = 76;
	  section.data(7).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.ControlSystem.takeoff_gain1_Gain
	  section.data(8).logicalSrcIdx = 77;
	  section.data(8).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.ControlSystem._Value_ouzfzmlb2y
	  section.data(9).logicalSrcIdx = 78;
	  section.data(9).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.ControlSystem.Gain1_Gain
	  section.data(10).logicalSrcIdx = 79;
	  section.data(10).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain_dvwjhkjmhw
	  section.data(11).logicalSrcIdx = 80;
	  section.data(11).dtTransOffset = 12;
	
	  ;% flightControlSystem_P.ControlSystem.Gain2_Gain
	  section.data(12).logicalSrcIdx = 81;
	  section.data(12).dtTransOffset = 13;
	
	  ;% flightControlSystem_P.ControlSystem.Gain3_Gain
	  section.data(13).logicalSrcIdx = 82;
	  section.data(13).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.ControlSystem.Gain4_Gain
	  section.data(14).logicalSrcIdx = 83;
	  section.data(14).dtTransOffset = 15;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain_b0xcv5ppve
	  section.data(15).logicalSrcIdx = 84;
	  section.data(15).dtTransOffset = 16;
	
	  ;% flightControlSystem_P.ControlSystem.opticalFlowErrorCorrect_Gain
	  section.data(16).logicalSrcIdx = 85;
	  section.data(16).dtTransOffset = 17;
	
	  ;% flightControlSystem_P.ControlSystem.Lykyhatkk1_Y0_ly1kk4lmmc
	  section.data(17).logicalSrcIdx = 86;
	  section.data(17).dtTransOffset = 18;
	
	  ;% flightControlSystem_P.ControlSystem.deltax_Y0_hbk4yyz1lk
	  section.data(18).logicalSrcIdx = 87;
	  section.data(18).dtTransOffset = 19;
	
	  ;% flightControlSystem_P.ControlSystem.TorqueTotalThrustToThrustPerMotor_Value
	  section.data(19).logicalSrcIdx = 88;
	  section.data(19).dtTransOffset = 20;
	
	  ;% flightControlSystem_P.ControlSystem.SimplyIntegrateVelocity_gainval
	  section.data(20).logicalSrcIdx = 89;
	  section.data(20).dtTransOffset = 36;
	
	  ;% flightControlSystem_P.ControlSystem.SimplyIntegrateVelocity_IC
	  section.data(21).logicalSrcIdx = 90;
	  section.data(21).dtTransOffset = 37;
	
	  ;% flightControlSystem_P.ControlSystem.invertzaxisGain_Gain
	  section.data(22).logicalSrcIdx = 91;
	  section.data(22).dtTransOffset = 38;
	
	  ;% flightControlSystem_P.ControlSystem.prsToAltGain_Gain
	  section.data(23).logicalSrcIdx = 92;
	  section.data(23).dtTransOffset = 39;
	
	  ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_NumCoef
	  section.data(24).logicalSrcIdx = 93;
	  section.data(24).dtTransOffset = 40;
	
	  ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_DenCoef
	  section.data(25).logicalSrcIdx = 94;
	  section.data(25).dtTransOffset = 44;
	
	  ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_InitialStates
	  section.data(26).logicalSrcIdx = 95;
	  section.data(26).dtTransOffset = 48;
	
	  ;% flightControlSystem_P.ControlSystem.Memory_InitialCondition
	  section.data(27).logicalSrcIdx = 96;
	  section.data(27).dtTransOffset = 49;
	
	  ;% flightControlSystem_P.ControlSystem.Constant_Value
	  section.data(28).logicalSrcIdx = 97;
	  section.data(28).dtTransOffset = 52;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain_nwkt5b5fro
	  section.data(29).logicalSrcIdx = 98;
	  section.data(29).dtTransOffset = 53;
	
	  ;% flightControlSystem_P.ControlSystem.Assumingthatcalibwasdonelevel_Bias
	  section.data(30).logicalSrcIdx = 99;
	  section.data(30).dtTransOffset = 54;
	
	  ;% flightControlSystem_P.ControlSystem.inverseIMU_gain_Gain
	  section.data(31).logicalSrcIdx = 100;
	  section.data(31).dtTransOffset = 60;
	
	  ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_NumCoef
	  section.data(32).logicalSrcIdx = 101;
	  section.data(32).dtTransOffset = 66;
	
	  ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_DenCoef
	  section.data(33).logicalSrcIdx = 102;
	  section.data(33).dtTransOffset = 72;
	
	  ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_InitialStates
	  section.data(34).logicalSrcIdx = 103;
	  section.data(34).dtTransOffset = 78;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain_juztar0qtz
	  section.data(35).logicalSrcIdx = 104;
	  section.data(35).dtTransOffset = 79;
	
	  ;% flightControlSystem_P.ControlSystem.FIR_IMUaccel_InitialStates
	  section.data(36).logicalSrcIdx = 105;
	  section.data(36).dtTransOffset = 80;
	
	  ;% flightControlSystem_P.ControlSystem.FIR_IMUaccel_Coefficients
	  section.data(37).logicalSrcIdx = 106;
	  section.data(37).dtTransOffset = 81;
	
	  ;% flightControlSystem_P.ControlSystem.Constant_Value_percv3dd1f
	  section.data(38).logicalSrcIdx = 107;
	  section.data(38).dtTransOffset = 87;
	
	  ;% flightControlSystem_P.ControlSystem.Merge_InitialOutput
	  section.data(39).logicalSrcIdx = 108;
	  section.data(39).dtTransOffset = 88;
	
	  ;% flightControlSystem_P.ControlSystem.X0_Value_lfdbgvehcb
	  section.data(40).logicalSrcIdx = 109;
	  section.data(40).dtTransOffset = 89;
	
	  ;% flightControlSystem_P.ControlSystem.C_Value_p3s05liash
	  section.data(41).logicalSrcIdx = 110;
	  section.data(41).dtTransOffset = 91;
	
	  ;% flightControlSystem_P.ControlSystem.IIRgyroz_NumCoef
	  section.data(42).logicalSrcIdx = 111;
	  section.data(42).dtTransOffset = 95;
	
	  ;% flightControlSystem_P.ControlSystem.IIRgyroz_DenCoef
	  section.data(43).logicalSrcIdx = 112;
	  section.data(43).dtTransOffset = 101;
	
	  ;% flightControlSystem_P.ControlSystem.IIRgyroz_InitialStates
	  section.data(44).logicalSrcIdx = 113;
	  section.data(44).dtTransOffset = 107;
	
	  ;% flightControlSystem_P.ControlSystem.TSamp_WtEt
	  section.data(45).logicalSrcIdx = 114;
	  section.data(45).dtTransOffset = 108;
	
	  ;% flightControlSystem_P.ControlSystem.Delay_InitialCondition
	  section.data(46).logicalSrcIdx = 115;
	  section.data(46).dtTransOffset = 109;
	
	  ;% flightControlSystem_P.ControlSystem.Delay1_InitialCondition
	  section.data(47).logicalSrcIdx = 116;
	  section.data(47).dtTransOffset = 110;
	
	  ;% flightControlSystem_P.ControlSystem.D_pr_Gain
	  section.data(48).logicalSrcIdx = 117;
	  section.data(48).dtTransOffset = 111;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_gainval
	  section.data(49).logicalSrcIdx = 118;
	  section.data(49).dtTransOffset = 113;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_IC
	  section.data(50).logicalSrcIdx = 119;
	  section.data(50).dtTransOffset = 114;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_UpperSat
	  section.data(51).logicalSrcIdx = 120;
	  section.data(51).dtTransOffset = 115;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_LowerSat
	  section.data(52).logicalSrcIdx = 121;
	  section.data(52).dtTransOffset = 116;
	
	  ;% flightControlSystem_P.ControlSystem.I_pr_Gain
	  section.data(53).logicalSrcIdx = 122;
	  section.data(53).dtTransOffset = 117;
	
	  ;% flightControlSystem_P.ControlSystem.P_pr_Gain
	  section.data(54).logicalSrcIdx = 123;
	  section.data(54).dtTransOffset = 118;
	
	  ;% flightControlSystem_P.ControlSystem.w1_Value
	  section.data(55).logicalSrcIdx = 124;
	  section.data(55).dtTransOffset = 120;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_gainval_b1wrfjbuk2
	  section.data(56).logicalSrcIdx = 125;
	  section.data(56).dtTransOffset = 121;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_IC_iymdtlt5j0
	  section.data(57).logicalSrcIdx = 126;
	  section.data(57).dtTransOffset = 122;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_UpperSat_plvc2rxdg0
	  section.data(58).logicalSrcIdx = 127;
	  section.data(58).dtTransOffset = 123;
	
	  ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_LowerSat_cbbd1x44vs
	  section.data(59).logicalSrcIdx = 128;
	  section.data(59).dtTransOffset = 124;
	
	  ;% flightControlSystem_P.ControlSystem.SaturationThrust1_UpperSat
	  section.data(60).logicalSrcIdx = 129;
	  section.data(60).dtTransOffset = 125;
	
	  ;% flightControlSystem_P.ControlSystem.SaturationThrust1_LowerSat
	  section.data(61).logicalSrcIdx = 130;
	  section.data(61).dtTransOffset = 126;
	
	  ;% flightControlSystem_P.ControlSystem.P_yaw_Gain
	  section.data(62).logicalSrcIdx = 131;
	  section.data(62).dtTransOffset = 127;
	
	  ;% flightControlSystem_P.ControlSystem.D_yaw_Gain
	  section.data(63).logicalSrcIdx = 132;
	  section.data(63).dtTransOffset = 128;
	
	  ;% flightControlSystem_P.ControlSystem.ThrustToMotorCommand_Gain
	  section.data(64).logicalSrcIdx = 133;
	  section.data(64).dtTransOffset = 129;
	
	  ;% flightControlSystem_P.ControlSystem.Saturation5_UpperSat
	  section.data(65).logicalSrcIdx = 134;
	  section.data(65).dtTransOffset = 130;
	
	  ;% flightControlSystem_P.ControlSystem.Saturation5_LowerSat
	  section.data(66).logicalSrcIdx = 135;
	  section.data(66).dtTransOffset = 131;
	
	  ;% flightControlSystem_P.ControlSystem.MotorDirections_Gain
	  section.data(67).logicalSrcIdx = 136;
	  section.data(67).dtTransOffset = 132;
	
	  ;% flightControlSystem_P.ControlSystem.A_Value_l0gpbuxkte
	  section.data(68).logicalSrcIdx = 137;
	  section.data(68).dtTransOffset = 136;
	
	  ;% flightControlSystem_P.ControlSystem.B_Value_divnfjb1dq
	  section.data(69).logicalSrcIdx = 138;
	  section.data(69).dtTransOffset = 140;
	
	  ;% flightControlSystem_P.ControlSystem.D_Value_j0gctn4yse
	  section.data(70).logicalSrcIdx = 139;
	  section.data(70).dtTransOffset = 144;
	
	  ;% flightControlSystem_P.ControlSystem.Delay_InitialCondition_cot5fhlv10
	  section.data(71).logicalSrcIdx = 140;
	  section.data(71).dtTransOffset = 148;
	
	  ;% flightControlSystem_P.ControlSystem.antiWU_Gain_Gain
	  section.data(72).logicalSrcIdx = 141;
	  section.data(72).dtTransOffset = 149;
	
	  ;% flightControlSystem_P.ControlSystem.I_pr_Gain_cswgo3ze1g
	  section.data(73).logicalSrcIdx = 142;
	  section.data(73).dtTransOffset = 150;
	
	  ;% flightControlSystem_P.ControlSystem.Gain_Gain_nkg3zw25sw
	  section.data(74).logicalSrcIdx = 143;
	  section.data(74).dtTransOffset = 151;
	
	  ;% flightControlSystem_P.ControlSystem.Gain1_Gain_ov00v2ikfj
	  section.data(75).logicalSrcIdx = 144;
	  section.data(75).dtTransOffset = 152;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Constant_Value_eesjyjh2ui
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_P.ControlSystem.Constant_Value_phytu2r2f1
	  section.data(2).logicalSrcIdx = 146;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_P.ControlSystem.Constant_Value_o24gdufi11
	  section.data(3).logicalSrcIdx = 147;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_P.ControlSystem.Delay2_DelayLength
	  section.data(4).logicalSrcIdx = 148;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_P.ControlSystem.MemoryX_DelayLength
	  section.data(5).logicalSrcIdx = 149;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_P.ControlSystem.MemoryX_DelayLength_hf1cizflt4
	  section.data(6).logicalSrcIdx = 150;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_P.ControlSystem.Output_InitialCondition
	  section.data(7).logicalSrcIdx = 151;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_P.ControlSystem.Delay_DelayLength
	  section.data(8).logicalSrcIdx = 152;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_P.ControlSystem.Delay1_DelayLength
	  section.data(9).logicalSrcIdx = 153;
	  section.data(9).dtTransOffset = 8;
	
	  ;% flightControlSystem_P.ControlSystem.Output_InitialCondition_c5nnqodi1t
	  section.data(10).logicalSrcIdx = 154;
	  section.data(10).dtTransOffset = 9;
	
	  ;% flightControlSystem_P.ControlSystem.Delay_DelayLength_nnijsqwcwl
	  section.data(11).logicalSrcIdx = 155;
	  section.data(11).dtTransOffset = 10;
	
	  ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value
	  section.data(12).logicalSrcIdx = 156;
	  section.data(12).dtTransOffset = 11;
	
	  ;% flightControlSystem_P.ControlSystem.Output_InitialCondition_j3t1gcu1w1
	  section.data(13).logicalSrcIdx = 157;
	  section.data(13).dtTransOffset = 12;
	
	  ;% flightControlSystem_P.ControlSystem.DelayOneStep_DelayLength
	  section.data(14).logicalSrcIdx = 158;
	  section.data(14).dtTransOffset = 13;
	
	  ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value_h5bewbcaxk
	  section.data(15).logicalSrcIdx = 159;
	  section.data(15).dtTransOffset = 14;
	
	  ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value_kchif4j3g4
	  section.data(16).logicalSrcIdx = 160;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.controlModePosVsOrient_Value
	  section.data(1).logicalSrcIdx = 161;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Merge_InitialOutput_ey5vocp2a3
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Normalcondition.Constant_Value
	  section.data(1).logicalSrcIdx = 163;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Ultrasoundimproper.Constant_Value
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Noopticalflow.Constant_Value
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.estimatorOpticalflowerror.Constant_Value
	  section.data(1).logicalSrcIdx = 166;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_P.ControlSystem.Geofencingerror.Constant_Value
	  section.data(1).logicalSrcIdx = 167;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.RateTransition1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.AND
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.RateTransition
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.Compare
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.Product2
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.ControlSystem.Product3
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.yaw
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.SimplyIntegrateVelocity
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.altitude
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.ControlSystem.Sum2
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_B.ControlSystem.inverseIMU_gain
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_B.ControlSystem.Merge
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 9;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion3
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 11;
	
	  ;% flightControlSystem_B.ControlSystem.Reshapexhat
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 14;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion2
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 16;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion1
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 17;
	
	  ;% flightControlSystem_B.ControlSystem.TmpSignalConversionAtToWorkspaceInport1
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 20;
	
	  ;% flightControlSystem_B.ControlSystem.Product2_af04vv1zot
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 32;
	
	  ;% flightControlSystem_B.ControlSystem.Product3_drwpv1e3vz
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 34;
	
	  ;% flightControlSystem_B.ControlSystem.x
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 36;
	
	  ;% flightControlSystem_B.ControlSystem.y
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 37;
	
	  ;% flightControlSystem_B.ControlSystem.z
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% motors_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 167;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(8) = section;
	    clear section
	  
	      
	    ;% flag_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 168;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(9) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 20;
    sectIdxOffset = 9;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.Delay1_DSTATE
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.Delay2_DSTATE
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.RateTransition1_Buffer
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition1_ActiveBufIdx
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition_Buffer0
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.objisempty
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Delay2_DSTATE
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.soonarFilter_IIR_states
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.ControlSystem.DelayOneStep_DSTATE
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.ControlSystem.vel
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.ControlSystem.grados
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 8;
	
	  ;% flightControlSystem_DW.ControlSystem.cen
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 9;
	
	  ;% flightControlSystem_DW.ControlSystem.actual
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.ToWorkspace_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_DSTATE
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.pressureFilter_IIR_states
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.IIR_IMUgyro_r_states
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_states
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 10;
	
	  ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE_f3yjwtkool
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 25;
	
	  ;% flightControlSystem_DW.ControlSystem.IIRgyroz_states
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 27;
	
	  ;% flightControlSystem_DW.ControlSystem.UD_DSTATE
	  section.data(7).logicalSrcIdx = 24;
	  section.data(7).dtTransOffset = 37;
	
	  ;% flightControlSystem_DW.ControlSystem.Delay1_DSTATE
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 39;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 41;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE_mnqnev55nj
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 43;
	
	  ;% flightControlSystem_DW.ControlSystem.Delay_DSTATE_fbcbshewsf
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_circBuf
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_hymmp1tw2p
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_nghfazzn45
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.IIRgyroz_tmp
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.sfEvent
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_PrevResetState
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_PrevResetState
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_bizsiivekb
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_nsfwreskp4
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.ControlSystem.IfActionSubsystem2_SubsysRanBC
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.ControlSystem.IfActionSubsystem_SubsysRanBC
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.icLoad
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.icLoad_nkomoir31r
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.is_active_c3_flightControlSystem
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.is_c3_flightControlSystem
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_MODE
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE_isfprezmm1
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_MODE_aicpl1r0k4
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Normalcondition.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1018786876;
  targMap.checksum1 = 3983076827;
  targMap.checksum2 = 1577453429;
  targMap.checksum3 = 2775738039;

