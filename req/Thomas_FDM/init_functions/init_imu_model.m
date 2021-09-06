%% Initialisierung des ISim-Modells Inertial Measurement Unit
%
% EINGANG:    
%   NOTWENDIG:
%    [1x1]   double    imu_Rate              ....... Messabtastung
%    [1x1]   double    imu_dt_d              ....... Blockschrittweite
%    [1x1]   double    imu_random_seed       ....... Initialisierungwert
%                                                    für Zufallszahlen-
%                                                    generator
%    [3x1]   double    a_sigmanoise          ....... weißes Sensorrauschen
%                                                    bei Beschleunigung
%    [3x1]   double    w_sigmanoise          ....... weißes Sensorrauschen
%                                                    bei Winkelgeschwindigkeit
%    [1x1]   double    a_quantization        ....... Quantisierung bei
%                                                    Beschleunigung
%    [1x1]   double    w_quantization        ....... Quantisierung bei
%                                                    Winkelgeschwindigkeit
%    [3x1]   double    a_bias_static         ....... konstanter Bias bei
%                                                    Beschleunigung
%    [3x1]   double    w_bias_static         ....... konstanter Bias bei
%                                                    Winkelgeschwindigkeit
%    [3x1]   double    a_biasIR_sigma        ....... Standardabweichung (In
%                                                    Run Stability) bei 
%                                                    Beschleunigung
%    [3x1]   double    w_biasIR_sigma        ....... Standardabweichung (In
%                                                    Run Stability) bei 
%                                                    Winkelgeschwindigkeit
%    [1x1]   double    a_biasIR_timeconstant ....... Dynamik (In Run
%                                                    Stability) bei 
%                                                    Beschleunigung
%    [1x1]   double    w_biasIR_timeconstant ....... Dynamik (In Run
%                                                    Stability) bei 
%                                                    Winkelgeschwindigkeit
%    [1x1]   double    a_flag_dyn            ....... flag zur Abstellung
%                                                    der Dynamik 
%                                                    (Beschleunigung)
%    [1x1]   double    w_flag_dyn            ....... flag zur Abstellung
%                                                    der Dynamik
%                                                    (Winkelgeschwindigkeit)
%
% AUSGABE:   
%    [3x3]   double    a_MisMat              ....... Ausrichtungsfehler-
%                                                    transformationsmatrix 
%                                                    bei Beschleunigung
%    [3x3]   double    w_MisMat              ....... Ausrichtungsfehler-
%                                                    transformationsmatrix 
%                                                    bei Winkelgeschwindigkeit
%    [1x3]   double    a_RWseed              ....... Initialisierungswert
%                                                    für Random Walk bei 
%                                                    Beschleunigung
%    [1x3]   double    a_WNseed              ....... Initialisierungswert
%                                                    für weißes Rauschen 
%                                                    bei Beschleunigung
%    [1x3]   double    w_RWseed              ....... Initialisierungswert
%                                                    für Random Walk bei 
%                                                    Winkelgeschwindigkeit
%    [1x3]   double    w_WNseed              ....... Initialisierungswert
%                                                    für weißes Rauschen 
%                                                    bei Winkelgeschwindigkeit
%    [1x1]   double    imu_NoOfDelaySamples  ....... Anzahl der Verzöge-
%                                                    rungsabtastungen
% 
% ZUSAMMENFASSUNG: 
% Dieses Skript wird von dem IMU-Modell aufgerufen und initialisiert das
% Modell mit den in der Eingabemaske des Modells übergebenen Parametern.
%
% BESCHREIBUNG: 
% Zur Initialisierung des ISim-IMU-Modells wird dieses Skript herangezogen.
% Dazu entnimmt es die in der Parametermaske des Modells eingegebenen Werte
% und prüft diese zunächst auf Gültigkeit. Anschließend werden daraus
% diejenigen Parameter ermittelt, welche für weitere Berechnungen im Modell
% benötigt werden.
%
% ABHÄNGIGKEITEN:
% -
%
% PROJEKT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% QUELLENANGABEN:
% -
%
% ÄNDERUNGSVERZEICHNIS
% Datum         Name                Beschreibung            Version
% 2016/11/10    Manfred Hinter      Initiale Version        V 1.0
% 2017/08/03    Florian Peter       Änderung an Mismatch-   V 1.1
%                                   Berechnung; Entfernung
%                                   von Strukturen
% 2019/04/02    Jakob Andres        Hinzufügung der flags   V 1.2
%                                   der Dynamik
%

