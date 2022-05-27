#include <iostream>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
	etype etype1;
	char ch = 'a';
	cout << "Введите первую букву должности " << endl;
	cout << "(laborer, secretary, manager, accountant, executive, researcher); ";
	cin >> ch;
	switch (ch) {
		case 'a':
		    etype1 = accountant;
	    	break;
		case 'e':
		    etype1 = executive;
		    break;
		case 'l':
	        etype1 = laborer;
	        break;
		case 'm':
		    etype1 = manager;
		    break;
		case 'r':
		    etype1 = researcher;
		    break;
		case 's':
		    etype1 = secretary;
		    break;
	}
	
	cout << "Полное название должности: ";
	
	switch (etype1) {
	    case 0:
	    	cout << "laborer" << endl;
	        break;
	    case 1:
	    	cout << "secretary" << endl;	
	        break;
	    case 2:
	    	cout << "manager" << endl;
	        break;
	    case 3:
	    	cout << "accountant" << endl;	
	        break;
	    case 4:
	    	cout << "executive" << endl;	
	        break;
	    case 5:
	    	cout << "researcher" << endl;
	        break;
	}
    return 0;
}
