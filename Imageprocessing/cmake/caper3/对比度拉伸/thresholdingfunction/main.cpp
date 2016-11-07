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
	int r = src.rows;
	int c = src.cols * src.channels();
	uchar *data;
	int temp = 0;
	for(int i = 0; i < r; i ++)
	{

		data = src.ptr<uchar>(i);

     		for(int j = 0; j < c; j ++)

		{
			temp = data[j] + temp;
			
		}
	}
	int avg = (int)temp/(r*c);

	for(int i = 0; i < r; i ++)
	{
		data = src.ptr<uchar>(i);
		for(int j = 0; j < c; j ++)
		{
			data[j] = (data[j])/avg * 255;
		}
	} 
	imshow("Process Image", src);
	imwrite("result.jpg", src);
	waitKey(0);
	return 0;

}
