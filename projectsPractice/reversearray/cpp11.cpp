// C++ program to get reverse of a const string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse string and return
// reverse string pointer of that
char *reverseConstString(char const *str)
{
    // find length of string
    int n = strlen(str);

    // create a dynamic pointer char array
    char *rev = new char[n + 1];

    // copy of string to ptr array
    strcpy(rev, str);

    // Swap character starting from two
    // corners
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(rev[i], rev[j]);

    // return pointer of the reversed string
    return rev;
}

// Driver code
int main(void)
{
    const char *s = "GeeksforGeeks";
    printf("%s", reverseConstString(s));
    return (0);
}