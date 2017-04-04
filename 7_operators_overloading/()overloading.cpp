#include <iostream>

using namespace std;

class sample
{
	int x, y, z;
public:
	sample operator ()(int a, int b);
	sample(){x=y=z=0;};
	sample (int i, int j, int k);
	~sample(){return;};
	void show();
};

sample :: sample (int i, int j, int k)
{
	x = i;
	y = j;
	z = k;
}

sample sample :: operator()(int a, int b)
{
	x = (x + a)/b;
	y = (y + a)/b;
	z = (z + a)/b;
}

void sample :: show()
{
	cout << x << " " << y << " " << z << endl;
}

int main(int argc, char const *argv[])
{
	sample a;
	a.show();
	sample b(10, 20 ,30);
	b.show();
	b(30, 2);
	b.show();
	return 0;
}