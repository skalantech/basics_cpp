#include <iostream>
#include <functional>
#include <pthread.h>

using namespace std;

class m
{
public:
    template <typename T>
    struct my_struct
    {
        function<void *(void *)> ptr;
    };
};

class g
{
public:
    static void *hello(void *)
    {
        cout << "Hello.." << endl;
    }
};

int main()
{
    struct m::my_struct<g> h;
    h.ptr = g::hello;
    h.ptr(nullptr);
    cin.get();
    return 0;
}