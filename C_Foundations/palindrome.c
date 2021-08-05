/*
 * Program to check if the given string is palindrome or not, considering only alphanumeric characters and ignoring cases.
 * Compilation- gcc -o palindrome palindrome.c
 * Execution- ./palindrome
 * Dushyant Batra,(1910990098),04/08/2021
 * Assignment 1 - C Foundations
 */

#include <stdio.h>
#include <ctype.h>

int areSame(char ch1, char ch2) {
    if(ch1 >= 65 && ch1 <= 90) {
        ch1 = tolower(ch1);
    }
    if(ch2 >= 65 && ch2 <= 90) {
        ch2 = tolower(ch2);
    }

    return (ch1 == ch2) == 1 ? 1 : 0; 
}

// to check if given string is palindrome
int isPalindrome(char str[]) {
    int size = 0;
    for(size = 0; str[size] != '\0'; size++);

    int i = 0, j = size - 1;
    while(i < j) {
	if(str[i] == ' ') {
	    i++;
	}
	else if(str[j] == ' ') {
	    j--;
	}
	else {
	    if(areSame(str[i], str[j]) == 0) {
                return 0;
            }
            i++;
            j--;
	}
    }

    return 1;
}

int main() {
    char str[1000];

    printf("Enter the string\n"); 
    scanf("%[^\n]s",str);   // scan the string

    if(isPalindrome(str) == 1) {
        printf("\nGiven String is Palindrome\n");
    }
    else {
	printf("\nGiven String is not Palindrome\n");
    }
}
