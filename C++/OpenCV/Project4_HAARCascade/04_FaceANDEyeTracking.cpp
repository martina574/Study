//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace  cv;
//
//string filename = "D:/•×‹­/C++/OpenCV/TestLib/01.mp4";
//string faceFile = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_frontalface_alt.xml";
//string eyeFile = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_eye.xml";
////string reyeFile = "D:/Env/opencv_build/build/install/etc/haarcascades/haarcascade_righteye_2splits.xml";
//
//void track_eye(Mat &img, Mat &tmp, Rect &rect) {
//	Mat track_result;
//	int result_cols = img.cols - tmp.cols + 1;
//	int result_rows = img.rows - tmp.rows + 1;
//
//	if (result_cols < 0 || result_rows < 0) {
//		cout << "??" << endl;
//		rect.x = rect.y = rect.height = rect.width = 0;
//		return;
//	}
//
//	track_result.create(result_rows, result_rows, CV_32FC1);
//	matchTemplate(img, tmp, track_result, TM_CCORR_NORMED);
//
//	double minVal, maxVal;
//	Point minLoc, maxLoc;
//	minMaxLoc(track_result, &minVal, &maxVal, &minLoc, &maxLoc);
//	if (maxVal > 0.75) {
//		rect.x += maxLoc.x;
//		rect.y += maxLoc.y;
//		rect.height = tmp.rows;
//		rect.width = tmp.cols;
//	}
//	else {
//		rect.x = rect.y = rect.height = rect.width = 0;
//	}
//}
//
//int main(int, char**) {
//	CascadeClassifier faceCascade;
//	CascadeClassifier leyeCascade;
//	CascadeClassifier reyeCascade;
//	VideoCapture capture(0);
//	//if (!capture.open(filename)) {
//	//	cout << "Cannot open video!..\n" << endl;
//	//	return -1;
//	//}
//	if (!faceCascade.load(faceFile)) {
//		cout << "Cannot open face file!..\n" << endl;
//		return -1;
//	}
//	if (!leyeCascade.load(eyeFile)) {
//		cout << "Cannot open left eye file!..\n" << endl;
//		return -1;
//	}
//	if (!reyeCascade.load(eyeFile)) {
//		cout << "Cannot open right eye file!..\n" << endl;
//		return -1;
//	}
//
//	Mat lefttpl, righttpl, frame, gray;
//	Rect leftRect, rightRect;
//	while (capture.read(frame)) {
//
//#pragma region Basic Face detection
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		equalizeHist(gray, gray);
//
//		vector<Rect> faces;
//		faceCascade.detectMultiScale(gray, faces);
//#pragma endregion
//
//		for (size_t i = 0; i < faces.size(); i++) {
//			rectangle(frame, faces[i], Scalar(255, 0, 0));
//			// For each face, detect the eyes.
//#pragma region eyedetection
//			// Common
//			int offsety = faces[i].height / 6;
//			int offsetx = faces[i].width / 12;
//			/*int eyeheight = faces[i].height / 2 - offsety;
//			int eyewidth = faces[i].width / 2 - offsetx;*/
//			int eyeheight = faces[i].height / 2;
//			int eyewidth = faces[i].width / 2;
//			Rect leftEyeRoi, rightEyeRoi;
//
//			// Left(Right) Eye Raw Area.
//			leftEyeRoi.x = faces[i].x + offsetx;
//			leftEyeRoi.y = faces[i].y + offsety;
//			leftEyeRoi.width = eyewidth;
//			leftEyeRoi.height = eyeheight;
//
//			rightEyeRoi.x = faces[i].x + faces[i].width / 2;
//			rightEyeRoi.y = faces[i].y + offsety;
//			rightEyeRoi.width = eyewidth;
//			rightEyeRoi.height = eyeheight;
//
//			// Detect Eye in raw area.
//			Mat leftRoi = gray(leftEyeRoi);
//			Mat rightRoi = gray(rightEyeRoi);
//			vector<Rect> leftEye, rightEye;
//			leyeCascade.detectMultiScale(leftRoi, leftEye, 1.1, 1, 0, Size(20, 20));
//			reyeCascade.detectMultiScale(rightRoi, rightEye, 1.1, 1, 0, Size(20, 20));
//
//			if (lefttpl.empty()) {
//				if (leftEye.size()) {
//					leftRect = leftEye[0] + Point(leftEyeRoi.x, leftEyeRoi.y);
//					lefttpl = gray(leftRect).clone();
//					rectangle(frame, leftRect, Scalar(0, 255, 0));
//				}
//			}
//			else {
//				leftRect.x = leftEyeRoi.x;
//				leftRect.y = leftEyeRoi.y;
//				track_eye(leftRoi, lefttpl, leftRect);
//				if (leftRect.x > 0 && leftRect.y > 0) {
//					rectangle(frame, leftRect, Scalar(0, 255, 0));
//				}
//			}
//
//			if (righttpl.empty()) {
//				if (rightEye.size()) {
//					rightRect = rightEye[0] + Point(rightEyeRoi.x, rightEyeRoi.y);
//					righttpl = gray(rightRect).clone();
//					rectangle(frame, rightRect, Scalar(0, 255, 255));
//				}
//			}
//			else {
//				rightRect.x = rightEyeRoi.x;
//				rightRect.y = rightEyeRoi.y;
//				track_eye(rightRoi, righttpl, rightRect);
//				if (rightRect.x > 0 && rightRect.y > 0) {
//					rectangle(frame, rightRect, Scalar(0, 255, 255));
//				}
//			}
//		}
//#pragma endregion 
//		char c = cv::waitKey(20);
//		if (c == 27) {
//			break;
//		}
//
//		imshow("Result", frame);
//	}
//
//	capture.release();
//	cv::waitKey(0);
//	return 0;
//
//}