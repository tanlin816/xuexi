#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;  
 int main() 
      { 
        
          IplImage*img_color=cvLoadImage("11.jpg",1);//原彩色图像（1表示读取彩色图）

//将彩色图像转换为灰度图像，并保存
IplImage*img_gray=cvCreateImage(cvGetSize(img_color),img_color->depth,1);//灰度图像（参数：图像宽、高、像素的位深度和通道数（单通道为灰度图像））
cvCvtColor(img_color,img_gray,CV_BGR2GRAY);
cvSaveImage("img_gray.jpg",img_gray);//保存灰度图像


//将灰度图像转换为二值图像，并保存
IplImage*image=cvCreateImage(cvGetSize(img_color),img_gray->depth,1);//二值图像
cvThreshold(img_gray,image,100,255,CV_THRESH_BINARY);//固定阈值操作（cvThreshold函数只针对单通道图像）
cvSaveImage("img_binary.jpg",image) ;
          
         vector<vector<Point > > contours; 
     // find 
     findContours(image,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE); 
    // draw 
     Mat result(image.size(),CV_8U,Scalar(0)); 
     drawContours(result,contours,-1,Scalar(255),2); 
            
     namedWindow("contours"); 
     imshow("contours",result); 
         waitKey(); 
         return 0; 
    } 
