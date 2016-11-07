#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{

    	Mat srcimage=imread("11.tif");
	if(!srcimage.data)
	{
		cout << "image read is error!" << endl;
		return 0;
	}

    	cout << "image Info:Height:" << srcimage.size().height << " Width:" << srcimage.size().width << endl;
	imshow("Original ", srcimage);
    	Mat dstimage;
   	dstimage.create(srcimage.rows,srcimage.cols,srcimage.type());
	dstimage=srcimage.clone();
 

    int r = srcimage.rows;

    int c = srcimage.cols * srcimage.channels();

   
    int i,j;

    uchar* data;
      for(i = 0; i < r; i ++)

      {

        data = dstimage.ptr<uchar>(i);
 
        for(j = 0; j < c; j ++)

        {    //最低阶比特置0；

          if(data[j]%2==1)

              	data[j] = data[j]-1;

          else

             	data[j] = data[j];
	
			

      }

     }
     imshow("Bit Level 1", dstimage);

     imwrite("Bit_Level_1.jpg", dstimage);
   
     waitKey(0);

     return 0;
}



