/*
 * Program to implement a queue using LinkedList
 * Compilation- gcc -o ll_queue ll_queue.c
 * Execution- ./ll_queue
 * Dushyant Batra,(1910990098), 28/08/2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//structure of node
typedef struct node {
    int val;
    struct node* next;
} node;

node* head;
node* tail;

//add element to the queue
//params:
//int val:num to be added
void enqueue(int val) {
    node* element = (node*)malloc(sizeof(node));
    element->val = val;
    
    if(head == NULL) {
        head = tail = element;
	return;
    }
    tail->next = element;
    tail = element;
}

//remove element from queue
int dequeue() {
    if(head == NULL) {
	printf("Empty Queue\n");
        return INT_MIN;
    }
    node* temp = head;
    head = head->next;
    if(head == NULL) {
        tail = NULL;
    }
    int val = temp->val;
    free(temp);
    return val;

}

//return head element of queue
int peek() {
    if(head == NULL) {
        printf("Empty Queue\n");
	return INT_MIN;
    }
    return head->val;
}

//check whether queue is empty or not
int isEmpty() {
    return (head == NULL); 
}

//prints the queue
void print() {
    node* current = head;
    while(current != NULL) {
        printf("%d ",current->val);
	current = current->next;
    }
    printf("\n");
}

int main(void) {

    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Enqueue operation\n");
        printf("2. Dequeue operation\n");
        printf("3. Peek operation\n");
        printf("4. Check whether queue is Empty or not\n");
	printf("5. Print the elements present in Queue\n");
        printf("6. Exit the Program\n");

        scanf("\n%d",&choice);

	int val;
        switch(choice) {
            case 1:
                printf("\nEnter the number to add:\n");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
		val = dequeue();
		if(val != INT_MIN) {
                    printf("\nThe number removed from Queue is %d\n", val);
		}
                break;
            case 3:
		val = peek();
		if(val != INT_MIN) {
                    printf("\nThe number present on top of Queue is %d\n", val);
		}
                break;
            case 4:
                if(isEmpty()) {
                    printf("\nYes, the Queue is empty\n");
                }
                else {
                    printf("\nNo, the Queue is not empty\n");
                }
                break;
	    case 5:
		print();
		break;
            case 6:
                exit(1);
            default:
                printf("\nInvalid operation\n");
        }
    }
    return 0;
}
