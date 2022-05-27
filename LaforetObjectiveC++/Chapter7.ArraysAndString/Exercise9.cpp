#include <iostream>

using namespace std;

class Stack {
private:
	enum { MAX = 10 };
	int st[MAX];
	int top;
public:
	Stack() {
		top = 0;
	}
	void push(int var) {
		st[++top] = var;
	}
	int pop() {
		return st[top--];
	}
};

class Queue {
private:
	enum { MAX = 10 };
	int qu[MAX];
	int head;
	int tail;
public:
	Queue() {
		head = 0; tail = 0;
	}
	void put(int var) {
		qu[++tail] = var;
	}
	int get() {
		return qu[++head];
	}
};

int main() {
   Queue q1;
   q1.put(11);
   q1.put(22);
   cout << "1: " << q1.get() << endl;
   cout << "2: " << q1.get() << endl;
   q1.put(33);
   q1.put(44);
   q1.put(55);
   q1.put(66);
   cout << "3: " << q1.get() << endl;
   cout << "4: " << q1.get() << endl;
   cout << "5: " << q1.get() << endl;
   cout << "6: " << q1.get() << endl;
	return 0;
}
