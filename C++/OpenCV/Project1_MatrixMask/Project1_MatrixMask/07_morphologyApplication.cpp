#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_morphologyA(int arg, char* arv)
{
	Mat src, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// Extract lines
	
	// 1. TO GrayScale
	Mat grayscale;
	cvtColor(src, grayscale, COLOR_RGB2GRAY);
	imshow("Gray", grayscale);

	// 2. To 2-value
	Mat binValue;
	adaptiveThreshold(grayscale, binValue, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	imshow("bin", binValue);

	// 3. Erode->Dialte: Open
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 8, 1));
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 8));

	/*Mat temp;
	erode(binValue, temp, hline);
	dilate(temp, dest, hline);*/

	/*Mat dest1, dest2;
	morphologyEx(binValue, dest1, MORPH_OPEN, hline);
	morphologyEx(binValue, dest2, MORPH_OPEN, hline);
	add(dest1, dest2, dest);
	imshow("Open", dest);*/

	/*morphologyEx(binValue, dest1, MORPH_CLOSE, hline);
	morphologyEx(binValue, dest2, MORPH_CLOSE, vline);
	add(dest1, dest2, dest);
	imshow("Close", dest);*/

	// Rect
	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat temp;
	erode(binValue, temp, kernal);
	dilate(temp, dest, kernal);

	//bitwise_not(dest, dest);
	//blur(dest, dest, Size(3, 3));

	imshow("Output", dest);
	waitKey(0);

	return 0;
}