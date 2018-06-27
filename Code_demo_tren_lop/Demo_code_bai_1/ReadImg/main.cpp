#include <iostream>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main () {
	
	Mat img = imread("../imgrgdfgdf.jpg"); // mac dich doc la anh color

	if(img.empty()){
		cout << "anh rong" << endl;
		return 0;
	}

	cout << "Doc anh thanh cong" << endl;
	
	imshow("test", img);
	waitKey();
	return 1;
}
