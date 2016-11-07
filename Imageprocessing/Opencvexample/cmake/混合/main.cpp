#include <iostream>
#include <opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
int main()
{
  Mat image=imread("11.jpg",15);
  Mat logo=imread("22.jpg");
  imshow("landspace",image);
  imshow("logo",logo);
  Mat ROI;
  ROI=image(Rect(5,3,logo.cols,logo.rows));
  addWeighted(ROI,0.5,logo,0.3,0.,ROI);
  imshow("融合图",image);
  imwrite("save.jpg",image);
   waitKey(0);
  return 0;

}


