#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int row, column, i, j;
	cout << "Now we create two dimensional array.\n Please enter two numbers (row and column)\n";
	 cin >> row;
	 cin >> column;

	int array[row][column];

	for (i = 0; i < row; ++i){
		for (j = 0; j < column; ++j){
			array[i][j] = (i*column) + j + 1;
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
 	cout << "Array adress:\n";
 	cout << array << endl;
 	cout << "Array size:\n";
 	cout << sizeof(array) << endl;

	return 0;
}		