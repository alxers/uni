#include <iostream>
#include <stdlib.h>
#include "counter.h"

using namespace std;

int main() {
    char text[MAXTEXTLENGTH];
    cout << "Enter text: ";
    cin.getline(text, MAXTEXTLENGTH - 1, '*');
    cout << "Sourse text:" << endl << text << endl;

    Counter counts;
    cout << "The number of punctuation marks is: " << counts.countPunctuationMarks(text) << endl;

	return 0;
}
