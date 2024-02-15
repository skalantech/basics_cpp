#include <iostream>
using namespace std;

int myAtoi_func(char* s) {

    int result = 0;

    for (int x = 0; s[x] != '\0'; ++x)
        result = result * 10 + s[x] - '0';
    return result;
}

int main() {
    //char s[] = "12345";
    char s[10];

    cout << "Enter the string to convert ";
    cin >> s;

    int i = myAtoi_func(s);

    cout << i;

    return 0;
}