#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class Figure
{
protected:
	double x, y;
public:
	Figure(double i, double j){ 
		x = i;                          
		y = j;							
	}
	virtual ~Figure(){}
	virtual void show_square() = 0;	// Pure virtual function
};


class Rectangle : public Figure
{
public:
	Rectangle(double i, double j) : Figure (i, j){}
	~Rectangle(){}
	void show_square(){
		cout << "Rectangle with hieght " << x << " & width ";
		cout << y << " square is " << x*y << endl;
	}
};

class Triangle : public Figure
{
public:
	Triangle(double i, double j) : Figure (i, j){}
	~Triangle(){}
	void show_square(){
		cout << "Triangle with hieght " << x << " & base ";
		cout << y << " square is " << x*0.5*y << endl;
	}
};

class Circle : public Figure
{
public:
	Circle(double i, double j = 0) : Figure (i, j){}
	~Circle(){}
	void show_square(){
		cout << "Circle with radius " << x;
		cout << " square is " << x*x*3.14 << endl;
	}
};

Figure* figureFactory()
{
	switch(rand()%3){
		case 0:
			return new Triangle(10,10);
		case 1:
			return new Rectangle(5, 10);
		case 2:
			return new Circle (10);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int num, c=0, t=0, r=0;
	Figure* ptr;
	cout << "Please enter how many figures you want to create\n";
	 cin >> num;
	for (int i = 0; i < num; i++){
		ptr = figureFactory();
		cout << "Created " << typeid(*ptr).name() << endl;
		if(typeid(*ptr) == typeid(Circle)) c++;
		if(typeid(*ptr) == typeid(Triangle)) t++;
		if(typeid(*ptr) == typeid(Rectangle)) r++;
	}

	cout << "Created: ";
	cout << c << " circles, " << t << " triangles, " << r << " rectangles.";

	return 0;
}