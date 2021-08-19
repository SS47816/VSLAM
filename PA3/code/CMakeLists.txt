cmake_minimum_required(VERSION 2.8)
project(draw_trajectory)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

find_package(Eigen3 3.1.0 REQUIRED)
find_package(Sophus REQUIRED)
find_package(Pangolin REQUIRED)

include_directories("/usr/include/eigen3")

include_directories(
${PROJECT_SOURCE_DIR}
${EIGEN3_INCLUDE_DIR}
${Pangolin_INCLUDE_DIRS}
)

add_executable(draw_trajectory src/draw_trajectory.cpp)
target_link_libraries(draw_trajectory ${EIGEN3_LIBS} Sophus::Sophus ${Pangolin_LIBRARIES})

add_executable(comp_trajectories src/comp_trajectories.cpp)
target_link_libraries(comp_trajectories ${EIGEN3_LIBS} Sophus::Sophus ${Pangolin_LIBRARIES})