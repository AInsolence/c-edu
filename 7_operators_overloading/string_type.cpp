#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int SIZE = 200;

class String_type
{
	char string_ [SIZE];
public:
	String_type();
	String_type(const char *str);
	~String_type();
	void show();
	int find(const char *str);

	String_type operator=(const char *str);

	/* Use friends functions for overloading '+',
	because we do not want any changes in source objects */
	friend String_type operator+(String_type object, String_type object2);
	friend String_type operator+(String_type object, const char *str);
	friend String_type operator+(const char *str, String_type object);

	friend String_type operator*(String_type object, int number);
	friend String_type operator*(int number, String_type object);

	String_type operator-(String_type object2){};
	String_type operator-(const char *str);

	char & operator[](int index);


};

String_type :: ~String_type(){return;}

String_type :: String_type(){return;}

String_type :: String_type(const char *str)
{
	strcpy(string_, str);
	return;
}

void String_type :: show()
{
	cout << string_ << endl;
}

String_type String_type :: operator=(const char *str)
{
	strcpy(string_, str);
}

String_type operator*(String_type object, int number)
{
	String_type temp;
	strcpy(temp.string_, object.string_);
	if (number == 0){
		strcpy(object.string_, '\0');
	}
	else{
		for (int i=1; i < number; i++){
			strcat(object.string_, temp.string_);
		}
	}
	return object;
}

String_type operator*(int number, String_type object)
{
	String_type temp;
	strcpy(temp.string_, object.string_);
	if (number == 0){
		strcpy(object.string_, '\0');
	}
	else{
		for (int i=1; i < number; i++){
			strcat(object.string_, temp.string_);
		}
	}
	return object;
}

String_type operator+(String_type object, String_type object2)
{
	String_type result;
	strcpy(result.string_, strcat(object.string_, object2.string_));
	return result;
}

String_type operator+(String_type object, const char *str)
{
	String_type result;
	strcpy(result.string_, (strcat(object.string_, str)));
	return result;
}

String_type operator+(const char *str, String_type object)
{
	String_type result;
	strcat(strcpy(result.string_, str), object.string_);
	return result;
}

char & String_type :: operator[](int index)
{
	char * str;
	str = string_;
	if ((index > -1) && (index < strlen(string_))){
		return str[index];
	}
	else{
		cout << "Error: out of range";
		exit(1);
	}
}

String_type String_type :: operator-(const char *str)
{

}

int String_type :: find(const char *str)
{
	char *s, *f;
	char temp [SIZE];
	strcpy(temp, str);
	s = string_;
	f = temp;
	int index = -1;
	for (register int i = 0; s[i]; i++){
		if (f[0] == s[i]){
			index = i;
			for (register int j = 0; f[j]; j++, i++){
				if (f[j] != s[i]){ 
					index = -1;
				 	break; 
				}
			}
			if (index != -1) return index;
		}
	}
	return index;
}

int main(int argc, char const *argv[])
{
	String_type a, b, c, d;
	int find_result;
	// Constructor overloading
	String_type e = "String e!";
	e.show();
	// Overloading "="
	a = "This is regulus rex ";
	// Overloading "+" for this + const *char
	a = a + "A!";
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
	cout << c[5] << endl;
	//Overloading "*"
	d = a * 2;
	d.show();
	a.show();
	// find method
	find_result = a.find("rex");
	cout << "Find function result is : " << find_result << endl;
	cout << c[30] << endl;
	return 0;
}