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
    ;% Auto data (dexojrsdjj)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Sensors
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Thresholdfortotalwhitepixels_const
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Thresholdforeachpixel1_const
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.Thresholdforeachpixel2_const
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.Thresholdforeachpixel3_const
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Delay_InitialCondition
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.RateTransition1_InitialCondition
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.RateTransition2_InitialCondition
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.Delay_DelayLength
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.RateTransition_InitialCondition
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.outlierBelowFloor_const
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.outlierJump_const
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.currentEstimateVeryOffFromPressure_const
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.currentStateVeryOffsonarflt_const
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Checkerrorcondition_const
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.u0continuousOFerrors_const
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteDerivative_ICPrevScaledInput
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant1_const
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxp_const
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxq_const
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw1_const
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw2_const
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 6;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxdw1_const
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxdw2_const
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxp2_const
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxq2_const
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw3_const
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.maxw4_const
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.minHeightforOF_const
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 13;
	
	  ;% dexojrsdjj.fxgka2mnesn.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
	  section.data(15).logicalSrcIdx = 30;
	  section.data(15).dtTransOffset = 14;
	
	  ;% dexojrsdjj.fxgka2mnesn.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
	  section.data(16).logicalSrcIdx = 31;
	  section.data(16).dtTransOffset = 15;
	
	  ;% dexojrsdjj.fxgka2mnesn.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
	  section.data(17).logicalSrcIdx = 32;
	  section.data(17).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant2_const
	  section.data(18).logicalSrcIdx = 33;
	  section.data(18).dtTransOffset = 17;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant4_const
	  section.data(19).logicalSrcIdx = 34;
	  section.data(19).dtTransOffset = 18;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant3_const
	  section.data(20).logicalSrcIdx = 35;
	  section.data(20).dtTransOffset = 19;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant5_const
	  section.data(21).logicalSrcIdx = 36;
	  section.data(21).dtTransOffset = 20;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_j00hy5w41n
	  section.data(22).logicalSrcIdx = 37;
	  section.data(22).dtTransOffset = 21;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant1_const_es2id1xqb3
	  section.data(23).logicalSrcIdx = 38;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold_ajpu2ajsvb
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.WrapToZero_Threshold_lqm3uuy0zb
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_ji3z4z0yse
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.CompareToConstant_const_pddtad1qtr
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn._Value
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Lykyhatkk1_Y0
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.deltax_Y0
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay2_InitialCondition
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationSonar_LowerSat
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 6;
	
	  ;% dexojrsdjj.fxgka2mnesn.soonarFilter_IIR_NumCoef
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.soonarFilter_IIR_DenCoef
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.soonarFilter_IIR_InitialStates
	  section.data(9).logicalSrcIdx = 52;
	  section.data(9).dtTransOffset = 15;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value
	  section.data(10).logicalSrcIdx = 53;
	  section.data(10).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value
	  section.data(11).logicalSrcIdx = 54;
	  section.data(11).dtTransOffset = 18;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainM_Value_kldosnwojn
	  section.data(12).logicalSrcIdx = 55;
	  section.data(12).dtTransOffset = 20;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value
	  section.data(13).logicalSrcIdx = 56;
	  section.data(13).dtTransOffset = 24;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value
	  section.data(14).logicalSrcIdx = 57;
	  section.data(14).dtTransOffset = 28;
	
	  ;% dexojrsdjj.fxgka2mnesn.gravity_Value
	  section.data(15).logicalSrcIdx = 58;
	  section.data(15).dtTransOffset = 32;
	
	  ;% dexojrsdjj.fxgka2mnesn.gravity_Value_cr5hy3vrzq
	  section.data(16).logicalSrcIdx = 59;
	  section.data(16).dtTransOffset = 35;
	
	  ;% dexojrsdjj.fxgka2mnesn.gainaccinput_Gain
	  section.data(17).logicalSrcIdx = 60;
	  section.data(17).dtTransOffset = 38;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value
	  section.data(18).logicalSrcIdx = 61;
	  section.data(18).dtTransOffset = 39;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value
	  section.data(19).logicalSrcIdx = 62;
	  section.data(19).dtTransOffset = 41;
	
	  ;% dexojrsdjj.fxgka2mnesn.KalmanGainL_Value_htocs2gnbm
	  section.data(20).logicalSrcIdx = 63;
	  section.data(20).dtTransOffset = 42;
	
	  ;% dexojrsdjj.fxgka2mnesn.Wait3Seconds_Value
	  section.data(21).logicalSrcIdx = 64;
	  section.data(21).dtTransOffset = 44;
	
	  ;% dexojrsdjj.fxgka2mnesn.DelayOneStep_InitialCondition
	  section.data(22).logicalSrcIdx = 65;
	  section.data(22).dtTransOffset = 45;
	
	  ;% dexojrsdjj.fxgka2mnesn.u5meters_Value
	  section.data(23).logicalSrcIdx = 66;
	  section.data(23).dtTransOffset = 46;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value
	  section.data(24).logicalSrcIdx = 67;
	  section.data(24).dtTransOffset = 47;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value
	  section.data(25).logicalSrcIdx = 68;
	  section.data(25).dtTransOffset = 51;
	
	  ;% dexojrsdjj.fxgka2mnesn.CovarianceZ_Value_exmk2dg2v3
	  section.data(26).logicalSrcIdx = 69;
	  section.data(26).dtTransOffset = 55;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value
	  section.data(27).logicalSrcIdx = 70;
	  section.data(27).dtTransOffset = 59;
	
	  ;% dexojrsdjj.fxgka2mnesn.ConstantP_Value
	  section.data(28).logicalSrcIdx = 71;
	  section.data(28).dtTransOffset = 61;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value
	  section.data(29).logicalSrcIdx = 72;
	  section.data(29).dtTransOffset = 62;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value
	  section.data(30).logicalSrcIdx = 73;
	  section.data(30).dtTransOffset = 63;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value
	  section.data(31).logicalSrcIdx = 74;
	  section.data(31).dtTransOffset = 64;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value
	  section.data(32).logicalSrcIdx = 75;
	  section.data(32).dtTransOffset = 65;
	
	  ;% dexojrsdjj.fxgka2mnesn.ConstantP_Value_fzoorst0zt
	  section.data(33).logicalSrcIdx = 76;
	  section.data(33).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 83;
      section.data(83)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.D_xy_Gain
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation_UpperSat
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation_LowerSat
	  section.data(4).logicalSrcIdx = 80;
	  section.data(4).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_xy_Gain
	  section.data(5).logicalSrcIdx = 81;
	  section.data(5).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_z1_Gain
	  section.data(6).logicalSrcIdx = 82;
	  section.data(6).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_z1_Gain
	  section.data(7).logicalSrcIdx = 83;
	  section.data(7).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.takeoff_gain1_Gain
	  section.data(8).logicalSrcIdx = 84;
	  section.data(8).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn._Value_iigvqrtbvy
	  section.data(9).logicalSrcIdx = 85;
	  section.data(9).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain1_Gain
	  section.data(10).logicalSrcIdx = 86;
	  section.data(10).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_kmmihz302o
	  section.data(11).logicalSrcIdx = 87;
	  section.data(11).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain2_Gain
	  section.data(12).logicalSrcIdx = 88;
	  section.data(12).dtTransOffset = 13;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain3_Gain
	  section.data(13).logicalSrcIdx = 89;
	  section.data(13).dtTransOffset = 14;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain4_Gain
	  section.data(14).logicalSrcIdx = 90;
	  section.data(14).dtTransOffset = 15;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_h3ccooc1lf
	  section.data(15).logicalSrcIdx = 91;
	  section.data(15).dtTransOffset = 16;
	
	  ;% dexojrsdjj.fxgka2mnesn.opticalFlowErrorCorrect_Gain
	  section.data(16).logicalSrcIdx = 92;
	  section.data(16).dtTransOffset = 17;
	
	  ;% dexojrsdjj.fxgka2mnesn.Lykyhatkk1_Y0_dyjn4goeal
	  section.data(17).logicalSrcIdx = 93;
	  section.data(17).dtTransOffset = 18;
	
	  ;% dexojrsdjj.fxgka2mnesn.deltax_Y0_iybgp2rjmo
	  section.data(18).logicalSrcIdx = 94;
	  section.data(18).dtTransOffset = 19;
	
	  ;% dexojrsdjj.fxgka2mnesn.TorqueTotalThrustToThrustPerMotor_Value
	  section.data(19).logicalSrcIdx = 95;
	  section.data(19).dtTransOffset = 20;
	
	  ;% dexojrsdjj.fxgka2mnesn.SimplyIntegrateVelocity_gainval
	  section.data(20).logicalSrcIdx = 96;
	  section.data(20).dtTransOffset = 36;
	
	  ;% dexojrsdjj.fxgka2mnesn.SimplyIntegrateVelocity_IC
	  section.data(21).logicalSrcIdx = 97;
	  section.data(21).dtTransOffset = 37;
	
	  ;% dexojrsdjj.fxgka2mnesn.invertzaxisGain_Gain
	  section.data(22).logicalSrcIdx = 98;
	  section.data(22).dtTransOffset = 38;
	
	  ;% dexojrsdjj.fxgka2mnesn.prsToAltGain_Gain
	  section.data(23).logicalSrcIdx = 99;
	  section.data(23).dtTransOffset = 39;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_NumCoef
	  section.data(24).logicalSrcIdx = 100;
	  section.data(24).dtTransOffset = 40;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_DenCoef
	  section.data(25).logicalSrcIdx = 101;
	  section.data(25).dtTransOffset = 44;
	
	  ;% dexojrsdjj.fxgka2mnesn.pressureFilter_IIR_InitialStates
	  section.data(26).logicalSrcIdx = 102;
	  section.data(26).dtTransOffset = 48;
	
	  ;% dexojrsdjj.fxgka2mnesn.Memory_InitialCondition
	  section.data(27).logicalSrcIdx = 103;
	  section.data(27).dtTransOffset = 49;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value
	  section.data(28).logicalSrcIdx = 104;
	  section.data(28).dtTransOffset = 52;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_nbtmsufn1q
	  section.data(29).logicalSrcIdx = 105;
	  section.data(29).dtTransOffset = 53;
	
	  ;% dexojrsdjj.fxgka2mnesn.Assumingthatcalibwasdonelevel_Bias
	  section.data(30).logicalSrcIdx = 106;
	  section.data(30).dtTransOffset = 54;
	
	  ;% dexojrsdjj.fxgka2mnesn.inverseIMU_gain_Gain
	  section.data(31).logicalSrcIdx = 107;
	  section.data(31).dtTransOffset = 60;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_NumCoef
	  section.data(32).logicalSrcIdx = 108;
	  section.data(32).dtTransOffset = 66;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_DenCoef
	  section.data(33).logicalSrcIdx = 109;
	  section.data(33).dtTransOffset = 72;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIR_IMUgyro_r_InitialStates
	  section.data(34).logicalSrcIdx = 110;
	  section.data(34).dtTransOffset = 78;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_moi2ufsqul
	  section.data(35).logicalSrcIdx = 111;
	  section.data(35).dtTransOffset = 79;
	
	  ;% dexojrsdjj.fxgka2mnesn.FIR_IMUaccel_InitialStates
	  section.data(36).logicalSrcIdx = 112;
	  section.data(36).dtTransOffset = 80;
	
	  ;% dexojrsdjj.fxgka2mnesn.FIR_IMUaccel_Coefficients
	  section.data(37).logicalSrcIdx = 113;
	  section.data(37).dtTransOffset = 81;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_mqbnirh1j0
	  section.data(38).logicalSrcIdx = 114;
	  section.data(38).dtTransOffset = 87;
	
	  ;% dexojrsdjj.fxgka2mnesn.Merge_InitialOutput
	  section.data(39).logicalSrcIdx = 115;
	  section.data(39).dtTransOffset = 88;
	
	  ;% dexojrsdjj.fxgka2mnesn.X0_Value_hnvinecnac
	  section.data(40).logicalSrcIdx = 116;
	  section.data(40).dtTransOffset = 89;
	
	  ;% dexojrsdjj.fxgka2mnesn.C_Value_jxqzhgkgnb
	  section.data(41).logicalSrcIdx = 117;
	  section.data(41).dtTransOffset = 91;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_NumCoef
	  section.data(42).logicalSrcIdx = 118;
	  section.data(42).dtTransOffset = 95;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_DenCoef
	  section.data(43).logicalSrcIdx = 119;
	  section.data(43).dtTransOffset = 101;
	
	  ;% dexojrsdjj.fxgka2mnesn.IIRgyroz_InitialStates
	  section.data(44).logicalSrcIdx = 120;
	  section.data(44).dtTransOffset = 107;
	
	  ;% dexojrsdjj.fxgka2mnesn.TSamp_WtEt
	  section.data(45).logicalSrcIdx = 121;
	  section.data(45).dtTransOffset = 108;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_InitialCondition
	  section.data(46).logicalSrcIdx = 122;
	  section.data(46).dtTransOffset = 109;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay1_InitialCondition
	  section.data(47).logicalSrcIdx = 123;
	  section.data(47).dtTransOffset = 110;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_pr_Gain
	  section.data(48).logicalSrcIdx = 124;
	  section.data(48).dtTransOffset = 111;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_gainval
	  section.data(49).logicalSrcIdx = 125;
	  section.data(49).dtTransOffset = 113;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_IC
	  section.data(50).logicalSrcIdx = 126;
	  section.data(50).dtTransOffset = 114;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_UpperSat
	  section.data(51).logicalSrcIdx = 127;
	  section.data(51).dtTransOffset = 115;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_LowerSat
	  section.data(52).logicalSrcIdx = 128;
	  section.data(52).dtTransOffset = 116;
	
	  ;% dexojrsdjj.fxgka2mnesn.I_pr_Gain
	  section.data(53).logicalSrcIdx = 129;
	  section.data(53).dtTransOffset = 117;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_pr_Gain
	  section.data(54).logicalSrcIdx = 130;
	  section.data(54).dtTransOffset = 118;
	
	  ;% dexojrsdjj.fxgka2mnesn.w1_Value
	  section.data(55).logicalSrcIdx = 131;
	  section.data(55).dtTransOffset = 120;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_gainval_o31w4ih0kq
	  section.data(56).logicalSrcIdx = 132;
	  section.data(56).dtTransOffset = 121;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_IC_ohdoeqfqw0
	  section.data(57).logicalSrcIdx = 133;
	  section.data(57).dtTransOffset = 122;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_UpperSat_lkz0qfkds1
	  section.data(58).logicalSrcIdx = 134;
	  section.data(58).dtTransOffset = 123;
	
	  ;% dexojrsdjj.fxgka2mnesn.DiscreteTimeIntegrator_LowerSat_ex0sffd5zn
	  section.data(59).logicalSrcIdx = 135;
	  section.data(59).dtTransOffset = 124;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationThrust1_UpperSat
	  section.data(60).logicalSrcIdx = 136;
	  section.data(60).dtTransOffset = 125;
	
	  ;% dexojrsdjj.fxgka2mnesn.SaturationThrust1_LowerSat
	  section.data(61).logicalSrcIdx = 137;
	  section.data(61).dtTransOffset = 126;
	
	  ;% dexojrsdjj.fxgka2mnesn.P_yaw_Gain
	  section.data(62).logicalSrcIdx = 138;
	  section.data(62).dtTransOffset = 127;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_yaw_Gain
	  section.data(63).logicalSrcIdx = 139;
	  section.data(63).dtTransOffset = 128;
	
	  ;% dexojrsdjj.fxgka2mnesn.ThrustToMotorCommand_Gain
	  section.data(64).logicalSrcIdx = 140;
	  section.data(64).dtTransOffset = 129;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation5_UpperSat
	  section.data(65).logicalSrcIdx = 141;
	  section.data(65).dtTransOffset = 130;
	
	  ;% dexojrsdjj.fxgka2mnesn.Saturation5_LowerSat
	  section.data(66).logicalSrcIdx = 142;
	  section.data(66).dtTransOffset = 131;
	
	  ;% dexojrsdjj.fxgka2mnesn.MotorDirections_Gain
	  section.data(67).logicalSrcIdx = 143;
	  section.data(67).dtTransOffset = 132;
	
	  ;% dexojrsdjj.fxgka2mnesn.A_Value_ctwy1b2zur
	  section.data(68).logicalSrcIdx = 144;
	  section.data(68).dtTransOffset = 136;
	
	  ;% dexojrsdjj.fxgka2mnesn.B_Value_dt3o420wvk
	  section.data(69).logicalSrcIdx = 145;
	  section.data(69).dtTransOffset = 140;
	
	  ;% dexojrsdjj.fxgka2mnesn.D_Value_bdemwyzalg
	  section.data(70).logicalSrcIdx = 146;
	  section.data(70).dtTransOffset = 144;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_InitialCondition_gh5bdd2pbx
	  section.data(71).logicalSrcIdx = 147;
	  section.data(71).dtTransOffset = 148;
	
	  ;% dexojrsdjj.fxgka2mnesn.antiWU_Gain_Gain
	  section.data(72).logicalSrcIdx = 148;
	  section.data(72).dtTransOffset = 149;
	
	  ;% dexojrsdjj.fxgka2mnesn.I_pr_Gain_hmtp040vxb
	  section.data(73).logicalSrcIdx = 149;
	  section.data(73).dtTransOffset = 150;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain_Gain_o4gwbrjhx2
	  section.data(74).logicalSrcIdx = 150;
	  section.data(74).dtTransOffset = 151;
	
	  ;% dexojrsdjj.fxgka2mnesn.Gain1_Gain_poq4ia0msg
	  section.data(75).logicalSrcIdx = 151;
	  section.data(75).dtTransOffset = 152;
	
	  ;% dexojrsdjj.fxgka2mnesn.P0_Value_m54fqfyega
	  section.data(76).logicalSrcIdx = 152;
	  section.data(76).dtTransOffset = 153;
	
	  ;% dexojrsdjj.fxgka2mnesn.G_Value_hoe1i4mjzq
	  section.data(77).logicalSrcIdx = 153;
	  section.data(77).dtTransOffset = 157;
	
	  ;% dexojrsdjj.fxgka2mnesn.H_Value_dp4knsa5bd
	  section.data(78).logicalSrcIdx = 154;
	  section.data(78).dtTransOffset = 161;
	
	  ;% dexojrsdjj.fxgka2mnesn.N_Value_hjeqmqjv4w
	  section.data(79).logicalSrcIdx = 155;
	  section.data(79).dtTransOffset = 165;
	
	  ;% dexojrsdjj.fxgka2mnesn.Q_Value_ony4n2glik
	  section.data(80).logicalSrcIdx = 156;
	  section.data(80).dtTransOffset = 169;
	
	  ;% dexojrsdjj.fxgka2mnesn.R_Value_axb2i5wrj2
	  section.data(81).logicalSrcIdx = 157;
	  section.data(81).dtTransOffset = 173;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_na404m3ygx
	  section.data(82).logicalSrcIdx = 158;
	  section.data(82).dtTransOffset = 177;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_pm0om3ok3e
	  section.data(83).logicalSrcIdx = 159;
	  section.data(83).dtTransOffset = 178;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.Delay2_DelayLength
	  section.data(1).logicalSrcIdx = 160;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.MemoryX_DelayLength
	  section.data(2).logicalSrcIdx = 161;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.MemoryX_DelayLength_pwkdwutqfj
	  section.data(3).logicalSrcIdx = 162;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition
	  section.data(4).logicalSrcIdx = 163;
	  section.data(4).dtTransOffset = 3;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_DelayLength
	  section.data(5).logicalSrcIdx = 164;
	  section.data(5).dtTransOffset = 4;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay1_DelayLength
	  section.data(6).logicalSrcIdx = 165;
	  section.data(6).dtTransOffset = 5;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition_ningrb1jms
	  section.data(7).logicalSrcIdx = 166;
	  section.data(7).dtTransOffset = 6;
	
	  ;% dexojrsdjj.fxgka2mnesn.Delay_DelayLength_otrelwgxbg
	  section.data(8).logicalSrcIdx = 167;
	  section.data(8).dtTransOffset = 7;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value
	  section.data(9).logicalSrcIdx = 168;
	  section.data(9).dtTransOffset = 8;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_pjtltggn3n
	  section.data(10).logicalSrcIdx = 169;
	  section.data(10).dtTransOffset = 9;
	
	  ;% dexojrsdjj.fxgka2mnesn.Output_InitialCondition_hxy4e0ic3f
	  section.data(11).logicalSrcIdx = 170;
	  section.data(11).dtTransOffset = 10;
	
	  ;% dexojrsdjj.fxgka2mnesn.DelayOneStep_DelayLength
	  section.data(12).logicalSrcIdx = 171;
	  section.data(12).dtTransOffset = 11;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value_l1quqfmtyl
	  section.data(13).logicalSrcIdx = 172;
	  section.data(13).dtTransOffset = 12;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_a30z1ihgak
	  section.data(14).logicalSrcIdx = 173;
	  section.data(14).dtTransOffset = 13;
	
	  ;% dexojrsdjj.fxgka2mnesn.FixPtConstant_Value_b5l51foprx
	  section.data(15).logicalSrcIdx = 174;
	  section.data(15).dtTransOffset = 14;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_ho3ea3e20o
	  section.data(16).logicalSrcIdx = 175;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.controlModePosVsOrient_Value
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_b0c3mrprov
	  section.data(2).logicalSrcIdx = 177;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.Constant_Value_c0ysjrgkd2
	  section.data(3).logicalSrcIdx = 178;
	  section.data(3).dtTransOffset = 2;
	
	  ;% dexojrsdjj.fxgka2mnesn.Reset_Value
	  section.data(4).logicalSrcIdx = 179;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.Merge_InitialOutput_an52quypia
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
	  ;% dexojrsdjj.fxgka2mnesn.ManualSwitchPZ_CurrentSetting
	  section.data(2).logicalSrcIdx = 181;
	  section.data(2).dtTransOffset = 1;
	
	  ;% dexojrsdjj.fxgka2mnesn.ManualSwitchPZ_CurrentSetting_mpimwp10by
	  section.data(3).logicalSrcIdx = 182;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.edmf1x5ofn.Constant_Value
	  section.data(1).logicalSrcIdx = 183;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.bp5djohmz0.Constant_Value
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.jtkhw0lgkw.Constant_Value
	  section.data(1).logicalSrcIdx = 185;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.mui4furwa3.Constant_Value
	  section.data(1).logicalSrcIdx = 186;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% dexojrsdjj.fxgka2mnesn.mkh12fremc3.Constant_Value
	  section.data(1).logicalSrcIdx = 187;
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
    nTotSects     = 10;
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
    ;% Auto data (ntrh2fpvwnc)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.ijrki5zvoe
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.etu2ggpmvt
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.obbszcohxa
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ntrh2fpvwnc.fyzunwpye4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ntrh2fpvwnc.elsetrpd4e
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ntrh2fpvwnc.fwc0wfrk12
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.lvnv5htezy
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.idhp3phmqa
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 19200;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.isdfgavbou
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.ldbcwnstct
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.hwb23eey2s
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.ogkgicnhmx
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.mihmxaxp4a
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.lelx53uc4x
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.mfiayx520u
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.kudqdbvklx
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 7;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.aitqf4ny4w
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 9;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.lzzaifywhh
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.g1rkrju3j2
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.l4rwawjf3g
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.jtyj1tptg0
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.cjcxtvn020
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.plok4ctqpy
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.hv3aepufzo
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.abcjtbp5yl
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.lf3u2pgzbp
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.gr2j3snp1d
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 9;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.hmyxm3opro
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 11;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.adhtmyatho
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 12;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.lip1w3qso4
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 15;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.cit0nxok5d
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 27;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.kuqewodpya
	  section.data(10).logicalSrcIdx = 31;
	  section.data(10).dtTransOffset = 29;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.besusuo1fm
	  section.data(11).logicalSrcIdx = 32;
	  section.data(11).dtTransOffset = 30;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.kq1j4caafv
	  section.data(12).logicalSrcIdx = 33;
	  section.data(12).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% ntrh2fpvwnc.fxgka2mnesn.bk3w2w5dsv
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.hmpp1v2igr
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ntrh2fpvwnc.fxgka2mnesn.czuvouss4m
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% motors_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 211;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(9) = section;
	    clear section
	  
	      
	    ;% flag_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 212;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(10) = section;
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
    sectIdxOffset = 10;
    
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
    ;% Auto data (cjyyyt0pe2y)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.adkargetc2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.gwbnagplkr
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.ggtmzbdfrl
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.bfw2czapwx
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.gfwidg31pr
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.g5lul5hren
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.a22yl5arfg
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.ojzwywsqra
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.elzr4ah2qw
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.gb3ngwnfyp
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.lgtz3ah4wy
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.myqcaypgmg
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 6;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bduaevj4fi
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 7;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.lgmnn051nt
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 8;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.axcrshkjcy
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.eimslitsk2.LoggedData
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.n4vi54iutf
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pqy11qhpyp
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.d23tuoejk4
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.fj0d4vhynw
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 10;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.auma44trpz
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 25;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.nkayezvwdo
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 27;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.mqdtfc4ayr
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 37;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.bd4uramag1
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 39;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.kzf5i0bibo
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 41;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.blxl3yyw5m
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 43;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.eflpyol1he
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 45;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.h2dsujsql0
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ig1sctqgjf
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.eujw5scov3
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ao20f5n40r
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.aj2vlvhpfu
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.cv22yygp1z
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.biwcd21box
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.cxkkkjqid4
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ln5tzpqugt
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.ct1zzqxx3z
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.pbfkihh304
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.l1hjgu2wa1
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.nogzfvjo3f
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.dlybrcmohe
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.n2klg2tkt5
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 5;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.jcze1p20xo
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 6;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.hkxwejf1dq
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.cl5rtperh5
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.iclv3gcap2
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.oponpuzk5b
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.ikw2u2pjkn
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.jzkvuc5vhq
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.labulfmwjg
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.iysofnflya
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% cjyyyt0pe2y.fxgka2mnesn.h4ulsmzxse
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.edmf1x5ofn.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.bp5djohmz0.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.jtkhw0lgkw.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.mui4furwa3.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% cjyyyt0pe2y.fxgka2mnesn.mkh12fremc3.ah5fb0fjvv
	  section.data(1).logicalSrcIdx = 59;
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


  targMap.checksum0 = 1005961222;
  targMap.checksum1 = 3717448418;
  targMap.checksum2 = 1591103417;
  targMap.checksum3 = 2696537537;

