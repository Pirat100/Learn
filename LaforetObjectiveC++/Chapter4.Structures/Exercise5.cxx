#include <iostream>

using namespace std;

class date {
private:
	int day;
	int month;
	int year;
	
public:
    date getDate() {
    	cout << "Введите день, месяц и год в формате --/--/----: ";
    	char ch = '/';
    	cin >> day >> ch >> month >> ch >> year;
    }
    
    void showDate() const {
    	cout << "Вы ввели дату: " << day << '/' << month << '/' << year << endl;	
    }
};

int main()
{
	date date1;
    date1.getDate();
    date1.showDate();
	return 0;
}
