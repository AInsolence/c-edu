#include <iostream>
#include <cstdlib> // для system
#include <conio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int y, limit;

	limit = 15;

	cout << "Give me the number: ";

	cin >> y;

	for( ; y<limit; y++) cout << ' ';

	for (int x = 0; x != 123;){
		cout << "Try once more" << endl;
		cin >> x;
	}

	cout << "well done!";

	for(int e=0L; e<1000000000; e++);

	return 0;
}

