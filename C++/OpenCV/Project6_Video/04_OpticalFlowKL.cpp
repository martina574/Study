///*
//1-Step: For the first frame image->Corner detection.
//2-Step: Store the result.
//*/
//
//
//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//vector<Point2f> features;  // SHI_TOMAS feature data
//vector<Point2f> iniPoints; // Initial feature data
//vector<Point2f> fpts[2];   // Current&Previous frame feature data
//
//void detectFeatures(Mat &inframe, Mat &ingray);
//void drawFeatures(Mat &inFrame);
//void klTrackFeature();
//void drawTrackLines();
//
//Mat frame, gray;
//Mat prev_frame, prev_gray;
//vector<uchar> status;
//vector<float> errors;
//
//int main() {
//	VideoCapture cap(0);
//	//cap.open("D:/•×‹­/C++/OpenCV/TestLib/01.mp4");
//	if (!cap.isOpened()) {
//		cout << "Cannot open video." << endl;
//		return -1;
//	}
//
//	while (cap.read(frame)) {
//		// Coners is detected by gray images.
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		/// fpts[0] previous frame feature data.
//		/// As the tracking going on, the corner data is getting fewer.
//		/// We need to redetect the corner points every several frames.
//		if (fpts[0].size() < 40) {
//			// Use Shi-Tomas to detect corners.
//			detectFeatures(frame, gray);
//			// -> Store corner detection data into fpts[0]:Current feature points.
//			fpts[0].insert(fpts[0].end(), features.begin(), features.end());
//			// -> Store corner detection data in initial corner points.
//			iniPoints.insert(iniPoints.end(), features.begin(), features.end());
//		}
//		else {
//			//printf("Tracking...\n");
//		}
//
//		if (prev_gray.empty()) {
//			// The first frame
//			gray.copyTo(prev_gray);
//		}
//
//		//klTrackFeature();
//		//drawFeatures(frame);
//
//		// Update previous data.
//		gray.copyTo(prev_gray);
//		frame.copyTo(prev_frame);
//
//		// Show
//		imshow("Demo", frame);
//		char c = waitKey(20);
//		if (c == 27) {
//			break;
//		}
//	}
//
//	cap.release();
//	waitKey(0);
//	return 0;
//}
//
//// Simply use shi-tomas to detect corner points.
//void detectFeatures(Mat &inframe, Mat &ingray) {
//	// Shi-Tomas Corner detection
//	goodFeaturesToTrack(ingray, features, 0, 0.01, 10);
//	//printf("Shi-Tomas Detection...\n");
//}
//
//// Draw shi-tomas corners.
//void drawFeatures(Mat &inFrame) {
//	for (size_t i = 0; i < features.size(); i++) {
//		circle(inFrame, features[i], 2, Scalar(0, 0, 255), 2);
//	}
//}
//
//// KL Track features.
//void klTrackFeature() {
//	// Call the api
//	calcOpticalFlowPyrLK(prev_gray, gray, fpts[0], fpts[1], status, errors);
//	int k = 0;
//	// Status is set to 1 if the previous corner point is detected.
//	// Otherwise is set to 0.
//	for (int i = 0; i < fpts[1].size(); i++) {
//		// Calculate the distance between the current feature point and detected feature point.
//		double dist = abs(fpts[0][i].x - fpts[1][i].x) + abs(fpts[0][i].y - fpts[1][i].y);
//		// The previous feature is detected within the current frame. -> Status:1
//		// And the moving distance is short enough.
//		if (dist > 2 && status[i]) {
//			// Update iniPoints
//			iniPoints[k] = iniPoints[i];
//			// Delete untracking feature points.
//			fpts[1][k++] = fpts[1][i];
//		}
//	}
//	// Resize the vectors
//	iniPoints.resize(k);
//	fpts[1].resize(k);
//	drawTrackLines();
//
//	swap(fpts[1], fpts[0]);
//}
//
//void drawTrackLines() {
//	for (size_t i = 0; i < fpts[1].size(); i++) {
//		line(frame, iniPoints[i], fpts[1][i], Scalar(0, 255, 0));
//		circle(frame, fpts[1][i], 2, Scalar(0, 0, 255), 2, 8, 0);
//	}
//}