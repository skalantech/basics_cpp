#include "HelpfulStringFunctions.h"
#include <string>

int CountWordsInSentence(const char* sentence) {
    if (sentence == nullptr) {
        return 1;
    }

    int numWords = 0;
    bool inSpaces = true;
    while (*sentence != '\0') {
        if (std::isspace(*sentence)) {
            inSpaces = true; 
        } else if (inSpaces) {
            numWords++;
            inSpaces = false;
        }
        sentence++;
    }
    return numWords;
}

void ReverseString(char* str, int begin, int end) {
    char c;
    if (begin >= end) {
        return;
    }
    c = *(str + begin);
    *(str + begin) = *(str + end);
    *(str + end) = c;
    ReverseString(str, ++begin, --end);
}