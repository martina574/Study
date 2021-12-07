#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_Laplace(int arg, char* arv)
{
	Mat src, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// 1, Gaussian Blur
	GaussianBlur(src, dest, Size(3, 3), 1.2, 1.2);

	// 2, ToGrayScale
	cvtColor(dest, dest, COLOR_BGR2GRAY);

	// 3, Laplace: calculate gradient
	Mat gradient;
	Laplacian(dest, gradient, CV_16S, 3);

	convertScaleAbs(gradient, gradient);
	threshold(gradient, gradient, 0, 255, THRESH_OTSU);

	imshow("input", src);
	imshow("Laplace", gradient);
	waitKey(0);
	return 0;
}