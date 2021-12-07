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
//	// KPS Extraction
//	// Ptr<Feature2D> detector = BRISK::create();
//	vector<KeyPoint> kps, kps_obj;
//	Mat dcptors, dcptors_obj;
//	Ptr<BRISK> detector = BRISK::create();
//	detector->detectAndCompute(src, Mat(), kps, dcptors);
//	detector->detectAndCompute(query, Mat(), kps_obj, dcptors_obj);
//
//	drawKeypoints(src, kps, src);
//	imshow("Result", src);
//	waitKey(0);
//	return 0;
//
//	// Matching
//	FlannBasedMatcher matcher(new flann::LshIndexParams(20, 10, 2));
//	vector<DMatch> matches;
//	vector<DMatch> goodMatches;
//	matcher.match(dcptors_obj, dcptors, matches);
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
//	/*Mat result_good, result;
//	drawMatches(query, kps_obj, src, kps, goodMatches, result);*/
//
//	// Find contour
//	vector<Point2f> objCoords, srcCoords;
//	for (size_t i = 0; i < goodMatches.size(); i++) {
//		srcCoords.push_back(kps[goodMatches[i].trainIdx].pt);
//		objCoords.push_back(kps_obj[goodMatches[i].queryIdx].pt);
//	}
//	cout << goodMatches.size() << endl;
//
//	Mat H = findHomography(objCoords, srcCoords, RANSAC);
//
//	vector<Point2f> corInObj(4), corToFind(4);
//	corInObj[0] = Point2f(0, 0);
//	corInObj[1] = Point2f(query.cols, 0);
//	corInObj[2] = Point2f(query.cols, query.rows);
//	corInObj[3] = Point2f(0, query.rows);
//	perspectiveTransform(corInObj, corToFind, H);
//
//	// Draw
//	Mat result = src.clone();
//	cvtColor(result, result, COLOR_GRAY2BGR);
//	for (int i = 0; i < 4; i++) {
//		line(result, corToFind[i], corToFind[(i + 1) % 4], Scalar(0, 0, 255), 2);
//	}
//
//	imshow("Result", result);
//	waitKey(0);
//
//	return 0;
//}
//
