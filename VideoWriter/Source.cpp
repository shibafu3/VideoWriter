#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif

#include "opencv2/highgui.hpp"
#include "opencv2/Videoio.hpp"
#include <opencv2/core.hpp>

#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

	VideoWriter writer("C:\\Users\\0133752\\Documents\\OutVideo.wmv", cv::VideoWriter::fourcc('W', 'M', 'V', '1'), 15.0, Size(1024, 1024));
	if (!writer.isOpened()){ return -1; }


	char image_name[100];
	Mat image;


	for (int i = 0; i < 1001; i++){
		sprintf(image_name, "C:\\log\\%07d.jpg", i);
		image = imread(image_name);

		if (image.empty()) {
			cout << "no image : " << image_name << endl;
			continue;
		}

		writer << image;
	}
	return 0;
}