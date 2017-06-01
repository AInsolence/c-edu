#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	const int SIZE = 7;
	char buffer[SIZE] ="Hello!";

	cout << "Buffer before any operations:\n";
	for(int i =0; i < SIZE; i++){
		cout << buffer[i] << endl;
	}

	ofstream out("test_2.txt", ios::out | ios::binary);
	if (!out){
		cout << "File is not open!";
		return 1;
	}

	out.write((char*) &buffer, sizeof buffer);
	out.close();

	for(int i =0; i < SIZE; i++){
		buffer[i] = 0;
	}

	cout << "Buffer after clearing:\n";
	for(int i =0; i < SIZE; i++){
		cout << buffer[i] << endl;
	}

	ifstream in("test_2.txt", ios::in | ios::binary);
	if (!in){
		cout << "File is not open!";
		return 1;
	}

	in.read((char*) &buffer, sizeof buffer);
	in.close();

	cout << "Buffer after reading from file:\n";
	for(int i =0; i < SIZE; i++){
		cout << buffer[i] << endl;
	}

	int last_oper;
	last_oper = in.gcount();
	cout << last_oper << endl;

	return 0;
}