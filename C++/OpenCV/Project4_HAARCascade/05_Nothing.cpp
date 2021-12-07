#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	Mat A = Mat::eye(4, 3, CV_32F) * 5;
	cout << A << endl;
	waitKey(0);
	return 0;
}