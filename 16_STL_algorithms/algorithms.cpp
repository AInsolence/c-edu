#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

template<class T>
void show_element(T const& ob)
{
	cout << ob << " ";
}

template<class Sequence>
void show_sequence(Sequence const& sequence)
{
    typedef typename Sequence::value_type T;
    for_each(sequence.begin(), sequence.end(), show_element<T>);    
}

int main(int argc, char const *argv[])
{
	//Adjacent find
	std::vector<int> v(20, 0);
	//here the problem
	show_sequence< std::vector<int> >(v);
	
	

	return 0;
}