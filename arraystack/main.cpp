#include <string>
#include <vector>
#include <iostream>
#include "arraystack.h"

int main() {
    ArrayStack<int> A;
    A.push(7);
    A.push(13);
    std::cout << A.top() << std::endl;
    A.pop();
    A.push(9);
    std::cout << A.top() << std::endl;
    A.pop();
    std::cout << A.top() << std::endl;
    A.pop();
    std::cout << A.empty() << std::endl;

    ArrayStack<std::string> B(4);
    B.push("Gael");
    std::cout << B.top() << std::endl;
    B.push("Alissa");
    std::cout << B.top() << std::endl;
    B.push("Carlos");
    std::cout << B.top() << std::endl;
    B.push("Karely");
    std::cout << B.top() << std::endl;
    std::cout << B.size() << std::endl;

}