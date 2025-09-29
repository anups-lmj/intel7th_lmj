
#include <iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s);

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;
	friend bool RectManager::equals(Rect r, Rect s);
	friend bool equals(Rect r, Rect s);
	bool equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src)
{
	dest.width = src.width;
	dest.height = src.height;
}

bool Rect::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

bool equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main()
{
	Rect a(3, 4), b(4, 5);
	RectManager man;
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
	
	man.copy(a, b);
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}

