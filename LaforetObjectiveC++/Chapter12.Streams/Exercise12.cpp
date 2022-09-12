#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;
#include <process.h>

const int LEN = 32;
const int MAXEM = 100;

enum employee_type { tmanager, tscientist, tlaborer };

class employee {
private:
	char name[LEN];                   // фамилия работника
	unsigned long number;             // номер оаботника
	static int n;                     // текущее число работников
	static employee* arrap[];         // массив указателей на класс работников
public:
	virtual void getdata() {
		cin.ignore(10, '\n');
		cout << " Введите фамилию: ";
		cin >> name;
		cout << " Введите номер: ";
		cin >> number;
	}

	virtual void putdata() {
		cout << "\n Фамилия: " << name;
		cout << "\n Номер: " << number;
	}

	virtual int get_number() {
		return this->number;
	}

	virtual employee_type get_type(); // получить тип
	static void add();                // добавить работника
	static void display();            // вывести данные обо всех
	static void read();               // чтение из файла
	static void write();              // запись в файл
	static void find();               // поиск работника по номеру
};

int employee::n;
employee* employee::arrap[MAXEM];

class manager : public employee {
private:
	char title[LEN];
	double dues;
public:
	void getdata() {
		employee::getdata();
		cout << " Введите титул: ";
		cin >> title;
		cout << " Введите налоги: ";
		cin >> dues;
	}

	void putdata() {
		employee::putdata();
		cout << "\n Титул: " << title;
		cout << "\n Налоги гольф-клуба: " << dues;
	}
};

class scientist : public employee {
private:
	int pubs;
public:
	void getdata() {
		employee::getdata();
		cout << " Введите число публикаций: ";
		cin >> pubs;
	}

	void putdata() {
		employee::putdata();
		cout << "\n Число публикаций: " << pubs;
	}
};

class laborer : public employee {

};

void employee::add() {
	char ch;
	cout << "'m' для добавления менеджера"
			"\n's' для добавления ученого"
			"\n'l' для добавления рабочего"
			"\nВаш выбор: ";
	cin >> ch;
	switch (ch) {
	case 'm':
    	arrap[n] = new manager;
        break;
    case 's':
    	arrap[n] = new scientist;
    	break;
    case 'l':
    	arrap[n] = new laborer;
    	break;
    default:
    	cout << "\nНеизвестный тип работника\n";
    	return;
	}
	arrap[n++]->getdata();       // Получить данные от пользователя
}

void employee::display() {
	for (int i = 0; i < n; ++i) {
		cout << (i + 1);
		switch (arrap[i]->get_type()) {
		case tmanager:
			cout << ". Тип: Менеджер";
			break;
		case tscientist:
			cout << ". Тип: Ученый";
			break;
		case tlaborer:
			cout << ". Тип: Рабочий";
			break;
		default:
			cout << ". Неизвестный тип";
		}
		arrap[i]->putdata();
		cout << endl;
	}
}

employee_type employee::get_type() {
	if (typeid(*this) == typeid(manager)) {
		return tmanager;
	} else if (typeid(*this) == typeid(scientist)) {
		return tscientist;
	} else if (typeid(*this) == typeid(laborer)) {
		return tlaborer;
	} else {
		cerr << "\nНеправильный тип работника";
		exit(1);
	}
	return tmanager;
}

void employee::write() {
	int size;
	cout << "Идет запись " << n << " работников.\n";
	ofstream ouf;
	employee_type etype;

	ouf.open("C:\\Users\\Путь к файлу... \\Desktop\\TEST.txt", ios::trunc | ios::binary);
	if (!ouf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		etype = arrap[i]->get_type();

		ouf.write((char*)&etype, sizeof(etype));
		switch (etype) {
		case tmanager:
			size = sizeof(manager);
			break;
		case tscientist:
			size = sizeof(scientist);
			break;
		case tlaborer:
			size = sizeof(laborer);
			break;
		}

		ouf.write((char*)(arrap[i]), size);
		if (!ouf) {
			cout << "\nЗапись в файл невозможна\n";
			break;
		}
	}
}

void employee::read() {
	int size;
	employee_type etype;
	ifstream inf;
	inf.open("C:\\Users\\Путь к файлу... \\Desktop\\TEST.txt", ios::binary);

	if (!inf) {
		cout << "\nНевозможно открыть файл\n";
		return;
	}
	n = 0;

	while (true) {
		inf.read((char*)&etype, sizeof(etype));
		if (inf.eof()) {
			break;
		}
		if (!inf) {
			cout << "\nНевозможно чтение типа\n";
			return;
		}
		switch (etype) {
		case tmanager:
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default:
			cout << "\nНеизвестный тип в файле\n";
			return;
		}

		inf.read((char*)arrap[n], size);

		if (!inf) {
			cout << "\nЧтение данных из файла невозможно\n";
			return;
		}
		n++;
	}
	cout << "Идет чтение " << n << " работников\n";
}

void employee::find() {
	int number;
	cout << "Введите номер работника для поиска: ";
	cin >> number;
	for (int i = 0; i < n; ++i) {
		if (number == arrap[i]->get_number()) {
	        switch (arrap[i]->get_type()) {
	        case tmanager:
		        cout << " Тип: Менеджер";
		        break;
	        case tscientist:
		        cout << " Тип: Ученый";
		        break;
	        case tlaborer:
		        cout << " Тип: Рабочий";
		        break;
	        default:
		        cout << " Неизвестный тип";
	        }
	        arrap[i]->putdata();
	        cout << endl;
		} else {
			cout << "Работника с таким номером не существует!\n";
			break;
		}
	}
}

int main() {
	char ch;
	while (true) {
		cout << "'a' - добавление сведений о работнике"
				"\n'd' - вывести сведения обо всех работниках"
				"\n'w' - записать все даннные в файл"
				"\n'r' - прочитать все данные из файла"
				"\n'f' - найти работника по его номеру"
				"\n'x' - выход"
				"\nВаш выбор: ";
		cin >> ch;
		switch (ch) {
		case 'a':
			employee::add();
			break;
		case 'd':
			employee::display();
			break;
		case 'w':
			employee::write();
			break;
		case 'r':
			employee::read();
			break;
		case 'f':
			employee::find();
			break;
		case 'x':
			exit(0);
		default:
			cout << "\nНеизвестная команда";
		}
	}
	return 0;
}
