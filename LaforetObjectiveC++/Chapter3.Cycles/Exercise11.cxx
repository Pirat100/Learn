#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int funt1, shiling1, pens1, funt2, shiling2, pens2, funt_res, shiling_res, pens_res;
    double coefficient = 0;

    unsigned char znak_funta = 176;
    char operation = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        cout << "Введите количество фунтов, шилингов и пенсов первой суммы: " << endl;
        cin >> funt1 >> shiling1 >> pens1;
        cout << "Введите операцию: " << endl;
        cin >> operation;
        if (operation == '*') {
        	cout << "Введите коэффициент: " << endl;
        	cin >> coefficient;
        } else {
        cout << "Введите количество фунтов, шилингов и пенсов второго счета" << endl;
        cin >> funt2 >> shiling2 >> pens2;
        }
        switch(operation) {
        	case '+': 
        	    funt_res = funt1 + funt2;
        	    shiling_res = shiling1 + shiling2;
        	    pens_res = pens1 + pens2;
        	    if (pens_res > 11) {
        	       ++shiling_res;
        	       pens_res = pens_res - 12;
        	    }
        	    if (shiling_res > 20) {
        	       ++funt_res;
        	       shiling_res = shiling_res - 20;
        	    }
                break;
        	case '-': 
                funt_res = funt1 - funt2;
        	    shiling_res = shiling1 - shiling2;
        	    pens_res = pens1 - pens2;
        	    if (pens_res < 0) {
        	       --shiling_res;
        	       pens_res = pens_res + 12;
        	    }
        	    if (shiling_res < 0) {
        	       --funt_res;
        	       shiling_res = shiling_res + 20;
        	    }
        	    break;
        	case '*':
        	    double funt_new = funt1 * coefficient + (shiling1 * coefficient) / 20 + (pens1 * coefficient) / (20 * 12);
        	    funt_res = static_cast<int>(funt_new);
        	    double shiling_ost = funt_new - funt_res;
        	    shiling_res = static_cast<int>(shiling_ost * 20);
        	    double pens_ost = shiling_ost * 20 - shiling_res;
        	    pens_res = static_cast<int>(pens_ost * 12);
        	    break;
        }
        cout << "Результат равен " << znak_funta << funt_res << ' ' << shiling_res << ' ' << pens_res << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}
