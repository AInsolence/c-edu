#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void vprint(const T ob)
{
	cout << ob << " ";
}

template<class T>
bool comparison(const T ob, const T ob_2)
{
	if (ob < ob_2) return true;
	return false;
}

long int factorial(int input)
{
	return input == 0 ? 1 : input*factorial(input-1);
}

int main(int argc, char const *argv[])
{
	int SIZE;
	cout << "Please enter the size of an array: ";
	cout << endl;
	 cin >> SIZE;

	if (SIZE < 0) throw 113;
	
	int perm_nums;	
	try{
		perm_nums = factorial(SIZE);
	}
	catch(int a){
		cout << "Negative number passed on factorial function! Try again ...";
		cout << "Error code: " << a;
		exit(1);
	}

	std::vector<char> v;
	for (int i = 0; i < SIZE; i++){
		v.push_back('A'+i);
	}

	

	cout << "Container has " << perm_nums;
	cout << " numbers of permutations:" << endl;

	do{
		for_each(v.begin(), v.end(), vprint<char>);
		cout << endl;
	}while(next_permutation(v.begin(), v.end(),comparison<char>));

	return 0;
}