#include <iostream>

using namespace std;

class employee {
private:
    int id;
    float salary;
public:
    employee() : id(0), salary(0.0f) { }
    
    void setId() {
    	cin >> id;
    }
    
    void setSalary() {
    	cin >> salary;
    }
    
    void printValues() const {
        cout << "Номер сотрудника и его пособие: " << id << ' ' << salary << endl;
    }
};

int main()
{
	employee employee1;
	employee employee2;
	employee employee3;
	cout << "Введите номер первого сотрудника и его пособие: ";
	employee1.setId();
	employee1.setSalary();
    cout << "Введите номер второго сотрудника и его пособие: ";
    employee2.setId();
	employee2.setSalary();
	cout << "Введите номер третьего сотрудника и его пособие: ";
    employee3.setId();
	employee3.setSalary();
    employee1.printValues();
    employee2.printValues();
    employee3.printValues();
	return 0;
}