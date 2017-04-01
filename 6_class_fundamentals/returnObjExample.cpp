#include <iostream>
#include <cstring>

using namespace std;

class sample
{
	char str[80];
public:
	void show_str(){ cout << str; };
	void init_str(char *s){ strcpy(str, s);}
	sample(){return;};
	~sample(){return;};
};

sample input_cpy()
{
	char input[80];
	sample object;
	cout << "Please enter string: ";
	 cin >> input;
	object.init_str(input);
	return object;
}

int main(int argc, char const *argv[])
{
	sample my_object;
	my_object = input_cpy(); // Assign to function which returned object
	cout << "Result: ";
	my_object.show_str(); // Check the result
	return 0;
}