/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: Poojan Yagnik
| Language: c
|
| To Compile: gcc -o VigènereCipher VigènereCipher.c
|
| To Execute: c -> ./VigènereCipher kX.txt pX.txt
|                   where kX.txt is the keytext file
|                   and pX.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
| Instructor: McAlpin
| Due Date: 2/27/22
|
+=============================================================================*/

// Important header files. 
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MAX number of plain text characters.
#define MAX 512

// Function prototypes.
void readKeyFile(FILE* keyFile, char* keyInput);
void readPlainText(FILE* plainTextFile, char* plainText);
void createCipher(char* key, char* plainTEXT, char* cipherTEXT);

int main(int argc, char *argv[]) {

    char key[MAX];
    char plainTEXT[MAX] = {0};
    char cipherTEXT[MAX] = {0};

    FILE* keyFile;
    FILE* plainTextFile;

    if(((keyFile = fopen(argv[1], "r")) && ((plainTextFile = fopen(argv[2], "r")))) != NULL) {

        // Read in the files and produce the cipher.
        readKeyFile(keyFile, key);
        readPlainText(plainTextFile, plainTEXT);
        createCipher(key, plainTEXT, cipherTEXT);

        // Close the files.
        fclose(keyFile);
        fclose(plainTextFile);

    }

    return 0;

}

// Function to read in the key.
void readKeyFile(FILE* keyFile, char* keyInput) {

    int i, j, k = 0, q = 0;
    char key[MAX] = {0};

    printf("\n\nVigenere Key:\n\n");

    // Processing only alphabetics. 
    while((k = fgetc(keyFile)) != EOF) {

        if(isalpha(k)) {

            key[q] = tolower(k);
            printf("%c", key[q]);
            q++;

        }

    }

    // Newly generated key.
    for(i = 0, j = 0; i < MAX; i++, j++) {

        if(j == strlen(key)) j = 0;
        keyInput[i] = key[j];

    } 

    keyInput[i] = '\0';

}

void readPlainText(FILE* plainTextFile, char* plainText) {




}

void createCipher(char* key, char* plainTEXT, char* cipherTEXT) {




}

/*=============================================================================
| I [Poojan Yagnik] [PO395937] affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
