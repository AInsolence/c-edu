#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char menu();
void init();
void enter();
void modify();
void display();

int main(int argc, char const *argv[])
{
	/* code */
	char choise;
	init();

	choise = menu();

	for (;;){
		char choise;
		choise = menu();

		switch (choise){
			case 'e':
				enter();
				break;
			case 'm':
				modify();
				break;
			case 'd':
				display;
			case 'q':
				return 0;
		}
	}
	return 0;
}

char menu(){

	char choise;

	do {
		cout << "(E)nter item" << '\n';
		cout << "(M)odify item" << '\n';
		cout << "(D)isplay item" << '\n';
		cout << "(Q)uit" << '\n';
		 cin >> choise;
		}while(!strchr('emdq', tolower(choise)))
	return tolower(choise);
}