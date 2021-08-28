#include "opencv2/core/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

/* Kernel's functions prototypes */
void applyBlur(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyBW(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyCanny(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyRotate(Mat imgSrc, Mat imgDst, String imgName, String folderpath);

/* Main func */
int main()
{
	String folderpath = "../dataset/";
	vector<String> filenames;
	glob(folderpath, filenames);

	for (size_t i = 0; i < filenames.size(); i++)
	{
		Mat src = imread(filenames[i]);
		Mat dst = src.clone();

		applyCanny(src, dst, filenames[i]+"_canny.jpg", folderpath);
		applyBW(src, dst, filenames[i]+"_bw.jpg", folderpath);
		applyBlur(src, dst, filenames[i]+"_blur.jpg", folderpath);
		applyRotate(src, dst, filenames[i]+"_rotate.jpg", folderpath);
	}

	return 0;
}

void applyBlur(Mat imgSrc, Mat imgDst, String imgName, String folderpath)
{
	GaussianBlur(imgSrc, imgDst, Size(9, 9), 1.0);

	imwrite(folderpath + imgName, imgDst);
}

void applyBW(Mat imgSrc, Mat imgDst, String imgName, String folderpath)
{
	cvtColor(imgSrc, imgDst, COLOR_BGR2GRAY);

	imwrite(folderpath + imgName, imgDst);
}

void applyCanny(Mat imgSrc, Mat imgDst, String imgName, String folderpath)
{
	Canny(imgSrc, imgDst, 50, 250);

	imwrite(folderpath + imgName, imgDst);
}

void applyRotate(Mat imgSrc, Mat imgDst, String imgName, String folderpath)
{
	flip(imgSrc, imgDst, -1);

	imwrite(folderpath + imgName, imgDst);
}
