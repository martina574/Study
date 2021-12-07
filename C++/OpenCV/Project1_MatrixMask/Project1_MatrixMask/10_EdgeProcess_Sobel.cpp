#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_Sobel(int arg, char* arv)
{
	Mat src, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// 1, Gaussian Blur
	GaussianBlur(src, dest, Size(3, 3), 1.2, 1, 2);

	// 2, ToGrayScale
	cvtColor(dest, dest, COLOR_BGR2GRAY);

	// 3, Sobel: calculate gradient
	Mat gradient_x, gradient_y, gradient, G;
	//G = Mat(dest.size(), dest.type());
	Sobel(dest, gradient_x, CV_16S, 1, 0); // Gradient: x
	Sobel(dest, gradient_y, CV_16S, 0, 1); // Gradient: y

	convertScaleAbs(gradient_x, gradient_x);
	convertScaleAbs(gradient_y, gradient_y);

	//addWeighted(gradient_x, 0.5, gradient_y, 0.5, 0, gradient);
	add(gradient_x, gradient_y, gradient);

	//for (int row = 0; row < src.rows; row++)
	//{
	//	for (int col = 0; col < src.cols; col++)
	//	{
	//		int xg = gradient_x.at<uchar>(row, col);
	//		int yg = gradient_y.at<uchar>(row, col);

	//		int xy = xg + yg;
	//		//G.at<uchar>(row, col) = saturate_cast<uchar>(xy);
	//		G.at<uchar>(row, col) = xy;
	//	}
	//}

	// 3-Scharr
	Scharr(dest, gradient_x, CV_16S, 1, 0);
	Scharr(dest, gradient_y, CV_16S, 0, 1);

	convertScaleAbs(gradient_x, gradient_x);
	convertScaleAbs(gradient_y, gradient_y);

	add(gradient_x, gradient_y, G);

	imshow("input", src);
	imshow("Sobel", gradient);
	imshow("Scharr", G);
	waitKey(0);
	return 0;
}