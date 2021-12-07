//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//void drawOpticalFlowHF(Mat &flowdata, Mat &image);
//
//int main() {
//	VideoCapture cap;
//	cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
//	if (!cap.isOpened()) {
//		cout << "Cannot open video." << endl;
//		return -1;
//	}
//
//	Mat frame, gray;
//	Mat prev_frame, prev_gray;
//	Mat flow_result, flow_data;
//
//	cap.read(frame);
//	cvtColor(frame, prev_gray, COLOR_BGR2GRAY);
//
//	while (cap.read(frame)) {
//		// Coners is detected by gray images.
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		if (!prev_gray.empty()) {
//			calcOpticalFlowFarneback(prev_gray, gray, flow_data, 0.5, 3, 15, 3, 5, 1.2, 0);
//			cvtColor(prev_gray, flow_result, COLOR_GRAY2BGR);
//			drawOpticalFlowHF(flow_data, flow_result);
//			imshow("Flow", flow_result);
//			imshow("Input", frame);
//		}
//
//		char c = waitKey(20);
//		if (c == 27) {
//			break;
//		}
//	}
//
//	cap.release();
//	return 0;
//}
//
//void drawOpticalFlowHF(Mat &flowdata, Mat &image) {
//	for (int row = 0; row < image.rows; row++) {
//		for (int col = 0; col < image.cols; col++) {
//			const Point2f fxy = flowdata.at<Point2f>(row, col);
//			// When it moving more then 2 pixels, Draw it.
//			if (fxy.x > 2 || fxy.y > 2) {
//				line(image, Point(col, row), Point(cvRound(col + fxy.x), \
//					cvRound(row + fxy.y)), Scalar(0, 0, 255));
//				circle(image, Point(col, row), 2, Scalar(0, 255, -1));
//			}
//		}
//	}
//}
