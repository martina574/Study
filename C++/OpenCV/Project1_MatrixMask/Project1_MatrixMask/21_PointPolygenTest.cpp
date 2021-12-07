#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_pointPolugenTest(int arg, char* arv)
{
	Mat src, gray, dest;
	
	const int r = 100;
	src = Mat::zeros(Size(r * 4, r * 4), CV_8UC1);

	vector<Point> vect(6);
	vect[0] = Point(3 * r / 2, static_cast<int>(1.34 * r));
	vect[1] = Point(1 * r, 2 * r);
	vect[2] = Point(3 * r / 2, static_cast<int>(2.68 * r));
	vect[3] = Point(5 * r / 2, static_cast<int>(2.68 * r));
	vect[4] = Point(3 * r, 2 * r);
	vect[5] = Point(5 * r / 2, static_cast<int>(1.34 * r));

	for (int i = 0; i < 6; i++) {
		line(src, vect[i], vect[(i + 1) % 6], Scalar(255));
	}

	// Contour
	vector<vector<Point>> contours;
	vector<Vec4i> hiers;

	findContours(src, contours, hiers, RETR_TREE, CHAIN_APPROX_SIMPLE);

	Mat raw_dist = Mat::zeros(src.size(), CV_32FC1);

	for (int row = 0; row < raw_dist.rows; row++) {
		for (int col = 0; col < raw_dist.cols; col++) {
			double dist = pointPolygonTest(contours[0], 
				Point2f(static_cast<float>(col), static_cast<float>(row)), true);

			raw_dist.at<float>(row, col) = static_cast<float>(dist);
		}
	}

	double minValue, maxValue;
	minMaxLoc(raw_dist, &minValue, &maxValue);

	Mat drawImg = Mat::zeros(src.size(), CV_8UC3);
	for (int row = 0; row < drawImg.rows; row++) {
		for (int col = 0; col < drawImg.cols; col++) {
			float dist = raw_dist.at<float>(row, col);

			if (dist > 0) {
				// The point is in the Contour
				drawImg.at<Vec3b>(col, row)[0] = (uchar)(abs(dist / maxValue * 255));
			}
			else if (dist < 0) {
				// The point is out the Contour
				drawImg.at<Vec3b>(col, row)[2] = (uchar)(abs(dist / minValue * 255));
			}
			else {
				// The point is on the Contour
				drawImg.at<Vec3b>(col, row)[0] = (uchar)255;
				drawImg.at<Vec3b>(col, row)[1] = (uchar)255;
				drawImg.at<Vec3b>(col, row)[2] = (uchar)255;
			}
		}
	}

	imshow("Input", src);
	imshow("drawImg", drawImg);

	waitKey(0);
	return 0;
}