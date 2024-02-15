#include "facilities.h"
#include <iostream>
#include <limits>

int main()
{
	int example{ 1998 };
	std::cout << "Enter two numbers like this: " << example << ": ";

	int x{};
	int y{};
	std::cin >> x >> y;

	std::cout << "You entered: " << x << " and " << y << '\n';

	keep_window_open();

	return 0;
}
