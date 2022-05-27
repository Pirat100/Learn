#include <iostream>

using namespace std;

int main() {
    cout << "Введите количество гостей и стульев: ";
    int guests = 0, chairs = 0;
    cin >> guests >> chairs;
    int variants = guests;
    
    for (int i = guests - 1; i > guests - chairs; --i) {
    	variants *= i;
    }
    
    cout << "Количество вохможных вариантов рассадки: " << variants << endl;   
    return 0;
}