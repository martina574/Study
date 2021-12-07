//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//void matchDemo(int, void*);
//int match_method = 0;
//int max_track = 5;
//
//Mat src, temp, dest;
//
////int main_Template(int arg, char* arv)
//int main(int arg, char* arv)
//{
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/templateMatch.png");
//	temp = imread("D:/•×‹­/C++/OpenCV/TestLib/template.png");
//
//	if (!src.data or !temp.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	namedWindow("input", WINDOW_AUTOSIZE);
//	createTrackbar("Match Algorithm type", "input", &match_method, max_track, matchDemo);
//	matchDemo(0, 0);
//
//	waitKey(0);
//	return 0;
//}
//
//void matchDemo(int, void*)
//{
//	int width = src.cols - temp.cols + 1;
//	int height = src.rows - temp.rows + 1;
//
//	Mat dest(width, height, CV_16FC1);
//
//	matchTemplate(src, temp, dest, match_method);
//	normalize(dest, dest, 0, 1, NORM_MINMAX);
//
//	// Locate the template in the source picture.
//	Point minLoc, maxLoc;
//	double min, max;
//
//	minMaxLoc(dest, &min, &max, &minLoc, &maxLoc);
//
//	Point tempLoc;
//
//	if (match_method == TM_SQDIFF or match_method == TM_SQDIFF_NORMED)
//	{
//		// In this case the min value represents the max matched value.
//		tempLoc = minLoc;
//	}
//	else
//	{
//		tempLoc = maxLoc;
//	}
//
//	// Draw ractangles
//	Rect rect1;
//	rect1 = Rect(tempLoc.x, tempLoc.y, temp.cols, temp.rows); // Rect's parameters: x,y,w,h
//	rectangle(src, rect1, Scalar(0, 0, 255)); // Draw rectangle on 
//	//rectangle(src, rect1, Scalar(0, 0, 255));
//
//	imshow("input", dest);
//	imshow("output", src);
//	//imshow("tImg", temp);
//	//imshow("output", dest);
//}