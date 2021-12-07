//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, gray, dest;
//void contour_demo(int, void *);
//int thres = 0;
//
//int main_contour(int arg, char* arv)
//{
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/pill_002.png");
//
//	if (!src.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	// 1-> ToGray
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//	createTrackbar("Mode", "Input", &thres, 255, contour_demo);
//	contour_demo(0, 0);
//
//	//imshow("input", src);
//	//imshow("output", dest);
//	waitKey(0);
//	return 0;
//}
//
//void contour_demo(int, void *)
//{
//	// 2-> Canny: the low:high threshold set to be 1:2 ot 1:3 to get a good value.
//	Canny(gray, dest, thres, thres*2);
//
//	// Find contour
//	vector<vector<Point>> contours;
//	vector<Vec4i> heirachy;
//	
//	// findContours
//	findContours(dest, contours, heirachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	// drawContours
//	RNG rng(12345);
//	Mat cont = Mat::zeros(src.size(), CV_8UC3);
//	Mat cont1 = Mat::zeros(src.size(), CV_8UC3);
//	for (size_t i = 0; i < contours.size(); i++) 
//	{
//		Scalar col = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		drawContours(cont, contours, i, col, 2, 8, heirachy, 0);
//		//drawContours(cont1, contours, i, col, 2, 8, heirachy, 1);
//	}
//
//	imshow("contour", cont);
//	//imshow("contour1", cont1);
//	imshow("Input", src);
//}