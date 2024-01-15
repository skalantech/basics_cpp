#include <iostream>

class Entity
{
private:
    int m_X, m_Y;
    int* m_Z;
    mutable int var;
public:
    int GetX() const    // 1
    {
        var = 2;
        return var;
    }

    int GetX()          // 2
    {
        var = 4;
        return var;
    }

    void SetX(int x)
    {
        m_X = x;
    }

    const int* const GetZ() const
    {
        return m_Z;
    }
};

void PrintEntity(const Entity& e)       // uses 1
{
    std::cout << e.GetX() << '\n';
}

void PrintEntity(const Entity* e)
{
    std::cout << e->GetX() << '\n';
}

void PrintEntity(Entity& e)             // uses 2
{
    std::cout << e.GetX() << '\n';
}

int main()
{
    const int MAX_AGE = 90;

    const int* a = new int;     // pointer of locations in the heap

    //*a = 2; error can't modify the content of this memory addres
    a = (int*)& MAX_AGE;
    std::cout << *a << '\n';

    int* const b = new int;
    *b = 2;
    //b = (int*)& MAX_AGE;
    std::cout << *b << '\n';

    Entity e;
    Entity e1;

    const Entity* e_ptr = &e;

    PrintEntity(e_ptr);
    PrintEntity(e1);

    std::cin.get();

    return 0;
}