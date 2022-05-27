#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace std;

class money {
private:

public:
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

//int main() {
//	long double s_money;
//	cout << "¬ведите денежную сумму в формате \"xxxx.xx\":";
//	cin >> s_money;
//	money m;
//	string result = m.ldtoms(s_money);
//	cout << "¬веденна€ вами сумма: " << result << endl;
//	return 0;
//}


