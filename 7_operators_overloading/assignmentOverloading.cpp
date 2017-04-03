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

	sample operator = (const sample &object);
	void show_string()
	{
		if (s) cout << s << endl;
		else cout << "NO s HERE";
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

sample sample :: operator = (const sample &object)
{
	if (strlen(s) < strlen(object.s)){
		delete [] s;
		s = new char[strlen(object.s) + 1];
	}
	strcpy(s, object.s);
	return *this;
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
	a = input();
	a.show_string();

	return 0;
}