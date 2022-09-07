#include <iostream>
#include <cstring>

using namespace std;

struct link {
	int data;
	link* next;
};

class linklist {
private:
	link* first;
public:
	linklist() { first = NULL; }

	~linklist();
	void addItem(int d);
	void display();
};

void linklist::addItem(int d) {
	link* newlink = new link;
	newlink->data = d;
	if (first == nullptr) {
		first = newlink;
	} else {
		link* temp = first;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = newlink;
	}
	newlink->next = nullptr;
}

void linklist::display() {
	link* current = first;
	while(current) {
		cout << "Добавлен элемент: " << current->data << endl;
		current = current->next;
	}
}

linklist::~linklist() {
	link* current = first;
	while(current) {
		link* temp = current;
		cout << "Удален элемент: " << temp->data << endl;
		current = current->next;
		delete temp;
	}
}

int main()
{
	linklist li;
	li.addItem(25);
	li.addItem(36);
	li.addItem(49);
	li.addItem(64);

	li.display();
    return 0;
}


