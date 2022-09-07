#include <iostream>

using namespace std;

const int NUMARRAYS = 10;
const int MAXSIZE = 10;

class array {
private:
	int* ap[NUMARRAYS];
public:
	array() {
		for (int i = 0; i < NUMARRAYS; ++i) {
			ap[i] = new int[MAXSIZE];
		}
	}

	~array() {
		for (int i = 0; i < NUMARRAYS; ++i) {
			delete[] ap[i];
		}
	}
	void initArray() {
		for (int j = 0; j < NUMARRAYS; ++j) {
		    for (int k = 0; k < MAXSIZE; ++k) {
		        *(*(ap + j) + k) = j * k * 2;
		    }
		}
	}

	int& operator[](int n) {
		if(n < 0 || n >= NUMARRAYS * MAXSIZE) {
			cout << "\nОшибочный индекс!";
			exit(1);
		}
		return *(*(ap + n / 10) + n % 10);
	}

	void showArray() const {
		for (int i = 0; i < NUMARRAYS; ++i) {
			for (int j = 0; j < MAXSIZE; ++j) {
				cout << *(*(ap + i) + j) << ' ';
			}
			cout << endl;
		}
	}
};

int main() {
	array a1;
	a1.initArray();
	a1.showArray();
	cout << a1[22] << endl;
    return 0;
}




