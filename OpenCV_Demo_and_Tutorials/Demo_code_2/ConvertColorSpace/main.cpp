#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main () {
	
	Mat img = imread("../input.png"); // mac dich doc la anh color // BGR

	if(img.empty()){
		cout << "Failed" << endl;
		return 0;
	}
	
	imshow("BGR", img);
	
	// RGB

	Mat dst;

	cvtColor(img, dst, COLOR_BGR2RGB);
	//imshow("RGB", dst);
	
	

	// gray
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("gray", gray);

	// thres
	Mat thres;
	threshold(gray, thres, 170, 255, THRESH_BINARY);
	imshow("thres", thres);

	// hsv
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	imshow("RGB", hsv);

	// inrange
	Mat inranged;

	inRange(hsv, Scalar(90, 180, 160), Scalar(255, 255,255), inranged);
	cv::imshow("inranged", inranged);
	
	waitKey();
	return 1;
}