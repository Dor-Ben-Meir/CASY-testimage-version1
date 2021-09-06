%% Defines the parameters of the GRM Simulink model
%
%
% SUMMARY:
% Defines the parameters of the subsystems of the Guided Research Missile
% Airframe model. Loads two .mat-files.
%
% DESCRIPTION:
% Defines the parameters of the subsystems of the Guided Research Missile
% Airframe model. Loads two .mat-files containing the thrust of the solid
% fuel rocket motor over time and the massflow over time.
%
% DEPENDENCIES:
% prp_lookup.mat

%
% PROJECT:
% *** LOW COST MISSILE TESTBED ***
%
% RESOURCES:
% Modeling and Simulation of the Guided Research Missile, Lausenhammer
% Thomas; Semester Thesis, Technical University Munich, 2018
%
% CHANGE DIRECTORY
% Date          Name                    Description         Version
% 2018/11/12    Lausenhammer, Thomas    initial version     V 1.0
% 2019/05/07    Lausenhammer, Thomas    changed Header      V 1.1
% 2019/05/07    Lausenhammer, Thomas    added comments      V 1.2
% 2020/05/24    Lausenhammer, Thomas    New GRM Model       V 2.0
% 2020/08/19    Lausenhammer, Thomas    Sensor para-        V 2.1
%                                       metrization
% 2020/10/05    Lausenhammer, Thomas    Added GPS           V 2.2
%
%
%%  Load Parameters
%%  Propulsion
%Time and thrust data for Propulstion look-up table

load('prop_model.mat');          % Look-Up Table Data mass flow over time [kg/s] and thrust
  
pNPB = [-1.248;0;0];             %[m] position vector of the noozle

% initial propellant load
propellant_kg = 0.871;  

%%  Weight and Balance

CGx_full_m = -0.616;
CGy_full_m = 0;
CGz_full_m = 0;

CGx_empty_m = -0.513;
CGy_empty_m = 0;
CGz_empty_m = 0;

Mass_Props.CGx_m_tbl = [CGx_empty_m CGx_full_m];
Mass_Props.CGy_m_tbl = [CGy_empty_m CGy_full_m];
Mass_Props.CGz_m_tbl = [CGz_empty_m CGz_full_m];

mB_0 = 4.542;               % Missile structure mass with motor (no propellant) [kg]
m0 = mB_0;

% MOI with full propellant (at launch)
JSPB_0     = [0.0183649	  -0.00031558	-0.00001496;
             -0.00031558   0.38045067	-0.00001731;
             -0.00001496  -0.00001731	 0.38051106];

% MOI with empty propellant (after burnout)
JSPB_e     = [0.0152183	  -0.00029577	-0.00003551
             -0.00029577   0.33319479	-0.0000173
             -0.00003551  -0.0000173	 0.33425523];

propellant_empty_threshold_kg = 0.015;

Mass_Props.propellant_bkpts = [propellant_empty_threshold_kg propellant_kg];
Mass_Props.Ixx_tbl          = [JSPB_e(1,1), JSPB_0(1,1)];
Mass_Props.Ixy_tbl          = [JSPB_e(1,2), JSPB_0(1,2)];
Mass_Props.Ixz_tbl          = [JSPB_e(1,3), JSPB_0(1,3)];
Mass_Props.Iyx_tbl          = [JSPB_e(2,1), JSPB_0(2,1)];
Mass_Props.Iyy_tbl          = [JSPB_e(2,2), JSPB_0(2,2)];
Mass_Props.Iyz_tbl          = [JSPB_e(2,3), JSPB_0(2,3)];
Mass_Props.Izx_tbl          = [JSPB_e(3,1), JSPB_0(3,1)];
Mass_Props.Izy_tbl          = [JSPB_e(3,2), JSPB_0(3,2)];
Mass_Props.Izz_tbl          = [JSPB_e(3,3), JSPB_0(3,3)];


%%  Fins and Fin actuators
% position, velocity and acceleration limitations of the 2nd order actuator
% system
siB_max = deg2rad(30);              %[rad]
siB_min = deg2rad(-30);             %[rad]
d_siB_min = deg2rad(-1200);         %[rad/S]
d_siB_max = deg2rad(1200);          %[rad/s]
dd_siB_min = -inf;                  %[rad/s^2]
dd_siB_max = inf;                   %[rad/s^2]

