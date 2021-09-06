% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Control Params
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% roll
load('roll_gains.mat');
Autopilot.Phi.Kp_p_vec    = Kp_p_tbl;
Autopilot.Phi.Kp_phi_vec  = Kp_phi_tbl;
Autopilot.Phi.Ki_phi_vec  = Ki_phi_tbl;
Autopilot.Phi.h_bkpts_m   = roll_bkpts.ind1;
Autopilot.Phi.V_bkpts_mps = roll_bkpts.ind2;

% yaw
load('yaw_gains.mat');
Autopilot.Ay.Kp_r_vec    = Kp_r_tbl;
Autopilot.Ay.Kp_ay_vec   = Kp_ay_tbl;
Autopilot.Ay.Ki_ay_vec   = Ki_ay_tbl;
Autopilot.Ay.h_bkpts_m   = yaw_bkpts.ind1;
Autopilot.Ay.V_bkpts_mps = yaw_bkpts.ind2;

% pitch
load('pitch_gains.mat');
Autopilot.Az.Kp_q_vec    = Kp_q_tbl;
Autopilot.Az.Kp_az_vec   = Kp_az_tbl;
Autopilot.Az.Ki_az_vec   = Ki_az_tbl;
Autopilot.Az.h_bkpts_m   = pitch_bkpts.ind1;
Autopilot.Az.V_bkpts_mps = pitch_bkpts.ind2;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Fin Limits and Uncertainties
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% max fin deflections (physical limits)
Autopilot.fin_def_max_rad = 20*pi/180;
Autopilot.fin_def_min_rad = -20*pi/180;

% virtual command uncertainties
Autopilot.dela_cmd_bias_rad = 0*pi/180;
Autopilot.dele_cmd_bias_rad = 0*pi/180;
Autopilot.delr_cmd_bias_rad = 0*pi/180;

% fin command uncertainties
Autopilot.fin1_cmd_bias_rad = 0*pi/180;
Autopilot.fin2_cmd_bias_rad = 0*pi/180;
Autopilot.fin3_cmd_bias_rad = 0*pi/180;
Autopilot.fin4_cmd_bias_rad = 0*pi/180;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Flight Logic Params
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Vehicle State Enumerations
vehicle_state.prelaunch     = 1;
vehicle_state.prelaunch_RTL = 2;

% threshold timers
Flight_Logic.Ax_launch_accel_threshold_mps2 = 40;
Flight_Logic.Ax_launch_timer_threshold_sec  = 0.3;
Flight_Logic.Ax_MECO_timer_threshold_sec    = 0.3;
Flight_Logic.h_apogee_timer_threshold_sec   = 0.5;
Flight_Logic.apogee_recovery_timer_threshold_sec = 0.5;

% timeout timers
Flight_Logic.MECO_timeout_TOF_sec     = 999;
Flight_Logic.apogee_timeout_TOF_sec   = 999;
Flight_Logic.recovery_timeout_TOF_sec = 999;

% flag to manually disable recovery
Flight_Logic.disable_recovery_manual  = 0;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Guidance Params
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Trajectory Enumerations
Guidance.traj_ballistic = 1;
Guidance.traj_max_glide = 2;

% Trajectory Default
Guidance.traj_default = Guidance.traj_ballistic;

% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
% Filters
% ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
load('imu_filt.mat');
num_lpf_d = num_lpf20;
den_lpf_d = den_lpf20;

guidc_n_window = 10;