/*
 * Program with solution to Ques 9
 * Compilation- gcc -o base32_to_base64 base32_to_base64.c
 * Execution- ./base32_to_base64
 * Dushyant Batra, (1910990098), 18/08/2021
 * Assignment 3 (Bits and Bytes)
 */

#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//returns the character corresponding to given binary representation in base 64.
//params:
//char* temp: string containing all bits.
//int start:the position from where this character in base 64 starts
//int end:the position where the character ends.
//return char:character corresponding to given binary representation in base 64.
char base64(char* temp, int start, int end) {
    int val = 0;

    for(int i = start; i < end; i++) {
        val = val * 2 + (temp[i] - '0');
    }
    if(val < 26) {
        val = val + 65;
    }
    else if(val < 52) {
        val = val + 71;
    }
    else if(val < 62) {
        val = val - 4;
    }
    else if(val == 62) {
        val = val - 19;
    }
    else {
        val = val - 16;
    }
    return val;
}

//returns binary representation of given integer.
//params:
//int val: integer value
//return char*: string with binary representation of given integer.
char* binary_representation(int val) {
    char* res = (char*)malloc(5*sizeof(int));
    int i = 4;

    while(val > 0) {
        res[i--] = (val % 2) + '0';
        val /= 2;
    }
    while(i >= 0) {
        res[i--] = '0';
    }
    return res;
}

//returns binary representation of given in character in base 32.
//params:
//char ch: character in base 32 format
//return char*: string with binary representation of given integer. 
char* base32_to_binary(char ch) {
    int val;
    if(ch >= 'A' && ch <= 'Z') {
        val = ch - 65;
    }
    else if(ch >= '2' && ch <= '7') {
        val = ch - 24;
    }
    else {
        return NULL;
    }
    return binary_representation(val);
}

//prints base 64 string corresponding to given base 32 string
//params:
//char* str: string in base 32 format
//return void
void get_base64_from_base32(char* str) {
    int str_length = strlen(str);
    char temp[1000] = {'\0'};
    for(int i = 0; i < str_length; i++) {
        char* res = base32_to_binary(str[i]);
        if(res != NULL) {
            strcat(temp,res);
            free(res);
        }
    }
    int binary_length = strlen(temp);

    binary_length = (binary_length / 8) * 8;
    temp[binary_length] = '\0';
    
    //variable which stores no. of 0 to be added at end.
    int pad = binary_length % 6;
    if(pad != 0) {
        pad = 6 - pad;
    }

    for(int i = 0; i < pad; i++) {
        strcat(temp,"0");
    }

    //variable which stores no. of = to be added at end.
    int equals = (strlen(temp) / 6) % 4;
    if(equals != 0) {
        equals = 4 - (equals % 4);
    }

    for(int i = 0; i < strlen(temp); i += 6) {
        printf("%c", base64(temp, i , i+6));
    }
    for(int i = 0; i < equals; i++) {
        printf("=");
    }
    printf("\n");

}

int main() {
    int n;
    scanf("%d",&n);

    while(n-- > 0) {
        char str[1000];

        scanf("%s",str);
        get_base64_from_base32(str);
    }
}


