#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 2){
		cout << "You missed name argument, please try again!\n";
	}else{
		cout << "Hello " << argv[1] << "!\n";
	}
	cout << "argc - Number of arguments == " << argc;
	return 0;
}