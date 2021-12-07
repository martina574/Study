#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat replace_and_belnd(Mat&, Mat&);
Mat background;

int main() {
	background = imread("D:/•×‹­/C++/OpenCV/TestLib/BG.jpg");
	VideoCapture cap;
	cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
	if (!cap.isOpened()) {
		cout << "Cannot load video..." << endl;
		return -1;
	}

	Mat frame, hsv, mask;
	int count = 0;
	while (cap.read(frame)) {
		cvtColor(frame, hsv, COLOR_BGR2HSV);
		inRange(hsv, Scalar(35, 43, 46), Scalar(155, 255, 255), mask);
		// Morphology
		Mat k = getStructuringElement(MORPH_RECT, Size(3, 3));
		morphologyEx(mask, mask, MORPH_CLOSE, k);
		GaussianBlur(mask, mask, Size(3, 3), 0, 0);

		// Resize BG
		if (count == 0) {
			resize(background, background, frame.size());
			count++;
		}

		Mat result = replace_and_belnd(frame, mask);

		imshow("Result", result);
		char c = waitKey(1);
		if (c == 27) {
			break;
		}
	}

	waitKey(0);
	return 0;
}

Mat replace_and_belnd(Mat &frame, Mat &mask) {
	Mat result = Mat::zeros(frame.size(), frame.type());
	int h = frame.rows;
	int w = frame.cols;
	int dims = frame.channels();

	// Replace&Blend
	int m = 0;
	double wt = 0.0;
	int b1 = 0, g1 = 0, r1 = 0;
	int b2 = 0, g2 = 0, r2 = 0;

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			int m = mask.at<uchar>(row, col);
			if (m == 0) {
				// fg
				result.at<Vec3b>(row, col) = frame.at<Vec3b>(row, col);
			}
			else if (m == 255) {
				// bg
				result.at<Vec3b>(row, col) = background.at<Vec3b>(row, col);
			}
			else {
				// Edges
				wt = m / 255.0;
				b1 = frame.at <Vec3b>(row, col)[0];
				g1 = frame.at <Vec3b>(row, col)[1];
				r1 = frame.at <Vec3b>(row, col)[2];

				b2 = background.at <Vec3b>(row, col)[0];
				g2 = background.at <Vec3b>(row, col)[1];
				r2 = background.at <Vec3b>(row, col)[2];

				result.at<Vec3b>(row, col)[0] = b1 * wt + b2 * (1.0 - w);
				result.at<Vec3b>(row, col)[1] = g1 * wt + g2 * (1.0 - w);
				result.at<Vec3b>(row, col)[2] = r1 * wt + r2 * (1.0 - w);
			}
		}
	}

	return result;
}