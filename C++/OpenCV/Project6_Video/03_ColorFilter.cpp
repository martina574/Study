//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int, char**) {
//	VideoCapture cap;
//	cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
//	if (!cap.isOpened()) {
//		cout << "Cannot open file..\n" << endl;
//		return -1;
//	}
//
//	Mat frame, result;
//	while (cap.read(frame)) {
//		inRange(frame, Scalar(0, 80, 0), Scalar(120, 255, 120), result);
//		imshow("result", result);
//		char c = waitKey(20);
//		if (c == 27) {
//			break;
//		}
//	}
//
//	cap.release();
//	waitKey(0);
//	return 0;
//}