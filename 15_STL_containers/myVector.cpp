#include <iostream>
#include <vector>

using namespace std;
template<class T>
void show_info(vector<T> &v)
{
	cout << "capcity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;

	typename std::vector<T>::iterator start;//NOTE: here initialization of the template iterator
	cout << "Container elements: " << endl;
	if (!v.empty()){
		for(start = v.begin(); start != v.end(); start++) cout << *start;
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;

	v.reserve(100);//Reserve func
	show_info(v);

	for (int i = 1; i <= 100; i++){
		v.push_back(i);
	}

	show_info(v);

	v.clear();//Clear func

	for (int i = 1; i <= 120; i++){
		v.push_back(i);
	}

	show_info(v);
	cout << "first element: " << v.front() << endl;
	cout << "last element: " << v.back() << endl;

    //insert one vector to another
	std::vector<char> v2(3, '#');
	std::vector<int>::iterator place; //NOTE: here we use <int> iterator

	place = v.begin() + 3;
	v.insert(place, v2.begin(), v2.end());
	v.insert(v.begin(), 10, 0);
	show_info(v);
	
	//Erase func
	cout << "element #2: " << v.at(2) << endl;//returns reference to element i
	v.erase(v.begin()+2);
	cout << "element #2: " << v.at(2) << endl;
	v.erase(v.begin()+3, v.end()-3);//removing elements in specified range
	v.reserve(300);
	show_info(v);
	//v.shrink_to_fit(); //c++11 cut v.capacity to v.size to free memory
	cout << "last element: " << v.back() << endl;
	v.pop_back();// pop-back func
	cout << "last element after pop_back: " << v.back() << endl;
	show_info(v);

	// Assign func
	std::vector<char> v3;
	v3.assign(v2.begin(), v2.end());
	cout << "v2 info: "<< endl;
	show_info(v2);
	cout << "v3 info: "<< endl;
	show_info(v3);

	//Resize func
	v3.resize(10, '*');
	cout << "v3 info: "<< endl;
	show_info(v3);

	//Swap func
	v3.swap(v2);
	cout << "after swap v3 -> v2 " << endl;
	cout << "v2 info: "<< endl;
	show_info(v2);
	cout << "v3 info: "<< endl;
	show_info(v3);
	cout << "10 element of the v2 vector: " << v2[9];// operator[]

	return 0;
}			