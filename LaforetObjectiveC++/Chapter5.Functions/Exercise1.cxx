#include <iostream>

using namespace std;

float circarea (const float& radius);

int main() {
    float radius;
    cout << "Введите радиус окружности: ";
    cin >> radius;
    float area = circarea(radius);
    cout << "Площадь круга равна " << area << endl;
	return 0;
}

float circarea(const float& radius) {
    const float PI = 3.14159F;
    return PI * radius * radius;
}