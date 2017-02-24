#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool password();

int main(int argc, char const *argv[])
{
	if (password()){
		cout << "Password is correct. Welcome!\n";
		return 0;
	}

	cout << "Password incorrect. Access denied. Try once more.\n";

	return 0;
}

bool password(){

	char key[80];
	char input[80];

	strcpy(key, "password");

	cout << "Enter Password\n";
	gets(input);
	if (strcmp(key, input)){
		return false;
	}

	return true;
}