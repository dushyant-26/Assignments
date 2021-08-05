/*
 * Program to print a pyramid having given number of steps.
 * Compilation- gcc -o pyramid pyramid.c
 * Execution- ./pyramid
 * Dushyant Batra, (1910990098), 29/07/2021 
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

int main (void) {
    int steps = 0;

    printf("Enter the height of pyramid:");
    scanf("%d", &steps);

    //pyramid logic
    for(int i = 1; i <= steps; i++) {

        for(int j = 1; j <= steps - i; j++) {
	    printf(" ");
	}
	for(int k = 1; k <= i; k++) {
	    printf("# ");
	}
        printf("\n");

    }

    return 1;
}
