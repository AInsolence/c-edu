#include <iostream>
#include <cstring>

using namespace std;

class AnotherSample;
class sample
{
	int password;
public:
	char name[80];
	int id;
	char description[80];
	void get_AnotherObj_status(AnotherSample *obj_ptr);
	friend void show_all(sample *object);
	friend void get_password(sample * object, AnotherSample * object2);
	sample(int num);
	~sample();
	
};

sample :: sample(int num)
{
	id = num;
	strcpy(name, "Sample object");
	strcpy(description, "I'm an implementation of class sample!");
	password = num * 35;
	return;
}

sample :: ~sample()
{
	return;
}

class AnotherSample
{
	int my_secret;
	int i;
	char name[30];
	int status;
public:
	friend void sample :: get_AnotherObj_status(AnotherSample *obj_ptr);
	friend void get_password(sample * object, AnotherSample * object2);
	AnotherSample(int i);
	~AnotherSample();
	
};

AnotherSample :: AnotherSample(int i)
{
	my_secret = (i-32)/2;
	i = 2;
	status = 22;
	strcpy(name, "HAHAa!");
}

AnotherSample :: ~AnotherSample()
{
	return;
}

// Friend for sample class
void show_all(sample *object) 
{
	cout << object -> name << " password is " << object -> password << endl;
	return;
}

// Friend for both classes
void get_password(sample * object, AnotherSample * object2)
{
	cout << "First pass: " << object -> password << endl;
	cout << "Second pass: " << object2 -> my_secret << endl;
	return;
}

// Member of sample class & Friend for AnotherSample class
void sample :: get_AnotherObj_status(AnotherSample *obj_ptr) 
{
	cout << "Sample Object status is " << id << endl;
	cout << "AnotherSample Object status is " << obj_ptr -> status << endl;
	return;
}

int main(int argc, char const *argv[])
{
	/* code */
	sample x(1), *x_ptr;
	sample y(20), *y_ptr;
	x_ptr = &x;
	y_ptr = &y;

	show_all(x_ptr); // Friend for sample class
	show_all(y_ptr);

	AnotherSample z(75), * z_ptr;
	z_ptr = &z;

	get_password(x_ptr, z_ptr); // Friend for both classes

	x.get_AnotherObj_status(z_ptr); // Member of sample class & Friend for AnotherSample class

	cout << "Program is well done!" << endl;
	return 0;
}