%% Überprüfen der eingehenden Systemzustände
% Geteilte Parameter:
validateattributes(imu_Rate, {'numeric'}, {'positive','numel', 1}, '', 'Update step size', 1);
validateattributes(imu_dt_d, {'numeric'}, {'>=',0,'numel', 1}, '', 'Delay of Sensors', 2);
validateattributes(imu_random_seed, {'numeric'}, {'>',-2917239,'integer','numel', 1}, '', 'Random Seed', 3);
% Random Walk:
validateattributes(a_sigmanoise, {'numeric'}, {'vector','numel', 3}, '', 'White Noise (Random Walk) of Acceleration Sensors', 5);
validateattributes(w_sigmanoise, {'numeric'}, {'vector','numel', 3}, '', 'White Noise (Random Walk) of Gyroscope Sensors', 19);
% Quantisierung:
validateattributes(a_quantization, {'numeric'}, {'vector','numel', 1}, '', 'Quantization of Acceleration Sensors', 6);
validateattributes(w_quantization, {'numeric'}, {'vector','numel', 1}, '', 'Quantization of Gyroscope Sensors', 20);
%Bias:
validateattributes(a_bias_static, {'numeric'}, {'vector','numel', 3}, '', 'Static Bias of Acceleration Sensors', 7);
validateattributes(w_bias_static, {'numeric'}, {'vector','numel', 3}, '', 'Static Bias of Gyroscope Sensors', 21);
validateattributes(a_biasIR_sigma, {'numeric'}, {'vector','numel', 3}, '', 'Sigma of dynamic Bias of Acceleration Sensors', 8);
validateattributes(w_biasIR_sigma, {'numeric'}, {'vector','numel', 3}, '', 'Sigma of dynamic Bias of Gyroscope Sensors', 22);
validateattributes(a_biasIR_timeconstant, {'numeric'}, {'vector','numel', 1}, '', 'theta of dynamic Bias of Acceleration Sensors', 9);
validateattributes(w_biasIR_timeconstant, {'numeric'}, {'vector','numel', 1}, '', 'theta of dynamic Bias of Gyroscope Sensors', 23);
% Sättigung:
if(length(a_limits)~=1)
    validateattributes(a_limits, {'numeric'}, {'vector','numel', 3}, '', 'Saturation of Acceleration Sensors', 4);
end
if(length(w_limits)~=1)
    validateattributes(w_limits, {'numeric'}, {'vector','numel', 3}, '', 'Saturation of Gyroscope Sensors', 18);
end
% Skalierung:
if(length(a_SF)~=1) 
    validateattributes(a_SF, {'numeric'}, {'vector','numel', 3}, '', 'linear Scalar Factor of Acceleration Sensors', 12);
end
if(length(a_SFA)~=1) 
validateattributes(a_SFA, {'numeric'}, {'vector','numel', 3}, '', 'asymmetric Scalar Factor of Acceleration Sensors', 14);
end
if(length(a_SFN)~=1) 
    validateattributes(a_SFN, {'numeric'}, {'vector','numel', 3}, '', 'quadratic Scalar Factor of Acceleration Sensors', 13);
end
if(length(w_SF)~=1) 
    validateattributes(w_SF, {'numeric'}, {'vector','numel', 3}, '', 'linear Scalar Factor of Gyroscope Sensors', 27);
end
if(length(w_SFA)~=1) 
    validateattributes(w_SFA, {'numeric'}, {'vector','numel', 3}, '', 'asymmetric Scalar Factor of Gyroscope Sensors', 29);
end
if(length(w_SFN)~=1) 
    validateattributes(w_SFN, {'numeric'}, {'vector','numel', 3}, '', 'quadratic Scalar Factor of Gyroscope Sensors', 28);
end
validateattributes(a_CC, {'numeric'}, {'vector','numel', 3}, '', 'Cross Correlation of Acceleration Sensors', 17);
validateattributes(w_CC, {'numeric'}, {'vector','numel', 3}, '', 'Cross Correlation of Gyroscope Sensors', 32);
validateattributes(w_Gg, {'numeric'}, {'size', [3 3]}, '', 'Acceleration Effect on Gyroscope Sensors', 24);
% Ausrichtungsfehler:
validateattributes(a_orth, {'numeric'}, {'vector','numel', 3}, '', 'Orthogonal Misalignment of Acceleration Sensors', 16);
validateattributes(w_orth, {'numeric'}, {'vector','numel', 3}, '', 'Orthogonal Misalignment of Gyroscope Sensors', 31);
validateattributes(a_mis, {'numeric'}, {'vector','numel', 3}, '', 'Angular Misalignment of Acceleration Sensors', 15);
validateattributes(w_mis, {'numeric'}, {'vector','numel', 3}, '', 'Angular Misalignment of Gyroscope Sensors', 30);
% Dynamik:
if(length(a_omega)~=1)
    validateattributes(a_omega, {'numeric'}, {'vector','numel', 3}, '', 'Dynamics Frequenzy of Acceleration Sensors', 10);
