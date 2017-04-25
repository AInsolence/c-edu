#include <iostream>

using namespace std;

template <typename Number>
Number myabs(Number x)
{
	return x < 0 ? -x : x;
}

int main(int argc, char const *argv[])
{
	int a = -10;
	float b = 9;
	double c = -15;
	char d = 'd';
	cout << myabs(a) << ' ' << myabs(b) << ' ' << myabs(c) << ' ' << myabs(d);
	return 0;
}