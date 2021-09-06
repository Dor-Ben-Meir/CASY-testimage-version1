clear,clc, close all
%load onlineRun2021.03.18b.mat
load onlineRun2021.04.01.mat
onlineData = data
load offlineRun2021.03.18.mat
offlineData = data
i = 1;

calibTimeOnline = onlineData.getElement('calibration time').Values.Data(:);
calibTimeOffline = offlineData.getElement('calibration time').Values.Data(:);
calibTime = calibTimeOnline(end);
calibSamples = calibTime*1000+1;
tOnline = (1:length(calibTimeOnline)-calibSamples+1)/1000;
tOffline = (1:length(calibTimeOffline))/1000;

%% Attitude - Gimbal Vs FDM
phi_fdm_online =        rad2deg(onlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Phi_rad.data(calibSamples:end));
theta_fdm_online =      rad2deg(onlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Theta_rad.data(calibSamples:end));
psi_fdm_online =        rad2deg(onlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Psi_rad.data(calibSamples:end));
phi_gimbal_online =     rad2deg(onlineData.getElement('Gimbal Angles').Values.gimbalPhi.Data(calibSamples:end));
theta_gimbal_online =   rad2deg(onlineData.getElement('Gimbal Angles').Values.gimbalTheta.Data(calibSamples:end));
psi_gimbal_online =     rad2deg(onlineData.getElement('Gimbal Angles').Values.gimbalPsi.Data(calibSamples:end));

figure(i); i = i+1;
p = plot(tOnline(:),[phi_fdm_online(:),phi_gimbal_online(:)]);
p(1).DisplayName = 'FDM data'; p(2).DisplayName = 'Gimbal position';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Gimbal Performance ($\phi$)");

figure(i); i = i+1;
p = plot(tOnline(:),[theta_fdm_online(:),theta_gimbal_online(:)]);
p(1).DisplayName = 'FDM data'; p(2).DisplayName = 'Gimbal position';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time (s)"), ylabel("$\theta$ [deg]"), title("Gimbal Performance ($\theta$)");

figure(i); i = i+1;
p = plot(tOnline(:),[psi_fdm_online(:),psi_gimbal_online(:)]);
p(1).DisplayName = 'FDM data'; p(2).DisplayName = 'Gimbal position';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time (s)"), ylabel("$\psi$ [deg]"), title("Gimbal Performance ($\psi$)");

%% Attitude - FDM online vs FDM online
phi_fdm_offline =        rad2deg(offlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Phi_rad.data);
theta_fdm_offline =      rad2deg(offlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Theta_rad.data);
psi_fdm_offline =        rad2deg(offlineData.getElement('FDM States').Values.Attitude_States.ATT_Euler.Psi_rad.data);

