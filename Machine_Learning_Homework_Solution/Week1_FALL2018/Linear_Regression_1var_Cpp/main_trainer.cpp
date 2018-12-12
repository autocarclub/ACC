#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <random>

using namespace std;
using namespace cv;

double generate_random_y(double x){
    return 0.7*x - 21 + 120*(double)rand() / RAND_MAX;
}

Mat plot_data(vector<double> list_x, vector<double> list_y){
    int width = *max_element(list_x.begin(), list_x.end()) + 2;
    int height = *max_element(list_y.begin(), list_y.end()) + 2;
    Mat mat = Mat::zeros(Size(width, height), CV_8UC1);

    for(int i=0;i<list_x.size();i++){
        Point center(list_x[i], list_y[i]);
        circle(mat, center, 3, 255, CV_FILLED);
    }
    
    return mat;
}

double hx(double x, double a0, double a1){
    return a0 + a1*x;
}

double cost(vector<double> list_x,vector<double> list_y,double a0, double a1){
    double sum = 0;
    int m = list_x.size();
    for (int i=0;i<list_x.size(); i++){
        double x = list_x[i];
        double y_true = list_y[i];
        double y_predict = hx(x, a0, a1);
        
        double err = y_predict - y_true;
        
        sum += pow(err, 2);
      
    }
    
    sum = 1.0/(2*m) * sum;
    return sum;
}

void gradients(vector<double> list_x,vector<double> list_y, double a0, double a1, double& grad_a0, double& grad_a1){
    
    int m = list_x.size();
    
    for (int i=0;i<list_x.size(); i++){
        double x = list_x[i];
        double y_true = list_y[i];
        double y_predict = hx(x, a0, a1);
        
        double err = y_predict - y_true;
        
        grad_a0 += err;
        grad_a1 += x*err;
    }
    
    grad_a0 /= m;
    grad_a1 /= m;
      
}

void train(vector<double> list_x,vector<double> list_y, double& a0, double& a1){
    int n_iterations = 10000;
    double learning_rate = 0.00001;
    
    double grad_a0 = 0, grad_a1 = 0;
    
    for (int i=0;i<n_iterations;i++){
        double cost_i = cost(list_x, list_y, a0, a1);
        gradients(list_x, list_y, a0, a1, grad_a0, grad_a1);
        
        // update parameter a0, a1
        a0 -= learning_rate*grad_a0;
        a1 -= learning_rate*grad_a1;
        
        
        if(i % 1000 == 0){
            cout << "===================Iteration "<<i<<" ====================="<<endl;
            cout << "cost: "<<cost_i<<endl;
            cout << "a0: "<< a0 <<endl;
            cout << "a1: "<< a1 <<endl;
        }
    }
}

int main(int argv, char ** argc){
    vector<double> list_x;
    vector<double> list_y;
    
    // =============== Generate data =======================
    for (double x=0;x<640;x+= 20){
        double y = generate_random_y(x);
        list_x.push_back(x);
        list_y.push_back(y);
        
    }
    
    // =============== Plot data =======================
    Mat mat = plot_data(list_x, list_y);
    imshow("mat", mat);
    imwrite("../plot.jpeg", mat);
    waitKey(0);
    
    
    // ================ Linear Regression ==================
    // fit line: y = a0 + a1*x  through training data
    // generate initial a0, a1
    double a0 = (double)rand() / RAND_MAX;
    double a1 = (double)rand() / RAND_MAX;
    
    //cout << a0 <<" "<< a1<<endl;
    
    // train data and save to 2 reference variables a0, a1
    train(list_x, list_y, a0, a1);
    
    // plot a line predict data given x
    line(mat, Point(0,a0 + 0*a1), Point(mat.cols, a0 + mat.cols * a1), 255);
    imshow("mat", mat);
    imwrite("../regression.jpeg", mat);
    waitKey(0);
    
    
    return 0;
}