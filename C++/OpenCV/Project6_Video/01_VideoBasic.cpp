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
//		cout << "Cannot open video file...\n" << endl;
//		return -1;
//	}
//
//	double fps = cap.get(CAP_PROP_FPS);
//	Size size = Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
//	VideoWriter wr("D:/•×‹­/C++/OpenCV/TestLib/02.mp4", -1, fps, size, true);
//
//	Mat frame;
//	while (cap.read(frame)) {
//		imshow("Demo", frame);
//		wr.write(frame);
//		char c = waitKey(10);
//		if (c == 27) {
//			break;
//		}
//	}
//	
//	cap.release();
//	waitKey(0);
//	return 0;
//}