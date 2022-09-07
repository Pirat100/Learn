#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "\nНекорректная команда\n";
		exit(-1);
	}

	ifstream infile;
	infile.open(argv[1]);
	if (!infile) {
		cerr << "\nНевозможно открыть " << argv[1] << endl;
		exit(-1);
	}

	ofstream outfile;
	outfile.open(argv[2]);
	if (!outfile) {
		cerr << "\nНевозможно открыть " << argv[2] << endl;
	}

	char ch;
	while (infile.get(ch)) {
		outfile.put(ch);
	}

	return 0;
}
