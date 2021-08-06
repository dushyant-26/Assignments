/*
 * Program to print all input lines longer than 80 characters
 * Compilation- gcc -o file_input file_input.c
 * Execution- ./file_input
 * Dushyant Batra,(1910990098),05/08/2021
 * Assignment no. 1 (C Foundations)
 */
#include<stdio.h>

//function to calculate length of string
//parameters:
//char* str: input string
//return int:length of string
int string_length(char* str) {
    int i = 0;

    for(; str[i] != '\0'; i++);

    return i;
}

//function to print all the lines in file which are longer than 80 characters.
//return void
void print_lines() {
    FILE* file = fopen("../../input.txt", "r");//../../input.txt is the input file.
    char str[1000];

    while(fscanf(file, " %[^\n]s", str) != EOF) {
        if(string_length(str) >= 80) {
	    printf("%s\n\n",str);
	}
    }
    fclose(file);
}

int main (void) {
    print_lines();
    return 1;
}
