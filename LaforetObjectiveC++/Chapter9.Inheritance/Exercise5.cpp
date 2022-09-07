#include <iostream>

using namespace std;

const int LEN = 80;
enum period { per_hour, per_week, per_month };

class employee {
private:
    char name[LEN];
    unsigned long number;
public:
    void getdata() {
    	cout << endl << "Введите фамилию работника: ";
    	cin >> name;
    	cout << "Введите номер: ";
    	cin >> number;
    }

    void putdata() const {
    	cout << endl << "Фамилия: " << name << ' ';
    	cout << "Номер: " << number;
    }
};

class employee2 : public employee {
private:
	double compensation;
    period p;
public:
    void getdata() {
    	employee::getdata();
    	cout << "Введите тип оплаты:(h - hour/w - week/m - month)? ";
    	char c_tip_oplati = 'a';
    	cin >> c_tip_oplati;
    	switch(c_tip_oplati) {
    	    case 'h': p = per_hour; break;
    	    case 'w': p = per_week; break;
    	    case 'm': p = per_month; break;
    	    default: cout << "Неправильный тип оплаты!"; exit(1);
    	}
    	cout << "Введите размер оплаты: ";
    	cin >> compensation;
    }

    void putdata() const {
        employee::putdata();
    	cout << endl << "Тип оплаты: ";
    	switch (p) {
    	    case per_hour: cout << "Почасовая; "; break;
    	    case per_week: cout << "Понедельная; "; break;
    	    case per_month: cout << "Помесячная; "; break;
    	    default: cout << "Тип оплаты не определен! ";
    	}
    	cout << "Ее размер составляет: " << compensation << endl;
    }
};

class manager : public employee2 {
private:
    char title[LEN];
    double dues;
public:
    void getdata() {
        employee2::getdata();
        cout << "Введите должность: ";
        cin >> title;
        cout << "Введите сумму взносов в гольф клуб: ";
        cin >> dues;
    }

    void putdata() const {
    	employee2::putdata();
    	cout << "Должность: " << title;
    	cout << "Сумма взносов в гольф клуб: " << dues;
	}
};

class scientist : public employee2 {
private:
    int pubs;
public:
    void getdata() {
    	employee2::getdata();
    	cout << "Введите количество публикаций: ";
    	cin >> pubs;
    }

    void putdata() const {
    	employee2::putdata();
    	cout << "Количество публикаций: " << pubs;
    }
};

class laborer : public employee2 {
};

int main()
{
    scientist s;
    s.getdata();

    s.putdata();
	return 0;
}
