#include <iostream>

using namespace std;

class my_object
{
	int x, y, z;
	int error;
public:
	int & operator [](int index); // Returning reference here allows us to use [] in left side of expression
	my_object(int i, int j, int k);
	~my_object();
};

my_object :: my_object(int i, int j, int k)
{
	x = i;
	y = j;
	z = k;
	error = -1;
}

my_object :: ~my_object()
{
	return;
}

int & my_object :: operator [](int index)
{
	switch (index) {
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			cout << "Index out of range! Error code: ";
			return error;
	}
}

int main(int argc, char const *argv[])
{
	my_object object(10, 20, 30);
	cout << object[0] << endl;
	cout << object[1] << endl;
	cout << object[2] << endl;
	cout << object[3] << endl;
	object[0] = 33;
	cout << object[0] << endl;

	return 0;
}