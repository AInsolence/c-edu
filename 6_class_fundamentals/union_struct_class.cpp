#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

union ans{
	short int i;
	char x [2];
	void show_variants();
} uanswer;

void ans :: show_variants()
{
	cout << "Choose two characters to answer: ";
	 cin >> x[0] >> x[1];
	cout << "\nYou have two variants of answer for candidate (yes/no): " << x[0] << " and " << x[1];
}

struct candidate
{
	int id;
	char name[80];
	char position[80];
	void create();
	void asses();
	void show_info();
	unsigned answer : 1;
	private:
		int mark;
};

void candidate :: create()
{
	cout << "Please enter info: \n";
	cout << "id: ";
	 cin >> id;
	cout << "Position: ";
	 cin >> position;
	cout << "Name: ";
	 cin >> name;
}

void candidate :: asses()
{
	unsigned i;
	cout << "Please give the mark (1-5) and answer (1/0):\n";
	 cin >> mark >> i;
	answer = i;
}

void candidate :: show_info()
{
	cout << "Info:\n" << "Candidate #" << id << endl;
	cout << "Name: " << name << endl;
	cout << "Position: " << position << endl;
	cout << "Mark: " << mark << endl;
	cout << "Answer: ";
	if (answer) cout << uanswer.x[0] << "\n";
	else cout << uanswer.x[1] << "\n";
}

class positions
{
	int annual_wage;
	int position_id;
	char creator[80];
public:
	char position_name[80];
	char company_name[80];
	void create();
	void show_info();
	void say_hello () 
	{ 
		cout << "HelloW!\n"; // Example of inline function
	}
	positions(int id);
	~positions();
	
};

positions :: positions(int id)
{
	strcpy(creator, "Anton");
	position_id = id;
}

positions :: ~positions()
{
	return;
}

void positions :: create()
{
	cout << "Please enter info: \n";
	cout << "Company: ";
	 cin >> company_name;
	cout << "Position: ";
	 cin >> position_name;
	cout << "Annual wage: ";
	 cin >> annual_wage;
}

void positions :: show_info()
{
	cout << "Position Info: \n";
	cout << "Position name: " << position_name << endl;
	cout << "Position id: " << position_id << endl;
	cout << "Company name: " << company_name << endl;
	cout << "Annual wage: " << annual_wage << endl;
	cout << "Creator: " << creator << endl;
}


int main(int argc, char const *argv[])
{	
	/* Work with union */

	uanswer.show_variants();

	/* Work with structures */
	const int ARRAY = 1;
	candidate array[ARRAY];
	for(int i = 0; i < ARRAY; i++){
		array[i].create();
		array[i].asses();
	}

	for (int i = 0; i < ARRAY; i++){
		array[i].show_info();
	}
	
	/* Wokr with class */

	positions head_of_department(001);
	head_of_department.create();
	head_of_department.show_info();
	head_of_department.say_hello();

	return 0;
}