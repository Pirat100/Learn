#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int compstr(char* ch1, char* ch2);
	char* s1 = "abcdefg";
	char* s2 = "abcdefh";
	cout << compstr(s1, s2) << endl;
    return 0;
}

int compstr(char* ch1, char* ch2) {
	int i = 0;
	char* temp = ch1;
	while(*temp) {
		if (*(ch1 + i) > *(ch2 + i)) {
     	    return 1;
	    } else if (*(ch1 + i) < *(ch2 + i)) {
	    	return -1;
		} else {
		    ++i;
		    ++temp;
		}
	}
	return 0;
}
