#include <iostream>
#include <cstring>

using namespace std;

const char *keyword[][2] = {
	"for", "for (initialization; condition; increment) {code};",
	"while", "while (condition) {code};",
	"if", "if (condition) {code} else (condition2) {code2}",
	"",""
};

int main()
{
	char input[80];
	int i;

	cout << "Please enter the C++ keyword here: \n";
	 cin >> input;

	for (i=0; keyword[i][0];i++) 
		if (!strcmp(keyword[i][0], input)){
			cout << keyword[i][1];
		} 
			

	return 0;
}