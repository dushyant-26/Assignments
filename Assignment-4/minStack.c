/* 
 * Program to get minimum value from stack in constant time
 * Output- to be run on leetcode Q.155
 * Dushyant Batra,(1910990098),15/08/2021
 * Assignment - 4 (Stacks and Queues)
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

//structure to store data of minstack.
typedef struct {
    Stack* stack;
    Stack* min;
} MinStack;

/** initialize your data structure here. */

//function to create and initialize minstack
//return MinStack*: pointer to the minstack created.
MinStack* minStackCreate() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->stack = createStack();
    minStack->min = createStack();
    
    return minStack;
}

//function to push data to given minStack.
//parameters:
//MinStack* obj: pointer to MinStack
//int val: data to be inserted
//return void
void minStackPush(MinStack* obj, int val) {
    if(isEmpty(obj->min) == 1) {
        push(obj->min,val);
    }
    else {
        int top = peek(obj->min);
        if(val <= top) {
            push(obj->min, val);
        }
        else {
            push(obj->min, top);
        }
    }
    push(obj->stack, val);
}

//function to pop top element from given minStack.
//parameters:
//MinStack* obj: pointer to MinStack
//return void
void minStackPop(MinStack* obj) {
    pop(obj->stack);
    pop(obj->min);
}

//function to get top element from given minStack.
//parameters:
//MinStack* obj: pointer to MinStack
//return int: value resent at top
int minStackTop(MinStack* obj) {
    return peek(obj->stack);
}

//function to get minimum value from given minStack.
//parameters:
//MinStack* obj: pointer to MinStack
//return int:minimum value in stack
int minStackGetMin(MinStack* obj) {
    return peek(obj->min);
}

//function to free memory assigned to given minStack.
//parameters:
//MinStack* obj: pointer to MinStack
//return void
void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
