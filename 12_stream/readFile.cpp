#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int BUF_SIZE = 1024;
	char buffer[BUF_SIZE];

	if (argc != 2){
		cout << "Program usage: prog_name file_name";
		return 0;
	}

	ifstream file(argv[1], ios::in | ios::binary);
			if (!file){
				cout << "File can not open";
				return 1;
			}

	file.read((char*) buffer, BUF_SIZE);
	
	file.close();

	for(int i = 0; i < file.gcount(); i++){
		cout << buffer[i];
	}

	return 0;
}