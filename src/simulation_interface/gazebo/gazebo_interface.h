#pragma once
#include <iostream>

#include "costmap_converter/ObstacleArrayMsg.h"
#include "geometry_msgs/PoseStamped.h"
#include "log.h"
#include "nav_msgs/Path.h"
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
namespace gazebo_interface {

class GazeboInterface {
 public:
  GazeboInterface(ros::NodeHandle& nh);
  ~GazeboInterface() {};
  void Publish();
  void Sub();
  void SpinOnce();

 private:
  ros::NodeHandle nh_;
  ros::Subscriber goal_sub_;
  ros::Subscriber path_sub_;
  ros::Subscriber laser_scan_sub_;
  ros::Subscriber obs_sub_;

 private:
  void GoalCallBack(const geometry_msgs::PoseStamped& goal);
  void PathCallBack(const nav_msgs::Path& path);
  void LaserScanCallBack(const sensor_msgs::LaserScan& laser_scan);
  void GazeboObsCallBack(const costmap_converter::ObstacleArrayMsg& obs);
};

}  // namespace gazebo_interface