/*
 * Program to reverse 1 D array
 * Compilation- gcc -o arrayReverse arrayReverse.c
 * Execution- ./arrayReverse
 * Dushyant Batra, (1910990098), 29/07/2021
 * Assignment 1 (C Foundations)
 */
#include<stdio.h>

//function to reverse 1D array
void reverse(int array[], int size) {
    int temp = 0;

    //logic for array reversal
    for(int i = 0; i < size/2; i++) {
        temp = array[i];
	array[i] = array[size - i - 1];
       	array[size - i - 1] = temp;
    }
}

int main (void) {
    //size of array
    int size = 0;
   
    printf("Enter size of array:");
    scanf("%d",&size);

    int array[size];

    printf("Enter numbers in array:\n");
    
    //Taking input for array
    for(int i = 0; i < size; i++) {
        scanf("%d",&array[i]);
    }
    reverse(array,size);

    printf("Reverse array is:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 1;
}
