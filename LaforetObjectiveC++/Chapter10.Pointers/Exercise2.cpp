#include <iostream>
#include <cstring>
#include <Cctype>

using namespace std;

class String {
private:
	char* str;
public:
	String (char* s) {
		int length = strlen(s);
		str = new char[length + 1];
		strcpy(str, s);
	}

	~String() {
		cout << "Удаляем строку\n";
		delete[] str;
	}

	void upit() {
		char* cptr = str;
		while (*cptr) {
			*cptr = toupper(*cptr);
			++cptr;
		}
	}

	void display() {
	    cout << str << endl;
	}
};

int main()
{
	String s1 = "To be or not to be.";
	cout << "s1 = ";
	s1.display();
	s1.upit();
	s1.display();
    return 0;
}
