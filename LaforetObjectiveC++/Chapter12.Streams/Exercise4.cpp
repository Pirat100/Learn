#include <iostream>
#include <fstream>

using namespace std;

int main () {
	string name, surname, otchestvo;
	unsigned long id;

	ofstream outfile;
	outfile.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::binary | ios::out);

	char answer;
	do {
		cout << "Введите имя: "; cin >> name;
		cout << "Введите фамилию: "; cin >> surname;
		cout << "Введите отчество: "; cin >> otchestvo;
		cout << "Введите номер работника: "; cin >> id;
		cout << "Продолжить (y/n)?: "; cin >> answer;

		outfile << name << ' ' << surname << ' ' << otchestvo << ' ' << id << '\n';
	} while (answer != 'n');

	outfile.close();

	ifstream infile;
	infile.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::binary | ios::in);

	char ch;
	while (infile.get(ch)) {
		cout << ch;
	}

	infile.close();
	return 0;
}
