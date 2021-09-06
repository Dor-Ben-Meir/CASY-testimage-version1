#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/sensor_combined.hpp>
#include "ROS2expiremnt2_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(px4_msgs::msg::OffboardControlMode& msgPtr, SL_Bus_px4_msgs_OffboardControlMode const* busPtr);
void convertToBus(SL_Bus_px4_msgs_OffboardControlMode* busPtr, const px4_msgs::msg::OffboardControlMode& msgPtr);

void convertFromBus(px4_msgs::msg::SensorCombined& msgPtr, SL_Bus_px4_msgs_SensorCombined const* busPtr);
void convertToBus(SL_Bus_px4_msgs_SensorCombined* busPtr, const px4_msgs::msg::SensorCombined& msgPtr);


#endif
