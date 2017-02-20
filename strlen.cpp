#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	char input[200];
	cout << "Please enter the string\n";
	gets(input);
	cout << strlen(input) << endl;

	for (int i = strlen(input) -1; i >= 0; i--){
		cout << input[i];
	}
	
	return 0;
}