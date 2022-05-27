#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class employee {
private:
	string name;
	long id;
public:
    void putdata() {
        cin >> name >> id;
    }
    void getdata() {
    	cout << name << ' ' << id << endl;
    }
};

int main() {
	int MAX = 100;
	employee emp[MAX];
	cout << "Введите количество служащих: ";
	cin >> MAX;
	for (int i = 0; i < MAX; ++i) {
		emp[i].putdata();
	}
	cout << "Вы ввели служащих: " << endl;
	for (int i = 0; i < MAX; ++i) {
		emp[i].getdata();
	}
	return 0;
}



