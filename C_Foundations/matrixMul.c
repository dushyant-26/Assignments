/*
 * Program to do matrix multiplication
 * Compilation- gcc -o matrixMul matrixMul.c
 * Execution- ./matrixMul
 * Dushyant Batra,(1910990098),29/07/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>
#include<stdlib.h>

int size = 0;

//function to get matrix multiplication
//parameters:
//int array1[][]: first array input
//int array2[][]: second array input
//return resultant array
int** matrixMultiply(int array1[size][size], int array2[size][size]) {
    int** res = (int**)malloc(sizeof(int*) * size);
    
    for(int i = 0; i < size; i++) {
        res[i]=(int*)malloc(sizeof(int) * size);
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size;j++) {
	    res[i][j] = 0;
	    for(int k = 0; k < size; k++) {
	        res[i][j] += array1[i][k] * array2[k][j];
	    }
	}
    }
    return res;

}
int main (void) {
    printf("Enter size of 2d square matrix:");
    scanf("%d",&size);

    int arr1[size][size];
    int arr2[size][size];

    printf("Enter numbers for first matrix\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
	    scanf("%d",&arr1[i][j]);
	}
    }

    printf("Enter numbers for second matrix\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
	    scanf("%d",&arr2[i][j]);
	}
    }

    int** res = matrixMultiply(arr1,arr2);
    
    printf("Result after matrix multiplication is:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size;j++) {
	    printf("%d ",res[i][j]);
	}
	printf("\n");
    }
    return 1;
}
