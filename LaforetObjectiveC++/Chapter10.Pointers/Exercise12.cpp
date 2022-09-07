#include <iostream>

using namespace std;

const int SIZE = 1000;

float fmemory[SIZE];
int pmemory[SIZE];
int fmem_top = 0;
int pmem_top = 0;

class Float {
private:
	int addr;
public:
	Float(const float& f) {
		addr = fmem_top;
		fmemory[fmem_top++] = f;
	}

	int operator& () {
		return addr;
	}
};

class ptrFloat {
private:
	int addr;
public:
	ptrFloat(const int& i) {
		addr = pmem_top;
		pmemory[pmem_top++] = i;
	}

	float& operator* () {
		return fmemory[pmemory[addr]];
	}
};

int main() {
	Float var1 = 1.234;
	Float var2 = 5.678;
	ptrFloat ptr1 = &var1;
	ptrFloat ptr2 = &var2;
	cout << "Адрес 1-го элемента Float: " << &var1 << endl;
	cout << "Адрес 2-го элемента Float: " << &var2 << endl;
	cout << " *ptr1 = " << *ptr1;
	cout << " *ptr2 = " << *ptr2;
	*ptr1 = 7.123;
	*ptr2 = 8.456;
	cout << " *ptr1 = " << *ptr1;
	cout << " *ptr2 = " << *ptr2;
    return 0;
}




