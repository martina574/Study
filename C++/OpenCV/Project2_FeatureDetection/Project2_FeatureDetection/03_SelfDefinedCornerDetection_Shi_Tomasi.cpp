//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//void CustomShiTomas_Demo(int, void*);
//int qualityLevel = 30;
//int max_count = 100;
//Mat src, resTomasi, gray;
//double minTomasi, maxTomasi;
//
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/corner.png");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	resTomasi = Mat::zeros(src.size(), CV_32FC1); 
//	cornerMinEigenVal(gray, resTomasi, 3);
//
//	minMaxLoc(resTomasi, &minTomasi, &maxTomasi);
//
//	namedWindow("Shi-Thomasi", WINDOW_AUTOSIZE);
//	createTrackbar("Quality Value", "Shi-Thomasi", &qualityLevel, max_count, CustomShiTomas_Demo);
//	CustomShiTomas_Demo(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void CustomShiTomas_Demo(int, void*) {
//	if (qualityLevel < 10) {
//		qualityLevel = 10;
//	}
//
//	Mat resultImg;
//	resultImg = src.clone();
//
//	float t = minTomasi + ((double)qualityLevel / max_count) * (maxTomasi - minTomasi);
//	for (int row = 0; row < resultImg.rows; row++) {
//		for (int col = 0; col < resultImg.cols; col++) {
//			float v = resTomasi.at<float>(row, col);
//			if (v > t) {
//				circle(resultImg, Point(col, row), 2, Scalar(0, 0, 255), -1);
//			}
//		}
//	}
//
//	imshow("Shi-Thomasi", gray);
//	imshow("Result", resultImg);
//}
//