act_omega = 59.9250;                %[rad/s] Sys-ID Technion
act_dmp = 0.6322;                   %[-] damping Sys-ID Technion
unc_act_bl = 0;                     %[rad] bias error
unc_act_scale = 1;                  %[-] scale factor error
unc_act_off = 0;                    %[rad] actuator offset
siB_0 = 0;                          %[rad] initial value
d_siB_0 = 0;                        %[rad/s] initial value
tRRR = 0;

Actuator.fin1_bias  = 0;
Actuator.fin1_scale = 1;
Actuator.fin2_bias  = 0;
Actuator.fin2_scale = 1;
Actuator.fin3_bias  = 0;
Actuator.fin3_scale = 1;
Actuator.fin4_bias  = 0;
Actuator.fin4_scale = 1;

% Control allocation matrix
Tr4r3 = [ 1,  1, -1;...
          1,  1,  1;...
          1, -1,  1;...
          1, -1, -1];  

%pseudo-inverse Control allocation matrix
Tr3r4 = 0.25*[ 1,  1,  1,  1;...
               1,  1, -1, -1;...
              -1,  1,  1, -1]; 

%%  Sensors

%%  IMU
% IMU-Accelerometer
%settings for IMU time step, update rate and time offset have to be in
%compliance with the simulation time step

%   Parametrisierung BMI088
imu_dt = 1/200;             %[s] IMU time step (Blockschrittweite)
imu_UpdateRate = 200;       %[Hz] IMU Update rate
imu_delay = 0.001;         %[s] IMU time offset
imu_seed = 0;            %[-] initialization value for random number generator (either zero or positive integer)
imu_a_limits = [16*9.81];     %[m/s^2] accelerometer saturation
imu_a_sigmanoise = [1.7162e-3;1.7162e-3;1.7162e-3];       %[m/s/sqrt(s)] white sensor noise
imu_a_quantization = 9e-3; %[m/s^2] Quantization
imu_a_bias_static = [9.80665*20e-3;9.80665*20e-3;9.80665*20e-3];    %[m/s^2] static acc-imu bias
imu_a_bias_randomwalk = [1e-3;1e-3;1e-3];   %[m/s^2] standard deviation in run stability
imu_a_bias_timeconstant = 1;         %[s] dynamic in run stability
imu_a_flag_dyn = 1;                  %
imu_a_omega = [523;523;523];            %[rad/s] acc-imu dynamic frequency 5-523 [Hz]
imu_a_damping = [sqrt(2)/2; sqrt(2)/2;sqrt(2)/2];         %[-] damping
imu_a_ScaleFactor = [1000;1000;1000];      %[ppm] linear scale factor acc
imu_a_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor acc
imu_a_ScaleFactorA = zeros(3,1);     %[ppm] absolute scale factor acc
imu_a_misalignment = zeros(3,1);     %[rad] misalignment
imu_a_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
imu_a_CrossCoupling = zeros(3,1);    %[-] cross coupling
% IMU-Gyroscope
imu_w_limits = deg2rad(2000);         %[rad/s] gyroscope saturation
imu_w_sigmanoise = [2.443392e-4;2.443392e-4;2.443392e-4];       %[rad/sqrt(s)] gyroscope white sensor noise
imu_w_quantization = deg2rad(0.004); %[rad/s] quantization gyroscope
imu_w_bias_static = [deg2rad(1);deg2rad(1);deg2rad(1)];      %[rad/s] static bias gyroscope
imu_w_bias_randomwalk = zeros(3,1);  %[rad/s] standard deviation in run stability
imu_w_bias_timeconstant = 1;        %[s] dynamic in run stability
imu_w_bias_AccelerationEffect = [4.943723709009050e-07,0,0;0,4.943723709009050e-07,0;0,0,4.943723709009050e-07];  %[rad*s/m] ruck effect
imu_w_flag_dyn = 1;                  %
imu_w_omega = [523;523;523];          %[rad/s] Imu dynamic frequency
imu_w_damping = [sqrt(2)/2; sqrt(2)/2;sqrt(2)/2];          %[-] damping
imu_w_ScaleFactor = [400;400;400];      %[ppm] linear scale factor error
imu_w_ScaleFactorN = zeros(3,1);     %[ppm] quadratic scale factor error
imu_w_ScaleFactorA = zeros(3,1);     %[ppm] norm scale factor error
imu_w_misalignment = zeros(3,1);     %[rad] misalignment
imu_w_nonorthogonality = zeros(3,1); %[rad] deviation from ideal orthogonal projection
imu_w_CrossCoupling = zeros(3,1);    %[-] cross coupling

