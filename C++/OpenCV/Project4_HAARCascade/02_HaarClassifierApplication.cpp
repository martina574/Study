//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int, char**) {
//
//	VideoCapture cap;
//	string filename = "D:/Env/opencv_build/build/install/etc/lbpcascades/lbpcascade_frontalface_improved.xml";
//	CascadeClassifier face_casscade;
//
//	if (!face_casscade.load(filename)) {
//		cout << "Canot load file..\n" << endl;
//	}
//
//	Mat frame, gray;
//	cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
//	while (cap.read(frame)) {
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		equalizeHist(gray, gray);
//
//		vector<Rect> faces;
//		face_casscade.detectMultiScale(gray, faces);
//		for (size_t i = 0; i < faces.size(); i++) {
//			rectangle(frame, faces[i], Scalar(255, 0, 0));
//		}
//		imshow("result", frame);
//		char c = waitKey(50);
//		if (c == 27) {
//			break;
//		}
//	}
//
//
//
//
//	cap.release();
//	waitKey(0);
//	return 0;
//}