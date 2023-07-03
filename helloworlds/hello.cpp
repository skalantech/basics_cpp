#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{ "Hello", "C++", "World", "from", "VS2022", "and the msvc v143 compiler" };

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}