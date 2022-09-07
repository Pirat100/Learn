#include <iostream>

using namespace std;

int main() {
	void initArray(int* ap[]);
	void showArray(int* ap[]);
	int a0[10], a1[10], a2[10], a3[10], a4[10], a5[10], a6[10], a7[10], a8[10], a9[10];
	int* ap[10] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};
	initArray(ap);
	showArray(ap);
    return 0;
}

void initArray(int* ap[]) {
	for (int j = 0; j < 10; ++j) {
		for (int k = 0; k < 10; ++k) {
			ap[j][k] = j * k * 2;
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


