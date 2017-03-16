#include <iostream>

using namespace std;

void dynamicArray();

int main(int argc, char const *argv[])
{
	int *ptr_1 = NULL; // Init with 0 to avoid errrors
	int *ptr_2 = NULL; // Init with 0 to avoid errrors

	cout << ptr_1 << " " << ptr_2;
	cout << '\n';

	ptr_1 = new int;      // Create without initialization
	ptr_2 = new int(100); // Create + init with value 100

	*ptr_1 = 50; // Init with 50

	cout << ptr_1 << " " << ptr_2;
	cout << '\n';
	cout << *ptr_1 << " " << *ptr_2;
	cout << '\n';

	delete ptr_1;
	delete ptr_2;

	cout << ptr_1 << " " << ptr_2;
	cout << '\n';
	cout << *ptr_1 << " " << *ptr_2;
	cout << '\n';

	dynamicArray();

	return 0;
}

void dynamicArray()
{
	double *ptr_array = NULL;
	int i, x;

	ptr_array = new double[10]; //Create dynamic array

	for (i = 0, x = 100; i < 10; i++, x += 100){
		ptr_array[i] = x;
		cout << ptr_array[i] << ' ';
	}

	delete [] ptr_array; // Delete dynamic array
}