#include <iostream>

using namespace std;

struct sample{

	int a;
	char ch;

};

void display(sample param);

int main(int argc, char const *argv[])
{
	sample arg;
	arg.a = 1000;
	arg.ch = 'x';
	cout << "Display arg structure:\n";
	display(arg);

	sample new_arg;
	new_arg.a = 200;
	new_arg.ch = 'a';
	cout << "Display new_arg structure:\n";
	display(new_arg);
	new_arg = arg;
	cout << "Display new_arg after expression 'new_arg = arg':\n";
	display(new_arg);

	return 0;
}

void display(sample param)
{
	cout << param.a << '\n';
	cout << param.ch << '\n';
}