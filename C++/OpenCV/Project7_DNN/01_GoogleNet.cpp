#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/dnn.hpp>
#include<fstream>

using namespace std;
using namespace cv;
using namespace cv::dnn;

string model_file = "D:/Env/DNN_Model/bvlc_googlenet/bvlc_googlenet.caffemodel";
string model_txt_file = "D:/Env/DNN_Model/bvlc_googlenet/solver.prototxt";
string labels_txt_file = "D:/Env/DNN_Model/bvlc_googlenet/solver.prototxt";
vector<string> readLabels();

int main() {
	Mat src = imread("D:/•×‹­/C++/OpenCV/TestLib/cat.jpg");
	if (src.empty()) {
		cout << "Canot load Image.." << endl;
		return -1;
	}
	
	vector<string> labels = readLabels();

	Net googleNet = readNetFromCaffe(model_txt_file, model_file);
	if (googleNet.empty()) {
		cout << "Cannot load googleNet modelo.." << endl;
		return -1;
	}

	



	Mat inputBlob = blobFromImage(src, 1.0, Size(224, 224), Scalar(104, 117, 123));



	waitKey(0);
	return 0;
}

vector<string> readLabels() {
	vector<string> classNames;
	ifstream fin(labels_txt_file);
	if (!fin.is_open()) {
		cout << "Cannot open lables file.." << endl;
		exit(-1);
	}

	string name;
	while (!fin.eof()) {
		getline(fin, name);
		if (name.length()) {
			classNames.push_back(name.substr(name.find(' ' + 1)));
		}
	}

	fin.close();
	return classNames;
}