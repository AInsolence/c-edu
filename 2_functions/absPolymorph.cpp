#include <iostream>

using namespace std;

int myabs(int i);
long myabs(long l);
double myabs(double d);

int main(int argc, char const *argv[])
{
	int num;
	cout << "For value -10 abs is: " << myabs(-10) << endl;
	cout << "For value -103546 abs is: " << myabs(-103546) << endl;
	cout << "For value -10.345 abs is: " << myabs(-10.345) << endl;
	return 0;
}

int myabs(int i){
	if (i < 0) return -i;
	return i;
}
long myabs(long l){
	if (l < 0) return -l;
	return l;
}
double myabs(double d){
	if (d < 0) return -d;
	return d;
}