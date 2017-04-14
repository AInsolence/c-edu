#include <iostream>

using namespace std;

class Base1
{
	int x;
public:
	Base1(int i){
		x = i;
		cout << "Base1 class parametrized constructor\n";
	}
	~Base1(){cout << "Base1 destructor\n";}
	void show_x(){ cout << "x = " << x << endl;}
};

class Base2
{
	int y;
public:
	int d;
	Base2(int i){
		y = i;
		cout << "Base2 class parametrized constructor\n";
	}
	~Base2(){cout << "Base2 destructor\n";}
	void show_y(){ cout << "y = " << y << endl;}
};

class Derived : public Base1, private Base2
{
	int j;
public:
	//Base2 :: y; //cannot increase access to private-born vars&funcs
	Base2 :: d; // increase access to public
	Base2 :: show_y; // NOTE: show_y func access increased without ()

	int demo;

	Derived(int x, int y, int z): Base1(x), Base2(y) //Syntax for parametrized derived class constructor
													// inherited from two base classes
	{ 
		demo = x+y+z; // We can use x&y not only like parameters for base classes, but in other ways too
		j = z;
		cout << "Derived class constructor\n";
	}
	~Derived(){
		cout << "Derived class destructor\n";
	}
	void show_z(){
		cout << "z = " << j << endl;
	}
	void show_demo(){
		cout << "demo = " << demo << endl;
	}

};

int main(int argc, char const *argv[])
{
	Derived object(22, 55, 99);
	object.show_x();
	object.show_y();
	object.show_z();
	object.show_demo();
	return 0;
}