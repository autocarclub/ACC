cmake_minimum_required (VERSION 3.0)
project (Caffe-gen-data)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (SOURCES main.cpp)
find_package (OpenCV REQUIRED)

add_executable (run ${SOURCES})
target_link_libraries (run ${OpenCV_LIBS})