function FDM = init_FDM 
    init_grm;
    para_def_grm;
    save('req/Thomas_FDM/generated_FDM_params');
    if (exist('eulBG','var') == 0)
        disp("Initial attiude (eulBG) does not exist in FDM parameter files")
        return
    end
    FDM.euler(1) = eulBG(1);
    FDM.euler(2) = eulBG(2);
    FDM.euler(3) = eulBG(3);
    FDM.Tr4r3 = Tr4r3;
% ------- EOF -------%% 
