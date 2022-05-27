#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    double operand1 = 0, operand2 = 0, result = 0;
    char operation = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        cout << "Введите первый операнд, операцию и второй операнд: " << endl;
        cin >> operand1 >> operation >> operand2;
        switch(operation) {
        	case '+': result = operand1 + operand2; break;
        	case '-': result = operand1 - operand2; break;
        	case '*': result = operand1 * operand2; break;
        	case '/': result = operand1 / operand2; break;
        }
        cout << "Результат равен " << result << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}