#include <iostream>
#include <cstring>
#include "counter.h"

using namespace std;

int Counter::countPunctuationMarks(char* text) {
    if (text == nullptr) {
        cout << "There is not source text!!!";
        return 0;
    }

    if (strlen(text) == 0) {
        cout << "Source text is empty!!!";
        return 0;
    }

    int counter = 0;
    for (unsigned i = 0; i < strlen(text); i++) {
        if (isInArray(text[i])) {
            counter++;
        }
    }
    return counter;
}

bool Counter::isInArray(char element) {
    for (unsigned i = 0; i < strlen(PUNCTUATION_MARKS); i++) {
        if (element == PUNCTUATION_MARKS[i]) {
            return true;
        }
    }

    return false;
}
