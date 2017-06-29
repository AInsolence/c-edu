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
};