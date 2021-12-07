//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<math.h>
//
//using namespace std;
//using namespace cv;
//
//void lbp_basic(Mat &);
//void lbp_extend_callback(int, void *);
//
//Mat gray;
//Mat lbpEImg;
//int elbp_radius = 10;
//
//int main() {
//	Mat src, dest;
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/Img1.jpg");
//	if (!src.data) {
//		printf("Cound not load image ... \n");
//		return -1;
//	}
//
//	cvtColor(src, gray, COLOR_BGR2GRAY);
//
//	// calc LBP image
//	Mat lbpImg;
//	int height = gray.rows;
//	int width = gray.cols;
//	lbpImg = Mat::zeros(height - 2, width - 2, CV_8UC1);
//	lbp_basic(lbpImg);
//
//	// calc extended LBP image
//	namedWindow("result_extend", WINDOW_AUTOSIZE);
//	createTrackbar("ELBP Radius", "result_extend", &elbp_radius, 20, lbp_extend_callback);
//	lbp_extend_callback(0, 0);
//
//	imshow("result_basic", lbpImg);
//	imshow("Input", gray);
//	waitKey(0);
//	return 0;
//}
//
//void lbp_basic(Mat &result)
//{
//	int height = gray.rows;
//	int width = gray.cols;
//
//	for (int r = 1; r < height - 1; r++) {
//		for (int c = 1; c < width - 1; c++) {
//			uchar center = gray.at<uchar>(r, c);
//			uchar code = 0;
//			code |= (gray.at<uchar>(r - 1, c - 1) > center) << 7;
//			code |= (gray.at<uchar>(r - 1, c) > center) << 6;
//			code |= (gray.at<uchar>(r - 1, c + 1) > center) << 5;
//			code |= (gray.at<uchar>(r, c + 1) > center) << 4;
//			code |= (gray.at<uchar>(r + 1, c + 1) > center) << 3;
//			code |= (gray.at<uchar>(r + 1, c) > center) << 2;
//			code |= (gray.at<uchar>(r + 1, c - 1) > center) << 1;
//			code |= (gray.at<uchar>(r, c - 1) > center);
//			result.at<uchar>(r - 1, c - 1) = code;
//		}
//	}
//}
//
//
//void lbp_extend_callback(int, void*) {
//
//	int height = gray.rows;
//	int width = gray.cols;
//
//	int offset = elbp_radius * 2;
//	lbpEImg = Mat::zeros(height - offset, width - offset, CV_8UC1);
//
//	int neighbers = 8;
//	for (int i = 0; i < neighbers; i++) {
//		// anticlockwise -> clockwise
//		float x = static_cast<float>(elbp_radius) * cos(2.0 * CV_PI*i / neighbers);
//		float y = static_cast<float>(elbp_radius) * -sin(2.0 * CV_PI*i / neighbers);
//
//		// interpolation(bilinear interpolation)
//		int cx = static_cast<int>(ceil(x));
//		int cy = static_cast<int>(ceil(y));
//		int fx = static_cast<int>(floor(x));
//		int fy = static_cast<int>(floor(y));
//
//		// depending on the area, calculate the weight
//		float ty = y - fy;
//		float tx = x - fx;
//		
//		float w1 = (1 - tx)*(1 - ty);
//		float w2 = tx * (1 - ty);
//		float w3 = (1 - tx)*ty;
//		float w4 = tx * ty;
//
//		for (int r = elbp_radius; r < height - elbp_radius; r++) {
//			for (int c = elbp_radius; c < width - elbp_radius; c++) {
//				float val = w1 * gray.at<char>(r + fy, c + fx) + w2 * gray.at<char>(r + fy, c + cx) \
//					+ w3 * gray.at<char>(r + cy, c + fx) + w4 * gray.at<char>(r + cx, c + cy);
//				lbpEImg.at<uchar>(r - elbp_radius, c - elbp_radius) += (val > gray.at<uchar>(r, c)) << i;
//				/*lbpEImg.at<uchar>(r - elbp_radius, c - elbp_radius) += ((val > gray.at<uchar>(r, c)) && \
//					(abs(val - gray.at<uchar>(r, c)) > numeric_limits<float>::epsilon())) << i;*/
//			}
//		}
//		imshow("result_extend", lbpEImg);
//	}
//
//}
