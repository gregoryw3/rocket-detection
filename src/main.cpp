#include <cstdio>
#include "extract_frames.h"
#include "utils.h"
#include "opencv2/opencv.hpp"
#include <gtkmm-4.0/gtkmm.h>

using namespace cv;

class MyWindow : public Gtk::Window {
    public: MyWindow();
};

MyWindow::MyWindow()
{
    set_title("Basic application");
    set_default_size(200, 200);
}

int main(int argc, char** argv )
{
    /**if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    **/

    // Create a new application
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<MyWindow>(argc, argv);

    Mat image;
    image = imread( R"(../tree.jpg)", 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
//https://stackoverflow.com/questions/66757199/color-percentage-in-image-for-python-using-opencv
    // The HSV mask values, defined for the green color:
    auto lowerValues = Scalar(29, 89, 70);
    auto upperValues = Scalar(179, 255, 255);

    resize_and_hsv(image, 0.3);

    Mat hsvMask;
 //   inRange(hsvImage, lowerValues, upperValues, hsvMask);

    Mat hsvOutput;
//    bitwise_and(hsvImage, hsvImage, hsvOutput, hsvMask);

    Mat imageByHSVImage;
 //   hconcat(image, hsvImage, imageByHSVImage);
    Mat hsvMaskByhsvOutput;
    hconcat(hsvMask, hsvOutput, hsvMaskByhsvOutput);


    Mat allfour;
    vconcat(imageByHSVImage, hsvMaskByhsvOutput, allfour);
    imshow("Top: Normal Image and HSV Image    Bottom: HSV Mask and HSV Final", allfour);
    waitKey(0);

    return 0;
}

