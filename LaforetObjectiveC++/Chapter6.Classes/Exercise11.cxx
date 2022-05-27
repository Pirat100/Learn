#include <iostream>
#include <cmath>

using namespace std;

class fraction {
private:
	int dividend;
	int divider;
public:
    void inputFraction(fraction& f2, char& operation) {
        cout << "Введите первую дробь, операцию и вторую дробь: ";
        char cherta = '/';
        cin >> dividend >> cherta >> divider >> operation >> f2.dividend >> cherta >> f2.divider;
    }
    
    void printFraction() {
    	char cherta = '/';
    	lowterms();
    	cout << dividend << cherta << divider << endl;
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
    char operation = 'a';
    char cherta = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        f1.inputFraction(f2, operation);      
        switch(operation) {
        	case '+': 
        	    f1.add(f2);
        	    break;
        	case '-': 
        	    f1.sub(f2);
                break;
        	case '*':
        	    f1.mul(f2);
                break;
            case '/':
                f1.div(f2);
                break;
        }
        f1.printFraction();
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}




