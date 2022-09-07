#include <iostream>
#include <fstream>

using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	void get_time() {
		while (true) {
		    cout << "Введите часы: ";
		    cin.unsetf(ios::skipws);
		    cin >> hours;
            if (hours < 0 || hours > 23) {
		    	cout << "Часы должны быть от 0 до 23!";
		        cin.clear(ios::failbit);
		    }
            if (cin.good()) {
            	cin.ignore(10, '\n');
            	break;
		    }
		    cin.clear();
		    cin.ignore(10, '\n');
		    cout << "Неверно введены часы!\n";
		}

		while (true) {
		    cout << "Введите минуты: ";
		    cin.unsetf(ios::skipws);
		    cin >> minutes;
            if (minutes < 0 || minutes > 59) {
		    	cout << "Минуты должны быть от 0 до 59!";
		        cin.clear(ios::failbit);
		    }
            if (cin.good()) {
            	cin.ignore(10, '\n');
            	break;
		    }
		    cin.clear();
		    cin.ignore(10, '\n');
		    cout << "Неверно введены минуты!\n";
		}

		while (true) {
		    cout << "Введите секунды: ";
		    cin.unsetf(ios::skipws);
		    cin >> seconds;
            if (seconds < 0 || seconds > 59) {
		    	cout << "Секунды должны быть от 0 до 59!";
		        cin.clear(ios::failbit);
		    }
            if (cin.good()) {
            	cin.ignore(100, '\n');
            	break;
		    }
		    cin.clear();
		    cin.ignore(10, '\n');
		    cout << "Неверно введены секунды!\n";
		}
	}

	void put_time() const {
		cout << "Время = " << hours << ':' << minutes << ':' << seconds << endl;
	}
};

int main () {
	char answer;
	Time t;
	do {
		t.get_time();
		t.put_time();
		cout << "\nПродолжить (y/n)?: ";
		cin >> answer;
		cin.ignore(100, '\n');
	} while (answer != 'n');

	return 0;
}
