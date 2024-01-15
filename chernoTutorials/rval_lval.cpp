#include <iostream>

int GetValue()
{
    return 10;
}

int& GetValue1()
{
    static int value = 10;
    return value;
}

void SetValue(int& value)
{

}

void SetValue1(int value)
{

}

void SetValue2(const int& value)
{

}

void PrintName0(std::string& name)
{
    std::cout << name << '\n';
}

void PrintName(const std::string& name) // copy
{
    std::cout << "[lvalue]" << name << '\n';
}

void PrintName(std::string&& name) // accepts only rvalue references (move)
{
    std::cout << "[rvalue]" << name << '\n';
}

int main()
{
    int i = GetValue();
    int j = i;
    GetValue1() = 5;

    SetValue(i);

    SetValue1(j);
    SetValue1(10);

    SetValue2(j);
    SetValue2(10);

    // int& a = 10;         // error
    const int& a = 10;      // a

    int temp = 5;
    const int& b = temp;    // same as a
    std::cout << a << '\n';
    std::cout << b << '\n';

    std::string firstName = "Carlos";
    std::string lastName = "Escalante";

    std::string fullName = firstName + " " + lastName;

    PrintName0(fullName);
    // PrintName0(firstName + " " + lastName); // error doesn'twork with rvalue

    PrintName(fullName);
    PrintName(firstName + " " + lastName); // works with rvalue and lvalues

    //lvalue: variable with storage backing them
    //rvalue: temporary values
    //lvalue references: can only take lvalues unless they are const
    //rvalue references: can only take temporary rvalues
    std::cin.get();
    return 0;
}