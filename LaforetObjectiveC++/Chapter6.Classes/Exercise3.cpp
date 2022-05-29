//Создайте класс с именем time, содержащий три поля типа int, предназначенные для хранения часов, минут и секунд.
//Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой констуктор - заданным
//набором значений. Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59, и метод,
//складывающий значения двух объектов типа time, передаваемых в качестве аргументов.
//В функции main следует создать два инициализированных объекта (подумайте, должны ли они быть константными) и один
//неинициализированный объект. Затем сложите два инициализированных значения, а результат присвойте третьему объекту
//и выведите его значение на экран. Где возможно, сделайте мтеоды константными.

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
	Time add(Time t2) {
		hours += t2.hours;
		minutes += t2.minutes;
		seconds += t2.seconds;
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
		return Time(hours, minutes, seconds);
	}
};

int main() {
	Time t1;
    Time t2(15,59,59);
	const Time t3(10,40,44);

	t2.display();
	t3.display();

	t1 = t2.add(t3);
	t1.display();

	return 0;
}
