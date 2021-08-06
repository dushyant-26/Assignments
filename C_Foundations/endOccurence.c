/*
 * Program to find whether string t occurs at end of string s or not.
 * Compilation- gcc -o endOccurrence endOccurrence.c
 * Execution- ./endOccurrence
 * Dushyant Batra,(1910990098), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

//calculate length of given string
//parameters:
//char* str: input string
//return int: length of string
int stringLength(char* str) {
    int i = 0;

    for(; str[i] != '\0'; i++);

    return i;
}

//function to find whether string t comes at end of s or not.
//parameters:
//char* s: first string
//char* t: second string
//return int:return 1,if t is present at end of s else return 0.
int strend(char*s, char* t) {
    int present = 0;
    int s_length = stringLength(s);
    int t_length = stringLength(t);

    if(s_length < t_length) {
        return 0;
    }

    int position = s_length - t_length;

    for(int i = position; s[i] != '\0'; i++) {
        if(s[i] != t[i - position]) {
	    return 0;
	}
    }
    
    return 1; 
}

int main (void) {
    char str[100];
    char t[100];

    printf("Enter the main string:\n");
    scanf("%[^\n]s",str);

    printf("Enter the substring to find:\n");
    scanf(" %[^\n]s",t);

    printf("%d\n" ,strend(str,t));
    return 1;
}

