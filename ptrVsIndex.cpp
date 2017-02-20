#include <iostream>
#include <cstdio>

using namespace std;

int array[100];
int bubleSort(int array[100]);
int ptrBubbleSort(int array[100]);


int main(int argc, char const *argv[])
{
	
	int x;

	for (int i = 0, x = 100; x > 0; x--, i++){
		array[i] = x;
		cout << array[i] << ' ';
	}

	int bubleSort(int array[100]);

	for (int y=0; y < 100; y++) cout << array[y] << ' ';

	return 0;
}

int bubleSort(int array[100]){

	int forward, backward, element;
	int size = 100;

	//Bubblesort code

	for (forward = 1; forward < size; forward++ ){

		for (backward = size - 1; backward >= forward; backward--){

			if (array[backward - 1] > array[backward]){

				element = array[backward-1];
				array[backward - 1] = array[backward];
				array[backward] = element;
			}

		}

	}

	cout << "Sorted array " << endl;
	for (element = 0; element < size; element++) cout << array[element] << ' ';
	return 0;
}

int ptrBubbleSort(int array[100]){

	return 0;
}
