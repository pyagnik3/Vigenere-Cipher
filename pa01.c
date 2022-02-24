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
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Set values.
#define MAX 512
#define lineLimit 80

// Function to process alphabetics only.
char* onlyAlphabetics(FILE* filePointer, int* position) {

    char* tmpArr = malloc(sizeof(char) * (512 + 1)); 
    char currentChar = '\0';
    tmpArr[0] = '\0';

    while((currentChar = fgetc(filePointer)) != EOF) {
        
        if(!isalpha(currentChar)) continue;

        currentChar = tolower(currentChar);
        tmpArr[(*position)++] = currentChar;
        tmpArr[*position] = '\0'; 

        if((*position) == MAX) return tmpArr;
    
    }

    // Return to the function that called it.
    return tmpArr;

}

// Function used for reading in the key.
char* readKey(char* keyFile) {

    // If empty return NULL.
    if(keyFile == NULL) return NULL;

    int position = 0;
    char* tmpKey = NULL;
    FILE* filePointer = NULL;

    filePointer = fopen(keyFile, "r");
    if(!(filePointer = fopen(keyFile, "r"))) return NULL;

    tmpKey = onlyAlphabetics(filePointer, &position);
    tmpKey[position] = '\0';
    
    // Return the key to get printed.
    return tmpKey;

}

// Funtion to read in the plain text.
char* readPlaintext(char* plainFile) {

    // If empty return Null.
    if (plainFile == NULL) return NULL;

    int position = 0;
    char* tmpPlainText = NULL;    
    FILE* filePointer = NULL;

    filePointer = fopen(plainFile, "r");
    if (!(filePointer = fopen(plainFile, "r"))) return NULL;
    
    tmpPlainText = onlyAlphabetics(filePointer, &position);

    // Pad with 'x'
    while (position < MAX) {
        tmpPlainText[position++] = 'x'; 
    }

    // Set last char to '\0' and then return to be printed. 
    tmpPlainText[position] = '\0'; 
    return tmpPlainText;

}

// Creating a cipher using the vegenere algorithm.
char* createCipher(char* plainText, char* key) {

    int i, j;
    int keyVal, plainVal,  inputVal;
    char* cipherText = malloc(sizeof(char) * (MAX + 1)); 

    // Vigenere algorithm.
    for(i = j = 0; i < MAX; i++) {

        if(key[j] == '\0') j = 0;

        keyVal = key[j] - 'a';
        plainVal = plainText[i] - 'a';
        inputVal = (keyVal + plainVal) % 26;
        cipherText[i] = tolower('a' + inputVal);
        j++;

    }

    // Return the cipher to main to be printed.
    return cipherText;

}

// Function to print 80 letters per line.
void printOutText(char* textToPrint) {

    int i = 0, j = 0;

    while(textToPrint[i] != '\0') {

        if (j == lineLimit) {
            j = 0;
            printf("\n");
        }

        printf("%c", textToPrint[i]);
        i++;
        j++;

    }

    printf("\n");

}

// Mainly used for passing to functions and printing.
int main(int argc, char **argv) {
        
    char* key = NULL;
    char* plainText = NULL; 
    char* cipherText = NULL;
    
    // Read in and print out the key.
    printf("\n\nVigenere Key:\n\n");
    if(!(key = readKey(argv[1]))) return 0;
    printOutText(key);

    // Read in and print out the plain text.
    printf("\n\nPlaintext:\n\n");
    if(!(plainText = readPlaintext(argv[2]))) return 0;
    printOutText(plainText);

    // Create and print out the cipher text.
    cipherText = createCipher(plainText, key);
    printf("\n\nCiphertext:\n\n");
    printOutText(cipherText);

    // free allocated space. 
    free(plainText);
    free(key);
    free(cipherText);

    return 0;

}

/*=============================================================================
| I [Poojan Yagnik] [PO395937] affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
