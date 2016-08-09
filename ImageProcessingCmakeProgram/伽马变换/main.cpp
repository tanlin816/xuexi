#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
void imagechange(Mat& r,Mat& s,int c,int l)
{
  s=r.clone();
  int rownumber=s.rows;
  int colnumber=s.cols*s.channels();
  char v[rownumber][colnumber]={0};
  for(int i=0;i<rownumber;i++)
	{
          uchar* data=s.ptr<uchar>(i);
         for(int j=0;j<colnumber;j++)
         	{
                  data[j]=c*j^l;
                 
		}
        
	} 


}

int main()
{

Mat srcimage=imread("22.jpg",0);
imshow("1",srcimage);
Mat dstimage;
dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
imagechange(srcimage,dstimage,1,3);
imshow("2",dstimage);
waitKey(0);
}



