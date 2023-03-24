// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    bool haveSpace = true;
    bool isCorrect = true;
    int Words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            isCorrect = false;
        }
        if (str[i] != ' ') {
            haveSpace = false;
        }
        else {
            if (isCorrect && !haveSpace) {
                Words++;
            }
            haveSpace = true;
            isCorrect = true;
        }
    }

    return Words;
}

unsigned int faStr2(const char* str) {
    bool notCorrect = false;
    bool isFirst = true;
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isFirst) {
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] > 'Z' || str[i] < 'A') {
                notCorrect = true;
            }
            isFirst = false;
        }
        else {
            if (str[i] != ' ') {
                if (str[i] < 'a' || str[i] > 'z') {
                    notCorrect = true;
                }
            }
            else {
                if (!notCorrect) {
                    ++words;
                }
                notCorrect = false;
                isFirst = true;
            }
        }
    }

    return words;
}

unsigned int faStr3(const char* str) {
    double lenght = 0;
    int Words = 0;
    for (int i = 0; str[i] != '\0';) {
        if (str[i] != ' ') {
            ++Words;
            while (str[i] != ' ') {
                if (str[i] == '\0') {
                    break;
                }
                lenght++;
                i++;
            }
        }
        i++;
    }
    if (Words > 0) {
        lenght /= Words;
    }
    return static_cast<int>(lenght + 0.5);
}