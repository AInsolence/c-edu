#include <iostream>

using namespace std;

class Base
{
public:
	Base(){return;}
	~Base(){return;}
	virtual void who(){cout << "This is the Base variant\n";} // if we delete 'virtual' in the access 
															  // through the pointer we always call base variant
};

class First_level : public Base
{
public:
	First_level(){return;}
	~First_level(){return;}
	void who(){cout << "This is the First_level variant\n";}
};

class Second_level : public First_level
{
public:
	Second_level(){return;}
	~Second_level(){return;}
	void who(){cout << "This is the Second_level variant\n";}
};

int main(int argc, char const *argv[])
{
	Base base_object;
	First_level first_object;
	Second_level second_object;

	base_object.who(); //Common call
	first_object.who(); //Common call
	second_object.who(); //Common call

	Base *base_ptr;
	base_ptr = &base_object;
	base_ptr -> who(); //Polimorphic variant here

	base_ptr = &first_object;
	base_ptr -> who(); //Polimorphic variant here

	base_ptr = &second_object;
	base_ptr -> who(); //Polimorphic variant here

	return 0;
}