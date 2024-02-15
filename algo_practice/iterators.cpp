#include <vector>
#include <iostream>
#include "removeEveryOtherItem.h"

using std::cout;
using std::vector;

int main()
{
    std::vector v {1,2,3,4,5,6,7,8,9,10};

    for (size_t i = 0; i != v.size(); ++i)
    {
        cout << v[i];
        
    }
    cout << '\n';
    
    removeEveryOtherItem(v);
    
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr;
    }
    cout << '\n';
    
    removeEveryOtherItem(v);
    
    vector<int>::iterator itr = v.begin();
    while  (itr != v.end())
        cout << *itr++;

    cout << '\n';

}
