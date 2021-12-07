//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, gray, dest;
//void Contours_callback(int, void *);
//int thres = 100;
//int thres_max = 255;
//RNG rng(12345);
//
//int main(int arg, char* arv)
//{
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
//	// 1-> ToGray
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//	blur(gray, gray, Size(3, 3)); // Denoise
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//	createTrackbar("Mode", "Input", &thres, 255, Contours_callback);
//	Contours_callback(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void Contours_callback(int, void *)
//{
//	// 2-> Binariozation
//	threshold(gray, dest, thres, thres_max, THRESH_BINARY);
//
//	// 3-> Find contour
//	vector<vector<Point>> contours;
//	vector<Vec4i> heirachy;
//
//	// 4-> findContours
//	findContours(dest, contours, heirachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	// 5-> Draw around the contours
//	Mat dst = Mat::zeros(src.size(), src.type());
//	vector<vector<Point>> polyDC(contours.size());
//	vector<Point2f> centers(contours.size());
//	vector<float> radius(contours.size());
//
//	vector<RotatedRect> rRects(contours.size());
//	vector<RotatedRect> rCircle(contours.size());
//
//	Point2f rectPoints[4];
//
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		approxPolyDP(contours[i], polyDC[i], 3, true);
//
//		Rect ret0 = boundingRect(polyDC[i]);
//		minEnclosingCircle(polyDC[i], centers[i], radius[i]);
//
//		if (polyDC[i].size() > 5) {
//			rCircle[i] = fitEllipse(polyDC[i]);
//			rRects[i] = minAreaRect(polyDC[i]);
//		}
//		else {
//			rCircle[i] = fitEllipse(contours[i]);
//			rRects[i] = minAreaRect(contours[i]);
//		}
//
//		rRects[i].points(rectPoints);
//
//		// Draw
//		rectangle(dst, ret0, Scalar(255, 255, 255));
//		circle(dst, centers[i], radius[i], Scalar(0, 0, 255));
//
//		ellipse(dst, rCircle[i], Scalar(0, 255, 255));
//
//		// The way to draw rotated rectangle.
//		for (int j = 0; j < 4; j++) {
//			line(dst, rectPoints[j], rectPoints[(j+1) % 4], Scalar(255, 255, 0));
//		}
//	}
//
//	imshow("result", dst);
//	imshow("Input", src);
//}