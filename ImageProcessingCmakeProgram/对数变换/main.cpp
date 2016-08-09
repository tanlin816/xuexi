#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void imagelog(Mat& r,Mat& s,int c)
{
  s=r.clone();
  int rownumber=s.rows;
  int colnumber=s.cols*s.channels();
  for(int i=0;i<rownumber;i++)
	{
          uchar* data=s.ptr<uchar>(i);
         for(int j=0;j<colnumber;j++)
         	{
                 data[j]=c*log(1+ data[j]);
		}
	} 


}

int main()
{

Mat srcimage=imread("22.jpg");
imshow("原图",srcimage);
Mat dstimage;
dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
imagelog(srcimage,dstimage,33);
imshow("对数变换",dstimage);
waitKey(0);
}
