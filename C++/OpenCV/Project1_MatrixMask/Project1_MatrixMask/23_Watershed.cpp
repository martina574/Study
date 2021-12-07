#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat src, gray;
int threshold_canny = 107;
void myWatershed(int, void *);

int main(int arg, char* arv)
{

	src = imread("D:/•×‹­/C++/OpenCV/TestLib/watershed.png");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	namedWindow("canny", WINDOW_AUTOSIZE);
	createTrackbar("threshold", "canny", &threshold_canny, 255, myWatershed);
	myWatershed(0, 0);
	
	waitKey(0);
	return 0;
}

void myWatershed(int, void *) {
	// 1-> FindEdge
	cvtColor(src, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gray, Size(3, 3), 0.2);
	Mat cannyOutput;
	Canny(gray, cannyOutput, threshold_canny, 2 * threshold_canny);

	// 2-> FindContour
	vector<vector<Point>> contourPoints;
	findContours(cannyOutput, contourPoints, RETR_TREE, CHAIN_APPROX_SIMPLE);

	// 3-> Marker
	Mat markers = Mat::zeros(cannyOutput.size(), CV_32SC1);

	for (size_t i = 0; i < contourPoints.size(); i++)
	{
		drawContours(markers, contourPoints, i, Scalar::all(i + 1), -1); // From 1 to contourSize + 1
	}


	// 4-> watershed
	watershed(src, markers);

	// 5-> Filled with color
	vector<Vec3b> colors;
	for (size_t i = 0; i < contourPoints.size(); i++)
	{
		int r = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int b = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}

	Mat dest = Mat::zeros(markers.size(), CV_8UC3);
	for (int row = 0; row < markers.rows; row++) {
		for (int col = 0; col < markers.cols; col++) {
			int index = markers.at<int>(row, col);
			if (index > 0 && index <= static_cast<int>(contourPoints.size())) {
				dest.at<Vec3b>(row, col) = colors[index - 1];
			}
			else {
				dest.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
			}
		}
	}

	markers.convertTo(markers, CV_8UC1);
	imshow("input", cannyOutput);
	imshow("output", dest);
}

