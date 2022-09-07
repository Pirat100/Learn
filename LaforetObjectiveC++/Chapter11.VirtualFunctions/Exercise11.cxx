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
	char getOperator()
	{
		return '0';
	}
};

class Stack
{
  private:
	Token *token[MAX];
	int top;

  public:
	Stack()
	{
		top = 0;
	}

	void push(Token *var)
	{
		token[++top] = var;
	}

	Token *pop()
	{
		return token[top--];
	}

	int gettop()
	{
		return top;
	}

	bool isNumber()
	{
		Number *numberPtr;
		if (numberPtr = dynamic_cast<Number *>(token[top]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class express
{
  private:
	Stack s;
	char* pStr;
	int len;

  public:
	express(char* ptr)
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
	Token* lastval;
	Token* lasttop;
	
	float ans;
	Number* ptrN;
	Operator* ptrO;

	for (int i = 0; i < len; ++i)
	{
		ch = pStr[i];
		if (ch >= '0' && ch <= '9')
		{
			Number* ptrN = new Number(ch);
			s.push(ptrN);
		}
		else
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if (s.gettop() == 1)
				{
					Operator* ptrO = new Operator(ch);
					s.push(ptrO);
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
	Stack s;
	Operator oplus('+'), ominus('-'), odivide('/'), omultiply('*');
	Number n1(2.4), n2(5.5), n3(87.2);
	s.push(&n1);
	s.push(&oplus);
	s.push(&n3);
	while (s.gettop() > 0)
	{
		if (s.isNumber())
		{
			cout << s.pop()->getNumber();
		}
		else
		{
			cout << s.pop()->getOperator();
		}
	}
	cout << endl;

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
