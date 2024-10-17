#include "gazebo_interface.h"
namespace gazebo_interface {
GazeboInterface::GazeboInterface(ros::NodeHandle& nh) {
  nh_ = nh;
  goal_sub_ = nh_.subscribe("/move_base_simple/goal", 10,
                            &GazeboInterface::GoalCallBack, this);
  path_sub_ =
      nh_.subscribe("/rda_sub_path", 10, &GazeboInterface::PathCallBack, this);
  laser_scan_sub_ = nh_.subscribe("/limo/scan", 10,
                                  &GazeboInterface::LaserScanCallBack, this);
  obs_sub_ = nh_.subscribe("/rda_obstacles", 10,
                           &GazeboInterface::GazeboObsCallBack, this);

  //                             rospy.Subscriber("/rda_sub_path", Path,
  //                             self.path_callback)
  // self.listener = tf.TransformListener()

  // # Topic Subscribe
  // if not use_scan_obstacle:
  //     rospy.Subscriber("/rda_obstacles", ObstacleArrayMsg,
  //     self.obstacle_callback)
  // else:
  //     rospy.Subscriber("/scan", LaserScan, self.scan_callback)
}

void GazeboInterface::GoalCallBack(const geometry_msgs::PoseStamped& goal) {
  AINFO << goal.pose.position.x << "," << goal.pose.position.y;
}

void GazeboInterface::SpinOnce() { ros::spinOnce(); }

void GazeboInterface::PathCallBack(const nav_msgs::Path& path) {
  for (const auto iter : path.poses) {
    AINFO << iter.pose.position.x << "," << iter.pose.position.y;
  }
}
void GazeboInterface::LaserScanCallBack(
    const sensor_msgs::LaserScan& laser_scan) {
  AINFO << laser_scan.angle_min << "," << laser_scan.angle_max;
}

void GazeboInterface::GazeboObsCallBack(
    const costmap_converter::ObstacleArrayMsg& obs) {}

}  // namespace gazebo_interface
