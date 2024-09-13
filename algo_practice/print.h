#include <iostream>

template <typename Container>
void print(const Container & c, std::ostream & out = std::cout)
{
    if (c.empty())
        out << "(empty)";
    else
    {
        auto itr = begin(c); //itr is a Container::const_iterator
        out << "[ " << *itr++; //Print first item
        while (itr != end(c))
            out << ", " << *itr++;
        out << " ]" << std::endl;
    }
}

template <typename Container>
auto begin(Container & c) -> decltype(c.begin())
{
    return c.begin();
}

template<typename Container>
auto begin(const Container & c) -> decltype(c.begin())
{
    return c.begin();
}

template <typename Container>
auto end(Container & c) -> decltype(c.end())
{
    return c.begin();
}

template<typename Container>
auto end(const Container & c) -> decltype(c.end())
{
    return c.end();
}