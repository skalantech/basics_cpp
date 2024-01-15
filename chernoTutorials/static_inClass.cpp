#include <iostream>

struct Entity
{
    static int x, y;
    Entity() {x++; y++;}
    void Print()
    {
        std::cout << x << ", " << y << '\n';
    }
};

void Print(Entity e)
{
    std::cout << e.x << ", " << e.y << '\n';
}

int Entity::x;
int Entity::y;

int main() 
{
    Entity e;
    Entity::x=2;
    Entity::y=3;
    e.Print();
    Entity e1;
    Print(e1);
    
    std::cin.get();

    return 0;
}