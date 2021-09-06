%% Computes the quaternion from the given rotation matrix.
%
% INPUTS:
%   MANDATORY:
%    3x3    double   T12         ....... rotation matrix
%
% OUTPUTS:
%    4x1    double   q12         ....... quaternion
%
% ABSTRACT:
% This function transforms a rotation matrix into a quaternion
%
% DESCRIPTION:
% This function transforms a rotation matrix, describing the
% passive rotation from coordinate system 2 to coordiante system 1 into a
% quaternion that describes the passive rotation from coordinate system
% 2 to coordinate system 1.
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% REFERENCES:
% DIEBEL, James. Representing attitude: Euler angles, unit quaternions,
% and rotation vectors. Matrix, 2006, 58. Jg., Nr. 15-16, S. 1-35.
%
% CHANGE LOG
% Date          Name                Description         Version
% 2019/03/07    T. Lausenhammer     initial version     V 1.0
% 2019/03/22    T. Lausenhammer     Bugfix SchreibfehlerV 1.1
% 2019/04/12    D. Paukner          Anpassen            V 1.2
%                                   Fallunterscheidung

%%
function q12 = q12_from_T12(T12)

q12=eye(4,1);

if T12(2,2)>= -T12(3,3) && T12(1,1) >= -T12(2,2) && T12(1,1) >= - T12(3,3)
    
    q12(4) = sqrt(1 + T12(1,1) + T12(2,2) + T12(3,3));
    q12(1) = (T12(2,3)-T12(3,2))/q12(4);
    q12(2) = (T12(3,1)-T12(1,3))/q12(4);
    q12(3) = (T12(1,2)-T12(2,1))/q12(4);
    
elseif T12(2,2)< -T12(3,3) && T12(1,1) >= T12(2,2) && T12(1,1) >= T12(3,3)
    q12(1) = sqrt(1 + T12(1,1) - T12(2,2) - T12(3,3));
    q12(2) = (T12(1,2)+T12(2,1))/q12(1);
    q12(3) = (T12(3,1)+T12(1,3))/q12(1);
    q12(4) = (T12(2,3)-T12(3,2))/q12(1);
    
elseif T12(2,2)>= T12(3,3) && T12(1,1) < T12(2,2) && T12(1,1) < -T12(3,3)
    q12(2) = sqrt(1 - T12(1,1) + T12(2,2) - T12(3,3));
    q12(1) = (T12(1,2) + T12(2,1))/q12(2);
    q12(3) = (T12(2,3) + T12(3,2))/q12(2);
    q12(4) = (T12(3,1) - T12(1,3))/q12(2);
    
elseif T12(2,2)< T12(3,3) && T12(1,1) < -T12(2,2) && T12(1,1) < T12(3,3)
    q12(3) = sqrt(1 - T12(1,1) - T12(2,2) + T12(3,3));
    q12(1) = (T12(3,1)+T12(1,3))/q12(3);
    q12(2) = (T12(2,3)+T12(3,2))/q12(3);
    q12(4) = (T12(1,2)-T12(2,1))/q12(3);
    
end

if (q12(4)<0)
    q12=-q12;
end
% Make sure quaternion is normalized
q12 = q12/norm(q12);

end