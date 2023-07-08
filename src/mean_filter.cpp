#include <ros/ros.h>
#include <fstream>
#include "sensor_msgs/Imu.h"
#include "Eigen/Dense"

#include "imu_filter/mean_filter.h"
 
double a_x; //x方向的加速度
double a_y; //y方向的加速度
double a_z; //z方向的加速度
 
using namespace std;
 
bool mean_filter::mean_output(Eigen::MatrixXd x)
{
    
    return true; // can publish
}


mean_filter::mean_filter(int win_size = 5)
{
    
    Eigen::MatrixXd AX = Eigen::MatrixXd(3,win_size); //创建一个3*n矩阵
    Eigen::MatrixXd WX = Eigen::MatrixXd(3,win_size); //创建一个3*n矩阵
    float a_nean;
    float w_nean;
}

mean_filter::~mean_filter(){}