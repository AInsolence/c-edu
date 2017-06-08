#include <iostream>
#include <typeinfo>

using namespace std;

class Myclass
{
public:
	Myclass(){};
	~Myclass(){};
};

class Base
{
public:
	//virtual void f(){};
	Base(){};
	~Base(){};
	
};

class Derived1 : public Base
{
public:
	Derived1(){};
	~Derived1(){};
	
};

class Derived2 : public Base
{
public:
	Derived2(){};
	~Derived2(){};
	
};

int main(int argc, char const *argv[])
{
	int * p;
	int i, j;
	float f;
	Myclass object;
	Myclass object1;

	p = &i;

	cout << "i variable type is: " << typeid(*p).name() << endl;

	p = &j;
	cout << "j variable type is: " << typeid(*p).name() << endl;
	cout << "f variable type is: " << typeid(f).name() << endl;
	cout << "object variable type is: " << typeid(object).name() << endl;
	cout << "object1 variable type is: " << typeid(object1).name() << endl;

	if (typeid(i) == typeid(j)) cout << "Types of i and j are the same.\n";
	if (typeid(i) != typeid(f)) cout << "Types of i and f are different.\n";

	//////////////////////////////////////////////////////////////////////

	Base * ptr;

	Base base;
	Derived1 derived1;
	Derived2 derived2;

	ptr = &base;
	cout << "pointer ptr point to an object type: " << typeid(*ptr).name() << endl;

	ptr = &derived1;
	cout << "pointer ptr point to an object type: " << typeid(*ptr).name() << endl;

	ptr = &derived2;
	cout << "pointer ptr point to an object type: " << typeid(*ptr).name() << endl;

	cout << "Type of int is: " << typeid(int).name() << endl;

	return 0;
}