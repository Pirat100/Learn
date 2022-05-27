#include <iostream>

using namespace std;

int main() {
    cout << "Введите начальный вклад: ";
    double money_start = 0;
    cin >> money_start;
    
    cout << "Введите процентную ставку: ";
    double coefficient = 0;
    cin >> coefficient;
    
    cout << "Введите желаемую сумму: ";
    double money_to_wish = 0;
    cin >> money_to_wish;
   
    int count_of_years = 0;
    do {
        money_start *= (1 + (coefficient / 100));
        ++count_of_years;
    } while (money_start < money_to_wish);
    cout << "Через " << count_of_years << " лет вы получите " << money_to_wish << " доллара." << endl;
    
}
