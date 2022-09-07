#include <iostream>

using namespace std;

struct Pair {
	int x;
	int y;
};

class Stack {
protected:
	enum { MAX = 40 };
	int st[MAX];
	int top;
public:
	Stack() {
		top = -1;
	}

	void push(int var) {
		st[++top] = var;
	}

	int pop() {
		return st[top--];
	}
};

class Stack2 : public Stack {
public:
	void push(int var) {
		if (top >= MAX - 1) {
			cout << "\nОшибка: стек полон";
			exit(1);
		} else {
			Stack::push(var);
		}
	}

	int pop() {
		if (top < 0) {
			cout << "\nОшибка: стек пуст\n";
			exit(1);
		} else {
			return Stack::pop();
		}
	}
};

class PairStack : public Stack2 {
public:
	void push(Pair p) {
		Stack2::push(p.x);
		Stack2::push(p.y);
	}

	Pair pop() {
		Pair p;
		p.y = Stack2::pop();
		p.x = Stack2::pop();
		return p;
	}
};

int main() {
	Pair p1 = {7,8}, p2 = {10,11}, p3 = {25,14};
	PairStack ps;
	ps.push(p1);
	ps.push(p2);
	ps.push(p3);
	Pair p = ps.pop();
	cout << p.x << ' ' << p.y << endl;
    p = ps.pop();
	cout << p.x << ' ' << p.y << endl;
    p = ps.pop();
	cout << p.x << ' ' << p.y << endl;
    p = ps.pop();
	cout << p.x << ' ' << p.y << endl;
	return 0;
}
