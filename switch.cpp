#include <iostream>
#include <cstdlib> // для system
using namespace std;

int tutorial();

int main()
{
	int start;
	start = 1;
	
	while (true){
		cout << "\n\n\n\nDo you want read tutorial 1/0\n";
		cin >> start;
		switch(start){
			case 1:
				tutorial();
				break;
			case 0:
				return 0;
				break;
		
		}
	}	

	return 0;
}

int tutorial(){

	int choise;

	cout << "\n\n\nTutorial info:\n";
	cout << "1. For loop\n";
	cout << "2. If\n";
	cout << "3. Switch\n";

	cout << "Please, choose topic (1-3)\n";
	cin >> choise;

	switch(choise){

		case 1:
			cout << "\nfor loop - is the most universal loop construction in C++.\n";
			break;
		case 2:
			cout << "\nif - is the conditional branch construction in C++.\n";
			break;
		case 3:
			cout << "\nswitch - is the multi-conditional branch construction in C++.\n";
			break;
		default:
			cout << "You must choose one of all available topics (1-3)\n";

	}
	return 0;
}
