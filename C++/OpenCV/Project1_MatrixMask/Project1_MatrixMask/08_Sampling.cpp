#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_sampling(int arg, char* arv)
{
	Mat src, dest1, dest2, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// Gaussian Pyramid
	/*pyrUp(src, dest1, Size(src.cols * 2, src.rows * 2));
	pyrDown(src, dest2, Size(src.cols / 2, src.rows / 2));*/

	// Difference of Gaussian
	Mat src_gray;
	cvtColor(src, src_gray, COLOR_RGB2GRAY);

	GaussianBlur(src_gray, dest1, Size(3, 3), 0, 0);
	GaussianBlur(src_gray, dest2, Size(3, 3), 2.2, 2.2);

	subtract(dest1, dest2, dest);
	normalize(dest, dest, 255, 0, NORM_MINMAX);
	
	//imshow("input", src);
	imshow("output", dest);
	imshow("output1", dest1);
	imshow("output2", dest2);
	waitKey(0);
	return 0;
}