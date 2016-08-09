#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
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

int main()
{

Mat srcimage=imread("22.jpg",0);
imshow("1",srcimage);
printf("test1");
Mat dstimage;
dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
imagechange(srcimage,dstimage,32);
imshow("2",dstimage);
waitKey(0);
}



