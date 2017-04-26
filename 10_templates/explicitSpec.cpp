#include <iostream>

using namespace std;

template<class T = double, int multiplier = 10>
class ExplicitSpec
{
	T x;
public:
	ExplicitSpec(T i){
		cout << "Main specialization\n";
		x = i*multiplier;
	}
	~ExplicitSpec(){}
	T get_x();
};

template<class T, int multiplier>
T ExplicitSpec<T, multiplier> :: get_x() //WARNING!!!! USE a CONSTANT type of integer
{
	return x;
}

template<>
class ExplicitSpec<int>
{
	int x;
public:
	ExplicitSpec(int i){
		cout << "Explicit specialization for integer\n";
		x = i;
	}
	~ExplicitSpec(){}
	int get_x();
};

int ExplicitSpec<int> :: get_x()
{
	return x;
}

int main(int argc, char const *argv[])
{
	ExplicitSpec<float, 3> three_object(10.2);
	ExplicitSpec<int> five_object(5);

	return 0;
}