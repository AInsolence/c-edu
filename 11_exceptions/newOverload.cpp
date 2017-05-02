#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

class newOverload
{
	int x, y, z;
public:
	newOverload();
	newOverload(int i, int j, int k);
	~newOverload(){cout << "Destructor.\n";}
	
	void * operator new(size_t size);
	void * operator new[](size_t size);
	void operator delete(void *ptr);
	void operator delete[](void *ptr);

	void show();
};

newOverload	:: newOverload()
{
	x = y = z = 0;
	cout << "Default construstor.\n";
}

newOverload :: newOverload(int i, int j, int k)
{
	x = i;
	y = j;
	z = k;
	cout << "Parametrized constructor.\n";
}

void * newOverload :: operator new(size_t size)
{
	void * ptr;
	cout << "Memory allocation for one object\n";
	ptr = malloc(size);
	if (!ptr){
		bad_alloc ba;
		throw ba;
	}
	return ptr;
}

void * newOverload :: operator new[](size_t size)
{
	void * ptr;
	cout << "Memory allocation for an array of objects\n";
	ptr = malloc(size);
	if (!ptr){
		bad_alloc ba;
		throw ba;
	}
	return ptr;
}

void newOverload :: operator delete(void *ptr)
{
	cout << "Free memory for var\n";
	free(ptr);
}

void newOverload :: operator delete[](void *ptr)
{
	cout << "Free memory for array\n";
	free(ptr);
}

void newOverload :: show()
{
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}

int main(int argc, char const *argv[])
{
	newOverload *ptr_array, *ptr_object;
	try{
		ptr_array = new newOverload[3];
		ptr_object = new newOverload(5, 6, 7);
	}

	catch(bad_alloc ba){
		cout << "Memory allocation error\n";
		return 1;
	}

	ptr_array[0].show();
	ptr_object -> show();

	delete [] ptr_array;
	delete ptr_object;

	return 0;
}