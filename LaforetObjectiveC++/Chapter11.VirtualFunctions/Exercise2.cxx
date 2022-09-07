#include <iostream>

using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    virtual void getdata() {
        cout << "Введите название книги: "; cin >> title;
        cout << "Введите цену книги: "; cin >> price;
    }
    
    virtual void putdata() const {
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
	int n = 0;
//	const int SIZE = 100;
	publication* pubarr[n];
	char answer = 'n';
//	int n = 0;
	do {
		char choice = ' ';
		cout << "Введите обычную книгу (b - book) или аудиокнигу (t - type)? (b/t):";
		cin >> choice;
		if (choice == 'b') {
			pubarr[n] = new book;
		} else if (choice == 't') {
			pubarr[n] = new type;
		} else {
			cout << "Некорректный ввод.";
			exit(1);
		}
		pubarr[n++]->getdata();
		cout << "Ввести еще персону?";
		cin >> answer;
	} while (answer == 'y');
	
	for (int i = 0; i < n; i++) {
		pubarr[i]->putdata();
	}
	
	return 0;
}

