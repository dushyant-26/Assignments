/*
 * Program to analyze run time complexity of Insertion Sort
 * Compilation- gcc -o insertion_sort insertion_sort.c
 * Execution- ./insertion_sort
 * Dushyant Batra,(1910990098),30/07/2021
 * Assignment - 2 (Sorting Algorithms)
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

// sort array using insertion sort.
// Parameters:
// int array[] : array of integers 
// int size : size of array
// return void
void insertion_sort(int array[], int size) {
    for(int i = 1 ; i < size ; i++){
	int min_value = array[i];
	int j = i - 1;
	while(j >= 0 && array[j] > min_value) {
	    array[j+1] = array[j];
	    j--;
	}
	array[j+1] = min_value;
    }
}

// print the time taken by insertion sort to complete at different sizes and values
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
	insertion_sort(array, size);
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
