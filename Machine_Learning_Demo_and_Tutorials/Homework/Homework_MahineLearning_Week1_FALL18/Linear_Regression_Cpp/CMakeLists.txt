cmake_minimum_required(VERSION 2.8)

project(Linear_Regression_1var)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

add_executable(run main.cpp)

target_link_libraries(run ${OpenCV_LIBS}) 
