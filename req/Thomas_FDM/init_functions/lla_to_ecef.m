%% LLA to ECEF coordinate representation
%
% INPUTS:    
%    3xN    double   pos_lla (lon, lat, alt) .. position in lla coordinates
%
% OUTPUTS:   
%    3xN    double   pos_ecef    .............. position in ecef coordinates
%
% ABSTRACT: 
% Transformation of LLA  coordinates to ECEF frame 
%
% DESCRIPTION: 
% This function transforms geodetic position representation as
% Longitude, Latitude, Altitude or short LLA to ECEF coordinates
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2017/09/21    M. Ger              initial version     V 1.0
% 2019/10/11    F. Peter, MBDA      Änderung Reihen-
%                                   folge lla           V 1.1

%% 
function pPEE = lla_to_ecef(pos_lla)

R0 = 6378137;           % Equatorial Radiaus 
Rp = 6356752.31425;     % Polar Radius
f  = (R0-Rp)/R0;        % Flattering
e  = sqrt(1-Rp^2/R0^2); % Eccentricity

lon = pos_lla(1,:);
lat = pos_lla(2,:);
h   = pos_lla(3,:);

Re  = R0./sqrt(1 - e^2* sin(lat).^2);

xe  = (Re + h).*cos(lat).*cos(lon);
ye  = (Re + h).*cos(lat).*sin(lon);
ze  = ((1 - e^2).* Re + h).*sin(lat);

pPEE = [xe', ye', ze']';
