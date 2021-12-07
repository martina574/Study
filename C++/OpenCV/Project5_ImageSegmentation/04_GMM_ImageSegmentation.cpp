//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<opencv2/ml.hpp>
//
//using namespace cv;
//using namespace std;
//using namespace cv::ml;
//
//int main() {
//	Mat src = imread("D:/•×‹­/C++/OpenCV/TestLib/toux.jpg");
//	if (src.empty()) {
//		printf("Could not load image...\n");
//		return -1;
//	}
//
//	string inputWinTitle = "Input Image";
//	namedWindow(inputWinTitle, WINDOW_AUTOSIZE);
//	imshow(inputWinTitle, src);
//
//	// Initiation
//	int numClusters = 3;
//	const Scalar colors[] = {
//		Scalar(255, 0, 0),
//		Scalar(0, 255, 0),
//		Scalar(0, 0, 255),
//		Scalar(255, 0, 255)
//	};
//	int width = src.cols;
//	int height = src.rows;
//	int dims = src.channels();
//	int nsamples = width * height;
//
//	Mat points(nsamples, dims, CV_64FC1);
//	Mat labels;
//	Mat result = Mat::zeros(src.size(), CV_8UC3);
//
//	// Convert RGB image to sample data
//	int index = 0;
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			Vec3b rgb = src.at<Vec3b>(row, col);
//			points.at<double>(index, 0) = static_cast<int>(rgb[0]);
//			points.at<double>(index, 1) = static_cast<int>(rgb[1]);
//			points.at<double>(index, 2) = static_cast<int>(rgb[2]);
//		}
//	}
//
//	// EM cluster train
//	Ptr<EM> em_model = EM::create();
//	em_model->setClustersNumber(numClusters);
//	em_model->setCovarianceMatrixType(EM::COV_MAT_SPHERICAL);
//	em_model->setTermCriteria(TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 100, 0.1));
//	em_model->trainEM(points, noArray(), labels, noArray());
//
//	// Draw result
//	/*Mat sample(dims, 1, CV_64FC1);
//	double time = getTickCount();
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			int label = labels.at<int>(index, 0);
//			Scalar c = colors[label];
//			result.at<Vec3b>(row, col)[0] = c[0];
//			result.at<Vec3b>(row, col)[1] = c[1];
//			result.at<Vec3b>(row, col)[2] = c[2];
//		}
//	}*/
//
//	Mat sample(dims, 1, CV_64FC1);
//	int r = 0, g = 0, b = 0;
//	double time = getTickCount();
//	for (int row = 0; row < height; row++) {
//		for (int col = 0; col < width; col++) {
//			index = row * width + col;
//			b = src.at<Vec3b>(row, col)[0];
//			g = src.at<Vec3b>(row, col)[1];
//			r = src.at<Vec3b>(row, col)[2];
//			sample.at<double>(0) = b;
//			sample.at<double>(1) = g;
//			sample.at<double>(2) = r;
//
//			int responce = cvRound(em_model->predict2(sample, noArray())[1]);
//			Scalar c = colors[responce];
//			result.at<Vec3b>(row, col)[0] = c[0];
//			result.at<Vec3b>(row, col)[1] = c[1];
//			result.at<Vec3b>(row, col)[2] = c[2];
//		}
//	}
//
//	printf("Execution times(s):%d", ((getTickCount() - time) / getTickFrequency()));
//	imshow("Result", result);
//	waitKey(0);
//	return 0;
//}