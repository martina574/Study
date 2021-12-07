//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, gray, dest, result;
//int threshold_min = 100;
//int threshold_max = 255;
//char input_window[] = "Input";
//void moments_demo(int, void*);
//
//int main_ImageMpments(int arg, char* arv)
//{
//
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/pill_002.png");
//
//	if (!src.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	namedWindow(input_window, WINDOW_AUTOSIZE);
//	createTrackbar("threshold_min", input_window, &threshold_min, 128, moments_demo);
//	moments_demo(0, 0);
//
//	// 0-> Prepare for edge detection
//	cvtColor(src, src, COLOR_BGR2GRAY);
//	blur(src, src, Size(3, 3));
//
//	waitKey(0);
//	return 0;
//}
//
//void moments_demo(int, void*)
//{
//	// 1-> Edge detection
//	Canny(src, dest, threshold_min, threshold_min * 2);
//
//	vector<vector<Point>> contourPoints;
//	vector<Vec4i> hierachy; // [Next, Previous, First_Child, Parent] 
//	// 2-> Find Contour
//	findContours(dest, contourPoints, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	vector<Moments> ms(contourPoints.size());
//	vector<Point2f> ccs(contourPoints.size());
//	result = Mat::zeros(dest.size(), CV_8UC3);
//	// 3-> Calculate Moments
//	for (size_t i = 0; i < contourPoints.size(); i++) {
//		ms[i] = moments(contourPoints[i]);
//		ccs[i] = Point(static_cast<float>(ms[i].m10 / ms[i].m00), 
//			static_cast<float>(ms[i].m01 / ms[i].m00));
//
//		// Draw central
//		printf("Contour %d area: %.2f, Arc length: %.2f \n.", 
//			i, contourArea(contourPoints[i]), arcLength(contourPoints[i], true));
//		circle(result, ccs[i], 5, Scalar(0, 0, 255), 2);
//		drawContours(result, contourPoints, i, Scalar(255, 255, 255));
//	}
//
//	imshow(input_window, src);
//	imshow("result", result);
//}