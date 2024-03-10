/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Andres Ayerbe, Vicky Wang
 * ayerbea, viwa
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * This file includes the necessary functions specific to the polybius cipher.
 */


#include "polybius.h"
#include <string>

using namespace std;

string mixKey(string key) {
    string newAlnum = "";
    
    //adds chars to a new version of ALNUM without the characters found in key
    for (int i = 0; i < ALNUM.length(); i++) {
        bool isInWord = false;
        for (int j = 0; j < key.length(); j++) {
            if (ALNUM.at(i) == key.at(j)) {
                isInWord = true;
            }
        }
        if (!isInWord) {
            newAlnum += ALNUM.at(i);
        }
    }
    
    return key + newAlnum;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    //declares var that will be calculated from the rows and columns
    int contentIndex = 0;
    
    //traverses the grid and adds the letter at current contentIndex
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++, contentIndex++) {
            contentIndex = (row + (5 * row)) + col;
            grid[row][col] = content.at(contentIndex);
        }
    }
}


string findInGrid(char c, char grid[SIZE][SIZE]) {
    int rowNum = 0;
    int colNum = 0;
    string answer = "";
    char nums = '0';
    char rowChar = '0';
    char colChar = '0';
    
    //traverses grid to find the right numerical coordinates
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == c) {
                rowNum = row;
                colNum = col;
            }
        }
    }
    
    //finds the corresponding int to assign to rowChar and colChar
    for (int i = 0; i < 10; i++) {
        if (rowNum == i) {
            rowChar = nums;
        }
        if (colNum == i) {
            colChar = nums;
        }
        nums++;
    }
    
    //adds each char that represents the row and col numbers to the return value
    answer += rowChar;
    answer += colChar;
    
    return answer;
}


string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    string answer = "";
    
    //creating new stream of characters to fill grid with
    string gridContent = mixKey(key);
    
    //will use these to organize decoding process
    int currentRow = 0;
    int currentCol = 0;
    
    fillGrid(grid, gridContent);
    
    //encodes or decodes by traversing original with index i
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            if (original.at(i) == ' ') {
                answer += " ";
            } 
            
            else {
                answer += findInGrid(original.at(i), grid);
            }
        }
    } 
    
    else {
        for(int i = 0; i < original.length() - 1; i++) {
            if(original.at(i) == ' ') {
                answer += " ";
            } 
            
            else {
                currentRow = charToInt(original.at(i));
                currentCol = charToInt(original.at(i + 1));
                answer += grid[currentRow][currentCol];
                i++;
            }
        }
    }
    return answer;
}
