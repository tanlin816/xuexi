#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main()
{
    Mat image=imread("11.jpg");
    imshow("图1",image);
    Mat dstI;
   blur(image,dstI,Size(7,7));
imshow("均值滤波",dstI);


    waitKey(0);
}

