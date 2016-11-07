#include <iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{

	Mat src = imread("11.tif");
	if(!src.data)
	{
		cout << "image read is error!" << endl;
		return 0;
	}
	cout << "Height:" << src.size().height << " Width:" << src.size().width << endl;		
	imshow("Original Image",src);
	int data_max = 0,data_min = 255;
	int r = src.rows;
	int c = src.cols * src.channels();
	uchar *data;
	for(int i = 0; i < r; i ++)
	{

		data = src.ptr<uchar>(i);

     		for(int j = 0; j < c; j ++)

		{

			if(data[j] > data_max)        
				data_max = data[j];
				if(data[j] < data_min)       
		 		data_min = data[j];
		}
	}
	cout << "data_max:" << data_max << " data_min:" << data_min << endl;
	int temp = data_max - data_min;
	//对比度
	for(int i = 0; i < r; i ++)
	{
		data = src.ptr<uchar>(i);
		for(int j = 0; j < c; j ++)
		{
			data[j] = (data[j] - data_min) * 255/temp;
		}
	}
	imshow("Process Image", src);
	imwrite("result.jpg", src);
	waitKey(0);
	return 0;

}
