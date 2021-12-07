//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//string filename = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_frontalface_alt.xml";
//CascadeClassifier face_classifier;
//
//int detectImage();
//int detectCamera();
//
//int main() {
//	if (!face_classifier.load(filename)) {
//		printf("Could not open file...\n");
//		return -1;
//	}
//
//	int ret = detectImage();
//	//int ret = detectCamera();
//
//	return ret;
//}
//
//int detectImage() {
//	Mat src = imread("D:/•×‹­/C++/OpenCV/TestLib/Img1.jpg");
//	if (!src.data) {
//		printf("Cant open Image file...\n");
//		return -1;
//	}
//
//	Mat gray, gray_equ, result;
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//	equalizeHist(gray, gray_equ);
//
//	vector<Rect> faceRects;
//	face_classifier.detectMultiScale(gray_equ, faceRects, 1.1, 5, 0, Size(30, 30));
//
//	result = src.clone();
//	for (size_t i = 0; i < faceRects.size(); i++) {
//		rectangle(result, faceRects[i], Scalar(255, 0, 0), 2);
//	}
//
//	imshow("result", result);
//	waitKey(0);
//
//	return 0;
//}
//
//int detectCamera() {
//	VideoCapture cap(0);
//	Mat frame;
//
//	while (cap.read(frame)) {
//		Mat gray, gray_equ, result;
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		equalizeHist(gray, gray_equ);
//
//		vector<Rect> faceRects;
//		face_classifier.detectMultiScale(gray_equ, faceRects);
//
//		result = frame.clone();
//		for (size_t i = 0; i < faceRects.size(); i++) {
//			rectangle(result, faceRects[i], Scalar(255, 0, 0), 2);
//		}
//
//		char c = waitKey(50);
//		if (c == 27) {
//			break;
//		}
//
//		imshow("Demo", result);
//	}
//
//	waitKey(0);
//	return 0;
//}