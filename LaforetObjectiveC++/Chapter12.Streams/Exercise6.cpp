#include <iostream>
#include <fstream>

using namespace std;

class Name;

class Name {
private:
	string name;
	string surname;
	string otchestvo;
	int id;
public:
	void get_data();
	void put_data() const;

	void writeData();
	int countNames();
	void readData(int countOfNames);
};

void Name::get_data() {
	cout << "Введите имя: "; cin >> name;
	cout << "Введите фамилию: "; cin >> surname;
	cout << "Введите отчество: "; cin >> otchestvo;
	cout << "Введите номер работника: "; cin >> id;
	writeData();
}

void Name::put_data() const {
	cout << "\nИмя: " << name <<
			"\nФамилия: " << surname <<
			"\nОтчество: " << otchestvo <<
			"\nID: " << id;
}

void Name::writeData() {
	ofstream outfile;
	outfile.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::app | ios::out);
	outfile << name << ' ' << surname << ' ' << otchestvo << ' ' << id << '\n';
	outfile.close();
}

int countNames() {

	ifstream infile;
	infile.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::in);

	int count = 0;

	string name, surname, otchestvo;
	int id;
    while (infile >> name >> surname >> otchestvo >> id) {
		count++;
	}
	infile.close();

	return count;
}

void Name::readData(int countOfNames) {
	ifstream infile;
	infile.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::in);

	cout << "Введите номер запрашиваемой записи: ";
	int k;
	cin >> k;

	for (int i = 1; i < countOfNames; ++i) {
		infile >> name >> surname >> otchestvo >> id;
		if (i == k) {
			return;
		}
	}
}

int main () {
	Name n;

	char answer;
	do {
		n.get_data();
		cout << "Продолжить (y/n)?: ";
		cin >> answer;
	} while (answer != 'n');

	int countOfNames = countNames();
	n.readData(countOfNames);
	n.put_data();

	return 0;
}
