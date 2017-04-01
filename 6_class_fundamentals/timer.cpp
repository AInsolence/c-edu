#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class timer
{
	int seconds;
public:
	timer(int sec);
	timer(const char *sec);
	timer(int min, int sec);
	~timer();
	void run();
};

timer :: timer(int sec) // Constructor with one int type argument
{
	seconds = sec;
}

timer :: timer(const char *sec) // Constructor with one char type argument
{
	seconds = atoi(sec);
}

timer :: timer(int min, int sec) //Constructor with two int arguments
{
	seconds = min*60 + sec;
}

timer :: ~timer()
{
	return;
}

void timer :: run()
{
	clock_t start_point;
	start_point = clock();
	cout << " " << start_point << " \n";
	while (clock()/CLOCKS_PER_SEC - start_point/CLOCKS_PER_SEC < seconds);
	cout << "\a"; // sound signal
	return;
}

int main(int argc, char const *argv[])
{
	timer a(3), b("5"), c(0,7);
	a.run();
	b.run();
	c.run();
	cout << "\nProgramm is done!";
	return 0;
}