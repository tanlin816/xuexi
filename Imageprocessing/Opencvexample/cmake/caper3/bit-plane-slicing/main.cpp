#include <iostream>
#include <math.h>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
//比特平面，代替突出灰度级范围，突出特定比特来为整个图像外观做出贡献。（数字图像处理（中卫第3版））下面的例子是该书上使用的实例。这里在matlab中进行实现，帮助大家理解，同时请大家提出宝贵的修改意见。思想：使用书中的图片（到官网进行下载），在8比特下，遍历整个图像，用像素值与各比特面的值（2^（n-1）,n为比特面）进行位与操作，判断该像素值在该比特面是否存在即该比特位是否为1，如果存在进行二值化给该像素值所在位赋值为255，这也是突出显示该比特的核心，否则赋值0。
	Mat src = imread("11.tif");
	if(!src.data)
	{
		cout << "image read is error!" << endl;
		return 0;
	}
	cout << "Height:" << src.size().height << " Width:" << src.size().width << endl;		
	imshow("Original Image",src);
	Mat dst = src.clone();
	int r = src.rows;
	int c = src.cols * src.channels();
	uchar *data;
	uchar *data_end;
	int b;
	for(int n=1;n<=8;n++)
	{
		b = pow(2, n - 1);	
	//bit分面用位与
	
		for(int i = 0; i < r; i ++)
		{

			data = src.ptr<uchar>(i);
			data_end = dst.ptr<uchar>(i);
     			for(int j = 0; j < c; j ++)

			{	

				int d=data[j]&b;
				if( b==d)
					data_end[j] = 255;
				else  
					data_end[j] = 0;
			}
		}
		switch(n)
	 	{
			case 1:
				imshow("Bit Level 1", dst);
				imwrite("Bit_Level_1.jpg",dst);
				break;
			case 2:
				imshow("Bit Level 2", dst);
				imwrite("Bit_Level_2.jpg", dst);
				break;
			case 3:
				imshow("Bit Level 3", dst);
				imwrite("Bit_Level_3.jpg", dst);
				break;
			case 4:
				imshow("Bit Level 4", dst);
				imwrite("Bit_Level_4.jpg", dst);
				break;
			case 5:
				imshow("Bit Level 5", dst);
				imwrite("Bit_Level_5.jpg", dst);
				break;
			case 6:
				imshow("Bit Level 6", dst);
				imwrite("Bit_Level_6.jpg", dst);
				break;
			case 7:
				imshow("Bit Level 7", dst);
				imwrite("Bit_Level_7.jpg", dst);
				break;
			case 8:
				imshow("Bit Level 8", dst);
				imwrite("Bit_Level_8.jpg", dst);
				break;
			default:break;

		}
	}
	waitKey(0);
	return 0;

}
