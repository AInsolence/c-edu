#include <iostream>
#include <cstdlib>

using namespace std;

class sample
{
	int *i_ptr;
public:
	sample(int i);
	sample(const sample &object);
	~sample();
	int get_val(){return *i_ptr;};
};

sample :: sample(int i) // Constructor
{
	i_ptr = new int;
	*i_ptr = i;
	cout << "Allocation of memory for i in construstor!\n";
}

sample :: sample(const sample &object) // Copy constructor
{
	i_ptr = new int;
	*i_ptr = *object.i_ptr; // value of copy of object
	cout << "Allocation of memory for i in construstor of copy!\n";
}
sample :: ~sample() // Destructor
{
	delete i_ptr;
	cout << "Destruct object\n";
}

sample func() // Function returned object called copy constructor
{
	sample object(10); // Call constructor
	return object; // Call copy constructor
}

int main(int argc, char const *argv[])
{	
	// Create object
	sample my_object(2);

	// declare+init my_object_2 as copy of my_object
	sample my_object_2 = my_object; 
	
	func();

	return 0;
}


/*
	myclass а(2), b(3);

		// ...

		b = а; Here copy constructor not called, cause it is not initialization of b!
	*/