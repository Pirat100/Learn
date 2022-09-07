#include <iostream>

using namespace std;

const int LIMIT = 100;

class safearray {
private:
    int arr[LIMIT];
public:
    int& operator[](int n) {
    	if (n < 0 || n >= LIMIT ) {
    		 cout << endl << "Ошибочный индекс!";
    		 exit(1);
    	}
    	return arr[n];
    }
};

class safearray2 : public safearray {
private:
    int arr[LIMIT];
    int begin_value;
    int end_value;
public:
    safearray2(const int& bv, const int& ev) {
        begin_value = bv;
        end_value = ev;
    }
    int& operator[](int n) {
    	if (n < 0 || n >= (end_value - begin_value) ) {
    		 cout << endl << "Ошибочный индекс!";
    		 exit(1);
    	}
    	return arr[n];
    }
};

int main() {
	safearray2 sa1(1,101);
    for (size_t i = 0; i < 100; ++i) {
    	sa1[i] = i * 10;
    }

    for (size_t i = 1; i < LIMIT; ++i) {
        int temp = sa1[i];
        cout << "Элемент " << i << " равен " << temp << endl;
    }
    return 0;
}
