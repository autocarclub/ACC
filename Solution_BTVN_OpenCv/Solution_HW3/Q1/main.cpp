#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    //check arguments
    if (argc != 2) {
        cout << "Require argument to run " << endl
                << "Command to run: ./run  path_to_image" << endl;
        return -1;
    }
    
    String path_to_img = argv[1];
    
    // read input image
    Mat input = imread(path_to_img);
    
    if (input.empty()) {
        cout << "Image doesn't exist\n";
        return 1;
    }
    
    // resize image to 640x480, assign to input
    resize(input, input, Size(640, 480), 0, 0);

    // convert image to grayscale
    Mat gray;
    cvtColor(input, gray, CV_BGR2GRAY);
    
    // threshold BINARY with threshold value = 220
    Mat thres;
    threshold(gray, thres, 220, 255, THRESH_BINARY);

    // find contour, mask is thres
    vector< std::vector<cv::Point> > contours;
    findContours(thres, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // draw contour to a matrix
    Mat draw_mat = Mat::zeros(thres.size(), CV_8UC1);
    int index = 0;
    for (const auto &cnt : contours) {
        
        // check if contour satisfies condition
        if (contourArea(cnt) > 200) {
            drawContours(draw_mat, contours, index, Scalar(255), -1);
        }

        ++index;
    }

    // show output image
//    imshow("output", draw_mat);
//    waitKey(0);
    
    // write output to file
    imwrite("../output.jpg", draw_mat);

    return 0;
}
