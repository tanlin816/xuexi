#include <iostream>
#include<cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
Mat histogram(Mat &src);
void GenerateGaussModel(double model[]); 
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
    	imwrite("original.jpg", src);
	imshow("一维直方图13", histogram(src));
	imwrite("一维直方图13.jpg", histogram(src));
    	int r = src.rows;
  	int c = src.cols;
 	int n = r*c;
  	Mat dst_2(r,c,CV_8U);
	Mat matchhist(r,c,CV_8U);
	matchhist=src.clone();
 	//get the histogram of original image
  	uchar *p_1 = NULL;
 	unsigned int hist[256] = {0};
 	for(int i=0;i<r;i++)
 	{
     		p_1 = src.ptr<uchar>(i);
    		for(int j=0;j<c;j++)
    		{
         	hist[p_1[j]] = hist[p_1[j]]+1;
     		}
 	}
  	//calculate the transform function
 	uchar transf_fun[256] = {0};
 	transf_fun[0] = (uchar)(255*hist[0]/n);
 	for(int i=1;i<256;i++)
 	{
     		hist[i] = hist[i-1]+hist[i];
     		transf_fun[i] = (uchar)(255*hist[i]/n);
 	}
    	//pad dst_2 the equalized values
 	uchar *p_2 = NULL;
 	for(int i=0;i<r;i++)
 	{
     		p_2 = dst_2.ptr<uchar>(i);
     		p_1 = src.ptr<uchar>(i);
     	for(int j=0;j<c;j++)
     	{
         	p_2[j] = transf_fun[p_1[j]];
     	}
 	}
 	imshow("histogram equalization_own",dst_2) ;
	imwrite("ww3.jpg",dst_2);
	imshow("一维直方图23", histogram(dst_2));
	imwrite("一维直方图23s.jpg", histogram(dst_2));
	double model[256]={0};
	double G[255]={0};
	GenerateGaussModel(model);//高斯函数且归一化了
	double match=0.0;
 	for(int i=0;i<256;i++)
	{
		match=model[i]+match;	
		G[i]=255*match;
	}//加了双峰高斯函数后的结果.
	int num=0,N[256]={0};
	for(int i=0;i<256;i++)
 	{
 		double min=255.0;
     		for(int j=0;j<256;j++)
     		{	
   			if(fabs(G[j]-transf_fun[i])<min)
				{
					min=fabs(G[j]-transf_fun[i]);
					num=j;
				}
		}
		N[i] =num;
			
   	}
	uchar *p_4=NULL;
	for(int i=0;i<r;i++)
 	{
     		p_4 = matchhist.ptr<uchar>(i);
    
     		for(int j=0;j<c;j++)
     		{
         		p_4 [j] = N[p_4 [j]];
     		}
 	}
	imshow("histogram matching",matchhist) ;
	imwrite("matching.jpg",matchhist);
	imshow("一维直方图matching", histogram(matchhist));
	imwrite("一维直方图matching.jpg", histogram(matchhist));
   	waitKey(0);
	return 0;
}
Mat histogram(Mat &src)
{
	MatND dstHist;       // 在cv中用CvHistogram *hist = cvCreateHist
	int dims = 1;
	float hranges[] = {0, 255};
	const float *ranges[] = {hranges};   // 这里需要为const类型
	int size = 256;
	int channels = 0;

	//【3】计算图像的直方图
	calcHist(&src, 1, &channels, Mat(), dstHist, dims, &size, ranges);    // cv 中是cvCalcHist
	int scale = 1;

	Mat dstImage(size * scale, size, CV_8U, Scalar(0));
	//【4】获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  在cv中用的是cvGetMinMaxHistValue

	//【5】绘制出直方图
	int hpt = saturate_cast<int>(0.9 * size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);           //   注意hist中是float类型    而在OpenCV1.0版中用cvQueryHistValue_1D
		int realValue = saturate_cast<int>(binValue * hpt/maxValue);
		rectangle(dstImage,Point(i*scale, size - 1), Point((i+1)*scale - 1, size - realValue), Scalar(255));
	}
	return dstImage;

}
void GenerateGaussModel(double model[])  
{  
    double m1,m2,sigma1,sigma2,A1,A2,K;  
    m1 = 0.15;  
    m2 = 0.75;  
    sigma1 = 0.05;  
    sigma2 = 0.05;  
    A1 = 1;  
    A2 = 0.07;  
    K = 0.002;  
  
    double c1 = A1*(1.0/(sqrt(2*CV_PI))*sigma1);  
    double k1 = 2*sigma1*sigma1;  
    double c2 = A2*(1.0/(sqrt(2*CV_PI))*sigma2);  
    double k2 = 2*sigma2*sigma2;  
    double p = 0.0,val= 0.0,z = 0.0;  
    for (int zt = 0;zt < 256;++zt)  
    {  
        val = K + c1*exp(-(z-m1)*(z-m1)/k1) + c2*exp(-(z-m2)*(z-m2)/k2);  
        model[zt] = val;  
        p = p +val;  
        z = z + 1.0/256;  
    }  
    for (int i = 0;i<256; ++i)  
    {  
        model[i] = model[i]/p;  
    }  
}   

 
