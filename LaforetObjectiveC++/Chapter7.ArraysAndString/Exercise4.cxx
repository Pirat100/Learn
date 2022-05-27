#include <iostream>

using namespace std;

int maxint(int numbers[], int count);

int main() {
	int numbers[100];
	int number;
	int counter = 0;
	char answer;
	do {
	    cout << "Введите целое число: ";
		cin >> number;
		numbers[counter] = number;
		++counter;
		cout << "Продолжить (y/n)?: ";
		cin >> answer;
	} while (answer != 'n');
	int index_max = maxint(numbers, counter);
	cout << "Наибольший элемент массива введеных вами чисел: " << numbers[index_max] << " с индексом: " << index_max << endl;
	return 0;
}

int maxint(int numbers[], int count) {
	int index_max = 0;
	int temp = numbers[0];
	for (size_t i = 0; i < count; ++i) {
		if (numbers[i] > temp) {
			temp = numbers[i];
			index_max = i;
		}
	}
	return index_max;
}


