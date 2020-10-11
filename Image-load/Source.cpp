#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include <sys/stat.h>

bool fileExist(const std::string& dir) 
{
	struct stat file;
	return (stat(dir.c_str(), &file) == 0);
}

int main()
{
	std::vector<cv::Mat> images;
	std::string __dir;
	for (int i = 0; i < 3; i++) {
		__dir = "images/" + std::to_string(i) + ".jpg";
		if (fileExist(__dir)) {
			images.push_back(cv::imread(__dir));
		}
		else {
			__dir = "images/" + std::to_string(i) + ".png";
			images.push_back(cv::imread(__dir));
		}
		cv::namedWindow("image"+std::to_string(i), cv::WINDOW_NORMAL);
		imshow("image" + std::to_string(i), images[i]);
		cv::waitKey(0);
	}
	return 0;
}