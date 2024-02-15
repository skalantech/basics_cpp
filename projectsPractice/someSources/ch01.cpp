#include <iostream>
#include "calcu.h"
#include <chrono>
#include "printTime.h"
#include <unistd.h>

/*comments go here*/

int main() {
    double x;
    double y;
    char op;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "Enter operator: ";
    std::cin >> op;

    auto start = std::chrono::steady_clock::now();

    calculation(x, y, op);

    auto end = std::chrono::steady_clock::now(); 
    
    printTime(start, end);

    return EXIT_SUCCESS;
}
