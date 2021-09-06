%% Computes the Julian Date out of the Gregorian Date
%
% INPUTS:    
%   MANDATORY:
%    1    double   year        ....... Gregorian date: year
%    1    double   month       ....... Gregorian date: month
%    1    double   day         ....... Gregorian date: day
%    1    double   hour        ....... Gregorian date: hour
%    1    double   minute      ....... Gregorian date: minute
%    1    double   second      ....... Gregorian date: second
%    
% OUTPUTS:   
%    1    double   julian_date ....... Julian Date
%
% ABSTRACT: 
% This function transforms a Gregorian Date into the corresponding Julian 
% date
%
% DESCRIPTION: 
% This function transforms a Gregorian Date into the corresponding Julian 
% date
%
% PROJECT:
%        ***  ISim - Generic Interceptor Simulation ***
%
% CHANGE LOG
% Date          Name                Description         Version
% 2015/06/10    T. Zöbelein         initial version     V 1.0 

%% 
function [julian_date] = comp_julian_date(year, month, day, hour, minute, second)
%#codegen

%Compjulian_date 
%  Computes the Julian Date out of the gregorian date

RefYear        = 1950;
RefDate_Julian = 2433282.5; % reference epoch: 01/01/1950, 0GMT
DaysPerMonth = [ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ];

%calculate julian date since reference epoch for all previous years

Date_Julian = RefDate_Julian;

if ( year > RefYear )
  for ActYear=RefYear:(year-1)
    % increase by normal number of days per year
    Date_Julian = Date_Julian + 365.0;
    % if actual year is leap year, add one day
    if (((mod(ActYear,4) < 0.01) && (mod(ActYear,100) > 0.0001)) || (mod(ActYear,400) < 0.0001))
      Date_Julian = Date_Julian + 1.0;
    end
  end % end of: for
end % end of: if-then

%increase julian date by days since reference epoch for actual year

% check for leap year
if (((mod(year,4) < 0.01) && (mod(year,100) > 0.0001)) || (mod(year,400) < 0.0001))
  IsLeapYear = 1;
else
  IsLeapYear = 0;
end

%days since January 1st, note that January has index '0'
for ActMonth=1:(month - 1)
  Date_Julian = Date_Julian + DaysPerMonth(ActMonth);
  % febuary is a special month in case of leap years...
  if ( ActMonth == 2 )
    if (IsLeapYear == 1)
      Date_Julian = Date_Julian + 1.0;
    end
  end
end % end of: for

Date_Julian = Date_Julian + (day - 1);
time=(hour+(minute+second/60)/60)/24;

julian_date=Date_Julian+time;

end
    
    
    