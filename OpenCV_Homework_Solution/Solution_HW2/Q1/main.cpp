#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    
    Mat bgr = imread("../img_1.jpg");  // input is of type BGR by default
    
    //if using imread("../img_1.jpg, IMREAD_COLOR), you get the same result. 
    //Because opencv will read image as color image type BGR by default
    
    if (bgr.empty()) {
        std::cout << "Image doesn't exist\n";
        return 1;
    }
    
    //define an vector: a vector is a dynamic array in c++ (no limit of elements)
    // this will contain 3 matrices of blue, green, red channels
    vector<Mat> channel_array;   
    
    
    //using split() function to split 3 channel matrices to a vector
    split(bgr,channel_array);
    
    
    // now the order of the 3 channels is B -> G -> R
    Mat blue = channel_array[0];           
    Mat green = channel_array[1];
    Mat red = channel_array[2];
    
    
    //re-arrange channels with this order: R -> G -> B
    channel_array[0] = red;
    channel_array[1] = green;
    channel_array[2] = blue;
           
    
    //merge 3 channels to a RGB image
    Mat rgb;
    merge(channel_array,rgb);       
    
    
    //write output image to file
    imwrite("../output.jpg", rgb);
    
    
    //show input and result
//    imshow("BGR - input", bgr);
//    imshow("RGB - output", rgb);
//    waitKey(0);
    
    return 0;
}