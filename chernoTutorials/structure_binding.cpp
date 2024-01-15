#include <iostream>
#include <tuple>
#include <string>

struct Person
{
    std::string Name;
    int Age;
};

std::tuple<std::string, int> CreatePerson()
{
    return {"Carlos", 42};
}

int main()
{
    std::tuple<std::string, int> person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::string name1;
    int age1;
    std::tie(name1, age1) = CreatePerson();

    Person personStc = {"Alissa", 1};
    std::string nameStc = personStc.Name;
    int ageStc = personStc.Age;

    auto[name2, age2] = CreatePerson();

    std::cout << name << '\n';
    std::cout << age << '\n';
    
    std::cout << name1 << '\n';
    std::cout << age1 << '\n';

    std::cout << name2 << '\n';
    std::cout << age2 << '\n';
    
    std::cout << nameStc << '\n';
    std::cout << ageStc << '\n';

    return 0;
}