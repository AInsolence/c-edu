#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int SIZE = 200;

class string_type
{
	char string [SIZE];
public:
	string_type();
	~string_type();
	void show();
	int find(char *str);

	string_type operator=(const char *str);

	/* Use friends functions for overloading '+',
	because we do not want any changes in source objects */
	friend string_type operator+(string_type object, string_type object2);
	friend string_type operator+(string_type object, const char *str);
	friend string_type operator+(const char *str, string_type object);

	friend string_type operator*(string_type object, int number);
	friend string_type operator*(int number, string_type object);

	string_type operator-(string_type object2){};
	string_type operator-(const char *str);

	char & operator[](int index);


};

string_type :: ~string_type(){return;}

string_type :: string_type(){return;}

void string_type :: show()
{
	cout << string << endl;
}

int string_type :: find(char *str)
{
	return 0;
}

string_type string_type :: operator=(const char *str)
{
	strcpy(string, str);
}

string_type operator*(string_type object, int number)
{
	string_type temp;
	strcpy(temp.string, object.string);
	if (number == 0){
		strcpy(object.string, '\0');
	}
	else{
		for (int i=1; i < number; i++){
			strcat(object.string, temp.string);
		}
	}
	return object;
}

string_type operator*(int number, string_type object)
{
	string_type temp;
	strcpy(temp.string, object.string);
	if (number == 0){
		strcpy(object.string, '\0');
	}
	else{
		for (int i=1; i < number; i++){
			strcat(object.string, temp.string);
		}
	}
	return object;
}

string_type operator+(string_type object, string_type object2)
{
	string_type result;
	strcpy(result.string, strcat(object.string, object2.string));
	return result;
}

string_type operator+(string_type object, const char *str)
{
	string_type result;
	strcpy(result.string, (strcat(object.string, str)));
	return result;
}

string_type operator+(const char *str, string_type object)
{
	string_type result;
	strcat(strcpy(result.string, str), object.string);
	return result;
}

char & string_type :: operator[](int index)
{
	char * str;
	str = string;
	if (index < strlen(string)){
		return str[index];
	}
	else{
		cout << "Error: out of range";
		exit(1);
	}
}

string_type string_type :: operator-(const char *str)
{

}


int main(int argc, char const *argv[])
{
	string_type a, b, c, d;
	// Overloading "="
	a = "This is ";
	// Overloading "+" for this + const *char
	a = a + " A!";
	a.show();
	// Overloading "+" for this + object2
	b = "New info from object B";
	b.show();
	c = a+b;
	c.show();
	// Overloading "+" for const *char + object
	c = "HHH" + a;
	a.show();
	//Overloading "[]"
	c.show();
	cout << c[0] << endl;
	cout << c[3] << endl;
	cout << c[13] << endl;
	//Overloading "*"
	d = a * 3;
	d.show();
	a.show();
	cout << c[30] << endl;
	return 0;
}