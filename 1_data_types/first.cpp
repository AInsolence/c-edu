#include <iostream>
#include <cstdlib> // для system
using namespace std;

int main() 
{ 
    cout << "Hello bro! I just calculate the summ of two numbers" << endl << endl;
    cout << "Please type first number" << endl;
    int a;
    cin >> a;
    cout << "Please giv me the second number" << endl;
    int b;
    cin >> b;
    int c = a + b;
    cout << "Heh) This puzzle was too easy for me) The summ will be " << endl << c << endl;
    return 0; 
}