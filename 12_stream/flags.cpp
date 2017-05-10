#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	float b;
	char x[80];
	cout.setf(ios::showpos);
	cout.setf(ios::scientific);
	cout << a << endl;
	cout << b << endl;
	cout.unsetf(ios::showpos);
	cout << a << endl;
	cin.setf(ios::skipws);
	 cin >> x;
	cout << x << endl;

	cout << "####################" << endl;
	char * ptr_s;
	ptr_s = new char [80];
	 cin >> ws >> ptr_s;
	cout << ptr_s << endl;
	delete [] ptr_s;

	return 0;
}