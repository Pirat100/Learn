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

    fraction operator + (const fraction& f2) const {
    	int dvdnd = dividend * f2.divider + divider * f2.dividend;
    	int dvdr = divider * f2.divider;
    	return fraction(dvdnd, dvdr);
    }
    fraction operator - (const fraction& f2) const {
        int dvdnd = dividend * f2.divider - divider * f2.dividend;
        int dvdr = divider * f2.divider;
        return fraction(dvdnd, dvdr);
    }
    fraction operator * (const fraction& f2) const {
    	int dvdnd = dividend * f2.dividend;
    	int dvdr = divider * f2.divider;
    	return fraction(dvdnd, dvdr);
    }
    fraction operator / (const fraction& f2) const {
	    int dvdnd = dividend * f2.divider;
        int dvdr = divider * f2.dividend;
        return fraction(dvdnd, dvdr);
    }
    bool operator == (fraction& f2) const {
    	fraction f1(dividend, divider);
    	return f1.dividend == f2.dividend
    			&& f1.divider == f2.divider;
    }
    bool operator != (fraction& f2) const {
    	fraction f1(dividend, divider);
    	return f1.dividend != f2.dividend
    			|| f1.divider != f2.divider;
    }

    friend istream& operator >> (istream& is, fraction& frac);
    friend ostream& operator << (ostream& os, const fraction& frac);
};

istream& operator >> (istream& is, fraction& frac) {
    char cherta = '/';
    while (true) {
    	is.unsetf(ios::skipws);
    	is >> frac.dividend;
    	if (is.good()) {
    		is >> cherta;
    		if (cherta == '/') {
    			is >> frac.divider;
    			if (is.good()) {
    				if (frac.divider != 0) {
    					is.ignore(80, '\n');
    					break;
    				} else {
    					is.clear();
    					cout << "Знаменатель не может быть равен нулю!\n";
    				}
    			} else {
    				is.clear();
    				cout << "Знаменатель должен быть числом!\n";
    			}
    		} else {
    			is.clear();
    			cout << "Числитель и знаменатель должна разделять косая черта!\n";
    		}
    	} else {
    		is.clear();
    		cout << "Числитель должен быть числом!\n";
    	}
    	is.ignore(80, '\n');
    	cout << "Введите дробь заново: ";
    }
    return is;
}

ostream& operator << (ostream& os, const fraction& frac) {
	os << frac.dividend << '/' << frac.divider << '\n';
	return os;
}

int main() {
    fraction f1, f2, f3;
    fraction f4(0,1), f5(0,0), f6(1,1);
    char operation = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        cout << "Введите первую дробь: ";
        cin >> f1;
        cout << "Введите оператор (+, -, *, /): ";
        cin >> operation;
        cout << "Введите вторую дробь: ";
        cin >> f2;
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
        f3.lowterms();
        cout << f3;
        if (f1 == f4 || f2 == f4 || f1 == f5 || f2 == f5 || f1 == f6 || f2 == f6) {
        	cout << "Одна из введенных Вами дробей равна 0/0, 0/1, 1/1. Цикл операций завершен." << endl;
        	more_operations = 'e'; //exit from cycle
        } else {
            cout << "Выполнить еще одну операцию (y/n)? ";
            cin >> more_operations;
        }
    }
    cout << endl;
    return 0;
}

