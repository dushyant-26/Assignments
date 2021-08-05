/*
 * Program to implement various string.h header file functions.
 * Compilation- gcc -o stringFunctions stringFunctions.c
 * Execution- ./stringFunctions
 * Dushyant Batra,(1910990098), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

//calculate length of string
//parameters:
//char* s: input string
//return int:length of string
int _strlen(char* s) {
    int i = 0;

    for(; s[i] != '\0'; i++);

    return i;
}

//function to copy n characters from string t to string s
//parameters:
//char* s: first string
//char* t: second string
//int n: number of characters to be copied
//return void
void _strncpy(char* s ,char* t, int n) {
    int t_length = _strlen(t);

    for(int i = 0; i < n; i++) {
        s[i] = (i < t_length) ? t[i] : '\0';
    }

}

//function to do catenation of n characters from string t to string s
//parameter:
//char* s: first string
//char* t: second string
//int n: number of characters to be concatenate
//return void
void _strncat(char* s, char* t, int n) {
    int s_length = _strlen(s);

    for(int i = s_length; i - s_length < n ; i++) {
        s[i] = t[i - s_length];
    }
    s[s_length + n] = '\0';
}

//function to compare n characters of given two strings
//parameters:
//char* s: first string
//char* t: second string
//int n: number of characters to be compared
//return int: return 0 if all n characters are same in both string else return -1 if first string is smaller than second else return 1.
int _strncmp(char* s, char* t, int n) {
    
    for(int i = 0; i < n; i++) {
        if(s[i] > t[i]) {
	    return 1;
	}

	if(s[i] < t[i]) {
	    return -1;
	}
    }

    return 0;
}

int main (void) {
    char str[100];
    char t[100];
    char demo[100];
    int n = 0;

    printf("Enter the main string:\n");
    scanf("%[^\n]s",str);

    printf("Enter the other substring:\n");
    scanf(" %[^\n]s",t);

    printf("No. of characters for which u want to perform these functions:\n");
    scanf("%d",&n);

    _strncat(str,t,n);
    printf("After performing catenation of %d characters,output of str is %s\n",n,str);

    printf("output of strncmp is %d\n", _strncmp(str,t,n));

    _strncpy(demo,t,n);
    printf("After copying %d characters from string t to new string,output is %s\n",n,demo);
    return 1;
}

