#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <typeinfo>
#include <cctype>

using namespace std;

namespace {
	const int SIZE = 7;
}


int my_rand() {
	static bool flag;
	if (!flag) {
		srand(time(NULL));
		flag = true;
	}
	return rand() % 100 +1;
}

template<class T>
void show_element(T const& ob) {
	cout << ob << " ";
}

template<class Sequence>
void show_sequence(Sequence const& sequence) {
	cout << endl;
	typedef typename Sequence::value_type T;
	//for_each: returns unPred's bool value
	if(!sequence.empty()) {
		for_each(sequence.begin(), sequence.end(), show_element<T>);
	} else cout << "Sequence is empty!";
	cout << endl;
}

template<typename K, typename V>
void show_c_element(pair <K, V> element) {
	cout << element.first << " - " << element.second << endl;
}

template<typename AC>
void show_associative_con(AC const& container) {
	cout << endl;
	typedef typename AC::mapped_type V;
	typedef typename AC::key_type K;
	for_each(container.begin(), container.end(), show_c_element<K, V>);
	cout << endl;
}

template<typename T>
bool unPred(T const& ob_1) {
	if (ob_1 < SIZE) return true;
	return false;
}

template<class T>
bool comparison(const T ob, const T ob_2) {
	if (ob < ob_2) return true;
	return false;
}

bool is_odd(int ob) {
	if (ob % 2 == 1) return true;
	return false;
}

int biPred(int a, int b) {
	return a*b;
}

template<typename T>
bool is_number(T ob)
{
	return typeid(ob) == typeid(int) ? true : false;
}

