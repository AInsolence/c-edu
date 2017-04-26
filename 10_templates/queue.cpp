#include <iostream>

using namespace std;

const int SIZE = 5;

template <class Qtype, const int SIZE>
class Queue
{
	Qtype q[SIZE];
	int sloc, rloc;
public:
	Queue(){sloc = rloc = -1;}
	~Queue(){}
	void put_element(Qtype i);
	Qtype get_element();
};

template <class Qtype, const int SIZE>
void Queue<Qtype, SIZE> :: put_element(Qtype i)
{
	if (sloc >= SIZE - 1){
		cout << "Queue is full!" << endl;
		return;
	}

	sloc ++;

	q[sloc] = i;
}

template <class Qtype, const int SIZE>
Qtype Queue<Qtype, SIZE> :: get_element()
{
	if (rloc == sloc){
		cout << "Queue is empty!" << endl;
		return 0;
	}

	rloc ++;
	return q[rloc];
}

int main(int argc, char const *argv[])
{
	Queue<int, 3> int_queue;
	Queue<double, 3> d_queue;

	int_queue.put_element(5);
	int_queue.put_element(6);
	int_queue.put_element(7);

	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;
	cout << int_queue.get_element() << endl;

	d_queue.put_element(10.1);
	d_queue.put_element(3.4);
	d_queue.put_element(6.7);
	d_queue.put_element(33.4);
	d_queue.put_element(8.9);

	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;
	cout << d_queue.get_element() << endl;

	return 0;
}