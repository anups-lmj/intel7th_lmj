#include <iostream>
using namespace std;
int num = 5;
int main(int argc, char* argv[])
{
	int num = 1;
	double db = 3.1415;
	cout << "hello" << endl;
	cout << num << endl;
	cout.precision(3);
	cout << db << endl;
	cout << ::num << endl;
	return 0;
}
