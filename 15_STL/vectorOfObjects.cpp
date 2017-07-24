#include <iostream>
#include <vector>

using namespace std;

class Three_d
{
public:
	int x, y, z;

	Three_d(){ x = 0; y = 0; z = 0;}
	Three_d(int i, int j, int k){ x = i; y = j; z = k;}
	~Three_d(){}

	friend bool operator > (const Three_d obj_1, const Three_d obj_2);
	friend bool operator < (const Three_d obj_1, const Three_d obj_2);
	friend bool operator == (const Three_d obj_1, const Three_d obj_2);
	friend bool operator >= (const Three_d obj_1, const Three_d obj_2);
	friend bool operator <= (const Three_d obj_1, const Three_d obj_2);

	friend ostream& operator << (ostream& stream, const Three_d obj);
	friend istream& operator >> (istream& stream, Three_d& obj);

};

bool operator > (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) > (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator < (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) < (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator == (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) == (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator >= (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) >= (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator <= (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) <= (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}


ostream& operator << (ostream& stream, const Three_d obj)
{
	stream << obj.x << ", " << obj.y << ", " << obj.z << endl;
	return stream;
}

istream& operator >> (istream& stream, Three_d& obj)
{
	cout << "Please enter coordinates: \n";
	stream >> obj.x >> obj.y >> obj.z;
	return stream;
}


int main(int argc, char const *argv[])
{
	Three_d obj(1, 2, 3);
	std::vector<Three_d> v(10, obj);
	for(int i = 0; i < v.size(); i++) cout << v[i];
	cout << (v[0] < v[1]) << endl;
	cout << (v[0] > v[1]) << endl;
	cout << (v[0] == v[1]) << endl;
	cout << (v[0] <= v[1]) << endl;
	cout << (v[0] >= v[1]) << endl;

	cin >> v[0];
	cout << "Now v[0] = " << v[0] << endl;
	
	return 0;
}