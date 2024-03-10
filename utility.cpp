/*
 * This file includes the necessary functions that will be utilized by
 * other cipher functions to perform operations on strings;
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    string upperWord = "";

    //checks character at each index and converts to uppercase if it is alpha
    for(size_t i = 0; i < original.length(); i++) {
        if(isalpha(original.at(i))) {
            upperWord += toupper(original.at(i));
        } 
        
        else {
            upperWord += original.at(i);
        }
    }
    
    return upperWord;
}

string removeNonAlphas(string original) {
    string newWord = "";

    //traverses original and only adds character if it is alpha
    for(size_t i = 0; i < original.length(); i++) {
        if(isalpha(original.at(i))) {
            newWord += original.at(i);
        }
    }
    
    return newWord;
}

string removeDuplicate(string original) {
    string newWord;
    /*
     * creates array to store each unique char in the string
     * the size of the array is the length of the string to account for
     * a case where all of the characters are unique
     */

    int indexCount = 0;
    bool notFound;

    //traverses original string and removes duplicates if they are found
    for (int i = 0; i < original.length(); i++) {
        for (int j = i + 1; j < original.length(); j++) {
            if (original.at(i) == original.at(j)) {
                original.at(j) = ' ';
            }
        }
    }

    for (int i = 0; i < original.length(); i++) {
        if (original.at(i) != ' ') {
            newWord += original.at(i);
        }
    }

    original = newWord;
    return original;
}


int charToInt(char original) {
    char current = '0';
    
    //increments the char, current, along with the iterator variable, i to
    //compare it to the original char
    for (int i = 0; i < 10; i++) {
        if (original == current) {
            return i;
        }
        current++;
    }
    
    return ' ';
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;

    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
