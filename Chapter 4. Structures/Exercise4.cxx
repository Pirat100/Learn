#include <iostream>

using namespace std;

struct employee {
	int id;
	float salary;
};

int main()
{
	employee employee1;
	employee employee2;
	employee employee3;
	cout << "Введите номер первого сотрудника и его пособие: ";
	cin >> employee1.id >> employee1.salary;
    cout << "Введите номер второго сотрудника и его пособие: ";
	cin >> employee2.id >> employee2.salary;
	cout << "Введите номер третьего сотрудника и его пособие: ";
	cin >> employee3.id >> employee3.salary;
	cout << "Номер первого сотрудника и его пособие: " << employee1.id << ' ' << employee1.salary << endl;
	cout << "Номер второго сотрудника и его пособие: " << employee2.id << ' ' << employee2.salary << endl;
	cout << "Номер третьего сотрудника и его пособие: " << employee3.id << ' ' << employee3.salary << endl;
	return 0;
}