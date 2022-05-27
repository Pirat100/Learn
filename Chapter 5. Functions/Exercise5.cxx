#include <iostream>

using namespace std;

long hms_to_secs(const int& hours, const int& minutes, const int& seconds);

int main() {
    int hours, minutes, seconds;
    char ch;
    char repeater = 'a';
    while (repeater != 'n') {
    	cout << "Введите время в формате чч:мм:сс: ";
    	cin >> hours >> ch >> minutes >> ch >> seconds;
    	int result = hms_to_secs(hours, minutes, seconds);
    	cout << "Общее количество секунд: " << result << endl;
    	cout << "Повторить операцию? (y/n) ";
    	cin >> repeater;
    }
    return 0;
}

long hms_to_secs (const int& hours, const int& minutes, const int& seconds) {
	long total_seconds = hours * 3600 + minutes * 60 + seconds;
	return total_seconds;
}