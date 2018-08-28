#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    
    cv::Mat src = cv::imread(argv[1]);
    
    cv::Point corners[2][3];
    corners[0][0] = Point(src.cols / 2, 0);
    corners[0][1] = Point(0, src.rows / 3);
    corners[0][2] = Point(src.cols, src.rows / 3);

    corners[1][0] = Point(src.cols, src.rows * 2 / 3);
    corners[1][1] = Point(0, src.rows * 2 / 3);
    corners[1][2] = Point(src.cols / 2, src.rows);
    const Point * corner_list[2] = {corners[0], corners[1]};

    int num_points[] = {3,3};
    int num_polygons = 2;
    int line_type = 8;
    cv::Mat mask(src.rows, src.cols, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::fillPoly(mask, corner_list, num_points, num_polygons, cv::Scalar(255, 255, 255), line_type);

    cv::Mat result;
    cv::bitwise_and(src, mask, result);

    imwrite("../2.jpeg", result);
    return 0;
}



