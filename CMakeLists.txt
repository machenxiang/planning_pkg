cmake_minimum_required(VERSION 3.0.2)
project(planning_pkg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

find_package(glog REQUIRED)
find_package(gflags REQUIRED)
find_package(Protobuf 3  REQUIRED)
find_package(PROJ)
find_package(Boost)
find_package(Eigen3 REQUIRED)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES planning_pkg
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/common/log)



file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.cc"
)


# 定义一个变量来存储包含目录
set(INCLUDE_DIRS)

# 查找所有头文件（根据需要可以扩展文件类型）
file(GLOB_RECURSE HEADER_FILES
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.hpp"
    "${PROJECT_SOURCE_DIR}/*.hh"
)

# 提取头文件所在的目录并添加到 INCLUDE_DIRS
foreach(header_file ${HEADER_FILES})
    get_filename_component(dir ${header_file} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${dir})
endforeach()

# 移除重复的目录
list(REMOVE_DUPLICATES INCLUDE_DIRS)


# 打印包含目录（可选，用于调试）
message(STATUS "Include directories:")
foreach(dir ${INCLUDE_DIRS})
    message(STATUS "  ${dir}")
endforeach()


add_executable(${PROJECT_NAME}_node
               ${SOURCES}
)

# 添加包含目录到目标
target_include_directories(${PROJECT_NAME}_node PRIVATE ${INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  glog::glog
  gflags
  ${PROTOBUF_LIBRARIES}
  proj
  ${Boost_LIBRARIES}
)

