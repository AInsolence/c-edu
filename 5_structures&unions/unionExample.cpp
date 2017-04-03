#include <iostream>

using namespace std;

union my_union{
		short int a;
		char ch[2];
};
void binary(register unsigned num);

int main(int argc, char const *argv[])
{
	my_union var;
	char temp;
	var.a = 15;
	cout << "\nNumber is:\n" << var.a << endl;
	cout << "Before substitute number 15:\n";
	binary(var.ch[1]);
	binary(var.ch[0]);

	temp = var.ch[0];
	var.ch[0] = var.ch[1];
	var.ch[1] = temp;
	cout << "\nAfter substitute:\n";
	binary(var.ch[1]);
	binary(var.ch[0]);

	cout << "\nNow number is:\n" << var.a;

	return 0;
}

void binary(register unsigned num)
{	
	register int i;
	for (i = 128; i > 0; i = i/2){
	 		if (num & i){
	 			cout << 1;
	 		} else cout << 0;
	 	    cout << ' ';
	}
	cout << " ";
}