#include <iostream>
#include <vector>

using namespace std;
void show_info(vector<int> &v)
{
	cout << "capcity: " << v.capacity() << endl;
	cout << "size: " << v.size() << endl;
	cout << "max_size: " << v.max_size() << endl;

	std::vector<int>::iterator start;
	cout << "Container elements: " << endl;
	if (!v.empty()){
		for(start = v.begin(); start != v.end(); start++) cout << *start;
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;

	v.reserve(100);
	show_info(v);

	for (int i = 1; i <= 100; i++){
		v.push_back(i);
	}

	show_info(v);

	v.clear();

	for (int i = 1; i <= 120; i++){
		v.push_back(i);
	}

	show_info(v);
	cout << "first element: " << v.front() << endl;
	cout << "last element: " << v.back() << endl;

    //insert one vector to another
	std::vector<char> v2(3, ' ');
	std::vector<int>::iterator place; //NOTE: here we use <int> iterator

	place = v.begin() + 3;
	v.insert(place, v2.begin(), v2.end());
	v.insert(v.begin(), 10, 0);
	show_info(v);
	//

	cout << "element #2: " << v.at(2) << endl;//returns reference to element i
	v.erase(v.begin()+2);
	cout << "element #2: " << v.at(2) << endl;
	v.erase(v.begin()+3, v.end()-3);//removing elements in specified range
	v.reserve(300);
	show_info(v);
	//v.shrink_to_fit(); //c++11 cut v.capacity to v.size to free memory
	cout << "last element: " << v.back() << endl;
	v.pop_back();
	cout << "last element after pop_back: " << v.back() << endl;
	show_info(v);

	return 0;
}			