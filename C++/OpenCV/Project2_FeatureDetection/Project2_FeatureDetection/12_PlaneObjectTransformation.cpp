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
//	// detect-> keypoints
//	// compute-> descriptor
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
//	// You should always pay attention to the goodMatches.
//	// To little matches may lead to unprecitous result.
//	for (size_t i = 0; i < matches.size(); i++) {
//		double dist = matches[i].distance;
//		// If the distance is less than the double times of minDist,
//		// We conside it as a good match
//		if (dist < MAX(3 * minDist, 0.02)) {
//			goodMatches.push_back(matches[i]);
//		}
//	}
//
//	Mat result_good, result;
//	drawMatches(query, keypoints_query, src, keypoints_src, goodMatches, result_good);
//	imshow("Result_good", result_good);
//
//	// New Contents From here
//	vector<Point2f> obj;
//	vector<Point2f> objInScene;
//	for (size_t i = 0; i < goodMatches.size(); i++) {
//		// match->queryIdx: query descriptor index
//		// match->trainIdx: train descriptor index
//		// keypoint->pt:x & y coordinates of the keypoint
//		obj.push_back(keypoints_query[goodMatches[i].queryIdx].pt);
//		objInScene.push_back(keypoints_src[goodMatches[i].trainIdx].pt);
//	}
//
//	// Caculate the transform matrix
//	Mat H = findHomography(obj, objInScene, RANSAC);
//
//	// Imply transform
//	vector<Point2f> obj_corners(4);
//	vector<Point2f> scene_corners(4);
//
//	obj_corners[0] = Point(0, 0);
//	obj_corners[1] = Point(query.cols, 0);
//	obj_corners[2] = Point(query.cols, query.rows);
//	obj_corners[3] = Point(0, query.rows);
//	
//	perspectiveTransform(obj_corners, scene_corners, H);
//
//	// Show the result
//	result = src.clone();
//	cvtColor(result, result, COLOR_GRAY2BGR);
//	for (int i = 0; i < 4; i++) {
//		line(result, scene_corners[i], scene_corners[(i + 1) % 4], Scalar(0, 0, 255), 2);
//	}
//
//	imshow("Result", result);
//	waitKey(0);
//
//	return 0;
//}
//
