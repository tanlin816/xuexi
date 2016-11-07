#include <iostream>
#include <math.h>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat src1 = imread("Bit_Level_8.jpg");
	Mat src2 = imread("Bit_Level_7.jpg");
	Mat src3 = imread("Bit_Level_6.jpg");
	Mat src4 = imread("Bit_Level_5.jpg");
	cout << "Height:" << src1.size().height << " Width:" << src1.size().width << endl;
	cout << "Height:" << src2.size().height << " Width:" << src2.size().width << endl;
	int r = src1.rows;
	int c = src1.cols * src1.channels();
	Mat dst1 = src1.clone();
	Mat dst2 = src1.clone();
	Mat dst3 = src1.clone();
	uchar *data1;
	uchar *data2;
	uchar *data3;
	uchar *data4;
	uchar *data_end1;
	uchar *data_end2;
	uchar *data_end3;
	for(int i = 0; i < r; i ++)
		{

			data1 = src1.ptr<uchar>(i);
			data2 = src2.ptr<uchar>(i);
			data3 = src3.ptr<uchar>(i);
			data4 = src4.ptr<uchar>(i);
			data_end1 = dst1.ptr<uchar>(i);
			data_end2 = dst2.ptr<uchar>(i);
			data_end3 = dst3.ptr<uchar>(i);
     			for(int j = 0; j < c; j ++)

			{	

				data_end1[j]=(int)((double)(data1[j]/255.0)*128.0+(double)(data2[j]/255.0)*64.0);
				data_end2[j]=(int)((double)(data1[j]/255.0)*128.0+(double)(data2[j]/255.0)*64.0+(double)(data3[j]/255.0)*32.0);
				data_end3[j]=(int)((double)(data1[j]/255.0)*128.0+(double)(data2[j]/255.0)*64.0+(double)(data3[j]/255.0)*32.0+(double)(data4[j]/255.0)*16.0);
			}
		}
	imshow("restrction1", dst1);
	imwrite("restrction1.jpg", dst1);
	imshow("restrction2", dst2);
	imwrite("restrction2.jpg", dst2);
	imshow("restrction3", dst3);
	imwrite("restrction3.jpg", dst3);
	waitKey(0);
	return 0;

}
