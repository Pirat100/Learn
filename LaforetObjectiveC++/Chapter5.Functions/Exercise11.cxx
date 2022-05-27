#include <iostream>

using namespace std;

struct sterling {
	int pounds;
	int shilings;
	int pence;
};

sterling inputFunts(const int& funts, const int& shilings, const int& pences);
sterling sumOfSterlings(const sterling& s1, const sterling& s2);
void printSterling(const sterling& s);

int main()
{
  sterling s1, s2, s3;
  cout << "Введите первую денежную сумму в фунтах, шилингах и пенсах: ";
  cin >> s1.pounds >> s1.shilings >> s1.pence;
  cout << "Введите вторую денежную сумму в фунтах, шилингах и пенсах: ";
  cin >> s2.pounds >> s2.shilings >> s2.pence;
  s3.pounds = s1.pounds + s2.pounds;
  s3.shilings = s1.shilings + s2.shilings;
  s3.pence = s1.pence + s2.pence;
  if (s3.pence > 11) {
  	++s3.shilings;
  	s3.pence -= 12;
  }
  if (s3.shilings > 19) {
  	++s3.pounds;
  	s3.shilings -= 20;
  }
  cout << "По старой системе данная денежная сумма составляет " << s.pounds << " фунтов, " << s.shilings << " шилингов, " << s.pence << " пенсов.";
  return 0;
}


