cmake_minimum_required(VERSION 3.25)
project(RocketDetection CXX)

set(CMAKE_C_STANDARD 23)
set(ENV{OpenCV_DIR} C:/Users/gregw/.clion-vcpkg/vcpkg/packages/opencv4_x64-windows-static)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV CONFIG REQUIRED)
include("C:/Code Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(RocketDetection main.cpp)
#opencv_core opencv_calib3d opencv_dnn opencv_features2d opencv_flann opencv_highgui opencv_imgcodecs opencv_imgproc opencv_ml opencv_objdetect opencv_photo opencv_stitching opencv_video opencv_videoio
set(OPENCV_LIBS opencv)

target_link_libraries(RocketDetection ${OpenCV_LIBS})
