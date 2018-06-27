#include <iostream>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main () {
	
	Mat img = imread("../img.jpg");
	
	imwrite("/home/nc/Desktop/new_img.jpg", img);

	cout << "saved" << endl;
	return 1;
}
