/*
 * Program to evaluate reverse polish expression
 * Compilation- gcc -o reverse_polish reverse_polish.c
 * Execution- ./reverse_polish
 * Dushyant Batra,(1910990098),03/08/2021
 * Assignment - 1 (C Fundamentals)
 */

#include<stdio.h>

// function to evaluate reverse polish expression
// parameters:
// char* str: input string
// return int: result of input
int reverse_polish(char* str) {
    int stack[100];
    int top = -1;
    int sameNum = 1;

    for(int i = 0; str[i] != '\0'; i++) {

	if(str[i] == ' ') {
	    sameNum = 1;
	    continue;
	}
	else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int firstOperand = stack[top--];
 	    int secondOperand = stack[top--];

	    if(str[i] == '+') {
	        stack[++top] = firstOperand + secondOperand;
	    }
	    else if(str[i] == '-') {
	        stack[++top] = secondOperand - firstOperand;
	    }
	    else if(str[i] == '*') {
	        stack[++top] = firstOperand * secondOperand;
	    }
	    else {
	        stack[++top] = secondOperand / firstOperand;
	    }
        }
	else {
	    if(sameNum == 1) {
	        stack[++top] = str[i] - '0';
		sameNum = 0;
	    }
	    else {
	        stack[top] = stack[top] * 10 + (str[i] - '0');
	    }
	}
    }
    return stack[0];
}

int main (void) {
    char str[100];
    
    printf("Enter the reverse polish expression:\n");
    scanf("%[^\n]s",str);
    
    printf("Answer is %d\n",reverse_polish(str));

    return 1;
}
