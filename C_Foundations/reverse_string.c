/*
 * Program to reverse a given string
 * Compilation- gcc -o reverse_string reverse_string.c
 * Execution- ./reverse_string
 * Dushyant Batra, 1910990098, 05/08/2021
 * Assignment no. 1 (C Foundations)
 */
#include<stdio.h>

//calculate length of string
//parameters:
//char* str: input string
//return int: length of string
int string_length(char* str) {
    int i = 0;

    for(i = 0; str[i] != '\0' ; i++);

    return i;
}

//function to reverse a string
//parameter:
//char* str: input string
//return void
void reverse_string(char* str) {
    int str_length = string_length(str);

    for(int i = 0; i < str_length / 2 ; i++) {
	char temp = str[i];
        str[i] = str[str_length - i - 1];
	str[str_length - i - 1] = temp;
    }
}

int main (void) {
    char str[100];

    printf("Enter the string\n");
    scanf("%[^\n]s",str);

    reverse_string(str);

    printf("Reversed string:\n");
    printf("%s\n",str);
    return 1;
}
