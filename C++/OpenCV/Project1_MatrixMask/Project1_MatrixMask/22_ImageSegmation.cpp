#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_segmentation(int arg, char* arv)
{
	Mat src, gray;
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/watershed.png");
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/watershed_2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// 1-> Change background
	// The pic we used is not necessary to change the background.
	/*for (int row = 0; row < src.rows; row++){
		for (int col = 0; col < src.cols; col++) {
			if (src.at<Vec3b>(row, col) == Vec3b(255, 255, 255)) {
				src.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
			}
		}
	}*/

	// 2-> Sharpen
	Mat kernal = (Mat_<float>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1); // Laplacian operator
	Mat imgLaplance;
	// L transform to get the edges
	filter2D(src, imgLaplance, CV_32F, kernal); // Laplacan calculate the float.

	Mat srcImg = src;
	src.convertTo(srcImg, CV_32F);
	// - edge to strengthen the edges.
	Mat resultImg = srcImg - imgLaplance;

	resultImg.convertTo(resultImg, CV_8UC3);
	imgLaplance.convertTo(imgLaplance, CV_8UC3);

	// 3-> Binarization
	Mat binaryImg;
	cvtColor(resultImg, resultImg, COLOR_BGR2GRAY);
	//threshold(resultImg, binaryImg, 0, 255, THRESH_OTSU);
	threshold(resultImg, binaryImg, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

	// 4-> Distance Transform
	Mat distImg;
	distanceTransform(binaryImg, distImg, DIST_L1, 3);
	normalize(distImg, distImg, 0, 1, NORM_MINMAX);
	threshold(distImg, distImg, 0.3, 1, THRESH_BINARY);

	// 5-> Erode
	Mat k = Mat::ones(3, 3, CV_8UC1);
	erode(distImg, distImg, k);

	// 6-> findContour
	Mat dist_8u;

	distImg.convertTo(dist_8u, CV_8U);// Here you can give the parameter outputArray & depth.
	                                  // The depth may meant the size of the Img without the channal digree.
									  // distImg.type() -> float

	vector<vector<Point>> contourPoints;
	findContours(dist_8u, contourPoints, RETR_TREE, CHAIN_APPROX_SIMPLE);

	// 7-> drawContours
	Mat markers = Mat::zeros(src.size(), CV_32SC1); // THE parameter need to be set to  CV_32SC1
	for (size_t i = 0; i < contourPoints.size(); i++) {
		drawContours(markers, contourPoints, static_cast<int>(i), Scalar::all(static_cast<int>(i) + 1), -1);
	}
	circle(markers, Point(5, 5), 3, Scalar(255), -1);

	// 8-> watershed
	watershed(src, markers);
	Mat mark;
	markers.convertTo(mark, CV_8UC1);
	bitwise_not(mark, mark);

	// * generate random color
	vector<Vec3b> colors;
	for (size_t i = 0; i < contourPoints.size(); i++)
	{
		int r = theRNG().uniform(0, 255);
		int g = theRNG().uniform(0, 255);
		int b = theRNG().uniform(0, 255);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}

	// fill color and show the final result
	Mat dest = Mat::zeros(markers.size(), CV_8UC3);
	for (int row = 0; row < markers.rows; row++){
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

	imshow("input", src);
	imshow("output", dest);
	waitKey(0);
	return 0;
}

