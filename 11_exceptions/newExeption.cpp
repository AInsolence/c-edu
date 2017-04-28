#include <iostream>
#include <new>

using namespace std;

int main(int argc, char const *argv[])
{
	int *p, i;
	try{
		p = new int[32];
	}

	catch (bad_alloc xa){
		cout << "Memory is not allocated!\n";
		return 1;
	}

	for (i = 0; i < 32; i++) p[i] = i;
	for (i = 0; i < 32; i++) cout << p[i] << ' ';

	delete [] p;

	return 0;
}