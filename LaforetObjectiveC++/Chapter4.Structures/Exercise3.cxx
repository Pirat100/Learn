#include <iostream>

using namespace std;

struct Distance {
	int feet;
	float inches;
};

struct Volume {
	Distance length;
	Distance width;
	Distance heigth;
};

int main()
{
	Volume volume1 = { {5, 2}, {7, 4}, {2, 7} };
	float length = volume1.length.feet + volume1.length.inches / 12;
	float width = volume1.width.feet + volume1.width.inches / 12;
	float heigth = volume1.heigth.feet + volume1.heigth.inches / 12;
	float result = length * width * heigth;
	cout << "Объем помещения длиной " << length << ", шириной " << width << " и высотой " << heigth << " равен: " << result << endl;
	return 0;
}
