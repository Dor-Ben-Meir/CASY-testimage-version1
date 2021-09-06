cmake_minimum_required(VERSION 3.5)
project(ros2expiremnt2)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
add_compile_options(-DMODEL=ROS2expiremnt2 -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DROS2_PROJECT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT=RT )
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package( px4_msgs REQUIRED)
find_package( rclcpp REQUIRED)
include_directories("include/ros2expiremnt2")
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
# Node
add_executable(ROS2expiremnt2 
src/ext_svr.c
src/rtiostream_interface.c
src/rtiostream_tcpip.c
src/ROS2expiremnt2.cpp
src/ROS2expiremnt2_data.cpp
src/main.cpp
src/ros2nodeinterface.cpp
src/slros_busmsg_conversion.cpp
)
ament_target_dependencies(
  ROS2expiremnt2
  "px4_msgs"
  "rclcpp"
)
target_include_directories(ROS2expiremnt2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(ROS2expiremnt2 
	${CMAKE_DL_LIBS}
    )
install(TARGETS ROS2expiremnt2
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
ament_export_include_directories(
  include
)
ament_package()
# Generated 18-May-2021 11:55:28
# Copyright 2019-2020 The MathWorks, Inc.
