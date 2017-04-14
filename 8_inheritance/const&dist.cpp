#include <iostream>

using namespace std;

class Base_class
{
public:
	Base_class(){cout << "Base class constructor\n";};
	~Base_class(){cout << "Base class constructor\n";};
};

class Derived_class : public Base_class
{
public:
	Derived_class(){cout << "Derived class constructor\n";};
	~Derived_class(){cout << "Derived class constructor\n";};
	
};

int main(int argc, char const *argv[])
{
	Derived_class object;
	return 0;
}