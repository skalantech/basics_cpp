#include <iostream>
#include <any>
#include <variant>

void* operator new(size_t size) 
{ 
    return malloc(size);
}

// any uses new (Dynamic memory allocation) for bigger data types than 32 bytes like structs:

struct CustomClass
{
    std::string s0, s1;
};

int main()
{
    std::any data;
    data = 40;
    data = "Carlos"; // const char *
    data = std::string("Alfredo");
    data = CustomClass(); // any is going to dinamically allocate

    std::variant<int, std::string> data2;
    data2 = 36;
    data2 = "Karely"; // std::string

    std::string& string = std::any_cast<std::string&>(data);
    std::string& string2 = std::get<std::string&>(data2);

    std::cin.get();
}

// EXAMPLE DOES NOT COMPILE I DO NOT KNOW WHY