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
//		cout << "Cannot open video file..\n" << endl;
//		return -1;
//	}
//
//	Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2();
//	//Ptr<BackgroundSubtractor> pKNN = createBackgroundSubtractorKNN();
//	Mat frame, bsmaskMOG2, bsmaskKNN;
//	while (cap.read(frame)) {
//		pMOG2->apply(frame, bsmaskMOG2);
//		//pKNN->apply(frame, bsmaskKNN);
//		imshow("Mask-MOG2", bsmaskMOG2);
//		//imshow("Mask-KNN", bsmaskKNN);
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