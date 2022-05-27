#include <iostream>
#include <conio.h>

using namespace std;

struct fraction {
	int dividend;
	int divider;
};

fraction fadd(const fraction& f1, const fraction& f2);
fraction fsub(const fraction& f1, const fraction& f2);
fraction fmul(const fraction& f1, const fraction& f2);
fraction fdiv(const fraction& f1, const fraction& f2);

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
        	    f3 = fadd(f1, f2);
        	    break;
        	case '-': 
        	    f3 = fsub(f1, f2);
                break;
        	case '*':
        	    f3 = fmul(f1, f2);
                break;
            case '/':
                f3 = fdiv(f1, f2);
                break;
        }
        cout << "Результат равен " << f3.dividend << cherta << f3.divider << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}

fraction fadd(const fraction& f1, const fraction& f2) {
	fraction result;
	result.dividend = f2.dividend * f1.divider + f1.divider * f2.dividend;
    result.divider= f1.divider * f2.divider;
    return result;
}

fraction fsub(const fraction& f1, const fraction& f2) {
    fraction result;
    result.dividend = f1.dividend * f2.divider - f1.divider * f2.dividend;
    result.divider = f1.divider * f2.divider;
    return result;
}

fraction fmul(const fraction& f1, const fraction& f2) {
    fraction result;
    result.dividend = f1.dividend * f2.dividend;
    result.divider = f1.divider * f2.divider;
    return result;
}

fraction fdiv(const fraction& f1, const fraction& f2) {
	fraction result;
	result.dividend = f1.dividend * f2.divider;
    result.divider = f1.divider * f2.dividend;
    return result;
}


