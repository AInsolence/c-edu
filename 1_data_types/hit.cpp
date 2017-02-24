#include <iostream>
#include <cstdlib> // для system
#include <conio.h>
using namespace std;

int main() 
{ 
    

    for (int i = 0; !kbhit() ; ++i)
    {
        cout << i << ' ';
    }
    return 0; 
}
