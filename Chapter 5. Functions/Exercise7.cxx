#include <iostream>

using namespace std;

double power(const double& n, const int& p = 2);
double power(const char& n, const int& p = 2);
double power(const int& n, const int& p = 2);
double power(const long& n, const int& p = 2);
double power(const float& n, const int& p = 2);

int main() {
    long n;
    int p;
    cout << "Введите число и через пробел степень, в которую надо его возвести: ";
    cin >> n >> p;
    float result = power(n, p);
    cout << "Число " << n << " в степени " << p << " равно " << result << endl;
	return 0;
}

double power(const double& n, const int& p) {
    if (p > 1) {
        return n * power (n, p - 1);
    } else {
    	return n;
    }
}

double power(const char& n, const int& p) {
    if (p > 1) {
        return static_cast<double>(n) * power (static_cast<double>(n), p - 1);
    } else {
    	return static_cast<double>(n);
    }
}

double power(const int& n, const int& p) {
    if (p > 1) {
        return static_cast<double>(n) * power (static_cast<double>(n), p - 1);
    } else {
    	return static_cast<double>(n);
    }
}

double power(const long& n, const int& p) {
    if (p > 1) {
        return static_cast<double>(n) * power (static_cast<double>(n), p - 1);
    } else {
    	return static_cast<double>(n);
    }
}

double power(const float& n, const int& p) {
    if (p > 1) {
        return static_cast<double>(n) * power (static_cast<double>(n), p - 1);
    } else {
    	return static_cast<double>(n);
    }
}