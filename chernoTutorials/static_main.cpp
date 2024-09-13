#include <iostream>

extern int s_Variable;
int s_Variable1 = 20;

int main()
{
    std::cout << s_Variable << '\n';
    std::cout << s_Variable1 << '\n';
    std::cin.get();
    return 0;
}