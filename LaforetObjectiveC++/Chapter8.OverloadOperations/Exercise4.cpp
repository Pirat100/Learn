//Создайте класс Int, основанный на упражнении 1 из главы 6. Перегрузите четыре целочисленных арифметических
//операции (+, -, * и /) так, чтобы их можно было использовать для операций с объектами класса Int. Если
//результат какой-либо из операций выходит за границы типа int (в 32-битной системе), имеющие значение
//от 2 147 483 648
//до - 2 147 483 648
//то операция дложна послать сообщение об ошибке и завершить программу. Такие типы данных полезны там, где ошибки
//могут быть вызваны арифметическим переполнением, которое недопустимо.
//Подсказка: для облегчения проверки переполнения выполняйте вычисления с использованием типа long double.
//Напишите программу для проверки этого класса.

#include <iostream>

using namespace std;

class Int {
private:
	int value;
public:
    Int() : value(0) { }
    Int(const long double& val) : value(val) {
    	if ((val < -2147483648) || (val > 2147483648)) {
    		cout << "Overflow!" << endl;
    		exit(1);
    	}
    }

    void setValue(const int& new_value) {
    	value = new_value;
    }

    void printValue() const {
        cout << value << endl;
    }

    Int operator+(const Int& i2) const {
    	long double val = static_cast<long double>(value) + i2.value;
    	return Int(val);
    }

    Int operator-(const Int& i2) const {
    	long double val = static_cast<long double>(value) - i2.value;
    	return Int(val);
    }

    Int operator*(const Int& i2) const {
    	long double val = static_cast<long double>(value) * i2.value;
    	return Int(val);
    }

    Int operator/(const Int& i2) const {
    	long double val = static_cast<long double>(value) / i2.value;
    	return Int(val);
    }
};

int main()
{
	Int i1, i2, i3, i4, i5, i6;
	i1.setValue(10000000);
	i2.setValue(1000);
	i3 = i1 + i2;
	i3.printValue();
	i4 = i1 - i2;
	i4.printValue();
	i5 = i1 * i2;
	i5.printValue();
	i6 = i1 / i2;
	i6.printValue();
	return 0;
}
