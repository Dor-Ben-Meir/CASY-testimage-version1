%% Computes the quaternion from a given set of Euler angles.
%
% INPUTS:    
%   MANDATORY:
%    3x1    double   eul         ....... Euler angles [rad]
%    
% OUTPUTS:   
%    4x1    double   q           ....... quaternion
%
% ABSTRACT: 
% This function transforms Euler angles into a quaternion 
%
% DESCRIPTION: 
% This function transforms Euler angles of the order 3-2-1 (z-y-x) into a 
% quaternion 
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2015/06/10    T. Zöbelein         initial version     V 1.0 

%% 
function q = euler_to_q(eul)
%#codegen

q  = zeros(4,1);

l1=cos(eul(3)/2)*cos(eul(2)/2);
l2=-sin(eul(3)/2)*sin(eul(2)/2);
l3= cos(eul(3)/2)*sin(eul(2)/2);
l4= sin(eul(3)/2)*cos(eul(2)/2);

q(4)=l1*cos(eul(1)/2)-l2*sin(eul(1)/2);
q(1)=l2*cos(eul(1)/2)+l1*sin(eul(1)/2);
q(2)=l3*cos(eul(1)/2)+l4*sin(eul(1)/2);
q(3)=l4*cos(eul(1)/2)-l3*sin(eul(1)/2);

q = q/norm(q);

end


