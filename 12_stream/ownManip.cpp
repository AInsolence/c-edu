#include <iostream>
#include <iomanip>

using namespace std;

ostream & setup (ostream & stream)
{
	stream.setf(ios::left);
	stream << setw(30) << setfill('$');
	return stream;
}

int main(int argc, char const *argv[])
{
	cout << setup << "Hello People!" << endl;
	return 0;
}