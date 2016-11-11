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
 	int t = r*c;
  	Mat dst_2(r,c,CV_8U);
	dst_2=src.clone();
 	//get the histogram of original image
  	uchar *p_1 = NULL;
	uchar *p_2 = NULL;
 	unsigned int hist[256] = {0};
	uchar transf_fun[256] = {0};//r的概率密度函数*255
	int m=3,n=3,num=0;
	for (int i = m / 2;i < r-m / 2;i++){
		p_1 = src.ptr<uchar>(i);
		p_2 = dst_2.ptr<uchar>(i);	
		for (int j = n / 2 ;j < c-n / 2;j++){
			for(int k = i - m / 2 ;k < i + m / 2;k++){
				
				for(int w = j - n / 2 ;w < j + n / 2;w++){
         				hist[p_1[w]]= hist[p_1[w]]+1;//找出灰度值为j的像素点数
     				}
 			}
			
			if(j=n/2)
			{	
				for(int k = 0;k < 3;k++){
				
					for(int w = 1 ;w < 3;w++){
         					hist[p_1[w]] = hist[p_1[w-1]]+hist[p_1[w]];
						num=w;
     					}
 				}
				p_2[1] =  (uchar)(255*hist[p_1[num]]/t);
			}
			else
			{	for(int k = i - m / 2 ;k < i + m / 2;k++){
				
					for(int w = j - n / 2 ;w < j + n / 2;w++){
         					hist[p_1[w]] = hist[p_1[w-1]]+hist[p_1[w]];
						num=w;
     					}
 				}
			
				p_2[j] =  (uchar)(255*hist[p_1[num]]/t);
			}
					
  		}
	}	
 	

    	

 	imshow("histogram equalization_own",dst_2) ;
	imwrite("ww3.jpg",dst_2);
   	waitKey(0);
	return 0;
}



