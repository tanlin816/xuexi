#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(int argc,char *argv[])  
{  
 IplImage *image=0,*imageresize=0;  
 image=cvLoadImage("22.jpg",1);  
 if(!image) printf("can't load an image/n");  
 imageresize=cvCreateImage(cvSize(1000,750),IPL_DEPTH_8U,3);  
 cvResize(image,imageresize,CV_INTER_LINEAR);  
 cvNamedWindow("lena",1);  
 cvNamedWindow("size",1);  
 cvShowImage("size",imageresize);  
 cvShowImage("lena",image);  
 cvWaitKey(0);  
 cvReleaseImage(&image);  
 cvReleaseImage(&imageresize);  
 cvDestroyWindow("size");  
 cvDestroyWindow("lena");  
 return 0;  
}  
