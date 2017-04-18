#include <iostream>

using namespace std;

class Figure
{
protected:
	double x, y;
public:
	Figure(){}
	~Figure(){}
	void set_dim(double i, double j=0){ // Use the default parameter to avoid 
		x = i;                          // overloaded set_dim function creation in class Circle
		y = j;							// cause in circle 'y' parameter is redundant
	}
	// Pure virtual function
	virtual void show_square() = 0;	
};

class Rectangle : public Figure
{
public:
	Rectangle(){}
	~Rectangle(){}
	void show_square(){
		cout << "Rectangle with hieght " << x << " & width ";
		cout << y << " square is " << x*y << endl;
	}
};

class Triangle : public Figure
{
public:
	Triangle(){}
	~Triangle(){}
	void show_square(){
		cout << "Triangle with hieght " << x << " & base ";
		cout << y << " square is " << x*0.5*y << endl;
	}
};

class Circle : public Figure
{
public:
	Circle(){}
	~Circle(){}
	void show_square(){
		cout << "Circle with radius " << x;
		cout << " square is " << x*x*3.14 << endl;
	}
};

int main(int argc, char const *argv[])
{
	Rectangle rec_object;
	Triangle tri_object;
	Figure * f_ptr;

	rec_object.set_dim(10, 5);
	tri_object.set_dim(10, 3);

	f_ptr = &rec_object;
	f_ptr -> show_square();

	f_ptr = &tri_object;
	f_ptr -> show_square();

	Circle cir_object;
	cir_object.set_dim(10);
	f_ptr = &cir_object;
	f_ptr -> show_square();


	return 0;
}