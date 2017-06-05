#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <limits>
#include <iomanip>

using namespace std;
const int BUF_SIZE = 1024;

void readFile(fstream &file, char buffer[BUF_SIZE]);
void writeFile(fstream &file);

void readFile(fstream &file, char buffer[BUF_SIZE])
	{
		int position;
		int status, is_eof, is_fail, is_bad, is_good;

		file.seekg(0, ios::end);
		const size_t f_end = file.tellg();

		cout << "Files size is " << f_end << " bit.\n";

		cout << "Please enter position to read from file some info" << endl;
		 cin >> position;
		file.seekg(position, ios::beg);
		file.read(&buffer[0], f_end);
		
		for (int i = 0; i < f_end; i++){
			cout << buffer[i];
		}
		

		status = file.rdstate();
		is_eof = file.eof();
		is_fail = file.fail();
		is_bad = file.bad();
		is_good = file.good();

		cout << "\nStatus is: " << status << endl;
		cout << "EOF flag is " << is_eof << endl;
		cout << "fail flag is " << is_fail << endl;
		cout << "bad flag is " << is_bad << endl;
		cout << "good flag is " << is_good << endl;

		file.clear(); //cleares EOF bit
	}

void writeFile(fstream &file)
{
	string temp;
	int position, gptr_place, pptr_place;
	int status, is_eof, is_fail, is_bad, is_good;

	file.width(10);
	file.fill('#');
	file.setf(ios::scientific | ios::showpos);

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

	status = file.rdstate();
	is_eof = file.eof();
	is_fail = file.fail();
	is_bad = file.bad();
	is_good = file.good();

	cout << "\nStatus is: " << status << endl;
	cout << "EOF flag is " << is_eof << endl;
	cout << "fail flag is " << is_fail << endl;
	cout << "bad flag is " << is_bad << endl;
	cout << "good flag is " << is_good << endl;


	file << right << "!!!tag!!!";
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