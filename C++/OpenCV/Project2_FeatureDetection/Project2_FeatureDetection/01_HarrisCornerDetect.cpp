//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//Mat src, dest, gray;
//int thres = 130;
//int thres_max = 200;
//int num_corners = 25;
//int max_corners = 200;
//
//void harris_demo(int, void*);
//void shi_tomasi_demo(int, void*);
//
//RNG rng(12345);
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/corner.png");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//	createTrackbar("Threshold", "Input", &thres, thres_max, harris_demo);
//	createTrackbar("Corners", "Input", &num_corners, max_corners, shi_tomasi_demo);
//	harris_demo(0, 0);
//	shi_tomasi_demo(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void harris_demo(int, void*) {
//	Mat hDest;
//	hDest = Mat::zeros(gray.size(), CV_32FC1);
//	cornerHarris(gray, hDest, 5, 3, 0.04); // Minus: Edge
//
//	// Debug
//	double minV, maxV;
//	minMaxLoc(hDest, &minV, &maxV);
//	cout << minV << " : " << maxV << endl;
//	// Debug end
//
//	//normalize(dest, dest, 0, 255, NORM_MINMAX, CV_32FC1);
//	normalize(hDest, hDest, 0, 255, NORM_MINMAX, CV_8UC1);
//
//	Mat hResult = src.clone();
//	for (int row = 0; row < hDest.rows; row++) {
//		for (int col = 0; col < hDest.cols; col++) {
//			if (hDest.at<uchar>(row, col) > thres) {
//				circle(hResult, Point(col, row), 2, Scalar(0, 0, 255), -1);
//			}
//		}
//	}
//
//	imshow("Input", src);
//	imshow("Harris", hResult);
//}
//
//// Note the value returned is different from Harris.
//void shi_tomasi_demo(int, void*) {
//	if (num_corners < 5) {
//		num_corners = 5;
//	}
//
//	vector<Point2f> corners;
//	double qulityLevel = 0.01;
//	double minDistance = 10;
//	
//	goodFeaturesToTrack(gray, corners, num_corners, qulityLevel, minDistance);
//
//	Mat hResult = src.clone();
//	for (size_t i = 0; i < corners.size(); i++) {
//		circle(hResult, corners[i], 2, Scalar(rng.uniform(0,255), rng.uniform(0, 255), rng.uniform(0, 255)), -1);
//	}
//
//	imshow("Input", src);
//	imshow("Shi-Tomasi", hResult);
//}