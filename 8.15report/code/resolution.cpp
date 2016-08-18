#include <iostream>
#include <cmath>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{

    Mat srcimage = imread("1250dpi.jpg");
    if(!srcimage.data)

    {

        cout << "image read is error!" << endl;

        return 0;

    }
    cout << "image Info:Height:" << srcimage.size().height << " Width:" << srcimage.size().width << endl;
imshow("origin",srcimage);
int a[3]={4,8,16};                                                        //定义小正方形的大小；
int nl = srcimage.rows;
int nc = srcimage.cols ;
for(int w=0;w<3;w++)
{
    int r = nl/a[w];
    int c = nc/a[w];
    Mat dstimage;                                                         //定义一个输出图像；
    dstimage.create(r,c,srcimage.type());                                 //定义输出图像的大小、类型；
    CvScalar  sum,avg;                                                    //定义可以存放四通道的变量；
    for(int x = 0;x < r;x++)                                              //行上有几个这样的小正方形块，也是输出图像的行；
    {
        for(int y = 0;y < c;y++)                                          //列上有几个这样的小正方形块，也是输出图像的列；
        {
            sum=0;                                                        //初始化；
     
            for(int i = a[w] * x;i <a [w]* (x+1);i++)                     //对每一个小块行取值；
            { 
                for(int j = a[w] * y;j < a[w] * (y+1);j++)                //对每一个小块列取值；
                {
		
                    sum.val[0] = sum.val[0] + srcimage.at<Vec3b>(i,j)[0]; //蓝色通道求和；
               
                    sum.val[1] = sum.val[1] + srcimage.at<Vec3b>(i,j)[1]; //绿色通道求和；
                
                    sum.val[2] = sum.val[2] + srcimage.at<Vec3b>(i,j)[2]; //红色通道求和；
                
               
                }
            } 
                
            dstimage.at<Vec3b>(x,y)[0] = sum.val[0]/(a[w]*a[w]);          //蓝色通道求平均，并且将其赋给输出图像；
            dstimage.at<Vec3b>(x,y)[1] = sum.val[1]/(a[w]*a[w]);          //绿色通道求平均，并且将其赋给输出图像；
            dstimage.at<Vec3b>(x,y)[2] = sum.val[2]/(a[w]*a[w]);          //红色通道求平均，并且将其赋给输出图像；

        }
    }
String str[3] = {"300dpi.jpg","150dpi.jpg","72dpi.jpg"};
imshow(str[w],dstimage);
imwrite(str[w], dstimage);
}

waitKey(0);
return 0;
}
