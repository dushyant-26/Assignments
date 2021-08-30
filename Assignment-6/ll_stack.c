/*
 * Program to implement a stack using LinkedList
 * Compilation- gcc -o ll_stack ll_stack.c
 * Execution- ./ll_stack
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

node* top;

//push element to stack
//params:
//int val:num to be added
void push(int val) {
    node* element = (node*)malloc(sizeof(node));
    element->val = val;
    element->next = top;
    top = element;
}

//pop element from stack
int pop() {
    if(top == NULL) {
	printf("Empty stack\n");
        return INT_MIN;
    }
    node* temp = top;
    top = top->next;
    int val = temp->val;
    temp->next = NULL;
    free(temp);
    return val;

}

//return the top element of stack
int peek() {
    if(top == NULL) {
        printf("Empty stack\n");
	return INT_MIN;
    }
    return top->val;
}

//check whether stack is empty or not
int isEmpty() {
    return (top == NULL); 
}

//prints the stack
void print() {
    node* current = top;
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
        printf("1. Push operation\n");
        printf("2. Pop operation\n");
        printf("3. Peek operation\n");
        printf("4. Check whether stack is Empty or not\n");
        printf("5. Exit the Program\n");

        scanf("\n%d",&choice);

	int val;
        switch(choice) {
            case 1:
                printf("\nEnter the number to push:\n");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
		val = pop();
		if(val != INT_MIN) {
                    printf("\nThe number popped from stack is %d\n", val);
		}
                break;
            case 3:
		val = peek();
		if(val != INT_MIN) {
                    printf("\nThe number present on top of stack is %d\n", val);
		}
                break;
            case 4:
                if(isEmpty()) {
                    printf("\nYes, the Stack is empty\n");
                }
                else {
                    printf("\nNo, the Stack is not empty\n");
                }
                break;
            case 5:
                exit(1);
            default:
                printf("\nInvalid operation\n");
        }
    }
    return 0;
}
