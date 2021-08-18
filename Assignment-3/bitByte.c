/*
 * Program with solution to Ques 1 to 8
 * Compilation- gcc -o bitByte bitByte.c
 * Execution- ./bitByte
 * Dushyant Batra, (1910990098), 15/08/2021
 * Assignment 3 (Bits and Bytes)
 */
#include<stdio.h>

int bitAnd(int x,int y) {
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}

int bitSign(int x) {
    if(x == 0) {
        return 0;
    }
    if(((x >> 31) & 1) == 1) {
        return -1;
    }
    else{
        return 1;
    }

    int mask = (!x + ~(0x00);
    int notMsb = (x >> 31) ^ 1;
    return (~mask & 0) | (mask & )

}

int getByte(int x,int n) {
    return (x >> 8*n & 255);
}

int logicalShift(int x, int n) {
    return ((x >> n) & ~((1 << 31) >> n) << 1);
}

int bang(int x) {
    int minus_x = ~x + 1;

    return ((minus_x | x) >> 31) + 1;
        
}

int invert(int x, int p, int n){
    return x ^ (~(~0 << n) << p);
}

int conditional(int x, int y, int z) {
    int mask = (!x + ~(0x00));

    return ((mask & y) | (~mask & z));
}



int main (void) {
    printf("%d\n",conditional(0,2,3));

    return 1;
}
