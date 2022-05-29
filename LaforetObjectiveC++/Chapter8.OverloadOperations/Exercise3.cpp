//Модифицируйте класс time из упражнения 3 главы 6 так, чтобы вместо метода add_time() можно бло использовать
//операцию + для складывания двух значений времени. Напишите программу для проверки класса.

#include <iostream>

using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
		if (seconds > 59) {
			seconds -= 60;
			++minutes;
		}
		if (minutes > 59) {
			minutes -= 60;
			++hours;
		}
		if (hours > 12) {
			hours -= 12;
		}
	}
	void display() const {
        cout << hours << ':' << minutes << ':' << seconds << endl;
	}
	Time operator+(Time t2) {
		hours += t2.hours;
		minutes += t2.minutes;
		seconds += t2.seconds;
		Time temp(hours, minutes, seconds);
		return temp;
	}
};

int main() {
	Time t1;
    Time t2(15,59,59);
	Time t3(10,40,44);

	t1.display();
	t2.display();
	t3.display();

	t1 = t2 + t3;
	t1.display();

	return 0;
}
