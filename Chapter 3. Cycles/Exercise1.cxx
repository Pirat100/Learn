#include <iostream>

using namespace std;

int main() {
    cout << "Введите число: ";
    int number;
    cin >> number;
    for (int i = 0; i < 20; ++i) {
    	for (int j = 1; j <= 10; ++j) {
    		cout << (j + i *10) * number;
    	}
    	cout << endl;
    }
	return 0;
}