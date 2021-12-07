//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<opencv2/xfeatures2d.hpp>
//#include<math.h>
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
//	// SURF Extraction
//	int minHessian = 400;
//	Ptr<SURF> detector = SURF::create(minHessian);
//
//	vector<KeyPoint> keypoints_src;
//	vector<KeyPoint> keypoints_query;
//	Mat descriptor_src, descriptor_query;
//	detector->detectAndCompute(src, Mat(), keypoints_src, descriptor_src);
//	detector->detectAndCompute(query, Mat(), keypoints_query, descriptor_query);
//
//	// Matching
//	FlannBasedMatcher matcher;
//	vector<DMatch> matches;
//	vector<DMatch> goodMatches;
//	matcher.match(descriptor_query, descriptor_src, matches);
//
//	// Find good matched points
//	double minDist = 1000;
//	double maxDist = 0;
//	for (size_t i = 0; i < matches.size(); i++) {
//		double dist = matches[i].distance;
//		if (dist > maxDist) {
//			maxDist = dist;
//		}
//		if (dist < minDist) {
//			minDist = dist;
//		}
//	}
//
//	for (size_t i = 0; i < matches.size(); i++) {
//		double dist = matches[i].distance;
//		// If the distance is less than the double times of minDist,
//		// We conside it as a good match
//		if (dist < MAX(2 * minDist, 0.02)) {
//			goodMatches.push_back(matches[i]);
//		}
//	}
//
//	Mat result_good, result;
//	drawMatches(query, keypoints_query, src, keypoints_src, goodMatches, result_good);
//	drawMatches(query, keypoints_query, src, keypoints_src, matches, result);
//
//	imshow("Result", result);
//	imshow("Result_good", result_good);
//	waitKey(0);
//
//	return 0;
//}
//
