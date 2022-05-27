#include <iostream>

using namespace std;

class Int {
private:
	int value;
public:
    Int() : value(0) { }
    
    void setValue(const int& new_value) {
    	value = new_value;
    }
    
    void printValue() const {
        cout << value << endl;
    }
    
    void addValue(const Int& value1, const Int& value2) {
    	value = value1.value + value2.value;
    }
};

int main()
{
	Int i1, i2, i3;
	i1.setValue(3);
	i2.setValue(4);
	i3.addValue(i1, i2);
	i3.printValue();
	return 0;
}