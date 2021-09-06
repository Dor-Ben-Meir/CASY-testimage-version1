#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/debug_vect.h>
#include <uORB/topics/mavlink_log.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct debug_vect_s  px4_Bus_debug_vect ;
typedef struct mavlink_log_s  px4_Bus_mavlink_log ;
typedef struct sensor_accel_s  px4_Bus_sensor_accel ;
typedef struct sensor_gyro_s  px4_Bus_sensor_gyro ;
typedef struct vehicle_gps_position_s  px4_Bus_vehicle_gps_position ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
