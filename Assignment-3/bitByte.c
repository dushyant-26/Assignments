/*
 * Program with solution to Ques 1 to 8
 * Compilation- gcc -o bitByte bitByte.c
 * Execution- ./bitByte
 * Dushyant Batra, (1910990098), 15/08/2021
 * Assignment 3 (Bits and Bytes)
 */
#include<stdio.h>

//perform bitwise and without using & operator.
//params:
//int x,y:given numbers
//return int: x & y
int bitAnd(int x,int y) {
    return ~(~x | ~y);
}

//perform bitwise xor without using ^ operator.
//params:
//int x,y:given numbers
//return int: x ^ y
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}

//check sign of number using bitwise operator.
//params:
//int x:given number
//return int: -1 if x is -ve ,1 if x is +ve, else 0.
int bitSign(int x) {
    int mask = (!x + ~(0x00));
    int msb = (x >> 31) & 1;
    int msb_mask = (!msb + ~(0x00));
    return (msb_mask & -1) | (~msb_mask & (mask & 1));
}

//return the required byte from number.
//params:
//int x:given number
//int n:byte number
//return int: required byte
int getByte(int x,int n) {
    return (x >> 8*n & 255);
}

//perform logical using bitwise operators.
//params:
//int x:given number
//int n: right shift by how many places
//return int: logical x >> n
int logicalShift(int x, int n) {
    return ((x >> n) & ~(((1 << 31) >> n) << 1));
}

//perform bang operator without using ! operator.
//params:
//int x:given number
//return int: !x
int bang(int x) {
    int minus_x = ~x + 1;

    return ((minus_x | x) >> 31) + 1;
        
}

//perform invert using bitwise operator.
//params:
//int x:given number
//int p: position from where invert starts
//int n:no. of places to be inverted
//return int: number after inversion
int invert(int x, int p, int n){
    return x ^ (~(~0 << n) << p);
}

//perform conditional operator using bitwise operator.
//params:
//int x,y,z:given numbers
//return int: if x == 0, return z else return y.
int conditional(int x, int y, int z) {
    int mask = (!x + ~(0x00));

    return ((mask & y) | (~mask & z));
}



int main (void) {
    printf("%d\n",bitAnd(6,5));
    printf("%d\n",bitXor(4,5));
    printf("%d\n",bitSign(-10));
    printf("%d\n",bitSign(10));
    printf("%d\n",bitSign(0));
    printf("%d\n",getByte(305419896,1));
    printf("%d\n",logicalShift(-10,29));
    printf("%d\n",conditional(2,3,4));
    printf("%d\n",bang(10));
    printf("%d\n",bang(0));
    printf("%d\n",invert(20,1,3));
    return 1;
}
