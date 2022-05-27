#include <iostream>

using namespace std;

struct point {
	int x;
	int y;
};

int main()
{
	point point1;
	point point2;
	cout << "Введите координаты точки p1: ";
	cin >> point1.x >> point1.y;
	cout << "Введите координаты точки p2: ";
	cin >> point2.x >> point2.y;
    point point3 = {(point1.x + point2.x), (point1.y + point2.y)};
	cout << "Координаты точки p1 + p2 равны: " << point3.x << ' ' << point3.y << endl;		
	return 0;
}
