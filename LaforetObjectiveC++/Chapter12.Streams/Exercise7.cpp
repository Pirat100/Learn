#include <iostream>
#include <fstream>

using namespace std;

class Name {
private:
	string name;
	string surname;
	string otchestvo;
	int id;
	static fstream file;

public:
	void get_data();
	void put_data() const;

	void writeData();
	int countNames();
	void readData(const int& countOfNames);
	static void openStream();
};

fstream Name::file;

void Name::openStream() {
	file.open("C:\\Users\\Путь к файлу ... \\Desktop\\TEST.txt", ios::app | ios::in | ios::out);
}

void Name::get_data() {
	cout << "Введите имя: "; cin >> name;
	cout << "Введите фамилию: "; cin >> surname;
	cout << "Введите отчество: "; cin >> otchestvo;
	cout << "Введите номер работника: "; cin >> id;
}

void Name::put_data() const {
	cout << "\nИмя: " << name <<
			"\nФамилия: " << surname <<
			"\nОтчество: " << otchestvo <<
			"\nID: " << id;
}

void Name::writeData() {
	file << name << ' ' << surname << ' ' << otchestvo << ' ' << id << '\n';
}

int Name::countNames() {
	file.seekg(0);

	int count = 0;
    while (file >> name >> surname >> otchestvo >> id) {
		count++;
	}
    file.clear();
    return count;
}

void Name::readData(const int& countOfNames) {
	file.seekg(0);
	cout << "Введите номер запрашиваемой записи: ";
	int k;
	cin >> k;

	for (int i = 1; i < countOfNames; ++i) {
		file >> name >> surname >> otchestvo >> id;
		if (i == k) {
			return;
		}
	}
}

int main () {
	Name n;

	char answer;
	n.openStream();
	do {
		n.get_data();
		n.writeData();
		cout << "Продолжить (y/n)?: ";
		cin >> answer;
	} while (answer != 'n');

	int countOfNames = n.countNames();
	n.readData(countOfNames);
	n.put_data();

	return 0;
}
