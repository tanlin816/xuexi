#include <iostream>
#include <cmath>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void imagechange(Mat& r,Mat& s,double c,double l)
{
   int rownumber=s.rows;
  int colnumber=s.cols;
  for(int i=0;i<rownumber;i++)
	{
          
         for(int j=0;j<colnumber;j++)
         	{
			                 	
			s.at<Vec3b>(i,j)[0]=(int)(c*pow((double)(r.at<Vec3b>(i,j)[0]/255.0),l)*255.0);
			s.at<Vec3b>(i,j)[1]=(int)(c*pow((double)(r.at<Vec3b>(i,j)[1]/255.0),l)*255.0);
			s.at<Vec3b>(i,j)[2]=(int)(c*pow((double)(r.at<Vec3b>(i,j)[2]/255.0),l)*255.0);
		}
	} 


}

int main()
{

Mat srcimage=imread("11.tif");
imshow("1",srcimage);
Mat dstimage;
dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
double l[3]={0.6,0.4,0.3};
for(int w=0;w<3;w++)
 {
	imagechange(srcimage,dstimage,1.0,l[w]);
	
	String str[3] = {"0.6.jpg","0.4.jpg","0.3.jpg"};
	imshow(str[w],dstimage);
	imwrite(str[w],dstimage);
 }
 waitKey(0);
}



