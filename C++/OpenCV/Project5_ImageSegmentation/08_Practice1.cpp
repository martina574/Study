//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat mat_to_samples(Mat&);
//Scalar colorTab[] = {
//	Scalar(0,0,255),
//	Scalar(0,255,0),
//	Scalar(255,0,0),
//	Scalar(0,255,255),
//	Scalar(255,0,255)
//};
//
//int main() {
//	Mat src = imread("D:/•×‹­/C++/OpenCV/TestLib/toux.jpg");
//	if (src.empty()) {
//		cout << "cant load image.." << endl;
//		return -1;
//	}
//
//	namedWindow("input image", WINDOW_AUTOSIZE);
//	imshow("input image", src);
//
//	// Prepare data
//	Mat points = mat_to_samples(src);
//
//	// KMeans
//	int numCluster = 4;
//	Mat labels;
//	Mat centers;
//	/// Ternimate condition
//	TermCriteria criteria(TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1));
//	kmeans(points, numCluster, labels, criteria, 3, KMEANS_PP_CENTERS, centers);
//
//	// Delete bg & generate mask
//	Mat mask = Mat::zeros(src.size(), CV_8UC1);
//	int index = 0; // Get the background label, Any bg point is OK.
//	int cindex = labels.at<int>(index, 0);
//	int height = src.rows;
//	int width = src.cols;
//	Mat dest;
//	src.copyTo(dest);
//
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			int label = labels.at<int>(index, 0);
//			if (label == cindex) { // BackGround
//				/*dest.at<Vec3b>(row, col)[0] = 0;
//				dest.at<Vec3b>(row, col)[1] = 0;
//				dest.at<Vec3b>(row, col)[2] = 0;*/
//				mask.at<uchar>(row, col) = 0;
//			}
//			else {
//				mask.at<uchar>(row, col) = 255;
//			}
//		}
//	}
//
//	// Erode & Gaussian Blur
//	Mat k = getStructuringElement(MORPH_RECT, Size(3,3));
//	morphologyEx(mask, mask, MORPH_ERODE, k);
//	GaussianBlur(mask, mask, Size(3, 3), 0, 0);
//
//	// MixChannels
//	Vec3b color;
//	color[0] = theRNG().uniform(0, 255);
//	color[1] = theRNG().uniform(0, 255);
//	color[2] = theRNG().uniform(0, 255);
//	
//	Mat result(src.size(), src.type());
//	double w = 0.0;
//	int b = 0, g = 0, r = 0;
//	int b1 = 0, g1 = 0, r1 = 0;
//	int b2 = 0, g2 = 0, r2 = 0;
//
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			int m = mask.at<uchar>(row, col);
//			if (m == 255) {
//				// fg
//				result.at<Vec3b>(row, col) = src.at<Vec3b>(row, col);
//			}
//			else if (m == 0) {
//				// bg
//				result.at<Vec3b>(row, col) = color;
//			}
//			else {
//				// Edges
//				w = m / 255.0;
//				b1 = src.at <Vec3b>(row, col)[0];
//				g1 = src.at <Vec3b>(row, col)[1];
//				r1 = src.at <Vec3b>(row, col)[2];
//
//				b2 = color[0];
//				g2 = color[1];
//				r2 = color[2];
//
//				int b = b1 * w + b2 * (1.0 - w);
//				int g = g1 * w + g2 * (1.0 - w);
//				int r = r1 * w + r2 * (1.0 - w);
//
//				result.at<Vec3b>(row, col)[0] = b;
//				result.at<Vec3b>(row, col)[1] = g;
//				result.at<Vec3b>(row, col)[2] = r;
//			}
//		}
//	}
//
//
//	// Show
//	Mat result_test = Mat::zeros(src.size(), src.type());
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			int label = labels.at<int>(index, 0);
//			result_test.at<Vec3b>(row, col)[0] = colorTab[label][0];
//			result_test.at<Vec3b>(row, col)[1] = colorTab[label][1];
//			result_test.at<Vec3b>(row, col)[2] = colorTab[label][2];
//		}
//	}
//
//	imshow("Result", result);
//	imshow("Result-Test", result_test);
//	waitKey(0);
//	return 0;
//}
//
//Mat mat_to_samples(Mat &image) {
//	int w = image.cols;
//	int h = image.rows;
//	int sampleCnt = w * h;
//	int dims = image.channels();
//	Mat points(sampleCnt, dims, CV_32F, Scalar(10));
//
//	int index = 0;
//	for (int row = 0; row < h; row++) {
//		for (int col = 0; col < w; col++) {
//			index = row * w + col;
//			Vec3b bgr = image.at<Vec3b>(row, col);
//			points.at<float>(index, 0) = bgr[0];
//			points.at<float>(index, 1) = bgr[1];
//			points.at<float>(index, 2) = bgr[2];
//		}
//	}
//
//	return points;
//}