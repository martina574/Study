#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, query, dest, gray, result;
void cmpDetectionTimeConsume();

int main() {

	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Match.png", IMREAD_GRAYSCALE);
	query = imread("D:/•×‹­/C++/OpenCV/TestLib/box.png", IMREAD_GRAYSCALE);
	if (!src.data || !query.data) {
		printf("Cound not load image ... \n");
		return -1;
	}

	// kaze detection&match
	vector<KeyPoint> kps, kps_obj;
	Mat dcptors, dcptors_obj;

	Ptr<KAZE> detector = KAZE::create(); // 3433
	double t1 = getTickCount();
	detector->detectAndCompute(src, Mat(), kps, dcptors);
	detector->detectAndCompute(query, Mat(), kps_obj, dcptors_obj);
	double t2 = getTickCount();
	double t = (t2 - t1) * 1000 / getTickFrequency();
	cout << t << " ms" << endl;

	drawKeypoints(src, kps, src);
	imshow("Result", src);
	waitKey(0);
	return 0;

	vector<DMatch> matches, goodMatches;
	// Can be used by KAZE but not AKAZE
	FlannBasedMatcher matcher_FLANN;
	matcher_FLANN.match(dcptors_obj, dcptors, matches, Mat());

	cout << "KAZE Dsp: " << dcptors_obj.size() << endl;
	double minV, maxV;
	minMaxLoc(dcptors_obj, &minV, &maxV);
	cout << "KAZE Dsp: " << dcptors_obj.size() << endl;
	cout << "KAZE Min: " << minV << "Max: " << maxV << endl;

	// Overwrite by AKAZE
	Ptr<AKAZE> detector_a = AKAZE::create(); // 332
	t1 = getTickCount();
	detector_a->detectAndCompute(src, Mat(), kps, dcptors);
	detector_a->detectAndCompute(query, Mat(), kps_obj, dcptors_obj);
	t2 = getTickCount();
	t = (t2 - t1) * 1000 / getTickFrequency();
	cout << t <<" ms" << endl;

	cout << "AKAZE Dsp: " << dcptors_obj.size() << endl;
	minMaxLoc(dcptors_obj, &minV, &maxV);
	cout << "AKAZE Dsp: " << dcptors_obj.size() << endl;
	cout << "AKAZE Min: " << minV << "Max: " << maxV << endl;

	// It seems FlannBasedMatcher donot suportn CV_8UC1 dcptor.
	// You can also use the FLANN by add a parameter like below
	FlannBasedMatcher matcher_test(new flann::LshIndexParams(20, 10, 2));
	matcher_test.match(dcptors_obj, dcptors, matches, Mat());

	// Or you can use the code below.
	/*BFMatcher matcher;
	matcher.match(dcptors_obj, dcptors, matches, Mat());*/

	double minD = 1000;
	double maxD = 0;
	for (size_t i = 0; i < matches.size(); i++) {
		if (matches[i].distance > maxD) {
			maxD = matches[i].distance;
		}

		if (matches[i].distance < minD) {
			minD = matches[i].distance;
		}
	}

	cout << "minD: " << minD << endl;
	
	for (size_t i = 0; i < matches.size(); i++) {
		if (matches[i].distance < max(minD * 2, 0.02)) {
			goodMatches.push_back(matches[i]);
		}
	}

	drawMatches(query, kps_obj, src, kps, goodMatches, result);
	drawMatches(query, kps_obj, src, kps, matches, result);

	// Find contour
	vector<Point2f> objCoords, srcCoords;
	for (size_t i = 0; i < goodMatches.size(); i++) {
		srcCoords.push_back(kps[goodMatches[i].trainIdx].pt);
		objCoords.push_back(kps_obj[goodMatches[i].queryIdx].pt);
	}
	cout << goodMatches.size() << endl;

	Mat H = findHomography(objCoords, srcCoords, RANSAC);

	vector<Point2f> corInObj(4), corToFind(4);
	corInObj[0] = Point2f(0, 0);
	corInObj[1] = Point2f(query.cols, 0);
	corInObj[2] = Point2f(query.cols, query.rows);
	corInObj[3] = Point2f(0, query.rows);
	perspectiveTransform(corInObj, corToFind, H);

	// Draw
	result = src.clone();
	cvtColor(result, result, COLOR_GRAY2BGR);
	for (int i = 0; i < 4; i++) {
		line(result, corToFind[i], corToFind[(i + 1) % 4], Scalar(0, 0, 255), 2);
	}

	imshow("Result", result);
	waitKey(0);

	return 0;
}

void cmpDetectionTimeConsume() {
	// kaze detection: calculate time consuming
	Ptr<KAZE> detector = KAZE::create();
	vector<KeyPoint> kps;
	double t1 = getTickCount();
	detector->detect(src, kps);
	double t2 = getTickCount();
	double tkaze = 1000 * (t2 - t1) / getTickFrequency();
	cout << tkaze << " ms" << endl;

	// akaze detection
	Ptr<AKAZE> detector_akaze = AKAZE::create();
	vector<KeyPoint> kps_akaze;
	t1 = getTickCount();
	detector_akaze->detect(src, kps_akaze);
	t2 = getTickCount();
	double takaze = (t2 - t1) * 1000 / getTickFrequency();
	cout << takaze << " ms" << endl;

	Mat kpsImg, kpsImg_akaze;
	drawKeypoints(src, kps, kpsImg);
	drawKeypoints(src, kps_akaze, kpsImg_akaze);

	imshow("Result_kaze", kpsImg);
	imshow("Result_akaze", kpsImg_akaze);
}

