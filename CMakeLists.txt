cmake_minimum_required(VERSION 3.9)

project(OpenCV)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCV MACOSX_BUNDLE main.cpp)

target_link_libraries(OpenCV ${OpenCV_LIBS})


#cmake_minimum_required(VERSION 3.9)
#project(OpenCVProject)
#
#set(CMAKE_CXX_STANDARD 23)
#
##find_library(OpenCV)
#find_package(OpenCV)
#
#include_directories(${OpenCV_INCLUDE_DIRS})
#set(CMAKE_CXX_STANDARD 23)
#
#add_executable(OpenCVProject main.cpp)
#
#target_link_libraries(OpenCVProject ${OpenCV_LIBS})