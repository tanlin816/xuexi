#include <iostream>
#include <opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
#define WINDOW_NAME "线性混合"
const int g_nmav=100;
int g_navs;
double g_dav;
double g_dbv;
Mat g_srci1;
Mat g_srci2;
Mat g_dsti;
void on_Trackbar(int, void*)
{
  g_dav=(double) g_navs/g_nmav;
  g_dbv=(1.0-g_dav);
  addweighted(g_srci1,g_dav,g_srci2,g_dbv,0.0,g_dsti);
  imshow(WINDOW_NAME,g_dsti);
}
int main(int argc,char** argv)
{
g_srci1=imread("11.jpg");
g_srci2=imread("22.jpg");
if(!g_srci1.data)
 { printf("读取第一幅图片错误，请确定目录下是否有imread函数指定图片存在~！\n");
  return -1;}
if(!g_srci2.data)
{ printf("读取第二幅图片错误，请确定目录下是否有imread函数指定图片存在~！\n");
  return -1;}

g_navs=70;
nameWindow(WINDOW_NAME, 1);
char Tbn[50];
sprintf(Tbn,“透明值 %d”,g_nmav);
xreateTrackbar(Tbn,WINDOW_NAME,&g_navs,g_nmav,on_Trackbar);
on_Trackbar(g_navs, 0);
waitKey(0);
return 0;
}
