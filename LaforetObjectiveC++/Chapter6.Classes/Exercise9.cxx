#include <iostream>

using namespace std;

class fraction {
private:
	int dividend;
	int divider;
public:
    void setFraction() {
        char ch = '/';
        cout << "Введите дробь: ";
        cin >> dividend >> ch >> divider;
    }
    
    void getFraction() const {
    	cout << dividend << '/' << divider << endl;
    }
    
    void add(const fraction& f2) {
    	dividend = dividend * f2.divider + f2.dividend * divider;
    	divider = divider * f2.divider;
    }
};

int main()
{
    fraction f1, f2;
    char response = 'a';
    while(response != 'n') {
   	  f1.setFraction();
   	  f2.setFraction();
   	  f1.add(f2);
   	  f1.getFraction();
   	  cout << "Повторить операцию? (y/n): ";
   	  cin >> response;
    }
    return 0;
}