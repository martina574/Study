//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//int main(int, char**) {
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
//	Mat points(sampleCount, 1, CV_32FC2);
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
//	// KMeans
//	kmeans(points, num_clusters, labels, \
//		TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1), \
//		3, KMEANS_PP_CENTERS, centers);
//
//	// Show result
//	img = Scalar::all(255);
//	for (int i = 0; i < sampleCount; i++) {
//		int index = labels.at<int>(i);
//		Point p = points.at<Point2f>(i);
//		circle(img, p, 2, colorTab[index], -1, 8);
//	}
//
//	imshow("KMeans-Data-Demo", img);
//	waitKey(0);
//	return 0;
//
//}