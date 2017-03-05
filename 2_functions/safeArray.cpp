#include <iostream>

using namespace std;

int &put(int i);
int &get(int i);
int error = -1;
int array[10];

int main(int argc, char const *argv[])
{
	put (0) = 100;
	put (3) = 400;
	put (5) = 600;
	cout << get(0) << endl;
	cout << get(3) << endl;
	cout << get(5) << endl;
	for (int i = 0; i < 10; i++){
		cout << i<< " == " << put(i) << ' ';
	}
	cout << endl;
	cout << put(1) << ' ';
	cout << endl;
	put(12);
	return 0;
}

int &put(int i){
	if (i >= 0 && i < 10){
		return array[i];
	}
	else {
		cout << "Error: you have gone beyond the array!";
		return error;
	}
}
int &get(int i){
	if (i >= 0 && i < 10){
		return array[i];
	}
	else {
		cout << "Error: you have gone beyond the array!";
		return error;
	}
}