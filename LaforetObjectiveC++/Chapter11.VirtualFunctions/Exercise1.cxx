#include <iostream>

using namespace std;

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

class book : public publication {
private:
    int pages;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите количество страниц в книге: "; cin >> pages;
    }
    
    void putdata() const {
    	publication::putdata();
    	cout << "Количество страниц в книге: " << pages << endl;
    }
};

class type : public publication {
private:
    float time;
public:
    void getdata() {
    	publication::getdata();
    	cout << "Введите время записи книги в минутах: "; cin >> time;
    }
    
    void putdata() const {
    	publication::putdata();
    	cout << "Время записи книги в минутах: " << time << endl;
    }
};

int main()
{
	publication p;
	book b;
	type t;
	
	p.getdata();
	p.putdata();
	
	b.getdata();
	b.putdata();
	
	t.getdata();
	t.putdata();
	return 0;
}

