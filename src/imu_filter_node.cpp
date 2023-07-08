#include <ros/ros.h>
#include <fstream>
#include "sensor_msgs/Imu.h"
#include "Eigen/Dense"

#include "imu_filter/imu_filter.h"
#include "imu_filter/mean_filter.h"
#include "imu_filter/sliding_window_filter.h"
 
double a_x; //x方向的加速度
double a_y; //y方向的加速度
double a_z; //z方向的加速度
 
Eigen::MatrixXd AX = Eigen::MatrixXd(3,1); //创建一个3*1矩阵
 
using namespace std;

void imumeanCallback(const sensor_msgs::Imu::ConstPtr& msg, ros::Publisher& IMU_pub)
{
    // 三个方向的线性加速度
    double ax = msg->linear_acceleration.x;
    double ay = msg->linear_acceleration.y;
    double az = msg->linear_acceleration.z;
    double wx = msg->angular_velocity.x;
    double wy = msg->angular_velocity.y;
    double wz = msg->angular_velocity.z;

    sensor_msgs::Imu M;
    M.header = msg->header;
    M.header.frame_id = "livox_imu";
    
    // filter process


    // publish value
    M.linear_acceleration.x = a_x;
    M.linear_acceleration.y = a_y;
    M.linear_acceleration.z = a_z;
    M.angular_velocity.x = a_x;
    M.angular_velocity.y = a_y;
    M.angular_velocity.z = a_z;
    IMU_pub.publish(M);
}


//接收IMU话题，通过卡尔曼滤波参数进行数据处理，然后发布处理后的数据作为一个话题。
int main(int argc, char **argv)
{
    ros::init(argc, argv, "imu_filter");
    ros::NodeHandle imu_node;

    imu_node.getParam("enable_neam_filter", enable_neam_filter);
    imu_node.getParam("enable_slide_filter", enable_slide_filter);
    imu_node.getParam("win_size", win_size);
    ros::Subscriber imu_info_sub;
    ros::Publisher IMU_filter_pub;

    if (enable_neam_filter)
    {
        mean_filter acc_mf;
        mean_filter ang_mf;

        imu_info_sub = imu_node.subscribe("/camera/imu", 100, imumeanCallback);
        IMU_filter_pub = imu_node.advertise<sensor_msgs::Imu>("/livox/imu", 10);
    }
    else if (enable_slide_filter)
    {
        /* code */
        sliding_window_filter acc_sf;
        sliding_window_filter ang_sf;

        imu_info_sub = imu_node.subscribe("/camera/imu", 100, imumeanCallback);
        IMU_filter_pub = imu_node.advertise<sensor_msgs::Imu>("/livox/imu", 10);

    }
    
    


    ros::spin();
    return 0;
}
