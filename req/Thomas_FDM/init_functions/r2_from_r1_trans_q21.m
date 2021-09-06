%% Transforms a vector from ref_1 to ref_2 via the corresponding quaternion.
%
% INPUTS:    
%   MANDATORY:
%    3x1    double   r1          ....... input vector in ref_1
%    4x1    double   q12         ....... quaternion from ref_1 to ref_2
%    
% OUTPUTS:   
%    3x1    double   r2          ....... transformed vector in ref_2
%
% ABSTRACT: 
% This function transforms a vector in ref_1 into the vector in ref_2 with
% the corresponding quaternion
%
% DESCRIPTION: 
% This function transforms a vector in ref_1 into the vector in ref_2 with
% the corresponding quaternion
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2019/03/07    T. Lausenhammer     initial version     V 1.0 

%% 
function r2 = r2_from_r1_trans_q21(r1,q21)

r2 = zeros(3,1);

r2(1) = (q21(4)^2 + q21(1)^2 - q21(2)^2 - q21(3)^2)*r1(1) + ...
        2*(q21(1)*q21(2) + q21(4)*q21(3))*r1(2) + ...
        2*(q21(1)*q21(3) - q21(4)*q21(2))*r1(3);

r2(2) = 2*(q21(1)*q21(2) - q21(4)*q21(3))*r1(1) + ...
        (q21(4)^2 - q21(1)^2 + q21(2)^2 - q21(3)^2)*r1(2) + ...
        2*(q21(4)*q21(1) + q21(2)*q21(3))*r1(3);

r2(3) = 2*(q21(1)*q21(3) + q21(4)*q21(2))*r1(1) + ...
        2*(q21(2)*q21(3) - q21(4)*q21(1))*r1(2) + ...
        (q21(4)^2 - q21(1)^2 - q21(2)^2 + q21(3)^2)*r1(3);
end