#include <iostream>
#include <cstdlib>

using namespace std;

class Vechicle
{
	int wheels;
	int passengers;
public:
	Vechicle(){return;};
	~Vechicle(){return;};

	void set_wheels(int i){wheels = i;};
	int get_wheels(){return wheels;};
	void set_passengers(int j){passengers = j;};
	int get_passengers(){return passengers;};
};

class Truck : public Vechicle
{
	int cargo;
public:
	Truck(){return;};
	~Truck(){return;};

	void set_cargo(int i){cargo = i;};
	int get_cargo(){return cargo;};
	void show();	
};

void Truck :: show()
{
	cout << "Truck\n" << "passengers: " << get_passengers() << endl;
	cout << "wheels: " << get_wheels() << endl;
	cout << "cargo (tonns): " << get_cargo() << endl;
}

enum type
{
	car, van, wagon
};

class Automobile : public Vechicle
{
	type car_type;
public:
	Automobile(){return;};
	~Automobile(){return;};

	void set_type(type t){car_type = t;};
	type get_type(){return car_type;};
	void show();
};

void Automobile :: show()
{
	cout << "Automobile\n" << "passengers: " << get_passengers() << endl;
	cout << "wheels: " << get_wheels() << endl;
	cout << "car type: ";
	switch (car_type){
		case car:
			cout << "car\n";
			break;
		case van:
			cout << "van\n";
			break;
		case wagon:
			cout << "wagon\n";
			break;
	}
}

int main(int argc, char const *argv[])
{
	Truck tatra, mersedes;
	Automobile toyota, lexus, mitsubishi;

	tatra.set_wheels(8);
	tatra.set_passengers(3);
	tatra.set_cargo(25);

	mersedes.set_wheels(16);
	mersedes.set_passengers(2);
	mersedes.set_cargo(50);

	toyota.set_wheels(4);
	toyota.set_passengers(5);
	toyota.set_type(car);

	lexus.set_wheels(4);
	lexus.set_passengers(5);
	lexus.set_type(van);

	mitsubishi.set_wheels(4);
	mitsubishi.set_passengers(5);
	mitsubishi.set_type(wagon);

	tatra.show();
	mersedes.show();
	toyota.show();
	lexus.show();
	mitsubishi.show();

	return 0;
}