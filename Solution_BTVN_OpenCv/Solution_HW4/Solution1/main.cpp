#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void writeToVideo(vector<Mat> frames) {
    if (frames.size() == 0) {
        cout << "Nothing!" << endl;
        return;
    } else {
        VideoWriter writer("../output.avi", CV_FOURCC('M', 'J', 'P', 'G'),
                10, Size(320, 240));
        int count = frames.size();
        int i = 0;
            
        while (i < count) {
            writer.write(frames[i]);
            i++;
        }
    }
}

int main(int argc, char** argv) {
    //Read the folder name through command line
    vector<Mat> images;
    Mat img;
    for (int i = 1; i < argc; i++) {
        img = imread(argv[i]);
        resize(img, img, Size(320, 240));
        images.push_back(img);
    }
    /*-------------------- CREATE ENDING FRAME -------------------------------*/
    //Add one zero matrix at the end of vector to make slide_show ending
    Mat black = Mat::zeros(Size(320, 240), CV_8UC3);
    //PutText
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 2;
    int thickness = 3;
    Point pos = Point(black.cols / 6, black.rows / 2);
    string text = "Ending";
    putText(black, text, pos, fontFace, fontScale, Scalar::all(255), thickness, 8);
    images.push_back(black);
    /*------------------------------------------------------------------------*/

    //Vector holds all results frame
    vector<Mat> frames;
    //Alpha and Beta using for AddWeight function
    double alpha, beta;

    //Slide through all image and combine two contiguous images
    for (int i = 0; i < images.size() - 1; i++) {
        //Alpha will increase gradually to 1
        for (alpha = 1; alpha > 0; alpha -= 0.1) {
            //Beta will decrease gradually to 0
            beta = 1 - alpha;
            //Result is the result by combining two images
            Mat result;
            addWeighted(images[i], alpha, images[i + 1], beta, 0.0, result);
            frames.push_back(result);
        }
    }
    /*Write to video*/
    writeToVideo(frames);
    return 0;
}



