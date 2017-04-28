#include <iostream>
#include <cstring>

using namespace std;


void xhandler(int i)
{
	try{
		if (i){
			throw i;
		}
		throw 'a';
	}
	catch(int j){
		cout << "Interception exception #" << j << endl;
	}
	catch(char ch){
		cout << "Interception #" << ch << endl;
	}
	catch(...){
		cout << "Last frontier!)" << endl;
	}
}

class Xhandler
{
public:
	char message[80];

	Xhandler(){*message = 0;}
	Xhandler(const char * s){strcpy(message, s);}
	~Xhandler(){}
	
};

int main(int argc, char const *argv[])
{
	xhandler(1);
	xhandler(0);
	xhandler(2);
	xhandler(3);
	xhandler('a');

	double a, b;

	try{
		cout << "Enter number and divider: \n";
		 cin >> a >> b;
		if (!b){
			throw Xhandler("You cannot divide to ZERO!\n");
		}
		else{
			cout << "Result is: " << a/b << endl;
		}
	}

	catch(Xhandler e){
		cout << e.message << endl;
	}

	return 0;
}