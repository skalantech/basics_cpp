//This program prints "Hello world"
//to the console

#include <iostream>
#include <limits>
using std::cout;
using std::endl;

int main()
{
    cout << "Hello World" << endl;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}
