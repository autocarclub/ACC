#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
int main(int argc, char const *argv[])
{
    Mat src = imread("../img_3.jpg");

    if (src.empty()) {
        std::cout << "Image doesn't exist\n";
        return 1;
    }

    Mat srcGray;
    cvtColor(src, srcGray, COLOR_BGR2GRAY);

    double thresh = 120;
    double max_val = 255;

    Mat dst_1, dst_2, dst_3, dst_4;

    //Process threshold with type Binary Inverted
    threshold(srcGray, dst_1, thresh, max_val, THRESH_BINARY_INV);
    
    //Process threshold with type Thresh To Zero
    threshold(srcGray, dst_2, thresh, max_val, THRESH_TOZERO);
    
    //Process threshold with type Thresh To Zero Inverted
    threshold(srcGray, dst_3, thresh, max_val, THRESH_TOZERO_INV);
    
    //Process threshold with type Thresh Truncate
    threshold(srcGray, dst_4, thresh, max_val, THRESH_TRUNC);
    
//    imshow("dst1", dst_1);
//    imshow("dst2", dst_2);
//    imshow("dst3", dst_3);
//    imshow("dst4", dst_4);
//    waitKey(0);

    imwrite("../output_1.jpg", dst_1);
    imwrite("../output_2.jpg", dst_2);
    imwrite("../output_3.jpg", dst_3);
    imwrite("../output_4.jpg", dst_4);
    return 0;
}
