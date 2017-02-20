#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int menu();
void enter(), report(), show();

char names[3][80];
char phones[3][20];
int worktime[3];
int wage[3];

int main(int argc, char const *argv[])
{
	int choice;
	do{
		choice = menu();
	} while (choice);

	return 0;
}

int menu(){
	int choice;

	cout << "Please enter your choice: " << endl;
	cout << "0. Exit" << endl;
	cout << "1. Enter information in db " << endl;
	cout << "2. Show Data Base " << endl;
	 cin >> choice;
	switch (choice){
		case 0:
			break;
		case 1:
			enter();
			break;
		case 2:
			report();
			break;
		default:
			cout << "Please try once more" << endl;

	}
		

	return choice;
}					

void enter(){
	cout << "Enter data: " << endl;

	for (int i = 0; i < 3; i++){
		cout << "Name: " << " \n";
		 cin >> names[i];
		cout << "Phone: " << " \n";
		 cin >> phones[i];
		cout << "Work time: " << " \n";
		 cin >> worktime[i];
		cout << "Wage: " << " \n";
		 cin >> wage[i];
	}
}

void report(){
	int i;
	for(i = 0; i < 3; i++){
		cout << "\n";
		cout << names[i] << "\n\n";
		cout << phones[i] << "\n\n";
		cout << worktime[i] << "\n\n";
		cout << wage[i] << "\n\n";
		cout << "Slary per week: " << worktime[i]*wage[i] << "\n\n";

	}
}