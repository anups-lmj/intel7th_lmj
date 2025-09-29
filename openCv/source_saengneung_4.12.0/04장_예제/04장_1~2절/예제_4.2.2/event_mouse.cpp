#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void onMouse(int, int, int, int, void *);		// ���콺 �ݹ� �Լ�

int main()
{
	Mat image(200, 300, CV_8U);
	image.setTo(255);	// image ��� �ʱ�ȭ - ��� ����
	int param = 100;
	imshow("���콺 �̺�Ʈ1", image);
	imshow("���콺 �̺�Ʈ2", image);

	setMouseCallback("���콺 �̺�Ʈ1", onMouse, &param);
	waitKey(0);
	return 0;
}

void onMouse(int event, int x, int y, int flags, void * param)
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