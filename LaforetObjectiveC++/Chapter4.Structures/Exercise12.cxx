#include <iostream>
#include <conio.h>

using namespace std;

struct fraction {
	int dividend;
	int divider;
};

int main() {
    fraction f1, f2, f3;
    char operation = 'a';
    char cherta = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        cout << "Введите первую дробь, операцию и вторую дробь: " << endl;
        cin >> f1.dividend >> cherta >> f1.divider >> operation >> f2.dividend >> cherta >> f2.divider;
        switch(operation) {
        	case '+': 
        	    f3.dividend = f1.dividend * f2.divider + f1.divider * f2.dividend;
        	    f3.divider= f1.divider * f2.divider;
                break;
        	case '-': 
                f3.dividend = f1.dividend * f2.divider - f1.divider * f2.dividend;
        	    f3.divider = f1.divider * f2.divider;
        	    break;
        	case '*':
                f3.dividend = f1.dividend * f2.dividend;
                f3.divider = f1.divider * f2.divider;
                break;
            case '/':
                f3.dividend = f1.dividend * f2.divider;
                f3.divider = f1.divider * f2.dividend;
                break;
        }
        cout << "Результат равен " << f3.dividend << cherta << f3.divider << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}
