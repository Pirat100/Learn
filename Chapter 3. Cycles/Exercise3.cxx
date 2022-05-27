#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    cout << "Введите число: ";
    char ch = 'a';
    string result = "";
    while (ch != '\n') {
        ch = getche();
        result += ch;
    }
    long number = stol(result);
    cout << "Вы ввели число " << number << endl;
	return 0;
}