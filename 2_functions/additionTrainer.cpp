#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int count;
int right_ans;

void addition();

int main(int argc, char const *argv[])
{
	cout << "How much exercises you want to do now?\n";
	 cin >> count;
	int q = count;
	right_ans = 0;
	do{
		addition();
		count--;
	} while (count);

	cout << "Today you have " << q << " questions\n";
	cout << "And get " << right_ans << " right answers\n";

	return 0;
}

void addition(){
	int num1;
	int num2;
	int result, version;
	srand(time(NULL));
	num1 = rand()%100;
	num2 = rand()%100;
	result = num1 + num2;
	cout << "How much will be " << num1 << '+' << num2 << '\n';
	 cin >> version;
	if (result == version){
		right_ans ++;
		cout << "Right answer!\n";
	}else cout << "Wrong answer!!!\n";
} 