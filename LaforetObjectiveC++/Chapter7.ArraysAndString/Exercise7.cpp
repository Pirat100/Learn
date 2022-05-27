#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>

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
};

int main() {
	string s_money;
	cout << "Input sum in format \"$ x xxx.xx\":";
	getline(cin, s_money);
	money m;
	long double result = m.mstold(s_money);
	cout << "Sum in new format: " << result << endl;
	return 0;
}


