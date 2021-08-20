/*
 * Program to print n numbers in fibonacci series that are even
 * Compilation- gcc -o even_fibo even_fibo.c
 * Execution- ./even_fibo
 * Dushyant Batra,(1910990098),19/08/2021
 * Assignment - 8 (Algorithms)
 */

#include<stdio.h>

//return the nth even number from fibbo series
//params:
//int n:integer value which tells which even no. we need to return
//long* mem: array fot memoization
//return long:nth even number from fibbo series
long even_fibo(int n, long* mem) {
    if(n == 1) {
        return 2;
    }
    
    if(n == 2) {
        return 8;
    }
    
    if(mem[n] == -1) {
        mem[n] = 4 * even_fibo(n - 1, mem) + even_fibo(n - 2, mem);
    }
    
    return mem[n];
}
	
int main(void) {
    int n;
    printf("Enter the number of even numbers in fibonacci series to print:\n");
    scanf("%d", &n);
    printf("\n");
    
    long mem[n + 1];
    for(int i = 0; i <= n; i++) {
        mem[i] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        printf("%ld ", even_fibo(i, mem));
    }
    printf("\n");
}

