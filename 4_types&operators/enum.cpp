#include <iostream>

using namespace std;

enum family {mother = 1, father, brother, syster = 10, uncle, aunt};

int main()
{

	register family head = mother;
	register family judge = father;
	family manager = uncle;

	cout << head << " " << judge << " " << manager;
	return 0;
	
}