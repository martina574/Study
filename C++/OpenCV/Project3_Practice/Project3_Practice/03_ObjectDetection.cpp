//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat src, binaryImg, result;
//
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test3.PNG", IMREAD_GRAYSCALE);
//	if (!src.data) {
//		printf("The image can not be found... \n");
//		return -1;
//	}
//
//	// Binarization
//	threshold(src, binaryImg, 0, 255, THRESH_BINARY | THRESH_OTSU);
//
//	// Morphology
//	// Review:
//	//       Open : Erode->Dilate..Get the designated morphology, like lines and eclipse etc..
//	//                             Eliminate the white noise.
//	//       Close: Dialte->Erode..Join the whilt area together..
//	//                             Eliminate the black noise.
//	Mat morphImg;
//	Mat kernal = getStructuringElement(MORPH_RECT, Size(11, 11));
//	morphologyEx(binaryImg, morphImg, MORPH_CLOSE, kernal);
//
//	kernal = getStructuringElement(MORPH_RECT, Size(17, 17));
//	morphologyEx(morphImg, morphImg, MORPH_OPEN, kernal);
//
//	// Find the circl
//	vector<vector<Point>> contours;
//	findContours(morphImg, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//	//cvtColor(src, result, COLOR_GRAY2BGR);
//	result = Mat::zeros(src.size(), CV_8UC3);
//	for (size_t i = 0; i < contours.size(); i++) {
//		// Eliminate by area.
//		double area = contourArea(contours[i]);
//		if (area < 5000) continue;
//		// Eliminate by Aspect Ratio
//		Rect rect = boundingRect(contours[i]);
//		float ratio = (float)rect.width / (float)rect.height;
//		if (0.9 < ratio && ratio < 1.1) {
//			drawContours(result, contours, i, Scalar(0, 0, 255), 2);
//			printf("Circle area: %f \n", area);
//			printf("Circle length: %f \n", arcLength(contours[i], true));
//
//			int x = rect.x + rect.width / 2;
//			int y = rect.y + rect.height / 2;
//			circle(result, Point(x, y), 4, Scalar(100, 100, 100), -1);
//		}
//	}
//
//	// Detect Circle
//	/*vector<Vec3f> circles;
//	HoughCircles(morphImg, circles, HOUGH_GRADIENT, 1, 7, 150, 13, 10, morphImg.cols/4);
//	for (size_t i = 0; i < circles.size(); i++) {
//		circle(result, Point2f(circles[i][0], circles[i][1]), circles[i][2], Scalar(255,0,0));
//	}*/
//
//	imshow("result", result);
//	waitKey(0);
//	return 0;
//}