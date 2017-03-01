#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

char* finded (char *str, char *find);

int main(int argc, char const *argv[])
{
	char str[80];
	char find[80];
	char* index;
	 gets(str);
	 gets(find);
	index = finded(str, find);
	cout << "\n" << &index;
	return 0;
}

char* finded (char *str, char *find){

	cout << "MAIN : " << *str << " " << &str << str << " " << *find << " " << find;
	int i;

	for (i=0; str[i]; i++){
		char *p;
		char *q;
		char *ptrsubstr;

		
		p = &str[i]; cout << "&p == " << &p << endl << "p == " << p << endl << "*p == " << *p;
		q = find;
		ptrsubstr = p;
		while (*q && *q == *p){
			q++;
			p++;
		}
		if (!*q) return ptrsubstr;
	}
	return 0;
}