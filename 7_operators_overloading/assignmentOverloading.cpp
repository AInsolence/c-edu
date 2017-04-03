#include <iostream>
#include <cstring>

using namespace std;

class sample
{
	char *s;
public:
	sample()
	{ 
		s = new char('\0'); 
		cout << "Constructor is called\n";
	}
	sample(const sample &object);

	~sample(){
		if(s){
			delete [] s;
			cout << "Desturctor is called\n";
		}

	}

	void show_string()
	{
		cout << s << endl;
	}

	void set(const char *str);
};

sample :: sample(const sample &object)
{
	s = new char[strlen(object.s) + 1];
	strcpy(s, object.s);
}

void sample :: set(const char *str)
{
	s = new char[strlen(str) + 1];
	strcpy(s, str);
}

sample input()
{
	sample str;
	char input_str[80];
	cout << "Please input the string\n";
	 cin >> input_str;
	str.set(input_str);
	return str;
}

int main(int argc, char const *argv[])
{
	sample a;
	a.show_string();
	a = input();
	a.show_string();

	return 0;
}