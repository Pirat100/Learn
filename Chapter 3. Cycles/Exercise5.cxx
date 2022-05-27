#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 1; i <= 20; ++i) {
    	for (int p = 20 - i; p >= 1; --p) {
    		cout << ' ';
    	}
    	for (int x = 1; x <= i; ++x) {
    		cout << 'X';
    	}
    	cout << endl;
    }
	return 0;
}