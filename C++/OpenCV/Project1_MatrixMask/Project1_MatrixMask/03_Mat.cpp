#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_2(int arg, char* arv)
{
	Mat src;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// How to create a Matrix--1
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(127, 0, 255);

	// How to create a Matrix--2
	src.copyTo(dst);

	// How to create a Matrix--3
	dst = src.clone();

	cvtColor(src, dst, COLOR_BGR2GRAY);
	printf("Input Image channels: %d \n", src.channels());
	printf("Output Image channels: %d \n", dst.channels());

	const uchar* firstRow = src.ptr<uchar>(0);
	printf("Fist pixel value: %d \n", *firstRow);

	// How to create a Matrix--4
	Mat M(100, 100, CV_8UC1, Scalar(127));
	
	// How to create a Matrix--5
	Mat m1;
	m1.create(src.size(), src.type());
	m1 = Scalar(0, 0, 255);

	// How to create a Matrix--6
	Mat kernal = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, -1, kernal);

	imshow("input", src);
	imshow("Test", m1);
	imshow("onput", dst);
	waitKey(0);

	return 0;
}