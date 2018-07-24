#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

// function prototype
Mat blue_detector(Mat hsv_input);
Mat red_detector(Mat hsv_input);
vector<Rect> get_bounding_rect(Mat input, Mat mask);
Mat draw_rect_to_candidate(Mat input);


int main(int argc, char** argv) {

    //check arguments
    if (argc != 2) {
        cout << "Require argument to run " << endl
                << "Command to run: ./run  path_to_video" << endl;
        return -1;
    }

    // argument 1 is path to video
    String path_to_vid = argv[1];

    //Read video
    VideoCapture cap(path_to_vid);
    
    // declare a video writer
    VideoWriter writer;
    // open writer stream
    writer.open("../output.avi",CV_FOURCC('D','I','V','X'), 60, cv::Size(640,480), true );

    while (cap.isOpened()) {
        Mat frame;
        cap >> frame;
        
        if(frame.empty()){
            return 1;
        }

        Mat output = draw_rect_to_candidate(frame);

//        imshow("frame", frame);
//        imshow("output", output);
        
        // write output frame to a video
        writer.write(output);

        char key = waitKey(1);
        if (key == 'f') {
            return 1;
        }else if(key == 's'){
            waitKey(0);
        }
    }

    //release the writer
    writer.release();
    
    return 0;
}

// return a binary mask representing blue color
Mat blue_detector(Mat hsv_input) {
    Mat mask_blue;
    inRange(hsv_input, Scalar(80, 140, 140), Scalar(120, 255, 255), mask_blue);
    return mask_blue;
}

// return a binary mask representing red color
Mat red_detector(Mat hsv_input){
    Mat mask_red;
    inRange(hsv_input, Scalar(130,50,50), Scalar(179,255,255), mask_red);
    return mask_red;
}


// get vector of bounding boxes
vector<Rect> get_bounding_rect(Mat input, Mat mask) {
    Mat draw_mat = input.clone();
    vector<Rect> vec_rects;
    
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE, Point(0, 0));

    for (size_t i = 0; i < contours.size(); i++) {
        Rect rect = boundingRect(contours[i]);
        
        //check condition of rect
        int width = rect.width;
        int height = rect.height;
        int x = rect.x;
        int y = rect.y;
        int rect_area = width * height;
        
        if(rect_area < 400 || abs(width - height) > 10){
            continue;
        }
        
        
        vec_rects.push_back(rect);
    }
    
    return vec_rects;
}

// draw bounding boxes marking the traffic signs on an image and return that image
Mat draw_rect_to_candidate(Mat input) {

    //convert input to hsv
    Mat hsv;
    cvtColor(input, hsv, COLOR_BGR2HSV);

    // output image = input image + drawn boxes
    Mat output = input.clone();
    
    // Create a binary mask representing blue color
    Mat mask_blue = blue_detector(hsv);
    
    // Create a binary mask representing red color
    Mat mask_red = red_detector(hsv);

    // get a vector of bounding box corresponding to blue traffic signs
    vector<Rect> blue_rects = get_bounding_rect(input, mask_blue);
    
     // get a vector of bounding box corresponding to red traffic signs
    vector<Rect> red_rects = get_bounding_rect(input, mask_red);
    
    // draw bounding rect of blue traffic signs on output image
    for(int i=0;i<blue_rects.size();i++){
        Rect rect = blue_rects[i];
        rectangle(output, rect, Scalar(255,255,255), 2);
    }
    
    // draw bounding rect of red traffic signs on output image
    for(int i=0;i<red_rects.size();i++){
        Rect rect = red_rects[i];
        rectangle(output, rect, Scalar(255,255,255), 2);
    }

//    imshow("mask_red", mask_red);
//    imshow("mask_blue", mask_blue);

    return output;
}



