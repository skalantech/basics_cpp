#include<unordered_map>

using namespace std;

class firstClass;

class secondClass {
    friend class firstClass;

private:
    void myfunc2(unordered_map<unsigned, double>& map) {
        map[1] = 0.5;
    }
};

class firstClass {
public:
    void myfunc1(secondClass* sc) {
        // here firstClass is accessing a private member
        // of secondClass, for it's allowed to do that
        // being a friend
        sc->myfunc2(sTable);
    }
private:
    unordered_map<unsigned, double> sTable;
};

int main() {
    firstClass  fco;
    secondClass sco;
    fco.myfunc1(&sco);
    return 0;
}