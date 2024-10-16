#include <gflags/gflags.h>
#include <glog/logging.h>
#include "log.h"

#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "gazebo_interface.h"
#include <filesystem>  


int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]); // 初始化一个log
    // FLAGS_logtostderr = 1;
    FLAGS_alsologtostderr = 1;
    std::string log_dir = "logs";

    // 检查并创建日志目录
    try
    {
        if (!std::filesystem::exists(log_dir))
        {
            std::filesystem::create_directories(log_dir);
            std::cout << "Created log directory: " << log_dir << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error creating log directory: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    FLAGS_log_dir = log_dir;


    AINFO << "20241016";
    gazebo_interface::GazeboInterface gzi;

    google::ShutdownGoogleLogging();

    return 0;
}
