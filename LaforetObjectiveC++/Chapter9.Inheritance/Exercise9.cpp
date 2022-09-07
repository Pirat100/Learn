#include <iostream>

using namespace std;

class date {
private:
	int day;
	int month;
	int year;

public:
	date() : day(0), month(0), year(0) {}
	date(int d, int m, int y) : day(d), month(m), year(y) {}

    date getDate() {
    	cout << "Введите день, месяц и год в формате --/--/----: ";
    	char ch = '/';
    	cin >> day >> ch >> month >> ch >> year;
    	return date(day, month, year);
    }

    void showDate() const {
    	cout << "Вы ввели дату: " << day << '/' << month << '/' << year << endl;
    }
};

class publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите название книги: "; cin >> title;
        cout << "Введите цену книги: "; cin >> price;
    }

    void putdata() const {
        cout << "Название книги: " << title << endl;
        cout << "Цена книги: " << price << endl;
    }
};

class publication2 : public publication {
protected:
	date release_date;
public:
	void getdata() {
		publication::getdata();
		release_date.getDate();
	}

	void putdata() const {
		publication::putdata();
		release_date.showDate();
	}
};

class book : public publication2 {
private:
    int pages;
public:
    void getdata() {
        publication2::getdata();
        cout << "Введите количество страниц в книге: "; cin >> pages;
    }

    void putdata() const {
    	publication2::putdata();
    	cout << "Количество страниц в книге: " << pages << endl;
    }
};

class type : public publication2 {
private:
    float time;
public:
    void getdata() {
    	publication2::getdata();
    	cout << "Введите время записи книги в минутах: "; cin >> time;
    }

    void putdata() const {
    	publication2::putdata();
    	cout << "Время записи книги в минутах: " << time << endl;
    }
};

int main()
{
	publication2 p2;
	book b;
	type t;

	p2.getdata();
	p2.putdata();

	b.getdata();
	b.putdata();

	t.getdata();
	t.putdata();
	return 0;
}


