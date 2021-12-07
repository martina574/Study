//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//const char* winTitle = "Input image";
//Rect rect;
//bool init = false;
//Mat src, image, mask, bgModel, fgModel;
//int numRun = 0;
//void onMouse(int event, int x, int y, int flag, void* param);
//void showImage();
//void setROIMask();
//void runGrabCut();
//
//int main() {
//	src = imread("D:/•×‹­/C++/OpenCV/TestLib/grabCut_3.PNG");
//	if (src.empty()) {
//		cout << "Cannot load image.." << endl;
//		return -1;
//	}
//
//	mask.create(src.size(), CV_8UC1);
//	mask.setTo(Scalar::all(GC_BGD));
//
//	namedWindow(winTitle, WINDOW_AUTOSIZE);
//	setMouseCallback(winTitle, onMouse, 0);
//	imshow(winTitle, src);
//
//	while (true) {
//		char c = (char)waitKey(0);
//		if (c == 'n') {
//			runGrabCut();
//			numRun++;
//			showImage();
//			cout << "Current iteration: " << numRun << endl;
//		}
//		if (c == 27) {
//			break;
//		}
//	}
//
//	waitKey(0);
//	return 0;
//}
//
//void onMouse(int event, int x, int y, int flag, void* param) {
//	switch (event) {
//	case EVENT_LBUTTONDOWN:
//		rect.x = x;
//		rect.y = y;
//		rect.width = 1;
//		rect.height = 1;
//		init = false;
//		break;
//	case EVENT_MOUSEMOVE:
//		if (flag & EVENT_FLAG_LBUTTON) {
//			rect = Rect(Point(rect.x, rect.y), Point(x, y));
//			showImage();
//		}
//		break;
//	case EVENT_LBUTTONUP:
//		if (rect.width > 1 && rect.height > 1) {
//			setROIMask();
//			showImage();
//		}
//	default:
//		break;
//	}
//}
//
//void showImage() {
//	Mat result, binMask;
//	binMask.create(src.size(), CV_8UC1);
//	binMask = mask & 1;
//	if (init) {
//		// Init with mask
//		src.copyTo(result, binMask);
//	}
//	else {
//		// Init with rect
//		src.copyTo(result);
//	}
//
//	rectangle(result, rect, Scalar(0, 0, 255), 2);
//	imshow(winTitle, result);
//}
//
//void setROIMask() {
//	mask.setTo(GC_BGD);
//	rect.x = max(0, rect.x);
//	rect.y = max(0, rect.y);
//	rect.width = min(rect.width, src.cols - rect.x);
//	rect.height = min(rect.height, src.rows - rect.y);
//
//	mask(rect).setTo(GC_PR_FGD);
//}
//
//void runGrabCut() {
//	if (rect.width < 2 || rect.height < 2) {
//		return;
//	}
//
//	if (init) {
//		grabCut(src, mask, rect, bgModel, fgModel, 1);
//	} 
//	else{
//		grabCut(src, mask, rect, bgModel, fgModel, 1, GC_INIT_WITH_RECT);
//		init = true;
//	}
//}