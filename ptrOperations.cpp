#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int *i, j[10];
	double *f, g[10];
	int x;

	i = j;
	f = g;

	for (x = 0; x < 10; x++){
		cout << i + x << ' ' << f + x << endl;
	}

	return 0;
}