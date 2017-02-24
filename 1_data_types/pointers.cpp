#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int num = 13;
	char myName [80] = "Anton\n";
	cout << num << ' ' << myName;
	int *ptrnum;
	ptrnum = &num;

	cout << "Pointer of num return " << ptrnum << endl;

	double x, y;
	int *ptrx;
	x = 123.23;
	ptrx = (int*) &x;
	y = *ptrx;
	cout << "x " << x << endl;
	cout << "y " << y << endl;

	return 0;
}