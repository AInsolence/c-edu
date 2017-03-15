#include <iostream>

using namespace std;

int div_zero();
int div(float a, float b);

int main(int argc, char const *argv[])
{
	float x, y, result;
	cout << "Enter two numbers to division\n";
	 cin >> x;
	 cin >> y;
	result = y ? div(x,y) : div_zero(); // Here you can see how work ternary operator '?:'
	return 0;
}

int div_zero()
{
	cout << "You cannot divide by zero!\n";
	return 0;
}

int div(float a, float b)
{
	cout << "Result is: " << a/b;
}