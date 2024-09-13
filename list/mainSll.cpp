#include <iostream>
#include <string>
#include "linkedlist.h"

int main() {
    SLinkedList<std::string> a;
    std::cout << "empty? "<< (a.empty() ? "true\n" : "false\n");
    a.addFront("MSP");
    std::cout << "front: " << a.front() << '\n';
    std::cout << "empty? "<< (a.empty() ? "true\n" : "false\n");
    a.removeFront();
    std::cout << "removing front\n";
    std::cout << "empty? "<< (a.empty() ? "true\n" : "false\n");

    SLinkedList<int> b;
    std::cout << "empty? "<< (b.empty() ? "true\n" : "false\n");
    b.addFront(13);
    std::cout << "front: " << b.front() << '\n';
    std::cout << "empty? "<< (b.empty() ? "true\n" : "false\n");
    b.removeFront();
    std::cout << "removing front\n";
    std::cout << "empty? "<< (b.empty() ? "true\n" : "false\n");

    return 0;
}