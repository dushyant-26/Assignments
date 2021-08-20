/*
 * Program to print mth smallest no. in unsorted array
 * Compilation- gcc -o mth_smallest mth_smallest.c
 * Execution- ./mth_smallest
 * Dushyant Batra,(1910990098),19/08/2021
 * Assignment - 8 (Algorithms)
 */

#include<stdio.h>

//swaps the numbers
//params:
//int* arr: input array
//int i: first position
//int j: second position
//return void
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//return the pivot element
//params:
//int* arr: input array
//int left: start of array
//int right: end of array
//return int: position of pivot
int partition(int* arr, int left, int right) {
    int num = arr[right];
    int ind = left - 1;

    for(int i = left; i < right; i++) {
        if(arr[i] <= num) {
            swap(arr, ++ind, i);
        }
    }

    swap(arr, ind + 1, right);
    return ind + 1;
}

//return mth smallest element
//params:
//int* arr:input array
//int left:start of array
//int right:end of array
//int m:which smallest element to find
//return int:mth smallest element
int findMthSmallest(int* arr, int left, int right, int m) {
     if(left == right) {
        return arr[left];
    }
    
    int pos = partition(arr, left, right);
    int count = pos - left + 1;

    if(count == m) {
        return arr[pos];
    }
    else if(count > m) {
        return findMthSmallest(arr, left, pos - 1, m);
    }
    else {
        return findMthSmallest(arr, pos + 1, right, m - count);
    }
}

//return mth smallest element
//params:
//int* arr:input array
//int size:size of array
//int m:which smallest element to find
//return int:mth smallest element
int get_mth_smallest(int* arr, int size, int m) {
    return findMthSmallest(arr, 0, size - 1, m);
}

int main(void) {
    int n;
    printf("Enter the no. of elements in array\n");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d",&m);
    printf("%dth smallest number is %d\n",m,get_mth_smallest(arr, n, m));
}

