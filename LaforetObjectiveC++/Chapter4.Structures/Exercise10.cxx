#include <iostream>

using namespace std;

struct sterling {
	int pounds;
	int shilings;
	int pence;
};

int main()
{
  double new_funt;
  cout << "Введите денежную сумму в новых десятичных фунтах: ";
  cin >> new_funt;
  sterling s;
  s.pounds = static_cast<int>(new_funt);
  double shiling_ost = (new_funt % s.pounds) * 20;
  s.shilings = static_cast<int>(shiling_ost);
  double pence_ost = (shiling_ost / s.shilings) * 12;
  s.pence = static_cast<int>(pence_ost);
  cout << "По старой системе данная денежная сумма составляет " << s.pounds << " фунтов, " << s.shilings << " шилингов, " << s.pence << " пенсов.";
  return 0;
}
