#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <iostream>  
using namespace std;  
using namespace cv;
int main()
{  

	
	Mat srcimage = imread("22.tif"); 
        if(!srcimage.data)

   {

        cout << "image read is error!" << endl;

        return 0;

    }
        cout << "image Info:Height:" << srcimage.size().height << " Width:" << srcimage.size().width << endl; 
	imshow("原始图像",srcimage);  
        imwrite("k=8.bmp",srcimage);
	//按原始图的参数规格来创建创建效果图
	Mat dstimage1;
        Mat dstimage2;
        dstimage1.create(srcimage.rows,srcimage.cols,srcimage.type());
	dstimage2.create(srcimage.rows,srcimage.cols,IPL_DEPTH_1U);//效果图的大小、类型与原图片相同 

	int a[6]={2,4,8,16,32,64};
        int r = srcimage.rows;  //行数
	int c = srcimage.cols;  //列数
        for(int w=0;w<6;w++)
          {
	   

	    for(int i = 0;i < r;i++)  
		{  
		   for(int j = 0;j < c;j++)  
			{  	
		
			  dstimage1.at<Vec3b>(i,j)[0] = srcimage.at<Vec3b>(i,j)[0]/a[w];  //蓝色通道
			  dstimage1.at<Vec3b>(i,j)[1] = srcimage.at<Vec3b>(i,j)[1]/a[w] ;  //绿色通道
			  dstimage1.at<Vec3b>(i,j)[2] = srcimage.at<Vec3b>(i,j)[2]/a[w];  //红是通道
                         
			
			}       
		} 


           string str[6]={"k=7.jpg","k=6.jpg","k=5.jpg","k=4.jpg","k=3.jpg","k=2.jpg"};
	   imshow(str[w],dstimage1);
           imwrite(str[w],dstimage1); 
           
          } 
          for(int i = 0;i < r;i++)  
		{  
                   uchar* a=dstimage1.ptr<uchar>(i);
                   uchar* b=dstimage2.ptr<uchar>(i);
		   for(int j = 0;j < c;j++)  
			{

  	                 b[j]=a[j]/2;
		        }   

                }
            imshow("dd",dstimage2);
           imwrite("k=1.jpg",dstimage2);

	waitKey(0); 
        return 0;  
}  



