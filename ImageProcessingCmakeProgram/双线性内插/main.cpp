#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
float Abs(float f);  
void zoom(IplImage* src, IplImage* dst);  
  
int main() {  
  
   IplImage* src = cvLoadImage("22.jpg");  
    IplImage* dst = cvCreateImage(cvSize(1000,1000), src->depth, src->nChannels);  
    zoom(src, dst);  
  
    cvShowImage("src", src);  
    cvShowImage("dst", dst);  
    cvWaitKey(0);  
  
    return 1; 
}  
/**************************** 
*返回绝对值 
*****************************/  
float Abs(float f)  
{  
    return f>=0 ? f : -f;  
}  
/**************************** 
*目标： 实现图像的缩放， 
        使用了双线性插值的算法 
 
*参数： src源图像 
        dst生成图像 
 
*返回值：无 
*****************************/  
void zoom(IplImage* src, IplImage* dst)  
{  
    int srcWidth = src->width;  
    int srcHeight = src->height;  
    int dstWidth = dst->width;  
    int dstHeight = dst->height;  
  
    //源图像与目标图像的宽高比例,这里减1很重要，否则有时报错，有时不报错。这点困扰了我很久  
    const float tx = (srcWidth-1.0f)/(dstWidth-1.0f);  
    const float ty = (srcHeight-1.0f)/(dstHeight-1.0f);  
  
    CvPoint2D32f uv;//存储源图像的浮点坐标  
    CvPoint3D32f f1;  
    CvPoint3D32f f2;  
  
    for (int j=0; j<dstHeight-1; j++)  
     {  
         for (int i=0; i<dstWidth-1; i++)  
         {  
            uv.x = i*tx;  
            uv.y = j*ty;  
  
            int iu = (int)uv.x;  
            int iv = (int)uv.y;  
  
            f1.x = ((uchar*)(src->imageData + src->widthStep*iv))[iu*3+0] * (1-Abs(uv.x-iu))+  
                ((uchar*)(src->imageData + src->widthStep*iv))[(iu+1)*3+0] * (uv.x-iu);  
            f1.y = ((uchar*)(src->imageData + src->widthStep*iv))[iu*3+1] * (1-Abs(uv.x-iu))+  
                ((uchar*)(src->imageData + src->widthStep*iv))[(iu+1)*3+1] * (uv.x-iu);  
            f1.z = ((uchar*)(src->imageData + src->widthStep*iv))[iu*3+2] * (1-Abs(uv.x-iu))+  
                ((uchar*)(src->imageData + src->widthStep*iv))[(iu+1)*3+2] * (uv.x-iu);  
  
            f2.x = ((uchar*)(src->imageData + src->widthStep*(iv+1)))[iu*3] * (1-Abs(uv.x-iu))  
                    +((uchar*)(src->imageData + src->widthStep*(iv+1)))[(iu+1)*3] * (uv.x-iu);  
            f2.y = ((uchar*)(src->imageData + src->widthStep*(iv+1)))[iu*3+1] * (1-Abs(uv.x-iu))+  
                ((uchar*)(src->imageData + src->widthStep*(iv+1)))[(iu+1)*3+1] * (uv.x-iu);  
            f2.z = ((uchar*)(src->imageData + src->widthStep*(iv+1)))[iu*3+2] * (1-Abs(uv.x-iu))+  
                ((uchar*)(src->imageData + src->widthStep*(iv+1)))[(iu+1)*3+2] * (uv.x-iu);  
  
            ((uchar*)(dst->imageData + dst->widthStep*j))[i*3] = f1.x*(1-Abs(uv.y-iv))+f2.x*(Abs(uv.y-iv));  
            ((uchar*)(dst->imageData + dst->widthStep*j))[i*3+1] = f1.y*(1-Abs(uv.y-iv))+f2.y*(Abs(uv.y-iv));  
            ((uchar*)(dst->imageData + dst->widthStep*j))[i*3+2] = f1.z*(1-Abs(uv.y-iv))+f2.z*(Abs(uv.y-iv));  
         }  
         //这里添加上最后一列  
         ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-1)*3] = ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-2)*3];  
         ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-1)*3+1] = ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-2)*3+1];  
         ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-1)*3+2] = ((uchar*)(dst->imageData + dst->widthStep*j))[(dstWidth-2)*3+2];  
    }  
    //这里添加上最后一行  
    for(int i=0; i<dstWidth*3; i++)  
    {  
        ((uchar*)(dst->imageData + dst->widthStep*(dstHeight-1)))[i] = ((uchar*)(dst->imageData + dst->widthStep*(dstHeight-2)))[i];  
    }  
}  
