#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int nun_classes = 3;
String classes[3] = {"left","right","stop"};

int main(int argc, char const *argv[])
{
    //check arguments
    if (argc != 3) {
        cout << "Require argument to run " << endl
                << "Command to run: ./run  path_to_data_folder path_to_output_folder" << endl;
        return -1;
    }
    
    String path_to_data_folder = argv[1];
    String path_to_output_folder = argv[2];

    // generate train.txt
    vector<String> fn;
    ofstream train_ouput_file(path_to_output_folder+"/train.txt");
    for(int j=0;j<nun_classes;j++){
        glob(path_to_data_folder+"/train/"+classes[j]+"/*.ppm",fn, true);
        for(int i=0;i<fn.size();i++){
            //cout << fn[i]<<endl;
            istringstream f(fn[i]);
            string s;    
            while (getline(f, s, '/')) {

            }
            train_ouput_file<<classes[j]+"/" << s <<" "<< j << endl;
        }
    }

    // generate test.txt
    ofstream val_output_file(path_to_output_folder+"/val.txt");
    for(int j=0;j<nun_classes;j++){
        glob(path_to_data_folder+"/val/"+classes[j]+"/*.ppm",fn, true);
        for(int i=0;i<fn.size();i++){
            //cout << fn[i]<<endl;
            istringstream f(fn[i]);
            string s;    
            while (getline(f, s, '/')) {

            }
            val_output_file <<classes[j]+"/"<< s <<" "<< j << endl;
        }
    }


    return 0;
}