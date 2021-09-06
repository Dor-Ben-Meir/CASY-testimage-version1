%% Multiplication of two quaternions q_3_1=q_3_2*q_2_1.
%
% INPUTS:    
%   MANDATORY:
%    3x1    double   r1          ....... input vector in ref_1
%    4x1    double   q           ....... quaternion form ref_1 to ref_2
%    
% OUTPUTS:   
%    3x1    double   r2          ....... transformed vector in ref_2
%
% ABSTRACT: 
% This function multiplies two quaternions: q_3_1=q_3_2*q_2_1
%
% DESCRIPTION: 
% This function multiplies two quaternions: q_3_1=q_3_2*q_2_1
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2015/06/10    T. Zöbelein         initial version     V 1.0 

%% 
function q_3_1 = qumul(q_3_2,q_2_1)
%#codegen

q_3_1=zeros(4,1);

q_3_1(1)= +q_3_2(1)*q_2_1(4)+q_3_2(4)*q_2_1(1)-q_3_2(3)*q_2_1(2)+q_3_2(2)*q_2_1(3);
q_3_1(2)= +q_3_2(2)*q_2_1(4)+q_3_2(3)*q_2_1(1)+q_3_2(4)*q_2_1(2)-q_3_2(1)*q_2_1(3);
q_3_1(3)= +q_3_2(3)*q_2_1(4)-q_3_2(2)*q_2_1(1)+q_3_2(1)*q_2_1(2)+q_3_2(4)*q_2_1(3);
q_3_1(4)= +q_3_2(4)*q_2_1(4)-q_3_2(1)*q_2_1(1)-q_3_2(2)*q_2_1(2)-q_3_2(3)*q_2_1(3);

if (q_3_1(4)<0)
    q_3_1=-q_3_1;
end
q_3_1 = q_3_1/norm(q_3_1);

end


