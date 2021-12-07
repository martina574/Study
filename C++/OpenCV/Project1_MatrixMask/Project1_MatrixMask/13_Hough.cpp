//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, gray, output, dest;
//Mat map_x, map_y;
//int index;
//
//void update_map(void);
//
//int main_Hough(int arg, char* arv)
//{
//	//Mat src, gray, output, dest;
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/coins_001.jpg");
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/cvtest.png");
//	//src = imread("D:/•×‹­/C++/OpenCV/TestLib/j.png");
//
//	if (!src.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	//// Hough line detection
//	//Canny(src, gray, 100, 200);
//	//cvtColor(gray, dest, COLOR_GRAY2BGR);
//
//	//vector<Vec4f> plines;
//	//HoughLinesP(gray, plines, 1, CV_PI/180.0, 10, 0, 10);
//
//	//Scalar color = Scalar(0, 0, 255);
//	//for (size_t i = 0; i < plines.size(); i++)
//	//{
//	//	Vec4f hline = plines[i];
//	//	line(dest, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3);
//	//}
//
//	// Hough circle detection
//	/*medianBlur(src, dest, 3);
//	cvtColor(dest, gray, COLOR_BGR2GRAY);
//
//	vector<Vec3f> pCircles;
//	HoughCircles(gray, pCircles, HOUGH_GRADIENT, 1, 10, 100, 50, 5, 50);
//
//	for (size_t i = 0; i < pCircles.size(); i++)
//	{
//		Vec3f cc = pCircles[i];
//		circle(src, Point(cc[0], cc[1]), cc[2], Scalar(0, 0, 255), 2);
//		circle(src, Point(cc[0], cc[1]), 5, Scalar(198, 23, 155), 2);
//	}
//
//	Canny(src, output, 50, 200);*/
//
//
//	map_x.create(src.size(), CV_32FC1);
//	map_y.create(src.size(), CV_32FC1);
//
//	int c = 0;
//
//	update_map();
//	remap(src, dest, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
//
//	imshow("output", dest);
//
//	imshow("input", src);
//	//imshow("gray", gray);
//
//	waitKey(0);
//	return 0;
//}
//
//void update_map(void)
//{
//	for (int row = 0; row < src.rows; row++)
//	{
//		for (int col = 0; col < src.cols; col++)
//		{
//			switch (index)
//			{
//			case 0:
//				// Half size
//				if (col >= (src.cols*0.25) && col <= (src.cols*0.75) && row >=(src.rows*0.25) && row <= (src.rows*0.75))
//				{
//					map_x.at<float>(row, col) = 2 * (col - (src.cols*0.25));
//					map_y.at<float>(row, col) = 2 * (row - (src.rows*0.25));
//				}
//				else
//				{
//					map_x.at<float>(row, col) = 0;
//					map_y.at<float>(row, col) = 0;
//				}
//				break;
//			case 1:
//				// X-reverse
//				map_x.at<float>(row, col) = src.cols - col - 1;
//				map_y.at<float>(row, col) = row;
//				break;
//			case 2:
//				// Y-reverse
//				map_x.at<float>(row, col) = col;
//				map_y.at<float>(row, col) = src.rows - row - 1;
//				break;
//			case 3:
//				// X&Y reverse
//				map_x.at<float>(row, col) = src.cols - col - 1;
//				map_y.at<float>(row, col) = src.rows - row - 1;
//				break;
//			}
//		}
//	}
//}