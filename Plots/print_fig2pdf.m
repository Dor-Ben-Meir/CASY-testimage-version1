function print_fig2pdf(figureHandle,name)
% PRINT_FIG2PDF saves the desired figure in .pdf format fitting the paper
% size to the size of the figure
% 
% Author: Gleb Merkulov, Technion, Faculty of Aerospace Engineering
% Date: 24/10/2020
%
% Inputs:
%   - figureHandle: a reference to figure object (typicaly, gcf)
%   - name: full name of the file including path
% Outputs:
%   void
%
% Usage example:
%   figure(1) % figure selection to use 'gcf'
%   print_fig2pdf(gcf,'_Figures\Approx_accuracy\errors')
%
% Changelog:
%   08/11/20 - deleted '-fillpage' option to minimize the white margins

set(figureHandle,'Units','inches');
screenposition = get(figureHandle,'Position');
set(figureHandle,'PaperPosition',[0 0 screenposition(3:4)],...
        'PaperSize',[screenposition(3:4)]);
print(name,'-dpdf')
end

