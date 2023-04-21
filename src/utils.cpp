//
// Created by gregw on 4/19/2023.
//

#include "utils.h"

void resize_frame(const Mat& image, float scalePercent){
    int width = int( image.size().width * scalePercent);
    int height = int( image.size().height * scalePercent);

    resize(image, image, Size(width, height), INTER_AREA);
}

void resize_and_hsv(const Mat& image, float scalePercent){
    int width = int( image.size().width * scalePercent);
    int height = int( image.size().height * scalePercent);

    resize(image, image, Size(width, height), INTER_AREA);
    cvtColor(image, image, COLOR_BGR2HSV);
}

void extract_subtitles(){

}

void get_num_frames(){

}
