#include <iostream>

using namespace std;

struct time {
	int hours;
	int minutes;
	int seconds;
};

int main()
{
   struct time t1, t2, t3;
   char ch = 'a';
   cout << "Введите первое время в формате чч:мм:сс: ";
   cin >> t1.hours >> ch >> t1.minutes >> ch >> t1.seconds;
   long totalseconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
   cout << "Введите второе время в формате чч:мм:сс: ";
   cin >> t2.hours >> ch >> t2.minutes >> ch >> t2.seconds;
   long totalseconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
   long totalseconds3 = totalseconds1 + totalseconds2;
   t3.hours = totalseconds3 / 3600;
   int minutes_ost = totalseconds3 % 3600;
   t3.minutes = minutes_ost / 60;
   t3.seconds = totalseconds3 % (t3.hours * 3600 + t3.minutes * 60);
   if (t3.hours > 23) {
   	t3.hours -= 24;
   }
   cout << "Суммарное время равно:  " << t3.hours << ':' << t3.minutes << ':' << t3.seconds << endl;  
   return 0;
}
