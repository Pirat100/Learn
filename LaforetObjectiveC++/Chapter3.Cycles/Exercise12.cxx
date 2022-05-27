#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int dividend1, divider1, dividend2, divider2, dividend_res, divider_res;
    char operation = 'a';
    char cherta = 'a';
    char more_operations = 'y';
    while (more_operations == 'y') {
        cout << "Введите первую дробь, операцию и вторую дробь: " << endl;
        cin >> dividend1>> cherta >> divider1 >> operation >> dividend2 >> cherta >> divider2;
        switch(operation) {
        	case '+': 
        	    dividend_res = dividend1 * divider2 + divider1 * dividend2;
        	    divider_res = divider1 * divider2;
                break;
        	case '-': 
                dividend_res = dividend1 * divider2 - divider1 * dividend2;
        	    divider_res = divider1 * divider2;
        	    break;
        	case '*':
                dividend_res = dividend1 * dividend2;
                divider_res = divider1 * divider2;
                break;
            case '/':
                dividend_res = dividend1 * divider2;
                divider_res = divider1 * dividend2;
                break;
        }
        cout << "Результат равен " << dividend_res << cherta << divider_res << endl;
        cout << "Выполнить еще одну операцию (y/n)? ";
        cin >> more_operations;
    } 
	return 0;
}
