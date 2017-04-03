#include <iostream>

using namespace std;

class vector3D
{
	int x, y, z;
public:
	vector3D(){ x=y=z=0; }
	vector3D(int i, int j, int k) {x = i; y = j; z = k;}
	vector3D operator + (vector3D operand2); // operand1 pass implicitly
	vector3D operator = (vector3D operand2); // operand1 pass implicitly
	vector3D operator ++ ();
	vector3D operator ++ (int notused);
	bool operator == (vector3D operand2);
	bool operator > (vector3D operand2);
	bool operator < (vector3D operand2);


	friend vector3D operator - (vector3D operand1, vector3D operand2);
	
	friend vector3D operator + (vector3D operand1, int operand);
	friend vector3D operator + (int operand, vector3D operand1);

	void show_values(){cout << "x= " << x << " y= " << y << " z= " << z << endl;};
	~vector3D(){};
};

vector3D vector3D :: operator + (vector3D operand2)
{
	vector3D temp;
	temp.x = x + operand2.x; // the same as "temp.x = this -> x + operand2.x"
	temp.y = this -> y + operand2.y;
	temp.z = this -> z + operand2.z;
	return temp;
}

vector3D vector3D :: operator = (vector3D operand2)
{
	this -> x = operand2.x; // same as next
	y = operand2.y; // same as previous
	z = operand2.z;
	return *this;
}

vector3D vector3D :: operator ++ ()
{
	x ++;
	y ++;
	z ++;
	return *this;
}

bool vector3D :: operator == (vector3D operand2)
{
	if ((x == operand2.x) && (y == operand2.y) && (z == operand2.z)){
		return true;
	}
	else
	{
		return false;
	}
}

bool vector3D :: operator > (vector3D operand2)
{
	if ((x - y) > (operand2.x - operand2.y)){
		return true;
	}
	else
	{
		return false;
	}
}

bool vector3D :: operator < (vector3D operand2)
{
	if ((x - y) < (operand2.x - operand2.y)){
		return true;
	}
	else
	{
		return false;
	}
}

vector3D vector3D :: operator ++ (int notused)
{
	vector3D temp = *this;
	x ++;
	y ++;
	z ++;
	return temp;
}

vector3D operator - (vector3D operand1, vector3D operand2)
{
	vector3D temp;
	temp.x = operand1.x - operand2.x;
	temp.y = operand1.y - operand2.y;
	temp.z = operand1.z - operand2.z;
	return temp;
}

vector3D operator + (vector3D operand1, int operand)
{
	vector3D temp;
	temp.x = operand1.x + operand;
	temp.y = operand1.y + operand;
	temp.z = operand1.z + operand;
	return temp;
}

vector3D operator + (int operand, vector3D operand1)
{
	vector3D temp;
	temp.x = operand + operand1.x;
	temp.y = operand + operand1.y;
	temp.z = operand + operand1.z;
	return temp;
}

int main(int argc, char const *argv[])
{
	vector3D a(10, 10, 10), b(20,20,20), c;
	a.show_values();
	b.show_values();
	c.show_values();
	cout << "c = a+b;\n";
	c = a+b;
	c.show_values();
	cout << "a = b;\n";
	a = b;
	a.show_values();
	cout << "++a;\n";
	++ a;
	a.show_values();

	// Pre- & Post- fix increment

	a = b;
	cout << "A and B now the same: \n";
	a.show_values();
	b.show_values();
	cout << "a = ++ b;\n";
	a = ++b;
	cout << "A and B now: \n";
	a.show_values();
	b.show_values();

	cout << "a = b ++;\n";
	a = b++;
	cout << "A and B now: \n";
	a.show_values();
	b.show_values();

	cout << "a and b;\n";
	a.show_values();
	b.show_values();
	cout << "a - b: \n";
	c = a-b;
	cout << "A and B now: \n";
	a.show_values();
	b.show_values();
	c.show_values();

	// Overloaded + with int in friend function
	a = a + 10;
	a.show_values();
	b = 10 + b;
	b.show_values();
	cout << (a == b) << endl;
	cout << (a == a) << endl;
	cout << (a > b) << endl;
	cout << (a < c) << endl;

	return 0;
}