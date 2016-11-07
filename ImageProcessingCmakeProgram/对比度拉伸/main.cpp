 #include <opencv2/core/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <opencv2/highgui/highgui.hpp>

 
#include <iostream>

 

using namespace :: std;

using namespace :: cv;

 

int main()

{

//图像读取

Mat image = imread("11.jpeg",0);

 
//判断图像读取是否有问题

if(!image.data)

{

cout << "image read is error!" << endl;

return 0;

}

 

//图像基本信息输出

cout << "image Info:Height:" << image.size().height << " Width:" << image.size().width << endl;

 

//原始图像显示

namedWindow("Original Image");

imshow("Original Image", image);

imwrite("original.jpg", image);

 

//处理图像 

int data_max = 0,data_min = 511;

int nl = image.rows;

int nc = image.cols * image.channels();

if(image.isContinuous())

{

nc = nc * nl;

nl = 1;

}

int i,j;

uchar *data;

for(j = 0; j < nl; j ++)

{

data = image.ptr<uchar>(j);

for(i = 0; i < nc; i ++)

{

if(data[i] > data_max)        data_max = data[i];

if(data[i] < data_min)        data_min = data[i];

}

}

 

cout << "data_max:" << data_max << " data_min:" << data_min << endl;

 

int temp = data_max - data_min;

//对比度

for(j = 0; j < nl; j ++)

{

data = image.ptr<uchar>(j);

for(i = 0; i < nc; i ++)

{

data[i] = (data[i] - data_min) * 511/temp;

//拉伸对比度公式

}

}

 

//显示图像

namedWindow("Process Image");

imshow("Process Image", image);

 

//保存图像

imwrite("result.JPG", image);

 

waitKey(0);

 

return 0;

}
