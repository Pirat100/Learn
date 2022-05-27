#include <iostream>

using namespace std;

int main() {
    cout << "Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта, 2 для перевода шкалы Фаренгейта в шкалу Цельсия: ";
	int command, temperature;
	double result;
	cin >> command;
	cout << "Введите температуру по: ";
	switch (command) {
		case 1: cout << "Цельсию: ";
		    cin >> temperature;
	    	result = (temperature * 1.8) + 32;
		    cout << "Значение по Фаренгейту: " << result << endl;
		    break;
		case 2: cout << "Фаренгейту: "; 
	    	cin >> temperature;
	    	result = (temperature - 32) / 1.8;
	    	cout << "Значение по Цельсию: " << result << endl;
	}
	return 0;
}