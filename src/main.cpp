#include <gflags/gflags.h>
#include <glog/logging.h>

#include <filesystem>
#include <sstream>

#include "gazebo_interface.h"
#include "log.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);  // 初始化一个log
  // FLAGS_logtostderr = 1;
  FLAGS_alsologtostderr = 1;
  std::string log_dir = "logs";
  // 检查并创建日志目录
  try {
    if (!std::filesystem::exists(log_dir)) {
      std::filesystem::create_directories(log_dir);
      std::cout << "Created log directory: " << log_dir << std::endl;
    }
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Error creating log directory: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  FLAGS_log_dir = log_dir;
  AINFO << "20241016";
  ros::init(argc, argv, "planning_pkg_node");
  ros::NodeHandle nh;
  gazebo_interface::GazeboInterface gazebo_interface(nh);
  ros::Rate loop_rate(10);  // 10 Hz

  while (ros::ok()) {
    gazebo_interface.SpinOnce();
    loop_rate.sleep();
  }

  google::ShutdownGoogleLogging();
  return 0;
}
