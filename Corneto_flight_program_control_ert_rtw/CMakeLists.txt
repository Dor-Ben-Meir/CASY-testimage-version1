## This cmakelist.txt file was generated from
## the UAV Toolbox Support Package for PX4 Autopilots

add_definitions(
-DMODEL=Corneto_flight_program_control -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DPX4 -DFMUv3 -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   MW_uORB_Read.cpp
   MW_uORB_Write.cpp
   MW_PX4_PWM.cpp
   MW_ParameterRead.cpp
   ert_main.cpp
   Corneto_flight_program_control.cpp
   Corneto_flight_program_control_data.cpp
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
   rt_zcfcn.cpp
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${PX4_SOURCE_DIR}/mavlink/include/mavlink
       /home/corneto/Desktop/FIles_from_Windows/HILsim/Mainframe
       /home/corneto/Documents/MATLAB/SupportPackages/R2021a/toolbox/target/supportpackages/px4/include
       /home/corneto/Desktop/FIles_from_Windows/HILsim/Mainframe/Corneto_flight_program_control_ert_rtw
       /usr/local/MATLAB/R2021a/extern/include
       /usr/local/MATLAB/R2021a/simulink/include
       /usr/local/MATLAB/R2021a/rtw/c/src
       /usr/local/MATLAB/R2021a/rtw/c/src/ext_mode/common
       /usr/local/MATLAB/R2021a/rtw/c/ert
       /usr/local/MATLAB/R2021a/rtw/c/src/ext_mode/serial
       /home/corneto/Documents/MATLAB/SupportPackages/R2021a/toolbox/target/shared/externalmode_daemon/include
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

