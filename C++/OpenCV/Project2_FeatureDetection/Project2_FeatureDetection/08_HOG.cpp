//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//	Mat src, hog, hogSVM;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/peopleDetection.jpg");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	// HOG detection
//	resize(src, hog, Size(64, 128));
//	HOGDescriptor detector_simple = HOGDescriptor();
//	vector<float> descriptors;
//	vector<Point> locations;
//	detector_simple.compute(hog, descriptors, Size(0, 0), Size(0,0), locations);
//
//	// HOG + SVM
//	HOGDescriptor detector = HOGDescriptor();
//	detector.setSVMDetector(detector.getDefaultPeopleDetector());
//
//	vector<Rect> locations_ms;
//	detector.detectMultiScale(src, locations_ms, 0, Size(8, 8), Size(32, 32));
//
//	vector<Point> locations_quick;
//	detector.detect(src, locations_quick, 0, Size(8, 8), Size(32, 32));
//
//	for (size_t i = 0; i < locations_ms.size(); i++) {
//		rectangle(src, locations_ms[i], Scalar(0, 0, 255));
//	}
//
//	for (size_t j = 0; j < locations_quick.size(); j++) {
//		circle(src, locations_quick[j], 20, Scalar(255, 255, 255), -1);
//	}
//
//	imshow("Result", src);
//	waitKey(0);
//
//	return 0;
//}
//
