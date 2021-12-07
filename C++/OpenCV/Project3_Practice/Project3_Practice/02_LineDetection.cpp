//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat src, dest, result, roiImg;
//int line_detect_thres = 100;
//void line_detect(int, void *);   // Depend on morthpology    & Hough detection: OO
//void line_detect_1(int, void *); // Depend on edge detection & Hough detection: --
//void line_detect_2(int, void *); // Depend on binarization   & Hough detection: XX
//
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test2.PNG", IMREAD_GRAYSCALE);
//	if (!src.data) {
//		printf("Could not find the input img...");
//		return -1;
//	}
//
//	// Binarization
//	Rect roi = Rect(10, 10, src.cols - 20, src.rows - 20);
//	roiImg = src(roi);
//	//imshow("ROI", roiImg);
//
//	namedWindow("Input image", WINDOW_AUTOSIZE);
//	createTrackbar("threshold", "image", &line_detect_thres, 255, line_detect);
//	line_detect(0, 0);
//
//	//imshow("result", result);
//	waitKey(0);
//	return 0;
//}
//
//void line_detect_1(int, void *) {
//	Canny(roiImg, dest, line_detect_thres, line_detect_thres * 2);
//	vector<Vec4i> lines;
//	HoughLinesP(dest, lines, 1, CV_PI / 180, 30, 30);
//	cvtColor(dest, result, COLOR_GRAY2BGR);
//
//	for (size_t i = 0; i < lines.size(); i++) {
//		line(result, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255));
//	}
//
//	imshow("Result", result);
//}
//
//void line_detect_2(int, void *) {
//	threshold(roiImg, dest, 0, 255, THRESH_BINARY | THRESH_OTSU);
//	vector<Vec4i> lines;
//	HoughLinesP(dest, lines, 1, CV_PI / 180, 30, 30);
//	cvtColor(dest, result, COLOR_GRAY2BGR);
//
//	for (size_t i = 0; i < lines.size(); i++) {
//		line(result, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255));
//	}
//
//	imshow("Result", result);
//}
//
//void line_detect(int, void *) {
//	// Morphology method
//	Mat binaryImg, morphImg;
//	threshold(roiImg, binaryImg, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
//	imshow("Bin", binaryImg);
//
//	// Morphology 1: Delete unneccessory alphabeta parts
//	Mat kernal = getStructuringElement(MORPH_RECT, Size(40, 1), Point(-1,-1));
//	// Review: Morphology-> 0:backgroud, 1:front
//	// Open: Erode->Dilate
//	//       Erode : ->0000
//	//       Dilate: ->1111
//	morphologyEx(binaryImg, morphImg, MORPH_OPEN, kernal);
//
//	// Motphology 2: Enhance the lines parts
//	kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
//	morphologyEx(morphImg, morphImg, MORPH_DILATE, kernal);
//
//	// Hough Line Detection
//	vector<Vec4i> lines;
//	HoughLinesP(morphImg, lines, 1, CV_PI / 180, 30);
//
//	// Show
//	cvtColor(roiImg, result, COLOR_GRAY2BGR);
//	for (size_t i = 0; i < lines.size(); i++) {
//		line(result, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255));
//	}
//
//	imshow("Result", result);
//}
