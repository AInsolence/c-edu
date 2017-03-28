#include <iostream>

using namespace std;

// Here we define class without logic
class queue
{

public:

	int b;
	void init(int i);
	int geta();
	void reset();

private:
	
	int a;

} my_queue;

// We separate logic from data
void queue::init(int i)
{
	a = i;
	b = i*i;
	return;
}

int queue::geta()
{
	return a;
}

void queue::reset()
{
	a = b = 0;
	return;
}




int main(int argc, char const *argv[])
{
	my_queue.init(5);
	cout << "Data:\n" << "a = " << my_queue.geta() << " b = " << my_queue.b << endl;
	my_queue.reset();
	cout << "After reset:\n" << "a = " << my_queue.geta() << " b = " << my_queue.b << endl;
	return 0;
}