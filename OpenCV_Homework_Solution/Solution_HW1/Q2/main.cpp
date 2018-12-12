#include<iostream>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;


int main(){

    //create 2D arrays of data
    float array_A[4][3] = {{1,4,5},
                            {2,3,1},
                            {9,6,0},
                            {8,8,8}};
    
    float array_B[3][4] = {{5,2,11,8},
                            {4,1,23,2},
                            {2,4,5,9}};
    
    float array_C[3][4] = {{7,7,3,3},
                            {4,2,1,1},
                            {9,6,8,5}};
    
    //create Mat object from 2D array
    Mat A(4,3, CV_32FC1, array_A);
    Mat B(3,4, CV_32FC1, array_B);
    Mat C(3,4, CV_32FC1, array_C);
    
    cout << "B + C = \n"<< B+C <<endl<<endl;
    cout << "C - B = \n"<< C-B <<endl<<endl;
    cout << "A * B = \n"<< A*B <<endl<<endl;
    cout << "B * A = \n"<< B*A <<endl<<endl;
    cout << "C * A = \n"<< C*A <<endl<<endl;
    
    return 1;

}
