clear,clc

%% ----------> CHANGE ONLY THIS SECTION <---------- %%
% NOTE ADDITIONAL SETTINGS LOCATED IN:  \req\init\FDM\sophisticated\

% Specify Simulation Parameters

Enable_FlightGear   = 0;    % ONLY ENABLE IN OFFLINE-MODE!! 

Enable_Pixhawk      = 1;    % <1> to enable, <0> to emulate
Enable_Flight_Table = 0;    % <1> to enable, <0> to disable
Enable_Gyros        = 0;    %!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Enable_Servos       = 0;    % <1> to measure servo deflections, <0> to use tranfer functions
Enable_INS          = 0;    %!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!         

Emulated_FCC_IO_Delay = 7;

%% Number of valiables sent from Pixhawk to HIL 
FCC_items           = 18;   % Number of variables sent from FCC to HIL

%% Define Variant subsystems
VSS_GIMBAL_ON      = Simulink.Variant('HIL_Data.VSS.Gimbal==1');
VSS_GIMBAL_OFF     = Simulink.Variant('HIL_Data.VSS.Gimbal==0');
VSS_FCC_REAL       = Simulink.Variant('HIL_Data.VSS.FCC==1'); 
VSS_FCC_EMUL       = Simulink.Variant('HIL_Data.VSS.FCC==0');
VSS_FLIGHTGEAR_ON  = Simulink.Variant('HIL_Data.VSS .FlightGear==1');
VSS_FLIGHTGEAR_OFF = Simulink.Variant('HIL_Data.VSS.FlightGear==0');
VSS_SERVOS_ON      = Simulink.Variant('HIL_Data.VSS.MeasureServos==1');
VSS_SERVOS_OFF     = Simulink.Variant('HIL_Data.VSS.MeasureServos==0');
       
%% Add paths to the Current Directory
addpath(genpath([pwd,'\req\Thomas_FDM']));
addpath(genpath([pwd,'\req\library']));

%% Initialize Submodules
HIL_Data.FDM                = init_FDM;
HIL_Data.VSS.FCC            = Enable_Pixhawk;
HIL_Data.VSS.Gimbal         = Enable_Flight_Table;
HIL_Data.VSS.FlightGear     = Enable_FlightGear;
HIL_Data.VSS.MeasureServos  = Enable_Servos;

FCC_message_size            = FCC_items*4+3;
FCC_types                   = sprintf('%d*uint8',FCC_message_size);
    
load_autopilot;
%%
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

%% Ready to Rock
%clc
disp("Ready!")