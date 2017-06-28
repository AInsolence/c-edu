#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass(){}
	~MyClass(){}
	
	static int num;
};

int MyClass::num;

int main(int argc, char const *argv[])
{
	MyClass A, B;
	cout << A.num << endl;
	cout << B.num << endl;
	A.num = 100;
	cout << A.num << endl;
	cout << B.num << endl;
	return 0;
}