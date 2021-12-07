//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat src, gray, canny_dest, result;
//int canny_threshold = 100;
//
//void find_canny_threshold(int, void*);
//void check_skew(int, void*);
//
//int main() {
//
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/P1_T1.PNG");
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test1_rotate.PNG");
//
//	if (!src.data) {
//		printf("Cannot find file...\n");
//		return -1;
//	}
//
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	namedWindow("Canny", WINDOW_AUTOSIZE);
//	/*createTrackbar("threshold", "Canny", &canny_threshold, 255, find_canny_threshold);
//	find_canny_threshold(0, 0);*/
//	createTrackbar("threshold", "Canny", &canny_threshold, 255, check_skew);
//	check_skew(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void find_canny_threshold(int, void*) {
//	// Edge Detection(Canny)
//	Canny(gray, canny_dest, canny_threshold, canny_threshold * 2);
//	imshow("Canny", canny_dest);
//
//	// FindContour
//	vector<vector<Point>> contours;
//	vector<Vec4i> heirs;
//	findContours(canny_dest, contours, heirs, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	// Result
//	result = Mat::zeros(src.size(), CV_8UC3);
//	int minw = src.cols * 0.5;
//	int minh = src.rows * 0.5;
//	Rect bbox;
//
//	RNG rng(12345);
//	for (size_t i = 0; i < contours.size(); i++) {
//		// Ref:
//		// boundingRect: Circumscribed Simple Rect : without orientation
//		// minAreaRect : Circumscribed Rect with orientation
//		// minEnclosingCircle : Circumscribed Circle.
//		// minEnclosingTriangle : Circumscribed triangle.
//		RotatedRect minRect = minAreaRect(contours[i]);
//		float recDegree = abs(minRect.angle);
//		if (minRect.size.height * minRect.size.width > minh * minw \
//			&& minRect.size.height * minRect.size.width < 0.99*(src.cols * src.rows)) {
//			/*cout << "height: " << minRect.size.height << "width: " << minRect.size.width << endl;
//			cout << "height: " << minh << "width: " << minw << endl;
//			cout << recDegree << endl;*/
//
//			Point2f pts[4];
//			minRect.points(pts);
//			bbox = minRect.boundingRect();
//			Scalar draw_color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//			for (int j = 0; j < 4; j++) {
//
//				line(result, pts[j], pts[(j + 1) % 4], draw_color);
//				circle(canny_dest, pts[j], 5, draw_color, -1);
//			}
//		}
//	}
//
//	imshow("Canny", canny_dest);
//	imshow("Result", result);
//
//	if (bbox.width > 0 && bbox.height > 0) {
//		Mat roiImg = src(bbox);
//		imshow("FinalResult", roiImg);
//	}
//}
//
//void check_skew(int, void *) {
//	result = Mat::zeros(src.size(), CV_8UC3);
//
//	// Find Max Contour
//	Canny(gray, canny_dest, canny_threshold, canny_threshold * 2);
//	vector<vector<Point>> contours;
//	vector<Vec4i> heirs;
//	findContours(canny_dest, contours, heirs, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	Mat drawImg = Mat::zeros(src.size(), CV_8UC3);
//	float max_area = 0;
//	double degree = 0;
//	RNG rng(12345);
//
//	int idx = 0;
//
//	// Find the max External rectangle
//	for (size_t i = 0; i < contours.size(); i++) {
//		RotatedRect rect = minAreaRect(contours[i]);
//
//		float tmp = max_area;
//
//		max_area = max(rect.size.width *rect.size.height, max_area);
//
//		if (tmp != max_area) {
//			//idx = i;
//			degree = rect.angle;
//			//cout << idx << endl;
//		}
//	}
//
//	/*RotatedRect maxRect = minAreaRect(contours[idx]);
//	Point2f pts[4];
//	maxRect.points(pts);
//	Scalar draw_color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
//	for (int j = 0; j < 4; j++) {
//		line(result, pts[j], pts[(j + 1) % 4], draw_color);
//	}*/
//
//	// From here: We show how to rotate a img.
//	// 1-> We need to find the center of the img.
//	Point2f center(src.cols / 2, src.rows / 2);
//	// 2-> Get the rotation matrix.
//	Mat rotateMatrix = getRotationMatrix2D(center, degree, 1);
//	// 3-> Do rotate.
//	Mat dest;
//	warpAffine(src, dest, rotateMatrix, src.size(), INTER_LINEAR, 0, Scalar(255, 255, 255));
//
//	imshow("result", dest);
//}