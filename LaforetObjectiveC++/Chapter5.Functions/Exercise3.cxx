#include <iostream>

using namespace std;

void zeroSmaller(int& a, int& b);

int main() {
    int a, b;
    cout << "Введите числа, которые необходимо сравнить: ";
    cin >> a >> b;
    cout << "Число a равно " << a << ", число b равно " << b << endl;
    zeroSmaller(a, b);
    cout << "Число a равно " << a << ", число b равно " << b << endl;
	return 0;
}

void zeroSmaller(int& a, int& b) {
	if (a < b) {
		a = 0;
	} else if (b < a) {
		b = 0;
	}
}