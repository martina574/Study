//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <math.h>
//
//using namespace cv;
//using namespace std;
//
//Mat src, dest;
//int element_size = 3;
//int max_size = 21;
//
//string OUTPUT_WIN = "Dilate";
//void Callback_Demo(int, void*);
//
//int main_morphology(int arg, char* arv)
//{
//	//src = imread("D:/ï◊ã≠/C++/OpenCV/TestLib/cvtest.png");
//	src = imread("D:/ï◊ã≠/C++/OpenCV/TestLib/closing.png");
//	if (!src.data) {
//		printf("Could not find image! \n");
//		return -1;
//	}
//
//	imshow("input", src);
//
//	/*namedWindow(OUTPUT_WIN, WINDOW_AUTOSIZE);
//	createTrackbar("Element size", OUTPUT_WIN, &element_size, max_size, Callback_Demo);
//	Callback_Demo(0, 0);*/
//
//	Mat kernal = getStructuringElement(MORPH_RECT, Size(5, 5));
//	//morphologyEx(src, dest, MORPH_OPEN, kernal);  // Open : Erode -> Dilate WhiteNoiseÇéÊÇËè¡Ç∑
//	//morphologyEx(src, dest, MORPH_CLOSE, kernal); // Close: Dilate-> Erode  BlackNoiseÇéÊÇËè¡Ç∑
//
//	//morphologyEx(src, dest, MORPH_GRADIENT, kernal);
//	//morphologyEx(src, dest, MORPH_TOPHAT, kernal);
//	morphologyEx(src, dest, MORPH_BLACKHAT, kernal);
//
//	imshow(OUTPUT_WIN, dest);
//
//	waitKey(0);
//	return 0;
//}
//
//void Callback_Demo(int, void*)
//{
//	int s = element_size * 2 + 1;
//	Mat structureElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
//
//	cout << structureElement << endl;
//
//	//dilate(src, dest, structureElement);
//	erode(src, dest, structureElement);
//	imshow(OUTPUT_WIN, dest);
//
//	return;
//}
