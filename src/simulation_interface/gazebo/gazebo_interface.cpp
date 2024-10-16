#include "gazebo_interface.h"
namespace gazebo_interface {
GazeboInterface::GazeboInterface(ros::NodeHandle& nh) {
  nh_ = nh;
  goal_sub_ = nh_.subscribe("/move_base_simple/goal", 10,
                            &GazeboInterface::GoalCallBack, this);
}

void GazeboInterface::GoalCallBack(const geometry_msgs::PoseStamped& goal) {
  AINFO << "bug1";
  AINFO << goal.pose.position.x << "," << goal.pose.position.y;
}

void GazeboInterface::SpinOnce() { ros::spinOnce(); }
}  // namespace gazebo_interface