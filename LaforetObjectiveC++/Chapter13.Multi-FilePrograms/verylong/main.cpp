#include "verylong.h"

int main() {
	unsigned long numb, j;
//	verylong numb, j;
	verylong fact = 1;

	cout << "Введите число: ";
	cin >> numb;

	for (j = numb; j > 0; --j) {
		fact = fact * j;
	}
	cout << "Факториал = ";
	fact.putvl();
	cout << endl;
	return 0;
}




