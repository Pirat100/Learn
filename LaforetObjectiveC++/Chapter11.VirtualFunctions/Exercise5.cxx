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
    
    virtual bool isOversize() = 0;
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
    
    bool isOversize() {
    	if (pages > 800) {
    		cout << "Превышение размера!" << endl;
    		return true;
    	} 
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
    
    bool isOversize() {
    	if (time > 90) {
    		cout << "Превышение размера!" << endl;
    		return true;
    	}
    }
};

int main()
{
	book b;
	type t;

	b.getdata();
	b.isOversize();
	
	t.getdata();
	t.isOversize();
	return 0;
}

