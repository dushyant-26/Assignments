/*
 * Program to convert infix expression to postfix expression
 * Compilation- gcc -o infix_to_postfix infix_to_postfix.c
 * Execution- ./infix_to_postfix
 * Dushyant Batra, (1910990098), 10/08/2021
 * Assignment - 4 (Stacks and Queues)
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

//function to check whether given character is an operand or not
//parameters:
//char ch: input character
//return int: retun 1 if ch is operand else return 0
int isOperand(char ch) {
    if(ch >=48 && ch <= 57) {
        return 1;
    }
    return 0;
}

//function which returns precedence of given operator
//the precedence is customly set as per precedence table(Not the actual values but in same order)
//parameters:
//char ch:input operator
//return int:custom precedence,return -1 if its not an operator.
int precedence(char ch) {
    switch(ch) {
        case '+':
	case '-':
		return 1;
	case '*':
        case '/':
		return 2;
    }
    return -1;
}

//function which returns postfix expression of given infix expression
//parameters:
//char* str: given infix expression
//return char*: string having postfix expression
char* getPostfix(char* str) {
    char* res = (char*)malloc(strlen(str)*sizeof(char));
    Stack* stack = createStack();
    int k = -1;

    for(int i = 0; str[i] != '\0' ; i++) {
        if(isOperand(str[i]) == 1) {
	    res[++k] = str[i];
	}
	else if(str[i] == '(') {
	    push(stack, str[i]);
	}
	else if(str[i] == ')') {
	    while(!isEmpty(stack) && peek(stack) != '(') {
	        res[++k] = pop(stack);
	    }
	    if(isEmpty(stack) == 1) {
	        printf("Invalid Expression\n");
		return NULL;
	    }
	    else {
	        pop(stack);
	    }
	}
	else {
	    if(isEmpty(stack) == 0) {
		char top = peek(stack);
	        while(!isEmpty(stack) && precedence(top) >= precedence(str[i])) {
		    res[++k] = pop(stack);
		    if(!isEmpty(stack)) {
		        top = peek(stack);
		    }
		}
	    }
	    push(stack, str[i]);
	}
    }
    while(isEmpty(stack) == 0) {
	char popped = pop(stack);
	if(popped == '(') {
	    printf("Invalid expression\n");
	    return NULL;
	} 
        res[++k] = popped;
    }
    res[++k] = '\0';
    free(stack);
    return res;
}

int main (void) {
    char str[100];

    printf("Enter the string\n");
    scanf("%[^\n]s",str);

    printf("Postfix expression:\n");

    char* res = getPostfix(str);

    if(res != NULL) {
        printf("%s\n", res);
    }
    free(res);
    return 1;
}
