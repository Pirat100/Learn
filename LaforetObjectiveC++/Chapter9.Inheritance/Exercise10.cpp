#include <iostream>

using namespace std;

const int LEN = 80;

class Student {
private:
	char school[LEN];
	char degree[LEN];
public:
	void getEdu() {
		cout << "Введите название учебного заведения: ";
		cin >> school;
		cout << "Введите степень высшего образования (неполное высшее, бакалавр, магистр, кандидат наук): ";
		cin >> degree;
	}

	void putEdu() const {
		cout << "Учебное заведение: " << school;
		cout << " Степень: " << degree << endl;
	}
};

class Employee {
private:
	char name[LEN];
	unsigned long number;
public:
	void getData() {
		cout << "Введите фамилию: ";
		cin >> name;
		cout << "Введите номер: ";
		cin >> number;
	}

	void putData() const {
		cout << "Фамилия: " << name;
		cout << " Номер: " << number << endl;
	}
};

class Manager : private Employee, private Student {
private:
	char title[LEN];
	double dues;
public:
	void getData() {
		Employee::getData();
		cout << "Введите должность: ";
		cin >> title;
		cout << "Введите сумму взносов в гольф-клуб: ";
		cin >> dues;
		Student::getEdu();
	}

	void putData() const {
		Employee::putData();
		cout << "Должность: " << title;
		cout << " Взносы в гольф-клуб: " << dues << endl;
		Student::putEdu();
	}
};

class Executive : private Manager {
private:
	double bonus;
	int stocks;
public:
	void getData() {
		Manager::getData();
		cout << "Введите размер годовой премии управляющего: ";
		cin >> bonus;
		cout << "Введите количество акций: ";
		cin >> stocks;
	}

	void putData() const {
		Manager::putData();
		cout << "Размер годовой премии составляет: " << bonus;
		cout << " Количество акций: " << stocks << endl;
	}
};

int main() {
	Executive e;
	e.getData();
	e.putData();
	return 0;
}


