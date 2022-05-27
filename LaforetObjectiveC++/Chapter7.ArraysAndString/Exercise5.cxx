#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class fraction {
private:
	int dividend;
	int divider;
public:
    fraction() : dividend(0), divider(1) { }
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
    
    void to_average(fraction& f, const int& counter) {
        fraction counter_fraction, result;
        counter_fraction.setDividend(counter);
        counter_fraction.setDivider(1);
        f.div(counter_fraction);
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
    fraction fractions[100];
    fraction f1;
    int dividend, divider, counter = 0;
    char ch, answer;
    do {
        cout << "Введите дробь в формате \"делитель / делимое\": ";
        cin >> dividend >> ch >> divider;
        f1.setDividend(dividend);
        f1.setDivider(divider);
        fractions[counter] = f1;
        ++counter;
        cout << "Повторить операцию(y/n)?: ";
        cin >> answer;
    } while(answer != 'n');
    
    fraction result;
    
    for (size_t i = 0; i < counter; ++i) {
    	cout << "Дробь " << i << ": ";
    	fractions[i].printFraction();
        result.add(fractions[i]);
    	cout << endl;
    }
    result.to_average(result, counter);
    result.printFraction();
	return 0;
}




