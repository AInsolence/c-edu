#include <iostream>

using namespace std;

class Coordinates
{
	int x, y, z;
public:
	Coordinates(){x = y = z = 0;}
	Coordinates(int i, int j, int k);
	~Coordinates(){}
	friend ostream & operator << (ostream & stream, Coordinates object);
	friend istream & operator >> (istream & stream, Coordinates & object);
};

Coordinates :: Coordinates(int i, int j, int k)
{
	x = i;
	y = j;
	z = k;
}

ostream & operator << (ostream & stream, Coordinates object)
{
	stream << object.x << ", ";
	stream << object.y << ", ";
	stream << object.z << endl;
	return stream;
}

istream & operator >> (istream & stream, Coordinates & object)
{
	cout << "Please enter coordinates: \n";
	stream >> object.x >> object.y >> object.z;
	return stream;
}

int main(int argc, char const *argv[])
{
	Coordinates one(1, 2, 3), two(5, 6, 8);
	cout << one;
	cout << two;
	 cin >> one;
	cout << one;
	return 0;
}