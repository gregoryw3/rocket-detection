#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    /**if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    **/
    Mat image;
    image = imread( R"(C:\Users\gregw\CLionProjects\RocketDetection\tree.jpg)", 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
//https://stackoverflow.com/questions/66757199/color-percentage-in-image-for-python-using-opencv
    // The HSV mask values, defined for the green color:
    auto lowerValues = Scalar(29, 89, 70);
    auto upperValues = Scalar(179, 255, 255);

    float scalePercent = 0.3;

    int width = int( image.size().width * scalePercent);
    int height = int( image.size().height * scalePercent);

    resize(image, image, Size(width, height), INTER_AREA);

    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_BGR2HSV);

    Mat hsvMask;
    inRange(hsvImage, lowerValues, upperValues, hsvMask);

    Mat hsvOutput;
    bitwise_and(hsvImage, hsvImage, hsvOutput, hsvMask);

    Mat imageByHSVImage;
    hconcat(image, hsvImage, imageByHSVImage);
    Mat hsvMaskByhsvOutput;
    hconcat(hsvMask, hsvOutput, hsvMaskByhsvOutput);


    Mat allfour;
    vconcat(imageByHSVImage, hsvMaskByhsvOutput, allfour);
    imshow("Top: Normal Image and HSV Image    Bottom: HSV Mask and HSV Final", allfour);
    waitKey(0);

    return 0;
}

