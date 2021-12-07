//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//	Mat src, dest, gray;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/corner.png", IMREAD_GRAYSCALE);
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//
//	Mat sumii = Mat::zeros(src.rows + 1, src.cols + 1, CV_32FC1);
//	Mat sqsumii = Mat::zeros(src.rows + 1, src.cols + 1, CV_64FC1);
//	integral(src, sumii, sqsumii);
//
//	Mat resSumii;
//	Mat ressqSumii;
//	normalize(sumii, resSumii, 0, 255, NORM_MINMAX);
//	normalize(sqsumii, ressqSumii, 0, 255, NORM_MINMAX);
//
//	resSumii.convertTo(resSumii, CV_8UC1);
//	ressqSumii.convertTo(ressqSumii, CV_8UC1);
//
//	imshow("Sumii", resSumii);
//	imshow("SQSumii", ressqSumii);
//	waitKey(0);
//
//	return 0;
//}
//
