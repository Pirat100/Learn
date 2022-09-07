#include <iostream>

using namespace std;

class Counter {
protected:
	unsigned int count;
public:
	Counter() : count() {}
	Counter(int c) : count(c) {}
	unsigned int get_count() const {
		return count;
	}
	Counter operator++() {
		return Counter(++count);
	}
};

class CountDn : public Counter {
public:
	CountDn() : Counter() {}
	CountDn(int c) : Counter(c) {}
	CountDn operator--() {
		return CountDn(--count);
	}
};

class Counter2 : public Counter {
public:
	Counter2() : Counter() {}
	Counter2(int c) : Counter(c) {}
	Counter2 operator++(int) {
		return Counter2(count++);
	}

	Counter2 operator--(int) {
		return Counter2(count--);
	}

	operator int() {
		return count;
	}
};

int main() {
	Counter counter;
	++counter;
	++counter;
	cout << counter.get_count() << endl;

    CountDn counterdn = 5;
	--counterdn;
	--counterdn;
	cout << counterdn.get_count() << endl;

	Counter2 counter2;
    int result = counter2++;
    cout << result << ' ' << counter2 << endl;

    result = counter2--;
    cout << result << ' ' << counter2 << endl;
	return 0;
}
