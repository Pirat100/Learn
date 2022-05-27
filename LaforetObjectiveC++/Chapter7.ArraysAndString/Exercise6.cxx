#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card {
private:
    int number;
    Suit suit;
public:
    card() {}
    void set(int n, Suit s) {
    	number = n;
    	suit = s;
    }
    
    void display();
};

void card::display() {
	if (number >= 2 && number <= 10) {
		cout << number;
	} else {
		switch (number) {
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;
		}
	}
	
	switch (suit) {
		case clubs: cout << static_cast<char>(5); break;
		case diamonds: cout << static_cast<char>(4); break;
		case hearts: cout << static_cast<char>(3); break;
		case spades: cout << static_cast<char>(6); break;
	}
}

int main() {
	card deck[52];
	int j;
	cout << endl;
	for (j = 0; j < 52; ++j) {
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}
	cout << "Исходная колода:\n";
	for(j = 0; j < 52; ++j) {
		deck[j].display();
		cout << " ";
		if(!((j + 1) % 13)) {
			cout << endl;
		}
	}
	srand(time(NULL));
	for (j = 0; j < 52; ++j) {
		int k = rand() % 52;
		card temp = deck[j];
		deck[j] = deck[k];
		deck[k] = temp;
	}
	/*
    cout << "n\Перемешанная колода:\n";
    for (j = 0; j < 52; ++j) {
       deck[j].display();
       cout << " ";
       if (!((j + 1) % 13)) {
       	cout << endl;
       }
    }
    */
    card deck1[13], deck2[13], deck3[13], deck4[13];
    for (j = 0; j < 52; ++j) {
    	if (j >= 0 && j < 13) {
    		deck1[j] = deck[j];
    	} else if (j >= 13 && j < 26) {
    		deck2[j - 13] = deck[j];
    	} else if (j >= 26 && j < 39) {
    		deck3[j - 26] = deck[j];
    	} else if (j >= 39 && j < 52) {
    		deck4[j - 39] = deck[j];
    	}
    }
    for (size_t i = 1; i < 5; ++i) {
        cout << endl << "Выдаем карты игроку " << i << endl;
        for (j = 0; j < 13; ++j) {
            if (i == 1) {
            	deck1[j].display();
            } else if (i == 2) {
            	deck2[j].display();
            } else if (i == 3) {
            	deck3[j].display();
            } else if (i == 4) {
            	deck4[j].display();
            }
            cout << " ";
            if (!((j + 1) % 13)) {
            	cout << endl;
            }
        }
    }
	return 0;
}