int main(int argc, char const *argv[]) {
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

	//copy_if
	std::vector<int> copy_vec, copy_vec2;
	for(int i = 0; i < 10; i++) {
		copy_vec.push_back(i);
		copy_vec2.push_back(0);
	}
	copy_if(copy_vec.begin(), copy_vec.end(), copy_vec2.begin(), is_odd);
	cout << "copy_vec2: ";
	show_sequence< vector<int> >(copy_vec2);

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

	//lower_bound, upper_bound
	range_2 = make_pair(lower_bound(my_list.begin(), my_list.end(), 5),\
	                    upper_bound(my_list.begin(), my_list.end(), 5));
	if (range_1 == range_2) cout << "We are find range with elements == 5" << endl;
	cout << "range_1: ";
	cout << *(range_1.first) << " ";
	cout << *(range_1.second) << endl;
	cout << "range_2: ";
	cout << *(range_2.first) << " ";
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
	for(int i = 4; i ; i--) {
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
	            v_back_copy_3.begin(), v_back_copy_3.end()-2)) {
		cout << \
		     "my_list contains  elements from begin to end - 2 of v_back_copy_3" << endl;
	}

	//inplace_merge: merges and sorts two sorted parts of one sequence
	//NOTE: faster than sort/stable_sort for the same case
	std::vector<char> v1, v2, v3;
	for(int i = 0; i < 10; i += 2) {
		v1.push_back('A'+i);
		v2.push_back('B'+ i);
	}
	cout << "v1: ";
	show_sequence< std::vector<char> >(v1);
	cout << "v2: ";
	show_sequence< std::vector<char> >(v2);
	v3.insert(v3.end(), v1.begin(), v1.end());
	v3.insert(v3.end(), v2.begin(), v2.end());
	cout << "v3 before inplace_merge: ";
	show_sequence< std::vector<char> >(v3);
	inplace_merge(v3.begin(), v3.begin()+(v1.size()), v3.end());
	cout << "v3 after inplace_merge: ";
	show_sequence< std::vector<char> >(v3);

	//iter_swap: returns void
	iter_swap(v3.begin(), v3.end() - 2);
	cout << "v3 after iter_swap first and before last elements: ";
	show_sequence< std::vector<char> >(v3);

	//lexicographical_compare: returns true if a first sequence less than a second
	string first_str = "Hello ";
	string second_str = "World!";
	result = lexicographical_compare(first_str.begin(), first_str.end(),\
	                                 second_str.begin(), second_str.end());
	if(result) cout << "The first_str are less the second_str" << endl;

	//make_heap: returns void
	//NOTE: to top[i] in a heap started with index[0]:
	//												  left element index == 2*i +1
	//												  right elemet index == 2*i +2
	std::vector<int> vec_to_heap(10, 0);
	generate_n(vec_to_heap.begin(), 10, my_rand);
	cout << "vec_to_heap: ";
	show_sequence< std::vector<char> >(v3);
	sort(vec_to_heap.begin(), vec_to_heap.end());
	cout << "vec_to_heap after sort: ";
	show_sequence< std::vector<int> >(vec_to_heap);
	make_heap(vec_to_heap.begin(), vec_to_heap.end());
	cout << "vec_to_heap after make_heap: ";
	show_sequence< std::vector<int> >(vec_to_heap);

	//COMPARE ELEMENTS: max, min, c++11: minmax: returns pair<min, max>
	int a, b;
	a = 5;
	b = 10;
	cout << "a = 5, b = 10" << endl;
	cout << "Max element: " << max(a, b) << endl;
	cout << "Min element: " << min(a, b) << endl;
	//Here returns element with less iterator (in fact compare iterators!)
	cout << "Iter: " << *(min(vec_to_heap.begin()+8, vec_to_heap.end()-5)) << endl;
	//cout << "Min element: " << (minmax(a, b)).first;

	//IN RANGE: min_element, max-element: returns iter to elem. c++11 minmax_element
	cout << *(min_element(vec_to_heap.begin(), vec_to_heap.end())) << endl;
	cout << *(max_element(vec_to_heap.begin(), vec_to_heap.end())) << endl;
	auto min_iter = (minmax_element(vec_to_heap.begin(), vec_to_heap.end())).first;
	auto max_iter = (minmax_element(vec_to_heap.begin(), vec_to_heap.end())).second;
	cout << "min: " << *min_iter << " & max: ";
	cout << *max_iter << " from minmax algorithm" << endl;


	//merge: ranges must be sorted
	std::vector<int> merge_vec;
	sort(vec_to_heap.begin(), vec_to_heap.end());
	std::vector<int> vec_to_heap_copy(10, 20);
	std::vector<int> result_vec(30, 11);

	cout <<"First vector: ";
	show_sequence< vector<int> >(vec_to_heap);
	cout <<"Second vector: ";
	show_sequence< vector<int> >(vec_to_heap_copy);
	cout <<"Result vector: ";
	show_sequence< vector<int> >(result_vec);
	merge(vec_to_heap.begin(), vec_to_heap.end(),\
	      vec_to_heap_copy.begin(), vec_to_heap_copy.end(), result_vec.begin());
	cout << "Result: ";
	show_sequence< vector<int> >(result_vec);
	cout << endl;

	//merge list
	my_list.sort();
	std::list<int> sec_list(my_list);
	std::list<int> res_list(100, 11);
	cout <<"First list: ";
	show_sequence< list<int> >(my_list);
	cout <<"Second list: ";
	show_sequence< list<int> >(sec_list);
	cout <<"Result list: ";
	show_sequence< list<int> >(res_list);
	merge(my_list.begin(), my_list.end(), sec_list.begin(), sec_list.end(), res_list.begin());
	cout << "Result: ";
	show_sequence< list<int> >(res_list);

	//mismatch: returns pair<val1, val2> of mismatches elements in two sequences
	std::vector<int> vec_to_heap_cc(vec_to_heap_copy);
	vec_to_heap_copy.insert(vec_to_heap_copy.end(), 66);
	for (int i = 30; i < 35; i++) vec_to_heap_cc.insert(vec_to_heap_cc.end(), i);
	show_sequence< vector<int> >(vec_to_heap_cc);

	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> mis_elements;
	mis_elements = mismatch(vec_to_heap_cc.begin(), vec_to_heap_cc.end(), \
	                        vec_to_heap_copy.begin());
	//NOTE: here is can be the iter == seq.end() if not mismatches before end of seq.
	cout << "Mismatched elements: " << endl;
	cout << *(mis_elements.first) << " from vec_to_heap_cc" << endl;
	cout << *(mis_elements.second) << " from vec_to_heap_copy" << endl;

	//nth_element: place only one element to sort position, less elements before &
	//greater elements after it. Returns void.
	std::vector<int> random_vec;
	for(int i = 0; i <= 15; i++) {
		random_vec.push_back(i);
	}
	cout << "random_vec before shuffle: ";
	show_sequence< vector <int> >(random_vec);

	//random_shuffle: mixed elements in random order
	random_shuffle(random_vec.begin(), random_vec.end());
	cout << "random_vec after shuffle: ";
	show_sequence< vector <int> >(random_vec);
	nth_element(random_vec.begin(),random_vec.begin() + 2 , random_vec.end());
	cout << "random_vec after nth_element with index 2: ";
	show_sequence< vector <int> >(random_vec);

	//partial_sort: returns void
	//partial_sort(first, middle, last)
	partial_sort(random_vec.begin(), random_vec.end()-5, random_vec.end());
	cout << "random_vec after partial_sort to the 10th element: ";
	show_sequence< vector <int> >(random_vec);
	random_shuffle(random_vec.begin(), random_vec.end());

	//partial_sort_copy: returns iter to upper_bound element after copied elements
	std::vector<int> random_vec_copy(random_vec);
	for(int i = 50; i <= 60; i++) {
		random_vec_copy.push_back(i);
	}
	random_shuffle(random_vec_copy.begin(), random_vec_copy.end());
	cout << "random_vec_copy: ";
	show_sequence< vector <int> >(random_vec_copy);
	partial_sort_copy(random_vec.begin(), random_vec.end() - 5, random_vec_copy.begin(),\
	                  random_vec_copy.end());
	cout << "random_vec_copy after partial_sort_copy random_vec[0, -5]: ";
	show_sequence< vector <int> >(random_vec_copy);

	//partition: all elements with unPred() == true will be before &
	// unPred() == false after element. Returns iter to first elem with unPred == false
	//stable_partition: same as partition, but + the order of the equal elements is saved
	cout << "random_vec before partition: ";
	show_sequence< vector <int> >(random_vec);
	nth_element(random_vec.begin(), random_vec.begin() + SIZE, random_vec.end());
	partition(random_vec.begin(), random_vec.end(), unPred<int>);
	cout << "random_vec after partition with unPred: ";
	show_sequence< vector <int> >(random_vec);

	//is_partitioned: returns true if the sequense partitioned with unPred c++11
	if(is_partitioned(random_vec.begin(), random_vec.end(), unPred<int>)) {
		cout << "random_vec is partitioned with unPred";
	}

	//next_permutation, prev_permutation, returns true if next/previous permutation
	//lexicographically greater (or used unPred) than previous/next.
	std::vector<char> perm_vec;
	for (int i = 0; i < 3; i++) {
		perm_vec.push_back('C' - i);
	}
	//random_shuffle(perm_vec.begin(), perm_vec.end());

	do {
		show_sequence< vector<char> >(perm_vec);
	} while(prev_permutation(perm_vec.begin(), perm_vec.end()));

	//pop_heap, push_heap, sort_heap: returns void
	make_heap(vec_to_heap.begin(), vec_to_heap.end());
	cout << "vec_to_heap: ";
	show_sequence< std::vector<int> >(vec_to_heap);
	pop_heap(vec_to_heap.begin(), vec_to_heap.end());
	vec_to_heap.pop_back();
	cout << "vec_to_heap after pop-heap & .pop_back(): ";
	show_sequence< std::vector<int> >(vec_to_heap);
	vec_to_heap.push_back(120);
	push_heap(vec_to_heap.begin(), vec_to_heap.end());
	cout << "vec_to_heap after .push_back(120) & push_heap: ";
	show_sequence< std::vector<int> >(vec_to_heap);
	sort_heap(vec_to_heap.begin(), vec_to_heap.end());
	cout << "vec_to_heap after sort_heap: ";
	show_sequence< std::vector<int> >(vec_to_heap);

	//remove, remove_if : returns iter to begin of deleted elements or "garbage"
	//(NOTE: really remove only copied elements to the end of sequence)
	std::vector<int> rem_vec;
	for(int i = 0; i < 10; i++) rem_vec.push_back(i);
	cout << "rem_vec: ";
	show_sequence< std::vector<int> >(rem_vec);
	//Useful variant:
	remove(rem_vec.begin(), rem_vec.end(), 4);
	rem_vec.pop_back();
	cout << "rem_vec after removing 4 + .pop_back(): ";
	show_sequence< std::vector<int> >(rem_vec);
	//!!!Best practice:!!!
	rem_vec.erase(remove_if(rem_vec.begin(), rem_vec.end(), is_odd), rem_vec.end());
	cout << "rem_vec after removing + erasing odd elements: ";
	show_sequence< std::vector<int> >(rem_vec);

	//remove_copy
	std::vector<int> rem_vec2;
	for(int i = 0; i < 10; i++) rem_vec2.push_back(i);
	remove_copy(rem_vec.begin(), rem_vec.end()-2, rem_vec2.begin()+2, 10);
	cout << "rem_vec2 after remove_copy all elements except the last of rem_vec: ";
	show_sequence< std::vector<int> >(rem_vec2);

	//remove_copy_if
	std::vector<int> rem_vec3(10, 0);
	remove_copy_if(rem_vec2.begin(), rem_vec2.end(),rem_vec3.begin(), is_odd);
	cout << "rem_vec3 after remove_copy_if all even elements from rem_vec2: ";
	show_sequence< std::vector<int> >(rem_vec3);

	/*NOTE THE MAIN THING ABOUT COPY_IF VS REMOVE_COPY_IF:
	1. 'Copy_if' - copies items to the sequense EXCEPT of elements with unPred == false;
	or another words copies all items with unPred == true will be copied;
	2. 'Remove_copy_if' - copies items to the sequense EXCEPT of
	elements with unPred == true;
	*/

	//replace, replace_if: returns void
	std::list<int> rep_list1, rep_list2, rep_list3;
	for(int i = 1; i < 13; i++) {
		rep_list1.push_back(i);
		rep_list1.push_back(0);
		rep_list2.push_back(10 + i);
		rep_list2.push_back(22);
		rep_list3.push_back(20 + i);
		rep_list3.push_back(30 + i);
		rep_list3.push_back(40 + i);

	}
	cout << "rep_list1: ";
	show_sequence< list<int> >(rep_list1);
	replace(rep_list1.begin(), rep_list1.end(), 0, 98);
	cout << "rep_list1 after replace all items == 0 to 99: ";
	show_sequence< list<int> >(rep_list1);
	replace_if(rep_list1.begin(), rep_list1.end(), is_odd, 33);
	cout << "rep_list1 after replace_if all odd items to 33: ";
	show_sequence< list<int> >(rep_list1);

	//replace_copy, replace_copy_if: returns iterator to element after last copied tiem
	//copy elements + replace old to new in copied item's sequence
	cout << "rep_list2: ";
	show_sequence< list<int> >(rep_list2);
	cout << "rep_list3: ";
	show_sequence< list<int> >(rep_list3);
	replace_copy(rep_list2.begin(), rep_list2.end(), rep_list3.begin(), 22, 77);
	cout << "rep_list3 after replace_copy elements of rep_list2 and replace ";
	cout << "all items == 22 to 77";
	show_sequence< list<int> >(rep_list3);
	replace_copy_if(rep_list2.begin(), rep_list2.end(), rep_list2.begin(), is_odd, 0);
	cout << "rep_list2 after replace_copy_if elements and replace odd items to 0";
	show_sequence< list<int> >(rep_list2);

	//reverse: returns void, reverse_copy: returns iterator to item after last copied
	std::vector<char> revers_vec, revers_vec2;
	for (int i = 0; i < 10; i++) {
		revers_vec.push_back('A' + i);
		revers_vec2.push_back('D');
	}
	cout << "revers_vec:";
	show_sequence< vector<char> >(revers_vec);
	reverse(revers_vec.begin(), revers_vec.end());
	cout << "revers_vec after reverse:";
	show_sequence< vector<char> >(revers_vec);
	reverse_copy(revers_vec.begin(), revers_vec.end(), revers_vec2.begin());
	cout << "revers_vec2 after reverse_copy from revers_vec:";
	show_sequence< vector<char> >(revers_vec2);
	reverse(revers_vec2.begin(), revers_vec2.begin() + 6);
	cout << "revers_vec after reverse first 6 elements:";
	show_sequence< vector<char> >(revers_vec2);

	//rotate, rotate_copy: returns (first + (last - n_first)) since c++11 before: void
	std::vector<int> rotate_vec, rotate_vec2(10,0);
	for(int i = 0; i < 10; i++) {
		rotate_vec.push_back(i);
	}
	cout << "rotate_vec:";
	show_sequence< vector<int> >(rotate_vec);
	rotate(rotate_vec.begin(), rotate_vec.begin() + 3, rotate_vec.end());
	cout << "rotate_vec after rotate to 3 items left: ";
	show_sequence< vector<int> >(rotate_vec);
	rotate(rotate_vec.rbegin(), rotate_vec.rbegin() + 3, rotate_vec.rend());
	cout << "rotate_vec after rotate to 3 items right: ";
	show_sequence< vector<int> >(rotate_vec);
	rotate_copy(rotate_vec.begin(), rotate_vec.begin() + 5,\
	            rotate_vec.end(), rotate_vec2.begin());
	cout << "rotate_vec2 after rotate_copy to 5 items left form rotate_vec: ";
	show_sequence< vector<int> >(rotate_vec2);

	//search: returns true if element in sequence
	v_iter = search(rotate_vec2.begin(), rotate_vec2.begin()+5, rotate_vec.begin()+5,\
	                rotate_vec.end());
	if(v_iter != rotate_vec2.begin()+5) {
		cout << "first part of rotate_vec2 == second part of rotate_vec" << endl;
	}

	//search_n: iterator for the first element of aim sequense, or last
	for(int i =0; i < 3; i++) {
		rotate_vec2.push_back(1);
	}
	v_iter = search_n(rotate_vec2.begin(), rotate_vec2.end(), 3, 1);
	//(start, end, count, &val)
	if (v_iter != rotate_vec2.end()) cout << "We find three items == 1 in rotate_vec2: ";
	cout << *(v_iter) << " " << *(v_iter + 1) << " " << *(v_iter + 2) << endl;
	v_iter = search_n(rotate_vec2.begin(), rotate_vec2.end(), 3, 4, std::greater<int>());
	//(start, end, count, &val, biPred)
	if (v_iter != rotate_vec2.end()) {
		cout << "We find two sequent odd items in rotate_vec2: ";
	}
	cout << *(v_iter) << " " << *(v_iter + 1);

	//set_difference: returns iterator past the end of the constructed range
	std::vector<int> sd_vec, sd_vec1, sd_vec_result(10, 0), sd_vec_result2(10,0);
	sd_vec = {1, 3, 3, 5, 6, 7, 8};
	sd_vec1 = {1, 2, 2, 3, 4, 5};
	cout << "sd_vec: ";
	show_sequence< vector<int> >(sd_vec);
	cout << "sd_vec1: ";
	show_sequence< vector<int> >(sd_vec1);
	cout << "sd_vec_result before any changes: ";
	show_sequence< vector<int> >(sd_vec_result);
	set_difference(sd_vec.begin(), sd_vec.end(), sd_vec1.begin(), sd_vec1.end(),\
	               sd_vec_result.begin());
	cout << "sd_vec_result after set_difference of sd_vec & sd_vec1: ";
	show_sequence< vector<int> >(sd_vec_result);

	//set_difference: returns iterator past the end of the constructed range
	set_symmetric_difference(sd_vec.begin(), sd_vec.end(), sd_vec1.begin(),\
	                         sd_vec1.end(), sd_vec_result.begin());
	cout << "sd_vec_result after set_symmetric_difference of sd_vec & sd_vec1: ";
	show_sequence< vector<int> >(sd_vec_result);

	//set_intersection: iterator past the end of the constructed range
	set_intersection(sd_vec.begin(), sd_vec.end(), sd_vec1.begin(),\
	                 sd_vec1.end(), sd_vec_result2.begin());
	cout << "sd_vec_result2 after set_intersection of sd_vec & sd_vec1: ";
	show_sequence< vector<int> >(sd_vec_result2);

	//set_union: iterator past the end of the constructed range
	std::vector<int> union_vec(20, 0);
	set_union(sd_vec.begin(), sd_vec.end(), sd_vec1.begin(),\
	          sd_vec1.end(), union_vec.begin());
	cout << "union_vec after set_union of sd_vec & sd_vec1: ";
	show_sequence< vector<int> >(union_vec);

	//stable_sort: returns void. Ensure order of the same adjacent items
	random_shuffle(union_vec.begin(), union_vec.end());
	cout << "union_vec after random_shuffle: ";
	show_sequence< vector<int> >(union_vec);
	stable_sort(union_vec.begin(), union_vec.end());
	cout << "union_vec after stable_sort: ";
	show_sequence< vector<int> >(union_vec);

	//swap: returns void
	swap(union_vec[10], union_vec[11]);
	cout << "union_vec after swap items [10] & [11]: ";
	show_sequence< vector<int> >(union_vec);

	//swap_ranges: returns iterator to the item past the last in the aim sequence
	swap_ranges(union_vec.begin(), union_vec.begin() + 10, union_vec.begin() + 10);
	cout << "union_vec after swap range [0-10) & [10-end): ";
	show_sequence< vector<int> >(union_vec);

	//transform: returns iterator past the last transformed
	std::vector<int> trans_vec0(20, 2);
	cout << "trans_vec0: ";
	show_sequence< vector<int> >(trans_vec0);
	transform(union_vec.begin(), union_vec.end(), trans_vec0.begin(),\
	[](int a) {
		return a*2;
	});
	cout << "trans_vec0 after transform union_vec items*2: ";
	show_sequence< vector<int> >(trans_vec0);

	//transform biPred version: returns iterator past the last transformed
	std::vector<int> trans_vec, trans_vec2, trans_vec_res(10, 0);
	for(int i = 1; i < 11; i++) {
		trans_vec.push_back(i);
		trans_vec2.push_back(i+1);
	}
	cout << "trans_vec: ";
	show_sequence< vector<int> >(trans_vec);
	cout << "trans_vec2: ";
	show_sequence< vector<int> >(trans_vec2);
	transform(trans_vec.begin(), trans_vec.end(), trans_vec2.begin(),\
	trans_vec_res.begin(), [](int a, int b) {
		return a*b;
	});
	//(first, last, first2, res_seq, biPred(a, b));
	cout << "trans_vec_res trans_vec*trans_vec2: ";
	show_sequence< vector<int> >(trans_vec_res);

	//unique: returns iterator to the end of the new range. Sequence must be sorted!!!
	sort(trans_vec0.begin(), trans_vec0.end());
	cout << "trans_vec0: ";
	show_sequence< vector<int> >(trans_vec0);
	/*trans_vec0.erase(unique(trans_vec0.begin(), trans_vec0.end()), trans_vec0.end());
	cout << "trans_vec0 after unique function: ";
	show_sequence< vector<int> >(trans_vec0);*/

	std::list<int> uni_list(20, 0), uni_list2(20, 0), uni_list3(20, 0);
	copy(trans_vec0.begin(), trans_vec0.end(), uni_list.begin());
	auto unilist_ptr = unique(uni_list.begin(), uni_list.end());
	uni_list.erase(unilist_ptr, uni_list.end());
	show_sequence< list<int> >(uni_list);

	//unique_copy: returns iterator to the end of the new range.
	//Sequence must be sorted!!!
	copy(trans_vec0.begin(), trans_vec0.end(), uni_list2.begin());
	cout << "uni_list2: ";
	show_sequence< list<int> >(uni_list2);
	cout << "uni_list3: ";
	show_sequence< list<int> >(uni_list3);
	unique_copy(uni_list2.begin(), uni_list2.end(), uni_list3.begin());
	cout << "uni_list3 after unique_copy from uni_list2: ";
	show_sequence< list<int> >(uni_list3);

	//C++ 11 new algorithms

	//all_of, any_of, none_of: returns bool
	result = all_of(uni_list.begin(), uni_list.end(), is_number<int>);
	if (result) cout << "All items in uni_list are numbers!" << endl;

	result = any_of(union_vec.begin(), union_vec.end(), is_odd);
	if (result) cout << "Some items in union_vec are odd numbers!" << endl;

	result = none_of(uni_list.begin(), uni_list.end(),\
					 [](int a){if(a > 1000) return true; return false;});
	if (result) cout << "None of items in uni_list are greater than 1000!" << endl;

	//find_if_not
	v_iter = find_if_not(trans_vec0.begin(), trans_vec0.end(),\
							[](int x){return x <= 6 ? true : false;});
	cout << "First item is not less or equal than 6 in trans_vec0 is: " << *v_iter;
	cout << endl;

	//copy_n: returns iterator past the last copied if count > 0, else first
	std::vector<int> cn_vec(10, 0);
	copy_n(uni_list3.begin(), 4, cn_vec.begin());
	cout << "cn_vec after copy_n 4 elements from uni_list3: ";
	show_sequence< vector<int> >(cn_vec);

	//move: returns an iterator to the last item in the aim sequence
	move(uni_list3.begin(), uni_list3.end(), std::back_inserter(cn_vec));
	cout << "cn_vec after add uni_list3 to the end with back_inserter(v): ";
	show_sequence< vector<int> >(cn_vec);

	//partition_point: returns an iterator to the last element in the first part
	//of the partitioned range
	//NOTE: range MUST be partitioned!!!
	std::vector<int> pp_vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	partition(pp_vec.begin(), pp_vec.end(), is_odd);
	auto pp_iter = partition_point(pp_vec.begin(), pp_vec.end(), is_odd);
	std::copy(pp_vec.begin(), pp_iter, ostream_iterator<int>(std::cout, " "));
	cout << endl;
	std::copy(pp_iter, pp_vec.end(), ostream_iterator<int>(std::cout, " "));

	//is_sorted: returns true if sequence is sorted
	sort(pp_vec.begin(), pp_vec.end());
	result = is_sorted(pp_vec.begin(), pp_vec.end());
	if(result){
		cout << endl << "pp_vec is_soted: ";
		show_sequence< vector<int> >(pp_vec);
	}

	//is_sorted_until: returns iterator upper_bound to sorted part of range
	pp_vec.emplace_back(1);
	pp_vec.emplace_back(7);
	auto iss_iter = is_sorted_until(pp_vec.begin(), pp_vec.end());
	if(result){
		cout << "last sorted element: " << *(iss_iter - 1);
		show_sequence< vector<int> >(pp_vec);
	}

	//is_permutation: returns true if aim range is permutation of the init range
	std::vector<int> isp_vec;
	rotate_copy(pp_vec.begin(), pp_vec.begin() + 3, pp_vec.end(),\
													std::back_inserter(isp_vec));
	result = is_permutation(pp_vec.begin(), pp_vec.end(),\
									isp_vec.begin(), isp_vec.end());
	if(result){
		cout << "isp_vec: ";
		show_sequence< vector<int> >(isp_vec);
		cout << "is a permutation of pp_vec: ";
		show_sequence< vector<int> >(pp_vec);
	}

	//iota: returns void
	//NOTE: REQUIRE #include <numeric>
	std::vector<int> iota_vec(10, 0);
	std::iota(iota_vec.begin(), iota_vec.end(), -5);
	cout << "iota_vec is filled with algorithm iota with start parameter == -5: ";
	copy(iota_vec.begin(), iota_vec.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	return 0;
}
