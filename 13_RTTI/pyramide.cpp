#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
class Pyramide
{
public:
	int levels;
	T cell;
	Pyramide(T ch);
	Pyramide(T ch, int i);
	~Pyramide(){}
	void show_pyramide();
	template<class F> // NOTE THIS STRING HERE WE declare 
					  // friends as template funcs
	friend ostream& operator << (ostream& stream, Pyramide<F> &object);
};

template<class T>
Pyramide<T>::Pyramide(T ch) // NOTE HOW TO DECLARE CLASS MEMBERS IN TEMPLATE CLASSES
{
	levels = 3;
	cell = ch;
}

template<class T>
Pyramide<T>::Pyramide(T ch, int i)
{
	levels = i;
	cell = ch;
}

template<class T>
ostream& operator << (ostream& stream, Pyramide<T> &object)
{
	stream << object.cell << '!';
	return stream;
}

template<class T>
void Pyramide<T>::show_pyramide()
{
	int num = 1;
	for (int j = 0; j <= levels; j++){
		for (int i = 1; i < num; i ++){
			cout << cell;
		}
		cout << endl;
		num++;
	}
}

int main(int argc, char const *argv[])
{
	char temp;
	cout << "Enter character to fill a pyramide\n";
	 cin >> temp;
	Pyramide<char> object(temp, 5);
	object.show_pyramide();
	cout << typeid(object).name() << endl;
	cout << object << endl;

	Pyramide<int> object_2(3);
	cout << typeid(object_2).name() << endl;
	return 0;
}