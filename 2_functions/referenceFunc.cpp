#include <iostream>

using namespace std;
int &f();
int val = 100;

int main(int argc, char const *argv[])
{
	int newval = 200;
	cout << f() << endl;
	f() = newval;

	cout << f() << endl;
	return 0;
}

int &f(){
	return val;
}