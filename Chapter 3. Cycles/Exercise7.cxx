#include <iostream>

using namespace std;

int main() {
    cout << "Введите начальный вклад: ";
    double money_start = 0;
    cin >> money_start;
    
    cout << "Введите число лет: ";
    double count_of_years = 0;
    cin >> count_of_years;
    
    cout << "Введите процентную ставку: ";
    double coefficient = 0;
    cin >> coefficient;
   
    double money_finish = money_start;
    for (int i = 1; i <= count_of_years; ++i) {
        money_finish *= (1 + (coefficient / 100));
    }
    cout << "Через " << count_of_years << " лет вы получите " << money_finish << " доллара." << endl;
    
}