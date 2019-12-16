  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 0;
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
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (flightControlSystem_P)
    ;%
    
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
    nTotSects     = 8;
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
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.RateTransition1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.estado
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_B.caso
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.RateTransition
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.Compare
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.Product2
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.ControlSystem.Product3
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.yaw
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.SimplyIntegrateVelocity
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% flightControlSystem_B.ControlSystem.altitude
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_B.ControlSystem.Sum2
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_B.ControlSystem.inverseIMU_gain
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_B.ControlSystem.Merge
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 9;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion3
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 11;
	
	  ;% flightControlSystem_B.ControlSystem.Reshapexhat
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 14;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion2
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 16;
	
	  ;% flightControlSystem_B.ControlSystem.DataTypeConversion1
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 17;
	
	  ;% flightControlSystem_B.ControlSystem.TmpSignalConversionAtToWorkspaceInport1
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 20;
	
	  ;% flightControlSystem_B.ControlSystem.Product2_i5itdihbiv
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 32;
	
	  ;% flightControlSystem_B.ControlSystem.Product3_gd3igxsc2c
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 34;
	
	  ;% flightControlSystem_B.ControlSystem.x
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 36;
	
	  ;% flightControlSystem_B.ControlSystem.y
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 37;
	
	  ;% flightControlSystem_B.ControlSystem.z
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% motors_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 164;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(7) = section;
	    clear section
	  
	      
	    ;% flag_outport
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 165;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(8) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 19;
    sectIdxOffset = 8;
    
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
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.Delay1_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.RateTransition1_Buffer
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition1_ActiveBufIdx
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.RateTransition_Buffer0
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.objisempty
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Delay2_DSTATE
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.soonarFilter_IIR_states
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.ControlSystem.DelayOneStep_DSTATE
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.ControlSystem.vel
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.ControlSystem.grados
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 8;
	
	  ;% flightControlSystem_DW.ControlSystem.actual
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 9;
	
	  ;% flightControlSystem_DW.ControlSystem.cen
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.ToWorkspace_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_DSTATE
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.pressureFilter_IIR_states
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.IIR_IMUgyro_r_states
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_states
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 10;
	
	  ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE_hqltbc4n3u
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 25;
	
	  ;% flightControlSystem_DW.ControlSystem.IIRgyroz_states
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 27;
	
	  ;% flightControlSystem_DW.ControlSystem.UD_DSTATE
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 37;
	
	  ;% flightControlSystem_DW.ControlSystem.Delay1_DSTATE
	  section.data(8).logicalSrcIdx = 25;
	  section.data(8).dtTransOffset = 39;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE
	  section.data(9).logicalSrcIdx = 26;
	  section.data(9).dtTransOffset = 41;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE_kgeqdjad0f
	  section.data(10).logicalSrcIdx = 27;
	  section.data(10).dtTransOffset = 43;
	
	  ;% flightControlSystem_DW.ControlSystem.Delay_DSTATE_ijwdhdrv0s
	  section.data(11).logicalSrcIdx = 28;
	  section.data(11).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_circBuf
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_kdeodyri3i
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_aloeis45eb
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.IIRgyroz_tmp
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.sfEvent
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_PrevResetState
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_PrevResetState
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_bgcmjfg1p0
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_cfrhkmpxp0
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 5;
	
	  ;% flightControlSystem_DW.ControlSystem.IfActionSubsystem2_SubsysRanBC
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 6;
	
	  ;% flightControlSystem_DW.ControlSystem.IfActionSubsystem_SubsysRanBC
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 7;
	
	  ;% flightControlSystem_DW.ControlSystem.Geofencingerror_SubsysRanBC
	  section.data(9).logicalSrcIdx = 47;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.icLoad
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% flightControlSystem_DW.ControlSystem.icLoad_gsr0jp51l1
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
	
	  ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE_n0gllf0cgu
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_MODE_gfpthrsdrn
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Normalcondition.Ultrasoundimproper_SubsysRanBC
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Ultrasoundimproper_SubsysRanBC
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.Noopticalflow.estimatorOpticalflowerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.estimatorOpticalflowerror_SubsysRanBC
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
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


  targMap.checksum0 = 3980205875;
  targMap.checksum1 = 2391229496;
  targMap.checksum2 = 1599075989;
  targMap.checksum3 = 1244393035;

