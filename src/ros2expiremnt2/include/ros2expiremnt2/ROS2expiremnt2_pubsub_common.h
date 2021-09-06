// Copyright 2019 The MathWorks, Inc.
// Generated 18-May-2021 11:55:18
#ifndef _ROS2EXPIREMNT2_PUBSUB_COMMON_
#define _ROS2EXPIREMNT2_PUBSUB_COMMON_
#include "ROS2expiremnt2_types.h"
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
namespace ros2 {
    namespace matlab {
        // ROS2expiremnt2/Publish
        extern void create_Pub_ROS2expiremnt2_14(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern void publish_Pub_ROS2expiremnt2_14(const SL_Bus_px4_msgs_OffboardControlMode* inBus);
        // ROS2expiremnt2/Subscribe
        extern void create_Sub_ROS2expiremnt2_1(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern bool getLatestMessage_Sub_ROS2expiremnt2_1(SL_Bus_px4_msgs_SensorCombined* outBus);
    }
}
#endif // _ROS2EXPIREMNT2_PUBSUB_COMMON_
