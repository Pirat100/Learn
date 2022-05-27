#include <iostream>

using namespace std;

class Foo {
private:
    static int counter;
    int number = counter;
public:
    Foo() {
    	++counter;
    }
    
    void getNumber() const {
    	cout << "Мой порядковый номер: " << number << endl;
    }
};

int Foo::counter = 1;

int main()
{
    Foo f1;
    Foo f2;
    Foo f3;
    f2.getNumber();
    f3.getNumber();
    f1.getNumber();
    return 0;
}