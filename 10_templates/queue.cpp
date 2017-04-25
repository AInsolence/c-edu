#include <iostream>

using namespace std;

const int SIZE = 100;

template <class Qtype>
class Queue
{
	Qtype q[SIZE];
	int sloc, rloc;
public:
	Queue(){sloc = rloc = 0;}
	~Queue(){}
	void put_element(Qtype i);
	Qtype get_element();
};

template <class Qtype>
void Queue<Qtype> :: put_element(Qtype i)
{
	if (sloc == SIZE){
		cout << "Queue is full!" << endl;
		return;
	}

	sloc ++;

	q[sloc] = i;
}

template <class Qtype>
Qtype Queue<Qtype> :: get_element()
{
	if (rloc >= sloc){
		cout << "Queue is empty!" << endl;
		return 0;
	}

	rloc ++;
	return q[rloc];
}

int main(int argc, char const *argv[])
{
	Queue<int> int_queue;
	Queue<double> d_queue;

	int_queue.put_element(5);
	int_queue.put_element(6);
	int_queue.put_element(7);

	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;

	cout << endl;

	d_queue.put_element(5.67);
	d_queue.put_element(6.0);
	d_queue.put_element(7.4);

	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;

	return 0;
}