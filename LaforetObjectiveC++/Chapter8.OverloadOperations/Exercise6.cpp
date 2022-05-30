//Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя перегруженную операцию -,
//и умножать эти значения, используя тип float и перегруженную операцию *.

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
		else if (seconds < 0) {
			seconds += 60;
			--minutes;
		}
		if (minutes > 59) {
			minutes -= 60;
			++hours;
		}
		else if (minutes < 0) {
			minutes += 60;
			--hours;
		}
		if (hours > 12) {
			hours -= 12;
		}
		else if (hours < 0) {
			hours += 12;
		}
	}
	void display() const {
		if (hours < 10) {
			cout << '0';
		}
        cout << hours << ':';
        if (minutes < 10) {
        	cout << '0';
        }
        cout << minutes << ':';
        if (seconds < 10) {
        	cout << '0';
        }
        cout << seconds << endl;
	}
	Time operator+(const Time& t2) const {
		int h = hours + t2.hours;
		int m = minutes + t2.minutes;
		int s = seconds + t2.seconds;
		Time temp(h, m, s);
		return temp;
	}
	Time operator-(const Time& t2) const {
		int h = hours - t2.hours;
		int m = minutes - t2.minutes;
		int s = seconds - t2.seconds;
		Time temp(h, m, s);
		return temp;
	}
	Time operator*(const float& f2) const {
		int h = hours * f2;
		int m = minutes * f2;
		int s = seconds * f2;
		Time temp(h, m, s);
		return temp;
	}
	Time operator++() {
		++hours;
		return Time(hours, minutes, seconds);
	}
	Time operator++(int) {
		hours++;
		return Time(hours, minutes, seconds);
	}
	Time operator--() {
		--hours;
		return Time(hours, minutes, seconds);
	}
	Time operator--(int) {
		hours--;
		return Time(hours, minutes, seconds);
	}
};

int main() {
	Time t1(0,1,1);
	Time t2 = ++t1;
	t2.display();

	Time t3 = t2++;
	t3.display();

	Time t4 = --t3;
	t4.display();

	Time t5 = t4--;
	t5.display();

	Time t6 = t2 * 3.5;
	t6.display();
	return 0;
}
