#include <iostream>

using namespace std;

class MyExp
{
public:
	explicit MyExp(int i){number = i;}
	~MyExp(){}
	int number;
};

class ConstMemberOwner
{
public:
	ConstMemberOwner(int i, int j) : NUMBER(i), OLD(j) {}
	~ConstMemberOwner(){}
	const int NUMBER;
	const int OLD;
	void show() {cout << NUMBER << " " << OLD << endl;}
};

void show_info(int a)
{
	cout << "This is a programm number " << a << endl;
	return;
}

int main(int argc, char const *argv[])
{
	void (*ptr)(int) = NULL;
	ptr = show_info;
	MyExp object(100);
	// object = 2000; Does not work with explicit constructor

	ConstMemberOwner obj (5, 3);
	obj.show();

	ptr(1);

	//Pointer to class member function
	typedef void (ConstMemberOwner::*memPtr)();

	memPtr ptr_CM = &ConstMemberOwner::show;

	(obj.*ptr_CM)();

	return 0;
}