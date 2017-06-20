#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int comp(const void * a, const void * b);

int main(int argc, char const *argv[])
{
	char str[] = "Hello my friends!";
	cout << "Origin string: " << str << endl;
	qsort(str, strlen(str), 1, comp);

	cout << "Sorted string: " << str << endl;

	return 0;
}

int comp(const void * a, const void * b)
{
	return * (char*) a - * (char*) b;
}