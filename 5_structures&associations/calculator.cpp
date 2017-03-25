#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <cctype>

using namespace std;

struct input{
	long double numbers[10];
	char sign;
} user_input;

char menu();
void user_str_to_user_input(char *user_str);
void calculator();
int help();

// Calculator action functions
void summ(input *user_input);
void subtraction(input *user_input);
void division(input *user_input);
void multiplication(input *user_input);
void remainder(input *user_input);
void int_division(input *user_input);
//-----------------------------------

int main(int argc, char const *argv[])
{
	char choise;
	for (;;){

		choise = menu();

		switch (choise){
			case 's':
				calculator();
				break;
			case 'h':
				help();
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
		cout << "(H)elp\n";
		cout << "(Q)uit" << '\n';
		 cin >> choise;
		}while(!strchr("shq", tolower(choise))); // Check user input

	return tolower(choise);
}

int help()
{
	cout << "\nEnter your expression as:\n2+2 and press 'enter'\n\n";
	cout << "Calculator commands:\n\n'+' -> summ\n'-' -> substraction\n\
'/' -> division\n'*' -> multiplication\n'^' -> \
integer division(for integer only)\n'?' -> \
remainder of division(for integer only)\n";
	return 0;
}

void calculator()
{
	char sign;
	char user_str[100];
	char * ptr_to_user_str;
	input * ptr_to_user_input;
	ptr_to_user_input = &user_input;
	ptr_to_user_str = user_str;
	cout << "Enter your expression or enter 'q' to exit\n";
	do{
		 gets(user_str);
		
		user_str_to_user_input(ptr_to_user_str);
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
			case '?':
				remainder(ptr_to_user_input);
				break;
			case '^':
				int_division(ptr_to_user_input);
				break;
			default :
				break;
		}
		user_input.sign = '\0';
		

	} while(strcmp(user_str,"q"));
}

void user_str_to_user_input(char *user_str)
{
	char *ptrtemp;
	char token[100];
	int count_nums = 0;

	while (*user_str){
		ptrtemp = token;
		while (isdigit(*user_str) || *user_str == '.'){
			*ptrtemp = *user_str;
			user_str++;
			ptrtemp++;
		}
		if (strchr("+-/*?^", *user_str) && !user_input.sign) user_input.sign = *user_str;
		if (*user_str) user_str++;
		*ptrtemp = '\0';
		user_input.numbers[count_nums] = atof(token);
		count_nums++;
	}
	for (int i = 0; i <= count_nums; i++){
		cout << user_input.numbers[i] << " ";
	}

	for (int i = 0; i <= count_nums; i++){
		cout << user_input.sign << " \n";
	}


}

void summ(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "+" << user_input -> numbers[1]\
	 << "=" << user_input -> numbers[0] + user_input -> numbers[1] << '\n';
}

void subtraction(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "-" << user_input -> numbers[1]\
	 << "=" << user_input -> numbers[0] - user_input -> numbers[1] << '\n';
}

void division(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "/" << user_input -> numbers[1]\
	 << "=" << user_input -> numbers[0] / user_input -> numbers[1] << '\n';
}

void multiplication(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "*" << user_input -> numbers[1]\
	 << "=" << user_input -> numbers[0] * user_input -> numbers[1] << '\n';
}

void remainder(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "?" << user_input -> numbers[1]\
	 << "=" << (int)user_input -> numbers[0] % (int)user_input -> numbers[1] << '\n';
}

void int_division(input *user_input)
{
	system("cls");
	cout << user_input -> numbers[0] << "^" << user_input -> numbers[1]\
	 << "=" << (int)user_input -> numbers[0] / (int)user_input -> numbers[1] << '\n';
}