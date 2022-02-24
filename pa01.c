/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: Poojan Yagnik
| Language: c
|
| To Compile: gcc -o pa01 pa01.c
|
| To Execute: c -> ./pa01 kX.txt pX.txt
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

// Defines.
#define MAX 513
#define stringLimit 80

// FIle Pointer.
FILE* filePointer;

// Funtion Prototyped.
char* readInFile(char* fileName);
char* vigenereCipher(char* plainText, int finalLen, char* key, int keyLen);

int main(int argc, char** argv) {

    int i, keyLen, plainLen, finalLen;

    // Read in the key file. 
    char* key = readInFile(argv[1]); 

    // Read in the plain text file. 
    char* plainText = readInFile(argv[2]);

    keyLen = strlen(key);
    plainLen = strlen(plainText);

    printf("\n\nVigenere Key:\n\n");
    printf("%s\n\n", key);
    printf("\nPlaintext:\n\n");
    printf("%s\n", plainText);

    if(keyLen > plainLen) {
        finalLen = keyLen - plainLen; 
    } else if(keyLen == plainLen) {
        finalLen = keyLen;
    } else {
        finalLen = plainLen - keyLen;
    }

    // Padding with 'x'.
    for(i = 0; i < finalLen; i++) {
        plainText[plainLen + i] = 'x';
    }

    finalLen += plainLen;

    printf("\n");
    printf("Ciphertext:\n\n");

    plainText = vigenereCipher(plainText, finalLen, key, keyLen);
    finalLen = strlen(plainText);

    // Print ater every 80 char.
    for(i = 0; i < finalLen; i++) {

        printf("%c", plainText[i]);
        if((i+1) % stringLimit == 0) printf("\n");

    }

    printf("\n");
    return 0;
    
}

// Function to read in and return the file. 
char* readInFile(char* fileName) {

    int counter = 0;
    char character;
    char* file;

    filePointer = fopen(fileName, "r");
    if(filePointer == NULL) return NULL;

    character = fgetc(filePointer);
    file = malloc(sizeof(char) * MAX);

    while(character != EOF) {

        if(!isalpha(character)) {
            character = fgetc(filePointer);
            continue;
        }

        if(isupper(character)) {
            character = tolower(character);
        }

        file[counter++] = character;
        character = fgetc(filePointer);

    }
    
    file[counter] = '\0';
    fclose(filePointer);
    return file;

}

// Function to create the cipher text.
char* vigenereCipher(char* plainText, int finalLen, char* key, int keyLen) {

    int i, j, cipher;
    char* tmpArr = malloc(sizeof(char) * MAX);

    for(i = 0, j = 0; i < finalLen; i++) {

        cipher = tolower(key[j % keyLen]) - 'a';
        tmpArr[i] = 'a' + (plainText[i] - 'a' + cipher) % 26;
        j++;

    }

    printf("\n");
    return tmpArr;

}

/*=============================================================================
| I [Poojan Yagnik] [PO395937] affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/