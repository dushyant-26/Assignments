/*
 * Program to find greatest rectangle area in histogram
 * Output- to be run on leetcode Q.84
 * Dushyant Batra,(1910990098),15/08/2021
 * Assignment - 4(Stacks and Queues)
 */

//all the properties of stack included in structure so that more stacks can be made.
typedef struct Stack{
    int* data;
    int top;
    int stack_size;
}Stack;

//function to create stack and initialize all its data
//return Stack*:pointer to the stack structure
Stack* createStack() {
    // dynamically allocating space to stack.
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    //Initializing all its data.
    stack->data = (int*)calloc(10, sizeof(int));
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
    st->data = (int*)realloc(st->data,st->stack_size * sizeof(int));
}

//function to add element to the array
//parameter:
//Stack* st: pointer to stack created using structure.
//int val: value to be added in stack.
//return void.
void push(Stack* st, int val) {
    if(st->top == st->stack_size - 1) {
        resize_stack(st);
    }
    st->data[++st->top] = val;
}

//function to remove the top element from stack
//parameter:
//Stack* st: pointer to stack created using structure.
//return int:value removed
int pop(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return st->data[st->top--];
}

//function to get top element from stack.
//parameter:
//Stack* st: pointer to stack created using structure.
//return int: value at the top.
int peek(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return st->data[st->top];
}

//function to find greatest rectangle area in histogram
//parameters:
//int* heights: given integer array
//int heightsSize: size of given array
//return int: greatest rectangle area
int largestRectangleArea(int* heights, int heightsSize){
    Stack* stack = createStack();
    
    int rb[heightsSize];
    rb[heightsSize - 1] = heightsSize;
    push(stack,heightsSize - 1);
    for(int i = heightsSize - 2; i >= 0; i--) {
        while(!isEmpty(stack) && heights[i] <= heights[peek(stack)]) {
            pop(stack);
        }
        if(isEmpty(stack) == 1) {
            rb[i] = heightsSize;
        }
        else {
            rb[i] = peek(stack);
        }
        push(stack,i);
    }
    
    stack = createStack();
    int lb[heightsSize];
    lb[0] = -1;
    push(stack,0);
    for(int i = 1; i < heightsSize; i++) {
        while(!isEmpty(stack) && heights[i] <= heights[peek(stack)]) {
            pop(stack);
        }
        if(isEmpty(stack) == 1) {
            lb[i] = -1;
        }
        else {
            lb[i] = peek(stack);
        }
        push(stack,i);
    }
    int maxArea = 0;

    for(int i = 0; i < heightsSize; i++) {
        int width = rb[i] - lb[i] - 1;
        int area = width * heights[i];
        
        if(area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

