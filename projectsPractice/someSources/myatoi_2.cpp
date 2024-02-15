#include <stdio.h>
#include <iostream>
#include "printTime.h"
using namespace std;

// Checking if c is numeric

// Step 3

bool isNumeric(char c) { return (c >= '0' && c <= '9') ? true : false; }

// atoi() function that returns 0 if c is non-convertible

int myAtoi_Func(char* s){

    if (*s == '\0') return 0;

    // Step 1

    int result = 0;

    int sign = 1;       //Initializing the positive sign
   
    int i = 0;          // Initializint the index of first digit

    // Checking if number is negative and updating the sign accordingly

    if (s[0] == '-') {
        sign = -1;
        i++;            // Updating the index of first digit
    }
   
    for (; s[i] != '\0'; ++i) {     // Iterating through all digits and updating result

        if (isNumeric(s[i]) == false)   // Error messages
        return 0;

        result = result * 10 + s[i] - '0';
    }  
    
    return sign * result;           // Returning the result
}

int main(){

    //char s[] = "-524GGG";
    char s[10];

    cout << "Enter the string to convert ";
    cin >> s;
    
    auto start = std::chrono::steady_clock::now();

    int val = myAtoi_Func(s);
    printf("%d \n", val);

    auto end = std::chrono::steady_clock::now();
    printTime (start, end);

    return EXIT_SUCCESS;
}