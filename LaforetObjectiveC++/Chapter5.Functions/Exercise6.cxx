#include <iostream>

using namespace std;

struct time {
	int hours;
	int minutes;
	int seconds;
};

long time_to_secs(const struct time& t);
struct time secs_to_time(const long& seconds);

int main()
{
   struct time t1, t2, t3;
   char ch = 'a';
   cout << "Введите первое время в формате чч:мм:сс: ";
   cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
   cout << "Введите второе время в формате чч:мм:сс: ";
   cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
   long totalseconds3 = time_to_secs(t1) + time_to_secs(t2);
   t3 = secs_to_time(totalseconds3);
   cout << "Суммарное время равно:  " << t3.hours << ':' << t3.minutes << ':' << t3.seconds << endl;  
   return 0;
}

long time_to_secs(const struct time& t) {
	long total_seconds = t.hours * 3600 + t.minutes * 60 + t.seconds;
	return total_seconds;
}

struct time secs_to_time(const long& seconds) {
	struct time t;
	t.hours = seconds / 3600;
	t.minutes = (seconds - t.hours * 3600) / 60;
	t.seconds = seconds - t.hours * 3600 - t.minutes * 60;
	if (t.hours > 23) {
		t.hours -= 24;
	}
	return t;
}