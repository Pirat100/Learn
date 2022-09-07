#include <iostream>
#include <string>

using namespace std;

const int LEN = 80;
const int MAX = 40;

class Token
{
  public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};

class Operator : public Token
{
  private:
	char oper;

  public:
	Operator(char var)
	{
		oper = var;
	}
	char getOperator()
	{
		return oper;
	}
	float getNumber() {
		return 0;
	}
};

class Number : public Token
{
  private:
	float fnum;

  public:
	Number(float fvar)
	{
		fnum = fvar;
	}
	float getNumber()
	{
		return fnum;
	}
	char getOperator() {
		return '0';
	}
};

class Stack
{
  private:
	Token* token[MAX];
	int top;

  public:
	Stack()
	{
		top = 0;
	}

	void push(Token* var)
	{
		token[++top] = var;
	}

	Token* pop()
	{
		return token[top--];
	}

	int gettop()
	{
		return top;
	}
	
    bool isNumber() {
	    Number* numberPtr;
	    if (numberPtr = dynamic_cast<Number*>(token[top])) {
		    return true;
	    } else {
		    return false;
	    }
    }

};

int main()
{
	Stack s;
	Operator oplus('+'), ominus('-'), odivide('/'), omultiply('*');
	Number n1(2.4), n2(5.5), n3(87.2);
	s.push(&n1); s.push(&oplus); s.push(&n3);
	while(s.gettop() > 0) {
		if (s.isNumber()) {
		    cout << s.pop()->getNumber();
		} else {
			cout << s.pop()->getOperator();
		}
	}
	cout << endl;
	return 0;
}
