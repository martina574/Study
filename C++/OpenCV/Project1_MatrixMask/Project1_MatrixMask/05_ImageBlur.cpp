#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_Blur(int arg, char* arv)
{
	Mat src, det;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/toux.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	int cols = src.cols * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;

	//blur(src, det, Size(3, 3));
	//GaussianBlur(src, det, Size(3, 3), 2, 4);
	//medianBlur(src, det, 3);
	bilateralFilter(src, det, 5, 30, 5);
	

	imshow("input", src);
	imshow("output", det);
	waitKey(0);
	return 0;
}