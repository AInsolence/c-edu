#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <limits>

using namespace std;
const int BUF_SIZE = 1024;

void readFile(fstream &file, char buffer[BUF_SIZE]);
void writeFile(fstream &file);

void readFile(fstream &file, char buffer[BUF_SIZE])
	{
		int position;
		cout << "Please enter position to read from file some info" << endl;
		 cin >> position;
		file.seekg(position, ios::beg);
		file.read(&buffer[0], BUF_SIZE);

		for(int i = 0; i < file.gcount(); i++){
		cout << buffer[i];
		}
		file.clear(); //cleares EOF bit
	}

void writeFile(fstream &file)
{
	string temp;
	int position, gptr_place, pptr_place;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nPlease enter some info to add to the file" << endl;
	 getline(cin, temp);
	cout << "Enter a position in the file:\n" << endl;
	 cin >> position;
	file.seekp(position, ios::beg);

	gptr_place = file.tellg();// Show the same place??
	pptr_place = file.tellp();

	const size_t STR_SIZE = temp.size();
	
	cout << gptr_place << " " << pptr_place << endl;
	file.write(temp.c_str(), STR_SIZE);
	cout << temp;

	cout << gptr_place << " " << pptr_place << endl;
	file.clear(); //cleares EOF bit
	cout << gptr_place << " " << pptr_place << endl;
}


int main(int argc, char const *argv[])
{
	char buffer[BUF_SIZE];

	if (argc != 2){
		cout << "Program usage: prog_name file_name";
		return 0;
	}

	fstream file(argv[1], ios::in | ios::out | ios::binary | ios::ate);
	if (!file){
		cout << "File can not open or doesn't exist";
		return 1;
	}

	//Try to read & write some info from/to file in particular position
	
	readFile(file, buffer);
	writeFile(file);
	
	//Find output & input pointers position
	//peek () function
	//putback () function
	//flush () function
	file.close();

	return 0;
}