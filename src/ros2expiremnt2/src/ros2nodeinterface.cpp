// Copyright 2019-2021 The MathWorks, Inc.
// Generated 18-May-2021 11:55:20
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "ROS2expiremnt2.h"
#include "ros2nodeinterface.h"
#include <thread>
#include <chrono>
#include <utility>
const std::string SLROSNodeName("ROS2expiremnt2");
namespace ros2 {
namespace matlab {
NodeInterface::NodeInterface()
    : mNode()
    , mExec()
    , mBaseRateSem()
    , mBaseRateThread()
    , mSchedulerThread()
    , mStopSem()
    , mRunModel(true){
  }
NodeInterface::~NodeInterface() {
    terminate();
  }
void NodeInterface::initialize(int argc, char * const argv[]) {
    try {
        //initialize ros2
        // Workaround to disable /rosout topic until rmw_fastrtps supports
        // multiple typesupport implementations for the same topic (https://github.com/ros2/rmw_fastrtps/issues/265)
        std::vector<char *> args(argv, argv + argc);
        char log_disable_rosout[] = "__log_disable_rosout:=true";
        args.push_back(log_disable_rosout);
        rclcpp::init(static_cast<int>(args.size()), args.data());
        //create the Node specified in Model
        std::string NodeName("ROS2expiremnt2");
        mNode = std::make_shared<rclcpp::Node>(NodeName);
        mExec = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
        mExec->add_node(mNode);
        //initialize the model which will initialize the publishers and subscribers
		rtmSetErrorStatus(ROS2expiremnt2_M, (NULL));
        ROS2expiremnt2_initialize();
        //create the threads for the rates in the Model
        mBaseRateThread = std::make_shared<std::thread>(&NodeInterface::baseRateTask, this);
		mSchedulerThread = std::make_shared<std::thread>(&NodeInterface::schedulerThreadCallback, this);
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
        throw;
    }
}
int NodeInterface::run() {
  if (mExec) {
    mExec->spin();
  }
  mRunModel = false;
  return 0;
}
boolean_T NodeInterface::getStopRequestedFlag(void) {
    #ifndef rtmGetStopRequested
    return (!(rtmGetErrorStatus(ROS2expiremnt2_M) 
        == (NULL)));
    #else
    return (!(rtmGetErrorStatus(ROS2expiremnt2_M) 
        == (NULL)) || rtmGetStopRequested(ROS2expiremnt2_M));
    #endif
}
void NodeInterface::stop(void) {
  if (mExec.get()) {
    mExec->cancel();
    if (mNode) {
      mExec->remove_node(mNode);
    }
    while (mExec.use_count() > 1);
  }
}
void NodeInterface::terminate(void) {
    if (mBaseRateThread.get()) {
        mBaseRateSem.notify();
        mBaseRateThread->join();
        mRunModel = false;
        mBaseRateThread.reset();
        if (mSchedulerThread.get()) {
            mSchedulerThread->join();
            mSchedulerThread.reset();
        }
        ROS2expiremnt2_terminate();
        // Release publisher ROS2expiremnt2/Publish
        mPub_ROS2expiremnt2_14.reset();
        // Release subscriber ROS2expiremnt2/Subscribe
        mSub_ROS2expiremnt2_1.reset();
        mExec.reset();
        mNode.reset();
        rclcpp::shutdown();
    }
}
// Scheduler thread that does the timer
void NodeInterface::schedulerThreadCallback(void)
{
  while (mRunModel) {
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(10000000));
        mBaseRateSem.notify();
    }
}
//Model specific
void NodeInterface::baseRateTask(void) {
  mRunModel = (rtmGetErrorStatus(ROS2expiremnt2_M) ==
              (NULL));
  while (mRunModel) {
    mBaseRateSem.wait();
    if (!mRunModel) break;
    ROS2expiremnt2_step();
    mRunModel = !NodeInterface::getStopRequestedFlag();
  }
  NodeInterface::stop();
}
// ROS2expiremnt2/Publish
void NodeInterface::create_Pub_ROS2expiremnt2_14(const char *topicName, const rmw_qos_profile_t& qosProfile){
  mPub_ROS2expiremnt2_14 = mNode->create_publisher<px4_msgs::msg::OffboardControlMode>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile));
}
void NodeInterface::publish_Pub_ROS2expiremnt2_14(const SL_Bus_px4_msgs_OffboardControlMode* inBus) {
  auto msg = std::make_unique<px4_msgs::msg::OffboardControlMode>();
  convertFromBus(*msg, inBus);
  mPub_ROS2expiremnt2_14->publish(std::move(msg));
}
// ROS2expiremnt2/Subscribe
void NodeInterface::create_Sub_ROS2expiremnt2_1(const char *topicName, const rmw_qos_profile_t& qosProfile){
    auto callback = [this](px4_msgs::msg::SensorCombined::SharedPtr msg) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_ROS2expiremnt2_1);
        mLatestMsg_Sub_ROS2expiremnt2_1 = msg;
    };
    mSub_ROS2expiremnt2_1 = mNode->create_subscription<px4_msgs::msg::SensorCombined>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile), callback);
}
bool NodeInterface::getLatestMessage_Sub_ROS2expiremnt2_1(SL_Bus_px4_msgs_SensorCombined* outBus) {
    if (mLatestMsg_Sub_ROS2expiremnt2_1.get()) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_ROS2expiremnt2_1);
        convertToBus(outBus, *mLatestMsg_Sub_ROS2expiremnt2_1);
        return true;
    }
    return false;
}
// Helper for ROS2expiremnt2/Publish
void create_Pub_ROS2expiremnt2_14(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Pub_ROS2expiremnt2_14(topicName, qosProfile);
}
void publish_Pub_ROS2expiremnt2_14(const SL_Bus_px4_msgs_OffboardControlMode* inBus) {
  ros2::matlab::getNodeInterface()->publish_Pub_ROS2expiremnt2_14(inBus);
}
// Helper for ROS2expiremnt2/Subscribe
void create_Sub_ROS2expiremnt2_1(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Sub_ROS2expiremnt2_1(topicName, qosProfile);
}
bool getLatestMessage_Sub_ROS2expiremnt2_1(SL_Bus_px4_msgs_SensorCombined* outBus) {
  return ros2::matlab::getNodeInterface()->getLatestMessage_Sub_ROS2expiremnt2_1(outBus);
}
}//namespace matlab
}//namespace ros2
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
