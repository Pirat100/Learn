#include <iostream>

using namespace std;

void swap(int& a, int& b);

int main() {
    int a, b;
    cout << "Введите числа a и b: ";
    cin >> a >> b;
    cout << "Числа a равно " << a << ", число b равно " << b << endl;
    swap(a,b);
    cout << "Числа a после обмена равно " << a << ", число b равно " << b << endl;
	return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

