#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DictElement
{
public:
	string language;
	DictElement(){language = "english";}
	DictElement(string lang){language = lang;}
	virtual ~DictElement(){}
	virtual void info() = 0;
};

class Word : public DictElement
{
public:
	string word;
	Word(){word = "word_here";}
	Word(string input){word = input;}
	Word(string input, string lang) : DictElement(lang){word = input;}
	~Word(){}
	void info();
	bool operator < (const Word obj_2);

	friend bool operator > (const Word obj_1, const Word obj_2);
	friend bool operator < (const Word obj_1, const Word obj_2);
	friend bool operator == (const Word obj_1, const Word obj_2);
	friend bool operator >= (const Word obj_1, const Word obj_2);
	friend bool operator <= (const Word obj_1, const Word obj_2);
};

void Word::info()
{
	cout << "Word: " << word << endl;
	cout << "Language: " << language << endl;
}

bool Word::operator < (const Word obj_2)
{
	if (word < obj_2.word) return true;
	return false;
}

bool operator > (const Word obj_1, const Word obj_2)
{
	if (obj_1.word > obj_2.word) return true;
	return false;
}
bool operator < (const Word obj_1, const Word obj_2)
{
	if (obj_1.word < obj_2.word) return true;
	return false;
}
bool operator == (const Word obj_1, const Word obj_2)
{
	if (obj_1.word == obj_2.word) return true;
	return false;
}
bool operator >= (const Word obj_1, const Word obj_2)
{
	if (obj_1.word >= obj_2.word) return true;
	return false;
}
bool operator <= (const Word obj_1, const Word obj_2)
{
	if (obj_1.word <= obj_2.word) return true;
	return false;
}

class Definition : public DictElement
{
public:
	string definition;
	Definition(){definition = "def_here";}
	Definition(string input){definition = input;}
	Definition(string input, string lang) : DictElement(lang){definition = input;}
	~Definition(){}
	void info();
	bool operator < (const Definition obj_2);

	friend bool operator > (const Definition obj_1, const Definition obj_2);
	friend bool operator < (const Definition obj_1, const Definition obj_2);
	friend bool operator == (const Definition obj_1, const Definition obj_2);
	friend bool operator >= (const Definition obj_1, const Definition obj_2);
	friend bool operator <= (const Definition obj_1, const Definition obj_2);
};

void Definition::info()
{
	cout << "Definition: " << definition << endl;
}

bool Definition :: operator < (const Definition obj_2)
{
	if (definition < obj_2.definition) return true;
	return false;
}

bool operator > (const Definition obj_1, const Definition obj_2)
{
	if (obj_1.definition > obj_2.definition) return true;
	return false;
}
bool operator < (const Definition obj_1, const Definition obj_2)
{
	if (obj_1.definition < obj_2.definition) return true;
	return false;
}
bool operator == (const Definition obj_1, const Definition obj_2)
{
	if (obj_1.definition == obj_2.definition) return true;
	return false;
}
bool operator >= (const Definition obj_1, const Definition obj_2)
{
	if (obj_1.definition >= obj_2.definition) return true;
	return false;
}
bool operator <= (const Definition obj_1, const Definition obj_2)
{
	if (obj_1.definition <= obj_2.definition) return true;
	return false;
}

void show_element(pair<Word, Definition> element)
{
	element.first.info();
	element.second.info();
}

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

	//Create objects to dictionary
	map<Word, Definition> dictionary;

	Word fork("fork", "english");
	Word knife("knife", "english");
	Word spoon("spoon", "english");
	
	Definition fork_def("a small object with three or four points and a handle, that you use to pick up food and eat");
	Definition knife_def("a tool, usually with a metal blade and a handle, used for cutting and spreading food or other substances, or as a weapon");
	Definition spoon_def("an object consisting of a round, hollow part and a handle, used for mixing, serving, and eating food");

	dictionary.insert(make_pair(fork, fork_def));
	dictionary.insert(make_pair(knife, knife_def));
	dictionary.insert(make_pair(spoon, spoon_def));

	for_each(dictionary.begin(), dictionary.end(), show_element);

	return 0;
}