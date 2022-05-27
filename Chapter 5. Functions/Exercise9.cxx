#include <iostream>

using namespace std;

struct time {
	int hours;
	int minutes;
	int seconds;
};

void swap(struct time& t1, struct time& t2);

int main() {
    struct time t1, t2;
    char ch = 'a';
    cout << "Введите первое время в формате чч:мм:сс: ";
    cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
    cout << "Введите второе время в формате чч:мм:сс: ";
    cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
    cout << "Первое время равно: " << t1.hours << ':' << t1.minutes << ':' << t1.seconds << endl;
    cout << "Второе время равно: " << t2.hours << ':' << t2.minutes << ':' << t2.seconds << endl;
    swap(t1, t2);
    cout << "Первое время после обмена равно: " << t1.hours << ':' << t1.minutes << ':' << t1.seconds << endl;
    cout << "Второе время после обмена равно: " << t2.hours << ':' << t2.minutes << ':' << t2.seconds << endl;
	return 0;
}

void swap(struct time& t1, struct time& t2) {
	struct time temp = t1;
	t1 = t2;
	t2 = temp;
}

