// Copyright 2019-2021 The MathWorks, Inc.
// Generated 18-May-2021 11:55:19
#ifndef _ROS2_MATLAB_NODEINTERFACE_
#define _ROS2_MATLAB_NODEINTERFACE_
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "rtwtypes.h"
#include "ROS2expiremnt2_types.h"
#include "slros_busmsg_conversion.h"
#include "px4_msgs/msg/offboard_control_mode.hpp"
#include "px4_msgs/msg/sensor_combined.hpp"
namespace ros2 {
namespace matlab {
  //Semaphore using std::CV and std::mutex
  class Semaphore {
  public:
    std::mutex mMutex;
    std::condition_variable mCV;
    std::atomic_uint mCount;
    //
    Semaphore(int count = 0)
      : mCount(count) {
      }
    //
    inline void notify() {
      std::unique_lock<std::mutex> lock(mMutex);
      mCount++;
      mCV.notify_all();
    }
    //
    inline void wait() {
      std::unique_lock<std::mutex> lock(mMutex);
      while (mCount == 0) {
        mCV.wait(lock);
      }
      if (mCount)
        mCount--;
    }
  };
  //NodeInterface
  class NodeInterface {
    NodeInterface(const NodeInterface& );
    NodeInterface& operator=(const NodeInterface& );
    //
    rclcpp::Node::SharedPtr mNode;
    rclcpp::executors::MultiThreadedExecutor::SharedPtr mExec;
    //
    Semaphore mBaseRateSem;
    std::shared_ptr<std::thread> mBaseRateThread;
    std::shared_ptr<std::thread> mSchedulerThread;
    //
    //
    Semaphore mStopSem;
    volatile boolean_T mRunModel;
    //
    // ROS2expiremnt2/Publish
    rclcpp::Publisher<px4_msgs::msg::OffboardControlMode>::SharedPtr mPub_ROS2expiremnt2_14;
    //
    // ROS2expiremnt2/Subscribe
    rclcpp::Subscription<px4_msgs::msg::SensorCombined>::SharedPtr mSub_ROS2expiremnt2_1;
    px4_msgs::msg::SensorCombined::SharedPtr mLatestMsg_Sub_ROS2expiremnt2_1;
    std::mutex mtx_Sub_ROS2expiremnt2_1;
  public:
    NodeInterface();
    ~NodeInterface();
    //
    void initialize(int argc, char * const argv[]);
    int run();
    void stop(void);
    void terminate(void);
    //
    boolean_T getStopRequestedFlag(void);
    void schedulerThreadCallback(void);
    void baseRateTask(void);
    // ROS2expiremnt2/Publish
    void create_Pub_ROS2expiremnt2_14(const char *topicName, const rmw_qos_profile_t& qosProfile);
    void publish_Pub_ROS2expiremnt2_14(const SL_Bus_px4_msgs_OffboardControlMode* inBus);
    // ROS2expiremnt2/Subscribe
    void create_Sub_ROS2expiremnt2_1(const char *topicName, const rmw_qos_profile_t& qosProfile);
    bool getLatestMessage_Sub_ROS2expiremnt2_1(SL_Bus_px4_msgs_SensorCombined* outBus);
    //
    rclcpp::Node::SharedPtr getNode() {
      return mNode;
    }
  }; //class NodeInterface
  //
  std::shared_ptr<ros2::matlab::NodeInterface> getNodeInterface();
  // Helper for ROS2expiremnt2/Publish
  void create_Pub_ROS2expiremnt2_14(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  void publish_Pub_ROS2expiremnt2_14(const SL_Bus_px4_msgs_OffboardControlMode* inBus);
  // Helper for ROS2expiremnt2/Subscribe
  void create_Sub_ROS2expiremnt2_1(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  bool getLatestMessage_Sub_ROS2expiremnt2_1(SL_Bus_px4_msgs_SensorCombined* outBus);
  // Get QoS Settings from RMW
  inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
      rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
      if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
          qos.transient_local();
      } else {
          qos.durability_volatile();
      }
      if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
          qos.reliable();
      } else {
          qos.best_effort();
      }
      return qos;
  }
}//namespace matlab
}//namespace ros2
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
#endif //_ROS2_MATLAB_ROS2CGEN_MULTIRATE_
