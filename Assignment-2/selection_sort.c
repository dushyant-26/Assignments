/*
 * Program to analyze run time complexity of Selection Sort
 * Compilation- gcc -o selection_sort selection_sort.c
 * Execution- ./selection_sort
 * Dushyant Batra,(1910990098),26/07/2021
 * Assignment - 2
 */

#include<stdio.h>
#include<stdlib.h>   // for rand() function
#include<sys/time.h> // for gettimeofday() function

// generating array with random numbers.
// Parameters:
// int array[] : array of integers 
// int size : size of array
// return void
void generateRandomInput(int array[], int size) { 
    for(int i = 0 ; i < size ; i++) {
        array[i] = rand() % size + 1;
    }

}

// generating array with numbers in ascending order.
// Parameters:
// int array[] : array of integers 
// int size : size of array
// return void
void generateAscendingInput(int array[], int size) {
    for(int i = 0 ; i < size ; i++) {
        array[i] = i + 1;
    }
}

// generating array with numbers in descending order.
// Parameters:
// int array[] : array of integers 
// int size : size of array
// return void
void generateDescendingInput(int array[], int size) {
    for(int i = 0 ; i < size ; i++) {
        array[i] = size - i + 1;
    }
}

// swapping two array elements.
// Parameters:
// int array[] : array of integers 
// int i : first index
// int j : second index
// return void
void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// sort array using selection sort.
// Parameters:
// int array[] : array of integers 
// int size : size of array
// return void
void selection_sort(int array[], int size) {
    for(int i = 0 ; i < size - 1 ; i++){
	int min_index = i;
        for(int j = i + 1 ; j < size; j++) {
	    if(array[min_index] > array[j]){
	        min_index = j;
	    }
	}
	swap(array,i,min_index);
    }
}

// print the time taken by selection sort to complete at different sizes and values
// Parameters:
// int start_size : initial size of array 
// int increment : increase size of array every time by this value
// return void
void generate_report(int start_size, int increment) {
    struct timeval te;

    for(int i = 0; i < 8; i++) {
        int size = start_size + increment * i;
	int array[size];

	//generateRandomInput(array, size);
	//generateAscendingInput(array, size);
	generateDescendingInput(array, size);
	
	gettimeofday(&te, NULL);
	long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
	selection_sort(array, size);
	gettimeofday(&te, NULL);
	long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
	printf("\n%lld", end - start);

    }
}

int main (void) {
    //initial_size :initial size of array
    //increment_by : increment size by this value everytime
    int initial_size = 8000;
    int increment_by = 4000;
    printf("starting");
    generate_report(initial_size, increment_by);
    printf("\nend\n");
    return 1;
}
