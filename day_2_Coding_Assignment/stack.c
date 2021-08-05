/*
 * Program to implement stack in C
 * Compilation- gcc -o stack stack.c
 * Execution- ./stack
 * Dushyant Batra,(1910990098), 04/08/2021
 * Assignment no. 2 (day_2_coding assignment)
 */
#include<stdio.h>
#include<stdlib.h>

int* stack = NULL;
int top = -1;
int stack_size = 0;

// checks whether stack is empty or not.
// return int: return 1 if stack is empty else return 0
int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
}

//resize the size of stack
//return void
void resize_stack() {
    stack_size *= 2;
    stack = (int*) realloc(stack, stack_size);
}

// push a number to stack
// parameters:
// int num: integer number that we want to push.
// return void
void push(int num) {
    if(top == stack_size - 1) {
        resize_stack();
    }
    stack[++top] = num;
}

//remove top element from stack and return it
//return int: removed element
int pop() {
    if(isEmpty() == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top--];
}

//return top element of stack
int peek() {
    if(isEmpty() == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

//print values in stack
//return void
void print() {
    if(isEmpty() == 1) {
        printf("Stack is Empty\n");
        return;
    }

    for(int i = 0; i <= top; i++) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the initial size of stack:\n");
    scanf("%d", &stack_size);

    stack = (int*) calloc(stack_size, sizeof(int));

    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Push operation\n");
        printf("2. Pop operation\n");
        printf("3. Peek operation\n");
        printf("4. Check whether stack is Empty or not\n");
        printf("5. Print values in stack\n");
        printf("6. Exit the Program\n");

        scanf("\n%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number to push:\n");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                printf("\nThe number popped from stack is %d\n", pop());
                break;
            case 3:
                printf("\nThe number present on top of stack is %d\n", peek());
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
                print();
                break;
            case 6:
                exit(1);
            default:
                printf("\nInvalid operation\n");
        }
    }
}
