#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    enum { SZ = 80 };
    char str[SZ];
public:
    String() {
        str[0] = '\x0';
    }

    String(char s[]) {
        strcpy(str, s);
    }

    void display() const {
        cout << str;
    }

    operator char*() {
        return str;
    }
};

class PString : public String {
public:
    PString() {
    	str[0] = '\x0';
    }
    PString(char s[]) {
        if (strlen(s) >= SZ) {
            char temp[SZ];
            for (size_t i = 0; i < SZ - 1; ++i) {
                temp[i] = s[i];
            }
            strcpy(str, temp);
        } else {
            strcpy(str, s);
        }
    }
};

class PString2 : public PString {
public:
	PString2() : PString() {}
	PString2(char s[]) : PString(s) {}
	PString2& left(PString2 ps2, int n) {
		for (int i = 0; i < n; ++i) {
			str[i] = ps2.str[i];
		}
		return *this;
	}

	PString2& mid(PString2 ps2, int s, int n) {
		for (int i = s; i < n; ++i) {
			str[i] = ps2.str[i];
		}
		return *this;
	}

	PString2 right(PString2 ps2, int n) {
		for (int i = n; i < SZ; ++i) {
			str[i] = ps2.str[i];
		}
		return *this;
	}
};

int main()
{
	PString2 ps2 = "Мы должны победить!";
	PString2 ps3 = "Сурок спокойный зверек";
	PString2 ps4;
	ps2.display();
	cout << endl;

	ps4 = ps2.left(ps3, 15);
	ps4.display();
	return 0;
}
