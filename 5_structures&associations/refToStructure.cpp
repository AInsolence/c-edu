#include <iostream>

using namespace std;

struct my_struct {
	int a, b;
};

my_struct &func(my_struct &var);

int main(int argc, char const *argv[])
{
	my_struct x, y;
	x.a = 10;
	x.b = 20;
	cout << x.a << " " << x.b << endl;
	
	y = func(x);
	cout << x.a << " " << x.b << endl;
	cout << y.a << " " << y.b << endl;

	return 0;
}

my_struct &func(my_struct &var)
{
	var.a = var.a * var.a;
	var.b = var.b / var.b;
	return var;
}