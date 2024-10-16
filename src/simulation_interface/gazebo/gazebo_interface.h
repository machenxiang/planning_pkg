#pragma once
#include <iostream>

#include "geometry_msgs/PoseStamped.h"
#include "log.h"
#include "ros/ros.h"
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

 private:
  void GoalCallBack(const geometry_msgs::PoseStamped& goal);
};

}  // namespace gazebo_interface