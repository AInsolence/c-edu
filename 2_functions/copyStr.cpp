#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

char str[100];
char str2[100];
char *copystr(char *str, char *str2);

int main(int argc, char const *argv[])
{
	cout << "Enter main string" << endl;
	 gets(str);
	cout << "Now " << endl;
	cout << "STR: " << str << endl;
	cout << "STR2: " << str2 << endl;
	cout << "We are copying your string ... " << endl << "Result: " << endl;
	copystr(str, str2);
	cout << "STR: " << str << endl;
	cout << "STR2: " << str2 << endl;
	return 0;
}

char* copystr(char *str, char *str2){
	int i;
	i = 0;
	for (i=0; str[i]; i++){
		str2[i] = str[i];
	}
	return str2;
}