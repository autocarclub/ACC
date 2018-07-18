#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main () {
	
	Mat img = imread("../video_8.png"); // mac dich doc la anh color // BGR

	if(img.empty()){
		cout << "Failed" << endl;
		return 0;
	}


	// thres img
	cv::Mat gray, thres;

	cv::cvtColor(img, gray, CV_BGR2GRAY);

	threshold(gray, thres, 233, 255, THRESH_BINARY);

	

	//find contours

	vector<vector<Point>> contours;

	findContours(thres, contours, cv::RETR_TREE , cv::CHAIN_APPROX_SIMPLE);

	cv::Mat mask = cv::Mat::zeros(thres.size(), CV_8UC1);

	int index = 0;

	for(auto & cnt : contours) {
		
		if(contourArea(cnt) > 255){
			drawContours(mask, contours, index, Scalar(255, 255, 255), 1);
		}

		index++;
	}

	vector<vector<Point>> convex(contours.size());
	index=0;

	for(auto & cnt : contours){

		convexHull(cnt, convex[index++]);

	}

	mask = cv::Mat::zeros(thres.size(), CV_8UC1);
	//drawContours(mask, convex, -1, Scalar(255, 255, 255), 1);
	drawContours(mask, contours, -1, Scalar(255, 255, 255), 1);
	
	vector<vector<Point>> approx(contours.size());
	index = 0;
	for(auto & cnt : contours){
		double chuvi = arcLength(cnt, true);
		approxPolyDP(cnt, approx[index++], 0.01 * chuvi, true);
	}




	drawContours(mask, approx, -1, Scalar(255, 255, 255), 1);

	for(auto & cnt : contours){

		if(contourArea(cnt) > 500){
			cv::Vec4f line_;
			fitLine(cnt, line_, CV_DIST_L2, 0, 0.01, 0.01);

			if(line_[0] < 0.01){
				line_[0] = 0.01;
			}
			double slope = line_[1]/line_[0];

			Point anchorPoint = cv::Point(line_[2], line_[3]);


				int rows = mask.rows;
				int cols = mask.cols;


			int lefty = int((-anchorPoint.x * slope) + anchorPoint.y);
			int righty = int(((cols - anchorPoint.x) * slope) + anchorPoint.y);

			cv::Point start = cv ::Point( cols - 1, righty);
			cv::Point end = cv:: Point(0 ,lefty);


			cv::line( mask, 
					start, 
					end, 
					cv::Scalar (255), 2);
		}
		
	}

	for(auto & cnt : contours){

		Rect r = cv::boundingRect(cnt);

		cv::rectangle(mask, r, Scalar(255), 1);

	}

	imshow("BGR", mask);
	waitKey();
	return 1;
}