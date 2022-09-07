#include <iostream>

using namespace std;

class sterling {
protected:
	long pounds;
	int shilings;
	int pence;
public:
    sterling() {}

    sterling(const long& po, const int& sh, const int& pe)
    : pounds(po)
    , shilings(sh)
    , pence(pe) {}

    sterling(double new_pounds) {
        pounds = static_cast<long>(new_pounds);
        double shilings_ost = (new_pounds - pounds) * 20;
        shilings = static_cast<int>(shilings_ost);
        double pence_ost = (shilings_ost - shilings) * 12;
        pence = static_cast<int>(pence_ost);
        if (pence > 11) {
  	      ++shilings;
  	      pence -= 12;
        }
        if (shilings > 19) {
        	++pounds;
  	      shilings -= 20;
        }
    }

    sterling getSterling() {
        cout << "Введите денежную сумму: ";
        cin >> pounds >> shilings >> pence;
        return sterling(pounds, shilings, pence);
    }

    void putSterling() {
    	char a = 163;
        cout << "Денежная сумма составляет: " << a << pounds << '.' << shilings << '.' << pence;
    }

    sterling operator+(const sterling& sterling2) const {
    	return sterling(double(sterling(pounds, shilings, pence)) + double(sterling2));
    }

    sterling operator*(const double& value2) const {
    	return sterling(double(sterling(pounds, shilings, pence)) * value2);
    }

    sterling operator/(const sterling& sterling2) const {
    	return sterling(double(sterling(pounds, shilings, pence)) / double(sterling2));
    }

    sterling operator/(const double& value2) const {
    	return sterling(double(sterling(pounds, shilings, pence)) / value2);
    }

    operator double() const {
        return pounds + static_cast<double>(shilings) / 20 + static_cast<double>(pence) / 20 / 12;
    }
};

class fraction {
protected:
	int dividend;
	int divider;
public:
	fraction() : dividend(0), divider(0) {}
	fraction(int dvdnd, int dvdr) : dividend(dvdnd), divider(dvdr) {}

    fraction inputFraction() {
        char cherta = '/';
        cin >> dividend >> cherta >> divider;
        return fraction(dividend, divider);
    }

    void printFraction() {
    	char cherta = '/';
    	cout << dividend << cherta << divider << endl;
    }
};

class sterfrac : public sterling, public fraction {
public:
	void getSterling() {
		char separator;
		cout << "Введите денежную сумму в формате \"х.х.х-х/х\":";
		cin >> pounds >> separator >> shilings >> separator >> pence >> separator >> dividend >> separator >> divider;
	}

	void putSterling() {
		cout << "Денежная сумма составляет: " << pounds << '.' << shilings << '.' << pence << '-' << dividend << '/' << divider << endl;
	}
};

int main()
{
    sterfrac s1;
    s1.getSterling();
    s1.putSterling();
    return 0;
}
