landscape = true;
h =  findobj('type','figure');
n = length(h);
if n==0
    disp("Nothing to print");
    return
end
if landscape
    L = 750;
else
    L = 500;
end

for i = 1:n
    figure(i);
    set(gcf, 'Position',  [0, 500, L, 200])
    h1=get(gca,'title');
    str=get(h1,'string');
    str = regexprep(str,'[^a-zA-Z]','');
    str(~ismember(str,['A':'Z' 'a':'z'])) = '';
    str(~ismember(double(str),[65:90 97:122])) = '';  
    exportgraphics(gcf,['plots/',str,'.png'],'BackgroundColor','white')
end
