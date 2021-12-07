#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat src_hue;
Mat src_HSV;
int bins = 12;
void Hist_AND_Backprojection(int, void *);

int main_backprojection(int arg, char* arv)
{
	Mat src, detect, dest;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/hand_base.jpg");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/pill_002.png");

	if (!src.data or !detect.data) {
		printf("Could not find image! \n");
		return -1;
	}

	cvtColor(src, src_HSV, COLOR_BGR2HSV);

	src_hue.create(src_HSV.size(), src_HSV.depth()); 
	int nchannals[] = { 0,0 };
	// Channals copy
	mixChannels(&src_HSV, 1, &src_hue, 1, nchannals, 1);

	namedWindow("Input");
	createTrackbar("Histogram_bins", "Input", &bins, 180, Hist_AND_Backprojection);
	Hist_AND_Backprojection(0, 0);


	imshow("Input", src);
	// imshow("output", histImg);
	waitKey(0);
	return 0;
}

void Hist_AND_Backprojection(int, void  *)
{
	if (bins == 0) {
		bins += 1;
	}

	// 1.-> calculate the hist & normalize it.
	float range[] = { 0,180 };
	const float * histRange = { range };
	Mat hist;
	/*
	parameters:
	Mat * img, int nimage, int * channals, Mat mask,
	OutputArray hist, int dims, int * distSize(bins), const float ** HistRange
	*/
	calcHist(&src_hue, 1, 0, Mat(), hist, 1, &bins, &histRange);
	normalize(hist, hist, 0, 255, NORM_MINMAX);

	// 2.-> calculate the back projection.
	Mat backProjection;
	calcBackProject(&src_hue, 1, 0, hist, backProjection, &histRange);

	// Show hist
	int hist_h = 400;
	int hist_w = 400;
	Mat histImg(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	int bin_w = round(hist_w / bins);
	Mat histToDraw;
	normalize(hist, histToDraw, 0, hist_h, NORM_MINMAX);

	for (int i = 1; i < bins; i++)
	{
		rectangle(histImg,
				Point((i - 1)*bin_w, hist_h - cvRound(histToDraw.at<float>(i-1))),
				//Point(i*bin_w, hist_h - cvRound(histToDraw.at<float>(i))),
				Point(i*bin_w, hist_h),
			Scalar(0, 0, 255), -1);
	}

	// Show it
	imshow("Hist", histImg);
	imshow("backProjection", backProjection);
}