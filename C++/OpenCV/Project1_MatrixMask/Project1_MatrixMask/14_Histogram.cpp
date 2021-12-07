#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_histogram(int arg, char* arv)
{
	Mat src, gray, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/pill_002.png");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// Histogram equalization
	//cvtColor(src, gray, COLOR_BGR2GRAY);
	//equalizeHist(gray, dest);

	// Split by channels
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	//imshow("Input", src);

	int histSize = 256;
	float range[] = { 0,256 };
	const float * histRanges = { range };
	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	int hist_h = 400;
	int hist_w = 512;

	int bin_w = hist_w / histSize;

	Mat histImg(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX);
	normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX);
	normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX);

	for (int i = 1; i < histSize; i++)
	{
		// hist_h - cvRound(b_hist.at<float>(i - 1) : change opencv coordinates to screen coordinates.
		line(histImg, Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))), \
			Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), Scalar(255,0,0), 2);

		line(histImg, Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))), \
			Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2);

		line(histImg, Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))), \
			Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2);
	}


	//imshow("input", gray);
	imshow("output", histImg);
	waitKey(0);
	return 0;
}