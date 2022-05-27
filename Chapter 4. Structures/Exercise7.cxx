#include <iostream>

using namespace std;

enum Etype { laborer, secretary, manager, accountant, executive, researcher };

struct Date {
	int day;
	int month;
	int year;
};

struct Employee {
	int id;
	float salary;
	Etype etype;
	Date date;
};

int main()
{
	Employee employee1;
	Employee employee2;
	Employee employee3;
	char ch = 'a';
	Etype etype;
	cout << "Введите номер первого работника, его зарплату, должность и дату принятия на работу: ";
    cin >> employee1.id >> employee1.salary >> 
    ch >> employee1.date.day >> 
    employee1.date.month >> employee1.date.year;
    switch (ch) {
		case 'a': employee1.etype = accountant; break;
		case 'e': employee1.etype = executive; break;
		case 'l': employee1.etype = laborer; break;
		case 'm': employee1.etype = manager; break;
		case 'r': employee1.etype = researcher; break;
		case 's': employee1.etype = secretary; break;
	}
    cout << "Введите номер второго работника, его зарплату, должность и дату принятия на работу: ";
    cin >> employee2.id >> employee2.salary >> 
    ch >> employee2.date.day >> 
    employee2.date.month >> employee2.date.year;
    switch (ch) {
		case 'a': employee2.etype = accountant; break;
		case 'e': employee2.etype = executive; break;
		case 'l': employee2.etype = laborer; break;
		case 'm': employee2.etype = manager; break;
		case 'r': employee2.etype = researcher; break;
		case 's': employee2.etype = secretary; break;
	}
	cout << "Введите номер третьего работника, его зарплату, должность и дату принятия на работу: ";
    cin >> employee3.id >> employee3.salary >> 
    ch >> employee3.date.day >> 
    employee3.date.month >> employee3.date.year;
    switch (ch) {
		case 'a': employee3.etype = accountant; break;
		case 'e': employee3.etype = executive; break;
		case 'l': employee3.etype = laborer; break;
		case 'm': employee3.etype = manager; break;
		case 'r': employee3.etype = researcher; break;
		case 's': employee3.etype = secretary; break;
	}
    
    cout << "Номер первого работника " << employee1.id 
    << ", его зарплата равна " << employee1.salary 
    << " доллара, его должность ";
    switch (employee1.etype) {
	    case 0: cout << "laborer" << endl; break;
	    case 1: cout << "secretary" << endl; break;
	    case 2: cout << "manager" << endl; break;
	    case 3: cout << "accountant" << endl; break;
	    case 4: cout << "executive" << endl; break;
	    case 5: cout << "researcher" << endl; break;
	}
    cout << " с датой принятия на работу " << employee1.date.day << employee1.date.month << employee1.date.year << endl;
    cout << "Номер второго работника " << employee2.id 
    << ", его зарплата равна " << employee2.salary 
    << " доллара, его должность ";
    switch (employee2.etype) {
	    case 0: cout << "laborer" << endl; break;
	    case 1: cout << "secretary" << endl; break;
	    case 2: cout << "manager" << endl; break;
	    case 3: cout << "accountant" << endl; break;
	    case 4: cout << "executive" << endl; break;
	    case 5: cout << "researcher" << endl; break;
	}
    cout << " с датой принятия на работу " << employee2.date.day << employee2.date.month << employee2.date.year << endl;
    cout << "Номер третьего работника " << employee3.id 
    << ", его зарплата равна " << employee3.salary 
    << " доллара, его должность ";
    switch (employee3.etype) {
	    case 0: cout << "laborer" << endl; break;
	    case 1: cout << "secretary" << endl; break;
	    case 2: cout << "manager" << endl; break;
	    case 3: cout << "accountant" << endl; break;
	    case 4: cout << "executive" << endl; break;
	    case 5: cout << "researcher" << endl; break;
	}
     cout << " с датой принятия на работу " << employee3.date.day << employee3.date.month << employee3.date.year << endl;
    return 0;
}