/*
 * Program to find GCD of two numbers using recursion.
 * Compilation- gcc -o gcd_recursive gcd_recursive.c
 * Execution- ./gcd_recursive
 * Dushyant Batra,(1910990098), 05/08/2021 
 * Assignment 5 (Recursion)
 */

#include <stdio.h>

// returns the gcd of two given numbers
// parameters: 
// int num1 : first number 
// int num2 : second number
// return : int : gcd of num1 and num2
int findGCD(int num1, int num2) {
    if(num1 % num2 == 0) {
        return num2;
    }

    return findGCD(num2, num1 % num2);
}

int main() {
    int num1 = 0, num2 = 0;
    printf("Enter the first number:\n");
    scanf("%d", &num1);

    printf("Enter the second number:\n");
    scanf("%d", &num2);

    int gcd = findGCD(num1, num2);
    printf("\nGCD of %d and %d is %d\n", num1, num2, gcd);
}
