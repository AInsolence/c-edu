#include <iostream>

using namespace std;

template <typename T>
void repeat_func(T data, int times)
{
	for (int i = 0; i < times; i++){
		cout << data << endl;
	}
}

int main(int argc, char const *argv[])
{
	char temp[80] = "Hello world!";
	int num = 29;
	float fnum = 2.2;

	repeat_func(temp, 2);
	repeat_func(num, 4);
	repeat_func(fnum, 5);

	return 0;
}