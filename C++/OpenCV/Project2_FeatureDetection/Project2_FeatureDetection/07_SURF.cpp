//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/xfeatures2d.hpp>
//
//using namespace std;
//using namespace cv;
//using namespace cv::xfeatures2d;
//
//int main() {
//	Mat src, src2, dest, gray;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png", IMREAD_GRAYSCALE);
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	// From here
//	int minHessian = 400;
//	Ptr<SURF> detector = SURF::create(minHessian);
//	vector<KeyPoint> keypoints;
//	detector->detect(src, keypoints);
//
//	Mat kpImg;
//	drawKeypoints(src, keypoints, kpImg);
//
//	imshow("Output", kpImg);
//	//imshow("Output", ressqSumii);
//	//waitKey(0);
//
//	return 0;
//}
//
