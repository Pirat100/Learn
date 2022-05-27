#include <iostream>

using namespace std;

class matrix {
private:
	static const int LIMIT1 = 10;
	static const int LIMIT2 = 10;
	int rows, columns;
    int aray[10][10];
public:
    matrix(const int& lim1, const int& lim2) : rows(lim1), columns(lim2) {}
	void putel(const int& index1, const int& index2, const int& value) {
		if (index1 >= 0 && index1 < LIMIT2) {
			if (index2 >= 0 && index2 < LIMIT2) {
	            aray[index1][index2] = value;
			} else {
				cout << "Incorrect index2 of array" << endl;
				exit(0);
			}
		} else {
			cout << "Incorrect index1 of array" << endl;
			exit(0);
		}
	}

	int getel(const int& index1, const int& index2) {
		if (index1 >= 0 && index1 < LIMIT1) {
			if (index2 >= 0 && index2 < LIMIT2) {
		        return aray[index1][index2];
			} else {
				cout << "Request for the incorrect index2 of array" << endl;
				exit(0);
			}
		} else {
			cout << "Request for the incorrect index1 of array" << endl;
			exit(0);
		}
	}
};

int main() {
   matrix m1(11, 4);
   int temp = 12345;
   m1.putel(7, 4, temp);
   temp = m1.getel(7, 4);
	return 0;
}
