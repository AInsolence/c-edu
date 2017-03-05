#include <iostream>

using namespace std;

void swap(int &var1, int &var2);

int main(int argc, char const *argv[])
{
	int x = 10;
	int y = 20;
	cout << "X = " << x << " " << "Y = " << y << endl;
	swap(x,y);
	cout << "After swap func: \n" << "X = " << x << " " << "Y = " << y << endl;
	return 0;
}

void swap(int &var1, int &var2){
	int temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}