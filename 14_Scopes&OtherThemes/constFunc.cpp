#include <iostream>

using namespace std;

class ConstFunc
{
	mutable int old;
	int number;
public:
	ConstFunc(int num){number = num;}
	~ConstFunc(){}

	int get_old() const 
	{
		return old;
	} 	
	int get_number() const
	{
		return number;
	}
	void set_old(int x) const 
	{
		old = x;
	} 	
	void set_number(int x) //Adding 'const' modifier led to compiler error
						  // cause number has NOT 'mutable' modifier
	{
		number = x;
	}
	
};

int main(int argc, char const *argv[])
{
	ConstFunc object(100);

	object.set_old(28);
	object.set_number(10);

	cout << object.get_old() << endl;
	cout << object.get_number() << endl;
	return 0;
}