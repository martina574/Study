//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int corners_num = 30;
//int max_count = 100;
//Mat src, resTomasi, gray;
//void subpix_demo(int, void*);
//
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/corner.png");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	namedWindow("output", WINDOW_AUTOSIZE);
//	createTrackbar("corner num", "output", &corners_num, max_count, subpix_demo);
//	subpix_demo(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void subpix_demo(int, void*) {
//	if (corners_num < 10) {
//		corners_num = 10;
//	}
//	vector<Point2f> corners;
//	double qualityLevel = 0.01;
//	int minDistance = 10;
//
//	Mat result;
//	result = src.clone();
//
//	goodFeaturesToTrack(gray, corners, corners_num, qualityLevel, minDistance);
//	for (size_t i = 0; i < corners.size(); i++) {
//		circle(result, corners[i], 2, Scalar(0, 0, 255));
//	}
//	
//	Size winSize = Size(5, 5);
//	Size zeroZone = Size(-1, -1);
//	TermCriteria tc = TermCriteria(TermCriteria::EPS + TermCriteria::MAX_ITER, 40, 0.001);
//
// 	cornerSubPix(gray, corners, winSize, zeroZone, tc);
//	for (size_t i = 0; i < corners.size(); i++) {
//		circle(result, corners[i], 2, Scalar(255, 0, 0));
//	}
//
//	imshow("output", result);
//}