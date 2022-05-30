//Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 главы 6 так,
//чтобы он использовал перегруженные операции сложения, вычитания, умножения и деления.
//(Вспомните правила арифметики с дробями в упражнении 12 главы 3 "Циклы и ветвления".) Также перезагрузите
//операции сравнения == и != и используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения
//двух частей дроби. Вы можете модифициовать и функцию lowterms() так, чтобы она возвращала значение ее аргумента,
//уменьшенное до несократимой дроби. Это будет полезным в арифметических функциях, которые могут быть
//выполнены сразу после получения ответа.

#include <iostream>
#include <cmath>

using namespace std;

class fraction {
private:
	int dividend;
	int divider;
public:
	fraction() : dividend(0), divider(0) {}
	fraction(int dvdnd, int dvdr) : dividend(dvdnd), divider(dvdr) {}

    void inputFraction(fraction& f2, char& operation) {
        cout << "Введите первую дробь, операцию, и вторую дробь: ";
        char cherta = '/';
        cin >> dividend >> cherta >> divider >> operation >> f2.dividend >> cherta >> f2.divider;
    }

    void printFraction() {
    	char cherta = '/';
    	lowterms();
    	cout << dividend << cherta << divider << endl;
    }

    fraction lowterms() {
    	long tnum, tden, temp, gcd;
    	tnum = labs(dividend);
    	tden = labs(divider);
    	if (tden == 0) {
    		cout << "Недопустимый знаменатель!";
    		exit(1);
    	} else if (tnum == 0) {
    		dividend = 0;
    		divider = 1;
    		return fraction(dividend, divider);
    	}
    	while (tnum != 0) {
    		if (tnum < tden) {
    			temp = tnum;
    			tnum = tden;
    			tden = temp;
    		}
    		tnum = tnum - tden;
    	}
    	gcd = tden;
    	dividend = dividend / gcd;
    	divider = divider / gcd;
    	return fraction(dividend, divider);
    }

    fraction operator+(const fraction& f2) const {
    	int dvdnd = dividend * f2.divider + divider * f2.dividend;
    	int dvdr = divider * f2.divider;
    	return fraction(dvdnd, dvdr);
    }
    fraction operator-(const fraction& f2) const {
        int dvdnd = dividend * f2.divider - divider * f2.dividend;
        int dvdr = divider * f2.divider;
        return fraction(dvdnd, dvdr);
    }
    fraction operator*(const fraction& f2) const {
    	int dvdnd = dividend * f2.dividend;
    	int dvdr = divider * f2.divider;
    	return fraction(dvdnd, dvdr);
    }
    fraction operator/(const fraction& f2) const {
	    int dvdnd = dividend * f2.divider;
        int dvdr = divider * f2.dividend;
        return fraction(dvdnd, dvdr);
    }
    bool operator==(fraction& f2) const {
    	fraction f1(dividend, divider);
//    	f1.lowterms();
//    	f2.lowterms();
    	return f1.dividend == f2.dividend
    			&& f1.divider == f2.divider;
    }
    bool operator!=(fraction& f2) const {
    	fraction f1(dividend, divider);
//    	f1.lowterms();
//    	f2.lowterms();
    	return f1.dividend != f2.dividend
    			|| f1.divider != f2.divider;
    }
};

int main() {
    fraction f1, f2, f3;
    fraction f4(0,1), f5(0,0), f6(1,1);
    char operation = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        f1.inputFraction(f2, operation);
        switch(operation) {
            case '+':
         	    f3 = f1 + f2;
         	    break;
         	case '-':
         	    f3 = f1 - f2;
                break;
         	case '*':
         	    f3 = f1 * f2;
                break;
            case '/':
         	    f3 = f1 / f2;
                break;
        }
        f3.printFraction();
        if (f1 == f4 || f2 == f4 || f1 == f5 || f2 == f5 || f1 == f6 || f2 == f6) {
        	cout << "Одна из введенных Вами дробей равна 0/0, 0/1, 1/1. Цикл операций завершен." << endl;
        	more_operations = 'e'; //exit from cycle
        } else {
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
        }
    }
    return 0;
}
