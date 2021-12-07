//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//void CustomHarris_Demo(int, void*);
//int qualityLevel = 30;
//int max_count = 100;
//Mat src, dest, gray;
//Mat harrisRspImg;
//double minHarris, maxHarris;
//
//int main() {
//	src = imread("D:/勉強/C++/OpenCV/TestLib/corner.png");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	// コーナーを検出するために，画像ブロックの固有値と固有ベクトルを求めます．
//	dest = Mat::zeros(src.size(), CV_32FC(6));  // float [6]
//	cornerEigenValsAndVecs(gray, dest, 3, 3);
//
//	float k = 0.04;
//	harrisRspImg = Mat::zeros(src.size(), CV_32FC1);
//	for (int row = 0; row < gray.rows; row++) {
//		for (int col = 0; col < gray.cols; col++) {
//			double lambda1 = dest.at<Vec6f>(row, col)[0];
//			double lambda2 = dest.at<Vec6f>(row, col)[1];
//
//			harrisRspImg.at<float>(row, col) = lambda1 * lambda2 - k * pow((lambda1 + lambda2), 2);
//		}
//	}
//
//	minMaxLoc(harrisRspImg, &minHarris, &maxHarris);
//	cout << minHarris << ":" << maxHarris << endl;
//	namedWindow("Harris", WINDOW_AUTOSIZE);
//	createTrackbar("Quality Value", "Harris", &qualityLevel, max_count, CustomHarris_Demo);
//	CustomHarris_Demo(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void CustomHarris_Demo(int, void*) {
//	if (qualityLevel < 10) {
//		qualityLevel = 10;
//	}
//
//	Mat resultImg;
//	resultImg = src.clone();
//
//	float t = minHarris + ((double)qualityLevel / max_count) * (maxHarris - minHarris);
//	for (int row = 0; row < harrisRspImg.rows; row++) {
//		for (int col = 0; col < harrisRspImg.cols; col++) {
//			float v = harrisRspImg.at<float>(row, col);
//
//			if (v > t) {
//				circle(resultImg, Point(col, row), 2, Scalar(0, 0, 255), -1);
//			}
//		}
//	}
//
//	imshow("Harris", gray);
//	imshow("Result", resultImg);
//}
//
