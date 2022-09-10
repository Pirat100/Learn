#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <limits>

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
    friend istream& operator >> (istream& is, bMoney& bm);
    friend ostream& operator << (ostream& os, bMoney& bm);
};

istream& operator >> (istream& is, bMoney& bm) {
    string s_money;
    getline(is, s_money);
    bm.money = bm.mstold(s_money);
    return is;
}

ostream& operator << (ostream& os, bMoney& bm) {
    string s_money = bm.ldtoms(bm.money);
    os << s_money << endl;
    return os;
}

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
        cin >> m1;
        cout << "Введите вторую денежную сумму в формате \"$x xxx.xx\":";
        cin >> m2;
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
        cout << m3;

        cout << "Разность сумм: ";
        cout << m4;

        cout << "Общая сумма, умноженная на количество изделий: ";
        cout << m5;

        cout << "Общая сумма, деленная на количество изделий: ";
        cout << m6;

        cout << "Первая сумма, деленная на вторую сумму: " << count_of_details << endl;

        cout << "Число, умноженное на сумму денег: ";
        cout << m7;

        cout << "Сумма денег, деленная на число: " << result << endl;

        cout << "Первая денежная сумма, округленная до целого доллара равна: ";
        cout << m8;

        cout << "Повторить операцию?(y/n): ";
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}


