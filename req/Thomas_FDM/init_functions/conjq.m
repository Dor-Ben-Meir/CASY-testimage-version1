%% Computes the conjugate complex quaternion
%
% INPUTS:    
%   MANDATORY:
%    4x1    double   q           ....... quaternion
%    
% OUTPUTS:   
%    4x1    double   q_conj      ....... conjugated quaternion
%
% ABSTRACT: 
% This function computes teh conjugate complex quaternion
%
% DESCRIPTION: 
% This function computes teh conjugate complex quaternion
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2015/06/10    T. Zöbelein         initial version     V 1.0 

%% 
function q_conj = conjq(q)
%#codegen

  q_conj    = -q;
  q_conj(4) =  q(4);

end


