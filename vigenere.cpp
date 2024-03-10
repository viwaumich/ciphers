/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Andres Ayerbe, Vicky Wang
 * ayerbea, viwa
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * This file includes the necessary functions specific to the vigenere cipher.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>


string vigenereCipher(string original, string keyword, bool encrypt) {
    string answer = "";
    
    //cleans up the keyword so that the cipher will perform successfully
    string newKey = removeNonAlphas(keyword);
    newKey = toUpperCase(newKey);
    
    //two necessary integers needed for functionality
    int keywordIndex = 0;
    int shiftVal = 0;
    
    //performs encryption or decryption process
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            if (!isalpha(original.at(i))) {
                answer += original.at(i);
            } 
            
            else {
                if (keywordIndex == newKey.length()) {
                    keywordIndex = 0;
                }

                shiftVal = newKey.at(keywordIndex) - 'A';
                answer += shiftAlphaCharacter(original.at(i), shiftVal);
                keywordIndex++;
            }
        }
    } 
    
    else {
        for (int i = 0; i < original.length(); i++) {
            if (!isalpha(original.at(i))) {
                answer += original.at(i);
            } 
            
            else {
                if (keywordIndex == newKey.length()) {
                    keywordIndex = 0;
                }

                shiftVal = newKey.at(keywordIndex) - 'A';
                answer += shiftAlphaCharacter(original.at(i), -1 * shiftVal);
                keywordIndex++;
            }
        }
    }
    return answer;
}
