#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void reversit(char chars[]);

int main() {
    const int MAX = 1000;
    char chars[MAX];
    cout << "Введите строку: ";
    cin.get(chars, MAX);
    cout << "Вы ввели: " << chars << endl;
    reversit(chars);
    cout << "Перевернутая строка: " << chars << endl;
	return 0;
}

void reversit(char chars[]) {
	int len = strlen(chars);
	for(int i = 0; i < len / 2; ++i) {
	    char temp = chars[len - i - 1];
	    chars[len - i - 1] = chars[i];
	    chars[i] = temp;
	}
}


