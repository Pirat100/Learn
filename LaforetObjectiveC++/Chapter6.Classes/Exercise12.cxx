#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class fraction {
private:
	int dividend;
	int divider;
public:
    fraction() : dividend(1), divider(1) { }
    void inputFraction(fraction& f2, char& operation) {
        cout << "Введите первую дробь, операцию и вторую дробь: ";
        char cherta = '/';
        cin >> dividend >> cherta >> divider >> operation >> f2.dividend >> cherta >> f2.divider;
    }
    void inputDivider() {
        cout << "Введите знаменатель дооби для таблицы умножения: ";
    	cin >> divider;
    }
    
    void incrDividend() {
    	++dividend;
    }
    
    int getDivider() const {
    	return divider;
    }
    
    void setDividend(const int& div) {
    	dividend = div;
    }
    
    void setDivider(const int& div) {
    	divider = div;
    }
    
    void printFraction() {
    	char cherta = '/';
    	lowterms();
    	cout << left << dividend << left << cherta << left << setw(5) << divider;
    }
    
    void add(const fraction& f2) {
	    dividend = dividend * f2.divider + divider * f2.dividend;
        divider= divider * f2.divider;
    }

    void sub(const fraction& f2) {
        dividend = dividend * f2.divider - divider * f2.dividend;
        divider = divider * f2.divider;
    }

    void mul(const fraction& f2) {
         dividend = dividend * f2.dividend;
         divider = divider * f2.divider;
    }

    void div(const fraction& f2) {
	    dividend = dividend * f2.divider;
        divider = divider * f2.dividend;
    }
    
    void lowterms() {
    	long tnum, tden, temp, gcd;
    	tnum = labs(dividend);
    	tden = labs(divider);
    	if (tden == 0) {
    		cout << "Недопустимый знаменатель!";
    		exit(1);
    	} else if (tnum == 0) {
    		dividend = 0;
    		divider = 1;
    		return;
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
    }
};

int main() {
    fraction f1, f2;
    f1.inputDivider();
    f2 = f1;
    int divider_count = f1.getDivider();
    cout << setw(7) << "";
    for (int i = f1.getDivider() - 1; i > 0; --i) {
    	f1 = f2;
    	f1.printFraction();
        f2.incrDividend();
    }
    cout << endl;
    for (int i = 0; i < divider_count * 7; ++i) {
    	cout << "-";
    }
    cout << endl;
    for (int i = 1; i < divider_count; ++i) {
        f1.setDividend(i);
        f1.setDivider(divider_count);
        f1.printFraction();
        for (int j = 1; j < divider_count; ++j) {
            f2.setDividend(j);
            f2.setDivider(divider_count);
            f2.mul(f1);
            f2.printFraction();
        }
        cout << endl;
    }
    
	return 0;
}




