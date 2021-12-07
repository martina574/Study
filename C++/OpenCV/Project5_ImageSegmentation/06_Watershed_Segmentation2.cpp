//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Mat watershedCluster(Mat&, int&);
//void createDisplaySegmentation(Mat&, int, Mat&);
//
//int main() {
//	Mat src = imread("D:/•×‹­/C++/OpenCV/TestLib/toux.jpg");
//	if (src.empty()) {
//		cout << "Cannot load Image..." << endl;
//		return -1;
//	}
//
//	//imshow("Input", src);
//	int numOfSegments;
//	Mat segments = watershedCluster(src, numOfSegments);
//	createDisplaySegmentation(segments, numOfSegments, src);
//
//	waitKey(0);
//	return 0;
//}
//
//Mat watershedCluster(Mat &image, int &num) {
//	Mat gray, binary;
//	cvtColor(image, gray, COLOR_BGR2GRAY);
//	threshold(gray, binary, 0, 255, THRESH_OTSU);
//
//	Mat k;
//	k = getStructuringElement(MORPH_RECT, Size(3, 3));
//	morphologyEx(binary, binary, MORPH_OPEN, k);
//
//	Mat dist;
//	distanceTransform(binary, dist, DIST_L2, 3, CV_32F);
//	normalize(dist, dist, 0, 1, NORM_MINMAX);
//
//	threshold(dist, dist, 0.1, 1.0, THRESH_BINARY);
//	normalize(dist, dist, 0, 255, NORM_MINMAX);
//	dist.convertTo(dist, CV_8UC3);
//
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(dist, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
//	if (contours.empty()) {
//		return Mat();
//	}
//
//	Mat markers(dist.size(), CV_32S);
//	markers = Scalar::all(0);
//	for (int i = 0; i < contours.size(); i++) {
//		drawContours(markers, contours, i, Scalar(i+1), -1);
//	}
//	circle(markers, Point(5, 5), 3, Scalar(255), -1);
//
//	watershed(image, markers);
//	num = contours.size();
//
//	return markers;
//}
//
//void createDisplaySegmentation(Mat &markers, int num, Mat &image) {
//	// Generate random color
//	vector<Vec3b> colors;
//	for (int i = 0; i < num; i++) {
//		int r = theRNG().uniform(0, 255);
//		int g = theRNG().uniform(0, 255);
//		int b = theRNG().uniform(0, 255);
//		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
//	}
//
//	// Fullfill
//	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
//	int index = 0;
//	for (int row = 0; row < markers.rows; row++) {
//		for (int col = 0; col < markers.cols; col++) {
//			index = markers.at<int>(row, col);
//			if (index > 0 && index <= num) {
//				dst.at<Vec3b>(row, col) = colors[index - 1];
//			}
//			else {
//				dst.at<Vec3b>(row, col) = Vec3b(255, 255, 255);
//			}
//		}
//	}
//
//	imshow("Result", dst);
//	return;
//}