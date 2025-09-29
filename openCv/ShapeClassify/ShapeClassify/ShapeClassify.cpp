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
void setColorLabel(Mat& img, const vector<Point>& pts, colorInfoStruct* colorinfo)
{
	double centerPoint_x, centerPoint_y;
	Rect rc = boundingRect(pts);
	centerPoint_x = rc.tl().x + rc.width / 2;
	centerPoint_y = rc.br().y - rc.height / 2;
	Point2d center(centerPoint_x, centerPoint_y);

	Rect temp_rect(0, 0, 100, 100);

	double newRect_x, newRect_y;
	if (colorinfo->name == "red")
	{

		Size textsize = getTextSize("red", FONT_HERSHEY_PLAIN, 1, 1, 0);
		//putText(img, "red", center, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
		newRect_x = centerPoint_x - textsize.width / 2;
		newRect_y = centerPoint_y - textsize.height / 2;
		Point newRectLL(newRect_x, newRect_y + textsize.height);
		Rect newRect(newRect_x, newRect_y, textsize.width, textsize.height);
		rectangle(img, newRect, Scalar(255, 255, 0), -1);
		putText(img, "red", newRectLL, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);

	}
	else if (colorinfo->name == "blue")
	{
		Size textsize = getTextSize("blue", FONT_HERSHEY_PLAIN, 1, 1, 0);
		//putText(img, "red", center, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
		newRect_x = centerPoint_x - textsize.width / 2;
		newRect_y = centerPoint_y - textsize.height / 2;
		Point newRectLL(newRect_x, newRect_y + textsize.height);
		Rect newRect(newRect_x, newRect_y, textsize.width, textsize.height);
		rectangle(img, newRect, Scalar(0, 255, 255), -1);
		putText(img, "blue", newRectLL, FONT_HERSHEY_PLAIN, 1, Scalar(255, 0, 0), 1);
	}
	else if (colorinfo->name == "green")
	{
		Size textsize = getTextSize("green", FONT_HERSHEY_PLAIN, 1, 1, 0);
		//putText(img, "red", center, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 1);
		newRect_x = centerPoint_x - textsize.width / 2;
		newRect_y = centerPoint_y - textsize.height / 2;
		Point newRectLL(newRect_x, newRect_y + textsize.height);
		Rect newRect(newRect_x, newRect_y, textsize.width, textsize.height);
		rectangle(img, newRect, Scalar(255, 0, 255), -1);
		putText(img, "green", newRectLL, FONT_HERSHEY_PLAIN, 1, Scalar(0, 255, 0), 1);
	}
}

void setLabel(Mat& img, const vector<Point>& pts, string label)
{
	Rect rc = boundingRect(pts);
	//rectangle(img, rc, Scalar(0, 0, 0), 0);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0));


}
int main(int argc, char* argv[])
{
	int num = 0;
	Mat img = imread("640x480_shape.png", IMREAD_COLOR);

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	/*imshow("grayscale", gray);*/

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);

	//imshow("binary", bin);

	Mat morp, kernel;
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(bin, morp, MORPH_GRADIENT, kernel);
	//imshow("morp", morp);

	vector<vector<Point>> contours, bincontours;
	findContours(morp, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	findContours(bin, bincontours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	cout << "contours.size() " << contours.size() << endl;
	drawContours(img, contours, -1, Scalar(128, 128, 128), 2);

	for (vector<Point> pts : contours) {
		if (contourArea(pts) < 400)
			continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);

		int vtc = (int)approx.size();
		if (vtc == 3) {
			setLabel(img, pts, "triangle");
		}
		else if (vtc == 4) {
			setLabel(img, pts, "rectangle");
		}
		else if (vtc == 5) {
			setLabel(img, pts, "pentagon");
		}
		else if (vtc == 6) {
			setLabel(img, pts, "hexagon");
		}
		else {
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4. * CV_PI * area / (len * len);

			if (ratio > 0.85) {
				setLabel(img, pts, "circle");
			}
			else
				setLabel(img, pts, "OVAL");
		}
		Scalar meanHsv;
		Mat hsvImage;
		int centerPoint_x, centerPoint_y;
		Rect rc = boundingRect(pts);
		centerPoint_x = rc.tl().x + rc.width / 2;
		centerPoint_y = rc.br().y - rc.height / 2;
		Point pt1(centerPoint_x - 10, centerPoint_y - 10), pt2(centerPoint_x + 10, centerPoint_y + 10);
		//cout << pt1 << pt2 << endl;
		Rect findrect(pt1, pt2);
		//cout << findrect << endl;
		//rectangle(img, findrect, Scalar(0, 0, 0), 1);
		Mat frameRoi = img(findrect);
		//cout << frameRoi << endl;
		cvtColor(frameRoi, hsvImage, COLOR_BGR2HSV);// 이미지의 RGB를 HSV값으로 변경
		meanHsv = mean(hsvImage); //사각형의 HSV 평균을 구함
		cout << "HSV : " << meanHsv << endl;
		colorInfoStruct sendColorInfo;
		if (170 <= meanHsv[0] || meanHsv[0] < 10)
		{
			colorInfo[2].count++;
			sendColorInfo.name = "red";
			sendColorInfo.color = Scalar(0, 0, 255);
			sendColorInfo.count = 0;
			setColorLabel(img, pts, &sendColorInfo);
		}
		else if (40 <= meanHsv[0] && meanHsv[0] < 70)
		{
			colorInfo[1].count++;
			sendColorInfo.name = "green";
			sendColorInfo.color = Scalar(0, 0, 255);
			sendColorInfo.count = 0;
			setColorLabel(img, pts, &sendColorInfo);
		}
		else if (90 <= meanHsv[0] && meanHsv[0] < 130)
		{
			colorInfo[0].count++;
			sendColorInfo.name = "blue";
			sendColorInfo.color = Scalar(255, 0, 0);
			sendColorInfo.count = 0;
			setColorLabel(img, pts, &sendColorInfo);
		}
		else
			colorInfo[3].count++;
		num++;
		
	}
	putText(img, "LEE MJ", Point(20, 40), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0), 3);
	for (int i = 0; i < sizeof(colorInfo) / sizeof(colorInfo[0]); i++)
	{
		String strText = colorInfo[i].name + " " + to_string(colorInfo[i].count);
		putText(img, strText, Point(20, 60 + (15 * i)), FONT_HERSHEY_PLAIN, 1, colorInfo[i].color, 1);
	}

	imshow("img", img);

	waitKey();
	return 0;
}