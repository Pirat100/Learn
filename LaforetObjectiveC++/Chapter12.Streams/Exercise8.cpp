#include <iostream>
#include <fstream>
#include <map>

using namespace std;

enum operation {ADD = 1, SHOW, WRITE, READ, EXIT};
map <string, operation> operations;

void defineOperationsMap() {
	operations["add"] = ADD;
	operations["show"] = SHOW;
	operations["write"] = WRITE;
	operations["read"] = READ;
	operations["exit"] = EXIT;
}

struct link {
	int data;
	link* next;
};

class linklist {
private:
	link* first;
	static fstream file;
public:
	linklist() {
		first = NULL;
	}
	void addItem(const int& d);
	void showItems();
	void writeItems();

	void readItems();

	static void openStream();
	void startUserApi();
};

fstream linklist::file;

void linklist::openStream() {
	file.open("C:\\Users\\Taras\\Desktop\\TEST.txt", ios::trunc | ios::in | ios::out);
}

void linklist::addItem(const int& d) {
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}

void linklist::showItems() {
	link* current = first;
	while (current) {
		cout << current->data << '\n';
		current = current->next;
	}

	file.seekg(0);
	file.clear();
}

void linklist::writeItems() {

	link* current = first;
	while (current) {
		file << current->data << '\n';
		current = current->next;
	}

	file.seekg(0);
	file.clear();
}

void linklist::readItems() {

	link* current = first;

	//Чистим список
	while (current) {
		first = current->next;
		delete current;
		current = first;
	}

	string data;
	while (getline(file, data)) {
		addItem(stoi(data));
	}

	file.seekg(0);
	file.clear();
}

void linklist::startUserApi() {
	char answer = 'y';
	do {
		cout << "Введите команду в формате (add ХХХ(где ХХХ это добавляемое число)/show/write/read)?: ";
	    string operation;
	    cin >> operation;
	    switch (operations[operation]) {
	    case ADD:
	    	int d;
	    	cin >> d;
		    addItem(d);
		    break;
	    case SHOW:
		    showItems();
		    break;
	    case WRITE:
		    writeItems();
		    break;
	    case READ:
		    readItems();
		    break;
	    case EXIT:
	    	cout << "Возвращайтесь еще!\n";
	    	exit(0);
	    default:
	    	cout << "Неправильно введена команда!\n";
	        break;
	    }
	} while (answer != 'n');
	file.close();
}

int main () {
	defineOperationsMap();
	linklist li;
	li.openStream();
	li.startUserApi();
	return 0;
}
