#include <iostream>
#include <cstring>

using namespace std;

struct card
{
	char name [40];
	int old;
	bool marriage_status;
};

void display(card *param);

int main(int argc, char const *argv[])
{
	card my_card;

	char name[40] = "Anton";
	strcpy(my_card.name, name);
	my_card.old = 29;
	my_card.marriage_status = true;

	card *ptrcard;
	ptrcard = &my_card;

	display(ptrcard);

	return 0;
}

void display(card *param)
{
	cout << "name: " << param -> name << endl;
	cout << "old: " << param -> old << endl;
	cout << "marriage_status: " << param -> marriage_status << endl;
}