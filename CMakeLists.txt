cmake_minimum_required(VERSION 3.0)
project(A_Star)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE PYTHON3.8_LIB "/usr/lib/python3.8/config-3.8-x86_64-linux-gnu/*.so")
set(PYTHON3.8_INLCUDE_DIRS "/usr/include/python3.8")

# find_package(catkin REQUIRED COMPONENTS
#   roscpp
#   std_msgs
# )

# catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES huatu
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
# )

include_directories(include
        ${PYTHON3.8_INLCUDE_DIRS}
)

add_executable(A_Star main.cpp src/A_Star.cpp)
target_link_libraries(A_Star ${PYTHON3.8_LIB})