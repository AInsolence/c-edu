#include <iostream>
#include <string>
#include <list>

using namespace std;

class Three_d
{
public:
	int x, y, z;

	Three_d(){ x = 0; y = 0; z = 0;}
	Three_d(int i, int j, int k){ x = i; y = j; z = k;}
	~Three_d(){}

	friend bool operator > (const Three_d obj_1, const Three_d obj_2);
	friend bool operator < (const Three_d obj_1, const Three_d obj_2);
	friend bool operator == (const Three_d obj_1, const Three_d obj_2);
	friend bool operator >= (const Three_d obj_1, const Three_d obj_2);
	friend bool operator <= (const Three_d obj_1, const Three_d obj_2);

	friend ostream& operator << (ostream& stream, const Three_d obj);
	friend istream& operator >> (istream& stream, Three_d& obj);

};

bool operator > (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) > (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator < (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) < (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator == (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) == (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator >= (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) >= (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}

bool operator <= (const Three_d obj_1, const Three_d obj_2)
{
	if ((obj_1.x + obj_1.y + obj_1.z) <= (obj_2.x + obj_2.y + obj_2.z)) return true;
	else return false;
}


ostream& operator << (ostream& stream, const Three_d obj)
{
	stream << obj.x << ", " << obj.y << ", " << obj.z << endl;
	return stream;
}

istream& operator >> (istream& stream, Three_d& obj)
{
	cout << "Please enter coordinates: \n";
	stream >> obj.x >> obj.y >> obj.z;
	return stream;
}

template<class T>
void show_info(std::list<T> lst)
{
	cout << "size: " << lst.size() << endl;
	cout << "max_size: " << lst.max_size() << endl;
	typename std::list<T>::iterator start;
	start = lst.begin();
	for (start; start != lst.end(); start ++){
		cout << *start << endl;
	}
}

bool reverse_sort_func(string one, string two)
{
	return one > two;
}

bool RemoveUnPred(string target)
{
	return (target == "Human");
}

bool RemoveIntUnPred(int target)
{
	return (target%2 == 0);
}

int main(int argc, char const *argv[])
{
	list<string> first;
	

	first.assign(5, "Human");
	string family [4] = {"Anton", "Marina", "Roma", "Elina"};

	first.insert(first.begin(), 10, "Who?");
	first.insert(first.begin(), 3, "I am");

	show_info(first);

	list<string> second(first);
	show_info(second);
	second.clear();

	string * ptr;
	ptr = family;

	for (int i = 0; i < (sizeof(family)/sizeof(string)); i++, ptr++){
		second.push_front(*ptr);
	}
	show_info(second);

	second.sort(reverse_sort_func);
	show_info(second);

	first.remove("Who?");
	first.remove_if(RemoveUnPred);
	show_info(first);

	//Remove_if with predicate
	list<int> third;
	for (int i = 0; i < 10; i++) third.push_back(i);
	show_info(third);
	third.remove_if(RemoveIntUnPred);
	show_info(third);

	third.reverse();

	//Splice function
	typename std::list<string>::iterator start;
	start = second.begin();
	std::advance(start, 2);//increase iterator to 2 positions

	first.splice(first.end(), second, second.begin(), start);

	show_info(first); show_info(second);

	//Merge lists
	first.merge(second);
	first.sort();
	show_info(first); show_info(second);

	//Swap & Unique functions
	second.swap(first);
	second.unique();
	show_info(first); show_info(second);
	//Resize
	second.resize(7);
	show_info(second);

	cout << first.empty();

	return 0;
}