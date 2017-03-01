#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int i,t;

	for (i=0; i<argc; i++){
		t = 0;
		while(argv[i][t]){
			cout << argv[i][t] << ' ';
			t++;
		}
		cout << '\n';
	}
	return 0;
}