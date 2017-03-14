#include <iostream>

using namespace std;

void bitAnd();
void bitOr();
void binary(register unsigned num);
void disp_binary();
void shift();

int main(int argc, char const *argv[])
{
	int choose;
	do {
		cout << "Select menu item or enter '0' to exit\n";
		cout << "1. Bit & (AND) demonstration\n";
		cout << "2. Bit | (OR) demonstration\n";
        cout << "3. Binary representation and '~' operator demonstration\n";
        cout << "4. Binary shift operators '<<' and '>>' demonstration\n";

		 cin >> choose;

		switch (choose){
			case 1:
				bitAnd();
				break;
			case 2:
				bitOr();
				break;
			case 3:
				disp_binary();
				break;
			case 4:
				shift();
				break;

			default:
				break;
		}
	} while (choose != 0);
	return 0;
}

void bitAnd()
{
	char ch;

	do{
		cout << "Enter character to capitalize with bit & (Enter 'Q' to exit): \n";
		 cin >> ch;
		ch = ch & 223;
		cout << "Your result is: " << ch << "\n";
		cout <<"Number '223' in binary is 1101 1111, cause of that \nexpression\
 ch & 223 turned 6th bit into 0 \nand we turn char to capital!\n";

	} while (ch != 'Q');

}

void bitOr()
{
	char ch;

	do{
		cout << "Enter character to lowercase with bit | (Enter 'q' to exit): \n";
		 cin >> ch;
		ch = ch | 32;
		cout << "Your result is: " << ch << "\n";
		cout <<"Number '32' in binary is 0010 0000, cause of that \nexpression\
 ch | 32 turned 6th bit into 1 \nand we turn char to lowercase!\n";

	} while (ch != 'q');

}

void disp_binary()
{
	
	register unsigned num;

	do{
		cout << "Enter number from 0 to 225 to show binary representation (Enter '300' to exit): \n";
	 	 cin >> num;
		cout << "Number " << num << " binary value is: \n";
		binary (num);
		cout << "And ~" << num << " (addition to 1):\n";
		binary (~num);
	 	
	} while (num != 300);
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
	cout << "\n";
}

void shift()
{
	int i = 1, t = 1;
	cout << "\nDemo left shift i variable start from 1 to 128 (multiple *2): \n\n";
	for (t = 0; t < 8; t++){
		binary(i);
		i = i << 1;
	}
	cout << '\n';
	cout << "Demo right shift i variable start from 128 to 1 (division *2): \n\n";
	for (t = 0; t < 8; t++){
		i = i >> 1;
		binary(i);
	}
	cout << '\n';

}