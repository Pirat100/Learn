#include <iostream>

using namespace std;

class Array {
private:
    int* ptr;
    int size;
public:
    Array(int s) {
    	size = s;
    	ptr = new int[s];
    }
    
    Array(Array& a) {
        size = a.size;
        ptr = new int[size];
        for (int i = 0; i < size; ++i) {
        	*(ptr + i) = *(a.ptr + i);
        }	
        cout << "Это конструктор копирования" << endl;
    }
    
    ~Array() {
    	delete[] ptr;
    }
    
    int& operator[](int j) {
    	return *(ptr + j);
    }
    
    Array& operator=(Array& a) {
    	delete[] ptr;
    	size = a.size;
    	ptr = new int[size];
    	for (int i = 0; i < size; ++i) {
    		*(ptr + i) = *(a.ptr + i);
    	}
    	cout << "Это оператор присваивания" << endl;
    	return *this;
    }
};

int main()
{
    const int ASIZE = 10;
    Array arr(ASIZE);
    
    for (int i = 0; i < ASIZE; ++i) {
    	arr[i] = i * i;
    }
    
    for (int i = 0; i < ASIZE; ++i) {
    	cout << arr[i] << ' ';
    }
    cout << endl;
    
    Array arr2(arr);
    
    for (int i = 0; i < ASIZE; ++i) {
    	cout << arr2[i] << ' ';
    }
    cout << endl;
    Array arr3(20);
    arr3 = arr;
    for (int i = 0; i < ASIZE; ++i) {
    	cout << arr3[i] << ' ';
    }
    cout << endl;
	return 0;
}

