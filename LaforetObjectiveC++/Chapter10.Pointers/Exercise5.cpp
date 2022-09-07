#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	void addArrays(float* arr1, float* arr2, float* sum, int size);
	void displayArrays(float* arr, int size);
	float arr1[3] = {1.0, 2.0, 3.0};
	float arr2[3] = {7.0, 10.0, 4.0};
	float sum[3];
	addArrays(arr1, arr2, sum, 3);
	displayArrays(sum, 3);
    return 0;
}


void addArrays(float* arr1, float* arr2, float* sum, int size) {
	for (int i = 0; i < size; ++i) {
		sum[i] = arr1[i] + arr2[i];
	}
}

void displayArrays(float* arr, int size) {
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << endl;
	}
}
