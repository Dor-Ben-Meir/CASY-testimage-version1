## This cmakelist.txt file was generated from
## the UAVToolbox Support Package for PX4 Autopilots

add_definitions(
-DMODEL=px4log -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DPX4 -DFMUv3 -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DMW_SD_STATIC_MEMORY_ENABLE -DMW_SD_VERBOSE_DISABLE=1 -DMW_SD_STATIC_MEMORY_SIZE=16392 )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   MW_uORB_Read.cpp
   MW_PX4_PWM.cpp
   ert_main.cpp
   px4log.cpp
   px4log_data.cpp
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
   rt_zcfcn.cpp
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
   MW_PX4_rtiostream_serial.cpp
   rtiostream_interface.c
   ext_svr_daemon.c
   daemon_checksum.c
   ert_targets_logging.c
   px4_file_logging.cpp
   MW_uORB_Read.h
   MW_PX4_PWM.h
   rtGetInf.h
   rtGetNaN.h
   rt_defines.h
   rt_nonfinite.h
   rt_zcfcn.h
   MW_custom_RTOS_header.h
   builtin_typeid_types.h
   multiword_types.h
   px4log.h
   px4log_private.h
   px4log_types.h
   rtmodel.h
   rtwtypes.h
   zero_crossing_types.h
   MW_uORB_busstruct_conversion.h
   dt_info.h
   ext_share.h
   ext_svr_transport.h
   ext_test.h
   ext_types.h
   updown.h
   updown_util.h
   upsup_public.h
   rt_logging.h
   rt_mxclassid.h
   rtw_continuous.h
   rtw_extmode.h
   rtw_matlogging.h
   rtw_solver.h
   sl_types_def.h
   solver_zc.h
   daemon_checksum.h
   daemon_checksum_prereq.h
   ert_targets_logging.h
   MW_PX4_TaskControl.h
   MW_uORB_Init.h
   nuttxinitialize.h
   MW_target_hardware_resources.h
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/px4_simulink_app
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${PX4_SOURCE_DIR}/mavlink/include/mavlink
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

