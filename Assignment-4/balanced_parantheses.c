/*
 * Program to check whether the given string is balanced or not
 * Compilation- gcc -o balanced_parantheses balanced_parantheses.c
 * Execution- ./balanced_parantheses
 * Dushyant Batra, (1910990098), 10/08/2021
 * Assignment - 4 (Stacks and Queues)
 */
#include<stdio.h>
#include<stdlib.h>

//all the properties of stack included in structure so that more stacks can be made.
typedef struct Stack{
    char* data;
    int top;
    int stack_size;
}Stack;

//function to create stack and initialize all its data
//return Stack*:pointer to the stack structure
Stack* createStack() {
    // dynamically allocating space to stack.
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    //Initializing all its data.
    stack->data = (char*)calloc(10, sizeof(char));
    stack->top = -1;
    stack->stack_size = 10;

    return stack;
}

//function to check whether stack is Empty or not.
//parameter:
//Stack* st: pointer to stack created using structure.
//return int: return 1 if stack is Empty else return 0.
int isEmpty(Stack* st) {
    if(st->top == - 1) {
        return 1;
    }
    return 0;
}

//function to resize the array.
//parameter:
//Stack* st: pointer to stack created using structure.
//return void
void resize_stack(Stack* st) {
    st->stack_size *= 2;
    st->data = (char*)realloc(st->data,st->stack_size * sizeof(char));
}

//function to add element to the array
//parameter:
//Stack* st: pointer to stack created using structure.
//char val: value to be added in stack.
//return void.
void push(Stack* st, char val) {
    if(st->top == st->stack_size - 1) {
        resize_stack(st);
    }
    st->data[++st->top] = val;
}

//function to remove the top element from stack
//parameter:
//Stack* st: pointer to stack created using structure.
//return char:value removed
char pop(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return 0;
    }
    return st->data[st->top--];
}

//function to get top element from stack.
//parameter:
//Stack* st: pointer to stack created using structure.
//return char: value at the top.
char peek(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return 0;
    }
    return st->data[st->top];
}

// function to check whether the given string is balanced or not
// parameters:
// char* str: given string
// return int:return 1 if string is balanced else return 0.
int balanced_str(char* str) {
    Stack* stack = createStack();

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
	    push(stack, str[i]);
	}
	else {
	    if(isEmpty(stack) == 1) {
	        return 0;
	    }
	    char previous = pop(stack);
	    if((str[i] == ')' && previous != '(') || (str[i] == ']' && previous != '[') || (str[i] == '}' && previous != '{')) {
	        return 0;
	    }
	}
    }
    
    if(isEmpty(stack) == 1) {
        return 1;
    }
    return 0;
}

int main (void) {
    char str[100];

    printf("Enter the string\n");
    scanf("%[^\n]s",str);

    if (balanced_str(str) == 1) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    return 1;
}
