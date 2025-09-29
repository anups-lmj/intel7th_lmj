#include <iostream>
using namespace std;
int num = 5;
int main(int argc, char* argv[])
{
	int num = 1;
	double db = 3.1415;
	std::cout << "Hello" << std::endl;
	std::cout << num << std::endl;
	std::cout.precision(3);//std::cou
	std::cout << db << std::endl;
	std::cout << ::num << std::endl;

	cout << ::num << endl;

	return 0;
}