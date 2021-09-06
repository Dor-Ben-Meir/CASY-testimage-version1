#ifndef PX4_MSGS__VISIBILITY_CONTROL_H_
#define PX4_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PX4_MSGS_EXPORT __attribute__ ((dllexport))
    #define PX4_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define PX4_MSGS_EXPORT __declspec(dllexport)
    #define PX4_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef PX4_MSGS_BUILDING_LIBRARY
    #define PX4_MSGS_PUBLIC PX4_MSGS_EXPORT
  #else
    #define PX4_MSGS_PUBLIC PX4_MSGS_IMPORT
  #endif
  #define PX4_MSGS_PUBLIC_TYPE PX4_MSGS_PUBLIC
  #define PX4_MSGS_LOCAL
#else
  #define PX4_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define PX4_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define PX4_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define PX4_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PX4_MSGS_PUBLIC
    #define PX4_MSGS_LOCAL
  #endif
  #define PX4_MSGS_PUBLIC_TYPE
#endif
#endif  // PX4_MSGS__VISIBILITY_CONTROL_H_
// Generated 18-May-2021 11:55:28
 