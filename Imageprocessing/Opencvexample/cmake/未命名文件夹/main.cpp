    #include "opencv2/imgproc/imgproc.hpp"  
    #include "opencv2/highgui/highgui.hpp"  
    #include <iostream>  
    #include <cmath>  
      
    using namespace cv;  
    using namespace std;  
      
    
      
      
    void MyRotation(Mat& src, Mat& dst, float TransMat[3][3]);  
    int main()  
    {  
      
    
      
      Mat image;  
      image = imread("22.jpg",1);  
      if(!image.data)  
      {  
          cout << "No image data" << endl;  
          return -1;  
      }  
      
  
     
      imshow("image", image);  
        
        
      Mat dst;  
      float alpha = 21.0;  
      float transMat[3][3] = { {cos(alpha), sin(alpha), 0}, {-sin(alpha), cos(alpha), 0}, {0, 0, 1} };
      MyRotation(image, dst, transMat);   
      imshow("out_image", dst);  
      
	imwrite("out.jpg", dst);  
      
      waitKey(0);  
      return 0;  
    }  
      
void MyRotation(Mat& src, Mat& dst, float TransMat[3][3])  
    {  
         
        float left = 0;  
        float right = 0;  
        float top = 0;  
        float down = 0;  
       //  对原图像的四个点进行求旋转之后的坐标值；公式是u=x*cos(alpha)+y*sin(alpha);v=x*cos(alpha)-y*sin(alpha)
        float x = src.rows * 1.0f;  
        float y = 0.0f;  
        float u1 = x * TransMat[0][0] + y * TransMat[0][1];  
        float v1 = x * TransMat[1][0] + y * TransMat[1][1];  
        x = src.rows * 1.0f;  
        y = src.cols * 1.0f;  
        float u2 = x * TransMat[0][0] + y * TransMat[0][1];  
        float v2 = x * TransMat[1][0] + y * TransMat[1][1];  
        x = 0.0f;  
        y = src.cols * 1.0f;  
        float u3 = x * TransMat[0][0] + y * TransMat[0][1];  
        float v3 = x * TransMat[1][0] + y * TransMat[1][1];  
      
        left =  min( min( min(0.0f,u1), u2 ), u3);  //找出做左边的横坐标；
        right =  max( max( max(0.0f,u1), u2 ), u3);  //找出做右边的横坐标；
        top =  min( min( min(0.0f,v1), v2 ), v3);  //找出做顶部的纵坐标；
        down =  max( max( max(0.0f,v1), v2 ), v3);  //找出做底部的纵坐标；
      
        // 定义输出图像 
        dst.create( int(abs(down-top)),int(abs(right-left)),src.type());  //旋转之后图像的大小
          
      
       
        int i,j;  
          
        for( i = 0; i < dst.rows; ++i)  
        {  
             
            for ( j = 0; j < dst.cols; ++j)  
            {  
               	//旋转之后原点是（left,top），求出旋转之后的坐标点x1=x+left,y1=y+top
		//旋转公式
                int x = (i+left)*TransMat[0][0] + (j+top)*TransMat[1][0] ;  
                int y = (i+left)*TransMat[0][1] + (j+top)*TransMat[1][1] ;  
      
      
                if( (x >= 0) && (x < src.rows) && (y >= 0) && (y < src.cols) )   //映射
                {  
                  	dst.at<Vec3b>(i,j)[0] = src.at<Vec3b>(x,y)[0]; 
			dst.at<Vec3b>(i,j)[1] = src.at<Vec3b>(x,y)[1];
			dst.at<Vec3b>(i,j)[2] = src.at<Vec3b>(x,y)[2];  
                }  
            }  
        }  
    }  
