#include "opencv2/core/core.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <filesystem>
#include <chrono>

using namespace std;
using namespace cv;

/* Kernel's functions prototypes */
void applyBlur(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyBW(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyCanny(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void applyRotate(Mat imgSrc, Mat imgDst, String imgName, String folderpath);
void showFiles(String folderpath);

/* Main func */
int main()
{
	String folderpath;// = "C:\\Users\\luizf\\Pictures\\images_for_tests";
	vector<String> filenames;
	char flagBl, flagBw, flagCa, flagRo;
	
	cout << "\n\t\t*** Data Augmentation ***\n" << endl;
	cout << "Type the folderpath: ";
	cin >> folderpath;

	glob(folderpath, filenames);

	cout << "\n\tNow, choose the options of efects: \n" << endl;
	cout << "Gaussian Blur [y/n]: ";
	cin >> flagBl;
	cout << "Black and White [y/n]: ";
	cin >> flagBw;
	cout << "Canny [y/n]: ";
	cin >> flagCa;
	cout << "Rotate [y/n]: ";
	cin >> flagRo;

	// make all lower
	tolower(flagBl);
	tolower(flagBw);
	tolower(flagCa);
	tolower(flagRo);

	auto t1 = chrono::high_resolution_clock::now(); // check the execution time
	for (size_t i = 0; i < filenames.size(); i++)
	{	
		// This is for take just the name of the file 
		int find_the_bar = filenames[i].rfind("\\"); // In the linux, this is probably will change
		int find_the_point = filenames[i].rfind(".");
		string nameOut = filenames[i].substr(find_the_bar, find_the_point - find_the_bar);
		Mat src = imread(filenames[i]);
		Mat dst = src.clone();

		if (flagBl == 'y')
		{
			applyBlur(src, dst, nameOut + "_blur.jpg", folderpath);
		}
		if (flagBw == 'y')
		{ 
			applyBW(src, dst, nameOut + "_bw.jpg", folderpath);
		}
		if (flagCa == 'y')
		{
			applyCanny(src, dst, nameOut + "_canny.jpg", folderpath);
		}
		if (flagRo == 'y')
		{
			applyRotate(src, dst, nameOut + "_rotate.jpg", folderpath);
		}

		cout << "Progess: " << i + 1 << " of " << filenames.size() << endl;
	}

	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> ms = t2 - t1;
	cout << "\nFinish.\n" << endl;
	cout << "Execution time : " << ms.count() << " ms" << endl;

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

// Não consegui rodar o filesystem aq, ai comentei por enqt
/*
void showFiles(String folderpath)
{
	string path = folderpath;
	for (const auto& entry : filesystem::directory_iterator(path))
		cout << entry.path();
	system("pause");

}
*/