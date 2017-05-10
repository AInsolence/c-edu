#include <iostream>
#include <iomanip>

using namespace std;

ostream & setup (ostream & stream)
{
	stream.setf(ios::left);
	stream << setw(30) << setfill('$');
	return stream;
}

istream & prompt (istream & stream)
{
	cin >> hex;
	cout << "Please enter in hex " << endl;
	return stream;
}

int main(int argc, char const *argv[])
{
	double x;
	cout << setup << "Hello People!" << endl;
	 cin >> prompt >> x;
	cout << hex << x;
	return 0;
}