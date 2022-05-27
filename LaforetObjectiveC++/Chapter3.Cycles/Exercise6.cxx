#include <iostream>

using namespace std;

int main() {
    int number = 0;
    do {
    	cout << "Введите число, чтобы вычислить факториал: ";
    	cin >> number;
    	
    	int factorial = 1;
    	for (int i = 1; i <= number; ++i) {
    		factorial *= i;
    	}
    	cout << "Факториал числа " << number << " равен " << factorial << endl;
    } while (number != 0);
	return 0;
}
