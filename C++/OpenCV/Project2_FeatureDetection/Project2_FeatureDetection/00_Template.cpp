#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main_tmp() {
	Mat src, dest, gray;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/corner.png");
	if (!src.data) {
		printf("Cound not load image ... \n");
		return -1;
	}

	cvtColor(src, gray, COLOR_BGR2GRAY);

	namedWindow("Input", WINDOW_AUTOSIZE);
	
	
	waitKey(0);

	return 0;
}

