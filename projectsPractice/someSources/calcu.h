#include <iostream>
#include "ch.h"

void calculation(double& x, double& y, char op) {

    switch (op) {
        case '+' : 
            std::cout << "sum = " << x << " + " << y << " = " << sum (&x, &y) << "\n" << std::endl;
            break;
        case '-' : 
            std::cout << "sub = " << x << " - " << y << " = " << sub (&x, &y) << "\n" << std::endl;
            break;
        case '*' : 
            std::cout << "mul = " << x << " * " << y << " = " << mul (&x, &y) << "\n" << std::endl;
            break;
        case '/' : 
            std::cout << "div = " << x << " / " << y << " = " << div (&x, &y) << "\n" << std::endl;
            break;
        default :
            std::cout << "\"" <<  op << "..." << "\"" << " is not a valid operator";
    }
}