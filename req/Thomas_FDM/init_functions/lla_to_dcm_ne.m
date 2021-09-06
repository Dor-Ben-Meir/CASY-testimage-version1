%% LLA position to Rne dcm matrix
%
% INPUTS:    
%    3x1    double   pos_lla (lon, lat, alt) .. position in lla coordinates
%    or 
%    1x3    double   pos_lla     .............. position in lla coordinates
%
% OUTPUTS:   
%    3x3    double   TGE         .............. dcm from ECEF frame to NED frame
%
% ABSTRACT: 
% Transformation of LLA  coordinates to Rne 
%
% DESCRIPTION: 
% This function transforms geodetic position representation as
% Longitude, Latitude, Altitude or short LLA to direction cosine 
% matrix Rne standing for transformation from ECEF frame to NED 
% frame
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2017/09/21    M. Ger, MBDA        Initiale Version    V 1.0
% 2019/02/20    F. Peter, MBDA      Änderungen an 
%                                   Nomenklatur         V 1.1
% 2019/10/11    F. Peter, MBDA      Änderung Reihen-
%                                   folge lla           V 1.2

%% 
function TGE = lla_to_dcm_ne (pos_lla)

lon = pos_lla(1); 
lat = pos_lla(2); 

sla = sin(lat); 
cla = cos(lat);
slo = sin(lon); 
clo = cos(lon);

TGE = [ -sla*clo, -sla*slo, cla ;
            -slo,      clo,   0 ;
        -cla*clo, -cla*slo -sla];