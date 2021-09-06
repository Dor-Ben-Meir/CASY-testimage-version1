#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_px4_msgs_OffboardControlMode and px4_msgs::msg::OffboardControlMode

void convertFromBus(px4_msgs::msg::OffboardControlMode& msgPtr, SL_Bus_px4_msgs_OffboardControlMode const* busPtr)
{
  const std::string rosMessageType("px4_msgs/OffboardControlMode");

  msgPtr.acceleration =  busPtr->acceleration;
  msgPtr.attitude =  busPtr->attitude;
  msgPtr.body_rate =  busPtr->body_rate;
  msgPtr.position =  busPtr->position;
  msgPtr.timestamp = (uint64_t) busPtr->timestamp;
  msgPtr.velocity =  busPtr->velocity;
}

void convertToBus(SL_Bus_px4_msgs_OffboardControlMode* busPtr, const px4_msgs::msg::OffboardControlMode& msgPtr)
{
  const std::string rosMessageType("px4_msgs/OffboardControlMode");

  busPtr->acceleration =  msgPtr.acceleration;
  busPtr->attitude =  msgPtr.attitude;
  busPtr->body_rate =  msgPtr.body_rate;
  busPtr->position =  msgPtr.position;
  busPtr->timestamp = (real_T) msgPtr.timestamp;
  busPtr->velocity =  msgPtr.velocity;
}


// Conversions between SL_Bus_px4_msgs_SensorCombined and px4_msgs::msg::SensorCombined

void convertFromBus(px4_msgs::msg::SensorCombined& msgPtr, SL_Bus_px4_msgs_SensorCombined const* busPtr)
{
  const std::string rosMessageType("px4_msgs/SensorCombined");

  msgPtr.accelerometer_clipping =  busPtr->accelerometer_clipping;
  msgPtr.accelerometer_integral_dt =  busPtr->accelerometer_integral_dt;
  convertFromBusFixedPrimitiveArray(msgPtr.accelerometer_m_s2, busPtr->accelerometer_m_s2);
  msgPtr.accelerometer_timestamp_relative =  busPtr->accelerometer_timestamp_relative;
  msgPtr.gyro_integral_dt =  busPtr->gyro_integral_dt;
  convertFromBusFixedPrimitiveArray(msgPtr.gyro_rad, busPtr->gyro_rad);
  msgPtr.timestamp = (uint64_t) busPtr->timestamp;
}

void convertToBus(SL_Bus_px4_msgs_SensorCombined* busPtr, const px4_msgs::msg::SensorCombined& msgPtr)
{
  const std::string rosMessageType("px4_msgs/SensorCombined");

  busPtr->accelerometer_clipping =  msgPtr.accelerometer_clipping;
  busPtr->accelerometer_integral_dt =  msgPtr.accelerometer_integral_dt;
  convertToBusFixedPrimitiveArray(busPtr->accelerometer_m_s2, msgPtr.accelerometer_m_s2, slros::NoopWarning());
  busPtr->accelerometer_timestamp_relative =  msgPtr.accelerometer_timestamp_relative;
  busPtr->gyro_integral_dt =  msgPtr.gyro_integral_dt;
  convertToBusFixedPrimitiveArray(busPtr->gyro_rad, msgPtr.gyro_rad, slros::NoopWarning());
  busPtr->timestamp = (real_T) msgPtr.timestamp;
}

