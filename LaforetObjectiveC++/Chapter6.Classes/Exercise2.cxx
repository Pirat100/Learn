#include <iostream>

using namespace std;

class toolBooth {
private:
	unsigned int passedCars;
	double revenue;
	
public:
    toolBooth() : passedCars(0), revenue(0.0) { }
    
    void payingCar() {
    	++passedCars;
    	revenue += 0.50;
    }
    
    void nopayCar() {
    	++passedCars;
    }
    
    void display() const {
    	cout << "Количество проехавших автомобилей: " << passedCars << ", выручка: " << revenue << endl;
    }
};

int main()
{
	toolBooth tool;
	char response = 'a';
	while(response != 'e') {
	    cout << "Нажмите клавишу Y, чтобы заплатить за проезд, клавишу N, чтобы не платить или клавишу E, чтобы выйти и увидеть выручку и число проехавших автомобилей(y/n/e): ";
        cin >> response;
   	 switch(response) {
	    	case 'y': tool.payingCar(); break;
	    	case 'n': tool.nopayCar(); break;
	    }
	}
	tool.display();
	return 0;
}