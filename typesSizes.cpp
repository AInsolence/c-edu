#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Size of short int: " << sizeof(short int) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of signed int: " << sizeof(signed int) << endl;
	cout << "Size of long int: " << sizeof(long int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of long double: " << sizeof(long double) << endl;
	cout << "Size of char " << sizeof(char) << endl;
	cout << "Size of unsigned char: " << sizeof(unsigned char) << endl;
	cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;
	
	return 0;
}