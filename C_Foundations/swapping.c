/*
 * Program to swap two numbers without using third variable
 * Compilation= gcc -o swapping swapping.c
 * Execution= ./swapping
 * Dushyant Batra,(1910990098), 29/07/2021
 * Assignment 1 C Foundations 
 */

#include<stdio.h>

int main (void) {
    //input numbers
    int first = 0;
    int second = 0;
    
    printf("Enter first Number:");
    scanf("%d",&first);
    printf("Enter second Number:");
    scanf("%d",&second);
    
    //swapping logic
    first = first ^ second;
    second = first ^ second;
    first = first ^ second;

    printf("swapped numbers are \nFirst Number = %d\nSecond Number = %d\n"
           ,first,second);

    return 1;
}
