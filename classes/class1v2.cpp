#include <iostream>
#include <cstdlib>

using namespace std;

class Box {
public:
	double length;
	double breadth;
	double height;

	double get_volume();
	void set_length(double len);
	void set_breadth(double bre);
	void set_height(double hei);
};

double Box::get_volume() {
	return length * breadth * height;
}

void Box::set_length(double len) {
	this->length = len;
}

void Box::set_breadth(double bre) {
	this->breadth = bre;
}

void Box::set_height(double hei) {
	this->height = hei;
}

int main() {
	Box box1;
	Box box2;
	double volume = 0.0;

	box1.set_length(6.0);
	box1.set_breadth(7.0);
	box1.set_height(5.0);

	box2.set_length(12.0);
	box2.set_breadth(13.0);
	box2.set_height(10.0);

	volume = box1.get_volume();
	cout << "Volume of box1: " << volume << '\n';

	volume = box2.get_volume();
	cout << "Volume of box2: " << volume << '\n';

	return EXIT_SUCCESS;
}