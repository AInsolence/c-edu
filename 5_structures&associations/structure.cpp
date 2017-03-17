#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char menu();
void init();
void enter();
void input(int i);
void modify();
void display();

const int SIZE = 100;

struct storage{
		char item [40];
		double cost;
		double retail;
		int on_hand;
		int lead_time;
	} storage_arr[SIZE];

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

void init()
{
	int i;
	for (i = 0; i < SIZE; i++) *storage_arr[i].item = '\0'; // *array - create ptr for first element
}

char menu(){

	char choise;

	do {
		cout << "(E)nter item" << '\n';
		cout << "(M)odify item" << '\n';
		cout << "(D)isplay item" << '\n';
		cout << "(Q)uit" << '\n';
		 cin >> choise;
		}while(!strchr("emdq", tolower(choise))); // Check user input

	return tolower(choise);
}

void enter()
{
	register int i;

	for (i = 0; i < SIZE; i ++){
		if (!storage_arr[i].item) break;
	}

	if (i == SIZE) {
		cout << "Storage is full!\n";
		return;
	}

	input(i);

}

void input (int i)
{
	cout << "Enter item name: \n";
	 cin >> storage_arr[i].item;
	cout << "Enter item cost: \n";
	 cin >> storage_arr[i].cost;
	cout << "Enter item retail: \n";
	 cin >> storage_arr[i].retail;
	cout << "Enter item available on hand: \n";
	 cin >> storage_arr[i].on_hand;
	cout << "Enter lead time: \n";
	 cin >> storage_arr[i].lead_time;

}

void modify()
{
	cout << "Enter the name of the item which you want to modify: \n";
	char name[40];
	 cin >> name;
	register int i;
	for (i = 0; i < SIZE; i++) if (strcmp(name, storage_arr[i].item)) input (i);
	cout << "Item is not found, please try again.\n";
	return;
}