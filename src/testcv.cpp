#include "opencv2/core/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
   string path = "me.png";
   
   Mat src = imread(path);
   Mat dst = src.clone();
   
   cvtColor(src, dst, CV_BGR2GRAY);
   Mat dst2;
   
   Canny(dst, dst2, 100, 25);

   imwrite("test.jpg", dst2);
   return 0;
}
