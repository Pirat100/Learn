#include <iostream>
#include <string>

using namespace std;

int main()
{
	float array[80];
	char answer = 'y';
	int size = 0;
	while (answer != 'n') {
		cout << "Введите число: ";
		cin >> *(array + size++);
		cout << "Продолжить ввод чисел?(y/n): ";
		cin >> answer;
	}
	float sum = 0.0;
	for (int j = 0; j < size; ++j) {
		sum += *(array + j);
	}
	cout << "Среднее арифметическое суммы чисел равно: " << sum / size << endl;
    return 0;
}
