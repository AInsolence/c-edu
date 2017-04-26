#include <iostream>
#include <cstdlib>

using namespace std;


class Queue
{
	int array[4];
	int sloc, rloc;
public:
	Queue(){sloc = rloc = -1;}
	~Queue(){}
	void put(int i);
	int get();
};

void Queue :: put(int i)
{
	if (sloc >= 3){
		cout << "Queue is full!\n";
		return;
	}
	sloc ++;
	cout << "sloc " << sloc << endl;
	array[sloc] = i;
}

int Queue :: get()
{
	if (rloc == sloc){
		cout << "Queue is empty!\n";
		return 0;
	}
	rloc ++;
	return array[rloc];
}

int main(int argc, char const *argv[])
{
	Queue one;
	one.put(5);
	one.put(6);
	one.put(7);
	one.put(8);
	one.put(9);
	one.put(9);
	one.put(9);

	cout << one.get() << endl;
	cout << one.get() << endl;
	cout << one.get() << endl;
	cout << one.get() << endl;
	cout << one.get() << endl;
	cout << one.get() << endl;


	return 0;
}