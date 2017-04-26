#include <iostream>

using namespace std;

template <class Type1, class Type2>
class Printer
{
	Type1 x;
	Type2 y;
public:
	Printer(Type1 a, Type2 b){
		x = a;
		y = b;
	}
	~Printer(){}
	
	void print();	
};

template <class Type1, class Type2>
void Printer<Type1, Type2> :: print()
{
	cout << " x = " << x << " y = " << y;
}

int main(int argc, char const *argv[])
{
	Printer<int, const char *> object(10, "Hello!");
	object.print();

	Printer<double, int> object2(10.5, 4);
	object2.print();

	return 0;
}