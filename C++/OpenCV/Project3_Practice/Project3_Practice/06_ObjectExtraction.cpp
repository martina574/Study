#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, gray, binary, dest, result;

int main() {

	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test6.PNG");
	if (!src.data) {
		cout << "Cannot find Img...\n" << endl;
		return -1;
	}

	// Deliminate white noise
	GaussianBlur(src, src, Size(15, 15), 0, 0);

	// Binarization
	cvtColor(src, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, THRESH_TRIANGLE);

	// Morphology
	Mat morphImg;
	Mat kernal = getStructuringElement(MORPH_RECT, Size(7, 7));
	morphologyEx(binary, binary, MORPH_CLOSE, kernal, Point(-1,-1), 2);

	// Contour
	vector<vector<Point>> contours;
	findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// Draw
	result = Mat::zeros(src.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++) {
		Rect rect = boundingRect(contours[i]);
		if (rect.width < src.cols / 2) continue;
		if (rect.height < src.rows / 2) continue;
		double area = contourArea(contours[i]);
		double length = arcLength(contours[i], true);
		cout << "The area is "<< area << endl;
		cout << "The length is "<< length << endl;
		drawContours(result, contours, i, Scalar(255, 255, 255));
	}

	imshow("R", result);
	waitKey(0); 
	return 0;

}