/*
 * Program to get equivalent integer value from its hexadecimal string
 * Compilation- gcc -o htoi htoi.c -lm
 * Execution- ./htoi
 * Dushyant Batra,(1910990098),05/08/2021
 * Assignment no. 1 (C Fundamentals)
 */
#include<stdio.h>
#include<math.h>

//calculate length of string
//parameters:
//char* str: input string
//return int: length of string
int string_length(char* str) {
    int i = 0;

    for(; str[i] != '\0'; i++);

    return i;
}

//calculate integer value of given hexadecimal string
//parameter:
//char* str: input string
//return int: integer value of hexadecimal string
int htoi(char* str) {
    int value = 0;
    int str_length = string_length(str);

    for(int i = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) ? 2 : 0; i < str_length ; i++) {
	int data = 0;
	if(str[i] >= 97 && str[i] <= 102) {
	    data = str[i] - 87;
	}
	else if(str[i] >= 65 && str[i] <= 90) {
	    data = str[i] - 55;
	}
	else {
	    data = str[i] - 48;
	}
        value += data * (pow(16,str_length - i - 1)); 
    }

    return value;
}

int main (void) {
    char hexa_str[100];

    printf("Enter the hexadecimal string\n");
    scanf("%[^\n]s",hexa_str);

    printf("Integer Equivalent = %d\n",htoi(hexa_str));
    return 1;
}
