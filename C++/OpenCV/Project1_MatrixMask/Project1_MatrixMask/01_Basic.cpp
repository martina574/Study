#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main_1(int arg, char** arv) {
	Mat src, det;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	int cols = src.cols * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	det = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < rows - 1; row++) {
		const uchar* current = src.ptr<uchar>(row);
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = det.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - previous[col] - next[col] - current[col - offsetx] - current[col + offsetx]);
		}
	}

	// Define a kernal
	double t = getTickCount();
	Mat kernal = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	Mat testFilter = Mat::zeros(src.size(), src.type());
	filter2D(src, testFilter, src.depth(), kernal);
	double timecost = (getTickCount() - t) / getTickFrequency();

	imshow("Output_mannul", det);
	imshow("Output_filter2D", testFilter);
	imshow("Input", src);

	cout << timecost << endl;
	waitKey(0);
	return 0;
}
