//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//using namespace cv::ml;
//
//int main() {
//	Mat img(500, 500, CV_8UC3);
//	RNG rng(12345);
//
//	Scalar colorTab[] = {
//		Scalar(0,0,255),
//		Scalar(0,255,0),
//		Scalar(255,0,0),
//		Scalar(0,255,255),
//		Scalar(255,0,255)
//	};
//
//	int num_clusters = rng.uniform(2, 5);
//	cout << "Num of clusters: " << num_clusters << endl;
//
//	int sampleCount = rng.uniform(5, 1000);
//	Mat points(sampleCount, 2, CV_32FC1);
//	Mat labels;
//	Mat centers;
//
//	// Generate random data
//	for (int k = 0; k < num_clusters; k++) {
//		Point center;
//		center.x = rng.uniform(0, img.cols);
//		center.y = rng.uniform(0, img.rows);
//		// Mat.rowRange-> Extract the area in the designated row ranges.
//		Mat pointChunk = points.rowRange(k*sampleCount / num_clusters, \
//			k == num_clusters - 1 ? sampleCount : (k + 1)*sampleCount / num_clusters);
//		// Fill the designated area with random data.
//		rng.fill(pointChunk, RNG::NORMAL, \
//			Scalar(center.x, center.y), Scalar(img.cols*0.05, img.rows*0.05));
//	}
//	randShuffle(points, 1, &rng);
//
//	// EM
//	Ptr<EM> em_model = EM::create();
//	em_model->setClustersNumber(num_clusters);
//	em_model->setCovarianceMatrixType(EM::COV_MAT_SPHERICAL);
//	em_model->setTermCriteria(TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 100, 0.1));
//	em_model->trainEM(points, noArray(), labels, noArray());
//
//	// Classify every image pixels
//	Mat sample(1, 2, CV_32FC1);
//	for (int row = 0; row < img.rows; row++) {
//		for (int col = 0; col < img.cols; col++) {
//			sample.at<float>(0) = (float)col;
//			sample.at<float>(1) = (float)row;
//			int responce = cvRound(em_model->predict2(sample, noArray())[1]);
//			Scalar c = colorTab[responce];
//			circle(img, Point(col, row), 1, c*0.75, -1);
//		}
//	}
//
//	// Draw the cluster
//	for (int i = 0; i < sampleCount; i++) {
//		Point p(cvRound(points.at<float>(i, 0)), cvRound(points.at<float>(i, 1)));
//		circle(img, p, 1, colorTab[labels.at<int>(i)], -1);
//	}
//
//	imshow("Result", img);
//	waitKey(0);
//	return 0;
//}