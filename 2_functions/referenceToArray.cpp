#include <iostream>

using namespace std;
int &ref(int i);
int array[5] = {23,45,66,78,23};
int main(int argc, char const *argv[])
{
	
	for (int i = 0; i < 5; i++){
		cout << array[i] << ' ';
	}
	cout << endl;

	ref(1) = 577;

	for (int i = 0; i < 5; i++){
		cout << array[i] << ' ';
	}
	
	return 0;
}

int &ref(int i){
	return array[i];
}