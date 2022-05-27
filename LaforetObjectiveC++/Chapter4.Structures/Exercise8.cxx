#include <iostream>

using namespace std;

struct fraction {
	int dividend;
	int divider;
};

int main()
{
   fraction fr1;
   fraction fr2;
   fraction fr3;
   char ch = 'a';
   cout << "Введите первую дробь: ";
   cin >> fr1.dividend >> ch >> fr1.divider;
   cout << "Введите вторую дробь: ";
   cin >> fr2.dividend >> ch >> fr2.divider;
   cout << "Сумма равна: ";
   fr3.dividend = fr1.dividend * fr2.divider + fr2.dividend * fr1.divider;
   fr3.divider = fr1.divider * fr2.divider;
   cout << fr3.dividend << '/' << fr3.divider << endl;
   return 0;
}
