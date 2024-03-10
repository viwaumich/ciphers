/*
 * This includes all of the test functions required.
 */

#include <stdio.h>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    
    return;
}

void testToUpperCase() {
    cout << endl << "Now testing function toUpperCase()" << endl << endl;
    cout << "Expected: DIAG @11 PM, Actual: " << toUpperCase("Diag @11 pm") << endl;
    cout << "Expected: ABCDEF, Actual: " << toUpperCase("aBcDeF") << endl;
    cout << "Expected: ABC1234 HELLO, Actual: " << toUpperCase("abc1234 Hello") << endl << endl; 
}

void testRemoveNonAlphas() {
    cout << "Now testing function removeNonAlphas()" << endl << endl;
    cout << "Expected: Diagpm, Actual: " << removeNonAlphas("Diag @11 pm") << endl;
    cout << "Expected: abcdef, Actual: " << removeNonAlphas("abcdef") << endl;
    cout << "Expected: abcHello, Actual: " << removeNonAlphas("abc1234 Hello") << endl;
    cout << "Expected: aaabbb, Actual: " << removeNonAlphas("@@@aaa111222bbb") << endl << endl; 
}

void testRemoveDuplicate() {
    cout << "Now testing function removeDuplicate()" << endl << endl;
    cout << "Expected: ECS183, Actual: " << removeDuplicate("EECS1833") << endl;
    cout << "Expected: HELO123, Actual: " << removeDuplicate("HELLO112233") << endl;
    cout << "Expected: HELOWRD, Actual: " << removeDuplicate("HELLOWORLD") << endl;
    cout << "Expected: H, Actual: " << removeDuplicate("HHHHHHH") << endl;
    cout << "Expected: 9, Actual: " << removeDuplicate("999999") << endl;
    cout << "Expected: ANDRES124, Actual: " << removeDuplicate("ANNNDRRRRES1A1224") 
        << endl << endl;
}

void testCharToInt() {
    cout << "Now testing function charToInt()" << endl << endl;
    cout << "Expected: 1, Actual: " << charToInt('1') << endl;
    cout << "Expected: 3, Actual: " << charToInt('3') << endl;
    cout << "Expected: 9, Actual: " << charToInt('9') << endl << endl;;

}
void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl << endl;;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'b', Actual: '" << shiftAlphaCharacter('a', 1) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('z', 1) << "'" << endl;
    cout << "Expected: 'C', Actual: '" << shiftAlphaCharacter('X', 5) << "'" << endl;
    cout << "Expected: 'V', Actual: '" << shiftAlphaCharacter('X', 50) << "'" << endl;
    cout << "Expected: 'Z', Actual: '" << shiftAlphaCharacter('A', -1) << "'" << endl
        << endl;
    return;
}
void testCaesarCipher() {
    cout << "Now testing function caesarCipher()" << endl << endl;
    cout << "Expected: 'Cuuj cu qj jxu Tyqw qj 11 f.c.', Actual: '" <<
        caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) <<
        "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" <<
        caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) <<
        "'" << endl;
    cout << "Expected: 'Nkrru oz oy iaxxktzre Ckjtkyjge!', Actual: '" <<
        caesarCipher("Hello it is currently Wednesday!", 58, true) <<
        "'" << endl;
    cout << "Expected: 'Hello it is currently Wednesday!', Actual: '" <<
        caesarCipher("Nkrru oz oy iaxxktzre Ckjtkyjge!", 58, false) <<
        "'" << endl << endl; 
    return;
}
void testVigenereCipher() {
    cout << "Now testing function vigenereCipher()" << endl << endl;
    cout << "Expected: 'Euyb dv ee lxy Lzrk ll 11 f.g.', Actual: '" <<
        vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) <<
        "'" << endl;
    cout << "Expected: 'Meet me at the Diag at 11 p.m.', Actual: '" <<
        vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) <<
        "'" << endl << endl;

        return;
}
void testFillGrid() {
    cout << "Now testing function fillGrid()" << endl << endl;

    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);

    printGrid(grid);
    cout << endl;
        
    return;
}
void testMixKey() {
    cout << "Now testing function mixKey()" << endl << endl;
    cout << "Expected: 'POLYBIUSACDEFGHJKMNQRTVWZ0123456789', Actual: '" <<
        mixKey("POLYBIUS") << "'" << endl << endl;
}
void testFindInGrid() {
    cout << "Now testing function findInGrid()" << endl << endl;

    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: '54', Actual: '" << findInGrid('8', grid) << "'" << endl << endl;

    return;
}
void testPolybiusSquare() {
    cout << "Now testing function polybiusSquare()" << endl << endl;
    char grid[SIZE][SIZE];

    cout << "Expected: '11110533 000102 1533 341411 04113334', Actual: '" <<
        polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) <<
        "'" << endl;
    cout << "Expected: 'EECS 183 IS THE BEST', Actual: '" <<
        polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) <<
        "'" << endl << endl;
    return;
}
