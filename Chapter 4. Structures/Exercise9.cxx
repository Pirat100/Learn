#include <iostream>

using namespace std;

struct time {
	int hours;
	int minutes;
	int seconds;
};

int main()
{
   struct time t;
   char ch = 'a';
   cout << "Введите время в формате чч:мм:сс: ";
   cin >> t.hours >> ch >> t.minutes >> ch >> t.seconds;
   long totalseconds = t.hours * 3600 + t.minutes * 60 + t.seconds;
   cout << "Количество секунд равно: " << totalseconds << " секунд." << endl;  
   return 0;
}