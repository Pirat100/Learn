#include <iostream>

using namespace std;

#include <string.h>
#include <stdlib.h>

class String {
private:
	enum { SZ = 80 };
	char str[SZ];
public:
	String() {
		strcpy(str, "");
	}
	String(char s[]) {
		strcpy(str, s);
	}
	void display() const {
		cout << str;
	}
	String operator+=(String ss) {
		if ((strlen(str) + strlen(ss.str)) < SZ) {
//			strcpy(str, ss.str);
			strcat(str, ss.str);
		} else {
			cout << "\nПереполнение!";
			exit(1);
		}
		return String(str);
	}
};

int main() {
	String s1 = "\nС рождеством!";
	String s2 = "С Новым годом!";
	String s3;

	s1.display();
	s2.display();
	s3.display();

	s1 += s2;

	s1.display();

	s3 = s1 += s2;

	s3.display();
	cout << endl;

	return 0;
}
