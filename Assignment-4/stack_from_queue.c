/* 
 * Program to implement stack from queues.
 * Output- to be run on leetcode Q.225
 * Dushyant Batra,(1910990098),15/08/2021
 * Assignment - 4 (Stacks and Queues)
 */

//all the properties of queue included in structure so that more queues can be made.
typedef struct {
    int* data;
    int front;
    int rear;
    int queue_size;
    int count;
}Queue;

//function to create queue and initialize all its data
//return Queue*:pointer to the queue structure
Queue* createQueue() {
    // dynamically allocating space to stack.
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    //Initializing all its data.
    queue->data = (int*)calloc(100, sizeof(int));
    queue->front = queue->rear = -1;
    queue->queue_size = 100;
    queue->count = 0;

    return queue;
}

//function to check whether queue is Empty or not.
//parameter:
//Queue* q: pointer to queue created using structure.
//return int: return 1 if queue is Empty else return 0.
int isEmpty(Queue* q) {
    if(q->front == - 1) {
        return 1;
    }
    return 0;
}

//function to add element to the queue
//parameter:
//Queue* q: pointer to queue created using structure.
//int val: value to be added in queue.
//return void.
void enqueue(Queue* q, int val) {
    if(q->count == q->queue_size) {
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1) {
        q->data[++q->front] = val;
        q->rear++;
        q->count++;

        return;
    }
    q->rear = (q->rear + 1) % q->queue_size;
    q->data[q->rear] = val;
    q->count++;
}

//function to remove the first element from queue
//parameter:
//Queue* q: pointer to queue created using structure.
//return int:value removed
int dequeue(Queue* q) {
    if(isEmpty(q) == 1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->queue_size;
    q->count--;
    if(q->count == 0) {
        q->front = q->rear = -1;
    }

    return val;
}

//function to get first element from queue.
//parameter:
//Queue* q: pointer to queue created using structure.
//return int: value at first.
int peek(Queue* q) {
    if(isEmpty(q) == 1) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

//structure to implement stack
typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

/** Initialize your data structure here. */

//function to create and initialize  stack.
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(isEmpty(obj->q1) == 1) {
        enqueue(obj->q1,x);
        shiftQueue(obj->q2,obj->q1);
    }  
    else {
        enqueue(obj->q2,x);
        shiftQueue(obj->q1,obj->q2);
    }
}
//shifting elements from first queue to secon queue
void shiftQueue(Queue* q1,Queue* q2) {
    while(isEmpty(q1) != 1) {
        enqueue(q2,dequeue(q1));
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(isEmpty(obj->q1) == 1) {
        return dequeue(obj->q2);
    }  
    else {
        return dequeue(obj->q1);
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1) == 1) {
        return peek(obj->q2);
    }  
    else {
        return peek(obj->q1);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (isEmpty(obj->q1) && isEmpty(obj->q2));
}

void myStackFree(MyStack* obj) {
    free(obj);  
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
