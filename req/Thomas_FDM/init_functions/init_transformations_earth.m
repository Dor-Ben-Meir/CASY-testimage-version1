%% Initialisierungsfunktion für Transformationen, die Erdbarameter benötigen
%
% EINGANG:    
%   NOTWENDIG:
%
%   OPTIONAL:
% 
% AUSGABE: 
%    scalar double  c_mue ........... Erdgravitationskonstante
%    scalar double  c_rsma........... große Halbachse der Erde
%    scalar double  c_flat........... Erdabflachung
%   
%   OPTIONAL:
% 
% ZUSAMMENFASSUNG: 
% Die Funktion "init_transformations_earth" initialisiert die Simulink
% Transformationsblöcke mit den entsprechend benötigten Erdparametern.
%
% BESCHREIBUNG: 
% Die Funktion "init_transformations_earth" initialisiert die Simulink
% Transformationsblöcke mit den entsprechend benötigten Erdparametern.
%
% ABHAENGIGKEITEN:
%
% PROJEKT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% QUELLEN:
% --
%
% AENDERUNGSLOGBUCH:
% Datum          Name                Beschreibung         Version
% 21.10.2016     Till Zoebelein      Initialverison       V 1.0


function [c_mue, c_rsma, c_flat] = init_transformations_earth()

c_rsma=6378137 ; % [m]
c_flat=1/298.257223563; % [-]
c_mue=3.986004415e14;  % [m^3/s^2]

end