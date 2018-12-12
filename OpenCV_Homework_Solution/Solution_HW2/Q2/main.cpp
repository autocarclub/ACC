#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    
    Mat bgr = imread("../img_2.jpeg");  // input is of type BGR by default
    
    //if using imread("../img_2.jpeg, IMREAD_COLOR), you get the same result. 
    //Because opencv will read image as color image type BGR by default
    
    if (bgr.empty()) {
        std::cout << "Image doesn't exist\n";
        return 1;
    }
    
    //create a zero-matrix type 8UC1
        // a zero-matrix is a matrix with all pixels having value = 0
        //8UC1 is type of gray scale image
    Mat gray = Mat::zeros(bgr.size(), CV_8UC1);
    
    
    //apply equation with each pixels of the image
    for(int x=0; x < bgr.rows; x++){
        for(int y=0; y < bgr.cols; y++){
            
            //get value at location (x,y) of each channel red, green, blue
            int blue = bgr.at<Vec3b>(x,y)[0];
            int green = bgr.at<Vec3b>(x,y)[1];
            int red = bgr.at<Vec3b>(x,y)[2];
            
            //compute gray value 
            double gray_value = 0.3086*red + 0.6094*green + 0.0820*blue;
            
            gray.at<uchar>(x,y) = gray_value;   // gray value will automatically casted to integer when assign it to that pixel
        }
    }
    
    
    //write output image to file
    imwrite("../output.jpeg", gray);
    
    
    //show input and output
//    imshow("BGR", bgr);
//    imshow("grayscale", gray);
//    waitKey(0);
    
    return 0;
}