#include <iostream>

using namespace std;

template <typename T> 
void swaparg(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<>
void swaparg<int>(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "This is an explicitly specialization of swaparg func for int parameters!" << endl;
}

int main(int argc, char const *argv[])
{
	int x, y;
	double i, j;
	char ch1, ch2;
	x = 10;
	y = 20;
	i = 55.5;
	j = 1.3;
	ch1 = 'a';
	ch2 = 'z';

	cout << "x = " << x << " y = " << y << endl;
	cout << "i = " << i << " j = " << j << endl;
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;

	cout << "Swaping... " << endl;
	swaparg(x, y);
	swaparg(i, j);
	swaparg(ch1, ch2);

	cout << "Result: " << endl;

	cout << "x = " << x << " y = " << y << endl;
	cout << "i = " << i << " j = " << j << endl;
	cout << "ch1 = " << ch1 << " ch2 = " << ch2 << endl;

	return 0;
}