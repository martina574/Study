//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int, char**) {
//
//	string filename = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_frontalcatface_extended.xml";
//	CascadeClassifier catface_casscade;
//
//	if (!catface_casscade.load(filename)) {
//		cout << "Canot load file..\n" << endl;
//	}
//
//	Mat src, gray;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/cat.jpg");
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//	equalizeHist(gray, gray);
//
//	vector<Rect> faces;
//	catface_casscade.detectMultiScale(gray, faces, 1.1, 10, 0, Size(48, 48));
//	for (size_t i = 0; i < faces.size(); i++) {
//		rectangle(src, faces[i], Scalar(255, 0, 0));
//	}
//	imshow("result", src);
//
//	waitKey(0);
//	return 0;
//}