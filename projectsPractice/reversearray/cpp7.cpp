// C++ program to reverse a string using recursion
#include <iostream>
using namespace std;
void getreverse(string &str, int i)
{
    if (i > (str.length() - 1 - i))
    {
        return;
    }
    swap(str[i], str[str.length() - i - 1]);
    i++;
    getreverse(str, i);
}
int main()
{
    string name = "geeksforgeeks";

    getreverse(name, 0);
    cout << name << endl;
    return 0;
}
// code contributed by pragatikohli