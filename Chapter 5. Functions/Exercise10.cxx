#include <iostream>

using namespace std;

int counter_global = 0;

void how_many_times_local();
void how_many_times_global();

int main() {
	for (int i = 0; i < 10; ++i) {
		how_many_times_local();
	}
	for (int i = 0; i < 15; ++i) {
		how_many_times_global();
	}
	return 0;
}

void how_many_times_local() {
	static int counter_local = 0;
	cout << "Эта функция вызывалась " << ++counter_local << " раз." << endl;
}

void how_many_times_global() {
	cout << "А эта фукция вызывалась " << ++counter_global << " раз." << endl;
}

