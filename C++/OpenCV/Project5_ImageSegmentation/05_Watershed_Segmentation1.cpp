#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {
	Mat src = imread("D:/勉強/C++/OpenCV/TestLib/pill_002.png");
	if (src.empty()) {
		cout << "Cannot load Image..." << endl;
		return -1;
	}

	Mat gray, binary, shifted;
	pyrMeanShiftFiltering(src, shifted, 21, 51); // Denoise: 边缘保留滤波
	//imshow("Shifted", shifted);

	cvtColor(shifted, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 0, 255, THRESH_OTSU);
	//imshow("Binary", binary);

	// Distance transform
	Mat dist;
	distanceTransform(binary, dist, DIST_L2, 3, CV_32F);
	normalize(dist, dist, 0, 1, NORM_MINMAX);
	//imshow("DistranceTransform", dist);

	// Binary
	threshold(dist, dist, 0.4, 1, THRESH_BINARY);

	// Contours
	Mat dist_m;
	dist.convertTo(dist_m, CV_8U);
	vector<vector<Point>> contours;
	findContours(dist_m, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	// Create Markers
	Mat markers = Mat::zeros(src.size(), CV_32SC1);
	for (size_t t = 0; t < contours.size(); t++) {
		drawContours(markers, contours, t, Scalar::all(t + 1), -1);
	}
	circle(markers, Point(5, 5), 3, Scalar(255), -1);
	
	// Morphology: Denoise
	Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(src, src, MORPH_ERODE, k);

	// Watershed
	watershed(src, markers);
	Mat mark = Mat::zeros(markers.size(), CV_8UC1);
	markers.convertTo(mark, CV_8UC1);
	bitwise_not(mark, mark, Mat());
	imshow("Result", mark);

	// Generate random color
	vector<Vec3b> colors;
	for (int i = 0; i < contours.size(); i++) {
		int r = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int b = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}

	// Fullfill
	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	int index = 0;
	for (int row = 0; row < markers.rows; row++) {
		for (int col = 0; col < markers.cols; col++) {
			index = markers.at<int>(row, col);
			if (index > 0 && index <= contours.size()) {
				dst.at<Vec3b>(row, col) = colors[index - 1];
			}
			else {
				dst.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
			}
		}
	}

	imshow("Result", dst);
	printf("Num of objects: %d", contours.size());
	waitKey(0);
	return 0;

}