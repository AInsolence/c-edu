#include <iostream>

using namespace std;

class Base
{
	int x;
public:
	Base(int i){x = i;}
	~Base(){}
	void show_x(){cout << x << endl;}	
};

class Derived : public Base
{
	int y;
public:
	Derived(int i, int j) : Base(i) {y = j;}
	~Derived(){}
	void show_x(){cout << y << endl;}
};


int main(int argc, char const *argv[])
{
	Base object_b(5);
	Derived object_d(40, 70);
	
	Base * b_ptr;
	b_ptr = &object_b;
	b_ptr -> show_x();

	b_ptr = &object_d;
	b_ptr -> show_x(); // here will call Base variant of overloaded show_x(), cause Derived variant
					   // is not available with pointer to base class
	// b_ptr -> show_y(); here will be error "'class Base' has no member named 'show_y'"

	Derived * d_ptr;
	// d_ptr = &object_b; here will be the error " invalid conversion from 'Base*' to 'Derived*'"
	d_ptr = &object_d;
	d_ptr -> show_x(); // // here will call Derived variant of overloaded show_x()

	return 0;
}