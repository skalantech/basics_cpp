#include <iostream>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;

public:
    Entity(std::string name) : m_Name(name) {}

    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e("Carlos");
    std::cout << e.GetName() << '\n';

    int x = 8;
    auto f = [=]() mutable
    {
        std::cout << "Hello" << '\n';
        std::cout << x << '\n';
        x++;
    };

    f();
    f();

    std::cin.get();

    return 0;
}