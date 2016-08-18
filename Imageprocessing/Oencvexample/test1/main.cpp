#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image=imread("11.jpg");
    imshow("origin",image);
    waitKey(0);
}
