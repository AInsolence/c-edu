#include <iostream>
#include <ctime>

using namespace std;

unsigned int i;
unsigned int delay;

int main(int argc, char const *argv[])
{
	register unsigned int j;
	long start, end;

	start = clock();

	for (delay = 0; delay < 50; delay ++){
		for (i = 0; i < 64000000; i++);
	}
	
	start = clock() - start;
	cout << "Time with not register variable loop == " << start << endl;
	
	start = clock();
	
	for (delay = 0; delay < 50; delay ++){
		for (j = 0; j < 64000000; j++);
	}
	
	end = clock();
	cout << "Time with register variable loop == " << end - start << endl;

	return 0;
}