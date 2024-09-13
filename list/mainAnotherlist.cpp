#include <iostream>
#include "anotherlinkedlist.h"

int main() {
    LinkedList<int> l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    std::cout << l1 << '\n';
    l1.deleteNode(6);
    std::cout << l1 << '\n';
    LinkedList<char> l2;
    l2.insert('a');
    l2.insert('b');
    l2.insert('c');
    l2.insert('d');
    l2.insert('e');
    std::cout << l2 << '\n';
    l2.deleteNode('d');
    std::cout << l2 << '\n';
    return 0;
}