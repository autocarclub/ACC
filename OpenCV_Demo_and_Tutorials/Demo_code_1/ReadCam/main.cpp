#include <iostream>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main () {
	
	VideoCapture video (0);
	
	Mat frame;

	while(true){
		
		video.read(frame);
		imshow("video", frame);
				
		int key = waitKey(30) & 0xff;
		
		if(key == 27){
			break;
		}
	}

	return 1;
}
