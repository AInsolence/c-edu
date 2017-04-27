#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	try{
		cout << "This is try block\n";
		throw 99;
		cout << "This instruction will not displayed\n";
	}
	catch(int i){
		cout << "This is a catch block!\n";
		cout << "Error code: " << i;
	}

	return 0;
}