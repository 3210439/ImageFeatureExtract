#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k = 0.04;
	Mat src, src_gray;
	int maxCorners = 300;

	src = imread("./chess.png");
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	imshow("src", src);

	goodFeaturesToTrack(src_gray,
		corners,
		maxCorners,
		qualityLevel,
		minDistance,
		Mat(),
		blockSize,
		useHarrisDetector,
		k);

	int r = 4;
	for (int i = 0; i < corners.size(); i++)
	{
		circle(src, corners[i], r, Scalar(0, 0, 255), -1, 8, 0);
	}

	imshow("src1", src);
	waitKey();
	return 0;
}
