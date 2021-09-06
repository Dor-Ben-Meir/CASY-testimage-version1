  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
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
    ;% Auto data (Mainframe_P)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Mainframe_P.INS_Passthrough
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_P.Real_Gyros
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 113;
      section.data(113)  = dumData; %prealloc
      
	  ;% Mainframe_P.PacketInput_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_P.PacketOutput_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_P.Randombias_Ts
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_P.Randombias_Ts_n
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_P.Randombias_Ts_i
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_P.Randombias_Ts_h
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_P.PacketInput_YieldWhenWaiting
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Mainframe_P.PacketOutput_YieldWhenWaiting
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_a_bias
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_a_bias_h
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 11;
	
	  ;% Mainframe_P.ThreeaxisAccelerometer_a_pow
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Mainframe_P.ThreeaxisAccelerometer_a_pow_e
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Mainframe_P.ThreeaxisAccelerometer_a_seeds
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Mainframe_P.ThreeaxisAccelerometer_a_seeds_a
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 23;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 26;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc_i
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 35;
	
	  ;% Mainframe_P.DelayedSine_amp
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 44;
	
	  ;% Mainframe_P.DelayedSine_bias
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 45;
	
	  ;% Mainframe_P.CompareToConstant_const
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 46;
	
	  ;% Mainframe_P.CompareToConstant_const_n
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 47;
	
	  ;% Mainframe_P.Rudder_d_siB_0
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 48;
	
	  ;% Mainframe_P.Rudder1_d_siB_0
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 49;
	
	  ;% Mainframe_P.Rudder2_d_siB_0
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 50;
	
	  ;% Mainframe_P.Rudder3_d_siB_0
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 51;
	
	  ;% Mainframe_P.Rudder_d_siB_max
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 52;
	
	  ;% Mainframe_P.Rudder1_d_siB_max
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 53;
	
	  ;% Mainframe_P.Rudder2_d_siB_max
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 54;
	
	  ;% Mainframe_P.Rudder3_d_siB_max
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 55;
	
	  ;% Mainframe_P.Rudder_d_siB_min
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 56;
	
	  ;% Mainframe_P.Rudder1_d_siB_min
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 57;
	
	  ;% Mainframe_P.Rudder2_d_siB_min
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 58;
	
	  ;% Mainframe_P.Rudder3_d_siB_min
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 59;
	
	  ;% Mainframe_P.Rudder_dd_siB_max
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 60;
	
	  ;% Mainframe_P.Rudder1_dd_siB_max
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 61;
	
	  ;% Mainframe_P.Rudder2_dd_siB_max
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 62;
	
	  ;% Mainframe_P.Rudder3_dd_siB_max
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 63;
	
	  ;% Mainframe_P.Rudder_dd_siB_min
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 64;
	
	  ;% Mainframe_P.Rudder1_dd_siB_min
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 65;
	
	  ;% Mainframe_P.Rudder2_dd_siB_min
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 66;
	
	  ;% Mainframe_P.Rudder3_dd_siB_min
	  section.data(40).logicalSrcIdx = 43;
	  section.data(40).dtTransOffset = 67;
	
	  ;% Mainframe_P.Rudder_dmp
	  section.data(41).logicalSrcIdx = 44;
	  section.data(41).dtTransOffset = 68;
	
	  ;% Mainframe_P.Rudder1_dmp
	  section.data(42).logicalSrcIdx = 45;
	  section.data(42).dtTransOffset = 69;
	
	  ;% Mainframe_P.Rudder2_dmp
	  section.data(43).logicalSrcIdx = 46;
	  section.data(43).dtTransOffset = 70;
	
	  ;% Mainframe_P.Rudder3_dmp
	  section.data(44).logicalSrcIdx = 47;
	  section.data(44).dtTransOffset = 71;
	
	  ;% Mainframe_P.Rigid_Body_EOM_6_DOF_flag_Kraft
	  section.data(45).logicalSrcIdx = 48;
	  section.data(45).dtTransOffset = 72;
	
	  ;% Mainframe_P.WGS84_Gravitation_flg_omega_enabled
	  section.data(46).logicalSrcIdx = 49;
	  section.data(46).dtTransOffset = 73;
	
	  ;% Mainframe_P.DelayedSine_freq
	  section.data(47).logicalSrcIdx = 50;
	  section.data(47).dtTransOffset = 74;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_bias
	  section.data(48).logicalSrcIdx = 51;
	  section.data(48).dtTransOffset = 75;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_bias_o
	  section.data(49).logicalSrcIdx = 52;
	  section.data(49).dtTransOffset = 78;
	
	  ;% Mainframe_P.ThreeaxisGyroscope_g_pow
	  section.data(50).logicalSrcIdx = 53;
	  section.data(50).dtTransOffset = 81;
	
	  ;% Mainframe_P.ThreeaxisGyroscope_g_pow_h
	  section.data(51).logicalSrcIdx = 54;
	  section.data(51).dtTransOffset = 84;
	
	  ;% Mainframe_P.ThreeaxisGyroscope_g_seeds
	  section.data(52).logicalSrcIdx = 55;
	  section.data(52).dtTransOffset = 87;
	
	  ;% Mainframe_P.ThreeaxisGyroscope_g_seeds_o
	  section.data(53).logicalSrcIdx = 56;
	  section.data(53).dtTransOffset = 90;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sens
	  section.data(54).logicalSrcIdx = 57;
	  section.data(54).dtTransOffset = 93;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sens_m
	  section.data(55).logicalSrcIdx = 58;
	  section.data(55).dtTransOffset = 96;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc
	  section.data(56).logicalSrcIdx = 59;
	  section.data(56).dtTransOffset = 99;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc_e
	  section.data(57).logicalSrcIdx = 60;
	  section.data(57).dtTransOffset = 108;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_imu
	  section.data(58).logicalSrcIdx = 61;
	  section.data(58).dtTransOffset = 117;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_imu_p
	  section.data(59).logicalSrcIdx = 62;
	  section.data(59).dtTransOffset = 120;
	
	  ;% Mainframe_P.IntervalTest_lowlimit
	  section.data(60).logicalSrcIdx = 63;
	  section.data(60).dtTransOffset = 123;
	
	  ;% Mainframe_P.IntervalTest1_lowlimit
	  section.data(61).logicalSrcIdx = 64;
	  section.data(61).dtTransOffset = 124;
	
	  ;% Mainframe_P.geopot_height_mean_earth_radius
	  section.data(62).logicalSrcIdx = 65;
	  section.data(62).dtTransOffset = 125;
	
	  ;% Mainframe_P.Rudder_omega
	  section.data(63).logicalSrcIdx = 66;
	  section.data(63).dtTransOffset = 126;
	
	  ;% Mainframe_P.Rudder1_omega
	  section.data(64).logicalSrcIdx = 67;
	  section.data(64).dtTransOffset = 127;
	
	  ;% Mainframe_P.Rudder2_omega
	  section.data(65).logicalSrcIdx = 68;
	  section.data(65).dtTransOffset = 128;
	
	  ;% Mainframe_P.Rudder3_omega
	  section.data(66).logicalSrcIdx = 69;
	  section.data(66).dtTransOffset = 129;
	
	  ;% Mainframe_P.DelayedSine_phase
	  section.data(67).logicalSrcIdx = 70;
	  section.data(67).dtTransOffset = 130;
	
	  ;% Mainframe_P.u_rot_mat_rot_1
	  section.data(68).logicalSrcIdx = 71;
	  section.data(68).dtTransOffset = 131;
	
	  ;% Mainframe_P.u_rot_mat_rot_1_e
	  section.data(69).logicalSrcIdx = 72;
	  section.data(69).dtTransOffset = 132;
	
	  ;% Mainframe_P.u_rot_mat_rot_2
	  section.data(70).logicalSrcIdx = 73;
	  section.data(70).dtTransOffset = 133;
	
	  ;% Mainframe_P.u_rot_mat_rot_2_a
	  section.data(71).logicalSrcIdx = 74;
	  section.data(71).dtTransOffset = 134;
	
	  ;% Mainframe_P.u_rot_mat_rot_3
	  section.data(72).logicalSrcIdx = 75;
	  section.data(72).dtTransOffset = 135;
	
	  ;% Mainframe_P.u_rot_mat_rot_3_a
	  section.data(73).logicalSrcIdx = 76;
	  section.data(73).dtTransOffset = 136;
	
	  ;% Mainframe_P.Rudder_siB_0
	  section.data(74).logicalSrcIdx = 77;
	  section.data(74).dtTransOffset = 137;
	
	  ;% Mainframe_P.Rudder1_siB_0
	  section.data(75).logicalSrcIdx = 78;
	  section.data(75).dtTransOffset = 138;
	
	  ;% Mainframe_P.Rudder2_siB_0
	  section.data(76).logicalSrcIdx = 79;
	  section.data(76).dtTransOffset = 139;
	
	  ;% Mainframe_P.Rudder3_siB_0
	  section.data(77).logicalSrcIdx = 80;
	  section.data(77).dtTransOffset = 140;
	
	  ;% Mainframe_P.Rudder_siB_max
	  section.data(78).logicalSrcIdx = 81;
	  section.data(78).dtTransOffset = 141;
	
	  ;% Mainframe_P.Rudder1_siB_max
	  section.data(79).logicalSrcIdx = 82;
	  section.data(79).dtTransOffset = 142;
	
	  ;% Mainframe_P.Rudder2_siB_max
	  section.data(80).logicalSrcIdx = 83;
	  section.data(80).dtTransOffset = 143;
	
	  ;% Mainframe_P.Rudder3_siB_max
	  section.data(81).logicalSrcIdx = 84;
	  section.data(81).dtTransOffset = 144;
	
	  ;% Mainframe_P.Rudder_siB_min
	  section.data(82).logicalSrcIdx = 85;
	  section.data(82).dtTransOffset = 145;
	
	  ;% Mainframe_P.Rudder1_siB_min
	  section.data(83).logicalSrcIdx = 86;
	  section.data(83).dtTransOffset = 146;
	
	  ;% Mainframe_P.Rudder2_siB_min
	  section.data(84).logicalSrcIdx = 87;
	  section.data(84).dtTransOffset = 147;
	
	  ;% Mainframe_P.Rudder3_siB_min
	  section.data(85).logicalSrcIdx = 88;
	  section.data(85).dtTransOffset = 148;
	
	  ;% Mainframe_P.DelayedStep1_stepTime
	  section.data(86).logicalSrcIdx = 89;
	  section.data(86).dtTransOffset = 149;
	
	  ;% Mainframe_P.DelayedStep2_stepTime
	  section.data(87).logicalSrcIdx = 90;
	  section.data(87).dtTransOffset = 150;
	
	  ;% Mainframe_P.DelayedStep1_u0
	  section.data(88).logicalSrcIdx = 91;
	  section.data(88).dtTransOffset = 151;
	
	  ;% Mainframe_P.DelayedStep2_u0
	  section.data(89).logicalSrcIdx = 92;
	  section.data(89).dtTransOffset = 152;
	
	  ;% Mainframe_P.DelayedStep1_u1
	  section.data(90).logicalSrcIdx = 93;
	  section.data(90).dtTransOffset = 153;
	
	  ;% Mainframe_P.DelayedStep2_u1
	  section.data(91).logicalSrcIdx = 94;
	  section.data(91).dtTransOffset = 154;
	
	  ;% Mainframe_P.Rudder_unc_bl
	  section.data(92).logicalSrcIdx = 95;
	  section.data(92).dtTransOffset = 155;
	
	  ;% Mainframe_P.Rudder1_unc_bl
	  section.data(93).logicalSrcIdx = 96;
	  section.data(93).dtTransOffset = 156;
	
	  ;% Mainframe_P.Rudder2_unc_bl
	  section.data(94).logicalSrcIdx = 97;
	  section.data(94).dtTransOffset = 157;
	
	  ;% Mainframe_P.Rudder3_unc_bl
	  section.data(95).logicalSrcIdx = 98;
	  section.data(95).dtTransOffset = 158;
	
	  ;% Mainframe_P.Rudder_unc_off
	  section.data(96).logicalSrcIdx = 99;
	  section.data(96).dtTransOffset = 159;
	
	  ;% Mainframe_P.Rudder1_unc_off
	  section.data(97).logicalSrcIdx = 100;
	  section.data(97).dtTransOffset = 160;
	
	  ;% Mainframe_P.Rudder2_unc_off
	  section.data(98).logicalSrcIdx = 101;
	  section.data(98).dtTransOffset = 161;
	
	  ;% Mainframe_P.Rudder3_unc_off
	  section.data(99).logicalSrcIdx = 102;
	  section.data(99).dtTransOffset = 162;
	
	  ;% Mainframe_P.Rudder_unc_scale
	  section.data(100).logicalSrcIdx = 103;
	  section.data(100).dtTransOffset = 163;
	
	  ;% Mainframe_P.Rudder1_unc_scale
	  section.data(101).logicalSrcIdx = 104;
	  section.data(101).dtTransOffset = 164;
	
	  ;% Mainframe_P.Rudder2_unc_scale
	  section.data(102).logicalSrcIdx = 105;
	  section.data(102).dtTransOffset = 165;
	
	  ;% Mainframe_P.Rudder3_unc_scale
	  section.data(103).logicalSrcIdx = 106;
	  section.data(103).dtTransOffset = 166;
	
	  ;% Mainframe_P.IntervalTest_uplimit
	  section.data(104).logicalSrcIdx = 107;
	  section.data(104).dtTransOffset = 167;
	
	  ;% Mainframe_P.IntervalTest1_uplimit
	  section.data(105).logicalSrcIdx = 108;
	  section.data(105).dtTransOffset = 168;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a
	  section.data(106).logicalSrcIdx = 109;
	  section.data(106).dtTransOffset = 169;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m
	  section.data(107).logicalSrcIdx = 110;
	  section.data(107).dtTransOffset = 170;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g
	  section.data(108).logicalSrcIdx = 111;
	  section.data(108).dtTransOffset = 171;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n
	  section.data(109).logicalSrcIdx = 112;
	  section.data(109).dtTransOffset = 172;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a
	  section.data(110).logicalSrcIdx = 113;
	  section.data(110).dtTransOffset = 173;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a_m
	  section.data(111).logicalSrcIdx = 114;
	  section.data(111).dtTransOffset = 174;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g
	  section.data(112).logicalSrcIdx = 115;
	  section.data(112).dtTransOffset = 175;
	
	  ;% Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g_h
	  section.data(113).logicalSrcIdx = 116;
	  section.data(113).dtTransOffset = 176;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Mainframe_P.PacketInput_PacketID
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_P.PacketOutput_PacketID
	  section.data(2).logicalSrcIdx = 118;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.States_Y0
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 614;
      section.data(614)  = dumData; %prealloc
      
	  ;% Mainframe_P.CalibrationTime_Y0
	  section.data(1).logicalSrcIdx = 121;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_P.c_flat_Value
	  section.data(2).logicalSrcIdx = 122;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_P.Gain_Gain
	  section.data(3).logicalSrcIdx = 123;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_P.Constant_Value
	  section.data(4).logicalSrcIdx = 124;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_P.c_rsma_Value
	  section.data(5).logicalSrcIdx = 125;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_P.Gain_Gain_b
	  section.data(6).logicalSrcIdx = 126;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_P.Constant_Value_l
	  section.data(7).logicalSrcIdx = 127;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Mainframe_P.Gain_Gain_a
	  section.data(8).logicalSrcIdx = 128;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Mainframe_P.Saturation1_UpperSat
	  section.data(9).logicalSrcIdx = 129;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Mainframe_P.Saturation1_LowerSat
	  section.data(10).logicalSrcIdx = 130;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Mainframe_P.Gain_Gain_n
	  section.data(11).logicalSrcIdx = 131;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Mainframe_P.Gain2_Gain
	  section.data(12).logicalSrcIdx = 132;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Mainframe_P.Gain_Gain_p
	  section.data(13).logicalSrcIdx = 133;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Mainframe_P.Gain1_Gain
	  section.data(14).logicalSrcIdx = 134;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Mainframe_P.Gain2_Gain_c
	  section.data(15).logicalSrcIdx = 135;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Mainframe_P.Gain_Gain_i
	  section.data(16).logicalSrcIdx = 136;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Mainframe_P.Gain1_Gain_k
	  section.data(17).logicalSrcIdx = 137;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Mainframe_P.Gain2_Gain_e
	  section.data(18).logicalSrcIdx = 138;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Mainframe_P.Gain_Gain_g
	  section.data(19).logicalSrcIdx = 139;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Mainframe_P.c_flat_Value_k
	  section.data(20).logicalSrcIdx = 140;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Mainframe_P.Gain_Gain_nm
	  section.data(21).logicalSrcIdx = 141;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Mainframe_P.Constant_Value_k
	  section.data(22).logicalSrcIdx = 142;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Mainframe_P.c_rsma_Value_j
	  section.data(23).logicalSrcIdx = 143;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Mainframe_P.Gain_Gain_ig
	  section.data(24).logicalSrcIdx = 144;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Mainframe_P.Constant_Value_lg
	  section.data(25).logicalSrcIdx = 145;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Mainframe_P.Gain_Gain_bf
	  section.data(26).logicalSrcIdx = 146;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Mainframe_P.WGS84_Gravity_Implementation_c_b_WGS
	  section.data(27).logicalSrcIdx = 147;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Mainframe_P.WGS84_Gravity_Implementation_c_grav
	  section.data(28).logicalSrcIdx = 148;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Mainframe_P.WGS84_Gravity_Implementation_c_rot
	  section.data(29).logicalSrcIdx = 149;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Mainframe_P.WGS84_Gravity_Implementation_c_rsma
	  section.data(30).logicalSrcIdx = 150;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Mainframe_P.c_flat_Value_h
	  section.data(31).logicalSrcIdx = 151;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Mainframe_P.Gain_Gain_ab
	  section.data(32).logicalSrcIdx = 152;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Mainframe_P.Constant_Value_lt
	  section.data(33).logicalSrcIdx = 153;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Mainframe_P.c_rsma_Value_a
	  section.data(34).logicalSrcIdx = 154;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Mainframe_P.Gain_Gain_l
	  section.data(35).logicalSrcIdx = 155;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Mainframe_P.Constant_Value_b
	  section.data(36).logicalSrcIdx = 156;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Mainframe_P.Gain_Gain_bh
	  section.data(37).logicalSrcIdx = 157;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Mainframe_P.Constant8_Value
	  section.data(38).logicalSrcIdx = 158;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Mainframe_P.Constant7_Value
	  section.data(39).logicalSrcIdx = 159;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Mainframe_P.Constant6_Value
	  section.data(40).logicalSrcIdx = 160;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Mainframe_P.Gain2_Gain_f
	  section.data(41).logicalSrcIdx = 161;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Mainframe_P.Gain1_Gain_m
	  section.data(42).logicalSrcIdx = 162;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Mainframe_P.Saturation_UpperSat
	  section.data(43).logicalSrcIdx = 163;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Mainframe_P.Saturation_LowerSat
	  section.data(44).logicalSrcIdx = 164;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Mainframe_P.thrust_lookup_tableData
	  section.data(45).logicalSrcIdx = 165;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Mainframe_P.thrust_lookup_bp01Data
	  section.data(46).logicalSrcIdx = 166;
	  section.data(46).dtTransOffset = 377;
	
	  ;% Mainframe_P.Constant11_Value
	  section.data(47).logicalSrcIdx = 167;
	  section.data(47).dtTransOffset = 710;
	
	  ;% Mainframe_P.Constant10_Value
	  section.data(48).logicalSrcIdx = 168;
	  section.data(48).dtTransOffset = 711;
	
	  ;% Mainframe_P.Constant4_Value
	  section.data(49).logicalSrcIdx = 169;
	  section.data(49).dtTransOffset = 712;
	
	  ;% Mainframe_P.Constant7_Value_f
	  section.data(50).logicalSrcIdx = 170;
	  section.data(50).dtTransOffset = 713;
	
	  ;% Mainframe_P.Constant8_Value_a
	  section.data(51).logicalSrcIdx = 171;
	  section.data(51).dtTransOffset = 714;
	
	  ;% Mainframe_P.Gain_Gain_k
	  section.data(52).logicalSrcIdx = 172;
	  section.data(52).dtTransOffset = 715;
	
	  ;% Mainframe_P.Constant7_Value_d
	  section.data(53).logicalSrcIdx = 173;
	  section.data(53).dtTransOffset = 716;
	
	  ;% Mainframe_P.Gain1_Gain_f
	  section.data(54).logicalSrcIdx = 174;
	  section.data(54).dtTransOffset = 717;
	
	  ;% Mainframe_P.Constant2_Value
	  section.data(55).logicalSrcIdx = 175;
	  section.data(55).dtTransOffset = 718;
	
	  ;% Mainframe_P.Constant1_Value
	  section.data(56).logicalSrcIdx = 176;
	  section.data(56).dtTransOffset = 719;
	
	  ;% Mainframe_P.Constant_Value_c
	  section.data(57).logicalSrcIdx = 177;
	  section.data(57).dtTransOffset = 720;
	
	  ;% Mainframe_P.Constant8_Value_k
	  section.data(58).logicalSrcIdx = 178;
	  section.data(58).dtTransOffset = 721;
	
	  ;% Mainframe_P.Constant7_Value_a
	  section.data(59).logicalSrcIdx = 179;
	  section.data(59).dtTransOffset = 722;
	
	  ;% Mainframe_P.Gain_Gain_c
	  section.data(60).logicalSrcIdx = 180;
	  section.data(60).dtTransOffset = 723;
	
	  ;% Mainframe_P.Constant8_Value_g
	  section.data(61).logicalSrcIdx = 181;
	  section.data(61).dtTransOffset = 724;
	
	  ;% Mainframe_P.Constant2_Value_i
	  section.data(62).logicalSrcIdx = 182;
	  section.data(62).dtTransOffset = 725;
	
	  ;% Mainframe_P.Constant1_Value_j
	  section.data(63).logicalSrcIdx = 183;
	  section.data(63).dtTransOffset = 726;
	
	  ;% Mainframe_P.Constant_Value_o
	  section.data(64).logicalSrcIdx = 184;
	  section.data(64).dtTransOffset = 727;
	
	  ;% Mainframe_P.Constant11_Value_p
	  section.data(65).logicalSrcIdx = 185;
	  section.data(65).dtTransOffset = 728;
	
	  ;% Mainframe_P.Constant10_Value_f
	  section.data(66).logicalSrcIdx = 186;
	  section.data(66).dtTransOffset = 729;
	
	  ;% Mainframe_P.Constant4_Value_a
	  section.data(67).logicalSrcIdx = 187;
	  section.data(67).dtTransOffset = 730;
	
	  ;% Mainframe_P.Constant7_Value_j
	  section.data(68).logicalSrcIdx = 188;
	  section.data(68).dtTransOffset = 731;
	
	  ;% Mainframe_P.Constant8_Value_j
	  section.data(69).logicalSrcIdx = 189;
	  section.data(69).dtTransOffset = 732;
	
	  ;% Mainframe_P.Gain_Gain_ii
	  section.data(70).logicalSrcIdx = 190;
	  section.data(70).dtTransOffset = 733;
	
	  ;% Mainframe_P.Constant7_Value_c
	  section.data(71).logicalSrcIdx = 191;
	  section.data(71).dtTransOffset = 734;
	
	  ;% Mainframe_P.Gain1_Gain_c
	  section.data(72).logicalSrcIdx = 192;
	  section.data(72).dtTransOffset = 735;
	
	  ;% Mainframe_P.Constant2_Value_p
	  section.data(73).logicalSrcIdx = 193;
	  section.data(73).dtTransOffset = 736;
	
	  ;% Mainframe_P.Constant1_Value_b
	  section.data(74).logicalSrcIdx = 194;
	  section.data(74).dtTransOffset = 737;
	
	  ;% Mainframe_P.Constant_Value_h
	  section.data(75).logicalSrcIdx = 195;
	  section.data(75).dtTransOffset = 738;
	
	  ;% Mainframe_P.Constant8_Value_j5
	  section.data(76).logicalSrcIdx = 196;
	  section.data(76).dtTransOffset = 739;
	
	  ;% Mainframe_P.Constant7_Value_o
	  section.data(77).logicalSrcIdx = 197;
	  section.data(77).dtTransOffset = 740;
	
	  ;% Mainframe_P.Gain_Gain_d
	  section.data(78).logicalSrcIdx = 198;
	  section.data(78).dtTransOffset = 741;
	
	  ;% Mainframe_P.Constant8_Value_g5
	  section.data(79).logicalSrcIdx = 199;
	  section.data(79).dtTransOffset = 742;
	
	  ;% Mainframe_P.Constant2_Value_io
	  section.data(80).logicalSrcIdx = 200;
	  section.data(80).dtTransOffset = 743;
	
	  ;% Mainframe_P.Constant1_Value_d
	  section.data(81).logicalSrcIdx = 201;
	  section.data(81).dtTransOffset = 744;
	
	  ;% Mainframe_P.Constant_Value_hm
	  section.data(82).logicalSrcIdx = 202;
	  section.data(82).dtTransOffset = 745;
	
	  ;% Mainframe_P.Constant11_Value_o
	  section.data(83).logicalSrcIdx = 203;
	  section.data(83).dtTransOffset = 746;
	
	  ;% Mainframe_P.Constant10_Value_g
	  section.data(84).logicalSrcIdx = 204;
	  section.data(84).dtTransOffset = 747;
	
	  ;% Mainframe_P.Constant4_Value_o
	  section.data(85).logicalSrcIdx = 205;
	  section.data(85).dtTransOffset = 748;
	
	  ;% Mainframe_P.Constant7_Value_ct
	  section.data(86).logicalSrcIdx = 206;
	  section.data(86).dtTransOffset = 749;
	
	  ;% Mainframe_P.Constant8_Value_c
	  section.data(87).logicalSrcIdx = 207;
	  section.data(87).dtTransOffset = 750;
	
	  ;% Mainframe_P.Gain_Gain_pz
	  section.data(88).logicalSrcIdx = 208;
	  section.data(88).dtTransOffset = 751;
	
	  ;% Mainframe_P.Constant7_Value_i
	  section.data(89).logicalSrcIdx = 209;
	  section.data(89).dtTransOffset = 752;
	
	  ;% Mainframe_P.Gain1_Gain_h
	  section.data(90).logicalSrcIdx = 210;
	  section.data(90).dtTransOffset = 753;
	
	  ;% Mainframe_P.Constant2_Value_l
	  section.data(91).logicalSrcIdx = 211;
	  section.data(91).dtTransOffset = 754;
	
	  ;% Mainframe_P.Constant1_Value_h
	  section.data(92).logicalSrcIdx = 212;
	  section.data(92).dtTransOffset = 755;
	
	  ;% Mainframe_P.Constant_Value_lv
	  section.data(93).logicalSrcIdx = 213;
	  section.data(93).dtTransOffset = 756;
	
	  ;% Mainframe_P.Constant8_Value_cm
	  section.data(94).logicalSrcIdx = 214;
	  section.data(94).dtTransOffset = 757;
	
	  ;% Mainframe_P.Constant7_Value_ih
	  section.data(95).logicalSrcIdx = 215;
	  section.data(95).dtTransOffset = 758;
	
	  ;% Mainframe_P.Gain_Gain_dp
	  section.data(96).logicalSrcIdx = 216;
	  section.data(96).dtTransOffset = 759;
	
	  ;% Mainframe_P.Constant8_Value_m
	  section.data(97).logicalSrcIdx = 217;
	  section.data(97).dtTransOffset = 760;
	
	  ;% Mainframe_P.Constant2_Value_f
	  section.data(98).logicalSrcIdx = 218;
	  section.data(98).dtTransOffset = 761;
	
	  ;% Mainframe_P.Constant1_Value_l
	  section.data(99).logicalSrcIdx = 219;
	  section.data(99).dtTransOffset = 762;
	
	  ;% Mainframe_P.Constant_Value_h1
	  section.data(100).logicalSrcIdx = 220;
	  section.data(100).dtTransOffset = 763;
	
	  ;% Mainframe_P.Gain_Gain_im
	  section.data(101).logicalSrcIdx = 221;
	  section.data(101).dtTransOffset = 764;
	
	  ;% Mainframe_P.Constant_Value_c5
	  section.data(102).logicalSrcIdx = 222;
	  section.data(102).dtTransOffset = 765;
	
	  ;% Mainframe_P.Saturation_UpperSat_p
	  section.data(103).logicalSrcIdx = 223;
	  section.data(103).dtTransOffset = 766;
	
	  ;% Mainframe_P.Saturation_LowerSat_g
	  section.data(104).logicalSrcIdx = 224;
	  section.data(104).dtTransOffset = 767;
	
	  ;% Mainframe_P.Gain_Gain_kz
	  section.data(105).logicalSrcIdx = 225;
	  section.data(105).dtTransOffset = 768;
	
	  ;% Mainframe_P.Constant_Value_i
	  section.data(106).logicalSrcIdx = 226;
	  section.data(106).dtTransOffset = 769;
	
	  ;% Mainframe_P.Saturation_UpperSat_h
	  section.data(107).logicalSrcIdx = 227;
	  section.data(107).dtTransOffset = 770;
	
	  ;% Mainframe_P.Saturation_LowerSat_a
	  section.data(108).logicalSrcIdx = 228;
	  section.data(108).dtTransOffset = 771;
	
	  ;% Mainframe_P.Gain_Gain_lq
	  section.data(109).logicalSrcIdx = 229;
	  section.data(109).dtTransOffset = 772;
	
	  ;% Mainframe_P.Constant_Value_p
	  section.data(110).logicalSrcIdx = 230;
	  section.data(110).dtTransOffset = 773;
	
	  ;% Mainframe_P.Saturation_UpperSat_pr
	  section.data(111).logicalSrcIdx = 231;
	  section.data(111).dtTransOffset = 774;
	
	  ;% Mainframe_P.Saturation_LowerSat_e
	  section.data(112).logicalSrcIdx = 232;
	  section.data(112).dtTransOffset = 775;
	
	  ;% Mainframe_P.Gain_Gain_m
	  section.data(113).logicalSrcIdx = 233;
	  section.data(113).dtTransOffset = 776;
	
	  ;% Mainframe_P.Constant_Value_j
	  section.data(114).logicalSrcIdx = 234;
	  section.data(114).dtTransOffset = 777;
	
	  ;% Mainframe_P.Saturation_UpperSat_k
	  section.data(115).logicalSrcIdx = 235;
	  section.data(115).dtTransOffset = 778;
	
	  ;% Mainframe_P.Saturation_LowerSat_b
	  section.data(116).logicalSrcIdx = 236;
	  section.data(116).dtTransOffset = 779;
	
	  ;% Mainframe_P.Gain_Gain_ih
	  section.data(117).logicalSrcIdx = 237;
	  section.data(117).dtTransOffset = 780;
	
	  ;% Mainframe_P.Gain12_Gain
	  section.data(118).logicalSrcIdx = 238;
	  section.data(118).dtTransOffset = 781;
	
	  ;% Mainframe_P.Gain11_Gain
	  section.data(119).logicalSrcIdx = 239;
	  section.data(119).dtTransOffset = 782;
	
	  ;% Mainframe_P.Gain6_Gain
	  section.data(120).logicalSrcIdx = 240;
	  section.data(120).dtTransOffset = 783;
	
	  ;% Mainframe_P.Gain5_Gain
	  section.data(121).logicalSrcIdx = 241;
	  section.data(121).dtTransOffset = 784;
	
	  ;% Mainframe_P.Gain4_Gain
	  section.data(122).logicalSrcIdx = 242;
	  section.data(122).dtTransOffset = 785;
	
	  ;% Mainframe_P.Gain3_Gain
	  section.data(123).logicalSrcIdx = 243;
	  section.data(123).dtTransOffset = 786;
	
	  ;% Mainframe_P.Gain8_Gain
	  section.data(124).logicalSrcIdx = 244;
	  section.data(124).dtTransOffset = 787;
	
	  ;% Mainframe_P.Gain7_Gain
	  section.data(125).logicalSrcIdx = 245;
	  section.data(125).dtTransOffset = 788;
	
	  ;% Mainframe_P.Gain10_Gain
	  section.data(126).logicalSrcIdx = 246;
	  section.data(126).dtTransOffset = 789;
	
	  ;% Mainframe_P.Gain9_Gain
	  section.data(127).logicalSrcIdx = 247;
	  section.data(127).dtTransOffset = 790;
	
	  ;% Mainframe_P.Gain2_Gain_j
	  section.data(128).logicalSrcIdx = 248;
	  section.data(128).dtTransOffset = 791;
	
	  ;% Mainframe_P.Gain1_Gain_g
	  section.data(129).logicalSrcIdx = 249;
	  section.data(129).dtTransOffset = 792;
	
	  ;% Mainframe_P.Saturation_UpperSat_d
	  section.data(130).logicalSrcIdx = 250;
	  section.data(130).dtTransOffset = 793;
	
	  ;% Mainframe_P.Saturation_LowerSat_ee
	  section.data(131).logicalSrcIdx = 251;
	  section.data(131).dtTransOffset = 794;
	
	  ;% Mainframe_P.uDLookupTable_tableData
	  section.data(132).logicalSrcIdx = 252;
	  section.data(132).dtTransOffset = 795;
	
	  ;% Mainframe_P.uDLookupTable_bp01Data
	  section.data(133).logicalSrcIdx = 253;
	  section.data(133).dtTransOffset = 1128;
	
	  ;% Mainframe_P.Constant11_Value_l
	  section.data(134).logicalSrcIdx = 254;
	  section.data(134).dtTransOffset = 1461;
	
	  ;% Mainframe_P.Constant10_Value_k
	  section.data(135).logicalSrcIdx = 255;
	  section.data(135).dtTransOffset = 1462;
	
	  ;% Mainframe_P.Constant4_Value_i
	  section.data(136).logicalSrcIdx = 256;
	  section.data(136).dtTransOffset = 1463;
	
	  ;% Mainframe_P.Constant7_Value_a5
	  section.data(137).logicalSrcIdx = 257;
	  section.data(137).dtTransOffset = 1464;
	
	  ;% Mainframe_P.Constant8_Value_j1
	  section.data(138).logicalSrcIdx = 258;
	  section.data(138).dtTransOffset = 1465;
	
	  ;% Mainframe_P.Gain_Gain_h
	  section.data(139).logicalSrcIdx = 259;
	  section.data(139).dtTransOffset = 1466;
	
	  ;% Mainframe_P.Constant7_Value_op
	  section.data(140).logicalSrcIdx = 260;
	  section.data(140).dtTransOffset = 1467;
	
	  ;% Mainframe_P.Gain1_Gain_g4
	  section.data(141).logicalSrcIdx = 261;
	  section.data(141).dtTransOffset = 1468;
	
	  ;% Mainframe_P.Constant2_Value_j
	  section.data(142).logicalSrcIdx = 262;
	  section.data(142).dtTransOffset = 1469;
	
	  ;% Mainframe_P.Constant1_Value_jv
	  section.data(143).logicalSrcIdx = 263;
	  section.data(143).dtTransOffset = 1470;
	
	  ;% Mainframe_P.Constant_Value_f
	  section.data(144).logicalSrcIdx = 264;
	  section.data(144).dtTransOffset = 1471;
	
	  ;% Mainframe_P.Constant8_Value_gc
	  section.data(145).logicalSrcIdx = 265;
	  section.data(145).dtTransOffset = 1472;
	
	  ;% Mainframe_P.Constant7_Value_g
	  section.data(146).logicalSrcIdx = 266;
	  section.data(146).dtTransOffset = 1473;
	
	  ;% Mainframe_P.Gain_Gain_gk
	  section.data(147).logicalSrcIdx = 267;
	  section.data(147).dtTransOffset = 1474;
	
	  ;% Mainframe_P.Constant8_Value_l
	  section.data(148).logicalSrcIdx = 268;
	  section.data(148).dtTransOffset = 1475;
	
	  ;% Mainframe_P.Constant2_Value_m
	  section.data(149).logicalSrcIdx = 269;
	  section.data(149).dtTransOffset = 1476;
	
	  ;% Mainframe_P.Constant1_Value_i
	  section.data(150).logicalSrcIdx = 270;
	  section.data(150).dtTransOffset = 1477;
	
	  ;% Mainframe_P.Constant_Value_pf
	  section.data(151).logicalSrcIdx = 271;
	  section.data(151).dtTransOffset = 1478;
	
	  ;% Mainframe_P.Constant11_Value_lg
	  section.data(152).logicalSrcIdx = 272;
	  section.data(152).dtTransOffset = 1479;
	
	  ;% Mainframe_P.Constant10_Value_i
	  section.data(153).logicalSrcIdx = 273;
	  section.data(153).dtTransOffset = 1480;
	
	  ;% Mainframe_P.Constant4_Value_j
	  section.data(154).logicalSrcIdx = 274;
	  section.data(154).dtTransOffset = 1481;
	
	  ;% Mainframe_P.Constant7_Value_n
	  section.data(155).logicalSrcIdx = 275;
	  section.data(155).dtTransOffset = 1482;
	
	  ;% Mainframe_P.Constant8_Value_mn
	  section.data(156).logicalSrcIdx = 276;
	  section.data(156).dtTransOffset = 1483;
	
	  ;% Mainframe_P.Gain_Gain_c4
	  section.data(157).logicalSrcIdx = 277;
	  section.data(157).dtTransOffset = 1484;
	
	  ;% Mainframe_P.Constant7_Value_l
	  section.data(158).logicalSrcIdx = 278;
	  section.data(158).dtTransOffset = 1485;
	
	  ;% Mainframe_P.Gain1_Gain_cw
	  section.data(159).logicalSrcIdx = 279;
	  section.data(159).dtTransOffset = 1486;
	
	  ;% Mainframe_P.Constant2_Value_ia
	  section.data(160).logicalSrcIdx = 280;
	  section.data(160).dtTransOffset = 1487;
	
	  ;% Mainframe_P.Constant1_Value_jy
	  section.data(161).logicalSrcIdx = 281;
	  section.data(161).dtTransOffset = 1488;
	
	  ;% Mainframe_P.Constant_Value_b4
	  section.data(162).logicalSrcIdx = 282;
	  section.data(162).dtTransOffset = 1489;
	
	  ;% Mainframe_P.Constant8_Value_cx
	  section.data(163).logicalSrcIdx = 283;
	  section.data(163).dtTransOffset = 1490;
	
	  ;% Mainframe_P.Constant7_Value_e
	  section.data(164).logicalSrcIdx = 284;
	  section.data(164).dtTransOffset = 1491;
	
	  ;% Mainframe_P.Gain_Gain_o
	  section.data(165).logicalSrcIdx = 285;
	  section.data(165).dtTransOffset = 1492;
	
	  ;% Mainframe_P.Constant8_Value_e
	  section.data(166).logicalSrcIdx = 286;
	  section.data(166).dtTransOffset = 1493;
	
	  ;% Mainframe_P.Constant2_Value_i3
	  section.data(167).logicalSrcIdx = 287;
	  section.data(167).dtTransOffset = 1494;
	
	  ;% Mainframe_P.Constant1_Value_f
	  section.data(168).logicalSrcIdx = 288;
	  section.data(168).dtTransOffset = 1495;
	
	  ;% Mainframe_P.Constant_Value_m
	  section.data(169).logicalSrcIdx = 289;
	  section.data(169).dtTransOffset = 1496;
	
	  ;% Mainframe_P.Constant11_Value_lo
	  section.data(170).logicalSrcIdx = 290;
	  section.data(170).dtTransOffset = 1497;
	
	  ;% Mainframe_P.Constant10_Value_a
	  section.data(171).logicalSrcIdx = 291;
	  section.data(171).dtTransOffset = 1498;
	
	  ;% Mainframe_P.Constant4_Value_h
	  section.data(172).logicalSrcIdx = 292;
	  section.data(172).dtTransOffset = 1499;
	
	  ;% Mainframe_P.Constant7_Value_ah
	  section.data(173).logicalSrcIdx = 293;
	  section.data(173).dtTransOffset = 1500;
	
	  ;% Mainframe_P.Constant8_Value_my
	  section.data(174).logicalSrcIdx = 294;
	  section.data(174).dtTransOffset = 1501;
	
	  ;% Mainframe_P.Gain_Gain_ib
	  section.data(175).logicalSrcIdx = 295;
	  section.data(175).dtTransOffset = 1502;
	
	  ;% Mainframe_P.Constant7_Value_ow
	  section.data(176).logicalSrcIdx = 296;
	  section.data(176).dtTransOffset = 1503;
	
	  ;% Mainframe_P.Gain1_Gain_b
	  section.data(177).logicalSrcIdx = 297;
	  section.data(177).dtTransOffset = 1504;
	
	  ;% Mainframe_P.Constant2_Value_b
	  section.data(178).logicalSrcIdx = 298;
	  section.data(178).dtTransOffset = 1505;
	
	  ;% Mainframe_P.Constant1_Value_p
	  section.data(179).logicalSrcIdx = 299;
	  section.data(179).dtTransOffset = 1506;
	
	  ;% Mainframe_P.Constant_Value_d
	  section.data(180).logicalSrcIdx = 300;
	  section.data(180).dtTransOffset = 1507;
	
	  ;% Mainframe_P.Constant8_Value_c0
	  section.data(181).logicalSrcIdx = 301;
	  section.data(181).dtTransOffset = 1508;
	
	  ;% Mainframe_P.Constant7_Value_b
	  section.data(182).logicalSrcIdx = 302;
	  section.data(182).dtTransOffset = 1509;
	
	  ;% Mainframe_P.Gain_Gain_kc
	  section.data(183).logicalSrcIdx = 303;
	  section.data(183).dtTransOffset = 1510;
	
	  ;% Mainframe_P.Constant8_Value_o
	  section.data(184).logicalSrcIdx = 304;
	  section.data(184).dtTransOffset = 1511;
	
	  ;% Mainframe_P.Constant2_Value_g
	  section.data(185).logicalSrcIdx = 305;
	  section.data(185).dtTransOffset = 1512;
	
	  ;% Mainframe_P.Constant1_Value_g
	  section.data(186).logicalSrcIdx = 306;
	  section.data(186).dtTransOffset = 1513;
	
	  ;% Mainframe_P.Constant_Value_dt
	  section.data(187).logicalSrcIdx = 307;
	  section.data(187).dtTransOffset = 1514;
	
	  ;% Mainframe_P.Constant_Value_g
	  section.data(188).logicalSrcIdx = 308;
	  section.data(188).dtTransOffset = 1515;
	
	  ;% Mainframe_P.Constant_Value_ck
	  section.data(189).logicalSrcIdx = 309;
	  section.data(189).dtTransOffset = 1516;
	
	  ;% Mainframe_P.Constant_Value_o0
	  section.data(190).logicalSrcIdx = 310;
	  section.data(190).dtTransOffset = 1517;
	
	  ;% Mainframe_P.Constant_Value_pq
	  section.data(191).logicalSrcIdx = 311;
	  section.data(191).dtTransOffset = 1518;
	
	  ;% Mainframe_P.Constant_Value_a
	  section.data(192).logicalSrcIdx = 312;
	  section.data(192).dtTransOffset = 1519;
	
	  ;% Mainframe_P.Constant_Value_kz
	  section.data(193).logicalSrcIdx = 313;
	  section.data(193).dtTransOffset = 1520;
	
	  ;% Mainframe_P.Constant_Value_g4
	  section.data(194).logicalSrcIdx = 314;
	  section.data(194).dtTransOffset = 1521;
	
	  ;% Mainframe_P.Constant_Value_do
	  section.data(195).logicalSrcIdx = 315;
	  section.data(195).dtTransOffset = 1522;
	
	  ;% Mainframe_P.Constant_Value_g1
	  section.data(196).logicalSrcIdx = 316;
	  section.data(196).dtTransOffset = 1523;
	
	  ;% Mainframe_P.Constant_Value_gb
	  section.data(197).logicalSrcIdx = 317;
	  section.data(197).dtTransOffset = 1524;
	
	  ;% Mainframe_P.Constant_Value_gf
	  section.data(198).logicalSrcIdx = 318;
	  section.data(198).dtTransOffset = 1525;
	
	  ;% Mainframe_P.Constant_Value_ok
	  section.data(199).logicalSrcIdx = 319;
	  section.data(199).dtTransOffset = 1526;
	
	  ;% Mainframe_P.Constant1_Value_c
	  section.data(200).logicalSrcIdx = 320;
	  section.data(200).dtTransOffset = 1527;
	
	  ;% Mainframe_P.Constant_Value_cg
	  section.data(201).logicalSrcIdx = 321;
	  section.data(201).dtTransOffset = 1530;
	
	  ;% Mainframe_P.Constant_Value_ix
	  section.data(202).logicalSrcIdx = 322;
	  section.data(202).dtTransOffset = 1543;
	
	  ;% Mainframe_P.Gain_Gain_iz
	  section.data(203).logicalSrcIdx = 323;
	  section.data(203).dtTransOffset = 1544;
	
	  ;% Mainframe_P.Saturation_UpperSat_ph
	  section.data(204).logicalSrcIdx = 324;
	  section.data(204).dtTransOffset = 1545;
	
	  ;% Mainframe_P.Saturation_LowerSat_o
	  section.data(205).logicalSrcIdx = 325;
	  section.data(205).dtTransOffset = 1546;
	
	  ;% Mainframe_P.Constant1_Value_la
	  section.data(206).logicalSrcIdx = 326;
	  section.data(206).dtTransOffset = 1547;
	
	  ;% Mainframe_P.Multiply_Gain
	  section.data(207).logicalSrcIdx = 327;
	  section.data(207).dtTransOffset = 1548;
	
	  ;% Mainframe_P.Multiply1_Gain
	  section.data(208).logicalSrcIdx = 328;
	  section.data(208).dtTransOffset = 1549;
	
	  ;% Mainframe_P.Multiply2_Gain
	  section.data(209).logicalSrcIdx = 329;
	  section.data(209).dtTransOffset = 1550;
	
	  ;% Mainframe_P.u2_Gain
	  section.data(210).logicalSrcIdx = 330;
	  section.data(210).dtTransOffset = 1551;
	
	  ;% Mainframe_P.Gain1_Gain_l
	  section.data(211).logicalSrcIdx = 331;
	  section.data(211).dtTransOffset = 1552;
	
	  ;% Mainframe_P.Gain2_Gain_o
	  section.data(212).logicalSrcIdx = 332;
	  section.data(212).dtTransOffset = 1553;
	
	  ;% Mainframe_P.Gain9_Gain_f
	  section.data(213).logicalSrcIdx = 333;
	  section.data(213).dtTransOffset = 1554;
	
	  ;% Mainframe_P.Gain10_Gain_o
	  section.data(214).logicalSrcIdx = 334;
	  section.data(214).dtTransOffset = 1555;
	
	  ;% Mainframe_P.Gain7_Gain_h
	  section.data(215).logicalSrcIdx = 335;
	  section.data(215).dtTransOffset = 1556;
	
	  ;% Mainframe_P.Gain8_Gain_f
	  section.data(216).logicalSrcIdx = 336;
	  section.data(216).dtTransOffset = 1557;
	
	  ;% Mainframe_P.Gain3_Gain_m
	  section.data(217).logicalSrcIdx = 337;
	  section.data(217).dtTransOffset = 1558;
	
	  ;% Mainframe_P.Gain4_Gain_g
	  section.data(218).logicalSrcIdx = 338;
	  section.data(218).dtTransOffset = 1559;
	
	  ;% Mainframe_P.Gain5_Gain_i
	  section.data(219).logicalSrcIdx = 339;
	  section.data(219).dtTransOffset = 1560;
	
	  ;% Mainframe_P.Gain6_Gain_e
	  section.data(220).logicalSrcIdx = 340;
	  section.data(220).dtTransOffset = 1561;
	
	  ;% Mainframe_P.Gain11_Gain_k
	  section.data(221).logicalSrcIdx = 341;
	  section.data(221).dtTransOffset = 1562;
	
	  ;% Mainframe_P.Gain12_Gain_j
	  section.data(222).logicalSrcIdx = 342;
	  section.data(222).dtTransOffset = 1563;
	
	  ;% Mainframe_P.Q_1_Value
	  section.data(223).logicalSrcIdx = 343;
	  section.data(223).dtTransOffset = 1564;
	
	  ;% Mainframe_P.Q_2_Value
	  section.data(224).logicalSrcIdx = 344;
	  section.data(224).dtTransOffset = 1580;
	
	  ;% Mainframe_P.Q_3_Value
	  section.data(225).logicalSrcIdx = 345;
	  section.data(225).dtTransOffset = 1596;
	
	  ;% Mainframe_P.Q_4_Value
	  section.data(226).logicalSrcIdx = 346;
	  section.data(226).dtTransOffset = 1612;
	
	  ;% Mainframe_P.Q_1_Value_d
	  section.data(227).logicalSrcIdx = 347;
	  section.data(227).dtTransOffset = 1628;
	
	  ;% Mainframe_P.Q_2_Value_f
	  section.data(228).logicalSrcIdx = 348;
	  section.data(228).dtTransOffset = 1644;
	
	  ;% Mainframe_P.Q_3_Value_c
	  section.data(229).logicalSrcIdx = 349;
	  section.data(229).dtTransOffset = 1660;
	
	  ;% Mainframe_P.Q_4_Value_n
	  section.data(230).logicalSrcIdx = 350;
	  section.data(230).dtTransOffset = 1676;
	
	  ;% Mainframe_P.Constant_Value_od
	  section.data(231).logicalSrcIdx = 351;
	  section.data(231).dtTransOffset = 1692;
	
	  ;% Mainframe_P.Constant8_Value_mc
	  section.data(232).logicalSrcIdx = 352;
	  section.data(232).dtTransOffset = 1693;
	
	  ;% Mainframe_P.Gain1_Gain_mx
	  section.data(233).logicalSrcIdx = 353;
	  section.data(233).dtTransOffset = 1697;
	
	  ;% Mainframe_P.Gain2_Gain_i
	  section.data(234).logicalSrcIdx = 354;
	  section.data(234).dtTransOffset = 1698;
	
	  ;% Mainframe_P.Gain9_Gain_fk
	  section.data(235).logicalSrcIdx = 355;
	  section.data(235).dtTransOffset = 1699;
	
	  ;% Mainframe_P.Gain10_Gain_f
	  section.data(236).logicalSrcIdx = 356;
	  section.data(236).dtTransOffset = 1700;
	
	  ;% Mainframe_P.Gain7_Gain_k
	  section.data(237).logicalSrcIdx = 357;
	  section.data(237).dtTransOffset = 1701;
	
	  ;% Mainframe_P.Gain8_Gain_a
	  section.data(238).logicalSrcIdx = 358;
	  section.data(238).dtTransOffset = 1702;
	
	  ;% Mainframe_P.Gain3_Gain_n
	  section.data(239).logicalSrcIdx = 359;
	  section.data(239).dtTransOffset = 1703;
	
	  ;% Mainframe_P.Gain4_Gain_k
	  section.data(240).logicalSrcIdx = 360;
	  section.data(240).dtTransOffset = 1704;
	
	  ;% Mainframe_P.Gain5_Gain_l
	  section.data(241).logicalSrcIdx = 361;
	  section.data(241).dtTransOffset = 1705;
	
	  ;% Mainframe_P.Gain6_Gain_d
	  section.data(242).logicalSrcIdx = 362;
	  section.data(242).dtTransOffset = 1706;
	
	  ;% Mainframe_P.Gain11_Gain_m
	  section.data(243).logicalSrcIdx = 363;
	  section.data(243).dtTransOffset = 1707;
	
	  ;% Mainframe_P.Gain12_Gain_o
	  section.data(244).logicalSrcIdx = 364;
	  section.data(244).dtTransOffset = 1708;
	
	  ;% Mainframe_P.Constant9_Value
	  section.data(245).logicalSrcIdx = 365;
	  section.data(245).dtTransOffset = 1709;
	
	  ;% Mainframe_P.Switch_Threshold
	  section.data(246).logicalSrcIdx = 366;
	  section.data(246).dtTransOffset = 1710;
	
	  ;% Mainframe_P.Constant_Value_fh
	  section.data(247).logicalSrcIdx = 367;
	  section.data(247).dtTransOffset = 1711;
	
	  ;% Mainframe_P.Saturation2_UpperSat
	  section.data(248).logicalSrcIdx = 368;
	  section.data(248).dtTransOffset = 1715;
	
	  ;% Mainframe_P.Saturation2_LowerSat
	  section.data(249).logicalSrcIdx = 369;
	  section.data(249).dtTransOffset = 1716;
	
	  ;% Mainframe_P.Gain2_Gain_h
	  section.data(250).logicalSrcIdx = 370;
	  section.data(250).dtTransOffset = 1717;
	
	  ;% Mainframe_P.Gain3_Gain_l
	  section.data(251).logicalSrcIdx = 371;
	  section.data(251).dtTransOffset = 1718;
	
	  ;% Mainframe_P.Saturation3_UpperSat
	  section.data(252).logicalSrcIdx = 372;
	  section.data(252).dtTransOffset = 1719;
	
	  ;% Mainframe_P.Saturation3_LowerSat
	  section.data(253).logicalSrcIdx = 373;
	  section.data(253).dtTransOffset = 1720;
	
	  ;% Mainframe_P.Gain4_Gain_j
	  section.data(254).logicalSrcIdx = 374;
	  section.data(254).dtTransOffset = 1721;
	
	  ;% Mainframe_P.Gain5_Gain_a
	  section.data(255).logicalSrcIdx = 375;
	  section.data(255).dtTransOffset = 1722;
	
	  ;% Mainframe_P.Constant8_Value_d
	  section.data(256).logicalSrcIdx = 376;
	  section.data(256).dtTransOffset = 1723;
	
	  ;% Mainframe_P.Constant7_Value_k
	  section.data(257).logicalSrcIdx = 377;
	  section.data(257).dtTransOffset = 1735;
	
	  ;% Mainframe_P.Gain6_Gain_a
	  section.data(258).logicalSrcIdx = 378;
	  section.data(258).dtTransOffset = 1736;
	
	  ;% Mainframe_P.Gain7_Gain_b
	  section.data(259).logicalSrcIdx = 379;
	  section.data(259).dtTransOffset = 1737;
	
	  ;% Mainframe_P.Constant_Value_mq
	  section.data(260).logicalSrcIdx = 380;
	  section.data(260).dtTransOffset = 1738;
	
	  ;% Mainframe_P.Gain_Gain_mn
	  section.data(261).logicalSrcIdx = 381;
	  section.data(261).dtTransOffset = 1739;
	
	  ;% Mainframe_P.Gain1_Gain_o
	  section.data(262).logicalSrcIdx = 382;
	  section.data(262).dtTransOffset = 1740;
	
	  ;% Mainframe_P.Constant_Value_kb
	  section.data(263).logicalSrcIdx = 383;
	  section.data(263).dtTransOffset = 1741;
	
	  ;% Mainframe_P.Gain_Gain_px
	  section.data(264).logicalSrcIdx = 384;
	  section.data(264).dtTransOffset = 1742;
	
	  ;% Mainframe_P.Gain1_Gain_ov
	  section.data(265).logicalSrcIdx = 385;
	  section.data(265).dtTransOffset = 1743;
	
	  ;% Mainframe_P.Constant2_Value_jd
	  section.data(266).logicalSrcIdx = 386;
	  section.data(266).dtTransOffset = 1744;
	
	  ;% Mainframe_P.Constant_Value_e
	  section.data(267).logicalSrcIdx = 387;
	  section.data(267).dtTransOffset = 1745;
	
	  ;% Mainframe_P.Tmp_norm_msl_Value
	  section.data(268).logicalSrcIdx = 388;
	  section.data(268).dtTransOffset = 1746;
	
	  ;% Mainframe_P.Tmp_gradient_tropo_Value
	  section.data(269).logicalSrcIdx = 389;
	  section.data(269).dtTransOffset = 1747;
	
	  ;% Mainframe_P.Constant_Value_ja
	  section.data(270).logicalSrcIdx = 390;
	  section.data(270).dtTransOffset = 1748;
	
	  ;% Mainframe_P.Constant2_Value_px
	  section.data(271).logicalSrcIdx = 391;
	  section.data(271).dtTransOffset = 1749;
	
	  ;% Mainframe_P.Constant1_Value_hf
	  section.data(272).logicalSrcIdx = 392;
	  section.data(272).dtTransOffset = 1750;
	
	  ;% Mainframe_P.c_rsma_Value_n
	  section.data(273).logicalSrcIdx = 393;
	  section.data(273).dtTransOffset = 1751;
	
	  ;% Mainframe_P.Constant_Value_ae
	  section.data(274).logicalSrcIdx = 394;
	  section.data(274).dtTransOffset = 1752;
	
	  ;% Mainframe_P.c_flat_Value_j
	  section.data(275).logicalSrcIdx = 395;
	  section.data(275).dtTransOffset = 1753;
	
	  ;% Mainframe_P.Gain_Gain_he
	  section.data(276).logicalSrcIdx = 396;
	  section.data(276).dtTransOffset = 1754;
	
	  ;% Mainframe_P.Constant_Value_cc
	  section.data(277).logicalSrcIdx = 397;
	  section.data(277).dtTransOffset = 1755;
	
	  ;% Mainframe_P.Gain_Gain_pd
	  section.data(278).logicalSrcIdx = 398;
	  section.data(278).dtTransOffset = 1756;
	
	  ;% Mainframe_P.Switch_Threshold_f
	  section.data(279).logicalSrcIdx = 399;
	  section.data(279).dtTransOffset = 1757;
	
	  ;% Mainframe_P.Saturation_UpperSat_e
	  section.data(280).logicalSrcIdx = 400;
	  section.data(280).dtTransOffset = 1758;
	
	  ;% Mainframe_P.Saturation_LowerSat_oe
	  section.data(281).logicalSrcIdx = 401;
	  section.data(281).dtTransOffset = 1759;
	
	  ;% Mainframe_P.geopotential_height_ref_Value
	  section.data(282).logicalSrcIdx = 402;
	  section.data(282).dtTransOffset = 1760;
	
	  ;% Mainframe_P.Constant1_Value_pz
	  section.data(283).logicalSrcIdx = 403;
	  section.data(283).dtTransOffset = 1761;
	
	  ;% Mainframe_P.Tmp_gradient_tropo_Value_p
	  section.data(284).logicalSrcIdx = 404;
	  section.data(284).dtTransOffset = 1762;
	
	  ;% Mainframe_P.pressure_exponent_Value
	  section.data(285).logicalSrcIdx = 405;
	  section.data(285).dtTransOffset = 1763;
	
	  ;% Mainframe_P.pa_norm_msl_Value
	  section.data(286).logicalSrcIdx = 406;
	  section.data(286).dtTransOffset = 1764;
	
	  ;% Mainframe_P.specific_gas_constant_Value
	  section.data(287).logicalSrcIdx = 407;
	  section.data(287).dtTransOffset = 1765;
	
	  ;% Mainframe_P.Constant1_Value_hj
	  section.data(288).logicalSrcIdx = 408;
	  section.data(288).dtTransOffset = 1766;
	
	  ;% Mainframe_P.Constant_Value_es
	  section.data(289).logicalSrcIdx = 409;
	  section.data(289).dtTransOffset = 1767;
	
	  ;% Mainframe_P.Constant2_Value_jj
	  section.data(290).logicalSrcIdx = 410;
	  section.data(290).dtTransOffset = 1770;
	
	  ;% Mainframe_P.Switch1_Threshold
	  section.data(291).logicalSrcIdx = 411;
	  section.data(291).dtTransOffset = 1771;
	
	  ;% Mainframe_P.Constant3_Value
	  section.data(292).logicalSrcIdx = 412;
	  section.data(292).dtTransOffset = 1772;
	
	  ;% Mainframe_P.Switch_Threshold_a
	  section.data(293).logicalSrcIdx = 413;
	  section.data(293).dtTransOffset = 1773;
	
	  ;% Mainframe_P.Q_1_Value_g
	  section.data(294).logicalSrcIdx = 414;
	  section.data(294).dtTransOffset = 1774;
	
	  ;% Mainframe_P.Q_1_Value_p
	  section.data(295).logicalSrcIdx = 415;
	  section.data(295).dtTransOffset = 1790;
	
	  ;% Mainframe_P.Q_2_Value_c
	  section.data(296).logicalSrcIdx = 416;
	  section.data(296).dtTransOffset = 1806;
	
	  ;% Mainframe_P.Q_3_Value_h
	  section.data(297).logicalSrcIdx = 417;
	  section.data(297).dtTransOffset = 1822;
	
	  ;% Mainframe_P.Q_4_Value_g
	  section.data(298).logicalSrcIdx = 418;
	  section.data(298).dtTransOffset = 1838;
	
	  ;% Mainframe_P.Constant8_Value_el
	  section.data(299).logicalSrcIdx = 419;
	  section.data(299).dtTransOffset = 1854;
	
	  ;% Mainframe_P.Constant_Value_p0
	  section.data(300).logicalSrcIdx = 420;
	  section.data(300).dtTransOffset = 1858;
	
	  ;% Mainframe_P.Constant1_Value_jf
	  section.data(301).logicalSrcIdx = 421;
	  section.data(301).dtTransOffset = 1859;
	
	  ;% Mainframe_P.Switch_Threshold_i
	  section.data(302).logicalSrcIdx = 422;
	  section.data(302).dtTransOffset = 1860;
	
	  ;% Mainframe_P.Gain1_Gain_n
	  section.data(303).logicalSrcIdx = 423;
	  section.data(303).dtTransOffset = 1861;
	
	  ;% Mainframe_P.Q_2_Value_h
	  section.data(304).logicalSrcIdx = 424;
	  section.data(304).dtTransOffset = 1862;
	
	  ;% Mainframe_P.Q_3_Value_h3
	  section.data(305).logicalSrcIdx = 425;
	  section.data(305).dtTransOffset = 1878;
	
	  ;% Mainframe_P.Q_4_Value_e
	  section.data(306).logicalSrcIdx = 426;
	  section.data(306).dtTransOffset = 1894;
	
	  ;% Mainframe_P.Constant_Value_az
	  section.data(307).logicalSrcIdx = 427;
	  section.data(307).dtTransOffset = 1910;
	
	  ;% Mainframe_P.Constant1_Value_hk
	  section.data(308).logicalSrcIdx = 428;
	  section.data(308).dtTransOffset = 1911;
	
	  ;% Mainframe_P.Switch_Threshold_a2
	  section.data(309).logicalSrcIdx = 429;
	  section.data(309).dtTransOffset = 1912;
	
	  ;% Mainframe_P.Gain1_Gain_b3
	  section.data(310).logicalSrcIdx = 430;
	  section.data(310).dtTransOffset = 1913;
	
	  ;% Mainframe_P.Gain2_Gain_fo
	  section.data(311).logicalSrcIdx = 431;
	  section.data(311).dtTransOffset = 1914;
	
	  ;% Mainframe_P.Gain9_Gain_e
	  section.data(312).logicalSrcIdx = 432;
	  section.data(312).dtTransOffset = 1915;
	
	  ;% Mainframe_P.Gain10_Gain_i
	  section.data(313).logicalSrcIdx = 433;
	  section.data(313).dtTransOffset = 1916;
	
	  ;% Mainframe_P.Gain7_Gain_n
	  section.data(314).logicalSrcIdx = 434;
	  section.data(314).dtTransOffset = 1917;
	
	  ;% Mainframe_P.Gain8_Gain_o
	  section.data(315).logicalSrcIdx = 435;
	  section.data(315).dtTransOffset = 1918;
	
	  ;% Mainframe_P.Gain3_Gain_i
	  section.data(316).logicalSrcIdx = 436;
	  section.data(316).dtTransOffset = 1919;
	
	  ;% Mainframe_P.Gain4_Gain_m
	  section.data(317).logicalSrcIdx = 437;
	  section.data(317).dtTransOffset = 1920;
	
	  ;% Mainframe_P.Gain5_Gain_c
	  section.data(318).logicalSrcIdx = 438;
	  section.data(318).dtTransOffset = 1921;
	
	  ;% Mainframe_P.Gain6_Gain_j
	  section.data(319).logicalSrcIdx = 439;
	  section.data(319).dtTransOffset = 1922;
	
	  ;% Mainframe_P.Gain11_Gain_l
	  section.data(320).logicalSrcIdx = 440;
	  section.data(320).dtTransOffset = 1923;
	
	  ;% Mainframe_P.Gain12_Gain_b
	  section.data(321).logicalSrcIdx = 441;
	  section.data(321).dtTransOffset = 1924;
	
	  ;% Mainframe_P.Constant1_Value_b4
	  section.data(322).logicalSrcIdx = 442;
	  section.data(322).dtTransOffset = 1925;
	
	  ;% Mainframe_P.Saturation_UpperSat_l
	  section.data(323).logicalSrcIdx = 443;
	  section.data(323).dtTransOffset = 1926;
	
	  ;% Mainframe_P.Saturation_LowerSat_f
	  section.data(324).logicalSrcIdx = 444;
	  section.data(324).dtTransOffset = 1927;
	
	  ;% Mainframe_P.a3_Value
	  section.data(325).logicalSrcIdx = 445;
	  section.data(325).dtTransOffset = 1928;
	
	  ;% Mainframe_P.a2_Value
	  section.data(326).logicalSrcIdx = 446;
	  section.data(326).dtTransOffset = 1929;
	
	  ;% Mainframe_P.WGS84SemiminorAxism_Value
	  section.data(327).logicalSrcIdx = 447;
	  section.data(327).dtTransOffset = 1930;
	
	  ;% Mainframe_P.WGS84SemimajorAxism_Value
	  section.data(328).logicalSrcIdx = 448;
	  section.data(328).dtTransOffset = 1931;
	
	  ;% Mainframe_P.Constant_Value_kc
	  section.data(329).logicalSrcIdx = 449;
	  section.data(329).dtTransOffset = 1932;
	
	  ;% Mainframe_P.Constant1_Value_o
	  section.data(330).logicalSrcIdx = 450;
	  section.data(330).dtTransOffset = 1933;
	
	  ;% Mainframe_P.Constant_Value_bh
	  section.data(331).logicalSrcIdx = 451;
	  section.data(331).dtTransOffset = 1934;
	
	  ;% Mainframe_P.Constant2_Value_d
	  section.data(332).logicalSrcIdx = 452;
	  section.data(332).dtTransOffset = 1937;
	
	  ;% Mainframe_P.Switch1_Threshold_g
	  section.data(333).logicalSrcIdx = 453;
	  section.data(333).dtTransOffset = 1938;
	
	  ;% Mainframe_P.Constant3_Value_l
	  section.data(334).logicalSrcIdx = 454;
	  section.data(334).dtTransOffset = 1939;
	
	  ;% Mainframe_P.Switch_Threshold_o
	  section.data(335).logicalSrcIdx = 455;
	  section.data(335).dtTransOffset = 1940;
	
	  ;% Mainframe_P.Constant_Value_aw
	  section.data(336).logicalSrcIdx = 456;
	  section.data(336).dtTransOffset = 1941;
	
	  ;% Mainframe_P.Constant1_Value_m
	  section.data(337).logicalSrcIdx = 457;
	  section.data(337).dtTransOffset = 1942;
	
	  ;% Mainframe_P.Constant_Value_n
	  section.data(338).logicalSrcIdx = 458;
	  section.data(338).dtTransOffset = 1943;
	
	  ;% Mainframe_P.Switch_Threshold_op
	  section.data(339).logicalSrcIdx = 459;
	  section.data(339).dtTransOffset = 1944;
	
	  ;% Mainframe_P.Switch1_Threshold_j
	  section.data(340).logicalSrcIdx = 460;
	  section.data(340).dtTransOffset = 1945;
	
	  ;% Mainframe_P.Constant1_Value_lf
	  section.data(341).logicalSrcIdx = 461;
	  section.data(341).dtTransOffset = 1946;
	
	  ;% Mainframe_P.thrust_rot_x_Value
	  section.data(342).logicalSrcIdx = 462;
	  section.data(342).dtTransOffset = 1947;
	
	  ;% Mainframe_P.thrust_rot_y_Value
	  section.data(343).logicalSrcIdx = 463;
	  section.data(343).dtTransOffset = 1948;
	
	  ;% Mainframe_P.Thrust_rot_z_Value
	  section.data(344).logicalSrcIdx = 464;
	  section.data(344).dtTransOffset = 1949;
	
	  ;% Mainframe_P.Constant_Value_ny
	  section.data(345).logicalSrcIdx = 465;
	  section.data(345).dtTransOffset = 1950;
	
	  ;% Mainframe_P.Switch_Threshold_o3
	  section.data(346).logicalSrcIdx = 466;
	  section.data(346).dtTransOffset = 1951;
	
	  ;% Mainframe_P.Switch1_Threshold_f
	  section.data(347).logicalSrcIdx = 467;
	  section.data(347).dtTransOffset = 1952;
	
	  ;% Mainframe_P.Constant1_Value_k
	  section.data(348).logicalSrcIdx = 468;
	  section.data(348).dtTransOffset = 1953;
	
	  ;% Mainframe_P.uncert_thrust_Value
	  section.data(349).logicalSrcIdx = 469;
	  section.data(349).dtTransOffset = 1954;
	
	  ;% Mainframe_P.Switch_Threshold_om
	  section.data(350).logicalSrcIdx = 470;
	  section.data(350).dtTransOffset = 1955;
	
	  ;% Mainframe_P.Saturation_UpperSat_g
	  section.data(351).logicalSrcIdx = 471;
	  section.data(351).dtTransOffset = 1956;
	
	  ;% Mainframe_P.Saturation_LowerSat_i
	  section.data(352).logicalSrcIdx = 472;
	  section.data(352).dtTransOffset = 1957;
	
	  ;% Mainframe_P.Constant_Value_bd
	  section.data(353).logicalSrcIdx = 473;
	  section.data(353).dtTransOffset = 1958;
	
	  ;% Mainframe_P.Constant_Value_fd
	  section.data(354).logicalSrcIdx = 474;
	  section.data(354).dtTransOffset = 1959;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICX
	  section.data(355).logicalSrcIdx = 475;
	  section.data(355).dtTransOffset = 1960;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICDXDT
	  section.data(356).logicalSrcIdx = 476;
	  section.data(356).dtTransOffset = 1961;
	
	  ;% Mainframe_P.ZeroOrderHold1_Gain
	  section.data(357).logicalSrcIdx = 477;
	  section.data(357).dtTransOffset = 1962;
	
	  ;% Mainframe_P.ZeroOrderHold2_Gain
	  section.data(358).logicalSrcIdx = 478;
	  section.data(358).dtTransOffset = 1963;
	
	  ;% Mainframe_P.ZeroOrderHold_Gain
	  section.data(359).logicalSrcIdx = 479;
	  section.data(359).dtTransOffset = 1964;
	
	  ;% Mainframe_P.ZeroOrderHold4_Gain
	  section.data(360).logicalSrcIdx = 480;
	  section.data(360).dtTransOffset = 1965;
	
	  ;% Mainframe_P.Gain_Gain_aj
	  section.data(361).logicalSrcIdx = 481;
	  section.data(361).dtTransOffset = 1966;
	
	  ;% Mainframe_P.Constant15_Value
	  section.data(362).logicalSrcIdx = 482;
	  section.data(362).dtTransOffset = 1969;
	
	  ;% Mainframe_P.Constant_Value_mt
	  section.data(363).logicalSrcIdx = 483;
	  section.data(363).dtTransOffset = 1978;
	
	  ;% Mainframe_P.Constant4_Value_as
	  section.data(364).logicalSrcIdx = 484;
	  section.data(364).dtTransOffset = 1979;
	
	  ;% Mainframe_P.Constant_Value_ds
	  section.data(365).logicalSrcIdx = 485;
	  section.data(365).dtTransOffset = 1980;
	
	  ;% Mainframe_P.Constant6_Value_i
	  section.data(366).logicalSrcIdx = 486;
	  section.data(366).dtTransOffset = 1981;
	
	  ;% Mainframe_P.Constant3_Value_p
	  section.data(367).logicalSrcIdx = 487;
	  section.data(367).dtTransOffset = 1982;
	
	  ;% Mainframe_P.Constant7_Value_ei
	  section.data(368).logicalSrcIdx = 488;
	  section.data(368).dtTransOffset = 1983;
	
	  ;% Mainframe_P.Constant5_Value
	  section.data(369).logicalSrcIdx = 489;
	  section.data(369).dtTransOffset = 1984;
	
	  ;% Mainframe_P.Constant1_Value_mh
	  section.data(370).logicalSrcIdx = 490;
	  section.data(370).dtTransOffset = 1985;
	
	  ;% Mainframe_P.Constant9_Value_a
	  section.data(371).logicalSrcIdx = 491;
	  section.data(371).dtTransOffset = 1986;
	
	  ;% Mainframe_P.Constant8_Value_n
	  section.data(372).logicalSrcIdx = 492;
	  section.data(372).dtTransOffset = 1987;
	
	  ;% Mainframe_P.Constant2_Value_lc
	  section.data(373).logicalSrcIdx = 493;
	  section.data(373).dtTransOffset = 1988;
	
	  ;% Mainframe_P.Constant17_Value
	  section.data(374).logicalSrcIdx = 494;
	  section.data(374).dtTransOffset = 1989;
	
	  ;% Mainframe_P.Gain_Gain_mf
	  section.data(375).logicalSrcIdx = 495;
	  section.data(375).dtTransOffset = 1992;
	
	  ;% Mainframe_P.Gain1_Gain_o1
	  section.data(376).logicalSrcIdx = 496;
	  section.data(376).dtTransOffset = 1993;
	
	  ;% Mainframe_P.Gain3_Gain_b
	  section.data(377).logicalSrcIdx = 497;
	  section.data(377).dtTransOffset = 1994;
	
	  ;% Mainframe_P.Constant16_Value
	  section.data(378).logicalSrcIdx = 498;
	  section.data(378).dtTransOffset = 1995;
	
	  ;% Mainframe_P.Gain_Gain_mj
	  section.data(379).logicalSrcIdx = 499;
	  section.data(379).dtTransOffset = 1998;
	
	  ;% Mainframe_P.Gain1_Gain_fv
	  section.data(380).logicalSrcIdx = 500;
	  section.data(380).dtTransOffset = 1999;
	
	  ;% Mainframe_P.Gain3_Gain_bz
	  section.data(381).logicalSrcIdx = 501;
	  section.data(381).dtTransOffset = 2000;
	
	  ;% Mainframe_P.thrust_rot_x_Value_h
	  section.data(382).logicalSrcIdx = 502;
	  section.data(382).dtTransOffset = 2001;
	
	  ;% Mainframe_P.thrust_rot_y_Value_j
	  section.data(383).logicalSrcIdx = 503;
	  section.data(383).dtTransOffset = 2002;
	
	  ;% Mainframe_P.Thrust_rot_z_Value_l
	  section.data(384).logicalSrcIdx = 504;
	  section.data(384).dtTransOffset = 2003;
	
	  ;% Mainframe_P.Constant21_Value
	  section.data(385).logicalSrcIdx = 505;
	  section.data(385).dtTransOffset = 2004;
	
	  ;% Mainframe_P.Constant20_Value
	  section.data(386).logicalSrcIdx = 506;
	  section.data(386).dtTransOffset = 2013;
	
	  ;% Mainframe_P.Constant17_Value_c
	  section.data(387).logicalSrcIdx = 507;
	  section.data(387).dtTransOffset = 2014;
	
	  ;% Mainframe_P.Constant16_Value_g
	  section.data(388).logicalSrcIdx = 508;
	  section.data(388).dtTransOffset = 2023;
	
	  ;% Mainframe_P.Constant19_Value
	  section.data(389).logicalSrcIdx = 509;
	  section.data(389).dtTransOffset = 2032;
	
	  ;% Mainframe_P.Constant18_Value
	  section.data(390).logicalSrcIdx = 510;
	  section.data(390).dtTransOffset = 2033;
	
	  ;% Mainframe_P.Constant16_Value_gd
	  section.data(391).logicalSrcIdx = 511;
	  section.data(391).dtTransOffset = 2034;
	
	  ;% Mainframe_P.Constant_Value_mx
	  section.data(392).logicalSrcIdx = 512;
	  section.data(392).dtTransOffset = 2043;
	
	  ;% Mainframe_P.Gain_Gain_kk
	  section.data(393).logicalSrcIdx = 513;
	  section.data(393).dtTransOffset = 2044;
	
	  ;% Mainframe_P.Constant3_Value_pw
	  section.data(394).logicalSrcIdx = 514;
	  section.data(394).dtTransOffset = 2045;
	
	  ;% Mainframe_P.Constant_Value_bp
	  section.data(395).logicalSrcIdx = 515;
	  section.data(395).dtTransOffset = 2046;
	
	  ;% Mainframe_P.Constant1_Value_cs
	  section.data(396).logicalSrcIdx = 516;
	  section.data(396).dtTransOffset = 2047;
	
	  ;% Mainframe_P.Constant_Value_ce
	  section.data(397).logicalSrcIdx = 517;
	  section.data(397).dtTransOffset = 2048;
	
	  ;% Mainframe_P.Constant_Value_f1
	  section.data(398).logicalSrcIdx = 518;
	  section.data(398).dtTransOffset = 2049;
	
	  ;% Mainframe_P.Constant1_Value_a
	  section.data(399).logicalSrcIdx = 519;
	  section.data(399).dtTransOffset = 2050;
	
	  ;% Mainframe_P.Constant1_Value_k5
	  section.data(400).logicalSrcIdx = 520;
	  section.data(400).dtTransOffset = 2051;
	
	  ;% Mainframe_P.Constant_Value_ixx
	  section.data(401).logicalSrcIdx = 521;
	  section.data(401).dtTransOffset = 2052;
	
	  ;% Mainframe_P.Constant2_Value_je
	  section.data(402).logicalSrcIdx = 522;
	  section.data(402).dtTransOffset = 2055;
	
	  ;% Mainframe_P.Switch1_Threshold_m
	  section.data(403).logicalSrcIdx = 523;
	  section.data(403).dtTransOffset = 2056;
	
	  ;% Mainframe_P.Constant3_Value_b
	  section.data(404).logicalSrcIdx = 524;
	  section.data(404).dtTransOffset = 2057;
	
	  ;% Mainframe_P.Switch_Threshold_j
	  section.data(405).logicalSrcIdx = 525;
	  section.data(405).dtTransOffset = 2058;
	
	  ;% Mainframe_P.pNPB_Value
	  section.data(406).logicalSrcIdx = 526;
	  section.data(406).dtTransOffset = 2059;
	
	  ;% Mainframe_P.Constant9_Value_l
	  section.data(407).logicalSrcIdx = 527;
	  section.data(407).dtTransOffset = 2062;
	
	  ;% Mainframe_P.ZeroOrderHold3_Gain
	  section.data(408).logicalSrcIdx = 528;
	  section.data(408).dtTransOffset = 2071;
	
	  ;% Mainframe_P.Switch_Threshold_p
	  section.data(409).logicalSrcIdx = 529;
	  section.data(409).dtTransOffset = 2072;
	
	  ;% Mainframe_P.WhiteNoise_Mean
	  section.data(410).logicalSrcIdx = 530;
	  section.data(410).dtTransOffset = 2073;
	
	  ;% Mainframe_P.WhiteNoise_StdDev
	  section.data(411).logicalSrcIdx = 531;
	  section.data(411).dtTransOffset = 2074;
	
	  ;% Mainframe_P.Saturation_UpperSat_j
	  section.data(412).logicalSrcIdx = 532;
	  section.data(412).dtTransOffset = 2075;
	
	  ;% Mainframe_P.Saturation_LowerSat_p
	  section.data(413).logicalSrcIdx = 533;
	  section.data(413).dtTransOffset = 2078;
	
	  ;% Mainframe_P.Constant_Value_p3
	  section.data(414).logicalSrcIdx = 534;
	  section.data(414).dtTransOffset = 2081;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICX_a
	  section.data(415).logicalSrcIdx = 535;
	  section.data(415).dtTransOffset = 2082;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n
	  section.data(416).logicalSrcIdx = 536;
	  section.data(416).dtTransOffset = 2083;
	
	  ;% Mainframe_P.ZeroOrderHold_Gain_k
	  section.data(417).logicalSrcIdx = 537;
	  section.data(417).dtTransOffset = 2084;
	
	  ;% Mainframe_P.ZeroOrderHold1_Gain_k
	  section.data(418).logicalSrcIdx = 538;
	  section.data(418).dtTransOffset = 2085;
	
	  ;% Mainframe_P.Switch_Threshold_i0
	  section.data(419).logicalSrcIdx = 539;
	  section.data(419).dtTransOffset = 2086;
	
	  ;% Mainframe_P.WhiteNoise_Mean_i
	  section.data(420).logicalSrcIdx = 540;
	  section.data(420).dtTransOffset = 2087;
	
	  ;% Mainframe_P.WhiteNoise_StdDev_f
	  section.data(421).logicalSrcIdx = 541;
	  section.data(421).dtTransOffset = 2088;
	
	  ;% Mainframe_P.Saturation_UpperSat_pp
	  section.data(422).logicalSrcIdx = 542;
	  section.data(422).dtTransOffset = 2089;
	
	  ;% Mainframe_P.Saturation_LowerSat_ga
	  section.data(423).logicalSrcIdx = 543;
	  section.data(423).dtTransOffset = 2092;
	
	  ;% Mainframe_P.Constant_Value_id
	  section.data(424).logicalSrcIdx = 544;
	  section.data(424).dtTransOffset = 2095;
	
	  ;% Mainframe_P.Gain_Gain_cv
	  section.data(425).logicalSrcIdx = 545;
	  section.data(425).dtTransOffset = 2096;
	
	  ;% Mainframe_P.Gain_Gain_e
	  section.data(426).logicalSrcIdx = 546;
	  section.data(426).dtTransOffset = 2097;
	
	  ;% Mainframe_P.Gain_Gain_ga
	  section.data(427).logicalSrcIdx = 547;
	  section.data(427).dtTransOffset = 2098;
	
	  ;% Mainframe_P.Gain_Gain_gh
	  section.data(428).logicalSrcIdx = 548;
	  section.data(428).dtTransOffset = 2099;
	
	  ;% Mainframe_P.Q_1_Value_k
	  section.data(429).logicalSrcIdx = 549;
	  section.data(429).dtTransOffset = 2100;
	
	  ;% Mainframe_P.Q_2_Value_a
	  section.data(430).logicalSrcIdx = 550;
	  section.data(430).dtTransOffset = 2116;
	
	  ;% Mainframe_P.Q_3_Value_d
	  section.data(431).logicalSrcIdx = 551;
	  section.data(431).dtTransOffset = 2132;
	
	  ;% Mainframe_P.Q_4_Value_l
	  section.data(432).logicalSrcIdx = 552;
	  section.data(432).dtTransOffset = 2148;
	
	  ;% Mainframe_P.Constant_Value_h4
	  section.data(433).logicalSrcIdx = 553;
	  section.data(433).dtTransOffset = 2164;
	
	  ;% Mainframe_P.Constant1_Value_ac
	  section.data(434).logicalSrcIdx = 554;
	  section.data(434).dtTransOffset = 2165;
	
	  ;% Mainframe_P.Switch_Threshold_pk
	  section.data(435).logicalSrcIdx = 555;
	  section.data(435).dtTransOffset = 2166;
	
	  ;% Mainframe_P.Gain1_Gain_be
	  section.data(436).logicalSrcIdx = 556;
	  section.data(436).dtTransOffset = 2167;
	
	  ;% Mainframe_P.Gain2_Gain_hx
	  section.data(437).logicalSrcIdx = 557;
	  section.data(437).dtTransOffset = 2168;
	
	  ;% Mainframe_P.Gain3_Gain_e
	  section.data(438).logicalSrcIdx = 558;
	  section.data(438).dtTransOffset = 2169;
	
	  ;% Mainframe_P.Gain4_Gain_kv
	  section.data(439).logicalSrcIdx = 559;
	  section.data(439).dtTransOffset = 2170;
	
	  ;% Mainframe_P.Gain5_Gain_ak
	  section.data(440).logicalSrcIdx = 560;
	  section.data(440).dtTransOffset = 2171;
	
	  ;% Mainframe_P.Gain6_Gain_g
	  section.data(441).logicalSrcIdx = 561;
	  section.data(441).dtTransOffset = 2172;
	
	  ;% Mainframe_P.Gain7_Gain_f
	  section.data(442).logicalSrcIdx = 562;
	  section.data(442).dtTransOffset = 2173;
	
	  ;% Mainframe_P.Gain8_Gain_o2
	  section.data(443).logicalSrcIdx = 563;
	  section.data(443).dtTransOffset = 2174;
	
	  ;% Mainframe_P.Gain9_Gain_l
	  section.data(444).logicalSrcIdx = 564;
	  section.data(444).dtTransOffset = 2175;
	
	  ;% Mainframe_P.Gain10_Gain_m
	  section.data(445).logicalSrcIdx = 565;
	  section.data(445).dtTransOffset = 2176;
	
	  ;% Mainframe_P.Gain11_Gain_b
	  section.data(446).logicalSrcIdx = 566;
	  section.data(446).dtTransOffset = 2177;
	
	  ;% Mainframe_P.Gain12_Gain_f
	  section.data(447).logicalSrcIdx = 567;
	  section.data(447).dtTransOffset = 2178;
	
	  ;% Mainframe_P.Gain_Gain_ce
	  section.data(448).logicalSrcIdx = 568;
	  section.data(448).dtTransOffset = 2179;
	
	  ;% Mainframe_P.Q_1_Value_a
	  section.data(449).logicalSrcIdx = 569;
	  section.data(449).dtTransOffset = 2180;
	
	  ;% Mainframe_P.Constant8_Value_km
	  section.data(450).logicalSrcIdx = 570;
	  section.data(450).dtTransOffset = 2196;
	
	  ;% Mainframe_P.Q_2_Value_p
	  section.data(451).logicalSrcIdx = 571;
	  section.data(451).dtTransOffset = 2197;
	
	  ;% Mainframe_P.Q_3_Value_f
	  section.data(452).logicalSrcIdx = 572;
	  section.data(452).dtTransOffset = 2213;
	
	  ;% Mainframe_P.Q_4_Value_p
	  section.data(453).logicalSrcIdx = 573;
	  section.data(453).dtTransOffset = 2229;
	
	  ;% Mainframe_P.Gain1_Gain_k1
	  section.data(454).logicalSrcIdx = 574;
	  section.data(454).dtTransOffset = 2245;
	
	  ;% Mainframe_P.Gain_Gain_f
	  section.data(455).logicalSrcIdx = 575;
	  section.data(455).dtTransOffset = 2246;
	
	  ;% Mainframe_P.Gain1_Gain_nr
	  section.data(456).logicalSrcIdx = 576;
	  section.data(456).dtTransOffset = 2247;
	
	  ;% Mainframe_P.Constant8_Value_k2
	  section.data(457).logicalSrcIdx = 577;
	  section.data(457).dtTransOffset = 2248;
	
	  ;% Mainframe_P.Constant9_Value_m
	  section.data(458).logicalSrcIdx = 578;
	  section.data(458).dtTransOffset = 2249;
	
	  ;% Mainframe_P.Switch_Threshold_m
	  section.data(459).logicalSrcIdx = 579;
	  section.data(459).dtTransOffset = 2250;
	
	  ;% Mainframe_P.Gain1_Gain_ge
	  section.data(460).logicalSrcIdx = 580;
	  section.data(460).dtTransOffset = 2251;
	
	  ;% Mainframe_P.Q_1_Value_o
	  section.data(461).logicalSrcIdx = 581;
	  section.data(461).dtTransOffset = 2252;
	
	  ;% Mainframe_P.Constant8_Value_kt
	  section.data(462).logicalSrcIdx = 582;
	  section.data(462).dtTransOffset = 2268;
	
	  ;% Mainframe_P.Q_2_Value_ca
	  section.data(463).logicalSrcIdx = 583;
	  section.data(463).dtTransOffset = 2269;
	
	  ;% Mainframe_P.Q_3_Value_g
	  section.data(464).logicalSrcIdx = 584;
	  section.data(464).dtTransOffset = 2285;
	
	  ;% Mainframe_P.Q_4_Value_po
	  section.data(465).logicalSrcIdx = 585;
	  section.data(465).dtTransOffset = 2301;
	
	  ;% Mainframe_P.Gain1_Gain_p
	  section.data(466).logicalSrcIdx = 586;
	  section.data(466).dtTransOffset = 2317;
	
	  ;% Mainframe_P.Gain_Gain_j
	  section.data(467).logicalSrcIdx = 587;
	  section.data(467).dtTransOffset = 2318;
	
	  ;% Mainframe_P.Gain1_Gain_e
	  section.data(468).logicalSrcIdx = 588;
	  section.data(468).dtTransOffset = 2319;
	
	  ;% Mainframe_P.Gain1_Gain_cc
	  section.data(469).logicalSrcIdx = 589;
	  section.data(469).dtTransOffset = 2320;
	
	  ;% Mainframe_P.Gain2_Gain_ev
	  section.data(470).logicalSrcIdx = 590;
	  section.data(470).dtTransOffset = 2321;
	
	  ;% Mainframe_P.Gain3_Gain_h
	  section.data(471).logicalSrcIdx = 591;
	  section.data(471).dtTransOffset = 2322;
	
	  ;% Mainframe_P.Gain4_Gain_p
	  section.data(472).logicalSrcIdx = 592;
	  section.data(472).dtTransOffset = 2323;
	
	  ;% Mainframe_P.Gain5_Gain_a1
	  section.data(473).logicalSrcIdx = 593;
	  section.data(473).dtTransOffset = 2324;
	
	  ;% Mainframe_P.Gain6_Gain_f
	  section.data(474).logicalSrcIdx = 594;
	  section.data(474).dtTransOffset = 2325;
	
	  ;% Mainframe_P.Gain7_Gain_o
	  section.data(475).logicalSrcIdx = 595;
	  section.data(475).dtTransOffset = 2326;
	
	  ;% Mainframe_P.Gain8_Gain_m
	  section.data(476).logicalSrcIdx = 596;
	  section.data(476).dtTransOffset = 2327;
	
	  ;% Mainframe_P.Gain9_Gain_fx
	  section.data(477).logicalSrcIdx = 597;
	  section.data(477).dtTransOffset = 2328;
	
	  ;% Mainframe_P.Gain10_Gain_l
	  section.data(478).logicalSrcIdx = 598;
	  section.data(478).dtTransOffset = 2329;
	
	  ;% Mainframe_P.Gain11_Gain_ky
	  section.data(479).logicalSrcIdx = 599;
	  section.data(479).dtTransOffset = 2330;
	
	  ;% Mainframe_P.Gain12_Gain_bf
	  section.data(480).logicalSrcIdx = 600;
	  section.data(480).dtTransOffset = 2331;
	
	  ;% Mainframe_P.Constant_Value_dg
	  section.data(481).logicalSrcIdx = 601;
	  section.data(481).dtTransOffset = 2332;
	
	  ;% Mainframe_P.Constant1_Value_gx
	  section.data(482).logicalSrcIdx = 602;
	  section.data(482).dtTransOffset = 2333;
	
	  ;% Mainframe_P.Merge_InitialOutput
	  section.data(483).logicalSrcIdx = 603;
	  section.data(483).dtTransOffset = 2334;
	
	  ;% Mainframe_P.Switch_Threshold_h
	  section.data(484).logicalSrcIdx = 604;
	  section.data(484).dtTransOffset = 2335;
	
	  ;% Mainframe_P.Constant_Value_fq
	  section.data(485).logicalSrcIdx = 605;
	  section.data(485).dtTransOffset = 2336;
	
	  ;% Mainframe_P.Constant1_Value_pl
	  section.data(486).logicalSrcIdx = 606;
	  section.data(486).dtTransOffset = 2337;
	
	  ;% Mainframe_P.Gain_Gain_p0
	  section.data(487).logicalSrcIdx = 607;
	  section.data(487).dtTransOffset = 2338;
	
	  ;% Mainframe_P.Saturation_UpperSat_gn
	  section.data(488).logicalSrcIdx = 608;
	  section.data(488).dtTransOffset = 2339;
	
	  ;% Mainframe_P.Saturation_LowerSat_n
	  section.data(489).logicalSrcIdx = 609;
	  section.data(489).dtTransOffset = 2340;
	
	  ;% Mainframe_P.Constant_Value_ly
	  section.data(490).logicalSrcIdx = 610;
	  section.data(490).dtTransOffset = 2341;
	
	  ;% Mainframe_P.Constant1_Value_py
	  section.data(491).logicalSrcIdx = 611;
	  section.data(491).dtTransOffset = 2342;
	
	  ;% Mainframe_P.Gain_Gain_jr
	  section.data(492).logicalSrcIdx = 612;
	  section.data(492).dtTransOffset = 2343;
	
	  ;% Mainframe_P.Saturation_UpperSat_db
	  section.data(493).logicalSrcIdx = 613;
	  section.data(493).dtTransOffset = 2344;
	
	  ;% Mainframe_P.Saturation_LowerSat_k
	  section.data(494).logicalSrcIdx = 614;
	  section.data(494).dtTransOffset = 2345;
	
	  ;% Mainframe_P.Q_1_Value_ab
	  section.data(495).logicalSrcIdx = 615;
	  section.data(495).dtTransOffset = 2346;
	
	  ;% Mainframe_P.Constant_Value_cu
	  section.data(496).logicalSrcIdx = 616;
	  section.data(496).dtTransOffset = 2362;
	
	  ;% Mainframe_P.Q_2_Value_m
	  section.data(497).logicalSrcIdx = 617;
	  section.data(497).dtTransOffset = 2363;
	
	  ;% Mainframe_P.Q_3_Value_c1
	  section.data(498).logicalSrcIdx = 618;
	  section.data(498).dtTransOffset = 2379;
	
	  ;% Mainframe_P.Q_4_Value_gi
	  section.data(499).logicalSrcIdx = 619;
	  section.data(499).dtTransOffset = 2395;
	
	  ;% Mainframe_P.Gain1_Gain_gee
	  section.data(500).logicalSrcIdx = 620;
	  section.data(500).dtTransOffset = 2411;
	
	  ;% Mainframe_P.Gain_Gain_bs
	  section.data(501).logicalSrcIdx = 621;
	  section.data(501).dtTransOffset = 2412;
	
	  ;% Mainframe_P.Gain1_Gain_nw
	  section.data(502).logicalSrcIdx = 622;
	  section.data(502).dtTransOffset = 2413;
	
	  ;% Mainframe_P.TransferFcn1_A
	  section.data(503).logicalSrcIdx = 623;
	  section.data(503).dtTransOffset = 2414;
	
	  ;% Mainframe_P.TransferFcn1_C
	  section.data(504).logicalSrcIdx = 624;
	  section.data(504).dtTransOffset = 2416;
	
	  ;% Mainframe_P.Gain_Gain_c5
	  section.data(505).logicalSrcIdx = 625;
	  section.data(505).dtTransOffset = 2418;
	
	  ;% Mainframe_P.TransferFcn2_A
	  section.data(506).logicalSrcIdx = 626;
	  section.data(506).dtTransOffset = 2419;
	
	  ;% Mainframe_P.TransferFcn2_C
	  section.data(507).logicalSrcIdx = 627;
	  section.data(507).dtTransOffset = 2421;
	
	  ;% Mainframe_P.Gain1_Gain_bb
	  section.data(508).logicalSrcIdx = 628;
	  section.data(508).dtTransOffset = 2423;
	
	  ;% Mainframe_P.TransferFcn3_A
	  section.data(509).logicalSrcIdx = 629;
	  section.data(509).dtTransOffset = 2424;
	
	  ;% Mainframe_P.TransferFcn3_C
	  section.data(510).logicalSrcIdx = 630;
	  section.data(510).dtTransOffset = 2426;
	
	  ;% Mainframe_P.Gain2_Gain_p
	  section.data(511).logicalSrcIdx = 631;
	  section.data(511).dtTransOffset = 2428;
	
	  ;% Mainframe_P.TransferFcn4_A
	  section.data(512).logicalSrcIdx = 632;
	  section.data(512).dtTransOffset = 2429;
	
	  ;% Mainframe_P.TransferFcn4_C
	  section.data(513).logicalSrcIdx = 633;
	  section.data(513).dtTransOffset = 2431;
	
	  ;% Mainframe_P.Gain3_Gain_l0
	  section.data(514).logicalSrcIdx = 634;
	  section.data(514).dtTransOffset = 2433;
	
	  ;% Mainframe_P.Constant7_Value_ej
	  section.data(515).logicalSrcIdx = 635;
	  section.data(515).dtTransOffset = 2434;
	
	  ;% Mainframe_P.Constant1_Value_l2
	  section.data(516).logicalSrcIdx = 636;
	  section.data(516).dtTransOffset = 2446;
	
	  ;% Mainframe_P.Gain1_Gain_m2
	  section.data(517).logicalSrcIdx = 637;
	  section.data(517).dtTransOffset = 2447;
	
	  ;% Mainframe_P.Constant2_Value_e
	  section.data(518).logicalSrcIdx = 638;
	  section.data(518).dtTransOffset = 2448;
	
	  ;% Mainframe_P.Gain1_Gain_ove
	  section.data(519).logicalSrcIdx = 639;
	  section.data(519).dtTransOffset = 2449;
	
	  ;% Mainframe_P.Constant3_Value_m
	  section.data(520).logicalSrcIdx = 640;
	  section.data(520).dtTransOffset = 2450;
	
	  ;% Mainframe_P.Gain1_Gain_gj
	  section.data(521).logicalSrcIdx = 641;
	  section.data(521).dtTransOffset = 2451;
	
	  ;% Mainframe_P.Constant6_Value_c
	  section.data(522).logicalSrcIdx = 642;
	  section.data(522).dtTransOffset = 2452;
	
	  ;% Mainframe_P.deviation_Tmp_Value
	  section.data(523).logicalSrcIdx = 643;
	  section.data(523).dtTransOffset = 2453;
	
	  ;% Mainframe_P.deviation_pa_QFH_Value
	  section.data(524).logicalSrcIdx = 644;
	  section.data(524).dtTransOffset = 2454;
	
	  ;% Mainframe_P.Gain_Gain_nd
	  section.data(525).logicalSrcIdx = 645;
	  section.data(525).dtTransOffset = 2455;
	
	  ;% Mainframe_P.Gain_Gain_bk
	  section.data(526).logicalSrcIdx = 646;
	  section.data(526).dtTransOffset = 2456;
	
	  ;% Mainframe_P.Gain_Gain_ju
	  section.data(527).logicalSrcIdx = 647;
	  section.data(527).dtTransOffset = 2457;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator1_gainval
	  section.data(528).logicalSrcIdx = 648;
	  section.data(528).dtTransOffset = 2458;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator1_IC
	  section.data(529).logicalSrcIdx = 649;
	  section.data(529).dtTransOffset = 2459;
	
	  ;% Mainframe_P.Gain_Gain_gj
	  section.data(530).logicalSrcIdx = 650;
	  section.data(530).dtTransOffset = 2460;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator_gainval
	  section.data(531).logicalSrcIdx = 651;
	  section.data(531).dtTransOffset = 2461;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator_IC
	  section.data(532).logicalSrcIdx = 652;
	  section.data(532).dtTransOffset = 2462;
	
	  ;% Mainframe_P.Gain_Gain_of
	  section.data(533).logicalSrcIdx = 653;
	  section.data(533).dtTransOffset = 2463;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator2_gainval
	  section.data(534).logicalSrcIdx = 654;
	  section.data(534).dtTransOffset = 2464;
	
	  ;% Mainframe_P.DiscreteTimeIntegrator2_IC
	  section.data(535).logicalSrcIdx = 655;
	  section.data(535).dtTransOffset = 2465;
	
	  ;% Mainframe_P.Gain_Gain_e2
	  section.data(536).logicalSrcIdx = 656;
	  section.data(536).dtTransOffset = 2466;
	
	  ;% Mainframe_P.Zero1_Value
	  section.data(537).logicalSrcIdx = 657;
	  section.data(537).dtTransOffset = 2467;
	
	  ;% Mainframe_P.Gain_Gain_dy
	  section.data(538).logicalSrcIdx = 658;
	  section.data(538).dtTransOffset = 2468;
	
	  ;% Mainframe_P.Zero_Value
	  section.data(539).logicalSrcIdx = 659;
	  section.data(539).dtTransOffset = 2469;
	
	  ;% Mainframe_P.Gain_Gain_ag
	  section.data(540).logicalSrcIdx = 660;
	  section.data(540).dtTransOffset = 2470;
	
	  ;% Mainframe_P.Zero2_Value
	  section.data(541).logicalSrcIdx = 661;
	  section.data(541).dtTransOffset = 2471;
	
	  ;% Mainframe_P.Gain_Gain_b4
	  section.data(542).logicalSrcIdx = 662;
	  section.data(542).dtTransOffset = 2472;
	
	  ;% Mainframe_P.Gain_Gain_abz
	  section.data(543).logicalSrcIdx = 663;
	  section.data(543).dtTransOffset = 2473;
	
	  ;% Mainframe_P.Gain_Gain_j1
	  section.data(544).logicalSrcIdx = 664;
	  section.data(544).dtTransOffset = 2474;
	
	  ;% Mainframe_P.Gain_Gain_ho
	  section.data(545).logicalSrcIdx = 665;
	  section.data(545).dtTransOffset = 2475;
	
	  ;% Mainframe_P.Gain_Gain_pm
	  section.data(546).logicalSrcIdx = 666;
	  section.data(546).dtTransOffset = 2476;
	
	  ;% Mainframe_P.Gain_Gain_fd
	  section.data(547).logicalSrcIdx = 667;
	  section.data(547).dtTransOffset = 2477;
	
	  ;% Mainframe_P.Gain_Gain_me
	  section.data(548).logicalSrcIdx = 668;
	  section.data(548).dtTransOffset = 2478;
	
	  ;% Mainframe_P.Gain_Gain_iq
	  section.data(549).logicalSrcIdx = 669;
	  section.data(549).dtTransOffset = 2479;
	
	  ;% Mainframe_P.Gain_Gain_pzg
	  section.data(550).logicalSrcIdx = 670;
	  section.data(550).dtTransOffset = 2480;
	
	  ;% Mainframe_P.Gain_Gain_n4
	  section.data(551).logicalSrcIdx = 671;
	  section.data(551).dtTransOffset = 2481;
	
	  ;% Mainframe_P.Integrator_IC
	  section.data(552).logicalSrcIdx = 672;
	  section.data(552).dtTransOffset = 2482;
	
	  ;% Mainframe_P.Zero1_Value_d
	  section.data(553).logicalSrcIdx = 673;
	  section.data(553).dtTransOffset = 2483;
	
	  ;% Mainframe_P.Zero2_Value_k
	  section.data(554).logicalSrcIdx = 674;
	  section.data(554).dtTransOffset = 2484;
	
	  ;% Mainframe_P.Zero6_Value
	  section.data(555).logicalSrcIdx = 675;
	  section.data(555).dtTransOffset = 2485;
	
	  ;% Mainframe_P.Zero5_Value
	  section.data(556).logicalSrcIdx = 676;
	  section.data(556).dtTransOffset = 2486;
	
	  ;% Mainframe_P.Zero4_Value
	  section.data(557).logicalSrcIdx = 677;
	  section.data(557).dtTransOffset = 2487;
	
	  ;% Mainframe_P.Zero3_Value
	  section.data(558).logicalSrcIdx = 678;
	  section.data(558).dtTransOffset = 2488;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICX_l
	  section.data(559).logicalSrcIdx = 679;
	  section.data(559).dtTransOffset = 2489;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b
	  section.data(560).logicalSrcIdx = 680;
	  section.data(560).dtTransOffset = 2490;
	
	  ;% Mainframe_P.Constant_Value_p3p
	  section.data(561).logicalSrcIdx = 681;
	  section.data(561).dtTransOffset = 2491;
	
	  ;% Mainframe_P.ZeroOrderHold1_Gain_b
	  section.data(562).logicalSrcIdx = 682;
	  section.data(562).dtTransOffset = 2492;
	
	  ;% Mainframe_P.Multiply2_Gain_g
	  section.data(563).logicalSrcIdx = 683;
	  section.data(563).dtTransOffset = 2493;
	
	  ;% Mainframe_P.Multiply_Gain_d
	  section.data(564).logicalSrcIdx = 684;
	  section.data(564).dtTransOffset = 2494;
	
	  ;% Mainframe_P.Multiply1_Gain_n
	  section.data(565).logicalSrcIdx = 685;
	  section.data(565).dtTransOffset = 2495;
	
	  ;% Mainframe_P.ZeroOrderHold2_Gain_l
	  section.data(566).logicalSrcIdx = 686;
	  section.data(566).dtTransOffset = 2496;
	
	  ;% Mainframe_P.ZeroOrderHold_Gain_a
	  section.data(567).logicalSrcIdx = 687;
	  section.data(567).dtTransOffset = 2497;
	
	  ;% Mainframe_P.Constant1_Value_plv
	  section.data(568).logicalSrcIdx = 688;
	  section.data(568).dtTransOffset = 2498;
	
	  ;% Mainframe_P.ZeroOrderHold4_Gain_o
	  section.data(569).logicalSrcIdx = 689;
	  section.data(569).dtTransOffset = 2501;
	
	  ;% Mainframe_P.Gain_Gain_en
	  section.data(570).logicalSrcIdx = 690;
	  section.data(570).dtTransOffset = 2502;
	
	  ;% Mainframe_P.ZeroOrderHold3_Gain_d
	  section.data(571).logicalSrcIdx = 691;
	  section.data(571).dtTransOffset = 2505;
	
	  ;% Mainframe_P.Switch_Threshold_k
	  section.data(572).logicalSrcIdx = 692;
	  section.data(572).dtTransOffset = 2506;
	
	  ;% Mainframe_P.WhiteNoise_Mean_o
	  section.data(573).logicalSrcIdx = 693;
	  section.data(573).dtTransOffset = 2507;
	
	  ;% Mainframe_P.WhiteNoise_StdDev_l
	  section.data(574).logicalSrcIdx = 694;
	  section.data(574).dtTransOffset = 2508;
	
	  ;% Mainframe_P.Saturation_UpperSat_m
	  section.data(575).logicalSrcIdx = 695;
	  section.data(575).dtTransOffset = 2509;
	
	  ;% Mainframe_P.Saturation_LowerSat_e1
	  section.data(576).logicalSrcIdx = 696;
	  section.data(576).dtTransOffset = 2512;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICX_h
	  section.data(577).logicalSrcIdx = 697;
	  section.data(577).dtTransOffset = 2515;
	
	  ;% Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d
	  section.data(578).logicalSrcIdx = 698;
	  section.data(578).dtTransOffset = 2516;
	
	  ;% Mainframe_P.Constant_Value_jy
	  section.data(579).logicalSrcIdx = 699;
	  section.data(579).dtTransOffset = 2517;
	
	  ;% Mainframe_P.ZeroOrderHold_Gain_i
	  section.data(580).logicalSrcIdx = 700;
	  section.data(580).dtTransOffset = 2518;
	
	  ;% Mainframe_P.ZeroOrderHold1_Gain_be
	  section.data(581).logicalSrcIdx = 701;
	  section.data(581).dtTransOffset = 2519;
	
	  ;% Mainframe_P.Switch_Threshold_c
	  section.data(582).logicalSrcIdx = 702;
	  section.data(582).dtTransOffset = 2520;
	
	  ;% Mainframe_P.WhiteNoise_Mean_k
	  section.data(583).logicalSrcIdx = 703;
	  section.data(583).dtTransOffset = 2521;
	
	  ;% Mainframe_P.WhiteNoise_StdDev_fq
	  section.data(584).logicalSrcIdx = 704;
	  section.data(584).dtTransOffset = 2522;
	
	  ;% Mainframe_P.Saturation_UpperSat_jb
	  section.data(585).logicalSrcIdx = 705;
	  section.data(585).dtTransOffset = 2523;
	
	  ;% Mainframe_P.Saturation_LowerSat_h
	  section.data(586).logicalSrcIdx = 706;
	  section.data(586).dtTransOffset = 2526;
	
	  ;% Mainframe_P.Zero_Value_d
	  section.data(587).logicalSrcIdx = 707;
	  section.data(587).dtTransOffset = 2529;
	
	  ;% Mainframe_P.One_Value
	  section.data(588).logicalSrcIdx = 708;
	  section.data(588).dtTransOffset = 2530;
	
	  ;% Mainframe_P.Saturation_UpperSat_a
	  section.data(589).logicalSrcIdx = 709;
	  section.data(589).dtTransOffset = 2531;
	
	  ;% Mainframe_P.Saturation_LowerSat_gt
	  section.data(590).logicalSrcIdx = 710;
	  section.data(590).dtTransOffset = 2532;
	
	  ;% Mainframe_P.course_angle_wind_Value
	  section.data(591).logicalSrcIdx = 711;
	  section.data(591).dtTransOffset = 2533;
	
	  ;% Mainframe_P.course_angle_uncertainty_Value
	  section.data(592).logicalSrcIdx = 712;
	  section.data(592).dtTransOffset = 2534;
	
	  ;% Mainframe_P.vWW_uncertainty_Value
	  section.data(593).logicalSrcIdx = 713;
	  section.data(593).dtTransOffset = 2535;
	
	  ;% Mainframe_P.vWW_Value
	  section.data(594).logicalSrcIdx = 714;
	  section.data(594).dtTransOffset = 2536;
	
	  ;% Mainframe_P.Constant1_Value_m5
	  section.data(595).logicalSrcIdx = 715;
	  section.data(595).dtTransOffset = 2537;
	
	  ;% Mainframe_P.Constant_Value_gk
	  section.data(596).logicalSrcIdx = 716;
	  section.data(596).dtTransOffset = 2538;
	
	  ;% Mainframe_P.Constant1_Value_co
	  section.data(597).logicalSrcIdx = 717;
	  section.data(597).dtTransOffset = 2539;
	
	  ;% Mainframe_P.Constant2_Value_eo
	  section.data(598).logicalSrcIdx = 718;
	  section.data(598).dtTransOffset = 2540;
	
	  ;% Mainframe_P.Constant8_Value_c2
	  section.data(599).logicalSrcIdx = 719;
	  section.data(599).dtTransOffset = 2541;
	
	  ;% Mainframe_P.Gain_Gain_go
	  section.data(600).logicalSrcIdx = 720;
	  section.data(600).dtTransOffset = 2542;
	
	  ;% Mainframe_P.Constant7_Value_gp
	  section.data(601).logicalSrcIdx = 721;
	  section.data(601).dtTransOffset = 2543;
	
	  ;% Mainframe_P.Constant8_Value_j0
	  section.data(602).logicalSrcIdx = 722;
	  section.data(602).dtTransOffset = 2544;
	
	  ;% Mainframe_P.Constant_Value_gx
	  section.data(603).logicalSrcIdx = 723;
	  section.data(603).dtTransOffset = 2545;
	
	  ;% Mainframe_P.Constant1_Value_hw
	  section.data(604).logicalSrcIdx = 724;
	  section.data(604).dtTransOffset = 2546;
	
	  ;% Mainframe_P.Constant2_Value_lq
	  section.data(605).logicalSrcIdx = 725;
	  section.data(605).dtTransOffset = 2547;
	
	  ;% Mainframe_P.Gain1_Gain_bg
	  section.data(606).logicalSrcIdx = 726;
	  section.data(606).dtTransOffset = 2548;
	
	  ;% Mainframe_P.Constant7_Value_bf
	  section.data(607).logicalSrcIdx = 727;
	  section.data(607).dtTransOffset = 2549;
	
	  ;% Mainframe_P.Gain_Gain_j0
	  section.data(608).logicalSrcIdx = 728;
	  section.data(608).dtTransOffset = 2550;
	
	  ;% Mainframe_P.Constant8_Value_lk
	  section.data(609).logicalSrcIdx = 729;
	  section.data(609).dtTransOffset = 2551;
	
	  ;% Mainframe_P.Constant7_Value_p
	  section.data(610).logicalSrcIdx = 730;
	  section.data(610).dtTransOffset = 2552;
	
	  ;% Mainframe_P.Constant4_Value_e
	  section.data(611).logicalSrcIdx = 731;
	  section.data(611).dtTransOffset = 2553;
	
	  ;% Mainframe_P.Constant10_Value_b
	  section.data(612).logicalSrcIdx = 732;
	  section.data(612).dtTransOffset = 2554;
	
	  ;% Mainframe_P.Constant11_Value_ll
	  section.data(613).logicalSrcIdx = 733;
	  section.data(613).dtTransOffset = 2555;
	
	  ;% Mainframe_P.Gain_Gain_nf
	  section.data(614).logicalSrcIdx = 734;
	  section.data(614).dtTransOffset = 2556;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.Zero_Value_i
	  section.data(1).logicalSrcIdx = 735;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Mainframe_P.Constant_Value_hg
	  section.data(1).logicalSrcIdx = 736;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_P.Output_InitialCondition
	  section.data(2).logicalSrcIdx = 737;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_P.FixPtConstant_Value
	  section.data(3).logicalSrcIdx = 738;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.One_Value_j
	  section.data(1).logicalSrcIdx = 739;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 740;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.EnabledSubsystem1_h.CalibrationTime_Y0
	  section.data(1).logicalSrcIdx = 741;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_P.EnabledSubsystem1.CalibrationTime_Y0
	  section.data(1).logicalSrcIdx = 742;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
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
    nTotSects     = 15;
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
    ;% Auto data (Mainframe_B)
    ;%
      section.nData     = 126;
      section.data(126)  = dumData; %prealloc
      
	  ;% Mainframe_B.Fin_1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_B.Fin_2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_B.Fin_3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_B.Fin_4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_B.siB_cmd
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_B.Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Mainframe_B.Gain_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% Mainframe_B.Gain_n
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Mainframe_B.Gain_p
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Mainframe_B.Gain_b
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Mainframe_B.Gain_i
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% Mainframe_B.gimbalPhi
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% Mainframe_B.Gain_br
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% Mainframe_B.gimbalTheta
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% Mainframe_B.Gain_e
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% Mainframe_B.gimbalPsi
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% Mainframe_B.Gain_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% Mainframe_B.Fin_1_Cmd_rad
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% Mainframe_B.Gain_h
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% Mainframe_B.Fin_2_Cmd_rad
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% Mainframe_B.Gain_a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% Mainframe_B.Fin_3_Cmd_rad
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% Mainframe_B.Gain_k
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% Mainframe_B.Fin_4_Cmd_rad
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% Mainframe_B.Gain_d
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% Mainframe_B.Gain_j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% Mainframe_B.Gain_kd
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% Mainframe_B.Gain_oi
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% Mainframe_B.Gain_is
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% Mainframe_B.Gain_m
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% Mainframe_B.Integrator
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% Mainframe_B.p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% Mainframe_B.q
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% Mainframe_B.r
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% Mainframe_B.phi
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% Mainframe_B.theta
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% Mainframe_B.psi
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% Mainframe_B.Gain_l
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% Mainframe_B.Product
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 43;
	
	  ;% Mainframe_B.Saturation
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 46;
	
	  ;% Mainframe_B.Product_i
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 49;
	
	  ;% Mainframe_B.Saturation_g
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 52;
	
	  ;% Mainframe_B.gyroX
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 55;
	
	  ;% Mainframe_B.gyroY
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 56;
	
	  ;% Mainframe_B.gyroZ
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 57;
	
	  ;% Mainframe_B.u
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 58;
	
	  ;% Mainframe_B.v
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 59;
	
	  ;% Mainframe_B.w
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 60;
	
	  ;% Mainframe_B.x
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 61;
	
	  ;% Mainframe_B.y
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 62;
	
	  ;% Mainframe_B.z
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 63;
	
	  ;% Mainframe_B.p_a
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 64;
	
	  ;% Mainframe_B.q_l
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 65;
	
	  ;% Mainframe_B.r_h
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 66;
	
	  ;% Mainframe_B.SquareRoot1
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 67;
	
	  ;% Mainframe_B.Sum
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 68;
	
	  ;% Mainframe_B.Sum_g
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 69;
	
	  ;% Mainframe_B.phicmdrad
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 70;
	
	  ;% Mainframe_B.phicmdrad_m
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 71;
	
	  ;% Mainframe_B.Sum2
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 72;
	
	  ;% Mainframe_B.Sum2_k
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 75;
	
	  ;% Mainframe_B.debug
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 78;
	
	  ;% Mainframe_B.FccDelay
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 79;
	
	  ;% Mainframe_B.Gain_fp
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 80;
	
	  ;% Mainframe_B.Constant
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 81;
	
	  ;% Mainframe_B.x_d
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 94;
	
	  ;% Mainframe_B.ComplextoRealImag
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 107;
	
	  ;% Mainframe_B.q0
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 110;
	
	  ;% Mainframe_B.q1
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 111;
	
	  ;% Mainframe_B.q2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 112;
	
	  ;% Mainframe_B.q3
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 113;
	
	  ;% Mainframe_B.Constant8
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 114;
	
	  ;% Mainframe_B.wIEE
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 118;
	
	  ;% Mainframe_B.sat
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 121;
	
	  ;% Mainframe_B.Gain3
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 122;
	
	  ;% Mainframe_B.sat_d
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 123;
	
	  ;% Mainframe_B.Gain3_g
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 124;
	
	  ;% Mainframe_B.sat_a
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 125;
	
	  ;% Mainframe_B.Gain3_o
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 126;
	
	  ;% Mainframe_B.sat_p
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 127;
	
	  ;% Mainframe_B.Gain3_i
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 128;
	
	  ;% Mainframe_B.Tmp_ref
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 129;
	
	  ;% Mainframe_B.Product_n
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 130;
	
	  ;% Mainframe_B.Divide
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 131;
	
	  ;% Mainframe_B.Subtract1
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 132;
	
	  ;% Mainframe_B.Subtract
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 133;
	
	  ;% Mainframe_B.Switch
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 134;
	
	  ;% Mainframe_B.pa_ref
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 137;
	
	  ;% Mainframe_B.hBE_0
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 138;
	
	  ;% Mainframe_B.VectorConcatenate
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 139;
	
	  ;% Mainframe_B.Constant8_a
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 142;
	
	  ;% Mainframe_B.e2
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 146;
	
	  ;% Mainframe_B.Add1
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 147;
	
	  ;% Mainframe_B.hBE_0_i
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 148;
	
	  ;% Mainframe_B.VectorConcatenate_g
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 149;
	
	  ;% Mainframe_B.T12
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 152;
	
	  ;% Mainframe_B.VectorConcatenate_c
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 161;
	
	  ;% Mainframe_B.aBIB
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 165;
	
	  ;% Mainframe_B.Gain_ln
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 168;
	
	  ;% Mainframe_B.Product_a
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 171;
	
	  ;% Mainframe_B.Product2
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 172;
	
	  ;% Mainframe_B.Product4
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 173;
	
	  ;% Mainframe_B.T12_a
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 174;
	
	  ;% Mainframe_B.Subtract_k
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 183;
	
	  ;% Mainframe_B.Subtract4
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 192;
	
	  ;% Mainframe_B.MathFunction
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 193;
	
	  ;% Mainframe_B.pAPB
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 202;
	
	  ;% Mainframe_B.hBE_0_c
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 205;
	
	  ;% Mainframe_B.VectorConcatenate_h
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 206;
	
	  ;% Mainframe_B.d_wBIB
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 209;
	
	  ;% Mainframe_B.Sum2_b
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 212;
	
	  ;% Mainframe_B.Product_k
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 215;
	
	  ;% Mainframe_B.Saturation_j
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 218;
	
	  ;% Mainframe_B.Sum2_h
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 221;
	
	  ;% Mainframe_B.Product_g
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 224;
	
	  ;% Mainframe_B.Saturation_je
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 227;
	
	  ;% Mainframe_B.Add
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 230;
	
	  ;% Mainframe_B.VectorConcatenate_m
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 246;
	
	  ;% Mainframe_B.wEGG
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 250;
	
	  ;% Mainframe_B.VectorConcatenate_d
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 253;
	
	  ;% Mainframe_B.VectorConcatenate_e
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 257;
	
	  ;% Mainframe_B.vBIB
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 261;
	
	  ;% Mainframe_B.VectorConcatenate_f
	  section.data(123).logicalSrcIdx = 123;
	  section.data(123).dtTransOffset = 264;
	
	  ;% Mainframe_B.d_x
	  section.data(124).logicalSrcIdx = 124;
	  section.data(124).dtTransOffset = 268;
	
	  ;% Mainframe_B.VectorConcatenate1
	  section.data(125).logicalSrcIdx = 125;
	  section.data(125).dtTransOffset = 281;
	
	  ;% Mainframe_B.DigitalClock
	  section.data(126).logicalSrcIdx = 126;
	  section.data(126).dtTransOffset = 284;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% Mainframe_B.CastToSingle18
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_B.RateTransition
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_B.CastToSingle
	  section.data(3).logicalSrcIdx = 130;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_B.CastToSingle19
	  section.data(4).logicalSrcIdx = 131;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_B.CastToSingle17
	  section.data(5).logicalSrcIdx = 132;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_B.CastToSingle16
	  section.data(6).logicalSrcIdx = 133;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_B.CastToSingle15
	  section.data(7).logicalSrcIdx = 134;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Mainframe_B.CastToSingle14
	  section.data(8).logicalSrcIdx = 135;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Mainframe_B.CastToSingle13
	  section.data(9).logicalSrcIdx = 136;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Mainframe_B.CastToSingle12
	  section.data(10).logicalSrcIdx = 137;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Mainframe_B.CastToSingle11
	  section.data(11).logicalSrcIdx = 138;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Mainframe_B.CastToSingle10
	  section.data(12).logicalSrcIdx = 139;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Mainframe_B.CastToSingle9
	  section.data(13).logicalSrcIdx = 140;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Mainframe_B.CastToSingle8
	  section.data(14).logicalSrcIdx = 141;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Mainframe_B.CastToSingle7
	  section.data(15).logicalSrcIdx = 142;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Mainframe_B.CastToSingle6
	  section.data(16).logicalSrcIdx = 143;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Mainframe_B.CastToSingle5
	  section.data(17).logicalSrcIdx = 144;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Mainframe_B.CastToSingle4
	  section.data(18).logicalSrcIdx = 145;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Mainframe_B.CastToSingle3
	  section.data(19).logicalSrcIdx = 146;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Mainframe_B.CastToSingle2
	  section.data(20).logicalSrcIdx = 147;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Mainframe_B.CastToSingle1
	  section.data(21).logicalSrcIdx = 148;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Mainframe_B.CastToSingle21
	  section.data(22).logicalSrcIdx = 149;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Mainframe_B.CastToSingle22
	  section.data(23).logicalSrcIdx = 150;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Mainframe_B.CastToSingle23
	  section.data(24).logicalSrcIdx = 151;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Mainframe_B.CastToSingle20
	  section.data(25).logicalSrcIdx = 152;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.FixPtSwitch
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Mainframe_B.PacketInput_o1
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_B.In1
	  section.data(2).logicalSrcIdx = 155;
	  section.data(2).dtTransOffset = 75;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Mainframe_B.PacketInput_o2
	  section.data(1).logicalSrcIdx = 156;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_B.GreaterThan
	  section.data(2).logicalSrcIdx = 157;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_B.GreaterThan_e
	  section.data(3).logicalSrcIdx = 158;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_B.GreaterThan_c
	  section.data(4).logicalSrcIdx = 159;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_B.AND
	  section.data(5).logicalSrcIdx = 160;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_B.Compare
	  section.data(6).logicalSrcIdx = 161;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_B.AND_c
	  section.data(7).logicalSrcIdx = 162;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Mainframe_B.AND_cl
	  section.data(8).logicalSrcIdx = 163;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Mainframe_B.q_R0R
	  section.data(9).logicalSrcIdx = 164;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Mainframe_B.q_R1R
	  section.data(10).logicalSrcIdx = 165;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Mainframe_B.q_R2R
	  section.data(11).logicalSrcIdx = 166;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Mainframe_B.q_R3R
	  section.data(12).logicalSrcIdx = 167;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Mainframe_B.HiddenBuf_InsertedFor_q_R0R_at_inport_1
	  section.data(13).logicalSrcIdx = 168;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Mainframe_B.HiddenBuf_InsertedFor_q_R1R_at_inport_1
	  section.data(14).logicalSrcIdx = 169;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Mainframe_B.HiddenBuf_InsertedFor_q_R2R_at_inport_1
	  section.data(15).logicalSrcIdx = 170;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Mainframe_B.HiddenBuf_InsertedFor_q_R3R_at_inport_1
	  section.data(16).logicalSrcIdx = 171;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.EnabledSubsystem1_h.DigitalClock
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Rate_o.d_siB_l
	  section.data(1).logicalSrcIdx = 173;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Acceleration_j.dd_siB_l
	  section.data(1).logicalSrcIdx = 174;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Rate_a.d_siB_l
	  section.data(1).logicalSrcIdx = 175;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Acceleration_l.dd_siB_l
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Rate_g.d_siB_l
	  section.data(1).logicalSrcIdx = 177;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Acceleration_p.dd_siB_l
	  section.data(1).logicalSrcIdx = 178;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Rate.d_siB_l
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.sf_Limiting_Acceleration.dd_siB_l
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_B.EnabledSubsystem1.DigitalClock
	  section.data(1).logicalSrcIdx = 181;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 15;
    
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
    ;% Auto data (Mainframe_DW)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% Mainframe_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_DW.DiscreteTimeIntegrator2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_DW.NextOutput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_DW.NextOutput_m
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Mainframe_DW.NextOutput_mb
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Mainframe_DW.NextOutput_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Mainframe_DW.TimeStampA
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% Mainframe_DW.LastUAtTimeA
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% Mainframe_DW.TimeStampB
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% Mainframe_DW.LastUAtTimeB
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% Mainframe_DW.TimeStampA_i
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% Mainframe_DW.LastUAtTimeA_d
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% Mainframe_DW.TimeStampB_c
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% Mainframe_DW.LastUAtTimeB_g
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% Mainframe_DW.Attitude_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.PacketInput_PWORK
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 9;
	
	  ;% Mainframe_DW.FinDeflections_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 10;
	
	  ;% Mainframe_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 18;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_EmulateEstimator_at_outport_0_1_PWORK.AQHandles
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 20;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_EnabledSubsystem1_at_outport_0_PWORK.AQHandles
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 33;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_From5_at_outport_0_1_PWORK.AQHandles
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 34;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_From6_at_outport_0_1_PWORK.AQHandles
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 39;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_From7_at_outport_0_1_PWORK.AQHandles
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 68;
	
	  ;% Mainframe_DW.TAQSigLogging_InsertedFor_From8_at_outport_0_1_PWORK.AQHandles
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 85;
	
	  ;% Mainframe_DW.U1_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 89;
	
	  ;% Mainframe_DW.Scope_PWORK_n.LoggedData
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 90;
	
	  ;% Mainframe_DW.Scope1_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 91;
	
	  ;% Mainframe_DW.Scope_PWORK_e.LoggedData
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 92;
	
	  ;% Mainframe_DW.Scope_PWORK_g.LoggedData
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 93;
	
	  ;% Mainframe_DW.Scope_PWORK_gw.LoggedData
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 94;
	
	  ;% Mainframe_DW.Debug_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 95;
	
	  ;% Mainframe_DW.FCCSync_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 96;
	
	  ;% Mainframe_DW.Scope_PWORK_a.LoggedData
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 97;
	
	  ;% Mainframe_DW.Scope1_PWORK_p.LoggedData
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 98;
	
	  ;% Mainframe_DW.PacketOutput_PWORK
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 99;
	
	  ;% Mainframe_DW.FccDelay_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 101;
	
	  ;% Mainframe_DW.Scope_PWORK_o.LoggedData
	  section.data(23).logicalSrcIdx = 37;
	  section.data(23).dtTransOffset = 102;
	
	  ;% Mainframe_DW.Scope_PWORK_oh.LoggedData
	  section.data(24).logicalSrcIdx = 38;
	  section.data(24).dtTransOffset = 103;
	
	  ;% Mainframe_DW.Assertion_slioAccessor
	  section.data(25).logicalSrcIdx = 39;
	  section.data(25).dtTransOffset = 104;
	
	  ;% Mainframe_DW.Assertion1_slioAccessor
	  section.data(26).logicalSrcIdx = 40;
	  section.data(26).dtTransOffset = 105;
	
	  ;% Mainframe_DW.Assertion2_slioAccessor
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 106;
	
	  ;% Mainframe_DW.Scope_PWORK_n4.LoggedData
	  section.data(28).logicalSrcIdx = 42;
	  section.data(28).dtTransOffset = 107;
	
	  ;% Mainframe_DW.Scope1_PWORK_m.LoggedData
	  section.data(29).logicalSrcIdx = 43;
	  section.data(29).dtTransOffset = 108;
	
	  ;% Mainframe_DW.Scope2_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 44;
	  section.data(30).dtTransOffset = 109;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Mainframe_DW.RandSeed
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.RandSeed_g
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Mainframe_DW.RandSeed_gr
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Mainframe_DW.RandSeed_i
	  section.data(4).logicalSrcIdx = 48;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Mainframe_DW.integration_eom_IWORK
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.integration_eom_IWORK_p
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_DW.integration_eom_IWORK_g
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_MODE
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_MODE_e
	  section.data(5).logicalSrcIdx = 53;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_MODE_h
	  section.data(6).logicalSrcIdx = 54;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_MODE_a
	  section.data(7).logicalSrcIdx = 55;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Mainframe_DW.Subsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.q_R3R_SubsysRanBC
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_DW.q_R2R_SubsysRanBC
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_DW.q_R1R_SubsysRanBC
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_DW.q_R0R_SubsysRanBC
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_DW.EnabledSubsystem_SubsysRanBC
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_DW.EnabledSubsystem1_SubsysRanBC
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_DWORK1
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_DWORK1_c
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_DWORK1_a
	  section.data(3).logicalSrcIdx = 66;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Mainframe_DW.IntegratorSecondOrderLimited_DWORK1_i
	  section.data(4).logicalSrcIdx = 67;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Mainframe_DW.Subsystem_MODE
	  section.data(5).logicalSrcIdx = 68;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Mainframe_DW.q_R3R_MODE
	  section.data(6).logicalSrcIdx = 69;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Mainframe_DW.q_R2R_MODE
	  section.data(7).logicalSrcIdx = 70;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Mainframe_DW.q_R1R_MODE
	  section.data(8).logicalSrcIdx = 71;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Mainframe_DW.q_R0R_MODE
	  section.data(9).logicalSrcIdx = 72;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_DW.EnabledSubsystem1_h.EnabledSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Mainframe_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 3958589060;
  targMap.checksum1 = 2956927614;
  targMap.checksum2 = 2779292625;
  targMap.checksum3 = 1316587036;

