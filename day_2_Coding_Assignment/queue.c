/*
 * Program to implement Queue in C
 * Compilation- gcc -o queue queue.c
 * Execution- ./queue
 * Dushyant Batra,(1910990098), 04/08/2021
 * Assignment no. 2 (day_2_coding assignment)
 */
#include<stdio.h>
#include<stdlib.h>

int* queue = NULL;
int head = -1;
int tail = -1;
int queue_size = 0;
int count = 0;

//checks whether queue is empty or not.
//return int: return 1 if queue is empty,else return 0.
//TC -> O(1)
int is_empty() {
    if(head == -1) {
        return 1;
    }
    return 0;
}

//checks whether queue is full or not.
//return int: return 1 if queue is full, else return 0.
//TC -> O(1)
int is_full() {
    if(count == queue_size) {
        return 1;
    }
    return 0;
}

// add element to queue
// return void
// TC - O(1)
void enqueue(int num) {
    if(is_full() == 1) {
        printf("\nQueue is full\n");
        return;
    }
    if(is_empty() == 1) {
        head++;
    }
    tail = (tail + 1) % queue_size;
    queue[tail] = num;
    count++;
}

//removes head element from queue and return it
//TC -> O(1)
int dequeue() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return -1;
    }
    int removed = queue[head];
    head = (head + 1) % queue_size;
    count--;

    if(count == 0) {
        head = tail = -1;
    }
    return removed;
}

//returns head element from queue.
//TC -> O(1)
int peek() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return -1;
    }
    return queue[head];
}

//print elements in queue.
//TC -> O(n)
void print() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return;
    }

    int j = 0;
    for(int i = head; j++ < count; i = (i + 1) % queue_size ) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main (void) {

    printf("Enter the size of Queue:\n");
    scanf("%d",&queue_size);

    queue = (int*) calloc(queue_size, sizeof(int));

    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Enqueue operation\n");
        printf("2. Dequeue operation\n");
        printf("3. Peek operation\n");
        printf("4. Check whether Queue is Empty or not\n");
        printf("5. Print values in Queue\n");
        printf("6. Exit the Program\n\n");

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number to add in Queue\n");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                printf("\nThe number removed from queue is %d\n",dequeue());
                break;
            case 3:
                printf("\nThe number present at head of Queue is %d\n", peek());
                break;
            case 4:
                if(is_empty()) {
                    printf("\nYes, the Queue is Empty\n");
                } else {
                    printf("\nNo the Queue is not empty\n");
                }
                break;
            case 5:
                print();
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid operation\n");
        }
    }

    return 1;
}
