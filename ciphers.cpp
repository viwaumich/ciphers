/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Andres Ayerbe, Vicky Wang
 * ayerbea, viwa
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * This is the ciphers function which allows the user to encrypt or decrypt
 * messages based on Caesar, Vigenere, or Polybius ciphers.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void ciphers() {

    //declaring/initializing input collecting variables
    string cipherType;
    int cypherNum;
    string userMessage;
    string userKeyStr;
    int userKeyInt = 0;
    string userEncrypt;
    string encryptedMessage;
    bool encryptType = false;
    bool includesNonAlphaNum = false;
    int numAlphaInKey = 0;
    char polybiusGrid [SIZE][SIZE];
        
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, cipherType);
    cipherType = toUpperCase(cipherType);
    
    //assigns a number based on which cipher type was chosen
    if (cipherType == "C" || cipherType == "CAESAR") {
        cypherNum = 1;
    } 
    
    else if (cipherType == "V" || cipherType == "VIGENERE") {
        cypherNum = 2;
    } 
    
    else if (cipherType == "P" || cipherType == "POLYBIUS") {
        cypherNum = 3;
    } 
    
    else {
        //exits program if cipher is invalid
        cypherNum = 0;
        cout << "Invalid cipher!" << endl;
        return;
    }
    
    // ask user to encrypt or decrypt
    cout << "Encrypt or decrypt: " <<endl;
    getline(cin, userEncrypt);
    userEncrypt = toUpperCase(userEncrypt);
    
    //assigns a boolean value based on user input for encryption type
    if (userEncrypt == "E" || userEncrypt == "ENCRYPT") {
        encryptType = true;
        userEncrypt = "encrypted";
    } 
    
    else if (userEncrypt == "D" || userEncrypt == "DECRYPT" ) {
        encryptType = false;
        userEncrypt = "decrypted";
    } 
    
    else {
        //exits program if cipher is invalid
        cout << "Invalid mode!" << endl;
        return;
    }
    
    // get message from user
    cout << "Enter a message: " << endl;
    getline(cin, userMessage);
    
    //determines if polybius key violates requires clause
    if (cypherNum == 3) {
        userMessage = toUpperCase(userMessage);
        for (int i = 0; i < userMessage.length(); i++) {
            if (!isalnum(userMessage[i]) && userMessage[i] != ' ') {
                cout << "Invalid message!" << endl;
                return;
            }
        }
    }
    
    // gets key or keyword from user based on cipher chosen
    cout << "What is your key: ";
    if (cypherNum == 1) {
        cin >> userKeyInt;
    } 
    
    else if (cypherNum == 2) {
        getline(cin, userKeyStr);
        
        //determines validity of vigenere key
        for (int i = 0; i < userKeyStr.length(); i++) {
            if (isalpha(userKeyStr.at(i))){
                numAlphaInKey++;
            }
        }
        if (numAlphaInKey == 0) {
            cout << "Invalid key!" << endl;
            return;
        }
    } 
    
    else if (cypherNum == 3) {
        getline(cin, userKeyStr);
        
        //determines validity of polybius key
        for (int i = 0; i < userKeyStr.length(); i++) {
            if (isalpha(userKeyStr.at(i)) && !isdigit(userKeyStr.at(i))) {
                includesNonAlphaNum = true;
            }
        }
        if (!includesNonAlphaNum) {
            cout << "Invalid key!" << endl;
            return;
        }
        userKeyStr = toUpperCase(userKeyStr);
        userKeyStr = removeDuplicate(userKeyStr);

    }
    
    //performs ciphers and assigns the answers to encryptedMessage
    if (cypherNum == 1) {
        encryptedMessage = caesarCipher(userMessage, userKeyInt, encryptType);
    } 
    
    else if (cypherNum == 2) {
        encryptedMessage = vigenereCipher(userMessage, userKeyStr, encryptType);
    } 
    
    else if (cypherNum == 3) {        
        encryptedMessage = 
            polybiusSquare(polybiusGrid, userKeyStr, userMessage, encryptType);
    }
    
    //outputs answers
    cout << "The " << userEncrypt << " message is: " << encryptedMessage
    << endl;

    
    return;
}
