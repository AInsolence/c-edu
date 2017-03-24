#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

long double a, b;

void start();
char listner();
long double calculate (long double a, long double b, char sign);
void reset();
char menu();


int main(int argc, char const *argv[])
{
	char choise;
	for (;;){

		choise = menu();

		switch (choise){
			case 's':
				start();
				break;
			case 'r':
				reset();
				break;
			case 'q':
				return 0;
		}
	}

	return 0;
}

char menu(){

	char choise;

	do {
		cout << '\n';
		cout << "(S)tart calculate" << '\n';
		cout << "(Q)uit" << '\n';
		 cin >> choise;
		}while(!strchr("emdq", tolower(choise))); // Check user input

	return tolower(choise);
}

void start()
{
	char action;
	for (;;){
		char action;
		action = listner();
		calculate (a, b, action);
	}
}

void listner()
{
	
}

void reset()
{
	
}

long double calculate (long double a, long double b, char sign)
{
	
}