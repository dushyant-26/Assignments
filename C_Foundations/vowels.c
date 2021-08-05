/*
 * Program to count the number of vowels and consonants in a string
 * Compilation- gcc -o vowels vowels.c
 * Execution- ./vowels
 * Dushyant Batra,(1910990098),29/07/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

//function to check if given character is vowel or not
//input parameter:
//char ch:ch of type character
int checkVowel(char ch) {
    if(ch == 'a' || ch == 'A' || ch == 'E' || ch == 'e' || ch == 'i' || ch == 'I'
       || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
        return 1;
    }
    return 0;
}

int main (void) {
    char str[100];
    int vowels = 0;
    int consonants = 0;

    printf("Enter the string:");
    scanf("%[^\n]s",str);

    //counting number of vowels and consonants
    for(int i = 0; i < str[i] != '\0' ; i++) {
        int checked = checkVowel(str[i]);
	vowels += checked;
	consonants += !checked;

    }

    printf("No. of vowels in string = %d\n", vowels);
    printf("No. of consonants in string = %d\n", consonants);


    return 1;
}

