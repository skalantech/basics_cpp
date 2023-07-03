#include <initializer_list>
#include <iostream>
using namespace std;

int main() {

	int x, y;
	x = 3;
	y = 4;
	std::cout << "x: " << x << '\n' << "y: " << y << '\n';
	y = x;
	x = 5;
	std::cout << "x: " << x << '\n' << "y: " << y << '\n';
	int* b;
	b = &x;
	y = *b;
	x = 6;
	std::cout << "x: " << x << '\n' << "y: " << y << '\n' << "*b: " << *b << '\n';
	y = 7;
	x = 1;
	std::cout << "x: " << x << '\n' << "y: " << y << '\n' << "*b: " << *b << '\n';

	int a = 3;
	cout << "a: " << a << ", &a: " << &a << '\n';

	int b = 4;
	cout << "b: " << b << ", &b: " << &b << '\n';

	int* pointerToA = &a;
	int* pointerToB = &b;
	int* p = pointerToA;
	cout << "*p: " << *p << ", p: " << p << '\n';

	p = pointerToB;
	cout << "*p: " << *p << ", p: " << p << '\n';

	cout << '\n';

	int& referenceToA = a;
	cout << "a: " << a << ", &a: " << &a << '\n';

	int& referenceToB = b;
	cout << "b: " << b << ", &b: " << &b << '\n';

	int& r = referenceToA;
	cout << "r: " << r << ", &r: " << &r << '\n';

	r = referenceToB;
	cout << "r: " << r << ", &r: " << &r << '\n';

	cout << "a: " << a << ", &a: " << &a << '\n'; // a is 4 now

	b = 5;
	//a = 8;
	r = referenceToB;
	cout << "a: " << a << ", &a: " << &a << '\n';
	cout << "b: " << b << ", &b: " << &b << '\n';
	cout << "r: " << r << ", &r: " << &r << '\n';
	cout << "*p: " << *p << ", p: " << p << '\n';


	return 0;
}

