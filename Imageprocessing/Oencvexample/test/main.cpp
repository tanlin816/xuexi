#include <iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
Mat function1()
{
  Mat image=imread("11.jpg");
  imshow("图1",image);
  waitKey(0);
  return image;
}

void function2(Mat a)
{
  Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
  Mat dstimg;
  erode(a,dstimg,element);
  imshow("图2",dstimg);
  waitKey(0);
}

int main()
{
   Mat proc=function1();
   function2(proc);
   return 0;
}
