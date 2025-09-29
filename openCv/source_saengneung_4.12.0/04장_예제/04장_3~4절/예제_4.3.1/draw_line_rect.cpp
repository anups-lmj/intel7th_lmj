#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Scalar white(255, 255, 255), yellow(0, 255, 255), blue(255, 0, 0);
	Scalar red = Scalar(0, 0, 255);
	Scalar green = Scalar(0, 255, 0);

	Mat image(400, 600, CV_8UC3, white);
	Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50);
	Rect  rect(pt3, Size(200, 150));

	line(image, pt1, pt2, red);
	line(image, pt3, pt4, green, 2, LINE_AA);
	line(image, pt3, pt4, green, 3, LINE_8, 1);

	rectangle(image, rect, blue, 2 );
	rectangle(image, rect, blue, FILLED, LINE_4, 1);
	rectangle(image, pt1, pt2, red, 3 );

	imshow("���� & �簢��", image);
	//setMouseCallback("���� & �簢��", onMouse, 0);
	waitKey(0);
	return 0;
}
void onMouse(int event, int x, int y, int flags, void* param)
{

	cout << "x : " << x << " y : " << y << " flags : " << flags << " param : " << param << endl;
	switch (event)			//switch������ event���� ���� ��ư ������ ����
	{
	case EVENT_LBUTTONDOWN:	cout << "���콺 ���ʹ�ư ������" << endl;	break;
	case EVENT_RBUTTONDOWN:	cout << "���콺 �����ʹ�ư ������" << endl;	break;
	case EVENT_RBUTTONUP:	cout << "���콺 �����ʹ�ư ����" << endl;	break;
	case EVENT_LBUTTONDBLCLK: cout << "���콺 ���ʹ�ư ����Ŭ��" << endl;	break;
	case EVENT_MBUTTONDOWN: cout << "���콺 �߰���ư Ŭ��" << endl; break;
	}
}