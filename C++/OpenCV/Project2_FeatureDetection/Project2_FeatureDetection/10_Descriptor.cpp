//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/xfeatures2d.hpp>
//
//using namespace std;
//using namespace cv;
//using namespace cv::xfeatures2d;
//
//int main() {
//	Mat src, query, dest, gray;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Match.png", IMREAD_GRAYSCALE);
//	query = imread("D:/•×‹­/C++/OpenCV/TestLib/box.png", IMREAD_GRAYSCALE);
//	if (!src.data || !query.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	namedWindow("Input", WINDOW_AUTOSIZE);
//
//	int minHessian = 400;
//	Ptr<SURF> detector = SURF::create(minHessian);
//
//	vector<KeyPoint> keypoints_src;
//	vector<KeyPoint> keypoints_query;
//	Mat descriptor_src, descriptor_query;
//	detector->detectAndCompute(src, Mat(), keypoints_src, descriptor_src);
//	detector->detectAndCompute(query, Mat(), keypoints_query, descriptor_query);
//
//	BFMatcher matcher;
//	vector<DMatch> matches;
//	matcher.match(descriptor_query, descriptor_src, matches);
//
//	Mat result;
//	drawMatches(query, keypoints_query, src, keypoints_src, matches, result);
//
//	imshow("Result", result);
//	waitKey(0);
//
//	return 0;
//}
//
