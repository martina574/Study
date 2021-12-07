#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int t1_value = 50;
int max_value = 174;

void canny_demo(int, void*);
Mat src_canny, gray_canny, dest_canny;

int main_canny(int arg, char* arv)
{
	src_canny = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src_canny.data) {
		printf("Could not find image! \n");
		return -1;
	}

	cvtColor(src_canny, gray_canny, COLOR_BGR2GRAY);

	namedWindow("Canny", WINDOW_AUTOSIZE);
	createTrackbar("t2_value", "Canny", &t1_value, max_value, canny_demo);
	canny_demo(0,0);

	waitKey(0);
	return 0;
}

void canny_demo(int, void*) 
{
	Mat edge_output;
	GaussianBlur(gray_canny, edge_output, Size(3, 3), 1.2, 1.2);
	Canny(edge_output, edge_output, t1_value, t1_value * 2);
	
	dest_canny.create(src_canny.size(), src_canny.type());

	src_canny.copyTo(dest_canny, edge_output);
	//imshow("Canny", dest_canny);
	imshow("Canny", edge_output);
	//imshow("Canny", ~edge_output);
}