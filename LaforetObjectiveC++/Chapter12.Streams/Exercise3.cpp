#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "\nНекорректная команда\n";
		exit(-1);
	}

	ifstream infile;
	infile.open(argv[1]);
	if (!infile) {
		cerr << "\nНевозможно открыть " << argv[1] << endl;
		exit(-1);
	}

	infile.seekg(0, ios::end);
	cout << infile.tellg();

	return 0;
}
