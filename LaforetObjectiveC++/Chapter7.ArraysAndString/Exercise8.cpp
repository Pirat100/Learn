#include <iostream>

using namespace std;

class safearray {
private:
	static const int LIMIT = 100;
    int aray[LIMIT];
public:
	void putel(const int& index, const int& value) {
		if (index >= 0 && index < LIMIT) {
            aray[index] = value;
		} else {
			cout << "Incorrect index of array" << endl;
			exit(0);
		}
	}

	int getel(const int& index) {
		if (index > 0 && index < LIMIT) {
		    return aray[index];
		} else {
			cout << "Request for the incorrect index of array" << endl;
			exit(0);
		}
	}
};

int main() {
   safearray sa1;
   int temp = 12345;
   sa1.putel(0, temp);
   temp = sa1.getel(1);
	return 0;
}
