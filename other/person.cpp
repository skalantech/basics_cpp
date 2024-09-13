#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ostream>

class person
{
public:
    person(std::string newname) { name = newname; }

    friend std::ostream &operator<<(std::ostream &out, const person &p)
    {
        out << p.name;
        return out;
    }

    std::string toString() const
    {
        return name;
    }

    bool operator==(const person &p)
    {
        return this->name == p.name;
    }

private:
    std::string name;
};

auto person_found(std::vector<person> &vp, std::vector<person>::const_iterator &it) -> void
{
    if (it != vp.end())
    {
        std::cout << "Person found! " << *it << '\n';
        std::cout << "Person found! " << it->toString() << '\n';
    }
    else
    {
        std::cout << "Person not found.\n";
    }
}

int main()
{
    person p1("Carlos"), p2("Karely"), p3("Gael"), p4("Alissa"), p5("Person_test");
    std::vector<person> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);

    std::vector<person>::const_iterator it1 = std::find(vp.begin(), vp.end(), p1);
    std::vector<person>::const_iterator it2 = std::find(vp.begin(), vp.end(), p2);
    std::vector<person>::const_iterator it3 = std::find(vp.begin(), vp.end(), p3);
    std::vector<person>::const_iterator it4 = std::find(vp.begin(), vp.end(), p4);
    std::vector<person>::const_iterator it5 = std::find(vp.begin(), vp.end(), p5);

    person_found(vp, it1);
    person_found(vp, it2);
    person_found(vp, it3);
    person_found(vp, it4);
    person_found(vp, it5);
}