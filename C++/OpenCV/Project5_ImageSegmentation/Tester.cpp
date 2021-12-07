#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/jp20414/Desktop/frame_bg.png");

	namedWindow("Input", WINDOW_AUTOSIZE);
	cout << src.size() << endl;


	imshow("Input", src);
	waitKey(0);

}