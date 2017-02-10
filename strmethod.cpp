#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	char str1[80], str2[80], input[80];
	cout << "Please input some text " << endl;
	gets(input);
	cout << "Your string is:\n" << input << endl;

	//String methods practice

	cout << "Hello! First string method is strcpy(to,from). Demonstration: \n";
	cout << "This is str1 " << str1 << endl;
	strcpy(str1, "New info in str1!!!");
	cout << "And now: " << str1 << endl;

	cout << "Second string method is strcat(s1,s2). Demonstration: \n";
	cout << "This is str1 " << str1 << endl;
	strcpy(str2, "STR 2");
	cout << "This is str2 " << str2 << endl;
	strncat(str1, str2, 3);
	cout << "And concatenate: " << str1 << endl;

	cout << "Third string method is strcmp(s1,s2). Demonstration: \n";
	cout << "This is str1 " << str1 << endl;
	cout << strcmp(str1, str2);

	return 0;

}