TUB = [-1,0,0;0,1,0;0,0,-1];          %IMU rotation Transformation matrix
TBU = TUB';
pUPB = [-0.136;0;0];                %[m] IMU position from the reference point

%%  GPS
%   It is assumed that the GPS is at the same positiona as the IMU in a
%   first iteration.

gps_sigH = 2.23;                    % Horizontal standard deviation [m] (typical value C/A based GPS receiver)
gps_sigV = 2.23;                    % Vertical Standard deviation [m] (typical value C/A based GPS receiver)
gps_T_sample = 1/10;                %   [s] Update Frequency of 10 Hz for GPS signal.

%%  Fin Encoder

%RMB20
enc_CLK_rate = 0.001;               %[s] Time periode of the SSI Bus Clock rate
enc_hys = 0.18;                     %{°] Encoder Hysteresis
enc_acc = 0.5;                      %[+-°] Encoder Accuracy
enc_reap = 0.07;                    %[°] Encoder repeatability
enc_res = 8192;                     %[bit] Encode resolution in positions per revolution
enc_rand_acc = rand;                 %[-] random initialization encoder accuracy

%%  Aerodynamics

% reference areas
Aerodynamics.lref = 0.0900;
Aerodynamics.sref = pi*((Aerodynamics.lref/2)^2);

% aero ref point along x-axis
Aerodynamics.xcg  = 0.6195;

% TLU limits
Aerodynamics.ulim_alpha_deg = 15;
Aerodynamics.llim_alpha_deg = -10;
Aerodynamics.ulim_beta_deg  = 15;
Aerodynamics.llim_beta_deg  = -10;

% load aero coefficients for TLU
load('aero_model.mat');

% CX0 2D (alpha,beta)
Aerodynamics.CX_alpha_beta         = aero_model.CX_alpha_beta;
Aerodynamics.alpha_beta_bkpts_ind1 = aero_model.alpha_beta_bkpts_ind1;
Aerodynamics.alpha_beta_bkpts_ind2 = aero_model.alpha_beta_bkpts_ind2;

% C0_alpha 1D (alpha)
Aerodynamics.CY_alpha  = aero_model.CY_alpha;
Aerodynamics.CZ_alpha  = aero_model.CZ_alpha;
Aerodynamics.CLL_alpha = aero_model.CLL_alpha;
Aerodynamics.CLM_alpha = aero_model.CLM_alpha;
Aerodynamics.CLN_alpha = aero_model.CLN_alpha;
Aerodynamics.alpha_bkpts_ind1 = aero_model.alpha_bkpts_ind1;

% C0_beta 1D (alpha)
Aerodynamics.CY_beta  = aero_model.CY_beta;
Aerodynamics.CZ_beta  = aero_model.CZ_beta;
Aerodynamics.CLL_beta = aero_model.CLL_beta;
Aerodynamics.CLM_beta = aero_model.CLM_beta;
Aerodynamics.CLN_beta = aero_model.CLN_beta;
Aerodynamics.beta_bkpts_ind1 = aero_model.beta_bkpts_ind1;

% dele increment 2D (alpha,dele)
Aerodynamics.CX_dele_inc  = aero_model.CX_dele_inc;
Aerodynamics.CY_dele_inc  = aero_model.CY_dele_inc;
Aerodynamics.CZ_dele_inc  = aero_model.CZ_dele_inc;
Aerodynamics.CLL_dele_inc = aero_model.CLL_dele_inc;
Aerodynamics.CLM_dele_inc = aero_model.CLM_dele_inc;
Aerodynamics.CLN_dele_inc = aero_model.CLN_dele_inc;
Aerodynamics.dele_inc_bkpts_ind1 = aero_model.dele_inc_bkpts_ind1;
Aerodynamics.dele_inc_bkpts_ind2 = aero_model.dele_inc_bkpts_ind2;

