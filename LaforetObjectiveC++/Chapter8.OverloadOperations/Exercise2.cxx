#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class String {
private:
    enum { SZ = 80 };
    char str[SZ];
public:
    String() { strcpy(str, ""); }
    String(char s[]) {
        strcpy(str, s);	
    }
    void display() const {
        cout << str;	
    }
    String operator+=(String ss) const {
    	String temp;
    	if (strlen(str) + strlen(ss.str) < SZ) {
    		strcpy(temp.str, str);
    		strcat(temp.str, ss.str);
    	} else {
    		cout << "\nПереполнение!";
    		exit(1);
    	}
    	return temp;
    }
};

int main()
{
    String s1 = "\nС Рождеством! ";
    String s2 = "С Новым годом!";
    String s3;
    
    s1.display();
    s2.display();
    s3.display();
    
    s3 = s1 + s2;
    
    s3.display();
    cout << endl;
	return 0;
}