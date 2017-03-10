#include <iostream>

using namespace std;

int r_avg(int num);

int main(int argc, char const *argv[])
{
	int number;
	
	do{
		cout << "Enter integer number (-1 mean exit) to find average" << endl;
	 	 cin >> number;
	 	if (number != -1){
	 		cout << "Current average position: " << r_avg(number) << endl;
	 	}

	}while(number > -1);

	return 0;
}

int r_avg(int num)
{
	static int sum = 0, count = 0;
	sum += num;
	count ++;
	return sum/count;
}