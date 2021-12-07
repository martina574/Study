//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//
//	String cascadeFilePath = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_frontalface_alt.xml";
//	CascadeClassifier face_cascade;
//
//	if (!face_cascade.load(cascadeFilePath)) {
//		printf("Could not load haar data... \n");
//		return -1;
//	}
//
//	Mat src, dest, gray;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//	equalizeHist(gray, dest);
//
//	vector<Rect> objs;
//	face_cascade.detectMultiScale(gray, objs);
//	for (size_t i = 0; i < objs.size(); i++) {
//		rectangle(src, objs[i], Scalar(0, 0, 255));
//	}
//
//	imshow("Gray", gray);
//	imshow("Output", dest);
//	imshow("Result", src);
//	waitKey(0);
//	return 0;
//}