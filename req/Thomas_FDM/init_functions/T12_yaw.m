%% Transformationsmatrix um Gierachse
%
% EINGANG:    
%   NOTWENDIG:
%    [1x1]    double    ps_12   ....... Gierwinkel zwischen Ziel-KOS (1)
%                                       und Ausgangs-KOS (2)
%    
%   OPTIONAL:
%    -
% 
% AUSGABE:   
%    [3x3]    double    T12   ......... Transformationsmatrix um Gierachse
%
%   OPTIONAL:
%    -
% 
% ZUSAMMENFASSUNG: 
% Berechnung der Transformationsmatrix um Gierachse.
%
% BESCHREIBUNG: 
% siehe oben.
%
% ABHÄNGIGKEITEN:
% - 
%
% PROJEKT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% QUELLENANGABEN:
% Luftfahrtnorm LN 9300
%
% ÄNDERUNGSVERZEICHNIS
% Datum         Name                Beschreibung        Version
% 2016/09/22    Florian Peter       Initiale Version    V 1.0

%%
function T12 = T12_yaw(ps_12)
%#codegen

T12 =  [ cos(ps_12),   sin(ps_12),    0;...
        -sin(ps_12),   cos(ps_12),    0;...
              0    ,     0       ,    1];
end

