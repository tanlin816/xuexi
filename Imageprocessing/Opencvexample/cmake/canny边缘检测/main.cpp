#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main()
{
 Mat srcI=imread("11.jpg");
    imshow("图1",srcI);
    Mat edge,grayI;
  cvtColor(srcI,grayI,CV_BGR2GRAY);
blur(grayI,edge,Size(3,3));
Canny(edge,edge,3,9,3);
imshow("Canny边缘检测",edge);
waitKey(0);
return(0);

}

