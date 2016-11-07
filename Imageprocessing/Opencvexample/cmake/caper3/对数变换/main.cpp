#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void imagelog(Mat& r,Mat& s1,Mat& s2,int c);

int main()
{

Mat srcimage=imread("22.tif");
imshow("原图",srcimage);
Mat dstimage1,dstimage2;
dstimage1.create(srcimage.rows,srcimage.cols,srcimage.type());
dstimage2.create(srcimage.rows,srcimage.cols,srcimage.type());
int c=1; 
int rownumber=srcimage.rows;
int colnumber=srcimage.cols;
  for(int i=0;i<rownumber;i++)
	{
          
         for(int j=0;j<colnumber;j++)
         	{
                 	dstimage2.at<Vec3b>(i,j)[0]=(int)(c*log(1+(double)(srcimage.at<Vec3b>(i,j)[0]/255.0))*255.0);
			dstimage2.at<Vec3b>(i,j)[1]=(int)(c*log(1+(double)(srcimage.at<Vec3b>(i,j)[1]/255.0))*255.0);
			dstimage2.at<Vec3b>(i,j)[2]=(int)(c*log(1+(double)(srcimage.at<Vec3b>(i,j)[2]/255.0))*255.0);
		}
	} 

 imshow("对数变换",dstimage2);
imwrite("LogTransformations.jpg",dstimage2);
waitKey(0);
return 0; 
}

