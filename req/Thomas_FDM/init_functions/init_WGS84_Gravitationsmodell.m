%% Initialisierungsfunktion für das Simulink Gravitationsmodell WGS84
%
% EINGANG:    
%   -
%
% 
% AUSGABE: 
%    [1x1] c_rsma             .......... Große Halbachse der Erde nach
%                                        WGS84
%    [1x1] c_b_WGS            .......... Kleine Halbachse der Erde nach
%                                        WGS84
%    [1x1] c_grav             .......... Gravitationskonstante der Erde nach
%                                        WGS84
%    [1x1] c_rot              .......... Rotationsgeschwindigkeit der Erde
%                                        nach WGS84
%   
%   OPTIONAL:
% 
% ZUSAMMENFASSUNG: 
% Diese Funktion lädt die  Konstanten die für die korrekte
% Berechnung der Gravitation nach dem WGS84 Standard nötig sind.
%
% ABHAENGIGKEITEN:
%
% PROJEKT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% QUELLEN:
% Technical Report
% "Department of Defense World Geodetic System 1984", NIMA TR8350.2,
% Third Edition, Amendment 1 vom 3 Januar 2000 
%
% AENDERUNGSLOGBUCH:
% Datum          Name                Beschreibung         Version
% 06.10.2016     Philippe Petit      Initialverison       V 1.0

function [ c_rsma, c_b_WGS, c_grav, c_rot] = init_WGS84_Gravitationsmodell()

%Kleine und Große Halbachse des WGS84 Standards
c_rsma      = 6378137.0;
c_b_WGS     = 6356752.3142;
%Normalfallbeschleunigung der Erde sowie Rotationsgeschwindigkeit der Erde
%nach WGS84
c_grav = 3986004.418e8;
c_rot = 7292115.8553e-11;

end


