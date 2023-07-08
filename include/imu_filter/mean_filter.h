#ifndef MEAN_FILTER
#define MEAN_FILTER

#include <ros/ros.h>
#include <fstream>
#include "sensor_msgs/Imu.h"
#include "Eigen/Dense"

class mean_filter
{
private:
    Eigen::MatrixXd A; //系统状态矩阵
 
    bool isinitized = false; //判断是否进行了初始化
 
public:
    mean_filter(int win_size);
    bool mean_output( Eigen::MatrixXd x);
    ~mean_filter();
};

#endif 