#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
   	if ( argc != 2 )
	{
		cout<<"Wrong arguments."<<endl;
		cout<<"Usage:"<<endl;
		cout<<"\t "<<argv[0]<<"Image"<<endl;
		exit(7);
	}
	string image = argv[1];
	Mat src = imread(image,0); 
    	//图像读取有问题
    	if(!src.data)
    	{
        	cout << "image read error! please check!" << endl;
        	return 0;
    	}
    	cout << "Image Info: height:" << src.size().height << "  width:" << src.size().width << endl;
    	imshow("Original Image", src);
    	int r = src.rows;
  	int c = src.cols;
 	int n = r*c;
  	Mat dst_2(r,c,CV_8U);
	dst_2=src.clone();
 	//get the histogram of original image
  	uchar *p_1 = NULL;
 	unsigned int hist[256] = {0};
	for(int m=1;m<r-1;m++)
	{
		for(int w=1;w<c-1;w++)
		{
 			for(int i=m-1;i<m+3;i++)
 			{
     				p_1 = src.ptr<uchar>(i);
    				for(int j=w-1;j<w+3;j++)
    				{
         				hist[p_1[j]] = hist[p_1[j]]+1;//找出灰度值为j的像素点数
     				}
 			}
  		}
	}		//calculate the transform function
 	uchar transf_fun[256] = {0};//r的概率密度函数*255
 	transf_fun[0] = (uchar)(255*hist[0]/n);//0比较特殊
 	for(int i=1;i<8;i++)
 	{
     		hist[i] = hist[i-1]+hist[i];
     		transf_fun[i] = (uchar)(255*hist[i]/n);
 	}
    	//pad dst_2 the equalized values
 	uchar *p_2 = NULL;
 	for(int i=1;i<r-1;i++)
 	{
     		p_2 = dst_2.ptr<uchar>(i);
     		p_1 = src.ptr<uchar>(i);
     		for(int j=1;j<c-1;j++)
     		{
         		p_2[j] = transf_fun[p_1[j]];//对输入图像进行直方图均衡.
     		}
 	}

 	imshow("histogram equalization_own",dst_2) ;
	imwrite("ww3.jpg",dst_2);
   	waitKey(0);
	return 0;
}



