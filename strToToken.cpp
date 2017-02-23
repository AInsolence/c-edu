#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	char inputStr[80];
	char token[80];
	char *p, *q;
	cout << "Please enter string to separate: " << endl;
	 gets(inputStr);
	p = inputStr;

	while(*p){
		q = token;
		while(*p != ' ' && *p) {
			*q = *p;
			q++;
			p++;
		}
		if (*p) p++;
		*q = '\0';

		cout << token << '\n';

	}
	cout << strlen("С++-компилятор");
	return 0;
}