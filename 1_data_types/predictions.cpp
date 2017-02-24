#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

const char *fortunes[] = {
	"You will be the best programmer!\n",
	"You'll take citizenship next year!\n",
	"You will take diploma next year!\n",
	"You will get a developer full time job next year!\n",
	"You will earn 100k next year!\n"
};

int main(int argc, char const *argv[]){

	int chance;
	cout << "Push the button to get fortune!";
	while (!kbhit()) rand();
	cout << '\n';
	chance = rand();
	chance = chance % 5;

	cout << fortunes[chance];

	
	return 0;
}

