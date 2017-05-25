#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	char ch;

	if (argc != 2){
		cout << "start program with a second argument file name";
		return 1;
	}

	ifstream in(argv[1], ios::binary | ios::app);

	if (!in.is_open()){
		cout << "!cannot open the file test1.txt!";
		return 1;
	}

	while (in.get(ch)) cout << ch; // get() return in-object which is return false when it approaches the end of file

	in.close();

	return 0;
}