% dela increment 2D (alpha,dela)
Aerodynamics.CX_dela_inc  = aero_model.CX_dela_inc;
Aerodynamics.CY_dela_inc  = aero_model.CY_dela_inc;
Aerodynamics.CZ_dela_inc  = aero_model.CZ_dela_inc;
Aerodynamics.CLL_dela_inc = aero_model.CLL_dela_inc;
Aerodynamics.CLM_dela_inc = aero_model.CLM_dela_inc;
Aerodynamics.CLN_dela_inc = aero_model.CLN_dela_inc;
Aerodynamics.dela_inc_bkpts_ind1 = aero_model.dela_inc_bkpts_ind1;
Aerodynamics.dela_inc_bkpts_ind2 = aero_model.dela_inc_bkpts_ind2;

% delr increment 2D (beta,delr)
Aerodynamics.CX_delr_inc  = aero_model.CX_delr_inc;
Aerodynamics.CY_delr_inc  = aero_model.CY_delr_inc;
Aerodynamics.CZ_delr_inc  = aero_model.CZ_delr_inc;
Aerodynamics.CLL_delr_inc = aero_model.CLL_delr_inc;
Aerodynamics.CLM_delr_inc = aero_model.CLM_delr_inc;
Aerodynamics.CLN_delr_inc = aero_model.CLN_delr_inc;
Aerodynamics.delr_inc_bkpts_ind1 = aero_model.delr_inc_bkpts_ind1;
Aerodynamics.delr_inc_bkpts_ind2 = aero_model.delr_inc_bkpts_ind2;

% Dynamic Derivatives
Aerodynamics.CLL_p = -102.48;
Aerodynamics.CLM_q = -380.077;
Aerodynamics.CLN_r = -380.077;

% Uncertainties
Aerodynamics.CX_scale  = 1;
Aerodynamics.CX_bias   = 0;
Aerodynamics.CY_scale  = 1;
Aerodynamics.CY_bias   = 0;
Aerodynamics.CZ_scale  = 1;
Aerodynamics.CZ_bias   = 0;
Aerodynamics.CLL_scale = 1;
Aerodynamics.CLL_bias  = 0;
Aerodynamics.CLM_scale = 1;
Aerodynamics.CLM_bias  = 0;
Aerodynamics.CLN_scale = 1;
Aerodynamics.CLN_bias  = 0;

%%  GNC

guidc_aUIB_x_th = 40;
guidc_T_th = 0.3;

guidc_n_window = 10;
%%  Controller

t_sample_contr = 0.001;

% fc_aero = load('fc_aero.mat');

%   Output redefinition

% pUBB_x = 1.4;
pUBB_x = 1.2;

% Gains NDI-Inner-Loop

% kIi = 0;
% kIp = 1000;
wI_ref = 400;

% kOp = 0.0275;
% kOi = 0;
wO_ref = 200;

%%  Implemented uncertainties:

unc_fin_def_roll =          0;
unc_fin_def_pitch =         0;
unc_fin_def_yaw =           0;

%  Weight and Balance
unc_cg_x = 0;
unc_cg_y = 0;
unc_cg_z = 0;

unc_moi_Jxx = 0;
unc_moi_Jyy = 0;
unc_moi_Jzz = 0;
unc_mB_bl = 0;
unc_mB_scale = 1;

%   Propulsion
unc_prp_z = 0;
unc_prp_y = 0;
unc_prp_x = 0;
unc_prp_scale = 1;

%   Aerodynamic coefficients
unc_aero_Cx_scale = 1;
unc_aero_Cy_scale = 1;
unc_aero_Cz_scale = 1;
unc_aero_Cl_scale = 1;
unc_aero_Cm_scale = 1;
unc_aero_Cn_scale = 1;

%   Actuator Failure
unc_act_fail_flag_1 = 1;
unc_act_fail_position_1 = 0;
unc_act_fail_flag_2 = 1;
unc_act_fail_position_2 = 0;
unc_act_fail_flag_3 = 1;
unc_act_fail_position_3 = 0;
unc_act_fail_flag_4 = 1;
unc_act_fail_position_4 = 0;