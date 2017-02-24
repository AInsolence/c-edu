#include <iostream>

#include <cstdlib>

using namespace std;



int main()

{

　int magic; // магическое число

　int guess; // вариант пользователя

　magic = rand(); // Получаем случайное число.

　do {

　　cout << "Введите свой вариант магического числа: ";

　　　cin >> guess;

　　if(guess == magic) {

　　　cout << "** Правильно ** ";

　　　cout << magic <<" и есть то самое магическое число.\n";

　　}

　　else {

　　　cout << "...Очень жаль, но вы ошиблись.";

　　　if(guess > magic)

　　　　cout <<" Ваш вариант превышает магическое число.\n";

　　　else cout <<" Ваш вариант меньше магического числа.\n";

　　}

　}while(guess != magic);

　return 0;

}
