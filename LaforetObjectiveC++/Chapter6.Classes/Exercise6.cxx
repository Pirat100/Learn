#include <iostream>

using namespace std;

enum etype { accountant, labour, manager, researcher, secretary, teacher };

class date {
private:
	int day;
	int month;
	int year;
	
public:
    date() : day(1), month(1), year(1) { }
    
    date getDate() {
    	char c = '/';
    	cin >> day >> c >> month >> c >> year;
    }
    
    void showDate() const {
    	cout << day << '/' << month << '/' << year;	
    }
};

class employee {
private:
    int id;
    float salary;
    date hire_date;
    etype type;
public:
    employee() : id(0), salary(0.0f), type(accountant) { }
    
    void putEmployee() {
        char ch = 'a';
        cout << "Введите номер сотрудника, его пособие, дату принятия на работу и первую букаву его должности: ";
	    cin >> id >> salary;
	    hire_date.getDate();
	    cin >> ch;
	    switch(ch) {
	    	case 'a': type = accountant; break;
	    	case 'l': type = labour; break;
	    	case 'm': type = manager; break;
	    	case 'r': type = researcher; break;
	    	case 's': type = secretary; break;
	    	case 't': type = teacher; break;
	    }
    }
    
    void getEmployee() const {
        string type_s = "";
        switch(type) {
        	case 0: type_s = "accountant"; break;
        	case 1: type_s = "labour"; break;
        	case 2: type_s = "manager"; break;
        	case 3: type_s = "researcher"; break;
        	case 4: type_s = "secretary"; break;
        	case 5: type_s = "teacher"; break;
        }
        cout << "Номер сотрудника, его пособие, дата принятия на работу и должность: " << id << ' ' << salary << ' ';
        hire_date.showDate();
        cout << ' ' << type_s << endl;
    }
};

int main()
{
	employee employee1;
	employee employee2;
	employee employee3;
    employee1.putEmployee();
    employee2.putEmployee();
    employee3.putEmployee();
    employee1.getEmployee();
    employee2.getEmployee();
    employee3.getEmployee();
	return 0;
}