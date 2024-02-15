// C++ program to illustrate the
// reversing of a string using
// reverse() function
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
 
    // Reverse str[begin..end]
    reverse(str.begin(), str.end());
 
    cout << str;
    return 0;
}