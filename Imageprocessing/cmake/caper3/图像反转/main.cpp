#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void imagechange(Mat& r,Mat& s,int l);

int main()
{

	Mat srcimage=imread("11.tif");
	imshow("1",srcimage);
	Mat dstimage;
	dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
	imagechange(srcimage,dstimage,256);
	imshow("2",dstimage);
	imwrite("Image_Negative.jpg",dstimage);
	waitKey(0);
}
void imagechange(Mat& r,Mat& s,int l)
{
  	s=r.clone();
  	int rownumber=s.rows;
  	int colnumber=s.cols*s.channels();
  	for(int i=0;i<rownumber;i++)
	{
          	uchar* data=s.ptr<uchar>(i);
         	for(int j=0;j<colnumber;j++)
         	{
                 	data[j]=l-1-data[j];
		}
	} 


}




