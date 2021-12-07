//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//int threshold_max = 255;
//int threshold_value = 127;
//int type_value = 2;
//int type_max = 4;
//
//void threshold_demo(int, void*);
//Mat src, gray_src, dest;
//
//int main_basicThreshold(int arg, char* arv)
//{
//	//Mat src, dest;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");
//
//	if (!src.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	/*Mat src_gray;
//	cvtColor(src, src_gray, COLOR_BGR2GRAY);*/
//	namedWindow("Output", WINDOW_AUTOSIZE);
//	createTrackbar("Threshold", "Output", &threshold_value, threshold_max, threshold_demo);
//	createTrackbar("Type", "Output", &type_value, type_max, threshold_demo);
//	threshold_demo(0,0);
//
//
//	//imshow("input", src);
//	//imshow("output", dest);
//	waitKey(0);
//	return 0;
//}
//
//void threshold_demo(int, void*)
//{
//	cvtColor(src, gray_src, COLOR_BGR2GRAY);
//	//threshold(gray_src, dest, threshold_value, threshold_max, THRESH_BINARY);
//	//threshold(gray_src, dest, threshold_value, threshold_max, type_value);
//	threshold(gray_src, dest, 0, 255, THRESH_TRIANGLE);
//
//	imshow("Output", dest);
//}