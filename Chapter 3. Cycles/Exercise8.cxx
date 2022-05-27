#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    char znak_funt = 176;
    char command = 'a';
    do {
        cout << "Введите первую сумму " << znak_funt;
        int funt1 = 0, shiling1 = 0, pens1 = 0;
        cin >> funt1 >> shiling1 >> pens1;
    
        cout << "Введите вторую сумму " << znak_funt;
        int funt2 = 0, shiling2 = 0, pens2 = 0;
        cin >> funt2 >> shiling2 >> pens2;
        
        int funt_res = funt1 + funt2;
        int shiling_res = shiling1 + shiling2;
        int pens_res = pens1 + pens2;
        if (pens_res > 11) {
        	++shiling_res;
        	pens_res = pens_res - 12;
        }
        if (shiling_res > 19) {
        	++funt_res;
        	shiling_res = shiling_res - 20;
        }
        
        cout << "Всего " << znak_funt << funt_res << ' ' << shiling_res << ' ' << pens_res << endl;   
        cout << "Продолжить (y / n) ?";
        cin >> command;
    } while (command == 'y');
    return 0;
}