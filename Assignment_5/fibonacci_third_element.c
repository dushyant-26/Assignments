/*
 * Program to print every third element of fibonacci series n times.
 * Compilation- gcc -o fibonacci_third_element fibonacci_third_element.c
 * Execution- ./fibonacci_third_element
 * Dushyant Batra,(1910990098),05/08/2021
 * Assignment 5 (Recursion)
 */

#include <stdio.h>

// function to print every third element of fibonacci series n times.
// parameters:
// int n : number of times to print
// return : void
void print_fibonacci(int n) {
    int position = 2;  // as we already stored first and second fibonacci numbers and will be calculating from third number in series
    int first = 1, second = 1;

    while(n > 0) {
        int third = first + second;
	position++;

	if(position == 3) {
	    printf("%d ", third);
	    position = 0;
	    n--;
	}

	first = second;
	second = third;
    }
}

int main() {
    int n = 0;
    printf("Enter the number of times to print:\n");
    scanf("%d", &n);

    print_fibonacci(n);
    printf("\n");
}
