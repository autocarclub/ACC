#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    
    Mat bgr = imread("../img_4.png");  // input is of type BGR by default
    
    //if using imread("../img_4.png, IMREAD_COLOR), you get the same result. 
    //Because opencv will read image as color image type BGR by default
    
    if (bgr.empty()) {
        std::cout << "Image doesn't exist\n";
        return 1;
    }
    
    Mat hsv;
    
    //convert to hsv
    cvtColor(bgr, hsv, CV_BGR2HSV);
    
    
    //find range of blue
    Mat mask_blue;
    Scalar lower = Scalar(100,100,100);
    Scalar upper = Scalar(130,255,255);
    inRange(hsv, lower, upper, mask_blue);
    // after inRange, output is a binary matrix called mask, it will keep pixels 
    // corresponding to "blue" color and discard all of the others

    
    //write output
    imwrite("../output.png", mask_blue);
    
    
    //show input image and result image
//    imshow("input", bgr);
//    imshow("Mask_blue", mask_blue);
//    waitKey(0);
    
    return 0;
}