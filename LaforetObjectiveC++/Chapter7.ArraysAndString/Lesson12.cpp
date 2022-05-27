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

    void madd(const bMoney& m1, const bMoney& m2) {
    	money = m1.money + m2.money;
    }

    void putmoney() {
    	string s_money;
	    cout << "Input sum in format \"$x xxx.xx\":";
	    getline(cin, s_money);
	    money = mstold(s_money);
    }

    void getmoney() {
    	string s_money = ldtoms(money);
    	cout << "Sum of money: " << s_money;
    }

	long double mstold(string smoney) {
		char sresult[100];
		int counter = 0;
		int len = smoney.size();
		for (int i = 0; i < len; ++i) {
			if ((smoney[i] >= '0' && smoney[i] <= '9') || smoney[i] == '.') {
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
};
//
//int main() {
//	bMoney m1, m2, m3;
//	m1.putmoney();
//	m2.putmoney();
//	m3.madd(m1, m2);
//	m3.getmoney();
//	return 0;
//}


