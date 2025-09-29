#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

struct colorInfoStruct {
	String name;
	Scalar color;
	int count;
};

colorInfoStruct colorInfo[4] = {
	{"blue",Scalar(255,0,0),0},
	{"green",Scalar(0,255,0),0},
	{"red",Scalar(0,0,255),0},
	{"none",Scalar(128,128,128),0}
};
void setColorLabel(Mat& img, const vector<Point>& pts, colorInfoStruct * colorinfo)
{
	for (int i = 0; i < sizeof(colorInfo) / sizeof(colorInfo[0]); i++)
	{
		String strText = colorInfo[i].name + " " + to_string(colorInfo[i].count);
		putText(img, strText, Point(20, 60 + (15 * i)), FONT_HERSHEY_PLAIN, 1, colorInfo[i].color, 1);
	}
}
void setLabel(Mat& img, const vector<Point>& pts, string label)
{
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}
int main(int argc, char* argv[])
{
	Mat img = imread("640x480_shape.png", IMREAD_COLOR);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//imshow("gray", gray);

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);
	//imshow("bin", bin);

	vector<vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	cout << "contours.size() " << contours.size() << endl;
	for (vector<Point> pts : contours) {
		if (contourArea(pts) < 400)
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);

		int vtc = (int)approx.size();

		if (vtc == 3) {
			setLabel(img, pts, "TRI");
		}
		else if (vtc == 4) {
			setLabel(img, pts, "RECT");
		}
		else if (vtc == 6) {
			setLabel(img, pts, "HEXA");
		}
		else if (vtc == 10) {
			setLabel(img, pts, "STAR");

		}
		else {
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4. * CV_PI * area / (len * len);

			if (ratio > 0.85) {
				setLabel(img, pts, "CIR");
			}
			else
				setLabel(img, pts, "OVAL");
		}
	}

	imshow("img", img);

	waitKey();
	return 0;
}