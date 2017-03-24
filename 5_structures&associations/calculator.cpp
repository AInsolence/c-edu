#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>

using namespace std;

struct input{
	long double a;
	long double b;
	char sign;
} user_input;

char menu();
void user_strTouser_input(char *user_str);
void calculator();

void summ(input *user_input);
void subtraction(input *user_input);
void division(input *user_input);
void multiplication(input *user_input);
void remainder(input *user_input);
void int_division(input *user_input);




int main(int argc, char const *argv[])
{
	char choise;
	user_input.sign = '\0';
	for (;;){

		choise = menu();

		switch (choise){
			case 's':
				calculator();
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
		}while(!strchr("sq", tolower(choise))); // Check user input

	return tolower(choise);
}

void calculator()
{
	char sign;
	char user_str[100];
	char * ptr_to_user_str;
	input * ptr_to_user_input;
	ptr_to_user_input = &user_input;
	ptr_to_user_str = user_str;

	do{
		
		cout << "Enter your expression or enter 'q' to exit" << endl;
		 gets(user_str);
		
		user_strTouser_input(ptr_to_user_str);
		sign = ptr_to_user_input -> sign;

		switch (sign){
			case '+':
				summ(ptr_to_user_input);
				break;
			case '-':
				subtraction(ptr_to_user_input);
				break;
			case '/':
				division(ptr_to_user_input);
				break;
			case '*':
				multiplication(ptr_to_user_input);
				break;
			case '%':
				remainder(ptr_to_user_input);
				break;
			case '^':
				int_division(ptr_to_user_input);
				break;
			default :
				cout << "\nSorry, this action does not supported.\n";
				break;
		}

	} while(strcmp(user_str,"q"));
}

void user_strTouser_input(char *user_str)
{
	char *ptr1;
	*ptr1 = *user_str;
	cout << ptr1;
}

void summ(input *user_input)
{
	cout << "Func" << endl;
}
void subtraction(input *user_input)
{
	cout << "Func" << endl;
}
void division(input *user_input)
{
	cout << "Func" << endl;
}
void multiplication(input *user_input)
{
	cout << "Func" << endl;
}
void remainder(input *user_input)
{
	cout << "Func" << endl;
}
void int_division(input *user_input)
{
	cout << "Func" << endl;
}