#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

// Declaration
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolygon();
void RandomLineDemo();
const char* drawdemo_win = "Draw Demo";
Mat bgImg;

int main_basicDraw(int arg, char* arv)
{
	Mat src, det;
	bgImg = imread("D:/•×‹­/C++/OpenCV/TestLib/img2.jpg");

	if (!bgImg.data) {
		printf("Could not find image! \n");
		return -1;
	}

	//MyLines();
	//MyRectangle();
	//MyEllipse();
	//MyCircle();
	//MyPolygon();
	//putText(bgImg, "Hello opencv", Point(20, 20), FONT_HERSHEY_COMPLEX, 2.0, Scalar(12,244,300));

	RandomLineDemo();

	imshow("input", bgImg);
	waitKey(0);
	return 0;
}

void MyLines()
{
	Point p1 = Point(20, 30);
	Point p2;
	p2.x = 200;
	p2.y = 300;

	Scalar color = Scalar(0, 0, 255);
	line(bgImg, p1, p2, color, 1, LINE_AA);
}

void MyRectangle()
{
	Rect rect = Rect(20, 10, 100, 100);// start , height, width
	Scalar color = Scalar(0, 0, 255);
	rectangle(bgImg, rect, color);
}

void MyEllipse() 
{
	Scalar color = Scalar(0, 255, 0);
	ellipse(bgImg, Point(bgImg.cols / 2, bgImg.rows / 2), Size(bgImg.cols / 4, bgImg.rows / 8), 45, 0, 180, color, 2);
}

void MyCircle()
{
	Scalar color = Scalar(0, 255, 0);
	Point center = Point(bgImg.cols / 2, bgImg.rows / 2);
	circle(bgImg, center, 40, color);
}

void MyPolygon()
{
	Scalar color = Scalar(0, 255, 0);
	Point pts[1][5];

	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);
	
	const Point * ppts[] = { pts[0] };
	int npt[] = { 5 };

	fillPoly(bgImg, ppts, npt, 1, color);
}

void RandomLineDemo()
{
	RNG rng(12345);
	Point p1, p2;
	Mat m = Mat::zeros(bgImg.size(), bgImg.type());
	for (int i= 0; i < 10000; i++)
	{
		p1.x = rng.uniform(0, bgImg.cols);
		p1.y = rng.uniform(0, bgImg.rows);
		p2.x = rng.uniform(0, bgImg.cols);
		p2.y = rng.uniform(0, bgImg.rows);

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

		if (waitKey(50) > 0) {
			break;
		}
		line(m, p1, p2, color);

		imshow("random", m);
	}
}