end
if(length(w_omega)~=1)
validateattributes(w_omega, {'numeric'}, {'vector','numel', 3}, '', 'Dynamics Frequenzy of Gyroscope Sensors', 25);
end
if(length(a_damping)~=1)
    validateattributes(a_damping, {'numeric'}, {'vector','numel', 3}, '', 'Dynamics Damping of Acceleration Sensors', 11);
end
if(length(w_damping)~=1)
    validateattributes(w_damping, {'numeric'}, {'vector','numel', 3}, '', 'Dynamics Damping of Gyroscope Sensors', 26);
end
validateattributes(a_flag_dyn, {'numeric'}, {'vector','numel', 1}, '', 'Flag for Usage of Acceleration Sensor dynamics', 33);
validateattributes(w_flag_dyn, {'numeric'}, {'vector','numel', 1}, '', 'Flag for Usage of Gyroscope Sensor dynamics', 34);
% 

%% Skalierung:
% Umrechnung von [ppm] in []
a_SF    = a_SF/1e6;
a_SFA   = a_SFA/1e6;
a_SFN   = a_SFN/1e6;
w_SF    = w_SF/1e6;
w_SFA   = w_SFA/1e6;
w_SFN   = w_SFN/1e6;

%% Sättigung:
a_limits = abs(a_limits);
w_limits = abs(a_limits);

%% Ausrichtungsfehler und Nichtorthogonalität:
% Beschleunigung:
a_orth      = -a_orth/2;
t1          = tan(a_orth(1));
t2          = tan(a_orth(2));
t3          = tan(a_orth(3));
A_orth      = [ 1,  t3,  t2; ...
                t3, 1,  t1; ...
                t2,  t1,  1];
A_orth(:,1) = A_orth(:,1)/norm(A_orth(:,1));
A_orth(:,2) = A_orth(:,2)/norm(A_orth(:,2));
A_orth(:,3) = A_orth(:,3)/norm(A_orth(:,3));

c1          = cos(a_mis(1));
c2          = cos(a_mis(2));
c3          = cos(a_mis(3));
s1          = sin(a_mis(1));
s2          = sin(a_mis(2));
s3          = sin(a_mis(3));

a_MisMat_tmp    =  [ c3*c2, s3*c2, -s2;...
                    -s3*c1+c3*s2*s1, c3*c1+s1*s2*s3, s1*c2;...
                    s1*s2+c3*s2*c1, -c3*s1+s1*s2*s3, c1*c2];
a_MisMat        =  a_MisMat_tmp*A_orth;

% Rotation:
w_orth=-w_orth/2;
t1 = tan(w_orth(1));
t2 = tan(w_orth(2));
t3 = tan(w_orth(3));
A_orth = [1,  t3,  t2; ...
           t3, 1,  t1; ...
           t2,  t1,  1];
A_orth(:,1) = A_orth(:,1)/norm(A_orth(:,1));
A_orth(:,2) = A_orth(:,2)/norm(A_orth(:,2));
A_orth(:,3) = A_orth(:,3)/norm(A_orth(:,3));

c1          = cos(w_mis(1));
c2          = cos(w_mis(2));
c3          = cos(w_mis(3));
s1          = sin(w_mis(1));
s2          = sin(w_mis(2));
s3          = sin(w_mis(3));

w_MisMat_tmp    =  [ c3*c2, s3*c2, -s2;...
                    -s3*c1+c3*s2*s1, c3*c1+s1*s2*s3, s1*c2;...
                    s1*s2+c3*s2*c1, -c3*s1+s1*s2*s3, c1*c2];
w_MisMat        =  w_MisMat_tmp*A_orth;

%% Dynamik:
if length(a_omega)<3
    a_omega=ones(3,1)*a_omega(1);
end
if length(a_damping)<3
    a_damping=ones(3,1)*a_damping(1);
end
a_omega = reshape(a_omega,3,1);
a_damping = reshape(a_damping,3,1);

if length(w_omega)<3
    w_omega=ones(3,1)*w_omega(1);
end
if length(w_damping)<3
    w_damping=ones(3,1)*w_damping(1);
end
w_omega = reshape(w_omega,3,1);
w_damping = reshape(w_damping,3,1);

% Initialisierungswert für weißes Rauschen:
imu_random_seed = imu_random_seed+2917239;
a_RWseed    = [0, 1, 2]+3*imu_random_seed;
a_WNseed    = [0, 1, 2]+3*(imu_random_seed+1);
w_RWseed    = [0, 1, 2]+3*(imu_random_seed+2);
w_WNseed    = [0, 1, 2]+3*(imu_random_seed+3);

%% Verzögerung:
imu_NoOfDelaySamples = round(imu_dt_d/imu_dt);