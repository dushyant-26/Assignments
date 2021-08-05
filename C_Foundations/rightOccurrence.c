/*
 * Program to find the position of rightmost occurence of string t in string s
 * Compilation- gcc -o rightOccurrence rightOccurrence.c
 * Execution- ./rightOccurrence
 * Dushyant Batra,(1910990098), 30/07/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

//function to find position of rightmost occurence of string t in string s
//parameters:
//char* s: first input string
//char* t: second input string
//return int: right most position of t in s.
int rightPosition(char*s, char* t) {
    int found = 0;
    int position = -1;

    for(int i = 0; s[i] != '\0'; i++) {
	found = 0;
        if(s[i] == t[0]) {
	    for(int j = 1; t[j] != '\0'; j++) {
	        if(s[i + j] == '\0' || s[i + j] != t[j]) {
		    found = 1;
		    break;
		}
	    }
	    if(found == 0) {
	        position = i;
	    }
	}
    }
    return position;
}

int main (void) {
    char str[100];
    char t[100];

    printf("Enter the main string:\n");
    scanf("%[^\n]s",str);

    printf("Enter the substring to find:\n");
    scanf(" %[^\n]s",t);

    printf("RightMost Occurrence of given substring is %d\n",rightPosition(str,t));
    return 1;
}