figure(i); i = i+1;
p = plot(tOnline(:),phi_fdm_online(:),tOffline,phi_fdm_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Attitude - Roll Angle ($\phi$)");

figure(i); i = i+1;
p = plot(tOnline(:),theta_fdm_online(:),tOffline,theta_fdm_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$\theta$ [deg]"), title("Attitude - Pitch Angle ($\theta$)");

figure(i); i = i+1;
p = plot(tOnline(:),psi_fdm_online(:),tOffline,psi_fdm_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$\psi$ [deg]"), title("Attitude - Yaw Angle ($\psi$)");

%% Gyro - PIXHAWK vs Virtual
gyroX_pix_online =      squeeze(rad2deg(onlineData.getElement('FCC Data').Values.Internal_Data.gyroX.Data(calibSamples:end)));
gyroY_pix_online =      squeeze(rad2deg(onlineData.getElement('FCC Data').Values.Internal_Data.gyroY.Data(calibSamples:end)));
gyroZ_pix_online =      squeeze(rad2deg(onlineData.getElement('FCC Data').Values.Internal_Data.gyroZ.Data(calibSamples:end)));

gyroX_virtual_online = zeros(size(gyroX_pix_online));
gyroY_virtual_online = zeros(size(gyroY_pix_online));
gyroZ_virtual_online = zeros(size(gyroZ_pix_online));

%gyroX_virtual_online(((calibTimeOnline(end)*1000)+1):end) =      rad2deg(onlineData.getElement('Virtual IMU').Values.gyro.gyroX.Data(calibSamples:end));
%gyroY_virtual_online(((calibTimeOnline(end)*1000)+1):end) =      rad2deg(onlineData.getElement('Virtual IMU').Values.gyro.gyroY.Data(calibSamples:end));
%gyroZ_virtual_online(((calibTimeOnline(end)*1000)+1):end) =      rad2deg(onlineData.getElement('Virtual IMU').Values.gyro.gyroZ.Data(calibSamples:end));

gyroX_virtual_online =      rad2deg(onlineData.getElement('IMU Data').Values.gyro.gyroX.Data(calibSamples:end));
gyroY_virtual_online =      rad2deg(onlineData.getElement('IMU Data').Values.gyro.gyroY.Data(calibSamples:end));
gyroZ_virtual_online =      rad2deg(onlineData.getElement('IMU Data').Values.gyro.gyroZ.Data(calibSamples:end));

% gyroX_pix_online(1:length(gyroX_pix_online)-length(gyroX_virtual_online)) = [];
% gyroY_pix_online(1:length(gyroY_pix_online)-length(gyroY_virtual_online)) = [];
% gyroZ_pix_online(1:length(gyroZ_pix_online)-length(gyroZ_virtual_online)) = [];

figure(i); i = i+1;
p = plot(tOnline(:),[gyroX_pix_online(:), gyroX_virtual_online(:)]);
p(1).DisplayName = 'Real gyro'; p(2).DisplayName = 'Virtual gyro';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$p$ [deg/s]"), title("Real vs Virtual Gyroscope Data (x-gyro)");

figure(i); i = i+1;
p = plot(tOnline(:),[gyroY_pix_online(:),gyroY_virtual_online(:)]);
p(1).DisplayName = 'Real gyro'; p(2).DisplayName = 'Virtual gyro';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$q$ [deg/s]"), title("Real vs Virtual Gyroscope Data (y-gyro)");

figure(i); i = i+1;
p = plot(tOnline(:),[gyroZ_pix_online(:),gyroZ_virtual_online(:)]);
p(1).DisplayName = 'Real gyro'; p(2).DisplayName = 'Virtual gyro';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("$r$ [deg/s]"), title("Real vs Virtual Gyroscope Data (z-gyro)");

%% Fin Deflections - Online vs offline
fin1_online = rad2deg(onlineData.getElement('Fin Deflections').Values.Fin_1.Data(calibSamples:end));
fin2_online = rad2deg(onlineData.getElement('Fin Deflections').Values.Fin_2.Data(calibSamples:end));
fin3_online = rad2deg(onlineData.getElement('Fin Deflections').Values.Fin_3.Data(calibSamples:end));
fin4_online = rad2deg(onlineData.getElement('Fin Deflections').Values.Fin_4.Data(calibSamples:end));
fin1_offline = rad2deg(offlineData.getElement('Fin Deflections').Values.Fin_1.Data(:));
fin2_offline = rad2deg(offlineData.getElement('Fin Deflections').Values.Fin_2.Data(:));
fin3_offline = rad2deg(offlineData.getElement('Fin Deflections').Values.Fin_3.Data(:));
fin4_offline = rad2deg(offlineData.getElement('Fin Deflections').Values.Fin_4.Data(:));
% % 
% % figure(i); i = i+1;
% %p =  plot(t(:),[fin1_online(:),fin1_offline(:)])
% p(1).DisplayName = 'FDM position'; p(2).DisplayName = 'Gimbal position';
% p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
% grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Gimbal Performance ($\phi$)");
% % 
% % figure(i); i = i+1;
% %p =  plot(t(:),[fin2_online(:),fin2_offline(:)])
% p(1).DisplayName = 'FDM position'; p(2).DisplayName = 'Gimbal position';
% p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
% grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Gimbal Performance ($\phi$)");
% % 
% % figure(i); i = i+1;
% %p =  plot(t(:),[fin3_online(:),fin3_offline(:)])
% p(1).DisplayName = 'FDM position'; p(2).DisplayName = 'Gimbal position';
% p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
% grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Gimbal Performance ($\phi$)");
% % 
% % figure(i); i = i+1;
% %p =  plot(t(:),[fin4_online(:),fin4_offline(:)])
% p(1).DisplayName = 'FDM position'; p(2).DisplayName = 'Gimbal position';
% p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
% % grid, legend, xlabel("Time [s]"), ylabel("$\phi$ [deg]"), title("Gimbal Performance ($\phi$)");
% 
% figure(i); i = i+1;
% p = plot(tOffline,fin4_offline(:), tOnline(:),[fin1_online(:),fin2_online(:),fin3_online(:),fin4_online(:)])
% p(1).DisplayName = 'FDM position'; p(2).DisplayName = 'Gimbal position';
% p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3; p(3).LineStyle = '--'; p(3).LineWidth = 3; p(4).LineStyle = '--'; p(4).LineWidth = 3; p(5).LineStyle = '--'; p(5).LineWidth = 3;
% grid, legend, xlabel("Time [s]"), ylabel("Fin deflection [deg]"), title("Online vs Offline Fin Deflections");

figure(i); i = i+1;
p = plot(tOnline(:),fin1_online(:),tOffline,fin4_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("Fin deflection [deg]"), title("Fin Deflections (fin \#1 shown)");

figure(i); i = i+1;
p = plot(tOnline(:),[fin1_online(:),fin2_online(:),fin3_online(:),fin4_online(:)]);
p(1).DisplayName = 'Fin 1'; p(2).DisplayName = 'Fin 2'; p(3).DisplayName = 'Fin 3'; p(4).DisplayName = 'Fin 4';
p(1).LineWidth = 2; p(1).LineStyle = '-';
p(2).LineWidth = 2; p(2).LineStyle = '--';
p(3).LineWidth = 2; p(3).LineStyle = '-.';
p(4).LineWidth = 2; p(4).LineStyle = ':';
xlim([5,10]);ylim([-1.5,1.5]);
grid, legend, xlabel("Time [s]"), ylabel("Fin deflection [deg]"), title("Fin Deflections - Zoomed In");

%% Inertial Position - Online vs Offline
x_online = onlineData.getElement('FDM States').Values.POS_NED.POS_x_NED_m.Data(calibSamples:end);
y_online = onlineData.getElement('FDM States').Values.POS_NED.POS_y_NED_m.Data(calibSamples:end);
z_online = -onlineData.getElement('FDM States').Values.POS_NED.POS_z_NED_m.Data(calibSamples:end);
x_offline = offlineData.getElement('FDM States').Values.POS_NED.POS_x_NED_m.Data(:);
y_offline = offlineData.getElement('FDM States').Values.POS_NED.POS_y_NED_m.Data(:);
z_offline = -offlineData.getElement('FDM States').Values.POS_NED.POS_z_NED_m.Data(:);

figure(i); i = i+1;
p = plot(tOnline(:),x_online(:),tOffline,x_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("X [m]"), title("Position in Inertial-Axis ($X$)");

figure(i); i = i+1;
p = plot(tOnline(:),y_online(:),tOffline,y_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("Y [m]"), title("Position in Inertial-Axis ($Y$)");

figure(i); i = i+1;
p = plot(tOnline(:),z_online(:),tOffline,z_offline(:));
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("Time [s]"), ylabel("Z [m]"), title("Position in Inertial-Axis ($Z$)");


figure(i); i = i+1;
p=plot(x_online(:),y_online(:),x_offline(:),y_offline(:))
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("X [m]"), ylabel("Y [m]"), title("Position in Inertial-Axis ($XY$ Plane)");

figure(i); i = i+1;
p = plot(x_online(:),z_online(:),x_offline(:),z_offline(:))
p(1).DisplayName = 'Hybrid Simulation'; p(2).DisplayName = 'Offline Simulation';
p(1).LineWidth = 2; p(2).LineStyle = '--'; p(2).LineWidth = 3;
grid, legend, xlabel("X [m]"), ylabel("-Z [m]"), title("Position in Inertial-Axis ($XZ$ Plane)");


%% Heartbeat Sync
load heartbeat
heartbeatData = data
figure(i); i = i+1;
t1 = 10;
t2 = 10.5;
HB_sent = heartbeatData.getElement('Heartbeat Sync(1)').Values.Data(t1*1000:t2*1000);
HB_received = heartbeatData.getElement('Heartbeat Sync(2)').Values.Data(t1*1000:t2*1000);
p = plot(t1:0.001:t2,[HB_sent,HB_received])
p(1).DisplayName = 'Heartbeat - reference'; p(2).DisplayName = 'Heartbeat - recieved from Pixhawk';
p(1).LineWidth = 2; p(2).LineStyle = '-'; p(2).LineWidth = 2;
grid, legend, xlabel("Time [s]"), ylabel("Heartbeat"), title("Heartbeat Signal");
