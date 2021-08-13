/*
 * Program to get inversion count from an array.
 * Compilation- gcc -o inversion_count inversion_count.c
 * Execution- ./inversion_count
 * Dushyant Batra, 1910990098, 12/08/2021
 * Assignment 7 (Sorting)
 */
#include<stdio.h>

int merge(int* arr, int* temp, int left, int right);

// function to get inversion count
// parameters:
// int* arr: input array
// int* temp: temporary array
// int left: start of array
// int right:end of array
// return int: inversion count
int inversion_count(int* arr, int* temp,int left, int right) {
    int mid, inv_count = 0;

    if(left < right) {
        mid = left + (right - left) / 2;

	inv_count += inversion_count(arr, temp, left, mid);
	inv_count += inversion_count(arr, temp, mid + 1, right);

	inv_count += merge(arr, temp, left, right);
    }

    return inv_count;
}

// function to merge the arrays starting from left and mid + 1
// parameters:
// int* arr: input array
// int* temp: temporary array
// int left: start of array
// int right:end of array
// return int: inversion count
int merge(int* arr, int* temp, int left, int right) {
    int inv_count  = 0;
    int mid = left + (right - left) / 2;
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
	    temp[k++] = arr[i++];   
	}
	else {
	    inv_count += mid - i + 1;
	    temp[k++] = arr[j++];
	}
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    int n = 0;
    for(int m = left; m <= right; m++) {
        arr[m] = temp[n++]; 
    }
    return inv_count;
}

int main (void) {
    int n;
    printf("No. of elements in array\n");
    scanf("%d", &n);

    int arr[n];
    int temp[n];

    printf("Enter elements in array\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Inversion count is %d\n", inversion_count(arr,temp,0,n - 1));

    return 1;
}
