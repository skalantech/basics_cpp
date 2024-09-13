// C++ program to reverse a string
// using recursion
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str, int n, int i)
{
     
  if(n<=i){return;}
//  Swaping the character
  swap(str[i],str[n]);
  reverseStr(str,n-1,i+1);
 
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str, str.length()-1, 0);
    cout << str;
    return 0;
}