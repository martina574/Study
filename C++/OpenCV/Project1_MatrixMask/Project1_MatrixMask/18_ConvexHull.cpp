//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, gray, dest;
//void vonvex_bull(int, void *);
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
//	blur(gray, gray, Size(3,3)); // Denoise
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//	createTrackbar("Mode", "Input", &thres, 255, vonvex_bull);
//	vonvex_bull(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void vonvex_bull(int, void *)
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
//	// 5-> convex bull
//	vector<vector<Point>> contexbulls(contours.size());
//	for (size_t i = 0; i < contours.size(); i++)
//	{
//		convexHull(contours[i], contexbulls[i]);
//	}
//
//	// 5-> Draw
//	Mat dst = Mat::zeros(src.size(), CV_8UC3);
//
//	cout << src.type() << endl;
//	cout << CV_8UC3 << endl;
//	cout << src.depth() << endl;
//
//	for (size_t i = 0; i < contours.size(); i++) 
//	{
//		Scalar col1 = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//		Scalar col2 = Scalar(255, 255, 255);
//		drawContours(dst, contours, i, col1);
//		drawContours(dst, contexbulls, i, col2);
//	}
//
//	imshow("result", dst);
//	imshow("Input", src);
//}