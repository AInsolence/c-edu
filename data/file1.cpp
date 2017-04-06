#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	for(;;){
		char symbol;
		symbol = getch();
		switch(symbol){
			case 'q':
				cout << "q";
				break;
			case 'w':
				cout << "w";
				break;
		}
	};

	return 0;
}