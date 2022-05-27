#include <iostream>

using namespace std;

struct phone {
	int city_code;
	int station_number;
	int abonent_number;
};

int main()
{
	phone phone1 = {212, 767, 8900};
	phone phone2;
	cout << "Введите код города, номер телефонной станции и номер абонента: ";
	cin >> phone2.city_code >> phone2.station_number >> phone2.abonent_number;
	cout << "Первый номер телефона: " << phone1.city_code << '-' << phone1.station_number << '-' << phone1.abonent_number << endl;
	cout << "Второй номер телефона: " << phone2.city_code << '-' << phone2.station_number << '-' << phone2.abonent_number << endl;		
	return 0;
}