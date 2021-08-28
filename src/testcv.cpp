#include "opencv2/core/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std; 
using namespace cv; 

/* Kernel's functions prototypes */
void applyBlur(Mat imgSrc, Mat imgDst, String imgName);
void applyBW(Mat imgSrc, Mat imgDst, String imgName);
void applyCanny(Mat imgSrc, Mat imgDst, String imgName);
void applyRotate(Mat imgSrc, Mat imgDst, String imgName);


/* Main func */
int main()
{
	string path = "C:\\Users\\luizf\\Documents\\UFPB\\POO\\projeto1\\dataAugmentation\\dataAugmentation\\Lenaaa.jpg";

	Mat src = imread(path);
	Mat dst = src.clone();	

	applyCanny(src, dst, "Canny.jpg");
	applyBW(src, dst, "BW.jpg");
	applyBlur(src, dst, "Blur.jpg");
	applyRotate(src, dst, "Rotate.jpg");
	
	return 0;
}

void applyBlur(Mat imgSrc, Mat imgDst, String imgName) 
{
	GaussianBlur(imgSrc, imgDst, Size(9, 9), 1.0);

	imwrite(imgName, imgDst);
}

void applyBW(Mat imgSrc, Mat imgDst, String imgName) 
{
	cvtColor(imgSrc, imgDst, COLOR_BGR2GRAY);

	imwrite(imgName, imgDst);
}

void applyCanny(Mat imgSrc, Mat imgDst, String imgName) 
{
	Canny(imgSrc, imgDst, 50, 250);

	imwrite(imgName, imgDst);
}

void applyRotate(Mat imgSrc, Mat imgDst, String imgName) 
{
	flip(imgSrc, imgDst, -1); 

	imwrite(imgName, imgDst);
}
