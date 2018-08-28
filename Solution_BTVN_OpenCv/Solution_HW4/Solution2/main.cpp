#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
    //Read input images
    Mat logo = imread(argv[1]);
    Mat messi = imread(argv[2]);
    
    resize(logo, logo, Size(320, 240));
    resize(messi, messi, Size(320, 240));
    //Step 1:
    Mat logo_gray; 
    cvtColor(logo, logo_gray, COLOR_BGR2GRAY);
    Mat mask;
    threshold(logo_gray, mask, 180, 255, THRESH_BINARY_INV);
    
    //Step 2:
    Mat mask_inv;
    bitwise_not(mask, mask_inv);
    
    //Step 3:
    Mat messi_clone = messi.clone();
    
    //Step 4:
    Mat layer1 = Mat::zeros(Size(320, 240), messi.type());
    Mat layer2 = Mat::zeros(Size(320, 240), logo.type());
    
    bitwise_and(messi_clone, messi_clone, layer1, mask_inv);
    bitwise_and(logo, logo, layer2, mask);

    //Step5
    Mat final_output;
    add(layer1, layer2, final_output);
    imshow("DST", final_output);
    waitKey();
    imwrite("final_output.jpg", final_output);
            
    return 0;
}



