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
	float getNumber()
	{
		return 0.0;
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
	char getOperator()
	{
		return ' ';
	}
};

class Stack
{
  private:
	char st[MAX];
	int top;

  public:
	Stack()
	{
		top = 0;
	}

	void push(char var)
	{
		st[++top] = var;
	}

	char pop()
	{
		return st[top--];
	}

	int gettop()
	{
		return top;
	}
};

class express
{
  private:
	Stack s;
	char* pStr;
	int len;

  public:
	express(char *ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}

	void parse();
	int solve();
};

void express::parse()
{
	char ch;
	char lastval;
	char lasttop;

	for (int i = 0; i < len; ++i)
	{
		ch = pStr[i];
		if (ch >= '0' && ch <= '9')
		{
			s.push(ch - '0');
		}
		else
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if (s.gettop() == 1)
				{
					s.push(ch);
				}
				else
				{
					lastval = s.pop();
					lasttop = s.pop();
					if ((ch == '*' || ch == '/') && (lasttop == '+' || lasttop == '-'))
					{
						s.push(lasttop);
						s.push(lastval);
					}
					else
					{
						switch (lasttop)
						{
						case '+':
							s.push(s.pop() + lastval);
							break;
						case '-':
							s.push(s.pop() - lastval);
							break;
						case '*':
							s.push(s.pop() * lastval);
							break;
						case '/':
							s.push(s.pop() / lastval);
							break;
						default:
							cout << "\nНеизвестный оператор!";
							exit(1);
						}
					}
					s.push(ch);
				}
			}
			else
			{
				cout << "\nНеизвестный символ!";
				exit(1);
			}
		}
	}
}

int express::solve()
{
	char lastval;
	while (s.gettop() > 1)
	{
		lastval = s.pop();
		switch (s.pop())
		{
		case '+':
			s.push(s.pop() + lastval);
			break;
		case '-':
			s.push(s.pop() - lastval);
			break;
		case '*':
			s.push(s.pop() * lastval);
			break;
		case '/':
			s.push(s.pop() / lastval);
			break;
		default:
			cout << "\Неизвестный символ!";
			exit(1);
		}
	}
	return int(s.pop());
}

int main()
{
	char ans;
	char string[LEN];
	cout << "\nВведите арифметическое выражение в виде 2+4*3/2-5"
			"\nЧисла должны быть из одной цифры"
			"\nНе используйте пробелы и скобки";

	do
	{
		cout << "\nВыражение: ";
		cin >> string;
		express *eptr = new express(string);
		eptr->parse();
		cout << "\nРезультат: "
			 << eptr->solve();
		delete eptr;
		cout << "\nЕще одно выражение (y/n)? ";
		cin >> ans;
	} while (ans == 'y');
	return 0;
}
