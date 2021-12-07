#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_tem(int arg, char* arv)
{
	Mat src, gray, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/pill_002.png");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}








	imshow("input", src);
	imshow("output", dest);
	waitKey(0);
	return 0;
}