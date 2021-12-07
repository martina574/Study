#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, src_gray, binImg, dest, result;

int main() {
	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Test5.PNG");
	if (!src.data) {
		cout << "Cannot find img...\n" << endl;
		return -1;
	}

	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	// Binarization
	threshold(src_gray, binImg, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

	// Morphology
	Mat morphImg;
	Mat kernal = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(binImg, morphImg, kernal, Point(-1, -1), 1);

	// Find Contour
	vector<vector<Point>> contours;
	findContours(morphImg, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat exContourImg = Mat::zeros(src_gray.size(), CV_8UC3);
	for (size_t i = 0; i < contours.size(); i++) {
		drawContours(exContourImg, contours, i, Scalar(0, 0, 255));
	}

	// Hough Line detection
	vector<Vec4i> lines;
	Mat houghLinesImg;
	cvtColor(exContourImg, houghLinesImg, COLOR_BGR2GRAY);
	HoughLinesP(houghLinesImg, lines, 1, CV_PI / 180.0, 2, 20, 20);

	/*for (size_t i = 0; i < lines.size(); i++) {
		line(src, Point(lines[i][0], lines[i][1]), \
			Point(lines[i][2], lines[i][3]), Scalar(255, 255, 255), 3);
	}*/

	// Find the four lines
	int maxH0 = 0;
	int maxH1 = 0;
	int maxW0 = 0;
	int maxW1 = 0;
	Vec4i bottomLine, topLine, leftLine, rightLine;

	for (size_t i = 0; i < lines.size(); i++) {
		Vec4i ln = lines[i];

		if (ln[0] > src_gray.size().width / 2) {
			if (maxH0 < abs(ln[3] - ln[1])) {
				maxH0 = abs(ln[3] - ln[1]);
				rightLine = lines[i];
			}
		}
		else if(ln[0] < src_gray.size().width / 2)
		{
			if (maxH1 < abs(ln[3] - ln[1])) {
				maxH1 = abs(ln[3] - ln[1]);
				leftLine = lines[i];
			}
		}

		// Y is OpenCV Coordinates
		if (ln[1] > src_gray.size().height / 2) {
			if (maxW0 < abs(ln[2] - ln[0])) {
				maxW0 = abs(ln[2] - ln[0]);
				bottomLine = lines[i];
			}
		}		
		else if (ln[1] < src_gray.size().height / 2) {
			if (maxW1 < abs(ln[2] - ln[0])) {
				maxW1 = abs(ln[2] - ln[0]);
				topLine = lines[i];
			}
		}
	}

	//line(src, Point(rightLine[0], rightLine[1]), \
	//	Point(rightLine[2], rightLine[3]), Scalar(255, 0, 0), 1);
	//line(src, Point(leftLine[0], leftLine[1]), \
	//	Point(leftLine[2], leftLine[3]), Scalar(255, 0, 0), 1);
	//line(src, Point(topLine[0], topLine[1]), \
	//	Point(topLine[2], topLine[3]), Scalar(255, 0, 0), 1);
	//line(src, Point(bottomLine[0], bottomLine[1]), \
	//	Point(bottomLine[2], bottomLine[3]), Scalar(255, 0, 0), 1);
	
	// Find the line formulation
	float k1, k2, k3, k4, c1, c2, c3, c4;
	k1 = (float)(topLine[3] - topLine[1]) / (float)(topLine[2] - topLine[0]);
	k2 = (float)(bottomLine[3] - bottomLine[1]) / (float)(bottomLine[2] - bottomLine[0]);
	k3 = (float)(rightLine[3] - rightLine[1]) / (float)(rightLine[2] - rightLine[0]);
	k4 = (float)(leftLine[3] - leftLine[1]) / (float)(leftLine[2] - leftLine[0]);

	c1 = topLine[1] - k1 * topLine[0];
	c2 = bottomLine[1] - k2 * bottomLine[0];
	c3 = rightLine[1] - k3 * rightLine[0];
	c4 = leftLine[1] - k4 * leftLine[0];

	// Find the cross points
	Point2f cp1, cp2, cp3, cp4;
	cp1.x = (c1 - c3) / (k3 - k1); // t-r
	cp2.x = (c1 - c4) / (k4 - k1); // t-l
	cp3.x = (c2 - c3) / (k3 - k2); // b-r
	cp4.x = (c2 - c4) / (k4 - k2); // b-l 
	
	cp1.y = k1 * cp1.x + c1;
	cp2.y = k1 * cp2.x + c1;
	cp3.y = k3 * cp3.x + c3;
	cp4.y = k4 * cp4.x + c4;

	/*circle(src, cp1, 3, Scalar(255, 0, 0), -1);
	circle(src, cp2, 3, Scalar(0, 255, 0), -1);
	circle(src, cp3, 3, Scalar(0, 0, 255), -1);
	circle(src, cp4, 3, Scalar(255, 255, 0), -1);	
	
	circle(exContourImg, cp1, 3, Scalar(255, 0, 0), -1);
	circle(exContourImg, cp2, 3, Scalar(0, 255, 0), -1);
	circle(exContourImg, cp3, 3, Scalar(0, 0, 255), -1);
	circle(exContourImg, cp4, 3, Scalar(255, 255, 255), -1);*/

	// Perspective Transformatin
	vector<Point2f> srcCorners(4), destCorners(4);
	srcCorners[0] = cp1;
	srcCorners[1] = cp2;
	srcCorners[2] = cp3;
	srcCorners[3] = cp4;

	//line(src, srcCorners[0], srcCorners[1], Scalar(1, 25, 255), 1);
	//line(src, srcCorners[1], srcCorners[3], Scalar(1, 25, 255), 1);
	//line(src, srcCorners[0], srcCorners[2], Scalar(1, 25, 255), 1);
	//line(src, srcCorners[2], srcCorners[3], Scalar(1, 25, 255), 1);

	destCorners[0] = Point(src_gray.size().width, 0);
	destCorners[1] = Point(0, 0);
	destCorners[2] = Point(src_gray.size().width, src_gray.size().height);
	destCorners[3] = Point(0, src_gray.size().height);

	Mat warpMatrix = getPerspectiveTransform(srcCorners, destCorners);
	warpPerspective(src, result, warpMatrix, result.size(), INTER_LINEAR);

	imshow("src", src);
	imshow("result", result);
	//imshow("middle", exContourImg);
	waitKey(0);
	return 0;
}