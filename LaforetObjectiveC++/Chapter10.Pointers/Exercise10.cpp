#include <iostream>

using namespace std;

const int NUMARRAYS = 10;
const int MAXSIZE = 10;

int main() {
	void initArray(int* ap[]);
	void showArray(int* ap[]);
	int* ap[NUMARRAYS];
	initArray(ap);
	showArray(ap);
    return 0;
}

void initArray(int* ap[]) {
	for (int j = 0; j < NUMARRAYS; ++j) {
		*(ap + j) = new int[MAXSIZE]; //тоже, что и - //ap[j] = new int[MAXSIZE]; - только через указатели, а не ссылки.
		for (int k = 0; k < MAXSIZE; ++k) {
			*(*(ap + j) + k) = j * k * 2; //тоже, что и - //ap[j][k] = j * k * 2; - только через указатели, а не ссылки.
		}
	}
}

void showArray(int* ap[]) {
	for (int j = 0; j < 10; ++j) {
		for (int k = 0; k < 10; ++k) {
			cout << ap[j][k] << ' ';
		}
		cout << endl;
	}
}


