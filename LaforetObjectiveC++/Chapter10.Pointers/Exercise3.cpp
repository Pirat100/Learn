#include <iostream>
#include <cstring>

using namespace std;

const int DAYS = 7;

int main()
{
	void bsort(char**, int);
	char* arrptrs[DAYS] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};

	cout << "Неупорядоченный по алфавиту список дней недели: \n";
	for (int j = 0; j < DAYS; ++j) {
		cout << arrptrs[j] << endl;
	}

	bsort(arrptrs, DAYS);

	cout << "\nУпорядоченный по алфавиту список дней недели: \n";
	for (int j = 0; j < DAYS; ++j) {
		cout << arrptrs[j] << endl;
	}

    return 0;
}

void bsort(char** pp, int size) {
	void order(char**, char**);
	for (int j = 0; j < size - 1; ++j) {
		for (int k = j + 1; k < size; ++k) {
			order(pp + j, pp + k);
		}
	}
}

void order (char** pp1, char** pp2) {
	if (strcmp(*pp1, *pp2) > 0) {
		char* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
