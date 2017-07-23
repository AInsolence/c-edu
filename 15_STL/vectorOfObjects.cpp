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
};

int main(int argc, char const *argv[])
{
	Three_d obj;
	std::vector<Three_d> v(10, obj);
	return 0;
}