#include <iostream>

using namespace std;

class Base
{
public:
	int main_parameter;
	Base(int x){main_parameter = x;}
	~Base(){}
protected:
	void show_base(){cout << "main_parameter: " << main_parameter << endl;}
};

class Base_level_2_1 : virtual private Base
{
public:
	Base :: main_parameter;
	int base_2_1_param;
	Base_level_2_1(int x, int y) : Base(x) {base_2_1_param = y;}
	~Base_level_2_1(){}
	void show_base_2_1(){cout << "base_2_1_param: " << base_2_1_param << endl;}
};

class Base_level_2_2 : virtual public Base
{
public:
	int base_2_2_param;
	Base_level_2_2(int x, int z) : Base(x) {base_2_2_param = z;}
	~Base_level_2_2(){}
	void show_base_2_2(){cout << "base_2_2_param: " << base_2_2_param << endl;}
};

class Final : public Base_level_2_1, public Base_level_2_2
{
public:
	Final(int x, int y, int z): Base(x), Base_level_2_1(x, y), Base_level_2_2(x, z){}
	~Final(){}
	void show_all(){
		show_base();
		show_base_2_1();
		show_base_2_2();
	}
};




int main(int argc, char const *argv[])
{
	Final object(11, 33, 55);
	object.show_all();
	return 0;
}