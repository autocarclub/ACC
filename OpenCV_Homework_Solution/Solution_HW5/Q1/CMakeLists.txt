cmake_minimum_required(VERSION 2.8)
project( FadeAwaySlideShow )
set(CMAKE_CXX_STANDARD 11)
find_package( OpenCV REQUIRED )
add_executable( run main.cpp )
target_link_libraries( run ${OpenCV_LIBS} )
