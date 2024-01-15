#include <iostream>

class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton &operator=(const Singleton&) = delete;

    static Singleton& Get()
    {
        return s_Instance;
    }

    void Function() {}

private:
    Singleton() {}

    static Singleton s_Instance;
};

class Singleton2
{
private:
    Singleton2() {}

    int INST = 1;

    int Iint() {return INST;}

public:
    static Singleton2& instance()
    {
        static Singleton2 INSTANCE;
        return INSTANCE;
    }

    static int Int() {return instance().Iint();}
};

Singleton Singleton::s_Instance;

int main()
{
    Singleton& instance = Singleton::Get(); // or auto&
    instance.Function();

    [[maybe_unused]] auto inst = Singleton2::Int();

    std::cout << inst << '\n';
}