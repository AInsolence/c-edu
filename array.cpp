#include <iostream>
#include <cstdlib> // для system
using namespace std;

int main(int argc, char const *argv[])
{
	int sample[10];
	int e;

	for (e = 0; e <= 10; ++e) {
		sample[e] = e;
		cout << sample[e] << ' ';
	}

	return 0;
}