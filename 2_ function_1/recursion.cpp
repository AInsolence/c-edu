#include <iostream>

using namespace std;

long double recursion(long double number);
long double number;

int main(int argc, char const *argv[])
{	
	long double result;
	cout << "Enter the number please\n";
	 cin >> number;
	result = recursion(number);
	cout << "Result:\n" << result;
	return 0;
}

long double recursion(long double number){
	if (number > 0){
		return (number*recursion(number - 1));
	}
	return 1;
}
