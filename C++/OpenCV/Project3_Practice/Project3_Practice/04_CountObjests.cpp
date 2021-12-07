#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, dest, result;

int main() {
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test4.PNG", IMREAD_GRAYSCALE);
	if (!src.data) {
		printf("Cannot find img... \n");
		return -1;
	}

	// Binarization
	Mat binaryImg;
	// Single Peak
	threshold(src, binaryImg, 0, 255, THRESH_BINARY | THRESH_TRIANGLE);

	// Eliminate the white noise
	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(binaryImg, binaryImg, kernal, Point(-1, -1), 1);

	// Distance Transform
	Mat dist;
	bitwise_not(binaryImg, binaryImg);
	distanceTransform(binaryImg, dist, DIST_L2, 3);
	normalize(dist, dist, 0, 1.0, NORM_MINMAX);

	// Binarization
	// Method 1: You may notice that it does not work so well, Because the connected parts can not
	//           be sepretated properly.
	// threshold(dist, dist, 0.6, 1.0, THRESH_BINARY);

	// Method 2: Locality adaptice method.
	threshold(dist, dist, 0.55, 1.0, THRESH_TOZERO);
	Mat adaptBinImg;
	dist.convertTo(adaptBinImg, CV_8UC1);
	adaptiveThreshold(adaptBinImg, adaptBinImg, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 121, 0.0);
	
	// Connect the contours
	Mat rt;
	Mat k = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(adaptBinImg, rt, k, Point(-1, -1), 3);

	// Count them
	vector<vector<Point>> contours;
	findContours(rt, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	RNG rng(12345);
	result = Mat::zeros(src.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++) {
		Scalar cl = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(result, contours, i, cl, -1);
	}
	
	imshow("result", result);
	cout<< contours.size() <<endl;
	
	waitKey(0);
	return 0;
}