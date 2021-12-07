//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//	VideoCapture cap(0);
//	//cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
//
//	if (!cap.isOpened()) {
//		cout << "Cannot open video file..." <<endl;
//		return -1;
//	}
//
//	Mat frame, gray, mogMask;
//	Ptr<BackgroundSubtractor> bsm = createBackgroundSubtractorMOG2();
//	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
//	vector<vector<Point>> contours;
//	int count = 0;
//
//	while (cap.read(frame)) {
//		bsm->apply(frame, mogMask);
//		threshold(mogMask, mogMask, 100, 255, THRESH_BINARY);
//		morphologyEx(mogMask, mogMask, MORPH_OPEN, kernal);
//
//		findContours(mogMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//		count = 0;
//		char numText[8];
//		for (size_t i = 0; i < contours.size(); i++) {
//			double area = contourArea(contours[i]);
//			if (area < 1000) continue;
//			Rect selection = boundingRect(contours[i]);
//			if (selection.width < 30 || selection.height < 30) continue;
//			count++;
//			rectangle(frame, selection, Scalar(0, 0, 255), 2);
//			sprintf_s(numText, "%d", count);
//			putText(frame, numText, Point(selection.x, selection.y), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
//		}
//
//		imshow("Result", frame);

//		char c = waitKey(20);
//		if (c == 27) {
//			break;
//		}
//	}
//
//	cap.release();
//	return 0;
//}