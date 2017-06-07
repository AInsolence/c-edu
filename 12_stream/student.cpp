#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

class Student
{
public:
	string name;
	int old;
	Student(string s_name, int years);
	~Student(){};
	friend ostream & operator << (ostream &, Student object); //return ref to stream object
};

Student::Student(string s_name, int years)
{
	name = s_name;
	old = years;
}

ostream & operator << (ostream & stream, Student object)
{
	stream << "Name: " << object.name << endl;
	stream << "Years old: " << object.old << endl;
	return stream; 
}

int main(int argc, char const *argv[])
{
	if (argc != 3){
		cout << "Use: prog_name student_name student_years_old";
	}

	Student new_student(argv[1], atoi(argv[2]));

	ofstream file("student.txt", ios::out | ios::app);

	if (!file){
		cout << "File can not open or doesn't exist";
		return 1;
	}

	file << new_student;
	file.close();

	return 0;
}