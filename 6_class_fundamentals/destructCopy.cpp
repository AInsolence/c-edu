#include <iostream>

using namespace std;

class sample
{
	int value;
public:

	int show_value(){ return value; };
	
	sample(int i)
	{ 
		value = i; 
		cout << "Constructor is called\n";
	}
	~sample()
	{ 
		cout << "Destructor is called\n";
		return; 
	};
};

void display_by_value(sample object)
{
	cout << object.show_value() << endl;
	return;
}

void display_by_ref(sample &object)
{
	cout << object.show_value() << endl;
	return;
}

int main(int argc, char const *argv[])
{
	sample ob1(10);
	cout << "Call func with call by reference: \n";
	display_by_ref(ob1);
	cout << "Call func with call by value: \n";
	display_by_value(ob1); // Called destructor of copy(could be potential problems!!)
	cout << "End of main\n";
	return 0;
}