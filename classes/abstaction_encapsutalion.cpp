#include <iostream>
using namespace std;

class Adder {
public:
	// constructor
	Adder(int i = 0);

	// interface to outside world
	void addNum(int number);

	// interface to outside world
	int getTotal();

private:
	// hidden data from outside world
	int total;
};

Adder::Adder(int i) {
	total = i;
}

void Adder::addNum(int number) {
	total += number;
}

int Adder::getTotal() {
	return total;
}

int main() {
	Adder a;

	a.addNum(10);
	a.addNum(20);
	a.addNum(30);

	cout << "Total " << a.getTotal() << endl;
	return 0;
}
