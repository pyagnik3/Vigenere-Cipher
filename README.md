# Vigènere Cipher 🚀

----------------

### Repo for Security in Computing(CIS 3360) project 1 for Spring 2022 at University of Central Florida using C.

### To Compile

```
// Note: swap kX and pX with the appropriate file number.
$ gcc -o pa01 pa01.c
$ ./pa01 kX.txt pX.txt
```

In this assignment you’ll write a program that encrypts the alphabetic letters in a file using the
Vigènere cipher. Your program will take two command line parameters containing the names
of the file storing the encryption key and the file to be encrypted. The program must generate
output to the console (terminal) screen as specified below.

### 1.1 Command line parameters

1. Your program must compile and run from the terminal command line.

2. Input the required file names as command line parameters. Your program may NOT
prompt the user to enter the file names. The first parameter must be the name of the
encryption key file, as described below. The second parameter must be the name of the
file to be encrypted, as also described below. The sample run command near the end of
this document contains an example of how the parameters will be entered.

3. Your program should open the two files, echo the processed input to the screen, make the
necessary calculations, and then output the ciphertext to the console (terminal) screen in
the format described below.

Note

If the plaintext file to be encrypted doesn’t have the proper number (512) of alphabetic characters, pad the last block as necessary with the lowercase letter x. Make sure that all the
input characters are lower case only.

### 1.2 Formats

1.2.1 Encryption Key File Formats

The encryption key is plain text that may contain upper and lower case letters, numbers, and
other text. The input must be stripped of all non-alphabetic characters. Please note that the
input text must be converted to contiguous lower case letters to simplify the encryption process.

1.2.2 Encryption Plaintext File Formats

The file to be encrypted can be any valid text file with no more than 512 letters in it. (Thus, it is
safe to store all characters in the file in a character array of size 512, including any pad
characters.) Please note that the input text file will also generally have punctuation, numbers,
special characters, and whitespace in it, which should be ignored. You should also ignore
whether a letter is uppercase or lowercase in the input file. In order to simplify the encryption,
all letters should be converted to lower case letters. In the event the plaintext input file is less
than 512 characters, pad the input file with a lowercase x until the 512 character input buffer is
full.

1.2.3 Output Format

The program must output the following to the console (terminal) screen, also known as stdout:

1. Echo the lowercase alphabetic text derived from the input key file.

2. Echo the lowercase alphabetic text derived from the input plaintext file. Remember to pad with x if the processed plaintext is less than 512 characters.

3. Ciphertext output produced from encrypting the input key file against the input plaintext
file.

The output portion of each input file should consist of only lowercase letters in rows of
exactly 80 letters per row, except for the last row, which may possibly have fewer. These
characters should correspond to the ciphertext produced by encrypting all the letters in the
input file. Please note that only the alphabetic letters in the input plaintext file will be
encrypted. All other characters should be ignored.

1.2.4 Program Execution

The program, pa01 expects two inputs at the command line. The first parameter is the name of
the key file, an 8 bit ASCII string terminated by a a newline character. The second parameter is
the name of the plaintext file, an 8 bit ASCII string terminated by a a newline character. Note thatthese input files may contain non-alphabetic characters (numbers, punctuation, white spaces,
etc.). The valid inputs, as discussed previously, may be any alphabetic character, and should be
converted to lower case.
