#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout.setf(ios::left);
	cout << "fill = \"" << cout.fill() << "\"" << endl;
	cout << "width = " << cout.width() << endl;
	cout << "precision = " << cout.precision() << endl;
	float f = 123.132424231313;
	char text [80]= "This is demo";
	cout << f << endl;
	cout << text << endl;
	cout.precision(10);
	cout.fill('@');
	cout << f << endl;
	cout.width(20);
	cout << text << endl;
	cout.unsetf(ios::left);
	cout.width(20);
	cout << text << endl;
	return 0;
}