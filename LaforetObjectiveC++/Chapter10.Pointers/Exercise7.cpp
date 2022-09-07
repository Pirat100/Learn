#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	float salary;
public:
	void setData() {
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите зарплату: ";
		cin >> salary;
	}

	void printData() {
		cout << endl << "Имя: " << name << ", зарплата: " << salary;
	}

	string getName() {
		return name;
	}

	float getSalary() {
		return salary;
	}
};

int main()
{
	void bsort(Person**, int);
	void salsort(Person**, int);
	Person* persPtr[100];
	int n = 0;
	char choice;

	do {
		persPtr[n] = new Person;
		persPtr[n]->setData();
		++n;
		cout << "Продолжаем ввод (y/n)?";
		cin >> choice;
	} while (choice == 'y');
	cout << "\nНеотсортированный список:";
	for (int j = 0; j < n; ++j) {
		persPtr[j]->printData();
	}

	salsort(persPtr, n);

	cout << "\nОтсортированный список:";
	for (int j = 0; j < n; ++j) {
		persPtr[j]->printData();
	}
	cout << endl;

    return 0;
}

void bsort(Person** pp, int n) {
	void orderName(Person**, Person**);
	int j, k;

	for (j = 0; j < n - 1; ++j) {
		for (k = j + 1; k < n; ++k) {
			orderName(pp + j, pp + k);
		}
	}
}

void orderName(Person** pp1, Person** pp2) {
	if ((*(*pp1)).getName() > (*(*pp2)).getName()) {
		Person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}

void salsort(Person** pp, int n) {
	int j, k;

	for (j = 0; j < n - 1; ++j) {
		for (k = j + 1; k < n; ++k) {
			if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
				Person* tempPtr = *(pp + j);
				*(pp + j) = *(pp + k);
				*(pp + k) = tempPtr;
			}
		}
	}
}


