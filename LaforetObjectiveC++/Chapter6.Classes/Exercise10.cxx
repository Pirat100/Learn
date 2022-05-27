#include <iostream>

using namespace std;

class angle {
private:
    int gradus;
    float minute;
    char direction;
public:
    angle() { }
    
    angle(const int& grad, const float& min, const char& dir) : gradus(0), minute(0.0f), direction('E') {
    	gradus = grad;
    	minute = min;
    	direction = dir;
    }
    
    void setAngle() {
    	cout << "Введите градусы и минуты по широте через пробел, а также направление (N/E/S/W): ";
    	cin >> gradus >> minute >> direction;
    }
    
    void printAngle() const {
    	cout << gradus << '\xF8' << minute << "\' " << direction << endl;
    }
};

class ship {
private:
    static int counter;
    int number = counter;
    angle horizontal;
    angle vertical;
public:
    ship() {
    	++counter;
    }
    
    int getNumber() const {
    	return number;
    }
    
    void setShip() {
    	horizontal.setAngle();
    	vertical.setAngle();
    }
    
    void printShip() const {
    	cout << "Номер корабля: " << number << endl;
    	horizontal.printAngle();
    	vertical.printAngle();
    }
};

int ship::counter = 0;

int main()
{
    ship ship1, ship2, ship3;
    ship1.setShip();
    ship2.setShip();
    ship3.setShip();
    ship1.printShip();
    ship3.printShip();
    ship2.printShip();
    return 0;
}