#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main_3(int arg, char* arv)
{
	Mat src, gray_src, det;
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!src.data) {
		printf("Could not find image! \n");
		return -1;
	}

	// Get Pixels: Single channel
	cvtColor(src, gray_src, COLOR_RGB2GRAY);
	int height = gray_src.rows;
	int width = gray_src.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col) = 255 - gray;
		}
	}

	// Get Pixels
	
	//m1.create(src.size(), src.type());
	height = src.rows;
	width = src.cols;
	int ch = src.channels();

	//Mat m1(Size(height, width), CV_8UC3, Scalar(0,0,0));
	/*Mat m1;
	m1.create(src.size(), src.type());*/

	Mat m1;
	m1 = src.clone();

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (ch == 1) {
				int gray = gray_src.at<uchar>(row, col);
				m1.at<uchar>(row, col) = 255 - gray;
			}
			else if (ch == 3) {
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];

				/*cout << typeid(src.at<Vec3b>(row, col)[0]).name() << endl;
				cout << typeid(m1.at<Vec3b>(row, col)[0]).name() << endl;
				cout << "Value_src:" <<src.at<Vec3b>(row, col)[0] << endl;
				cout << "Value_m1:" <<m1.at<Vec3b>(row, col)[0] << endl;

				cout << "Value_src:" << int(src.at<Vec3b>(row, col).val[0]) << endl;
				cout << "Value_m1:" << int(m1.at<Vec3b>(row, col).val[0]) << endl;*/

				m1.at<Vec3b>(row, col)[0] = 255 - b;
				m1.at<Vec3b>(row, col)[1] = 255 - g;
				m1.at<Vec3b>(row, col)[2] = 255 - r;
			}
		}
	}

	Mat dest;
	bitwise_not(src, dest);
	//imshow("Output", gray_src);
	imshow("Output_m", m1);
	imshow("Output_b", dest);
	waitKey(0);

	return 0;
}