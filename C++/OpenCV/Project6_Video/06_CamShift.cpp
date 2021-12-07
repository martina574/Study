#include<opencv2/opencv.hpp>
#include<opencv2/tracking.hpp>
#include<math.h>
#include<iostream>

using namespace std;
using namespace cv;

#pragma region global variants
bool firstRead = true;
Rect selection;

int smin = 15;
int vmin = 40;
int vmax = 256;
int bins = 16;

#pragma endregion

int main() {
	VideoCapture cap(0);
	//cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");

	if (!cap.isOpened()) {
		cout << "Cannot open video...\n"<<endl;
		return -1;
	}

	Mat frame, hsv, hue, mask, hist, backprojection;
	Mat histImg = Mat::zeros(200, 300, CV_8UC3);
	namedWindow("Camshift tracking", WINDOW_AUTOSIZE);
	float hrange[] = { 0, 180 };
	const float* phrange = hrange;

	while (cap.read(frame)) {
		// 1-> Get the ROI area.
		if (firstRead) {
			Rect2d firstROI = selectROI("Camshift tracking", frame);
			selection.x = firstROI.x;
			selection.y = firstROI.y;
			selection.width = firstROI.width;
			selection.height = firstROI.height;
			cout << "Selection is over..." << endl;
			//firstRead = false;
		}
		
		// 2-> Convert to HSV
		cvtColor(frame, hsv, COLOR_BGR2HSV);
		// Get mask to denoise.
		inRange(hsv, Scalar(0, smin, vmin), Scalar(180, vmax, vmax), mask);

		hue = Mat(hsv.size(), hsv.depth()); // The mixChannel algorithm need the output var be initialized.
		int channels[] = { 0,0 }; // mixChannels: from src.channel[0] -> dest.channel[0]
		// brief Copies specified channels from input arrays to the specified channels of output arrays.
		mixChannels(&hsv, 1, &hue, 1, channels, 1); 

		// Get the original tracking histogram.
		if (firstRead) {
			// 3-> Calculate Histogram
			Mat roi(hue, selection);
			Mat maskroi(mask, selection);
			calcHist(&roi, 1, 0, maskroi, hist, 1, &bins, &phrange);
			normalize(hist, hist, 0, 255, NORM_MINMAX);

			// ** Show histogram
			int binw = histImg.cols / bins;
			Mat colorIdx = Mat(1, bins, CV_8UC3);
			for (int i = 0; i < bins; i++) {
				colorIdx.at<Vec3b>(0, i) = Vec3b(saturate_cast<uchar>(i * 180 / bins), 255, 255);
			}
			// Hue ranges [0-180] --> RGB ranges [0-255]
			cvtColor(colorIdx, colorIdx, COLOR_HSV2BGR);
			for (int i = 0; i < bins; i++) {
				int val = saturate_cast<int>(hist.at<float>(i) / 255 * histImg.rows);
				rectangle(histImg, Point(binw*i, histImg.rows), Point(binw*(i + 1), histImg.rows - val), Scalar(colorIdx.at<Vec3b>(0, i)), -1);
			}
		}

		// 4-> Back projection
		calcBackProject(&hue, 1, 0, hist, backprojection, &phrange);
		backprojection &= mask;
		
		// 5-> Camshift tracking
		RotatedRect trackbox = CamShift(backprojection, selection, \
			TermCriteria((TermCriteria::COUNT | TermCriteria::EPS), 10, 1));

		// ** Draw locations
		ellipse(frame, trackbox, Scalar(0, 0, 255), 3, 8);

		if (firstRead) {
			firstRead = false;
		}

		imshow("Camshift", frame);
		imshow("backprojection", backprojection);
		imshow("ROI Histogram", histImg);

		char c = waitKey(20);
		if (c == 27) {
			break;
		}
	}

	cap.release();
	return 0;
}