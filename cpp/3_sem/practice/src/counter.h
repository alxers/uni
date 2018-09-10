#ifndef COUNTER_H
#define COUNTER_H

#define MAXTEXTLENGTH 200

class Counter {
public:
    Counter(){};
    ~Counter(){};

    const char* PUNCTUATION_MARKS = ",.!;:?-";

    int countPunctuationMarks(char* text);
    bool isInArray(char element);
};

#endif // COUNTER_H


