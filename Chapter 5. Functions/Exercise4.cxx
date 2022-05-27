#include <iostream>

using namespace std;

struct Distance {
	int feet;
	float inches;
};

Distance biggerDistance(const Distance& d1, const Distance& d2);

int main() {
    Distance d1, d2;
    cout << "Первое расстояние: Введите число футов: ";
    cin >> d1.feet;
    cout << "Первое расстояние: Введите число дюймов: ";
    cin >> d1.inches;
    cout << "Второе расстояние: Введите число футов: ";
    cin >> d2.feet;
    cout << "Второе расстояние: Введите число дюймов: ";
    cin >> d2.inches;
    Distance result = biggerDistance(d1, d2);
    cout << "Наибольшее расстояние: " << result.feet << "\'-" << result.inches << "\" ";
    return 0;
}

Distance biggerDistance(const Distance& d1, const Distance& d2) {
	if (d1.feet > d2.feet) {
		return d1;
	} else if (d2.feet > d1.feet) {
		return d2;
	} else {
		if (d1.inches > d2.inches) {
		    return d1;
		} else if (d2.inches > d1.inches) {
			return d2;
		} else {
			return d1;
		}
	}
}