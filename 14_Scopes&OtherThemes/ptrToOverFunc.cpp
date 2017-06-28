#include <iostream>

using namespace std;

void space(int i);
void space(int i, char ch);

int main(int argc, char const *argv[])
{
	void (*ptr_space1)(int) = NULL;
	void (*ptr_space2)(int, char) = NULL;

	ptr_space1 = space;// pointer for first specialization
	ptr_space2 = space;// pointer for second specialization

	ptr_space1(5);
	ptr_space2(5, '@');

	return 0;
}

void space(int i)
{
	for ( ; i; i--){
		cout << "_";
	}
	cout << endl;
}
void space(int i, char ch)
{
	for ( ; i; i--){
		cout << ch;
	}
	cout << endl;
}