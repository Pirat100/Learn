#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Distance {
private:
	int feet;
	float inches;
public:
    Distance() {}
    Distance(int new_feet, float new_inches) : feet(new_feet), inches(new_inches) {}
    void get_dist() {
    	cout << endl << "Введите футы: ";
    	cin >> feet;
    	cout << "Введите дюймы: ";
    	cin >> inches;
    }
    
    void show_dist() {
    	cout << feet << "\'-" << inches << '\"';
    }
    
    void add_dist(Distance d1, Distance d2) {
    	inches = d1.inches + d2.inches;
    	feet = 0;
    	if (inches >= 12.0) {
    		inches -= 12.0;
    		feet++;
    	}
    	feet += d1.feet + d2.feet;
    }
    
    void div_dist(Distance d2, int divisor) {
    	float fltfeet = d2.feet + d2.inches / 12.0;
    	float temp = fltfeet /= divisor;
    	feet = int(fltfeet);
    	inches = (temp - feet) * 12.0;
    }
};

int main() {
	Distance dist[100];
	int n = 0;
	char ans;
	Distance result(0, 0.0);
	cout << endl;
	do {
		cout << "Введите длину номер " << n + 1;
		dist[n++].get_dist();
		cout << "Продолжить (y/n)?: ";
		cin >> ans;
	} while(ans != 'n');
	for (size_t i = 0; i < n; ++i) {
		result.add_dist(result, dist[i]);
	}
	result.div_dist(result, n);
	cout << "Среднее значение всех введенных длин равно: ";
	result.show_dist();
	return 0;
}



