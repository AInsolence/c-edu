#include <iostream>

using namespace std;

// Here we define class without logic
class queue
{

public:

	int b;
	queue(int id);
	~queue();
	int geta();
	void reset();

private:
	
	int a;
	int sloc, rloc;
	int who;

};

// We separate logic from data
queue::queue(int id)
{
	sloc = rloc = 0;
	who = id;
	a = id;
	return;
}

queue::~queue()
{
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
	
	queue my_queue(1);
	queue my_queue2(2);
	my_queue.b = 10;
	cout << "Data:\n" << "a = " << my_queue.geta() << " b = " << my_queue.b << endl;
	my_queue.reset();
	cout << "After reset:\n" << "a = " << my_queue.geta() << " b = " << my_queue.b << endl;
	return 0;
}