#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
  
using namespace std;
  
class bMoney { 
private: 
    long double money; 
public: 
    bMoney() : money(0) {} 
  
    bMoney(char s[]) : money(0) { 
        money = mstold(s); 
    } 
    bMoney(long double m) : money(m) {}
  
    void madd(const bMoney& m1, const bMoney& m2) { 
        money = m1.money + m2.money; 
    } 
  
    void putmoney() { 
        string s_money;
        getline(cin, s_money);
        money = mstold(s_money);      
    } 
  
    void getmoney() {
        string s_money = ldtoms(money);
        cout << s_money << endl;
    }
  
    long double mstold(string smoney) {
        char sresult[100];
        int counter = 0;
        int len = smoney.size();
        for (int i = 0; i < len; ++i) {
            if ((smoney[i] >='0' && smoney[i] <= '9') || smoney[i] == '.') { 
                sresult[counter] = smoney[i];
                ++counter;
            }
        }
        return atof(sresult);
    }
  
    string ldtoms(long double ldmoney) {
        string result = "$";
        if (ldmoney < 9999999999999999.00) {
            ostringstream os;
            os << setiosflags(ios::fixed) << setprecision(2) << ldmoney;
            string ustring = os.str();
            for (size_t i = 0; i < ustring.size(); ++i) {
                if (ustring.size() > 6) {
                    if ((ustring.size() - 1 - i) % 3 == 0 && i < ustring.size() - 4) {
                        result += ustring[i];
                        result += ',';
                    } else {
                        result += ustring[i];
                    }
                } else {
                    result += ustring[i];
                }
            }
        } else {
            cout << "Wrong input value";
            exit(0);
        }
        return result;
    }
    bMoney operator+(const bMoney& bm2) const {
        long double temp_money = money + bm2.money;
        return bMoney(temp_money);
    }
    bMoney operator-(const bMoney& bm2) const {
        long double temp_money = money - bm2.money;
        return bMoney(temp_money);
    }
    bMoney operator*(const long double& ld) const {
    	long double temp_money = money * ld;
    	return bMoney(temp_money);
    }
    bMoney operator/(const long double& ld) const {
    	long double temp_money = money / ld;
    	return bMoney(temp_money);
    }
    long double operator/(const bMoney& bm2) const {
    	long double temp_money = money / bm2.money;
    	return temp_money;
    }
    
    friend bMoney operator*(const long double& ld, const bMoney& bm) {
    	long double temp = ld * bm.money;
    	return bMoney(temp);
    }
    
    friend long double operator/(const long double& ld, const bMoney& bm) {
    	return ld / bm.money;
    }
 
    friend bMoney round(const bMoney& bm);
}; 

bMoney round(const bMoney& bm) {
    long double whole_part = static_cast<int>(bm.money);
    long double fractional_part = bm.money - whole_part;
    if (fractional_part >= 0.5) {
    	long double result = whole_part + 1;
    	return bMoney(result);
    } else {
    	return bMoney(whole_part);
    }
}
  
int main() {
    bMoney m1, m2;
    long double number = 0, result = 0;
    
    bMoney m3, m4, m5, m6, m7, m8;
    long double count_of_details = 0;
    
    char operation = 'y';
    while (operation == 'y') {
        cout << "Введите первую денежную сумму в формате \"$x xxx.xx\":";   
        m1.putmoney();    
        cout << "Введите вторую денежную сумму в формате \"$x xxx.xx\":";
        m2.putmoney();
        cout << "Введите количество изделий: ";
        cin >> number;
 
        m3 = m1 + m2;
        m4 = m1 - m2;
        m5 = (m1 + m2) * number;
        m6 = (m1 + m2)/ number;
        m7 = number * m1;
        result = number / m2;
        count_of_details = m1 / m2;
        m8 = round(m1);
   
        cout << "Общая сумма: ";
        m3.getmoney(); 
 
        cout << "Разность сумм: ";
        m4.getmoney();
        
        cout << "Общая сумма, умноженная на количество изделий: ";
        m5.getmoney();
        
        cout << "Общая сумма, деленная на количество изделий: ";
        m6.getmoney();
   
        cout << "Первая сумма, деленная на вторую сумму: " << count_of_details << endl;
        
        cout << "Число, умноженное на сумму денег: ";
        m7.getmoney();
        
        cout << "Сумма денег, деленная на число: " << result << endl;
        
        cout << "Первая денежная сумма, округленная до целого доллара равна: ";
        m8.getmoney();
        
        cout << "Повторить операцию?(y/n): "; 
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0; 
} 
 