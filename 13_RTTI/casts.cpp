#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

class Base
{
public:
	Base(){}
	~Base(){}
	virtual void  f(){cout << "In Base class\n";}	
};

class Derived : public Base
{
public:
	Derived(){}
	~Derived(){}
	void f(){cout << "In derived class\n";}
};

void del_const(const int * p)
	{
		int *v;
		v = const_cast<int*>(p);
		*v = 100;		
	}

int main(int argc, char const *argv[])
{
	// dynamic_cast example
	Base ob_base, *ptr_base;
	Derived ob_derived, *ptr_derived;

	ptr_derived = dynamic_cast<Derived*>(&ob_derived);
	if (ptr_derived){
		cout << "Cast from Derived to Derived\n";
		ptr_derived -> f();
	}
	else cout << "Fail cast from Derived to Derived\n";

	ptr_base = dynamic_cast<Derived*>(&ob_derived);
	if (ptr_base){
		cout << "Cast from Base to Derived point to Derived object\n";
		ptr_derived -> f();
	}
	else cout << "Fail cast from Base to Derived object is Derived\n";

	ptr_derived = &ob_derived;

	ptr_base = dynamic_cast<Base*>(ptr_derived);
	if (ptr_derived){
		cout << "Cast from Derived to Base\n";
		ptr_derived -> f();
	}
	else cout << "Fail cast from Derived to Base\n";


	ptr_base = dynamic_cast<Base*>(ptr_derived);
	if (ptr_derived){
		cout << "Cast from Derived to Base\n";
		ptr_derived -> f();
	}
	else cout << "Fail cast from Derived to Base\n";

	//const_cast


	//static_cast example

	char age = '3';
	float n_age;
	n_age =	static_cast<float>(age);
	/*

	float* n_age;                    // this variant work with reinterpret_cast
	n_age =	static_cast<float*>(age);// and does not work with static_cast

	*/
	cout << typeid(n_age).name() << endl;
	cout << typeid(age).name() << endl;

	cout << n_age << endl;


	// reinterpret_cast example
	int i;
	const char * PP = "Hello";
	i = reinterpret_cast<int>(PP); //Cast a pointer to type int

	cout << i;
	////////////////////////////
	return 0;
}