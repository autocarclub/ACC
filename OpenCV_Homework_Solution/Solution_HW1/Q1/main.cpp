#include<iostream>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;


int main(){

	VideoCapture video("../Clip_1.avi");

	if(!video.isOpened()){
            cout << "Video is empty" <<endl;
            return -1;
        }
            
	
	int countFrame = 0;

	Mat frame;
        Mat frame50;
        Mat frame60;

	while(true){
		countFrame++;
		video.read(frame);
                
                if(frame.empty()){
                    cout << "Frame "<<countFrame<<" is empty" <<endl;
                    return -1;
                }
                
		if(countFrame == 50){
                    frame50 = frame.clone();
                    //why using clone() ?
                    // this assignment:   frame50 = frame create a reference to which frame is pointing at.
                    // So when frame changes, frame50 also changes, here we use clone() to make a totally separated copy of frame
                }
		if(countFrame == 60){
                    frame60 = frame.clone();
                    break;
		}
	}

        //Calculate the difference between frame 50 and frame 60
	Mat difference = frame50 - frame60;
       
//        imshow("frame50", frame50);
//        imshow("frame60", frame60);
//        imshow("difference", difference);
        
        imwrite("../frame50.png", frame50);
        imwrite("../frame60.png", frame60);
        imwrite("../difference.png", difference);
        
//	waitKey();
        
	return 1;
}
