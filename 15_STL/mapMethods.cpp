#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	map<char, int> alphabet;
	cout << (int)'A';
	for (int i = 0; i < 26; i++){
		alphabet.insert(make_pair('A'+i, 65+i));
	}

	cout << alphabet['A'] << endl;
	cout << alphabet['Z'] << endl;
	cout << alphabet['a'] << endl;

	std::map<char,int>::iterator map_ptr = alphabet.find('A');
	alphabet.erase('A');
	map_ptr = alphabet.find('A');
	if(map_ptr == alphabet.end()){
		cout << "There is no key 'A' in map" << endl;
	} 
	alphabet.insert(pair<char, int>('A', 100));
	cout << "Now 'A' value is " << alphabet['A'] << endl;
	cout << alphabet.count('A') << endl;

	cout << alphabet.count('b') << endl;
	cout << alphabet['b'] << endl;

	map_ptr = alphabet.find('b');
	if(map_ptr == alphabet.end()){
		cout << "There is no key 'b' in map" << endl;
	}

	std::vector<int> lowercase_values;
	lowercase_values.reserve(26);
	cout << endl << endl;
	for (int j = 0; j < 26; j++){
		lowercase_values.push_back(126+j);
		alphabet['a'+j] = lowercase_values[j];
		cout << alphabet['A'+j] << " "; //Here in output for key 'A'
									// we'll see 100 cause we change it before
		cout << alphabet['a'+j] << " ";
	}
	cout << endl;

	map<char, int> second_map;
	cout << second_map.empty() << endl;
	second_map.swap(alphabet);//Swap & insert works only
							//with another *map* as argument
	cout << alphabet.empty() << endl;
	map<char, int> third_map(second_map);// Init with another map
	cout << third_map.empty() << endl;
	//Work with pair struct as element of the map
	map_ptr = third_map.find('z');
	cout << "'" << map_ptr->first << "'";
	cout << " value is ";
	cout << map_ptr->second;//Cause of struct *pair* has
							//'first' as name to key &
							//'second' as name to value
	//Get all keys and collect it in vector
	map<int, int> m;
	for (int i = 0; i < 26; i++){
		m.insert(make_pair(i, 65+i));
	}
	vector<int> v;
	for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
		v.push_back(it->first);
		cout << it->first << "\n";
	}


	return 0;
}