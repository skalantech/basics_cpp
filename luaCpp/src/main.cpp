#include <numeric>
#include <iostream>
#include <sol/sol.hpp>


void TestLua() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    lua.script_file("../src/script.lua");

    // This is how we get the value of a global variable from our Lua script
    int someVariableInsideCpp = lua["some_variable"];
    std::cout << "The value of some_variable in C++ is " << someVariableInsideCpp << std::endl;
}

int main(int argc, char* argv[]) {
    
    TestLua();

    return 0;
}