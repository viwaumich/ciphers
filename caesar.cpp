/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Andres Ayerbe, Vicky Wang
 * ayerbea, viwa
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * This file includes the necessary functions specific to the caesar cipher.
 */

#include "caesar.h"
#include <iostream>


char shiftAlphaCharacter(char c, int n) {
    const int NUM_ALPHA_LETTERS = 26;
    char lowerLetters[26];
    char upperLetters[26];
    char lowerFiller = 'a';
    char upperFiller = 'A';
    
    //declares old and new indexes of the old char and new char values
    int oldIndex = 0;
    int newIndex = 0;
    
    
    //populating arrays with the upper and lowercase letters
    for (int i = 0; i < NUM_ALPHA_LETTERS; i++) {
        lowerLetters[i] = lowerFiller;
        upperLetters[i] = upperFiller;
        if (c == lowerFiller || c == upperFiller) {
            oldIndex = i;
        }
        lowerFiller++;
        upperFiller++;
    }
    
    //newIndex before figuring out its value (mod 26)
    int preModIndex = oldIndex + n;
    
    //calculates index of shifted char based on sign of the key
    if (n >= 0) {
        newIndex = preModIndex % NUM_ALPHA_LETTERS;
    } else {
        //brings the index to a positive number below 26 
        while (preModIndex < NUM_ALPHA_LETTERS) {
            preModIndex += NUM_ALPHA_LETTERS;
        }
        newIndex = preModIndex % NUM_ALPHA_LETTERS;
    }
    //returns based on case
    if (isupper(c)) {
        return upperLetters[newIndex];
    } else {
        return lowerLetters[newIndex];
    }
}

string caesarCipher(string original, int key, bool encrypt) {
    string answer = "";
    
    //encodes or decodes by traversing original string with index i 
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            if (isalpha(original.at(i))) {
                answer += shiftAlphaCharacter(original.at(i), key);
            } else {
                answer += original.at(i);
            }
        }
    } else {
        for (int i = 0; i < original.length(); i++) {
            if (isalpha(original.at(i))) {
                answer += shiftAlphaCharacter(original.at(i), -1 * key);
            } else {
                answer += original.at(i);
            }
        }
    }
    return answer;
}
