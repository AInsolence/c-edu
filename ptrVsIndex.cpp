#include <iostream>
#include <cstdio>

using namespace std;

int array[1000], array_2[1000];
void bubleSort(int param[], int size);
void ptrBubbleSort(int *ptrParam, int size);

int main(int argc, char const *argv[]){

	int x, i, size;

	cout << "Please enter size of arrays from 0 to 1000: "<< endl;
	 cin >> size;

	cout << "Array for Bubble sort " << endl;
	for (i = 0, x = size; x > 0; x--, i++){
		array[i] = x;
		cout << array[i] << ' ';
	}
	cout << endl;

	cout << "Array for Pointer Bubble sort " << endl;
	for (i = 0, x = size; x > 0; x--, i++){
		array_2[i] = x;
		cout << array_2[i] << ' ';
	}
	cout << endl;

	int *ptrarray_2 = &array_2[0];
	ptrBubbleSort(ptrarray_2, size);

	cout << "Array sorted by POINTERS " << endl;
	for (int element = 0; element < size; element++) cout << array_2[element] << ' ';
	cout << endl;

	bubleSort(array, size);

	return 0;
}

void bubleSort(int param[], int size){

	int forward, backward, element;

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

	cout << "Array sorted by index " << endl;
	for (element = 0; element < size; element++) cout << array[element] << ' ';
	cout << endl;
}

void ptrBubbleSort(int *ptrParam, int size){

	int *end, element;
	end = (ptrParam + size) - 1;
	cout << "PTR  " << ptrParam << endl << "PTR*  " << *ptrParam << endl;
	cout << "Last PTR " << end << endl;
	cout << "Last number " << *(end - 1) << endl;

	for (ptrParam; ptrParam < end; ptrParam++ ){

		for (int *backward = end; backward >= ptrParam; backward--){

			if (*(backward - 1) > *backward){

				element = *(backward-1);
				*(backward - 1) = *backward;
				*backward = element;
			}
		}
	}

}
