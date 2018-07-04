#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    
    Mat input = imread("../img_3.jpg", IMREAD_COLOR);
    //Check if Mat is empty or not
    if (input.empty()){
        cout <<"Input is empty"<<endl;
    }
    Mat output = input.clone();
    
    // Use nested for loops to modify each pixel of an image
    for (int x = 0; x < output.rows; x = x + 2) {
        for (int y = 0; y < output.cols; y = y + 2) {
                output.at<Vec3b>(x, y)[0] = 0;
            output.at<Vec3b>(x, y)[1] = 0;
            output.at<Vec3b>(x, y)[2] = 0;
        }
    }

    
    //imshow("OUTPUT", output);
    imwrite("../output.jpg", output);
    
    //waitKey(0);

    return 0;
}
