#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

namespace{
	const int SIZE = 3;
}


int my_rand()
{	
	static bool flag;
    if (!flag)
    {
        srand(time(NULL));
        flag = true;
    }
	return rand() % 100 +1;
}

template<class T>
void show_element(T const& ob)
{
	cout << ob << " ";
}

template<class Sequence>
void show_sequence(Sequence const& sequence)
{
	cout << endl;
    typedef typename Sequence::value_type T;
    //for_each: returns unPred's bool value
    for_each(sequence.begin(), sequence.end(), show_element<T>); 
    cout << endl;
}

template<typename K, typename V>
void show_c_element(pair <K, V> element)
{
	cout << element.first << " - " << element.second << endl;
}

template<typename AC>
void show_associative_con(AC const& container)
{
	cout << endl;
	typedef typename AC::mapped_type V;
	typedef typename AC::key_type K;
	for_each(container.begin(), container.end(), show_c_element<K, V>);
	cout << endl;
}

template<typename T>
bool unPred(T const& ob_1)
{
	if (ob_1 < SIZE) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v(20, 0);
	show_sequence< std::vector<int> >(v);
	
	//generate: void
	generate(v.begin(), v.end(), my_rand);//here I using my own function to
										  //get random number
	show_sequence< std::vector<int> >(v);
	int new_number = v[10];
	v.push_back(new_number);
	cout << endl << new_number << endl;
	
	//sort: void
	sort(v.begin(), v.end());
	show_sequence< std::vector<int> >(v);
	
	//adjacent_find: returns an iterator to the first element of adjacent elements
	std::vector<int>::iterator v_iter;
	v_iter = adjacent_find(v.begin(), v.end());
	if (*v_iter = 53) cout << "Element " << new_number << " is finded!" << endl;
	
	//binary_search: returns bool
	if(binary_search(v.begin(), v.end(), 53)) cout << "true" << endl;
	else cout << "false" << endl;
	
	//copy: void
	std::vector<int> v_back_copy(30);
	copy(v.begin(), v.begin() + 10, v_back_copy.begin() + 10);
	show_sequence<vector<int> >(v_back_copy);
	cout << endl;
	
	//copy_backward: void - copy start from the last element, but sequence is saved
	copy_backward(v.begin(), v.begin() + 5, v_back_copy.begin() + 10);
	show_sequence<vector<int> >(v_back_copy);
	cout << endl;
	
	//count: returns number of elements == value
	cout << "Number of 0: " << count(v_back_copy.begin(), v_back_copy.end(), 0);
	
	//count_if: returns number of unPred(element) == true
	cout << "Number of elements < " << SIZE << ": ";
	cout << count_if(v_back_copy.begin(), v_back_copy.end(), unPred<int>) << endl;
	
	//equal: return bool, compare two sequences
	std::vector<int> v_back_copy_2(v_back_copy);
	bool result = equal(v_back_copy.begin(), v_back_copy.end(),\
		 				v_back_copy_2.begin());
	if (result) cout << "v_back_copy and v_back_copy_2 is equal" << endl;
	result = equal(v_back_copy.begin(), v_back_copy.end(), v.begin());
	if (!result) cout << "v_back_copy and v is not equal" << endl;
	std::list<int> my_list(v.begin(), v.end());
	if(equal(v.begin(), v.end(), my_list.begin())) cout << "v and my_list is equal";
	cout << endl;
	
	//equal_range: return pair<iter, iter> for range of elements == val
	for(register int i = 0; i < 5; i++) my_list.push_back(5);
	my_list.push_back(100);
	my_list.sort();
	show_sequence< list<int> >(my_list);
	cout << endl;
	pair<std::list<int>::iterator, std::list<int>::iterator> range_1, range_2;
	range_1 = equal_range(my_list.begin(), my_list.end(), 5);
	range_2 = make_pair(lower_bound(my_list.begin(), my_list.end(), 5),\
						upper_bound(my_list.begin(), my_list.end(), 5));
	if (range_1 == range_2) cout << "We are find range with elements == 5" << endl;
	cout << "range_1: ";
	cout << *(range_1.first) << endl;
	cout << *(range_1.second) << endl;
	cout << "range_2: ";
	cout << *(range_2.first) << endl;
	cout << *(range_2.second) << endl;

	//fill
	std::vector<char> char_vec(30);
	fill(char_vec.begin(), char_vec.end(), '#');
	show_sequence< vector<char> >(char_vec);

	//
	std::map<char, char> my_map;
	for(int i = 0; i < 10; i++) my_map.insert(make_pair('$'+ i, '@'));
	show_associative_con<std::map<char, char> > (my_map);

	//fill_n: returns void c++11: returns iterator to sequence
	cout << "Before fill_n: ";
	show_sequence< vector<int> >(v_back_copy);
	fill_n(v_back_copy.end() - 7, 5, 44);//from where, how much, new value
	cout << "After fill_n: ";
	show_sequence< vector<int> >(v_back_copy);

	//find: returns iterator to the first element == val
	v_iter = find(v_back_copy.begin(), v_back_copy.end(), 44);
	cout << *v_iter << endl;

	//find_end: returns iterator to the first element
	//in the last appearence of the seq_2 in the seq_1
	std::vector<int> v_back_copy_3;
	for(int i = 4; i ; i--){
		my_list.push_back(5-i);
		my_list.push_front(i);
		v_back_copy_3.push_back(5-i);
	}
	cout << "my_list: ";
	show_sequence< list<int> >(my_list);
	cout << "v_back_copy_3: ";
	show_sequence< vector<int> >(v_back_copy_3);

	std::list<int>::iterator lst_iter;
	lst_iter = find_end(my_list.begin(), my_list.end(),\
						v_back_copy_3.begin(), v_back_copy_3.end());

	//distance: returns number of elements betwee two iterators
	cout << distance(v_back_copy.begin(), v_iter);
	cout << " elements between begin of the vector and element == 44" << endl;
	cout << "Last position of the v_back_copy_3 in the my_list is: ";
	cout << distance(my_list.begin(), lst_iter) << endl;

	//find_first_of: returns iterator to the first element
	//in the first appearence of the seq_2 in the seq_1
	lst_iter = find_first_of(my_list.begin(), my_list.end(),\
						v_back_copy_3.begin(), v_back_copy_3.end());
	cout << "First position of the v_back_copy_3 in the my_list is: ";
	cout << distance(my_list.begin(), lst_iter) << endl;

	//find_if: returns iterator to the firs element
	//!NOTE: find_if_not doesn't work! This is a question why?
	lst_iter = find_if(my_list.begin(), my_list.end(), unPred<int>);
	cout << "Position of the first element in the my_list == " << SIZE << ": ";
	cout << distance(my_list.begin(), lst_iter) << endl;

	//generate_n
	cout << "Before generate_n: ";
	show_sequence< vector<int> >(v_back_copy);
	generate_n(v_back_copy.begin(), 5, my_rand);//from where, how much, new value
	cout << "After generate_n: ";
	show_sequence< vector<int> >(v_back_copy);

	//includes: returns true if the range elements of the seq_2 is in the seq_1
	if(includes(my_list.begin(), my_list.end(),\
			 v_back_copy_3.begin(), v_back_copy_3.end()-2)){
		cout << \
		"my_list contains  elements from begin to end - 2 of v_back_copy_3" << endl;
	}

	return 0;
}