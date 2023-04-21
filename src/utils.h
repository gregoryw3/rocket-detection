//
// Created by gregw on 4/19/2023.
//

#ifndef ROCKETDETECTION_UTILS_H
#define ROCKETDETECTION_UTILS_H

#include <opencv2/opencv.hpp>
using namespace cv;
void resize_frame(const Mat& image, float scalePercent);
void resize_and_hsv(const Mat& image, float scalePercent);

#endif //ROCKETDETECTION_UTILS_H
