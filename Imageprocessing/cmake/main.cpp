#include <iostream>
#include <cmath>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{

Mat srcimage=imread("11.jpeg");
if(!srcimage.data)

{

cout << "image read is error!" << endl;

return 0;

}
cout << "image Info:Height:" << srcimage.size().height << " Width:" << srcimage.size().width << endl;
imshow("origin",srcimage);
imwrite("original.jpeg", srcimage);

double nl = srcimage.rows;

double nc = srcimage.cols * srcimage.channels();
int l= (int)(nl/2+0.5);
int c= (int)(nc/2+2.5);
Mat dstimage;
dstimage.create(l,c,srcimage.type());
for(int i=0;i<l;i++)
	{ uchar* a=srcimage.ptr<uchar>(2*i);
          uchar* b=dstimage.ptr<uchar>(i);
         for(int j=0;j<c;j++)
         	{
                 b[j]=a[2*j];
		}
	} 
imshow("空间率降低效果图",dstimage);
imwrite("空间率降低效果图.jpeg", dstimage);
waitKey(0);
return 0;
} 
