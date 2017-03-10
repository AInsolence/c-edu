#include <iostream>

using namespace std;

void code(const char *str);

int main(int argc, char const *argv[])
{
	char str[80] = "This is test";
	code(str);
	cout << str;
	return 0;
}

void code(const char *str){

	while (*str){
		cout << (char) (*str + 1);
		str ++;
	}
}
