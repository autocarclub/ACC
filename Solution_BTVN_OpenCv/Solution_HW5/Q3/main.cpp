#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    
    cv::Mat src = cv::imread(argv[1]);
    
    cv::Mat mask(src.rows, src.cols, CV_8UC3, cv::Scalar(0, 0, 0));
    
    int width, height, thickness;
    width = 100; height = 50; thickness = CV_FILLED;
    
    double angle, start_angle, end_angle;
    angle = 50; start_angle = 0, end_angle = 360;
    //Try with angle = 45, start_angle = 10, end_angle = 240 and thickness = CV_FILLED
            //compare with old parameters         
    cv::ellipse(mask,
            Point(src.cols/2, src.rows/2),
            Size(width, height),
            angle,
            start_angle, end_angle,
            Scalar(255,255,255),
            thickness, LINE_8);
    
    cv::Mat result;
    cv::bitwise_and(src, mask, result);
    
    imwrite("../3.jpeg", result);
    return 0;
}




