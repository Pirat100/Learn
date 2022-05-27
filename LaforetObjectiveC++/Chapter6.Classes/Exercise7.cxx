#include <iostream>

using namespace std;

class angle {
private:
    int gradus;
    float minute;
    char direction;
public:
    angle(int grad, float min, char dir) : gradus(0), minute(0.0f), direction('E') {
    	gradus = grad;
    	minute = min;
    	direction = dir;
    }
    
    void setAngle() {
    	cout << "Введите градусы и минуты по широте через пробел, а также направление (N/E/S/W): ";
    	cin >> gradus >> minute >> direction;
    }
    
    void printAngle() {
    	cout << gradus << '\xF8' << minute << "\' " << direction << endl;
    }
};

int main()
{
    angle a(122, 28.7, 'E');
    a.printAngle();
    char ch = 'a';
    while (ch != 'n') {
    	a.setAngle();
    	a.printAngle();
    	cout << "Повторить операцию? (y/n): ";
    	cin >> ch;
    }
    return 0;
}