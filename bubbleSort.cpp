#include <iostream>

#include <cstdlib>

using namespace std;



int main(int argc, char const *argv[])
{
	int sample[10];

	int forward, backward, element;

	int size = 10; //Array size

	//Create and output random array
	for (element = 0; element < size; element++) {
		sample[element] = rand();
		cout << sample[element] << '\n';
	}

	//Bubblesort code

	for (forward = 1; forward < size; forward++ ){

		for (backward = size - 1; backward >= forward; backward--){

			if (sample[backward - 1] > sample[backward]){

				element = sample[backward-1];
				sample[backward - 1] = sample[backward];
				sample[backward] = element;
			}

		}

	}

	cout << "Sorted array " << endl;
	for (element = 0; element < size; element++) cout << sample[element] << ' ';

	return 0;
}