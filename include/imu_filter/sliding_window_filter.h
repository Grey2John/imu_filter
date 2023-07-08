#ifndef SILDING_WINDOW_FILTER
#define SILDING_WINDOW_FILTER

#include <ros/ros.h>
#include <fstream>
#include "sensor_msgs/Imu.h"
#include "Eigen/Dense"


class sliding_window_filter
{
private:
    /* data */
public:
    sliding_window_filter(/* args */);
    ~sliding_window_filter();
};

#endif 