#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	ofstream out("test.txt");

	if(!out.is_open()){
		cout << "File is not open!\n";
		return 1;
	}

	out << 1 << 123.22 << "Here is some text information!\n";
	out.close();

	ofstream out1("test.txt", ios::app | ios::binary);
	out1 << "   Helllolololo! \n";
	out1 << "   Helllolololo! \n";
	out1.close();

	ifstream in("test.txt");
	
	if(!in.is_open()){
		cout << "File is not open!\n";
		return 1;
	}

	int i;
	double d;
	char str [100];

	in >> i;
	in >> d;
	in.getline(str, 100);

	cout << i << " " << d << " " << " " << str << endl;

	in.close();

	return 0;
}