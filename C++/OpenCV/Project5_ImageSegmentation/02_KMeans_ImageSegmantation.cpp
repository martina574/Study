//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int, char**) {
//	Mat src, gray, dest, result;
//	src = imread("D:/�׋�/C++/OpenCV/TestLib/toux.jpg");
//	if (src.empty()) {
//		cout << "Cannot find image..." << endl;
//		return -1;
//	}
//
//	int width = src.cols;
//	int height = src.rows;
//	int dims = src.channels();
//
//	Scalar colorTab[] = {
//		Scalar(0,0,255),
//		Scalar(0,255,0),
//		Scalar(255,0,0),
//		Scalar(0,255,255),
//		Scalar(255,0,255)
//	};
//
//	// Initiation
//	int sampleCount = width * height;
//	int clusterCount = 4;
//	Mat points(sampleCount, dims, CV_32F, Scalar(10));
//	Mat labels;
//	Mat centers(clusterCount, 1, points.type());
//
//	// RGB data -> Sample data
//	int index = 0;
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			Vec3b bgr = src.at<Vec3b>(row, col);
//			points.at<float>(index, 0) = static_cast<int>(bgr[0]);
//			points.at<float>(index, 1) = static_cast<int>(bgr[1]);
//			points.at<float>(index, 2) = static_cast<int>(bgr[2]);
//		}
//	}
//
//	// KMeans
//	TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 0.1);
//	kmeans(points, clusterCount, labels, criteria, 3, KMEANS_PP_CENTERS, centers);
//
//	// Show
//	result = Mat::zeros(src.size(), src.type());
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			int label = labels.at<int>(index, 0);
//			result.at<Vec3b>(row, col)[0] = colorTab[label][0];
//			result.at<Vec3b>(row, col)[1] = colorTab[label][1];
//			result.at<Vec3b>(row, col)[2] = colorTab[label][2];
//		}
//	}
//
//	for (int i = 0; i < clusterCount; i++) {
//		Point center;
//		center.x = centers.at<float>(i, 0);
//		center.y = centers.at<float>(i, 1);
//		circle(result, center, 4, Scalar(0, 0, 0), -1, LINE_AA);
//	}
//
//	imshow("Result", result);
//	waitKey(0);
//	return 0;
//
//}