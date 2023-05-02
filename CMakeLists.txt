cmake_minimum_required(VERSION 3.25)
project(RocketDetection CXX)

set(CMAKE_C_STANDARD 23)
set(ENV{OpenCV_DIR} C:/Users/gregw/.clion-vcpkg/vcpkg/packages/opencv4_x64-windows-static)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV CONFIG REQUIRED)
find_package(FFMPEG REQUIRED)
find_package(GTK REQUIRED)
find_package(PkgConfig)
pkg_check_modules(GTKMM_VARS REQUIRED IMPORTED_TARGET gtkmm-4.0)

include("C:/Code Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake")


add_library(FFMPEG STATIC IMPORTED src/extract_frames_test.cpp)




add_executable(RocketDetection src/main.cpp src/extract_frames.cpp src/extract_frames.h src/extract_frames.h src/utils.cpp src/utils.h src/utils.h src/utils.cpp src/extract_frames_test.cpp src/extract_frames_test.h src/extract_subtitles_test.cpp)
#opencv_core opencv_calib3d opencv_dnn opencv_features2d opencv_flann opencv_highgui opencv_imgcodecs opencv_imgproc opencv_ml opencv_objdetect opencv_photo opencv_stitching opencv_video opencv_videoio
set(OPENCV_LIBS opencv)

link_directories(${GTKMM_LIBRARY_DIRS}  )
include_directories(${GTKMM_INCLUDE_DIRS}  )

target_include_directories(RocketDetection PRIVATE ${FFMPEG_INCLUDE_DIRS}, ${GTK_INCLUDE_DIR}, ${GTKMM_INCLUDE_DIRS})
target_link_directories(RocketDetection PRIVATE ${FFMPEG_LIBRARY_DIRS}, ${GTK_LIBRARY_DIRS}, ${GTKMM_LIBRARY_DIRS})
target_link_libraries(RocketDetection PRIVATE ${FFMPEG_LIBRARIES}, ${OpenCV_LIBS}, ${GTK_LIBRARIES}, ${GTKMM_LIBRARIES}, PRIVATE PkgConfig::GTKMM_VARS)
