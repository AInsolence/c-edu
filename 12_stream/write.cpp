#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	string arr;
	 getline(cin, arr);
	ofstream out("test1.txt", ios::binary | ios::app);
	if (!out){
		cout << "File is not open!";
		return 1;
	}
	out.write(&arr[0], 10);
	cout << arr;
	return 0;
}