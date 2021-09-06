#ifndef ROS2EXPIREMNT2__VISIBILITY_CONTROL_H_
#define ROS2EXPIREMNT2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS2EXPIREMNT2_EXPORT __attribute__ ((dllexport))
    #define ROS2EXPIREMNT2_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS2EXPIREMNT2_EXPORT __declspec(dllexport)
    #define ROS2EXPIREMNT2_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS2EXPIREMNT2_BUILDING_LIBRARY
    #define ROS2EXPIREMNT2_PUBLIC ROS2EXPIREMNT2_EXPORT
  #else
    #define ROS2EXPIREMNT2_PUBLIC ROS2EXPIREMNT2_IMPORT
  #endif
  #define ROS2EXPIREMNT2_PUBLIC_TYPE ROS2EXPIREMNT2_PUBLIC
  #define ROS2EXPIREMNT2_LOCAL
#else
  #define ROS2EXPIREMNT2_EXPORT __attribute__ ((visibility("default")))
  #define ROS2EXPIREMNT2_IMPORT
  #if __GNUC__ >= 4
    #define ROS2EXPIREMNT2_PUBLIC __attribute__ ((visibility("default")))
    #define ROS2EXPIREMNT2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS2EXPIREMNT2_PUBLIC
    #define ROS2EXPIREMNT2_LOCAL
  #endif
  #define ROS2EXPIREMNT2_PUBLIC_TYPE
#endif
#endif  // ROS2EXPIREMNT2__VISIBILITY_CONTROL_H_
// Generated 18-May-2021 11:55:28
 