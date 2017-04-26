#include <iostream>

using namespace std;

const int SIZE = 10;

template <class Element>
class Safe_array
{
	Element arr[SIZE];
public:
	Safe_array(){
		for (int j = 0; j < SIZE; j++){
		arr[j] = 0;
		}
	}
	~Safe_array(){}
	Element & operator [](int i);
};

template <class Element>
Element & Safe_array<Element> :: operator [] (int i)
{
	if (i < 0 || i > SIZE - 1){
		cout << "Index out of range" << endl;
	}
	return arr[i];
} 

int main(int argc, char const *argv[])
{
	Safe_array<int> i_array;
	for (int j = 0; j < SIZE; j++){
		i_array[j] = j;
		cout << i_array[j] << ' ';
	}

	Safe_array<double> d_array;
	d_array[0] = 10.4;
	d_array[1] = 14.7;
	d_array[2] = 22.2;

	for (int j = 0; j < SIZE; j++){
		cout << d_array[j] << ' ';
	}

	Safe_array<const char *> ch_array;
	ch_array[0] = "Hello";
	ch_array[1] = "World";
	ch_array[2] = "from";
	ch_array[3] = "incredible";
	ch_array[4] = "C++";


	for (int j = 0; j < SIZE; j++){
		cout << ch_array[j] << ' ';
	}

	return 0;
}